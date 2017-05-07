#include "QTWebServer.h"
#include "MediaPlayer.h"
#include "RequestsHandler.h"
#include "ApplicationManager.h"
#include "FullMediaPlayerWithList.h"


ApplicationManager::ApplicationManager()
    : m_pQTWebServer(nullptr )
    , m_pMediaPlayer( nullptr )
    , m_pRequestsHandler( nullptr )

{
    m_pRequestsHandler = new RequestsHandler();
    m_pQTWebServer = new QTWebServer( nullptr, m_pRequestsHandler );
    m_pMediaPlayer = new MediaPlayer();
   
    m_pRequestsHandler->setConnections( m_pQTWebServer, m_pMediaPlayer );
    m_pMediaPlayer->show();
    
    /*
    MediaPlayer player;

    if ( !parser.positionalArguments().isEmpty() && player.isPlayerAvailable() ) {
        QList<QUrl> urls;
        foreach( const QString &a, parser.positionalArguments() )
            urls.append( QUrl::fromUserInput( a, QDir::currentPath(), QUrl::AssumeLocalFile ) );
        player.addToPlaylist( urls );
    }

#if defined(Q_WS_SIMULATOR)
    player.setAttribute( Qt::WA_LockLandscapeOrientation );
    player.showMaximized();
#else
    player.show();
#endif                   */
  
}


ApplicationManager::~ApplicationManager()
{
    delete m_pRequestsHandler;
    delete m_pQTWebServer;
    delete m_pMediaPlayer;
}
