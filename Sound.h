#ifndef HANG_H
#define HANG_H

#include "SDL/SDL_mixer.h"

class Sound
{
    public:
        Sound();
        ~Sound();
        void play_music(char * path); //zene lejatszasa
        void play_sound(const int & i, const int & chanel); //Sound lejatszasa
        void stop(); //zene leallitasa
        void hozzaad(char ** ujhang, int Objectszam);
    protected:
    private:
        Mix_Music* music; //zene valtozoja
        Mix_Chunk** sound; //Sound valtozoja
        int maxObject;
};

#endif // HANG_H
