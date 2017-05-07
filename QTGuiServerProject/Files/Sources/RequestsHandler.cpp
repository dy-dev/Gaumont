#include <QtWidgets>
#include <QtNetwork>      
#include <QtWebSockets/qwebsocketserver.h>
#include <QtWebSockets/qwebsocket.h>

#include <stdlib.h>

#include "QTWebServer.h"
#include "MediaPlayer.h"
#include "RequestsHandler.h"

RequestsHandler::RequestsHandler()
    :m_pQTWebServer(nullptr)
{
}

RequestsHandler::~RequestsHandler()
{
}

void RequestsHandler::setConnections( QTWebServer* p_pQTWebServer, MediaPlayer * p_pMediaPlayer )
{
    connect( this, &RequestsHandler::ManageTextClientResponse, p_pQTWebServer, &QTWebServer::processTextResponse );
    connect( this, &RequestsHandler::ManageBinaryClientResponse, p_pQTWebServer, &QTWebServer::processBinaryResponse );

    connect( this, &RequestsHandler::PrepareVideo, p_pMediaPlayer, &MediaPlayer::go );
    connect( this, &RequestsHandler::StartVideo, p_pMediaPlayer, &MediaPlayer::go2 );

}

//! [processTextMessage]
void RequestsHandler::processTextMessage( QString message )
{
    QJsonObject obj;
    QJsonDocument doc = QJsonDocument::fromJson( message.toUtf8() );
    if ( !doc.isNull() )
    {
        if ( doc.isObject() )
        {
            obj = doc.object();
        }
        else
        {
            qDebug() << "Document is not an object" << endl;
        }
    }
    else
    {
        qDebug() << "Invalid JSON...\n" << message << endl;
    }

    PrepareVideo( obj["type"].toString() );
   
   
    QWebSocket *pClient = qobject_cast< QWebSocket * >( sender() );
    ManageTextClientResponse( pClient, message );
    
}
//! [processTextMessage]

//! [processBinaryMessage]
void RequestsHandler::processBinaryMessage( QByteArray message )
{
    QWebSocket *pClient = qobject_cast< QWebSocket * >( sender() );
    ManageTextClientResponse( pClient, message );
}
//! [processBinaryMessage]

