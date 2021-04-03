#ifndef UI_LABEL_H
#define UI_LABEL_H

#include "vector.h"

#include "UI.h"
#include "Texture.h"
#include "Model.h"

class UI_Label : public UI
{
public:
    UI_Label(float tx, float ty, float sx, float sy, char* texname, char* _title);
    ~UI_Label();
    void rendering();
    void setText(const char * _text);
    const char * getText();
    bool clicked(const int mouse_x, const int mouse_y, const int width, const int height);
private:
    char title[32];
    eCoord2f global_scale;
    void setGlobalScale();
};

#endif //UI_Label_H