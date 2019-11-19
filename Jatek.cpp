#include "Jatek.h"

#define N 80
Jatek::Jatek(char * level_path, Top * top, char * scorename, int * width, int * height, int * language)
{
    //ctor
    isCompleted = false;

    for (int i=0; i<3; i++)
        stars[i] = new Object(-0.2, 1.0, 0.1, //koordinatak
                              0, 0, 0, //elforgatas
                              0.025, 0.025, 0.01, //atmeretezes
                              true, "Colors/brown.bmp", 0, "Objects/star1.obj", 0, 0);
    bonuses = new Object* [10];

    char temp[32] = "Textures/bonus0.bmp";
    for (int i=0; i<10; i++)
    {
        bonuses[i] = new Object(0.5, -0.29, 1.0, //koordinatak
                              0, 0, 0, //elforgatas
                              0.1, 0.1, 0.1, //atmeretezes
                              true, temp, 0, "negyzet", 0, 0);

        temp[14]++;
    }

    titles = new Object* [4];
    char temp2[32];
    if (*language == 0)
        strcpy(temp2, "fonts/hungarian/title0.bmp");
    else
        strcpy(temp2, "fonts/english/title0.bmp");
    float place = 0.0;
    if ((float)(*width)/(float)(*height) < 1.3) //5:4
        place = 0.008;
    else if ((float)(*width)/(float)(*height) < 1.4) //4:3
        place = 0.0;
    else if ((float)(*width)/(float)(*height) < 1.7) //16:10
        place = -0.028;
    else if ((float)(*width)/(float)(*height) < 1.8) //16:9
        place = -0.046;

    for (int i=0; i<4; i++)
    {
        titles[i] = new Object(-0.109+place, -0.025*i, 0.0, //koordinatak
                             0, 0, 0, //elforgatas
                             0.014, 0.0, 0.055, //atmeretezes
                             true, temp2, 0, "negyzet", 3, 0);

        if (*language == 0)
            temp2[21]++;
        else
            temp2[19]++;
    }


    level_title = new Object(-0.1+place, -0.067, 0.0, //koordinatak
                           0, 0, 0, //elforgatas
                           0.0066, 1.0, 0.0044, //atmeretezes
                           true, "fonts/numbers", 0, "negyzet", 4, 0);

    life_title = new Object(-0.1+place, -0.075, 0.0, //koordinatak
                          0, 0, 0, //elforgatas
                          0.0066, 1.0, 0.0044, //atmeretezes
                          true, "fonts/numbers", 0, "negyzet", 4, 0);

    ammo_title = new Object(-0.1+place, -0.083, 0.0, //koordinatak
                          0, 0, 0, //elforgatas
                          0.0066, 1.0, 0.0044, //atmeretezes
                          true, "fonts/numbers", 0, "negyzet", 4, 0);

    block_title = new Object(-0.134+place, -0.057, 0.0, //koordinatak
                          0, 0, 0, //elforgatas
                          0.0066, 1.0, 0.0044, //atmeretezes
                          true, "fonts/numbers", 0, "negyzet", 4, 0);

    score_title = new Object(-0.134+place, -0.037, 0.0, //koordinatak
                          0, 0, 0, //elforgatas
                          0.0066, 1.0, 0.0044, //atmeretezes
                          true, "fonts/numbers", 0, "negyzet", 4, 0);

    gamebox = new Object(0.0, 0.0, 0.0, //koordinatak
                          0, 0, 0, //elforgatas
                          0.074, 1.0, 0.166, //atmeretezes
                          true, "fonts/english/w.bmp", 0, "negyzet", 3, 0);

    gameover = new Object(-0.015, 0.02, 0.0, //koordinatak
                          0, 0, 0, //elforgatas
                          0.005, 1.0, 0.0025, //atmeretezes
                          true, "fonts/letters", 0, "negyzet", 4, 0);

    g_title = new Object(-0.022, 0.01, 0.0, //koordinatak
                          0, 0, 0, //elforgatas
                          0.005, 1.0, 0.0025,
                          true, "fonts/letters", 0, "negyzet", 4, 0);

    r_title = new Object(-0.028, -0.025, 0.0, //koordinatak
                          0, 0, 0, //elforgatas
                          0.005, 1.0, 0.0025,
                          true, "fonts/letters", 0, "negyzet", 4, 0);

    best_title = new Object(-0.134+place, 0.08, 0.0, //koordinatak
                          0, 0, 0, //elforgatas
                          0.0066, 1.0, 0.0044, //atmeretezes
                          true, "fonts/numbers", 0, "negyzet", 4, 0);

    text = new Object(-0.03, -0.01, 0.0, //koordinatak
                          0, 0, 0, //elforgatas
                          0.005, 1.0, 0.0025, //atmeretezes
                          true, "fonts/letters", 0, "negyzet", 4, 0);

    textbox = new Object(0.00, -0.01, 0.0, //koordinatak
                          0, 0, 0, //elforgatas
                          0.012, 1.0, 0.08, //atmeretezes
                          true, "fonts/frame.bmp", 0, "negyzet", 3, 0);

    titles[0]->setty(0.09);
    titles[3]->settx(-0.123+place);
    titles[3]->setsz(0.028);
    titles[3]->setsx(0.028);

    Objectszam = 0;
    for (int i=0; i<8; i++)
                play_list[i]=true;
    char ** hangpath= new char*[9];
    for (int i=0; i<9; i++)
        hangpath[i] = new char[32];

    strcpy(hangpath[0], "Sounds/B1.wav");
    strcpy(hangpath[1], "Sounds/B2.wav");
    strcpy(hangpath[2], "Sounds/B3.wav");
    strcpy(hangpath[3], "Sounds/BONUS.wav");
    strcpy(hangpath[4], "Sounds/EFFECT0.wav");
    strcpy(hangpath[5], "Sounds/END_OF_G.wav");
    strcpy(hangpath[6], "Sounds/END_OF_L.wav");
    strcpy(hangpath[7], "Sounds/FIRE.wav");
    strcpy(hangpath[8], "Sounds/STAR.wav");

    hangok.hozzaad(hangpath, 9);

    bal = false;
    jobb = false;

    this->top = top;
    this->scorename = scorename;
    this->language = language;

    life = 5;
    ammo = 10;
    score = 0;
}

