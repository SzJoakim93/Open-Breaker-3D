#include "Menu.h"

Menu::Menu(Top * top, int * s_width, int * s_height, bool * valtozas, int * language)
{
    cursor = 0;
    maxcursor = 6;
    this->language = language;
    int i=0;

    bool van=true;

    /**A menu Objectei:**/
    char lang_path[32];
    if (*language == 0)
    {
        strcpy(lang_path, "Fonts/hungarian/");
        strcpy(on_title, "be");
        strcpy(off_title, "ki");
    }
    else
    {
        strcpy(lang_path, "Fonts/english/");
        strcpy(on_title, "on");
        strcpy(off_title, "off");
    }



    Objectek[0] = new Object(0.0, 0.0, 0.0, //koordinatak
                             0, 0, 0, //elforgatas
                             0.135, 1.0, 0.18, //atmeretezes
                             true, "Textures/title.bmp", 0, "negyzet", 3, 0);


    Objectek[1] = new Object(-0.03, -0.098, 0.0, //koordinatak
                             0, 0, 0, //elforgatas
                             0.014, 1.0, 0.028, //atmeretezes
                             true, "Fonts/english/start.bmp", 0, "negyzet", 3, 0);

    char temp[32];
    strcpy(temp, lang_path);
    strcat(temp, "settings.bmp");
    Objectek[2] = new Object(0.0, -0.098, 0.0, //koordinatak
                             0, 0, 0, //elforgatas
                             0.014, 1.0, 0.028, //atmeretezes
                             true, temp, 0, "negyzet", 3, 0);

    strcpy(temp, lang_path);
    strcat(temp, "scores.bmp");
    Objectek[3] = new Object(0.03, -0.098, 0.0, //koordinatak
                             0, 0, 0, //elforgatas
                             0.014, 1.0, 0.028, //atmeretezes
                             true, temp, 0, "negyzet", 3, 0);

    strcpy(temp, lang_path);
    strcat(temp, "help.bmp");
    Objectek[4] = new Object(0.06, -0.098, 0.0, //koordinatak
                             0, 0, 0, //elforgatas
                             0.014, 1.0, 0.028, //atmeretezes
                             true, temp, 0, "negyzet", 3, 0);

    strcpy(temp, lang_path);
    strcat(temp, "about.bmp");
    Objectek[5] = new Object(0.09, -0.098, 0.0, //koordinatak
                             0, 0, 0, //elforgatas
                             0.014, 1.0, 0.028, //atmeretezes
                             true, temp, 0, "negyzet", 3, 0);

    strcpy(temp, lang_path);
    strcat(temp, "quit.bmp");
    Objectek[6] = new Object(0.12, -0.098, 0.0, //koordinatak
                             0, 0, 0, //elforgatas
                             0.014, 1.0, 0.028, //atmeretezes
                             true, temp, 0, "negyzet", 3, 0);


    strcpy(temp, lang_path);
    strcat(temp, "Help_w.bmp");
    Objectek[7] = new Object(0.0, 0.0, 0.0, //koordinatak
                             0, 0, 0, //elforgatas
                             0.22, 1.0, 0.22, //atmeretezes
                             true, temp, 0, "negyzet", 3, 0);

    strcpy(temp, lang_path);
    strcat(temp, "About_w.bmp");
    Objectek[8] = new Object(0.0, 0.00, 0.0, //koordinatak
                             0, 0, 0, //elforgatas
                             0.11, 1.0, 0.22, //atmeretezes
                             true, temp, 0, "negyzet", 3, 0);

    Objectek[9] = new Object(0.0, -0.08, 0.5, //koordinatak
                             0, 0, 0, //elforgatas
                             0.014, 1.0, 0.028, //atmeretezes
                             true, "Fonts/english/OK.bmp", 0, "negyzet", 3, 0);

    Objectek[10] = new Object(-0.03, -0.098, 0.0, //koordinatak
                             0, 0, 0, //elforgatas
                             0.014, 1.0, 0.028, //atmeretezes
                             true, "Fonts/english/start_c.bmp", 0, "negyzet", 3, 0);

    Objectek[11] = new Object(0.0, -0.098, 0.0, //koordinatak
                             0, 0, 0, //elforgatas
                             0.014, 1.0, 0.028, //atmeretezes
                             true, "Fonts/english/settings_c.bmp", 0, "negyzet", 3, 0);

    Objectek[12] = new Object(0.03, -0.098, 0.0, //koordinatak
                             0, 0, 0, //elforgatas
                             0.014, 1.0, 0.028, //atmeretezes
                             true, "Fonts/english/scores_c.bmp", 0, "negyzet", 3, 0);

    Objectek[13] = new Object(0.06, -0.098, 0.0, //koordinatak
                             0, 0, 0, //elforgatas
                             0.014, 1.0, 0.028, //atmeretezes
                             true, "Fonts/english/help_c.bmp", 0, "negyzet", 3, 0);

    Objectek[14] = new Object(0.09, -0.098, 0.0, //koordinatak
                             0, 0, 0, //elforgatas
                             0.014, 1.0, 0.028, //atmeretezes
                             true, "Fonts/english/about_c.bmp", 0, "negyzet", 3, 0);

    Objectek[15] = new Object(0.12, -0.098, 0.0, //koordinatak
                             0, 0, 0, //elforgatas
                             0.014, 1.0, 0.028, //atmeretezes
                             true, "Fonts/english/quit_c.bmp", 0, "negyzet", 3, 0);

    Objectek[16] = new Object(0.0, -0.08, 0.5, //koordinatak
                             0, 0, 0, //elforgatas
                             0.014, 1.0, 0.028, //atmeretezes
                             true, "Fonts/english/OK_c.bmp", 0, "negyzet", 3, 0);

    Objectek[17] = new Object(0.0, 0.0, 0.0, //koordinatak
                             0, 0, 0, //elforgatas
                             0.155, 1.0, 0.22, //atmeretezes
                             true, "Fonts/english/Scores_w.bmp", 0, "negyzet", 3, 0);

    Objectek[18] = new Object(0.0, 0.0, 0.0, //koordinatak
                             0, 0, 0, //elforgatas
                             0.22, 1.0, 0.22, //atmeretezes
                             true, "Fonts/english/Settings_w.bmp", 0, "negyzet", 3, 0);

    Objectek[19] = new Object(0.0, 0.01, 0.0, //koordinatak
                             0, 0, 0, //elforgatas
                            0.005, 1.0, 0.0025, //atmeretezes
                             true, "Fonts/letters", 0, "negyzet", 4, 0);

    Objectek[20] = new Object(0.0, 0.0, 0.0, //koordinatak
                             0, 0, 0, //elforgatas
                             0.005, 1.0, 0.0025, //atmeretezes
                             true, "Fonts/letters", 0, "negyzet", 4, 0);
    for (int i=0; i<10; i++)
        score_titles[i] = new Object(0.02, 0.053-0.0105*i, 0.0, //koordinatak
                             0, 0, 0, //elforgatas
                             0.005, 1.0, 0.0025, //atmeretezes
                             true, "Fonts/letters", 0, "negyzet", 4, 0);

    for (int i=0; i<10; i++)
        player_titles[i] = new Object(-0.05, 0.053-0.0105*i, 0.0, //koordinatak
                             0, 0, 0, //elforgatas
                             0.005, 1.0, 0.0025, //atmeretezes
                             true, "Fonts/letters", 0, "negyzet", 4, 0);

    sound_title = new Object(0.035, 0.013, 0.0, //koordinatak
                             0, 0, 0, //elforgatas
                             0.005, 1.0, 0.0025, //atmeretezes
                             true, "Fonts/letters", 0, "negyzet", 4, 0);

    music_title = new Object(0.035, 0.0, 0.0, //koordinatak
                             0, 0, 0, //elforgatas
                             0.005, 1.0, 0.0025, //atmeretezes
                             true, "Fonts/letters", 0, "negyzet", 4, 0);

    screen_title = new Object(0.035, -0.013, 0.0, //koordinatak
                             0, 0, 0, //elforgatas
                             0.005, 1.0, 0.0025, //atmeretezes
                             true, "Fonts/letters", 0, "negyzet", 4, 0);

    frame = new Object(0.04, -0.013, 0.0, //koordinatak
                             0, 0, 0, //elforgatas
                             0.012, 1.0, 0.027, //atmeretezes
                             true, "Fonts/frame.bmp", 0, "negyzet", 3, 0);

    lang_title = new Object(0.03, -0.039, 0.0, //koordinatak
                             0, 0, 0, //elforgatas
                             0.005, 1.0, 0.0025, //atmeretezes
                             true, "Fonts/letters", 0, "negyzet", 4, 0);

    res_title = new Object(0.03, -0.026, 0.0, //koordinatak
                             0, 0, 0, //elforgatas
                             0.005, 1.0, 0.0025, //atmeretezes
                             true, "Fonts/letters", 0, "negyzet", 4, 0);

    screen_settings = new Object* [16];

    for (int i=0; i<16; i++)
        screen_settings[i] = new Object(-0.06+0.1*(i/9), 0.06-0.01*(i%9), 0.0, //koordinatak
                                0, 0, 0, //elforgatas
                                0.005, 1.0, 0.0025, //atmeretezes
                                true, "Fonts/letters", 0, "negyzet", 4, 0);

    FILE * packages = fopen("Levels/Packages.txt", "r");
    fscanf(packages, "%d\n", &max_package);
    obj_game_titles = new Object* [max_package];
    char char_game_titles[32];

    for (int j=0; j<max_package; j++)
    {
        fscanf(packages, "%s\n", char_game_titles);
        obj_game_titles[j] = new Object(-0.06+0.06*j, 0.06, 0.0, //koordinatak
                                0, 0, 0, //elforgatas
                                0.05, 1.0, 0.05, //atmeretezes
                                true, char_game_titles, 0, "negyzet", 3, 0);
    }

    fclose(packages);

    this->top = top;
    this->s_width = s_width;
    this->s_height = s_height;
    this->valtozas = valtozas;
}

