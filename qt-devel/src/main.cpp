#include <qapplication.h>
#include "awcalcmain.h"

int main( int argc, char ** argv )
{
    QApplication a( argc, argv );
    awcalcMain w;
    w.show();
    a.connect( &a, SIGNAL( lastWindowClosed() ), &a, SLOT( quit() ) );
    return a.exec();
}