Jatek::~Jatek()
{
    for (int i=0; i<3; i++)
        delete stars[i];

    for (int i=0; i<10; i++)
        delete bonuses[i];
    delete [] bonuses;

    for (int i=0; i<4; i++)
        delete titles[i];
    delete [] titles;

    delete level_title;
    delete life_title;
    delete ammo_title;
    delete block_title;
    delete score_title;
    delete gamebox;
    delete gameover;
    delete g_title;
    delete r_title;
    delete best_title;
    delete text;
    delete textbox;


}

void Jatek::load(char * path)
{
    FILE * file = fopen(path, "r");
    fscanf(file, "%f %s", &level_size, level_color);
    level_x = -0.8+level_size*2.0/1.5;
    level_y = 1.0-level_size*2.0;
    level_z = 1.0-level_size*2.0;

    blocks=0;
    int i=0;
    while(!feof(file))
    {
        float tx;
        float ty;
        float tz;
        float sx;
        float sy;
        float sz;
        char texture[30];
        char obj[30];
        int r;
        fscanf(file, "%f %f %f %f %f %f %d %s %s %d %d %d %d %d %d %d %d %d %d", &tx, &ty, &tz, &sx, &sy, &sz, &r, texture, obj, &flags[i][0], &flags[i][1], &flags[i][2], &flags[i][3], &flags[i][4], &flags[i][5], &flags[i][6], &flags[i][7], &flags[i][8], &flags[i][9]);
        Objectek[i] = new Object(tx, ty, tz, //koordinatak
                             0, r, 0, //elforgatas
                             sx, sy, sz, //atmeretezes
                             true, texture, 0, obj, 0, 0);

        if (flags[i][0] != -2)
            blocks++;
        i++;
    }

    fclose(file);

    Objectszam = i;
}

