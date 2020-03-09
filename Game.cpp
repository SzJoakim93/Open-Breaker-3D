#include "Game.h"

Game::Game(char * level_path, Top * top, char * scorename, int * width, int * height, int * language)
{
    //ctor
    isCompleted = false;

    player = new Player();

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

    for (int i=0; i<8; i++)
                play_list[i]=true;
    char ** soundpath= new char*[9];
    for (int i=0; i<9; i++)
        soundpath[i] = new char[32];

    strcpy(soundpath[0], "Sounds/B1.wav");
    strcpy(soundpath[1], "Sounds/B2.wav");
    strcpy(soundpath[2], "Sounds/B3.wav");
    strcpy(soundpath[3], "Sounds/BONUS.wav");
    strcpy(soundpath[4], "Sounds/EFFECT0.wav");
    strcpy(soundpath[5], "Sounds/END_OF_G.wav");
    strcpy(soundpath[6], "Sounds/END_OF_L.wav");
    strcpy(soundpath[7], "Sounds/FIRE.wav");
    strcpy(soundpath[8], "Sounds/STAR.wav");

    sounds.hozzaad(soundpath, 9);

    left_key_pressed = false;
    right_key_pressed = false;

    this->top = top;
    this->scorename = scorename;
    this->language = language;
}

Game::~Game()
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

void Game::load(char * path)
{
    FILE * file = fopen(path, "r");
    fscanf(file, "%f %s", &level_size, level_color);
    level_x = -0.8+level_size*2.0/1.5;
    level_y = 1.0-level_size*2.0;
    level_z = 1.0-level_size*2.0;

    blocks=0;

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
        int * new_flag = new int [10];
            
        fscanf(file, "%f %f %f %f %f %f %d %s %s %d %d %d %d %d %d %d %d %d %d", &tx, &ty, &tz, &sx, &sy, &sz, &r, texture, obj, &new_flag[0], &new_flag[1], &new_flag[2], &new_flag[3], &new_flag[4], &new_flag[5], &new_flag[6], &new_flag[7], &new_flag[8], &new_flag[9]);
        level_objects.insert(new Block(new Object(tx, ty, tz, //koordinatak
                             0, r, 0, //elforgatas
                             sx, sy, sz, //atmeretezes
                             true, texture, 0, obj, 0, 0), new_flag));

        if (new_flag[0] != -2)
            blocks++;
    }

    fclose(file);
}

