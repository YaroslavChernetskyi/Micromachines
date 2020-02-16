#ifndef GAME_H
#define GAME_H

#include <QPainter>
#include <QKeyEvent>
//#include "opponent.h"
//#include "car.h"
#include "mycarfactory.h"
#include "opponentcarfactory.h"
#include "abyss.h"
#include "trampoline.h"
#include "bridge.h"

class Game
{
public:
    void drawGame(QPainter*);
    void drawBackground(QPainter *);
    void staticCollision();
    void movingCollision();
    void abyssCollision();
    void bridgeCollision();
    void trampCollision();
    void objectsMoving();
    void reactionToKeyPress(QKeyEvent *event);
    void reactionToKeyRelease(QKeyEvent *event);
    int passedCheckpoints(MovingObject*,int);
    void gameOver();
    bool getGameState();
    QString getWinMessage();
    void moveCamera();
    static Game& getInstance();

private:
    Game();
    ~Game();
    Game(const Game& rhs) = delete;
    Game& operator=(const Game& rhs) = delete;
    Car* car;
    Opponent* opponent;
    Bridge* bridge;
    Abyss* abyss;
    Trampoline* tramp;
    QString winMessage;
    MyCarFactory * myCarFactory;
    OpponentCarFactory* opponentCarFactory;
    std::list<MovingObject*> gameMovingObjects;
    std::list<StaticObject*> gameCheckpointsObjects;
    std::list<StaticObject*> gameStaticObjects;
    std::pair<StaticObject*, StaticObject*> checkpoint;
    std::vector<std::pair<StaticObject*, StaticObject*>> checks;
    bool checkCollisions(StaticObject* obj1, StaticObject* obj2);
    int counterForCar,counterForOpponent;
    bool m_gameOver;
    int camX, camY;
    void createCheckpoint();
    void loadGame();
};

#endif // GAME_H
