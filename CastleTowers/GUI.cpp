//
//  GUI.cpp
//  CastleTowers
//
//  Created by Ahmed Nezar on 25/12/2022.
//

#include "GUI.hpp"

using namespace std;


void GUI::initVariables() {
    window = nullptr;
    path = "/Users/ahmednezar/Desktop/Gam3a/Semester 5/Data Structure/Project/CastleTowers/images/";
    enemySpawnTimerMax = 1000;
    enemeySpawnTimer = enemySpawnTimerMax;
    castleShootTimerMax = 60;
    castleShootTimer = castleShootTimerMax;
    sf::Texture texture, texture2, texture3;
    if(!texture.loadFromFile(path + "enemy.png")) {
        cerr << "Cannot read from file" << endl;
    }if(!texture2.loadFromFile(path + "fighter.png")) {
        cerr << "Cannot read from file" << endl;
    }if(!texture3.loadFromFile(path + "balloon.png")) {
        cerr << "Cannot read from file" << endl;
    }
    textures[0] = texture;
    textures[1] = texture2;
    textures[2] = texture3;
    maxDistance = 580;
    maxSpawn = 8;
    win = false;
    totalEnemies = 0;
    sf::Music music;
//    if (!music.openFromFile(path + "Victory.wav")) cerr << "Cannot read from file" << endl;
//    music.play();
    //    sf::SoundBuffer buffer2;
//    if (!buffer2.loadFromFile(path + "Defeat.wav")) cerr << "Cannot read from file" << endl;
//    defeatSound.setBuffer(buffer2);
//    victorySound.play();
    
}


void GUI::initWindow() {
    window = new sf::RenderWindow(sf::VideoMode(1680, 1280), "Castle Battle");
    window->setFramerateLimit(60);
}

GUI::GUI() {
    initVariables();
    initWindow();
}

GUI::~GUI() {
    delete window;
}

bool GUI::isRunning() {
    return window->isOpen();
}

void GUI::pollEvents() {
    while (window->pollEvent(ev)) {
        if(ev.type == sf::Event::Closed) window->close();
    }
}

void GUI::spawnEnemy() {
    if(win && totalEnemies >= maxSpawn) return;
    for(int i = 0; i < 4; i++) {
        Enemy * e;
        int enemytype = rand() % 3 ;
        switch (enemytype) {
            case 0:
                e = new Enemy(i);
                break;
            case 1:
                e = new Balloon(i);
                break;
            case 2:
                e = new Fighter(i);
                break;
            default:
                e = new Enemy(i);
                break;
        }
        if(win) e->setWinDamage();
        enemies.insertLast(e);
        int flip = (i == 0 || i == 2) ? 1 : -1;
        sf::Sprite sprite;
        sprite.setTexture(textures[enemytype]);
        sprite.setScale(0.2 * flip, 0.2);
        int xVal = (i == 0 || i == 2) ? 0 : 1680;
        int yVal = (i == 0 || i == 1) ? (rand() % 181) + 420 : (rand() % 181) + 600;
        sprite.setPosition(xVal, yVal);
        enemiesSprite.push_back(sprite);
        Castle::castles[i].enemies.enqueue(e, e->getPriority());
        totalEnemies++;
    }
}

void GUI::updateEnemies() {
    
    if(enemeySpawnTimer >= enemySpawnTimerMax) {
        spawnEnemy();
        enemeySpawnTimer = 0;
    }
    else enemeySpawnTimer += 1.0f;
    
    if(castleShootTimer >= castleShootTimerMax) {
        b.castleKill();
        castleShootTimer = 0;
        for(int i = 0; i < enemies.nodeCount(); i++) {
            if(enemies.get(i)->getDistance() >= maxDistance && Castle::castles[enemies.get(i)->getRegion()].getHealth() > 0) enemies.get(i)->fight();
        }
    }
    else castleShootTimer += 1.0f;
    
    
    vector<sf::Sprite>::iterator it = enemiesSprite.begin();
    int index = 0;
    while(it != enemiesSprite.end()) {
        
        //Move
        if(enemies.get(index)->getDistance()  < maxDistance) {
            float moveVal = (enemies.get(index)->getRegion() == 0 || enemies.get(index)->getRegion() == 2) ? 1.f : -1.f;
            
            enemiesSprite[index].move(moveVal, 0.f);
            enemies.get(index)->move();
        }

        //Check Health
        if(enemies.get(index)->getHealth() <= 0) {
            enemies.erase(index);
            it = enemiesSprite.erase(it);
        }
        else {
            it++;
            index++;
        }
    }
}

