#include "Sound.h"

Sound::Sound(Appsettings * appsettings)
{
    //ctor
    Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 512 ); //inicializalas
    music = NULL;
    maxObject = 0;
    soundEnabled = &(appsettings->isSoundEnabled());
    musicEnabled = &(appsettings->isMusicEnabled());
}

Sound::~Sound()
{
    //dtor
    //felszabaditas
    for (int i=0; i<maxObject; i++)
        Mix_FreeChunk(sound[i]);
    Mix_CloseAudio();

    if (maxObject > 0)
        delete [] sound;
}

void Sound::add(char ** soundArray, int count)
{
    Mix_Chunk** temp = new Mix_Chunk*[maxObject+count];

    //Copy existing sounds to the new array
    for (int i=0; i<maxObject; i++)
        temp[i] = sound[i];

    for (int i=0; i<count; i++)
        temp[maxObject+i] = Mix_LoadWAV(soundArray[i]); //Load sounds

    if (maxObject > 0)
        delete [] sound;

    maxObject += count;

    sound = temp;

}

void Sound::play_music(char * path)
{
    if (*musicEnabled)
    {
        music = Mix_LoadMUS(path); //zene betoltese
        Mix_PlayMusic(music, -1); //lejatszas 2. parameter: hanyszor ismetelje meg (-1: vegtelenszer)
    }
    
}

void Sound::play_sound(const int & i, const int & chanel)
{
    if (*soundEnabled)
        Mix_PlayChannel(chanel , sound[i], 0 ); //Sound lejatszasa
}

void Sound::stop()
{
    Mix_HaltMusic(); //megszakitas
    Mix_FreeMusic(music);
}
