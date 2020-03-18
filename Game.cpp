#include "Game.h"

Game::Game(char * level_path, Top * top, char * scorename, int * width, int * height, int * language)
{
    //ctor
    player = new Player();

    for (int i=0; i<3; i++)
    {
        stars[i] = new Object(-0.2, 1.0, 0.1, //koordinatak
                              0, 0, 0, //elforgatas
                              0.025, 0.025, 0.01, //atmeretezes
                              true, "Colors/brown.bmp", 0, "Objects/star1.obj", 0, 0);
        stars[i]->setActive(false);
    }
        
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

    for (int i=0; i<3; i++)
        balls[i] = new Ball(new Object(0.5f, -0.27f, -0.32f, //koordinatak
                           0, 180, 0, //elforgatas
                           0.04f, 0.04f, 0.04f, //atmeretezes
                           true, "Colors/red.bmp", 0, "Objects/sphere.obj", 0, 0), false);

    padle = new Object(0.5f, -0.27f, -0.25, //koordinatak
                     0, 0, 0, //elforgatas
                     0.1f, 0.025f, 0.025f, //atmeretezes
                     true, "Colors/gray.bmp", 0, "Objects/padle.obj", 0, 0);

    ammo_fire = new Object(0.5f, -0.27f, 1.0f, //koordinatak
                         0, 270, 0, //elforgatas
                         0.08f, 0.01f, 0.08f, //atmeretezes
                         true, "Textures/ammo.bmp", 0, "negyzet", 0, 0);

    ammo_fire->setActive(false);

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

    for (int i=0; i<3; i++)
        delete balls[i];

    delete padle;
    delete ammo_fire;

}

void Game::esemenyek(int & jatekresz)
{
    level->cameraAnimation();

    if (player->getLife() > 0 && !level->isCompleted())
    {
        for (int i=0; i<3; i++)
            if (stars[i]->isActive())
            {
                stars[i]->rotateY(1);
                if (stars[i]->getty() > -0.2)
                    stars[i]->trans_lengthical(-0.002);
            }

        if (left_key_pressed && padle->gettx() - padle->getsx() > 0.5-level->getSize())
            padle->trans_horizontal(-0.015);
        if (right_key_pressed && padle->gettx() + padle->getsx() < 0.5+level->getSize())
            padle->trans_horizontal(+0.015);

        ball_events();

        level->events();

        ballCollisions();

        ammoEvents();

        bonusEvents();


        if (level->isCompleted())
            end_level();
    }

}

void Game::ball_events()
{
    for (int i=0; i<3; i++)
        if (balls[i]->isActive())
        {
            balls[i]->moving();

            if (!balls[i]->isLaunched())
                balls[i]->getObj()->settx(padle->gettx());

            balls[i]->pongFromBorder(level->getSize(), level->isWall());


            if (balls[i]->collision(padle))
            {
                if (*isSound)
                    sounds.play_sound(0, -1);
                if (player->isGrip())
                {
                    balls[i]->setSpeed(0.0f);
                    balls[i]->getObj()->settx(padle->gettx());
                    balls[i]->getObj()->settz(-0.32+level->getSize());
                }

                balls[i]->pongFromPaddle(padle);
            }

            if (balls[i]->getObj()->gettz() > 0.4+level->getSize())
                balls[i]->setActive(false);
        }

    if (Ball::getActiveBalls() == 0)
    {
        player->decreaseLife();
        if (player->getLife() > 0)
        {
            balls[0]->setActive(true);
            balls[0]->getObj()->settx(padle->gettx());
            balls[0]->getObj()->settz(-0.32+level->getSize());
            balls[0]->setDefaults();
        }
            
    }
}

void Game::ballCollisions()
{
    vector<Block*> level_objects = level->getObjs();

    for (int j=0; j<3; j++)
    {
        for (int i=0; i<3; i++)
            if (stars[i]->getty() < 0.2 && *(balls[j]->getObj()) == *stars[i])
            {
                player->increaseScore(15);
                if (*isSound)
                    sounds.play_sound(8, -1);
                stars[i]->setActive(false);
                break;
            }

        for (int i = 0; i < level_objects.size(); i++)
        {
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
                    hitBonusObject(level_objects[i]);
                }
                else
                {
                    hitNormalObject(level_objects[i], balls[j]);
                }

                break;
            }
        }
    }
}

void Game::ammoEvents()
{
    vector<Block*> level_objects = level->getObjs();

    for (int i = 0; i < level_objects.size(); i++)
        if (*ammo_fire == *(level_objects[i]->getObj()))
        {
            hitNormalObject(level_objects[i], NULL);
            ammo_fire->setActive(false);
        }

    if (ammo_fire->isActive())
        ammo_fire->trans_vertical(-0.015);

    if (ammo_fire->gettz() < -0.2-level->getSize())
        ammo_fire->setActive(false);
}