Menu::~Menu()
{
    for (int i=0; i<20; i++)
        delete Objectek[i];


    for (int i=0; i<10; i++)
        delete score_titles[i];

    for (int i=0; i<10; i++)
        delete player_titles[i];

    delete sound_title;
    delete music_title;
    delete screen_title;
    delete frame;
    delete lang_title;
    delete res_title;



    for (int i=0; i<16; i++)
        delete screen_settings[i];
    delete [] screen_settings;

    for (int j=0; j<max_package; j++)
        delete obj_game_titles[j];
    delete [] obj_game_titles;
}

void Menu::fel(int & jatekresz)
{
    if (jatekresz == 9)
        cursor-=3;
    else
        cursor--;

    if (cursor < 0)
        cursor = maxcursor - 1;

    if (jatekresz == 2)
    {
        if (cursor == 0)
            frame->setty(0.013);
        else if (cursor == 1)
            frame->setty(0.0);
        else if (cursor == 2)
        frame->setty(-0.013);
        else if (cursor == 3)
            frame->setty(-0.026);
        else if (cursor == 4)
            frame->setty(-0.039);
    }
    else if (jatekresz == 6)
    {
        frame->settx(-0.05+(cursor/9)*0.105);
        frame->setty(0.06-(cursor%9)*0.01);
    }
    else if (jatekresz == 9)
    {
        frame->settx(-0.06+(cursor%3)*0.06);
        frame->setty(0.06-(cursor/3)*0.06);
    }

    set_selected = true;
    selected = cursor;
}

