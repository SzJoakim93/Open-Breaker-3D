#include "Hang.h"

Hang::Hang()
{
    //ctor
    Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 512 ); //inicializalas
    music = NULL;
    maxObject = 0;

}

Hang::~Hang()
{
    //dtor
    //felszabaditas
    for (int i=0; i<maxObject; i++)
        Mix_FreeChunk(sound[i]);
    Mix_CloseAudio();

    if (maxObject > 0)
        delete [] sound;
}

void Hang::hozzaad(char ** ujhang, int Objectszam)
{
    Mix_Chunk** temp = new Mix_Chunk*[maxObject+Objectszam];

    for (int i=0; i<maxObject; i++)
        temp[i] = sound[i];

    for (int i=0; i<Objectszam; i++)
        temp[maxObject+i] = Mix_LoadWAV(ujhang[i]); //hang betoltese

    if (maxObject > 0)
        delete [] sound;

    maxObject+=Objectszam;

    sound = temp;

}

void Hang::play_music(char * path)
{
    music = Mix_LoadMUS(path); //zene betoltese
    Mix_PlayMusic(music, -1); //lejatszas 2. parameter: hanyszor ismetelje meg (-1: vegtelenszer)
}

void Hang::play_sound(const int & i, const int & chanel)
{
    Mix_PlayChannel(chanel , sound[i], 0 ); //hang lejatszasa
}

void Hang::stop()
{
    Mix_HaltMusic(); //megszakitas
    Mix_FreeMusic(music);
}
