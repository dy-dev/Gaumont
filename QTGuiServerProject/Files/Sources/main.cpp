#include "QTWebServer.h"
#include "MediaPlayer.h"
#include "ApplicationManager.h"        
#include "FullMediaPlayerWithList.h"
#include <QApplication>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include <QDir>
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
   // QApplication a(argc, argv);
   // QTWebServer w;   
   //// w.setWindowFlags( Qt::Window | Qt::FramelessWindowHint );
   // w.show();
   // return a.exec();



    QApplication app( argc, argv );

    QCoreApplication::setApplicationName( "Gaumont Server Player" );
    QCoreApplication::setOrganizationName( "Light In Chaos" );
    QCoreApplication::setApplicationVersion( QT_VERSION_STR );
    QCommandLineParser parser;
    parser.setApplicationDescription( "Light In Chaos Webserver - Player Example" );
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument( "url", "The URL to open." );
    parser.process( app );

    ApplicationManager appMgr;
    /*MediaPlayer tmp;
    //FullMediaPlayerWithList tmp;
    tmp.show();
    //tmp.Action();
   // tmp.go();*/
    return app.exec();

}