void Game::bonusEvents()
{
    for (int i=0; i<10; i++)
        if (bonuses[i]->isActive())
        {
            bonuses[i]->trans_vertical(0.005);
            bonuses[i]->rotateY(1);

            if (bonuses[i]->gettz() > -0.3+level->getSize() && bonuses[i]->gettz() < -0.29+level->getSize() && bonuses[i]->gettx() > padle->gettx() - padle->getsx() && bonuses[i]->gettx() < padle->gettx() + padle->getsx())
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
                    level->setWall(2000);
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

                bonuses[i]->setActive(false);
            }
        }
}

void Game::end_level()
{
    if (level->getNum() % 10 == 0)
    {
        if (*isSound)
            sounds.play_sound(5, -1);
    }
    else
    {
        if (*isSound)
            sounds.play_sound(6, -1);
    }

    SDL_Delay(3000);
    
    int level_num = level->getNum();
    reset();
    player->increaseScore(20);

    if (level_num % 10 != 0)
    {
        level_num++;
        start(level_num);
    }
}

void Game::hitNormalObject(Block * obj, Ball * ball)
{
    obj->hit();

    if (obj->destroyed())
    {
        if (ball != NULL)
            ball->increaseSpeed(-0.0002);

        level->decreaseBlock();
        obj->addGravityRange();
        
        player->increaseScore(5);
        
        if (*isSound)
            sounds.play_sound(2, -1);

        if (level->getBlockNum() % 30 == 0)
        {
            stars[0]->settx(((float)(rand() % 10)/10.0)*level->getSize()*2);
            stars[0]->settz(((float)(rand() % 10)/10.0)*level->getSize()*2 - 0.75);
            stars[0]->setty(0.8);
            stars[0]->setActive(true);
        }


        if (level->getBlockNum() % 30 == 10)
        {
            stars[1]->settx(((float)(rand() % 10)/10.0)*level->getSize()*2);
            stars[1]->settz(((float)(rand() % 10)/10.0)*level->getSize()*2 - 0.75);
            stars[1]->setty(0.8);
            stars[1]->setActive(true);
        }

        if (level->getBlockNum() % 30 == 20)
        {
            stars[2]->settx(((float)(rand() % 10)/10.0)*level->getSize()*2);
            stars[2]->settz(((float)(rand() % 10)/10.0)*level->getSize()*2 - 0.75);
            stars[2]->setty(0.8);
            stars[2]->setActive(true);
        }

    }
    else //object hit but not destroyed
    {
        if (*isSound)
            sounds.play_sound(1, -1);
        player->increaseScore(2);
    }
}

void Game::hitBonusObject(Block * obj)
{
    obj->hit();
    level->decreaseBlock();
    obj->addGravityRange();

    player->increaseScore(3);
    if (*isSound)
        sounds.play_sound(3, -1);

    int k = rand() % 10;
    bonuses[k]->settx(obj->getObj()->gettx());
    bonuses[k]->settz(obj->getObj()->gettz());
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

void Game::launch()
{
    if (balls[0]->isLaunched())
    {
        if (player->getAmmo() > 0 && !ammo_fire->isActive())
        {
            if (*isSound)
                sounds.play_sound(7, -1);
            player->decreaseAmmo();
            ammo_fire->settx(padle->gettx());
            ammo_fire->settz(padle->gettz());
            ammo_fire->setActive(true);
        }
    }
    else 
        balls[0]->setSpeed(-0.018f);
}

void Game::rendering(int & jatekresz)
{

    if (player->getLife() < 1 || level->isCompleted())
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

        if (level->isCompleted())
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
        stars[i]->rendering(0);

    padle->rendering(0);

    for (int i=0; i<3; i++)
        if (balls[i]->isActive())
            balls[i]->getObj()->rendering(0);

    print(level->getBlockNum(), *block_title);
    for (int i=0; i<4; i++)
        titles[i]->rendering(0);

    print(player->getLife(), *life_title);
    print(player->getAmmo(), *ammo_title);
    print(player->getScore(), *score_title);
    print(top[0].score, *best_title);
    print(level->getNum(), *level_title);


    level->rendering();

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
    delete level;
    sounds.stop();
}

void Game::sethangok(bool * behang, bool * bezene)
{
    isSound = behang;
    isMusic = bezene;
}

void Game::start(const int & level_num)
{
    Object::setcz(-10.0f);
    Object::setcy(-10.0f);
    Object::setcz(-10.0f);

    level = new Level(level_num);

    if (level_num % 10 == 1)
        player->resetGame();
    player->resetLevel();    

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

    

    balls[0]->getObj()->settx(0.5f);
    balls[0]->getObj()->settz(-0.32f + level->getSize());
    balls[0]->setDefaults();
    
    for (int i = 1; i < 3; i++)
        balls[i]->setActive(false);

    padle->settx(0.5f);
    padle->settz(-0.25 + level->getSize());
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
    return level->isCompleted();
}

void Game::setBallSpeed(const float x)
{
    for (int j=0; j < 3; j++)
        balls[j]->setSpeed(x);
}