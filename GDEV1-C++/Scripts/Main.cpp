#include <iostream>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Time.h"
#include "Physics.h"
#include "GameRules.h"

#include "Variables/Vector2.h"
#include "Components/Object.h"

#include "GameObjects/Player.h"
#include "GameObjects/EnemyCar.h"


using namespace std;

sf::RenderWindow window;
vector<shared_ptr<Object>> objects;
vector<shared_ptr<DrawObject>> sprites;

sf::Texture backgroundTexture;
sf::Sprite background;

sf::Text textScore;
sf::Text textEnd;
sf::Text textPress;
sf::Font font;


void handleBackground();
void handleUI();
void handleWin();
void handleLose();

void callUpdate();
void callTickUpdate();
void drawSprites();

void startGame();


int main()
{
    window.create(sf::VideoMode(854, 480), "DashRacer++");

    window.setVerticalSyncEnabled(true);

    srand(time(NULL));

    font.loadFromFile("Fonts/ARCADECLASSIC.ttf");

    textScore.setFont(font);
    textEnd.setFont(font);
    textPress.setFont(font);
    textScore.setLetterSpacing(2);
    textEnd.setLetterSpacing(2);
    textPress.setLetterSpacing(2);
    textScore.setCharacterSize(48);
    textEnd.setCharacterSize(48);
    textPress.setCharacterSize(48);


    backgroundTexture.loadFromFile("Sprites/BackgroundStreet.png");
    backgroundTexture.setRepeated(true);
    background.setTexture(backgroundTexture);
    background.setTextureRect(sf::IntRect(0, 0, 854, 528));


    Time& instanceTime = Time::getInstance();
    GameRules& instanceGameRules = GameRules::getInstance();

    instanceTime.initializeClock();

    startGame();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();


        instanceTime.restartClock();

        handleBackground();

        if (instanceGameRules.won)
        {
            handleWin();
        }
        if (instanceGameRules.lose)
        {
            handleLose();
        }


        handleUI();

        callUpdate();
        drawSprites();

        //Tick/fixed update loop. Waits for time to pass and does it multiple times if required.
        //This way differing framerates dont impact the game without resorting to capping framerate.
        while (instanceTime.waitForTicks > instanceTime.tickRate)
        {
            callTickUpdate();

            instanceTime.waitForTicks -= instanceTime.tickRate;
        }

        window.display();
    }

    return 0;
}

#pragma region Handlers

void handleBackground() 
{
    Time& instanceTime = Time::getInstance();
    GameRules& instanceGameRules = GameRules::getInstance();
    float positionY = background.getPosition().y;
    float speedModifier = instanceTime.deltaTime.asSeconds() * 500 * instanceGameRules.carSpeed;

    background.setPosition(0, positionY + speedModifier);
    if (positionY - speedModifier > 0)
    {
        background.setPosition(0, fmod(positionY + speedModifier - 48, 48));
    }

    window.draw(background);
}

void handleUI()
{
    GameRules& instanceGameRules = GameRules::getInstance();
    textScore.setString("  SCORE\n  " + to_string(instanceGameRules.points));

    window.draw(textScore);
}

void handleWin() 
{
    textEnd.setString("YOU   WIN!");
    textPress.setString("Press  both  arrow  keys  to  restart");

    sf::FloatRect endRect = textEnd.getLocalBounds();
    sf::FloatRect pressRect = textPress.getLocalBounds();
    textEnd.setOrigin(endRect.left + endRect.width / 2, endRect.top + endRect.height / 2);
    textPress.setOrigin(pressRect.left + pressRect.width / 2, pressRect.top + pressRect.height / 2);
    textEnd.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
    textPress.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2 + 48));

    window.draw(textEnd);
    window.draw(textPress);

    int input = sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right) + sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left);
    if (input == 2) 
    {
        startGame();

        GameRules& instanceGameRules = GameRules::getInstance();
        instanceGameRules.won = false;
    }
}

void handleLose()
{
    textEnd.setString("YOU   LOSE");
    textPress.setString("Press  both  arrow  keys  to  restart");

    sf::FloatRect endRect = textEnd.getLocalBounds();
    sf::FloatRect pressRect = textPress.getLocalBounds();
    textEnd.setOrigin(endRect.left + endRect.width / 2, endRect.top + endRect.height / 2);
    textPress.setOrigin(pressRect.left + pressRect.width / 2, pressRect.top + pressRect.height / 2);
    textEnd.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
    textPress.setPosition(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2 + 48));

    window.draw(textEnd);
    window.draw(textPress);

    int input = sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Right) + sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::Left);
    if (input == 2)
    {
        startGame();

        GameRules& instanceGameRules = GameRules::getInstance();
        instanceGameRules.lose = false;
    }
}

#pragma endregion


#pragma region Calls

//Calls Update to all Objects attached to the objects vector.
void callUpdate()
{
    for (unsigned int i = 0; i < objects.size(); ++i) {
        objects.at(i)->update();
    }
}

//See above, but for ticked updates.
void callTickUpdate() 
{
    for (unsigned int i = 0; i < objects.size(); ++i) {
        objects.at(i)->tickUpdate();
    }
}

void drawSprites() 
{
    for (unsigned int i = 0; i < sprites.size(); ++i) {
        window.draw(sprites.at(i)->sprite);
    }
}

#pragma endregion


void startGame()
{
    objects.clear();
    sprites.clear();

    Physics& instancePhysics = Physics::getInstance();
    instancePhysics.colliders.clear();

    Time& instanceTime = Time::getInstance();
    instanceTime.timeScale = 1;

    GameRules& instanceGameRules = GameRules::getInstance();
    instanceGameRules.points = 0;

    shared_ptr<Player> player = make_shared<Player>();
    objects.push_back(player);
    sprites.push_back(player);
    instancePhysics.colliders.push_back(player);

    shared_ptr<EnemyCar> enemy1 = make_shared<EnemyCar>();
    objects.push_back(enemy1);
    sprites.push_back(enemy1);
    instancePhysics.colliders.push_back(enemy1);

    shared_ptr<EnemyCar> enemy2 = make_shared<EnemyCar>();
    objects.push_back(enemy2);
    sprites.push_back(enemy2);
    instancePhysics.colliders.push_back(enemy2);
}