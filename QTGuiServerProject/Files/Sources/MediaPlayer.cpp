#include <QVideoWidget>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsVideoItem>
#include <QMediaPlayer>
#include <QMediaService>
#include <QMediaPlaylist>


#include <qvideowidget.h>
#include <qvideosurfaceformat.h>

#include "MediaPlayer.h"



MediaPlayer::MediaPlayer( QWidget *parent )
    : QMainWindow( parent )
    , m_pQMediaPlayer( nullptr )
    , m_pQPlaylistLive( nullptr )
    , m_pQPlaylistPathe( nullptr )
    , m_pQPlaylistPub1( nullptr )
    , m_pQPlaylistPub2( nullptr )
{
    //setWindowFlags( Qt::Window /*| Qt::FramelessWindowHint*/);
    
    ui.setupUi( this );
  //  this->showFullScreen();
   
    // ui.InfosLabel->setTextInteractionFlags( Qt::TextBrowserInteraction );
    m_pQMediaPlayer = new QMediaPlayer( 0 );
    m_pQVideoWidget = new QVideoWidget( 0 );
    //m_pQVideoWidget->setSizePolicy( QSizePolicy::Expanding, QSizePolicy::Expanding );
    //m_pQMediaPlayer->setVideoOutput( m_pQVideoWidget );
    m_pQMediaPlayer->setVideoOutput( m_pQVideoWidget );

    m_pQPlaylistPathe = new QMediaPlaylist(  );
    m_pQPlaylistLive = new QMediaPlaylist(  );
    m_pQPlaylistPub1 = new QMediaPlaylist(  );
    m_pQPlaylistPub2 = new QMediaPlaylist(  );

    m_pQPlaylistPathe->addMedia( QUrl( "D:/Light In Chaos/Prospects-Client/Pedro/Gaumont Pathe/QTGuiServerProject/Resources/Medias/GaumontPathe1.mp4"  ) );
    m_pQPlaylistPathe->addMedia( QUrl( "D:/Light In Chaos/Prospects-Client/Pedro/Gaumont Pathe/QTGuiServerProject/Resources/Medias/GaumontPathe2.mp4" ) );

    m_pQPlaylistPub1->addMedia( QUrl( "D:/Light In Chaos/Prospects-Client/Pedro/Gaumont Pathe/QTGuiServerProject/Resources/Medias/Pub Oasis.mp4" ) );
    m_pQPlaylistPub1->addMedia( QUrl( "D:/Light In Chaos/Prospects-Client/Pedro/Gaumont Pathe/QTGuiServerProject/Resources/Medias/pubmms.mp4") );
                                
    m_pQPlaylistPub2->addMedia( QUrl( "D:/Light In Chaos/Prospects-Client/Pedro/Gaumont Pathe/QTGuiServerProject/Resources/Medias/PubPrintempsCine.mp4" ) );
    m_pQPlaylistPub2->addMedia( QUrl( "D:/Light In Chaos/Prospects-Client/Pedro/Gaumont Pathe/QTGuiServerProject/Resources/Medias/pubmms.mp4" ) );
                                
    m_pQPlaylistLive->addMedia( QUrl( "D:/Light In Chaos/Prospects-Client/Pedro/Gaumont Pathe/QTGuiServerProject/Resources/Medias/foot.mp4" ) );

    //QBoxLayout *displayLayout = new QHBoxLayout;
    //displayLayout->addWidget( m_pQVideoWidget );
    //ui.waitingWidget->setLayout( displayLayout );
    connect( m_pQMediaPlayer, SIGNAL( mediaStatusChanged( QMediaPlayer::MediaStatus ) ),
        this, SLOT( statusChanged( QMediaPlayer::MediaStatus ) ) );


   
    //Action();     
}


MediaPlayer::~MediaPlayer()
{
}


void MediaPlayer::statusChanged( QMediaPlayer::MediaStatus status )
{

    // handle status message
    switch ( status ) {
  //  case QMediaPlayer::PlayingState:
    case QMediaPlayer::BufferedMedia:
       // _sleep( 1000 );
        go2();
        break;
    case QMediaPlayer::LoadingMedia:
        //setStatusInfo( tr( "Loading..." ) );
        break;

        break;
    case QMediaPlayer::StalledMedia:
        //setStatusInfo( tr( "Media Stalled" ) );
        break;
    case QMediaPlayer::EndOfMedia:
        //QApplication::alert( this );
        break;
    case QMediaPlayer::InvalidMedia:
        //  displayErrorMessage();
        break;
    }
}
void MediaPlayer::plastronGo()
{
    go( "Pathe" );
}

void MediaPlayer::go( QString p_QStringPlayList )
{
    m_pQMediaPlayer->stop();
    bool play = true;
    if ( p_QStringPlayList == "Pathe" )
    {
        m_pQMediaPlayer->setPlaylist( m_pQPlaylistPathe );
    }
    else if ( p_QStringPlayList == "Pub1" )
    {
        m_pQMediaPlayer->setPlaylist( m_pQPlaylistPub1 );
    }
    else if ( p_QStringPlayList == "Live" )
    {
       // m_pQMediaPlayer->setPlaylist( m_pQPlaylistLive );
        
        play = false;
        m_pQMediaPlayer->setPlaylist( 0 );
        //ui.DisplayLayout->addWidget( m_pQVideoWidget );
    }
    else if ( p_QStringPlayList == "Pub2" )
    {
        m_pQMediaPlayer->setPlaylist( m_pQPlaylistPub2 );

    }
    // ui.Info->layout()->addWidget( videoWidget );
    // ui.Video->layout()->addWidget( videoWidget );


    // ui.centralWidget->layout()->addWidget( videoWidget );
   // m_pQMediaPlayer->setMedia( QUrl( "D:/Light In Chaos/Prospects-Client/Pedro/Gaumont Pathe/QTGuiServerProject/Resources/Medias/foot.mp4" ) );
    play == true? m_pQMediaPlayer->play(): ui.DisplayLayout->removeWidget( m_pQVideoWidget );
}

void MediaPlayer::go2()
{
    m_pQMediaPlayer->pause();
    ui.DisplayLayout->removeWidget( ui.waitingWidget );
    ui.DisplayLayout->addWidget( m_pQVideoWidget );
    this->showMaximized();
   // _sleep( 500 );

    m_pQMediaPlayer->play();

    //this->showFullScreen();
}