/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is "Award Calculating Tool".
 *
 * The Initial Developer of the Original Code is
 * Boris Wachtmeister.
 * Portions created by the Initial Developer are Copyright (C) 2003
 * the Initial Developer. All Rights Reserved.
 *
 * Contributor(s):
 *      Boris Wachtmeister  < sirro 'at`  nurfuerspam `dot' de >
 * ***** END LICENSE BLOCK ***** */

/****************************************************************************
** ui.h extension file, included from the uic-generated form implementation.
**
** If you want to add, delete, or rename functions or slots, use
** Qt Designer to update this file, preserving your code.
**
** You should not define a constructor or destructor in this file.
** Instead, write your code in functions called init() and destroy().
** These will automatically be called by the form's constructor and
** destructor.
*****************************************************************************/

#include<qfile.h>
#include<qfiledialog.h>
#include<qmessagebox.h>
#include<qtextstream.h>
#include<qstringlist.h>
#include<qvaluelist.h>
#include<iostream>
#include<iomanip>
using namespace std;

void awcalcMain::init()
{
    readingInfoLabel->hide();
}


void awcalcMain::fileNew()
{

}


void awcalcMain::fileOpen()
{
    QString filename = QFileDialog::getOpenFileName(
	    "",
	    "Input Files (*.inp *.txt *.dat)",
	    this,
	    "awcalc - open file dialog","Choose a file" );
    inputTable->hide();
    readingInfoLabel->show();
    QFile *file = new QFile( filename );
    if ( file->open( IO_ReadOnly ) ) {
	QTextStream stream( file );
	QString line;
	QStringList zahlen;
	for (int i=0; !stream.atEnd() ; ++i) {
	    line = stream.readLine(); // line of text excluding '\n'
	    inputTable->setNumRows(i+1);
	    zahlen = QStringList::split(";",line,false);
	    if(inputTable->numCols()==0)
	    {
		this->inputTable->setNumCols(zahlen.count());
		for(unsigned col=0; col<zahlen.count(); ++col)
		    inputTable->setColumnWidth(col,20);
	    }
	    int j=0;
	    for ( QStringList::Iterator it = zahlen.begin(); it != zahlen.end(); ++it, ++j ) 
	    {
		inputTable->setText(i,j,*it);
	    }
	}
	file->close();
    }
    else if(!filename.isEmpty())
	QMessageBox::critical( this, "Fehler", filename + " konnte nicht geöffnet werden!");
    readingInfoLabel->hide();
    inputTable->show();
}


void awcalcMain::fileSave()
{

}


void awcalcMain::fileSaveAs()
{

}


void awcalcMain::filePrint()
{

}


void awcalcMain::fileExit()
{
    this->close();
}


void awcalcMain::helpIndex()
{

}


void awcalcMain::helpAbout()
{
    QMessageBox::about( this, "Award Calculation Tool",
			"\n"
			"To be added\n"
			"\n" );
}


void awcalcMain::helpAboutQt()
{
    QMessageBox::aboutQt( this, "About Qt" );
}


void awcalcMain::calc()
{
    // create Int-Lists initialised with 0 to count the results
    QValueList<int> wins, equals, loose, votings, places;
    QValueList<double> result;
    for(int i=0; i<inputTable->numCols(); ++i)
    {
	wins.append(0);
	equals.append(0);
	loose.append(0);
	votings.append(0);
	//result.append(0);
    }
    
    // walk through the table and compare two different rows in every step
    for(int i=0; i<inputTable->numCols(); ++i)
	for(int j=0; j<inputTable->numCols(); ++j)
	    if(i!=j)
	    {
	int sum=0;
	// compare the rows foreach participant
	for(int row=0; row<inputTable->numRows(); ++row)
	{
	    bool i_ret, j_ret;
	    int i_value=inputTable->text(row,i).toInt(&i_ret,10);
	    int j_value=inputTable->text(row,j).toInt(&j_ret,10);
	    if((i_ret&&j_ret) && (i_value!=0 && j_value!=0)) // toInt successful and things voted
	    {
		if (i_value>j_value) --sum;
		else if(i_value<j_value) ++sum;
	    }
	}
	// record the result for later use
	if(sum>0)	wins[i]++;
	else if(sum<0)	loose[i]++;
	else 		equals[i]++;
    }
    /*                  2*Sieganzahl + Zahl der Unentschieden
               -----------------------------------------------------------
        2 * (Sieganzahl + Verlustanzahl + Zahl der Unentschieden)            */
    for(unsigned i=0;i<wins.count(); ++i)
    {
	result.append((2*(double)wins[i]+(double)equals[i]) / \
		  2/((double)wins[i]+(double)loose[i]+(double)equals[i]));
    }
    
    //sort things with simple O(n^2) into sortpermutation "places"
    for(unsigned i=0;i<wins.count(); ++i)
    {
	int sum=0;
	for(unsigned j=0;j<wins.count(); ++j)
	    if (result[i]<result[j]) sum++;
	places.append(sum+1);
    }
    #define LINE "---------------------------------------------------------\n"
    #define DATAROW "|  %2d\t|  %2.0f\t|  %2.0f\t|  %2.0f\t|  %3d\t| %.3f\t|  %2d\t|\n"
    #define HEADOFTABLE "| Ding\t| Siege\t| Unent.|Nieder.|Bewert.| Quot.\t| Platz\t|\n"
    //cout << LINE << HEADOFTABLE << LINE;
    outTable->setNumRows(wins.count());
    outTable->setNumCols(6);
    for(unsigned i=0;i<wins.count(); ++i)
    {
	outTable->setText(i,0,QString::number(wins[i],10));
	outTable->setColumnWidth(0,30);
	outTable->setText(i,1,QString::number(equals[i],10));
	outTable->setColumnWidth(1,30);
	outTable->setText(i,2,QString::number(loose[i],10));
	outTable->setColumnWidth(2,30);
	outTable->setText(i,3,QString::number(0,10));
	outTable->setColumnWidth(3,30);
	outTable->setText(i,4,QString::number(result[i],'g',3));
	outTable->setColumnWidth(4,40);
	outTable->setText(i,5,QString::number(places[i],10));
	outTable->setColumnWidth(5,30);
	/*cout << "|  "   <<  setw(2) << i+1;
	cout << "\t|  " << setw(2) << wins[i];
	cout << "\t|  " << setw(2) << equals[i];
	cout << "\t|  " << setw(2) << loose[i];
	cout << "\t|  " << setw(2) << 0;
	cout << "\t| "  << setprecision(3) << setw(5) << fixed << result[i];
	cout << "\t|  " << setw(2) << places[i];
	cout << "\t|"   << endl;*/
    }
    //cout << LINE;
}
