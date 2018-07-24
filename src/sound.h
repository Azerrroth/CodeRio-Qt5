#ifndef SOUND_H
#define SOUND_H

#include <QThread>
#include <QMediaPlayer>
#include <QMediaPlaylist>

//碰金币、死亡、开局、开始音乐、BGM、
class Sound: public QThread
{
    Q_OBJECT
public:
    Sound(QString s);
    ~Sound();
    void ppplay();
    QMediaPlayer *player;

    QString address;


};

#endif // SOUND_H
