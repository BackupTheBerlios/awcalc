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
using namespace std;

void awcalcMain::init()
{

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
    QFile *file = new QFile( filename );
    if ( file->open( IO_ReadOnly ) ) {
	QTextStream stream( file );
	QString line;
	QStringList zahlen;
	for (int i=0; !stream.atEnd() ; ++i) {
	    line = stream.readLine(); // line of text excluding '\n'
	    this->inputTable->setNumRows(i+1);
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
		inputTable->setText(i,j,*it); //(*it).toInt());
	    }
	}
	file->close();
    }
    else if(!filename.isEmpty())
	QMessageBox::critical( this, "Fehler", filename + " konnte nicht geöffnet werden!" );
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
    QValueList<int> wins, equals, loose, votings;
    for(int i=0; i<inputTable->numCols(); ++i)
    {
	wins.append(0);
	equals.append(0);
	loose.append(0);
	votings.append(0);
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
	    if(i_ret&j_ret) // toInt successful
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
    for(unsigned i=0;i<wins.count();++i)
	cout << i << ": " << wins[i] << " " << equals[i] << " " << loose[i] <<endl;
    
}