void Jatek::esemenyek(int & jatekresz)
{
    if (Object::getcx() < level_x - 0.2)
        Object::setcx(Object::getcx() + 0.2);

    if (Object::getcy() < level_y - 0.2)
        Object::setcy(Object::getcy() + 0.2);

    if (Object::getcz() < level_z - 0.2)
        Object::setcz(Object::getcz() + 0.2);

    if (life > 0 && !isCompleted)
    {
        if (wall > 0)
            wall--;
        for (int i=0; i<3; i++)
            if (stars[i]->getty() < 0.9)
            {
                stars[i]->rotateY(1);
                if (stars[i]->getty() > -0.2)
                    stars[i]->trans_lengthical(-0.002);
            }

        if (bal && padle->gettx() - padle->getsx() > 0.5-level_size)
            padle->trans_horizontal(-0.015);
        if (jobb && padle->gettx() + padle->getsx() < 0.5+level_size)
            padle->trans_horizontal(+0.015);

        if (ballspeed == 0.0)
            ball[0]->settx(padle->gettx());


        for (int i=0; i<3; i++)
            if (ball[i]->gettz() < 0.5+level_size)
            {
                ball[i]->trans_horizontal(ballspeed_x[i]*ballspeed);
                ball[i]->trans_vertical(ballspeed_y[i]*ballspeed);

                for (int j=0; j<3; j++)
                    if (stars[j]->getty() < 0.2 && *ball[i] == *stars[j])
                    {
                        score +=15;
                        if (*isSound)
                            hangok.play_sound(8, -1);
                        stars[j]->setty(1.0);
                    }

                if (ball[i]->gettx() > 0.45 + level_size && ballspeed_x[i] < 0.0 || ball[i]->gettx() < 0.55 - level_size && ballspeed_x[i] > 0.0)
                {
                    ballspeed_x[i] *= -1.0;
                    if (*isSound)
                        hangok.play_sound(0, -1);
                }


                if (ball[i]->gettz() < -0.15 - level_size || wall > 0 && ball[i]->gettz() > -0.25 + level_size)
                {
                    ballspeed_y[i] *= -1.0;
                    if (*isSound)
                        hangok.play_sound(0, -1);
                }


                if (ball[i]->gettz() > -0.3+level_size && ball[i]->gettz() < -0.25+level_size && ball[i]->gettx() > padle->gettx() - padle->getsx() && ball[i]->gettx() < padle->gettx() + padle->getsx())
                {
                    if (*isSound && !grip)
                        hangok.play_sound(0, -1);
                    if (grip && i==0)
                    {
                        ballspeed=0;
                    }

                    if (ball[i]->gettx() < padle->gettx() - padle->getsx() + padle->getsx()/6)
                    {
                        ballspeed_x[i] = 0.7;
                        ballspeed_y[i] = 0.3;
                    }
                    else if (ball[i]->gettx() < padle->gettx() - padle->getsx() + 2*padle->getsx()/6)
                    {
                        ballspeed_x[i] = 0.6;
                        ballspeed_y[i] = 0.4;
                    }
                    else if (ball[i]->gettx() < padle->gettx() - padle->getsx() + 3*padle->getsx()/6)
                    {
                        ballspeed_x[i] = 0.5;
                        ballspeed_y[i] = 0.5;
                    }

                    else if (ball[i]->gettx() < padle->gettx() - padle->getsx() + 4*padle->getsx()/6)
                    {
                        ballspeed_x[i] = 0.4;
                        ballspeed_y[i] = 0.6;
                    }

                    else if (ball[i]->gettx() < padle->gettx() - padle->getsx() + 5*padle->getsx()/6)
                    {
                        ballspeed_x[i] = 0.3;
                        ballspeed_y[i] = 0.7;
                    }

                    else if (ball[i]->gettx() < padle->gettx() - padle->getsx() + 6*padle->getsx()/6)
                    {
                        ballspeed_x[i] = 0.1;
                        ballspeed_y[i] = 0.9;

                    }
                    else if (ball[i]->gettx() < padle->gettx() - padle->getsx() + 7*padle->getsx()/6)
                    {
                        ballspeed_x[i] = -0.1;
                        ballspeed_y[i] = 0.9;
                    }
                    else if (ball[i]->gettx() < padle->gettx() - padle->getsx() + 8*padle->getsx()/6)
                    {
                        ballspeed_x[i] = -0.3;
                        ballspeed_y[i] = 0.7;
                    }
                    else if (ball[i]->gettx() < padle->gettx() - padle->getsx() + 9*padle->getsx()/6)
                    {
                        ballspeed_x[i] = -0.4;
                        ballspeed_y[i] = 0.6;
                    }

                    else if (ball[i]->gettx() < padle->gettx() - padle->getsx() + 10*padle->getsx()/6)
                    {
                        ballspeed_x[i] = -0.5;
                        ballspeed_y[i] = 0.5;
                    }

                    else if (ball[i]->gettx() < padle->gettx() - padle->getsx() + 11*padle->getsx()/6)
                    {
                        ballspeed_x[i] = -0.6;
                        ballspeed_y[i] = 0.4;
                    }

                    else
                    {
                        ballspeed_x[i] = -0.7;
                        ballspeed_y[i] = 0.3;
                    }
                }
            }

        if (ball[0]->gettz() > 0.4+level_size && ball[1]->gettz() > 0.4+level_size && ball[2]->gettz() > 0.4+level_size && life > 0)
        {
            ballspeed = 0;
            ballspeed_x[0] = 0.5;
            ballspeed_y[0] = 0.5;
            life--;
            if (life > 0)
            {
                ball[0]->settx(padle->gettx());
                ball[0]->settz(-0.32+level_size);
            }

        }



        for (int i=0; i<Objectszam; i++)
        {
            if (flags[i][0] > 0 && flags[i][0] < 9 && *ammo_fire == (*Objectek[i]))
            {
                flags[i][0]--;

                if (flags[i][0] == 0)
                {
                    score+=3;
                    blocks--;
                    Objectek[i]->setGravityRange(Objectek[i]->getsy());
                    if (*isSound)
                        hangok.play_sound(2, -1);
                }
                else
                {
                    score++;
                    if (*isSound)
                        hangok.play_sound(1, -1);
                }



                ammo_fire->settz(1.0+level_size);

                break;
            }
            else if (flags[i][0] % 10 == 9 || flags[i][0] == -1)
            {
                Objectek[i]->rotateY(1);
                if (flags[i][0] == -1)
                    for (int j=0; j<3; j++)
                        if (ball[j]->gettz() < 0.5+level_size && (*Objectek[i]) == (*ball[j]))
                        {
                            score +=3;
                            if (*isSound)
                                hangok.play_sound(3, -1);
                            blocks--;

                            flags[i][0] = 0;
                            int j = rand() % 10;
                            bonuses[j]->settx(Objectek[i]->gettx());
                            bonuses[j]->settz(Objectek[i]->gettz());
                        }
            }
            else if (flags[i][0] == -2)
            {
                float t_begin = flags[i][1]/100.0;
                float t_end = flags[i][2]/100.0;
                float moving = flags[i][3]/1000.0;

                Objectek[i]->trans_horizontal(moving);
                if (Objectek[i]->gettx() < t_begin || Objectek[i]->gettx() > t_end)
                    flags[i][3]*=-1;

                for (int j=0; j<3; j++)
                    if (ball[j]->gettz() + ball[j]->getsz() > Objectek[i]->gettz() - Objectek[i]->getsz() && ball[j]->gettz() - ball[j]->getsz() < Objectek[i]->gettz() + Objectek[i]->getsz() &&
                        ball[j]->gettx() - ball[j]->getsx() < Objectek[i]->gettx() + Objectek[i]->getsx() && ball[j]->gettx() - ball[j]->getsx() > Objectek[i]->gettx() + Objectek[i]->getsx() - 0.02)
                            flags[i][3]*=-1;
                    else if (ball[j]->gettz() + ball[j]->getsz() > Objectek[i]->gettz() - Objectek[i]->getsz() && ball[j]->gettz() - ball[j]->getsz() < Objectek[i]->gettz() + Objectek[i]->getsz() &&
                        ball[j]->gettx() + ball[j]->getsx() > Objectek[i]->gettx() - Objectek[i]->getsx() && ball[j]->gettx() + ball[j]->getsx() < Objectek[i]->gettx() - Objectek[i]->getsx() + 0.02)
                           flags[i][3]*=-1;
            }


            for (int j=0; j<3; j++)
                if (ball[j]->gettz() < 0.5+level_size && (flags[i][0] < 9 && (flags[i][0] > 0 || flags[i][0] == -1 || flags[i][0] == -2) && (*Objectek[i]) == (*ball[j])))
                {
                    if (!megaball || flags[i][0] == -2)
                    {
                        if (ball[j]->gettx() + ball[j]->getsx() > Objectek[i]->gettx() - Objectek[i]->getsx() && ball[j]->gettx() - ball[j]->getsx() < Objectek[i]->gettx() + Objectek[i]->getsx() &&
                        ball[j]->gettz() + ball[j]->getsz() > Objectek[i]->gettz() - Objectek[i]->getsz() && ball[j]->gettz() + ball[j]->getsz() < Objectek[i]->gettz() - Objectek[i]->getsz() + 0.02)
                            ballspeed_y[j] *=-1;
                        else if (ball[j]->gettx() + ball[j]->getsx() > Objectek[i]->gettx() - Objectek[i]->getsx() && ball[j]->gettx() - ball[j]->getsx() < Objectek[i]->gettx() + Objectek[i]->getsx() &&
                        ball[j]->gettz() - ball[j]->getsz() < Objectek[i]->gettz() + Objectek[i]->getsz() && ball[j]->gettz() - ball[j]->getsz() > Objectek[i]->gettz() + Objectek[i]->getsz() - 0.02)
                            ballspeed_y[j] *=-1;
                        else if (ball[j]->gettz() + ball[j]->getsz() > Objectek[i]->gettz() - Objectek[i]->getsz() && ball[j]->gettz() - ball[j]->getsz() < Objectek[i]->gettz() + Objectek[i]->getsz() &&
                        ball[j]->gettx() - ball[j]->getsx() < Objectek[i]->gettx() + Objectek[i]->getsx() && ball[j]->gettx() - ball[j]->getsx() > Objectek[i]->gettx() + Objectek[i]->getsx() - 0.02)
                            ballspeed_x[j] *=-1;
                        else if (ball[j]->gettz() + ball[j]->getsz() > Objectek[i]->gettz() - Objectek[i]->getsz() && ball[j]->gettz() - ball[j]->getsz() < Objectek[i]->gettz() + Objectek[i]->getsz() &&
                        ball[j]->gettx() + ball[j]->getsx() > Objectek[i]->gettx() - Objectek[i]->getsx() && ball[j]->gettx() + ball[j]->getsx() < Objectek[i]->gettx() - Objectek[i]->getsx() + 0.02)
                            ballspeed_x[j] *=-1;
                    }

                    if (flags[i][0] > -2)
                    {
                        flags[i][0]--;

                        if (flags[i][0] == 0)
                        {
                            blocks--;
                            Objectek[i]->setGravityRange(Objectek[i]->getsy());
                            score += 5;
                            if (ballspeed > -0.03);
                                ballspeed-=0.0002;
                            if (*isSound)
                                hangok.play_sound(2, -1);

                            if (blocks % 30 == 0)
                            {
                                stars[0]->settx(((float)(rand() % 10)/10.0)*level_size*2);
                                stars[0]->settz(((float)(rand() % 10)/10.0)*level_size*2 - 0.75);
                                stars[0]->setty(0.8);
                            }


                            if (blocks % 30 == 10)
                            {
                                stars[1]->settx(((float)(rand() % 10)/10.0)*level_size*2);
                                stars[1]->settz(((float)(rand() % 10)/10.0)*level_size*2 - 0.75);
                                stars[1]->setty(0.8);
                            }

                            if (blocks % 30 == 20)
                            {
                                stars[2]->settx(((float)(rand() % 10)/10.0)*level_size*2);
                                stars[2]->settz(((float)(rand() % 10)/10.0)*level_size*2 - 0.75);
                                stars[2]->setty(0.8);
                            }

                        }
                        else
                        {
                            if (*isSound)
                                hangok.play_sound(1, -1);
                            score +=2;
                        }

                    }

                    goto collision_detect_end;
                }
        }

        collision_detect_end:

        for (int i=0; i<Objectszam; i++)
            if (Objectek[i]->getGravityRange() > 0.0)
            {
                for (int j=1; flags[i][j] > -1 && j<10; j++)
                    Objectek[flags[i][j]]->trans_lengthical(-0.001);

                Objectek[i]->trans_gravity(-0.0005);

                if (Objectek[i]->getGravityRange() < 0.0)
                    for (int j=1; flags[i][j] > -1 && j<9; j++)
                        flags[flags[i][j]][0] -= 10;
            }

        if (ammo_fire->gettz() < 0.5+level_size)
            ammo_fire->trans_vertical(-0.015);

        if (ammo_fire->gettz() < -0.2-level_size)
            ammo_fire->settz(1.0+level_size);

        for (int i=0; i<10; i++)
            if (bonuses[i]->gettz() < 0.5+level_size)
            {
                bonuses[i]->trans_vertical(0.005);
                bonuses[i]->rotateY(1);

                if (bonuses[i]->gettz() > -0.3+level_size && bonuses[i]->gettz() < -0.29+level_size && bonuses[i]->gettx() > padle->gettx() - padle->getsx() && bonuses[i]->gettx() < padle->gettx() + padle->getsx())
                {
                    if (*isSound)
                        hangok.play_sound(4, -1);
                    switch (i)
                    {
                    case 0:
                    {
                        ammo+=10;
                        score +=5;
                        break;
                    }
                    case 1:
                    {
                        life+=3;
                        score +=10;
                        break;
                    }
                    case 2:
                    {
                        //triplaball
                        ball[1]->settx(ball[0]->gettx());
                        ball[1]->settz(ball[0]->gettz());
                        ball[2]->settx(ball[0]->gettx());
                        ball[2]->settz(ball[0]->gettz());
                        ballspeed_x[1]=ballspeed_x[0]+0.1;
                        ballspeed_y[1]=ballspeed_y[0]-0.1;
                        ballspeed_x[2]=ballspeed_x[0]-0.1;
                        ballspeed_y[2]=ballspeed_y[0]+0.1;
                        score +=5;
                        break;
                    }
                    case 3:
                    {
                        megaball = true;
                        score +=5;
                        break;
                    }
                    case 4:
                    {
                        wall = 2000;
                        score +=5;
                        break;
                    }
                    case 5:
                    {
                        ballspeed = -0.01;
                        score +=5;
                        break;
                    }
                    case 6:
                    {
                        grip = true;
                        score +=5;
                        break;
                    }
                    case 7:
                    {
                        padle->setsx(padle->getsx()+0.05);
                        score +=5;
                        break;
                    }
                    case 8:
                    {
                        padle->setsx(0.05);
                        score -=10;
                        break;
                    }
                    case 9:
                    {
                        ballspeed = -0.025;
                        score -=10;
                        break;
                    }
                    }
                    bonuses[i]->settz(0.5+level_size);
                }
            }

        if (blocks < 1)
        {

            if (!isCompleted)
            {
                if (level % 10 == 0)
                {
                    if (*isSound)
                        hangok.play_sound(5, -1);
                }
                else
                {
                    reset();
                    score +=20;
                    if (*isSound)
                        hangok.play_sound(6, -1);
                }

                SDL_Delay(3000);

                if (level % 10 == 0)
                    isCompleted=true;
                else
                {
                    level++;
                    start(level);
                }
            }

        }
    }

}

