class QTWebServer;
class MediaPlayer;
class RequestsHandler;


#pragma once
class ApplicationManager
{
public:
    ApplicationManager();
    ~ApplicationManager();

private:
    QTWebServer * m_pQTWebServer;
    MediaPlayer * m_pMediaPlayer;
    RequestsHandler * m_pRequestsHandler;
};

