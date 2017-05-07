#pragma once

#include <QtWidgets/QMainWindow>
#include <QMediaPlayer>
#include <QtGui/QMovie>
#include "videowidget.h"


#include "ui_GaumontMediaDisplay.h"

QT_BEGIN_NAMESPACE
class QLabel;
class QPushButton;
class QMediaPlayer;
class QMediaPlaylist;
QT_END_NAMESPACE


class MediaPlayer : public QMainWindow
{
    Q_OBJECT

private:
    Ui::QTMediaPlayerClass ui;
    QMediaPlayer * m_pQMediaPlayer;
    QVideoWidget * m_pQVideoWidget;
    QMediaPlaylist * m_pQPlaylistPathe;
    QMediaPlaylist * m_pQPlaylistPub1;
    QMediaPlaylist * m_pQPlaylistLive;
    QMediaPlaylist * m_pQPlaylistPub2;


public:
    MediaPlayer( QWidget *parent = Q_NULLPTR);
    ~MediaPlayer();

    public slots:
    void statusChanged( QMediaPlayer::MediaStatus status );
    void plastronGo();
    void go( QString p_QStringPlayList);
    void go2();
};

