//
//  GUI.hpp
//  CastleTowers
//
//  Created by Ahmed Nezar on 25/12/2022.
//

#ifndef GUI_hpp
#define GUI_hpp

#include <stdio.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "List.hpp"
#include "Balloon.hpp"
#include "Fighter.hpp"
#include "Battle.hpp"
#include <vector>

using namespace std;

class GUI {
private:
    
    void initVariables();
    void initWindow();
    string path;
    sf::RenderWindow* window;
    sf::Event ev;
    List enemies;
    vector<sf::Sprite> enemiesSprite;
    sf::Texture textures[3];
    float enemeySpawnTimer;
    float enemySpawnTimerMax;
    float castleShootTimer;
    float castleShootTimerMax;
    int maxDistance;
    int maxSpawn;
    bool win;
    int totalEnemies;
    Battle b;
//    sf::Sound victorySound;
//    sf::Sound defeatSound;
public:
    GUI();
    virtual ~GUI();
    
    void update();
    void render();
    bool isRunning();
    void pollEvents();
    void renderEnemeis(sf::RenderTarget&);
    void spawnEnemy();
    void updateEnemies();
    void renderCastle();
    void gameState(bool);
    void checkWin();
};

#endif /* GUI_hpp */