void Menu::le(int & jatekresz)
{
    if (jatekresz == 9)
        cursor+=3;
    else
        cursor++;

    if (cursor >= maxcursor)
        cursor = 0;

    if (jatekresz == 9)
    {
        frame->settx(-0.06+(cursor%3)*0.06);
        frame->setty(0.06-(cursor/3)*0.06);
    }
    else if (jatekresz == 6)
    {
        frame->settx(-0.05+(cursor/9)*0.105);
        frame->setty(0.06-(cursor%9)*0.01);
    }
    else if (jatekresz == 2)
    {
        if (cursor == 0)
            frame->setty(0.013);
        else if (cursor == 1)
            frame->setty(0.0);
        else if (cursor == 2)
            frame->setty(-0.013);
        else if (cursor == 3)
            frame->setty(-0.026);
        else if (cursor == 4)
            frame->setty(-0.039);
    }

    set_selected = true;
    selected = cursor;

}

void Menu::balra(int & jatekresz)
{
    if (jatekresz == 6)
        cursor-=9;
    else
        cursor --;

    if (cursor < 0)
        cursor = 0;

    if (jatekresz == 9)
    {
        frame->settx(-0.06+(cursor%3)*0.06);
        frame->setty(0.06-(cursor/3)*0.06);
    }
    else if (jatekresz == 6)
    {
        frame->settx(-0.05+(cursor/9)*0.105);
        frame->setty(0.06-(cursor%9)*0.01);
    }

    set_selected = true;
    selected = cursor;

}