void GUI::renderEnemeis(sf::RenderTarget& target) {
    for (auto &e : enemiesSprite) {
        target.draw(e);
    }
}

void GUI::update() {
    pollEvents();
    updateEnemies();
}

void GUI::render() {
    window->clear(sf::Color(255, 255, 255, 255));
    
    renderCastle();
    renderEnemeis(*window);
    checkWin();
    
    window->display();
}

void GUI::renderCastle() {
    sf::Texture backgroundTexture;
    if(!backgroundTexture.loadFromFile(path + "background.jpg")) {
        cerr << "Cannot read from file" << endl;
    }
    sf::Sprite backgroundSprite;
    sf::Vector2u textureSize = backgroundTexture.getSize();
    sf::Vector2u windowSize = window->getSize();
    float scaleX = (float) windowSize.x / textureSize.x;
    float scaleY = (float) windowSize.y / textureSize.y;
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(scaleX, scaleY);
    window->draw(backgroundSprite);

    sf::Texture texture;
    if(!texture.loadFromFile(path + "castle.jpg")) {
        cerr << "Cannot read from file" << endl;
    }
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setScale(1.5, 1.5);
    sprite.setPosition(680, 460);
    window->draw(sprite);
    
    int lostCastles = 0;
    for(int i = 0; i < NoOfRegions; i++) {
        string reg = (i == 0) ? "rega" : (i == 1) ? "regb" : (i == 2) ? "regd" : "regc";
        if(Castle::castles[i].getHealth() <= 0) {
            lostCastles++;
            sf::Texture texture2;
            if(!texture2.loadFromFile(path + reg + ".jpg")) {
                cerr << "Cannot read from file" << endl;
            }
            sf::Sprite sprite2;
            int xVal = (i == 1 || i == 3) ? 180 : 0;
            int yVal = (i == 2 || i == 3) ? 180 : 0;
            sprite2.setTexture(texture2);
            sprite2.setScale(1.5, 1.5);
            sprite2.setPosition(680 + xVal, 460 + yVal);
            window->draw(sprite2);
        }
    }
    if(lostCastles == 4) gameState(false);
}

void GUI::checkWin() {
    if(totalEnemies >= maxSpawn && win) {
        bool exist = false;
        for(int i = 0; i < NoOfRegions; i++) {
            if(Castle::castles[i].getHealth() > 0) {
                for(int x = 0; x < enemies.nodeCount(); x++) {
                    if(enemies.get(x)->getRegion() == i) {
                        exist = true;
                        break;
                    }
                }
            }
        }
        if(!exist) {
            gameState(true);
        }
    }
}

void GUI::gameState(bool win) {
    
    sf::Texture texture;
    string t = (win) ? "victory" : "defeat";
    if(!texture.loadFromFile(path + t + ".jpg")) {
        cerr << "Cannot read from file" << endl;
    }
    sf::Sprite sprite;
    sf::Vector2u textureSize = texture.getSize();
    sf::Vector2u windowSize = window->getSize();
    float scaleX = (float) windowSize.x / textureSize.x;
    float scaleY = (float) windowSize.y / textureSize.y;
    sprite.setTexture(texture);
    sprite.setScale(scaleX, scaleY);
    enemiesSprite.clear();
    window->draw(sprite);
}