void Jatek::balgomb()
{
    bal = true;
}

void Jatek::balgomb_fel()
{
    bal = false;
}

void Jatek::jobbgomb()
{
    jobb = true;
}

void Jatek::jobbgomb_fel()
{
    jobb = false;
}

/*void Jatek::mouse_ok(bool isClicked, int & jatekresz)
{
    if (life < 1 || isCompleted)
    {
        if (isClicked)
            jatekresz = 0;
    }
}*/

void Jatek::launch()
{
    if (ammo > 0 && ammo_fire->gettz() > 0.4+level_size && ballspeed < 0.0)
    {
        if (*isSound)
            hangok.play_sound(7, -1);
        ammo--;
        ammo_fire->settx(padle->gettx());
        ammo_fire->settz(-0.3+level_size);
    }
    else if (ballspeed > -.0001)
        ballspeed = -0.018;
}

void Jatek::rendering(int & jatekresz)
{

    if (life < 1 || isCompleted)
    {
        if (score > top[9].score)
        {
            text->gprintf(scorename);
            textbox->rendering(0);
            if (*language == 0)
                g_title->gprintf("g/1peld be a neved");
            else
                g_title->gprintf("type your name");
        }

        if (*language == 0)
            r_title->gprintf("nyomj entert a folytat/0shoz");
        else
            r_title->gprintf("press enter to return");

        if (isCompleted)
        {
            if (*language == 0)
                gameover->gprintf("sorozat teljes/2tve");
            else
                gameover->gprintf("boardpack completed");
        }
        else
        {
            if (*language == 0)
                gameover->gprintf("v/1ge a j/0t/1knak");
            else
                gameover->gprintf("game over");
        }

        gamebox->rendering(0);
    }


    for (int i=0; i<3; i++)
        if (stars[i]->getty() < 0.9)
            stars[i]->rendering(0);

    aljzat->rendering(0);
    fal1->rendering(0);
    fal2->rendering(0);
    fal3->rendering(0);
    if (wall > 0 && wall < 20 || wall > 40 && wall < 60 || wall > 80 && wall < 100 || wall > 120)
        fal4->rendering(0);

    padle->rendering(0);

    for (int i=0; i<3; i++)
        if (ball[i]->gettz() < 1.0)
            ball[i]->rendering(0);

    print(blocks, *block_title);
    for (int i=0; i<4; i++)
        titles[i]->rendering(0);

    print(life, *life_title);
    print(ammo, *ammo_title);
    print(score, *score_title);
    print(top[0].score, *best_title);
    print(level, *level_title);


    for (int i=0; i<Objectszam; i++)
        if (flags[i][0] != 0)
            Objectek[i]->rendering(0);

    for (int i=0; i<10; i++)
        if (bonuses[i]->gettz() < 1.0)
            bonuses[i]->rendering(0);



    if (ammo_fire->gettz() < 1.0)
        ammo_fire->rendering(0);

}