void Menu::jobbra(int & jatekresz)
{
    /*if (jatekresz == 9 && cursor < maxcursor-1)
    {
        frame->trans_horizontal(0.06);
        if (frame->gettx() > 0.06)
            frame->settz(-0.06);
    }*/

    if (jatekresz == 6)
        cursor+=9;
    else
        cursor++;

    if (cursor >= maxcursor)
        cursor = maxcursor - 1;

    if (jatekresz == 9)
    {
        frame->settx(-0.06+(cursor%3)*0.06);
        frame->setty(0.06-(cursor/3)*0.06);
    }
    else if (jatekresz == 6)
    {
        frame->settx(-0.05+(cursor/9)*0.105);
        frame->setty(0.06-(cursor%9)*0.01);
    }


    set_selected = true;
    selected = cursor;
}

int Menu::getcursor()
{
    return cursor;
}

void Menu::setmaxcursor(int becursor)
{
    maxcursor = becursor;
}

void Menu::setcursor(int becursor)
{
    cursor = becursor;
    setcursor();

}

void Menu::setcursor()
{

    /*if  (maxcursor > 9)
    {
        Objectek[18]->settx(-0.11+(cursor/9)*(0.125));
        Objectek[18]->setty((cursor%9)*(-0.02)+0.08);
    }
    else if  (maxcursor == 9)
        Objectek[18]->setty(cursor*(-0.02)+0.08);
    else if (maxcursor == 8)
        Objectek[18]->setty(cursor*(-0.02)+0.06);
    else if  (maxcursor == 7)
        Objectek[18]->setty(cursor*(-0.02)+0.04);
    else if  (maxcursor == 6)
        Objectek[18]->setty(cursor*(-0.02)+0.02);
    else
        Objectek[18]->setty(cursor*(-0.02));*/
}

