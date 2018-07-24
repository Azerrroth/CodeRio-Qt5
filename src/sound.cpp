#include "sound.h"


Sound::Sound(QString s)
{
    address=s;
    ppplay();
}

Sound::~Sound()
{
    delete player;
}

void Sound::ppplay()
{
    player =new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile(address));//设置音频路径
    player->setVolume(30);//设置音量
    player->play();
    return;
}