void Jatek::print(int x, Object & Object)
{
    char temp[6];
    if (x>9999)
    {
        temp[0] = x/10000 + '0';
        temp[1] = (x%10000)/1000 + '0';
        temp[2] = (x%1000)/100 + '0';
        temp[3] = (x%100)/10 + '0';
        temp[4] = x%10 + '0';
        temp[5] = 0;
    }
    else if (x>999)
    {
        temp[0] = x/1000 + '0';
        temp[1] = (x%1000)/100 + '0';
        temp[2] = (x%100)/10 + '0';
        temp[3] = x%10 + '0';
        temp[4] = 0;
    }
    else if (x>99)
    {
        temp[0] = x/100 + '0';
        temp[1] = (x%100)/10 + '0';
        temp[2] = x%10+'0';
        temp[3] = 0;
    }
    else if (x>9)
    {
        temp[0] = x/10+'0';
        temp[1] = x%10+'0';
        temp[2] = 0;
    }
    else
    {
        temp[0] = '0';
        temp[1] = x+'0';
        temp[2] = 0;
    }

    Object.gprintf(temp);
}

void Jatek::zene(char * eleres)
{

}

void Jatek::zene_stop()
{

}

void Jatek::reset()
{
    for (int i=0; i<Objectszam; i++)
        delete Objectek[i];

    for (int i=0; i<Objectszam; i++)
        delete [] flags[i];

    delete fal1;
    delete fal2;
    delete fal3;
    delete fal4;
    for (int i=0; i<3; i++)
        delete ball[i];

    delete [] ball;
    delete padle;
    delete aljzat;
    delete ammo_fire;
    delete [] Objectek;
    delete [] flags;

    hangok.stop();
}