void Menu::rendering(int & jatekresz)
{
    if (jatekresz == 0)
        Objectek[0]->rendering(0);
    if (selected == 0)
        Objectek[10]->rendering(0);
    else
        Objectek[1]->rendering(0);
    if (selected == 1)
        Objectek[11]->rendering(0);
    else
        Objectek[2]->rendering(0);
    if (selected == 2)
        Objectek[12]->rendering(0);
    else
        Objectek[3]->rendering(0);
    if (selected == 3)
        Objectek[13]->rendering(0);
    else
        Objectek[4]->rendering(0);
    if (selected == 4)
        Objectek[14]->rendering(0);
    else
        Objectek[5]->rendering(0);
    if (selected == 5)
        Objectek[15]->rendering(0);
    else
        Objectek[6]->rendering(0);

    if (jatekresz > 1 && jatekresz < 7)
    {
        if (selected == 6)
            Objectek[16]->rendering(0);
        else
            Objectek[9]->rendering(0);
    }

    if (jatekresz == 4)
        Objectek[7]->rendering(0);
    if (jatekresz == 5)
        Objectek[8]->rendering(0);
    if (jatekresz == 2)
    {
        if (*hang)
            sound_title->gprintf(on_title);
        else
            sound_title->gprintf(off_title);

        if (*zene)
            music_title->gprintf(on_title);
        else
            music_title->gprintf(off_title);

        if (*fullscreen)
            screen_title->gprintf(on_title);
        else
            screen_title->gprintf(off_title);

        char temp[16];
        sprintf(temp, "%dx%d", *s_width, *s_height);
        res_title->gprintf(temp);

        if (*language == 0)
            lang_title->gprintf("magyar");
        else
            lang_title->gprintf("english");

        if (set_selected)
            frame->rendering(0);

        Objectek[18]->rendering(0);
    }

    if (jatekresz == 6)
    {
        screen_settings[0]->gprintf("320x200");
        screen_settings[1]->gprintf("320x240");
        screen_settings[2]->gprintf("400x300");
        screen_settings[3]->gprintf("640x480");
        screen_settings[4]->gprintf("800x468");
        screen_settings[5]->gprintf("848x480");
        screen_settings[6]->gprintf("800x600");
        screen_settings[7]->gprintf("1024x768");
        screen_settings[8]->gprintf("1152x864");
        screen_settings[9]->gprintf("1280x720");
        screen_settings[10]->gprintf("1280x800");
        screen_settings[11]->gprintf("1280x960");
        screen_settings[12]->gprintf("1280x1024");
        screen_settings[13]->gprintf("1366x768");
        screen_settings[14]->gprintf("1366x1024");
        screen_settings[15]->gprintf("custom");
        frame->rendering(0);
    }

    if (jatekresz == 3)
    {
        for (int i=0; i<10; i++)
        {
            char temp[7];
            sprintf(temp, "%d", top[i].score);
            score_titles[i]->gprintf(temp);
            player_titles[i]->gprintf(top[i].name);
        }
        Objectek[17]->rendering(0);

    }

    if (jatekresz == 9)
    {
        for (int i=0; i<max_package; i++)
            obj_game_titles[i]->rendering(0);
        frame->rendering(0);
    }


}

void Menu::rendering_res(int & jatekresz, int & setres)
{
    char temp[30];

    if (jatekresz == 7)
        Objectek[19]->gprintf("sz/1less/1g");
    else if (jatekresz == 8)
        Objectek[19]->gprintf("magass/0g");
    sprintf(temp, "%d", setres);
    Objectek[20]->gprintf(temp);
}

void Menu::sethangok(bool * behang, bool * bezene, bool * befullscreen)
{
    hang = behang;
    zene = bezene;
    fullscreen = befullscreen;
    if (*zene)
        hangok.play_music("Music/s.mid");
}

