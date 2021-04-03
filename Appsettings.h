#ifndef APPSETTINGS_H
#define APPSETTINGS_H

typedef enum Language { ENG, HUN };
typedef enum ApplicationState { RUN, QUIT, RESTART };

class Appsettings
{
public:
    Appsettings(/* args */);
    ~Appsettings();
    void load();
    void save();
    const int & getWidth();
    const int & getHeight();
    const int & getDepth();
    const float & getNear();
    const float  &getFar();
    const bool & isFullscreen();
    const bool & isSoundEnabled();
    const bool & isMusicEnabled();
    const Language & getLanguage();
private:
    int  width; // Az ablak szelessege pixelben.
    int  height; // Az ablak magassaga pixelben.
    int depth; // Szinmelyseg
    bool fullscreen; // Az ablak teljes kepernyos beallitasa.
    bool soundEnabled;
    bool musicEnabled;
    Language language;
    float near; //a latotavolsag kezdete
    float far; //latotavolsag
    bool modifyed;
};

#endif //Appsettings_H