void Jatek::sethangok(bool * behang, bool * bezene)
{
    isSound = behang;
    isMusic = bezene;
}

void Jatek::start(const int & level)
{
    Object::setcz(-10.0);
    Object::setcy(-10.0);
    Object::setcz(-10.0);

    if (level % 10 == 1)
    {
        life = 5;
        ammo = 10;
        score = 0;
    }

    this->level = level;

    for (int i=0; i<3; i++)
    {
        ballspeed_x[i]=0.25;
        ballspeed_y[i]=0.75;
    }

    ballspeed=0;
    grip = false;
    wall = 0;
    megaball = false;

    if (*isMusic)
    {
        int x = rand() % 8;
        int _try = -1;
        while (!play_list[x] && _try < 10)
        {
            _try++;
            if (_try == 10)
            {
                for (int i=0; i<8; i++)
                play_list[i]=true;
            }
            x = rand() % 8;

        }

        play_list[x] = false;
        char mus_path[30];
        sprintf(mus_path, "Music/%d.mid", x+1);
        hangok.play_music(mus_path);
    }

    Objectszam = N;
    Objectek = new Object* [Objectszam];
    flags = new int* [Objectszam];
    for (int i=0; i<Objectszam; i++)
        flags[i] = new int [10];

    for (int i=0; i<Objectszam; i++)
    {
        for (int j=0; j<10; j++)
            flags[i][j] = -1;
    }

    levelpath = new char [30];
    sprintf(levelpath, "Levels/L%d.txt", level);
    load(levelpath);

    delete levelpath;

    aljzat = new Object(0.5, -0.3, -0.2, //koordinatak
                      0, 0, 0, //elforgatas
                      level_size*2.0, 1.0, level_size*2.0, //atmeretezes
                      true, level_color, 0, "negyzet", 0, 0);

    fal1 = new Object(0.5 + level_size, -0.27, -0.2, //koordinatak
                    0, 0, 0, //elforgatas
                    0.01, 0.025, level_size, //atmeretezes
                    true, level_color, 0, "Objects/cube.obj", 0, 0);

    fal2 = new Object(0.5 - level_size, -0.27, -0.2, //koordinatak
                    0, 0, 0, //elforgatas
                    0.01, 0.025, level_size, //atmeretezes
                    true, level_color, 0, "Objects/cube.obj", 0, 0);

    fal3 = new Object(0.5, -0.27, -0.2 - level_size, //koordinatak
                    0, 90, 0, //elforgatas
                    0.01, 0.025, level_size, //atmeretezes
                    true, level_color, 0, "Objects/cube.obj", 0, 0);

    fal4 = new Object(0.5, -0.27, -0.2 + level_size, //koordinatak
                    0, 90, 0, //elforgatas
                    0.01, 0.025, level_size, //atmeretezes
                    true, level_color, 0, "Objects/cube.obj", 0, 0);

    padle = new Object(0.5, -0.27, -0.25 + level_size, //koordinatak
                     0, 0, 0, //elforgatas
                     0.1, 0.025, 0.025, //atmeretezes
                     true, "Colors/gray.bmp", 0, "Objects/padle.obj", 0, 0);

    ammo_fire = new Object(0.5, -0.27, 1.0 + level_size, //koordinatak
                         0, 270, 0, //elforgatas
                         0.08, 1.0, 0.08, //atmeretezes
                         true, "Textures/ammo.bmp", 0, "negyzet", 0, 0);

    ball = new Object* [3];
    ball[0] = new Object(0.5, -0.27, -0.32 + level_size, //koordinatak
                       0, 180, 0, //elforgatas
                       0.04, 0.04, 0.04, //atmeretezes
                       true, "Colors/red.bmp", 0, "Objects/sphere.obj", 0, 0);
    for (int i=1; i<3; i++)
        ball[i] = new Object(0.5, -0.27, 1.0 + level_size, //koordinatak
                           0, 180, 0, //elforgatas
                           0.04, 0.04, 0.04, //atmeretezes
                           true, "Colors/red.bmp", 0, "Objects/sphere.obj", 0, 0);

    isCompleted = false;
}

int Jatek::getLife()
{
    return life;
}


int Jatek::getScore()
{
    return score;
}

bool Jatek::getCompleted()
{
    return isCompleted;
}