void Menu::enter(int & jatekresz, int & quit, Jatek & jatek, int & width, int & height, int & setres)
{
    switch (jatekresz)
                {
                    case 0: //fomenu
                    {
                        if (cursor == 0)
                        {
                            maxcursor = max_package;
                            setcursor(0);
                            jatekresz = 9;
                            frame->settx(-0.06);
                            frame->setty(0.06);
                            frame->setsx(0.06);
                            frame->setsz(0.06);
                        }
                        else if (cursor == 1)
                        {
                            maxcursor = 5;
                            cursor = 0;
                            jatekresz = 2;
                            Objectek[9]->setty(-0.051);
                            Objectek[16]->setty(-0.051);
                            frame->settx(0.04);
                            frame->setty(0.013);
                            frame->setsx(0.012);
                            frame->setsz(0.027);
                        }

                        else if (cursor == 2)
                        {
                            jatekresz = 3;
                            Objectek[9]->setty(-0.065);
                            Objectek[16]->setty(-0.065);
                        }
                        else if (cursor == 3)
                        {
                            jatekresz = 4;
                            Objectek[9]->setty(-0.08);
                            Objectek[16]->setty(-0.08);
                        }
                        else if (cursor == 4)
                        {
                            jatekresz = 5;
                            Objectek[9]->setty(-0.041);
                            Objectek[16]->setty(-0.041);
                        }
                        else if (cursor == 5)
                            quit = 1;

                        break;
                    }
                    case 2: //settings
                    {
                        if (cursor == 0)
                        {
                            if (*hang)
                                *hang = false;
                            else
                                *hang = true;
                        }
                        else if (cursor == 1)
                        {
                            if (*zene)
                                *zene = false;
                            else
                                *zene = true;
                        }
                        else if (cursor == 2)
                        {
                            if (*fullscreen)
                                *fullscreen = false;
                            else
                                *fullscreen = true;
                        }
                        else if (cursor == 3)
                        {
                            jatekresz = 6;
                            cursor=0;
                            maxcursor=16;
                            frame->settx(-0.05);
                            frame->setty(0.06);
                            frame->setsx(0.012);
                            frame->setsz(0.035);
                        }
                        else if (cursor == 4)
                        {
                            if (*language == 0)
                                *language = 1;
                            else
                                *language = 0;
                        }
                        *valtozas = true;
                        break;
                    }
                    case 3:
                    case 4:
                    case 5:
                    {
                        jatekresz = 0;
                        break;
                    }
                    case 6: //felbontas
                    {
                        if (cursor == 0)
                        {
                            *s_width = 320;
                            *s_height = 200;
                        }

                        if (cursor == 1)
                        {
                            *s_width = 320;
                            *s_height = 240;
                        }

                        if (cursor == 2)
                        {
                            *s_width = 400;
                            *s_height = 300;
                        }

                        if (cursor == 3)
                        {
                            *s_width = 640;
                            *s_height = 480;
                        }

                        if (cursor == 4)
                        {
                            *s_width = 800;
                            *s_height = 468;
                        }

                        if (cursor == 5)
                        {
                            *s_width = 848;
                            *s_height = 480;
                        }

                        if (cursor == 6)
                        {
                            *s_width = 800;
                            *s_height = 600;
                        }

                        if (cursor == 7)
                        {
                            *s_width = 1024;
                            *s_height = 768;
                        }

                        if (cursor == 8)
                        {
                            *s_width = 1152;
                            *s_height = 864;
                        }

                        if (cursor == 9)
                        {
                            *s_width = 1280;
                            *s_height = 720;
                        }

                        if (cursor == 10)
                        {
                            *s_width = 1280;
                            *s_height = 800;
                        }

                        if (cursor == 11)
                        {
                            *s_width = 1280;
                            *s_height = 960;
                        }

                        if (cursor == 12)
                        {
                            *s_width = 1280;
                            *s_height = 1024;
                        }

                        if (cursor == 13)
                        {
                            *s_width = 1366;
                            *s_height = 768;
                        }

                        if (cursor == 14)
                        {
                            *s_width = 1366;
                            *s_height = 1024;
                        }

                        if (cursor == 15)
                            jatekresz = 7;

                        if (cursor != 15)
                        {
                            quit = 2;
                            cursor=0;
                            maxcursor = 4;
                            *valtozas = true;
                        }


                        break;
                    }

                    case 7:
                    {
                        *s_width = setres;
                        setres = 0;
                        jatekresz = 8;
                        break;
                    }

                    case 8:
                    {
                        *s_height = setres;
                        setres = 0;
                        jatekresz = 6;
                        *valtozas = true;
                        quit = 2;
                        break;
                    }
                    case 9:
                    {
                        hangok.stop();
                        jatekresz = 1;
                        jatek.start(cursor*10+1);
                        break;
                    }
                }
}

