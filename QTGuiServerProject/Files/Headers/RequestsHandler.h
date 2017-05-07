#pragma once
#include <QObject>

class QTWebServer;
class MediaPlayer;

QT_BEGIN_NAMESPACE
class QWebSocket;
QT_END_NAMESPACE

class RequestsHandler : public QObject
{
    Q_OBJECT

public:
    RequestsHandler();
    ~RequestsHandler();

    void setConnections( QTWebServer* p_pQTWebServer, MediaPlayer* p_pMediaPlayer );

    public slots:
    void processTextMessage( QString message );
    void processBinaryMessage( QByteArray message );

signals:
    void ManageTextClientResponse( QWebSocket *pClient, QString message );
    void ManageBinaryClientResponse( QWebSocket *pClient, QByteArray message );
    void PrepareVideo( QString );
    void StartVideo();


private:
    QTWebServer* m_pQTWebServer;
};

