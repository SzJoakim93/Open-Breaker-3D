#include <cstdio>

#include "Appsettings.h"

Appsettings::Appsettings(/* args */)
{
    load();
    this->depth = 32;
    this->near = 0.2;
    this->far = 30.0;
    this->modifyed = false;
}

Appsettings::~Appsettings()
{
    if (modifyed)
        save();
}

void Appsettings::load()
{
    FILE * file = fopen("settings.ini", "r");

    int temp;
    fscanf(file, "screen_width=%d\n", &width);
    fscanf(file, "screen_height=%d\n", &height);
    fscanf(file, "fullscreen=%d\n", &temp);
    fullscreen=temp;
	fscanf(file, "sound=%d\n", &temp);
	soundEnabled= temp;
	fscanf(file, "music=%d\n", &temp);
	musicEnabled= temp;
	fscanf(file, "language=%d\n", &language);

	fclose(file);
}

void Appsettings::save()
{
    FILE * file = fopen("settings.ini", "w");
    fprintf(file, "screen_width=%d\n", width);
    fprintf(file, "screen_height=%d\n", height);
    fprintf(file, "fullscreen=%d\n", fullscreen);
    fprintf(file, "sound=%d\n", soundEnabled);
    fprintf(file, "music=%d\n", musicEnabled);
    fprintf(file, "language=%d\n", language);

    fclose(file);
}

const int & Appsettings::getWidth()
{
    return width;
}

const int & Appsettings::getHeight()
{
    return height;
}

const int & Appsettings::getDepth()
{
    return depth;
}

const float & Appsettings::getNear()
{
    return near;
}

const float & Appsettings::getFar()
{
    return far;
}

const bool & Appsettings::isFullscreen()
{
    return fullscreen;
}

const bool & Appsettings::isSoundEnabled()
{
    return soundEnabled;
}

const bool & Appsettings::isMusicEnabled()
{
    return musicEnabled;
}

const Language & Appsettings::getLanguage()
{
    return language;
}