void Menu::mouse_event(const int & x, const int & y, int & jatekresz, Jatek & jatek, int & quit, bool isClicked, Uint8 & isMouseMoving)
{
    float multipler = *s_height / 480.0;
    int offset = (*s_width-640.0*multipler)/2.0;


    if (x > 222.0*multipler+offset && x < 620*multipler+offset &&  y > 450.0*multipler && y < 480*multipler)
    {
        //start
        if (x < 278.0*multipler+offset)
        {
            if (isClicked)
            {
                setcursor(0);
                maxcursor = max_package;
                jatekresz = 9;
                frame->settx(-0.06);
                frame->setty(0.06);
                frame->setsx(0.06);
                frame->setsz(0.06);
            }
            selected = 0;
        }
        //settings
        else if (x < 355.0*multipler+offset)
        {
            if (isClicked)
            {
                jatekresz = 2;
                Objectek[9]->setty(-0.051);
                Objectek[16]->setty(-0.051);
                cursor = 0;
                maxcursor = 5;
                frame->settx(0.04);
                frame->setty(0.013);
                frame->setsx(0.012);
                frame->setsz(0.027);
            }

            selected = 1;
        }
        //scores
        else if (x < 427.0*multipler+offset)
        {
            if (isClicked)
            {
                cursor = 0;
                maxcursor = 6;
                jatekresz = 3;
                Objectek[9]->setty(-0.065);
                Objectek[16]->setty(-0.065);
            }

            selected = 2;
        }
        //help
        else if (x < 490.0*multipler+offset)
        {
            if (isClicked)
            {
                cursor = 0;
                maxcursor = 6;
                jatekresz = 4;
                Objectek[9]->setty(-0.08);
                Objectek[16]->setty(-0.08);
            }

            selected = 3;

        }

        //about
        else if (x < 560.0*multipler+offset)
        {
            if (isClicked)
            {
                cursor = 0;
                maxcursor = 6;
                jatekresz = 5;
                Objectek[9]->setty(-0.041);
                Objectek[16]->setty(-0.041);
            }
            selected = 4;
        }
        //quit
        else
        {
            if (isClicked)
                quit = 1;
            selected = 5;
        }
    }
    //ok
    else if (jatekresz == 4 && x > 295.0*multipler+offset && x < 337.0*multipler+offset && y > 410.0*multipler && y < 428.0*multipler ||
             (jatekresz == 5 || jatekresz == 2 || jatekresz == 6) && x > 300.0*multipler+offset && x < 344.0*multipler+offset && y > 321.0*multipler && y < 367.0*multipler ||
             jatekresz == 3 && x > 300.0*multipler+offset && x < 340.0*multipler+offset && y > 378.0*multipler && y < 400.0*multipler)
    {
        if (isClicked)
        {
            jatekresz = 0;
            cursor = 0;
            maxcursor = 6;
        }

        selected = 6;
    }
    else if (selected != -1 && isMouseMoving == SDL_MOUSEMOTION)
        selected = -1;

    if (jatekresz == 2 && x > 215.0*multipler+offset && x < 450.0*multipler+offset)
    {
        if (y > 200.0*multipler && y < 226.0*multipler)
        {
            if (isClicked)
            {
                *valtozas = true;
                if (*hang)
                    *hang = false;
                else
                    *hang = true;
            }
            set_selected=true;
            frame->setty(0.013);
        }
        else if (y > 226.0*multipler && y < 252.0*multipler)
        {
            if (isClicked)
            {
                *valtozas = true;
                if (*zene)
                    *zene = false;
                else
                    *zene = true;
            }
            set_selected=true;
            frame->setty(0.0);
        }

        else if (y > 252.0*multipler && y < 278.0*multipler)
        {
            if (isClicked)
            {
                *valtozas = true;
                if (*fullscreen)
                    *fullscreen = false;
                else
                    *fullscreen = true;
            }
            set_selected=true;
            frame->setty(-0.013);
        }

        else if (y > 278.0*multipler && y < 314.0*multipler)
        {
            if (isClicked)
            {
                cursor=0;
                maxcursor=16;
                frame->settx(-0.05);
                frame->setty(0.06);
                frame->setsx(0.012);
                frame->setsz(0.035);
                jatekresz = 6;
            }

            set_selected=true;
            frame->setty(-0.026);
        }
        else if (y > 314.0*multipler && y < 340.0*multipler)
        {
            if (isClicked)
            {
                *valtozas = true;
                if (*language == 0)
                    *language = 1;
                else
                    *language = 0;
            }

            set_selected=true;
            frame->setty(-0.039);
        }
        else if (isMouseMoving == SDL_MOUSEMOTION)
            set_selected=false;
    }
    else if (jatekresz == 6 && x > 160.0*multipler+offset && x < 470.0*multipler+offset && y > 90.0*multipler && y < 295.0*multipler)
    {
        frame->settx(-0.05+(int)((-160*multipler+x+offset)/(180*multipler+offset))*0.105);
        frame->setty(0.06-(int)((-85*multipler+y)/(25*multipler))*0.01);
        if (x < 340.0*multipler+offset)
        {
            if (y > 85.0*multipler && y < 110.0*multipler)
            {
                if (isClicked)
                {
                    *s_width = 320;
                    *s_height = 200;
                }
                set_selected=0;

            }
            else if (y > 110.0*multipler && y < 134.0*multipler)
            {
                if (isClicked)
                {
                    *s_width = 320;
                    *s_height = 240;
                }
                set_selected=1;

            }
            else if (y > 134.0*multipler && y < 158.0*multipler)
            {
                if (isClicked)
                {
                    *s_width = 400;
                    *s_height = 300;
                }
                set_selected=2;
            }
            else if (y > 158.0* multipler && y < 182.0*multipler)
            {
                if (isClicked)
                {
                    *s_width = 640;
                    *s_height = 480;
                }
                set_selected=2;

            }
            else if (y > 182.0* multipler && y < 203.0*multipler)
            {
                if (isClicked)
                {
                    *s_width = 800;
                    *s_height = 468;
                }
                set_selected=2;
            }
            else if (y > 203.0* multipler && y < 227.0*multipler)
            {
                if (isClicked)
                {
                    *s_width = 848;
                    *s_height = 480;
                }
                set_selected=2;
            }
            else if (y > 227.0*multipler && y < 250.0 * multipler)
            {
                if (isClicked)
                {
                    *s_width = 800;
                    *s_height = 600;
                }
                set_selected=2;
            }
            else if (y > 250.0* multipler && y < 274.0 * multipler)
            {
                if (isClicked)
                {
                    *s_width = 1024;
                    *s_height = 768;
                }
                set_selected=2;

            }
            else if (y > 274.0* multipler && y < 296.0 * multipler)
            {
                if (isClicked)
                {
                    *s_width = 1152;
                    *s_height = 864;
                }
                set_selected=2;
            }
        }
        else
        {
            if (y > 85.0*multipler && y < 110.0*multipler)
            {
                if (isClicked)
                {
                    *s_width = 1280;
                    *s_height = 720;
                }
                set_selected=2;
            }
            else if (y > 110.0*multipler && y < 134.0*multipler)
            {
                if (isClicked)
                {
                    *s_width = 1280;
                    *s_height = 800;
                }
                set_selected=2;
            }
            else if (y > 134.0*multipler && y < 158.0*multipler)
            {
                if (isClicked)
                {
                    *s_width = 1280;
                    *s_height = 960;
                }
                set_selected=2;
            }
            else if (y > 158.0* multipler && y < 182.0*multipler)
            {
                if (isClicked)
                {
                    *s_width = 1280;
                    *s_height = 1024;
                }
                set_selected=2;
            }
            else if (y > 182.0* multipler && y < 203.0*multipler)
            {
                if (isClicked)
                {
                    *s_width = 1366;
                    *s_height = 768;
                }
                set_selected=2;
            }
            else if (y > 203.0* multipler && y < 227.0*multipler)
            {
                if (isClicked)
                {
                    *s_width = 1366;
                    *s_height = 1024;
                }
                set_selected=2;
            }
            else if (y > 227.0*multipler && y < 250.0 * multipler)
            {
                //custom resolution
                if (isClicked)
                    jatekresz = 7;
            }
        }

        if (isClicked && (y < 285.0 * multipler || y > 315.0 * multipler))
        {
            *valtozas = true;
            jatekresz = 2;
            cursor = 0;
            maxcursor = 4;
            quit = 2;
        }

    }
    else if (jatekresz == 9)
    {
        if (x > 112.0*multipler+offset && x < 528*multipler+offset && y > 32.0*multipler && y < 447.0*multipler)
        {
            int temp = 3*(int)((y-31*multipler)/(139*multipler))+(x-111*multipler-offset)/(139*multipler);
            if (isClicked)
            {
                //int temp = ((int)((-32*multipler+y)/139*multipler)*3+(int)((-112*multipler+offset+x)/(139*multipler+offset)))*10;

                if (temp < max_package)
                {
                    hangok.stop();
                    jatekresz = 1;
                    jatek.start(temp*10+1);
                }
            }

            frame->settx(-0.06+0.06*(temp%3));
            frame->setty(0.06-0.06*(temp/3));

            /*frame->settx(-0.06+0.06*(int)((-112*multipler+offset+x)/(139*multipler+offset)));
            frame->setty(0.06-0.06*(int)((-32*multipler+y)/(139*multipler)));*/

        }

    }
}
