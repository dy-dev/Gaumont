#pragma once


//#include "videowidget.h"
//
#include <QWidget>
//#include <QMediaPlayer>
//#include <QMediaPlaylist>
//
//QT_BEGIN_NAMESPACE
//class QAbstractItemView;
//class QLabel;
//class QMediaPlayer;
//class QModelIndex;
//class QPushButton;
//class QSlider;
//class QVideoProbe;
//class QVideoWidget;
//QT_END_NAMESPACE
//
//class PlaylistModel;
//class HistogramWidget;

class FullMediaPlayerWithList: public QWidget
{
    Q_OBJECT

public:
    FullMediaPlayerWithList( QWidget *parent = 0 );
    ~FullMediaPlayerWithList();
//
//  /*  bool isPlayerAvailable() const;
//
//    void addToPlaylist( const QList<QUrl> urls );
//  */  void go();
//
//
//signals:
//    void fullScreenChanged( bool fullScreen );
//
//    private slots:
//    /*void open();
//    void durationChanged( qint64 duration );
//   */ void positionChanged( qint64 progress );
//   /* void metaDataChanged();
//
//    void previousClicked();
//
//    void seek( int seconds );
//    void jump( const QModelIndex &index );
//    void playlistPositionChanged( int );
//   */
//    void statusChanged( QMediaPlayer::MediaStatus status );
//    void bufferingInProgress( int progress );
//    /*void videoAvailableChanged( bool available );
//
//    void displayErrorMessage();
//
//    void showColorDialog();
//
//private:
//    void setTrackInfo( const QString &info );
//    */void setStatusInfo( const QString &info );
//    void handleCursor( QMediaPlayer::MediaStatus status );
//    /*void updateDurationInfo( qint64 currentInfo );
//      */
//private:
//    QMediaPlayer *player;
//    QMediaPlaylist *playlist;
//    QVideoWidget *videoWidget;
//    QLabel *coverLabel;
//    QSlider *slider;
//    QLabel *labelDuration;
//    QPushButton *fullScreenButton;
//    QPushButton *colorButton;
//    QDialog *colorDialog;
//
//    QLabel *labelHistogram;
//    HistogramWidget *histogram;
//    QVideoProbe *probe;
//
//    PlaylistModel *playlistModel;
//    QAbstractItemView *playlistView;
//    QString trackInfo;
//    QString statusInfo;
//    qint64 duration;
};
