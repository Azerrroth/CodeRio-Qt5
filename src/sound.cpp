#include "sound.h"


Sound::Sound(QString s)
{
    address=s;
    run();
}

void Sound::run()
{
    player =new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile(address));//设置音频路径
    player->setVolume(50);//设置音量
    player->play();
}