void Game::esemenyek(int & jatekresz)
{
    if (Object::getcx() < level_x - 0.2)
        Object::setcx(Object::getcx() + 0.2);

    if (Object::getcy() < level_y - 0.2)
        Object::setcy(Object::getcy() + 0.2);

    if (Object::getcz() < level_z - 0.2)
        Object::setcz(Object::getcz() + 0.2);

    if (player->getLife() > 0 && !isCompleted)
    {
        player->wallEvent();
        for (int i=0; i<3; i++)
            if (stars[i]->getty() < 0.9)
            {
                stars[i]->rotateY(1);
                if (stars[i]->getty() > -0.2)
                    stars[i]->trans_lengthical(-0.002);
            }

        if (left_key_pressed && padle->gettx() - padle->getsx() > 0.5-level_size)
            padle->trans_horizontal(-0.015);
        if (right_key_pressed && padle->gettx() + padle->getsx() < 0.5+level_size)
            padle->trans_horizontal(+0.015);

        for (int i=0; i<3; i++)
            if (balls[i]->isActive())
            {
                balls[i]->moving();

                if (!balls[i]->isLaunched())
                    balls[i]->getObj()->settx(padle->gettx());

                for (int j=0; j<3; j++)
                    if (stars[j]->getty() < 0.2 && *balls[i]->getObj() == *stars[j])
                    {
                        player->increaseScore(15);
                        if (*isSound)
                            sounds.play_sound(8, -1);
                        stars[j]->setty(1.0);
                    }

                balls[i]->pongFromBorder(level_size, player->isWall());


                if (balls[i]->collision(padle))
                {
                    if (*isSound)
                        sounds.play_sound(0, -1);
                    if (player->isGrip())
                    {
                        //balls[i]->setDefaults();
                        balls[i]->setSpeed(0.0f);
                        balls[i]->getObj()->settx(padle->gettx());
                        balls[i]->getObj()->settz(-0.32+level_size);
                    }

                    balls[i]->pongFromPaddle(padle);
                }

                if (balls[i]->getObj()->gettz() > 0.4+level_size)
                    balls[i]->incativate();
            }

        //if (balls[0]->getObj()->gettz() > 0.4+level_size && balls[1]->getObj()->gettz() > 0.4+level_size && balls[2]->getObj()->gettz() > 0.4+level_size && player->getLife() > 0)
        if (Ball::getActiveBalls() == 0)
        {
            player->decreaseLife();
            if (player->getLife() > 0)
                balls[0]->activate();
                balls[0]->getObj()->settx(padle->gettx());
                balls[0]->getObj()->settz(-0.32+level_size);
        }

        for (int i=0; i<level_objects.size(); i++)
        { 
            if (level_objects[i]->isNormal())
            {
                if (*ammo_fire == *(level_objects[i]->getObj()))
                {
                    level_objects[i]->hit();

                    if (level_objects[i]->destroyed())
                    {
                        player->increaseScore(3);
                        blocks--;
                        level_objects[i]->addGravityRange();
                        if (*isSound)
                            sounds.play_sound(2, -1);
                    }
                    else
                    {
                        player->increaseScore(1);
                        if (*isSound)
                            sounds.play_sound(1, -1);
                    }

                    ammo_fire->settz(1.0+level_size);

                    break;
                }
                
            }
            else if (level_objects[i]->isBonus())
            {
                level_objects[i]->getObj()->rotateY(1);
            }
            else if (level_objects[i]->isMoving())
            {
                level_objects[i]->moving();    
            }


            for (int j=0; j<3; j++)
                if (balls[j]->isActive() && level_objects[i]->isActive() && balls[j]->collision(level_objects[i]->getObj()))
                {
                    if (!player->isMegaball() || level_objects[i]->isMoving())
                    {
                        if (balls[j]->collision_front(level_objects[i]->getObj()))
                            balls[j]->reverseDir_Y();
                        else if (balls[j]->collision_left(level_objects[i]->getObj()))
                            balls[j]->reverseDir_X();
                        else if (balls[j]->collision_back(level_objects[i]->getObj()))
                            balls[j]->reverseDir_Y();
                        else if (balls[j]->collision_right(level_objects[i]->getObj()))
                            balls[j]->reverseDir_X();
                    }

                    if (level_objects[i]->isMoving())
                    {
                        if (balls[j]->collision_left(level_objects[i]->getObj()))
                            level_objects[i]->reverse_direction();
                         else if (balls[j]->collision_left(level_objects[i]->getObj()))
                            level_objects[i]->reverse_direction();
                    }
                    else if (level_objects[i]->isBonus())
                    {
                        level_objects[i]->hit();
                        blocks--;
                        level_objects[i]->addGravityRange();

                        player->increaseScore(3);
                        if (*isSound)
                            sounds.play_sound(3, -1);

                            int k = rand() % 10;
                            bonuses[k]->settx(level_objects[k]->getObj()->gettx());
                            bonuses[k]->settz(level_objects[k]->getObj()->gettz());
                    }
                    else
                    {
                        level_objects[i]->hit();

                        if (level_objects[i]->destroyed())
                        {
                            blocks--;
                            level_objects[i]->addGravityRange();
                            
                            player->increaseScore(5);
                            balls[j]->increaseSpeed(-0.0002);
                            if (*isSound)
                                sounds.play_sound(2, -1);

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
                        else //object hit but not destroyed
                        {
                            if (*isSound)
                                sounds.play_sound(1, -1);
                            player->increaseScore(2);
                        }

                    }

                    goto collision_detect_end;
                }
        }

        collision_detect_end:

        for (int i=0; i<level_objects.size(); i++)
            level_objects[i]->gravityEvents(level_objects);

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
                        sounds.play_sound(4, -1);
                    switch (i)
                    {
                    case 0:
                    {
                        player->increaseAmmo(10);
                        player->increaseScore(5);
                        break;
                    }
                    case 1:
                    {
                        player->increaseLife(3);
                        player->increaseScore(10);
                        break;
                    }
                    case 2:
                    {
                        //triplaball
                        balls[1]->cloneBall(balls[0], 0);
                        balls[2]->cloneBall(balls[0], 1);
                        player->increaseScore(5);
                        break;
                    }
                    case 3:
                    {
                        player->setMegaBall(true);
                        player->increaseScore(5);
                        break;
                    }
                    case 4:
                    {
                        player->setWall(2000);
                        player->increaseScore(5);
                        break;
                    }
                    case 5:
                    {
                        setBallSpeed(-0.01);
                        player->increaseScore(5);
                        break;
                    }
                    case 6:
                    {
                        player->setGrip(true);
                        player->increaseScore(5);
                        break;
                    }
                    case 7:
                    {
                        padle->setsx(padle->getsx()+0.05f);
                        player->increaseScore(5);
                        break;
                    }
                    case 8:
                    {
                        padle->setsx(0.05);
                        player->increaseScore(-10);
                        break;
                    }
                    case 9:
                    {
                        setBallSpeed(-0.025f);
                        player->increaseScore(-10);
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
                        sounds.play_sound(5, -1);
                }
                else
                {
                    reset();
                    player->increaseScore(20);
                    if (*isSound)
                        sounds.play_sound(6, -1);
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

void Game::leftKeyDown()
{
    left_key_pressed = true;
}

void Game::leftKeyUp()
{
    left_key_pressed = false;
}

void Game::rightKeyDown()
{
    right_key_pressed = true;
}

void Game::rightKeyUp()
{
    right_key_pressed = false;
}

/*void Game::mouse_ok(bool isClicked, int & jatekresz)
{
    if (life < 1 || isCompleted)
    {
        if (isClicked)
            jatekresz = 0;
    }
}*/

void Game::launch()
{
    if (balls[0]->isLaunched())
    {
        if (player->getAmmo() > 0 && ammo_fire->gettz() > 0.4f+level_size)
        {
            if (*isSound)
                sounds.play_sound(7, -1);
            player->decreaseAmmo();
            ammo_fire->settx(padle->gettx());
            ammo_fire->settz(-0.3+level_size);
        }
    }
    else 
        balls[0]->setSpeed(-0.018f);
}

void Game::rendering(int & jatekresz)
{

    if (player->getLife() < 1 || isCompleted)
    {
        if (player->getScore() > top[9].score)
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
        if (stars[i]->getty() < 0.9f)
            stars[i]->rendering(0);

    aljzat->rendering(0);
    fal1->rendering(0);
    fal2->rendering(0);
    fal3->rendering(0);
    if (player->needRenderWall())
        fal4->rendering(0);

    padle->rendering(0);

    for (int i=0; i<3; i++)
        if (balls[i]->isActive())
            balls[i]->getObj()->rendering(0);

    print(blocks, *block_title);
    for (int i=0; i<4; i++)
        titles[i]->rendering(0);

    print(player->getLife(), *life_title);
    print(player->getAmmo(), *ammo_title);
    print(player->getScore(), *score_title);
    print(top[0].score, *best_title);
    print(level, *level_title);


    for (int i=0; i<level_objects.size(); i++)
        if (level_objects[i]->isActive())
            level_objects[i]->getObj()->rendering(0);

    for (int i=0; i<10; i++)
        if (bonuses[i]->gettz() < 1.0f)
            bonuses[i]->rendering(0);



    if (ammo_fire->gettz() < 1.0f)
        ammo_fire->rendering(0);

}

void Game::print(int x, Object & Object)
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

void Game::zene(char * eleres)
{

}

void Game::zene_stop()
{

}

void Game::reset()
{
    for (int i=0; i<level_objects.size(); i++)
        delete level_objects[i];
    level_objects.clear();

    delete fal1;
    delete fal2;
    delete fal3;
    delete fal4;
    /*for (int i=0; i<3; i++)
        delete ball[i];*/

    //delete [] ball;
    delete padle;
    delete aljzat;
    delete ammo_fire;

    sounds.stop();

    fprintf(stdout, "reset executed\n");
}

void Game::sethangok(bool * behang, bool * bezene)
{
    isSound = behang;
    isMusic = bezene;
}

void Game::start(const int & level)
{
    Object::setcz(-10.0f);
    Object::setcy(-10.0f);
    Object::setcz(-10.0f);

    if (level % 10 == 1)
        player->resetGame();
    player->resetLevel();    

    this->level = level;

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
        sounds.play_music(mus_path);
    }

    levelpath = new char [30];
    sprintf(levelpath, "Levels/L%d.txt", level);
    load(levelpath);

    delete levelpath;

    aljzat = new Object(0.5f, -0.3f, -0.2f, //koordinatak
                      0, 0, 0, //elforgatas
                      level_size*2.0f, 1.0f, level_size*2.0f, //atmeretezes
                      true, level_color, 0, "negyzet", 0, 0);

    fal1 = new Object(0.5f + level_size, -0.27f, -0.2, //koordinatak
                    0, 0, 0, //elforgatas
                    0.01f, 0.025f, level_size, //atmeretezes
                    true, level_color, 0, "Objects/cube.obj", 0, 0);

    fal2 = new Object(0.5 - level_size, -0.27, -0.2, //koordinatak
                    0, 0, 0, //elforgatas
                    0.01f, 0.025f, level_size, //atmeretezes
                    true, level_color, 0, "Objects/cube.obj", 0, 0);

    fal3 = new Object(0.5f, -0.27f, -0.2f - level_size, //koordinatak
                    0, 90, 0, //elforgatas
                    0.01f, 0.025f, level_size, //atmeretezes
                    true, level_color, 0, "Objects/cube.obj", 0, 0);

    fal4 = new Object(0.5f, -0.27f, -0.2f + level_size, //koordinatak
                    0, 90, 0, //elforgatas
                    0.01f, 0.025f, level_size, //atmeretezes
                    true, level_color, 0, "Objects/cube.obj", 0, 0);

    padle = new Object(0.5f, -0.27f, -0.25 + level_size, //koordinatak
                     0, 0, 0, //elforgatas
                     0.1f, 0.025f, 0.025f, //atmeretezes
                     true, "Colors/gray.bmp", 0, "Objects/padle.obj", 0, 0);

    ammo_fire = new Object(0.5f, -0.27f, 1.0f + level_size, //koordinatak
                         0, 270, 0, //elforgatas
                         0.08f, 1.0f, 0.08f, //atmeretezes
                         true, "Textures/ammo.bmp", 0, "negyzet", 0, 0);

    balls[0] = new Ball(new Object(0.5f, -0.27f, -0.32f + level_size, //koordinatak
                       0, 180, 0, //elforgatas
                       0.04f, 0.04f, 0.04f, //atmeretezes
                       true, "Colors/red.bmp", 0, "Objects/sphere.obj", 0, 0), true);

    for (int i=1; i<3; i++)
        balls[i] = new Ball(new Object(0.5f, -0.27f, 1.0f + level_size, //koordinatak
                           0, 180, 0, //elforgatas
                           0.04f, 0.04f, 0.04f, //atmeretezes
                           true, "Colors/red.bmp", 0, "Objects/sphere.obj", 0, 0), false);

    isCompleted = false;
}

int Game::getLife()
{
    return player->getLife();
}

int Game::getScore()
{
    return player->getScore();
}

bool Game::getCompleted()
{
    return isCompleted;
}

void Game::setBallSpeed(const float x)
{
    for (int j=0; j < 3; j++)
        balls[j]->setSpeed(x);
}