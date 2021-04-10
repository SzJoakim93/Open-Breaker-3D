#include "Game.h"

Game::Game(Appsettings * appsettings, SDL_Event * event, Uint8* keystates, char * level_path, Top * top,
    void (*backToMenu)(void*),void* application) :
    sounds(appsettings), backToMenu(backToMenu), application(application), State(appsettings, event, keystates)
{
    //ctor
    player = new Player();

    for (int i=0; i<3; i++)
    {
        stars[i] = new Object(-0.2, 1.0, 0.1, //koordinatak
                              0, 0, 0, //elforgatas
                              0.025, 0.025, 0.01, //atmeretezes
                              NULL, "Colors/brown.bmp", "Objects/star1.obj");
        stars[i]->setActive(false);
    }
        
    bonuses = new Object* [10];

    char temp[32] = "Textures/bonus0.bmp";
    for (int i=0; i<10; i++)
    {
        bonuses[i] = new Object(0.5, -0.29, 1.0, //koordinatak
                              0, 0, 0, //elforgatas
                              0.05, 0.05, 0.05, //atmeretezes
                              STRECH_TEXTURED, temp, "rectangle");
        temp[14]++;
    }

    titles = new UI* [4];
    char temp2[32];
    if (appsettings->getLanguage() == HUN)
        strcpy(temp2, "Fonts/hungarian/title0.bmp");
    else
        strcpy(temp2, "Fonts/english/title0.bmp");
    float place = 0.0;
    if ((float)(appsettings->getWidth())/(float)(appsettings->getHeight()) < 1.3) //5:4
        place = 0.008;
    else if ((float)(appsettings->getWidth())/(float)(appsettings->getHeight()) < 1.4) //4:3
        place = 0.0;
    else if ((float)(appsettings->getWidth())/(float)(appsettings->getHeight()) < 1.7) //16:10
        place = -0.028;
    else if ((float)(appsettings->getWidth())/(float)(appsettings->getHeight()) < 1.8) //16:9
        place = -0.046;

    for (int i=0; i<4; i++)
    {
        titles[i] = new UI(-0.109+place, -0.025*i, //koordinatak
                             0.007, 0.0275, //atmeretezes
                            temp2, STRECH_TEXTURED);

        if (appsettings->getLanguage() == HUN)
            temp2[21]++;
        else
            temp2[19]++;
    }

    level_title = new UI_Label(-0.1+place, -0.067, //koordinatak
                           0.0033, 0.0022, //atmeretezes
                           "Fonts/letters", "");

    life_title = new UI_Label(-0.1+place, -0.075, //koordinatak
                          0.0033, 0.0022, //atmeretezes
                          "Fonts/letters", "");

    ammo_title = new UI_Label(-0.1+place, -0.083, //koordinatak
                          0.0033, 0.0022, //atmeretezes
                        "Fonts/letters", "");

    block_title = new UI_Label(-0.134+place, -0.057, //koordinatak
                            0.0033, 0.0022, //atmeretezes
                            "Fonts/letters", "");

    score_title = new UI_Label(-0.134+place, -0.037, //koordinatak
                            0.0033, 0.0022, //atmeretezes
                            "Fonts/letters", "");

    best_title = new UI_Label(-0.134+place, 0.08, //koordinatak
                            0.0033, 0.0022, //atmeretezes
                            "Fonts/letters", "");

    gamebox = new UI(0.0, 0.0, //koordinatak
                        0.074, 0.166, //atmeretezes
                        "Fonts/english/w.bmp", STRECH_TEXTURED);

    gameover = new UI(-0.015, 0.02, //koordinatak
                        0.005, 0.0025, //atmeretezes
                        "Fonts/letters", STRECH_TEXTURED);

    g_title = new UI(-0.022, 0.01, //koordinatak
                        0.005, 0.0025,
                        "Fonts/letters", STRECH_TEXTURED);

    r_title = new UI(-0.028, -0.025, //koordinatak
                        0.005, 0.0025,
                        "Fonts/letters",STRECH_TEXTURED);

    text = new UI(-0.03, -0.01, //koordinatak
                    0.005,  0.0025, //atmeretezes
                    "Fonts/letters", STRECH_TEXTURED);

    textbox = new UI(0.00, -0.01, //koordinatak
                        0.012, 0.08, //atmeretezes
                        "Fonts/frame.bmp", STRECH_TEXTURED);

    titles[0]->setTY(0.09);
    titles[3]->setTX(-0.123+place);
    titles[3]->setSY(0.014);
    titles[3]->setSX(0.014);



    Ball::setSounds(&sounds);
    for (int i=0; i<3; i++)
        balls[i] = new Ball(new Object(0.5f, -0.27f, -0.32f, //koordinatak
                           0, 180, 0, //elforgatas
                           0.04f, 0.04f, 0.04f, //atmeretezes
                           NULL, "Colors/red.bmp", "Objects/sphere.obj"), false);

    padle = new Object(0.5f, -0.27f, -0.25, //koordinatak
                     0, 0, 0, //elforgatas
                     0.1f, 0.025f, 0.025f, //atmeretezes
                     NULL, "Colors/gray.bmp", "Objects/padle.obj");

    ammo_fire = new Object(0.5f, -0.27f, -0.32f, //koordinatak
                         0, 270, 0, //elforgatas
                         0.04f, 0.01f, 0.04f, //atmeretezes
                         STRECH_TEXTURED, "Textures/ammo.bmp", "rectangle");

    ammo_fire->setActive(false);

    for (int i=0; i<8; i++)
        play_list[i]=true;
    char ** soundpath= new char*[9];
    for (int i=0; i<9; i++)
        soundpath[i] = new char[32];

    strcpy(soundpath[0], "Sounds/B1.WAV");
    strcpy(soundpath[1], "Sounds/B2.WAV");
    strcpy(soundpath[2], "Sounds/B3.WAV");
    strcpy(soundpath[3], "Sounds/BONUS.WAV");
    strcpy(soundpath[4], "Sounds/EFFECT0.WAV");
    strcpy(soundpath[5], "Sounds/END_OF_G.WAV");
    strcpy(soundpath[6], "Sounds/END_OF_L.WAV");
    strcpy(soundpath[7], "Sounds/FIRE.WAV");
    strcpy(soundpath[8], "Sounds/STAR.WAV");

    sounds.add(soundpath, 9);

    left_key_pressed = false;
    right_key_pressed = false;

    this->top = top;
    this->scorename = scorename;
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

void Game::handleEvents()
{
    level->cameraAnimation();

    if (player->getLife() > 0 && !level->isCompleted())
    {
        starEvents();

        if (keystates[SDLK_LEFT] && padle->getTX() - padle->getSX() > 0.5-level->getSize())
            padle->translateX(-0.015);

        if (keystates[SDLK_RIGHT] && padle->getTX() + padle->getSX() < 0.5+level->getSize())
            padle->translateX(+0.015);

        ball_events();
        level->events();
        ballCollisions();
        ammoEvents();
        bonusEvents();

        if (level->isCompleted())
        {
            end_level();
            return;
        }

        if (player->getLife() == 0)
            backToMenu(application);
    }

}

void Game::hanldeSDLEvents()
{
    if (keystates[SDLK_SPACE])
        launch();
}

void Game::starEvents()
{
    for (int i=0; i<3; i++)
        if (stars[i]->isActive())
        {
            stars[i]->rotateY(1);
            if (stars[i]->getTY() > -0.2)
                stars[i]->translateY(-0.002);
        }
}

void Game::ball_events()
{
    for (int i=0; i<3; i++)
        if (balls[i]->isActive())
        {
            balls[i]->moving();

            if (!balls[i]->isLaunched())
                balls[i]->getObj()->setTX(padle->getTX());

            balls[i]->pongFromBorder(level->getSize(), level->isWall());


            if (balls[i]->collision(padle) && balls[i]->getObj()->getTZ() < padle->getTZ() - 0.03)
            {
                sounds.play_sound(0, -1);
                if (player->isGrip())
                {
                    balls[i]->setSpeed(0.0f);
                    balls[i]->getObj()->setTX(padle->getTX());
                    balls[i]->getObj()->setTZ( padle->getTZ() - 0.07);
                }

                balls[i]->pongFromPaddle(padle);
            }

            if (balls[i]->getObj()->getTZ() > 0.4+level->getSize())
                balls[i]->setActive(false);
        }

    if (Ball::getActiveBalls() == 0)
    {
        increaseLife(-1);
        if (player->getLife() > 0)
        {
            balls[0]->setActive(true);
            balls[0]->getObj()->setTX(padle->getTX());
            balls[0]->getObj()->setTZ(-0.32+level->getSize());
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
            if (stars[i]->getTY() < 0.2 && *(balls[j]->getObj()) == *stars[i])
            {
                increaseScore(15);
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
                        balls[j]->setPositiveDir_Y();
                    else if (balls[j]->collision_left(level_objects[i]->getObj()))
                        balls[j]->setNegativeDir_X();
                    else if (balls[j]->collision_back(level_objects[i]->getObj()))
                        balls[j]->setNegativeDir_Y();
                    else if (balls[j]->collision_right(level_objects[i]->getObj()))
                        balls[j]->setPositiveDir_X();
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
        if (level_objects[i]->getObj()->getTY() - level_objects[i]->getObj()->getSY() + 0.2f < 0.05f && *ammo_fire == *(level_objects[i]->getObj()))
        {
            hitNormalObject(level_objects[i], NULL);
            ammo_fire->setActive(false);
        }

    if (ammo_fire->isActive())
        ammo_fire->translateZ(-0.015);

    if (ammo_fire->getTZ() < -0.2-level->getSize())
        ammo_fire->setActive(false);
}

void Game::bonusEvents()
{
    for (int i=0; i<10; i++)
        if (bonuses[i]->isActive())
        {
            bonuses[i]->translateZ(0.005);
            bonuses[i]->rotateY(1);

            if (bonuses[i]->getTZ() > -0.3+level->getSize() && bonuses[i]->getTZ() < -0.29+level->getSize() && bonuses[i]->getTX() > padle->getTX() - padle->getSX() && bonuses[i]->getTX() < padle->getTX() + padle->getSX())
            {
                sounds.play_sound(4, -1);
                switch (i)
                {
                case 0:
                {
                    increaseAmmo(10);
                    increaseScore(5);
                    break;
                }
                case 1:
                {
                    increaseLife(3);
                    increaseScore(10);
                    break;
                }
                case 2:
                {
                    //triplaball
                    balls[1]->cloneBall(balls[0], 0);
                    balls[2]->cloneBall(balls[0], 1);
                    increaseScore(5);
                    break;
                }
                case 3:
                {
                    player->setMegaBall(true);
                    increaseScore(5);
                    break;
                }
                case 4:
                {
                    level->setWall(2000);
                    increaseScore(5);
                    break;
                }
                case 5:
                {
                    setBallSpeed(-0.01);
                    increaseScore(5);
                    break;
                }
                case 6:
                {
                    player->setGrip(true);
                    increaseScore(5);
                    break;
                }
                case 7:
                {
                    padle->setSX(padle->getSX()+0.05f);
                    increaseScore(5);
                    break;
                }
                case 8:
                {
                    padle->setSX(0.05);
                    increaseScore(-10);
                    break;
                }
                case 9:
                {
                    setBallSpeed(-0.025f);
                    increaseScore(-10);
                    break;
                }
                }

                bonuses[i]->setActive(false);
            }
        }
}

void Game::end_level()
{
    sounds.stop();
    if (level->getNum() % 10 == 0)
        sounds.play_sound(5, -1);
    else
        sounds.play_sound(6, -1);

    SDL_Delay(3000);
    
    int level_num = level->getNum();
    stop();
    increaseScore(20);

    if (level_num % 10 != 0)
    {
        level_num++;
        start(level_num);
    }
    else
        backToMenu(application);
    
}

void Game::hitNormalObject(Block * obj, Ball * ball)
{
    obj->hit();

    if (obj->destroyed())
    {
        if (ball != NULL)
            ball->increaseSpeed(-0.0002);

        level->decreaseBlock();
        block_title->setText(level->getBlockNum());
        obj->addGravityRange();
        
        increaseScore(5);
        
        sounds.play_sound(2, -1);

        if (level->getBlockNum() % 30 == 0)
        {
            stars[0]->setTX(((float)(rand() % 10)/10.0)*level->getSize()*2);
            stars[0]->setTZ(((float)(rand() % 10)/10.0)*level->getSize()*2 - 0.75);
            stars[0]->setTY(0.8);
            stars[0]->setActive(true);
        }


        if (level->getBlockNum() % 30 == 10)
        {
            stars[1]->setTX(((float)(rand() % 10)/10.0)*level->getSize()*2);
            stars[1]->setTZ(((float)(rand() % 10)/10.0)*level->getSize()*2 - 0.75);
            stars[1]->setTY(0.8);
            stars[1]->setActive(true);
        }

        if (level->getBlockNum() % 30 == 20)
        {
            stars[2]->setTX(((float)(rand() % 10)/10.0)*level->getSize()*2);
            stars[2]->setTZ(((float)(rand() % 10)/10.0)*level->getSize()*2 - 0.75);
            stars[2]->setTY(0.8);
            stars[2]->setActive(true);
        }

    }
    else //object hit but not destroyed
    {
        sounds.play_sound(1, -1);
        increaseScore(2);
    }
}

void Game::hitBonusObject(Block * obj)
{
    obj->hit();
    level->decreaseBlock();
    block_title->setText(level->getBlockNum());
    obj->addGravityRange();

    increaseScore(3);
    sounds.play_sound(3, -1);

    int k = rand() % 10;
    bonuses[k]->setTX(obj->getObj()->getTX());
    bonuses[k]->setTZ(obj->getObj()->getTZ());
    bonuses[k]->setActive(true);
}

void Game::launch()
{
    if (balls[0]->isLaunched())
    {
        if (player->getAmmo() > 0 && !ammo_fire->isActive())
        {
            sounds.play_sound(7, -1);
            increaseAmmo(-1);
            ammo_fire->setTX(padle->getTX());
            ammo_fire->setTZ(padle->getTZ());
            ammo_fire->setActive(true);
        }
    }
    else 
        balls[0]->setSpeed(-0.018f);
}

void Game::rendering()
{

    /*if (player->getLife() < 1 || level->isCompleted())
    {
        if (player->getScore() > top[9].score)
        {
            text->gprintf(scorename);
            textbox->rendering();
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

        gamebox->rendering();
    }*/


    for (int i=0; i<3; i++)
        stars[i]->rendering();

    padle->rendering();

    for (int i=0; i<3; i++)
        if (balls[i]->isActive())
            balls[i]->getObj()->rendering();

    level->rendering();

    for (int i=0; i<10; i++)
        if (bonuses[i]->getTZ() < 1.0f)
            bonuses[i]->rendering();

    if (ammo_fire->getTZ() < 1.0f)
        ammo_fire->rendering();

    block_title->rendering();
    life_title->rendering();
    ammo_title->rendering();
    score_title->rendering();
    best_title->rendering();
    level_title->rendering();

    for (int i=0; i<4; i++)
        titles[i]->rendering();
}

void Game::stop()
{
    delete level;
    sounds.stop();
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

    level_title->setText(level_num);
    ammo_title->setText(player->getAmmo());
    life_title->setText(player->getLife());
    score_title->setText(player->getScore());
    best_title->setText(top[0].score);

    if (appsettings->isMusicEnabled())
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
        sprintf(mus_path, "Music/%d.wav", x+1);
        sounds.play_music(mus_path);
    }

    for (int i = 1; i < 3; i++)
        balls[i]->setActive(false);

    for (int i = 0; i < 10; i++)
        bonuses[i]->setActive(false);

    padle->setTX(0.5f);
    padle->setTZ(-0.25 + level->getSize());

    balls[0]->getObj()->setTX(0.5f);
    balls[0]->getObj()->setTZ(padle->getTZ() - 0.07);
    balls[0]->setActive(true);
    balls[0]->setDefaults();
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

void Game::increaseScore(const int x)
{
    player->increaseScore(x);
    score_title->setText(player->getScore());
}

void Game::increaseLife(const int x)
{
    player->increaseLife(x);
    life_title->setText(player->getLife());
}

void Game::increaseAmmo(const int x)
{
    player->increaseAmmo(x);
    ammo_title->setText(player->getAmmo());
}