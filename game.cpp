#include "game.h"
#include "car.h"
#include "QDebug"
#include "QTimer"
#include "opponent.h"
#include "widget.h"
#include "checkpoint.h"

Game& Game::getInstance() {
    static Game game;
    return game;
}

Game::Game()
{
    loadGame();
    createCheckpoint();
    counterForCar = 0;
    counterForOpponent = 0;
    m_gameOver = false;
    winMessage = "";
    myCarFactory = new MyCarFactory();
    opponentCarFactory = new OpponentCarFactory();
}
/*k
void Game::camera()
{
//    if(car->getX()<5*OBJECT_SIZE)
//    {
//        camX = 0;
//    }
//    else
//        camX = car->getX()-5*OBJECT_SIZE;
//    if(car->getX()>25*OBJECT_SIZE)
//    {
//        camW = 25*OBJECT_SIZE;
//    }
//    else camW = car->getX()+car->getWidth()+5*OBJECT_SIZE;

//    if(car->getY()<4*OBJECT_SIZE)
//    {
//        camY = 0;
//    }
//    else
//        camY = car->getY()-8*OBJECT_SIZE;
//    if(car->getY()>14*OBJECT_SIZE)
//    {
//        camH = 14*OBJECT_SIZE;
//    }
//    else
//        camH = car->getY()+car->getHeight()+8*OBJECT_SIZE;

//    camX = car->getX();
//    camY = car->getY();


}
l*/
Game::~Game()
{
    if(!gameCheckpointsObjects.empty())
        for(auto obj: gameCheckpointsObjects)
            delete obj;

    if(!gameStaticObjects.empty())
        for(auto obj: gameStaticObjects)
            delete obj;


    if(!gameMovingObjects.empty())
    {
        for(auto obj: gameMovingObjects)
        {
            delete obj;
        }
    }
}

void Game::objectsMoving()
{
    car->move();
    car->jump();
    opponent->changeAngle();
    opponent->move();
    opponent->jump();
}

void Game::reactionToKeyPress(QKeyEvent *event)
{
    car->moveAfterPress(event);
}

void Game::reactionToKeyRelease(QKeyEvent *event)
{
    car->moveAfterRelease(event);
}

void Game::loadGame()
{
    QFile file(":/img/level1.txt");
    if (file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        int i = 0;
        while (!file.atEnd())
        {
            QByteArray arr = file.readLine();
            for(int j = 0; j <= arr.size(); j++)
            {
                if(arr[j] == '1')
                {
                    Checkpoint* brick = new Checkpoint(j*OBJECT_SIZE, i*OBJECT_SIZE);
                    gameCheckpointsObjects.push_back(brick);
                }
                else if(arr[j] == '5')
                {
                    //this->car = new Car(0, j*OBJECT_SIZE, i*OBJECT_SIZE);
                    car = myCarFactory->createCar(0, j*OBJECT_SIZE, i*OBJECT_SIZE);
                    gameMovingObjects.push_back(car);
                }
                else if(arr[j] == '4')
                {
                    //this->opponent = new Opponent(0, j*OBJECT_SIZE, i*OBJECT_SIZE);
                    opponent = opponentCarFactory->createCar(0, j*OBJECT_SIZE, i*OBJECT_SIZE);
                    gameMovingObjects.push_back(opponent);
                }
                else if(arr[j] == '2')
                {
                    this->tramp = new Trampoline( j*OBJECT_SIZE, i*OBJECT_SIZE);
                    gameStaticObjects.push_back(tramp);
                }
                else if(arr[j] == '3')
                {
                    this->bridge = new Bridge( j*OBJECT_SIZE, i*OBJECT_SIZE);
                    gameStaticObjects.push_back(bridge);
                }
                else if(arr[j] == '6')
                {
                    this->abyss = new Abyss( j*OBJECT_SIZE, i*OBJECT_SIZE);
                    gameStaticObjects.push_back(abyss);
                }
            }
            i++;
        }
    }
    file.close();
}

void Game::drawBackground(QPainter *p)
{
    QPixmap n(":/img/map2.png");
    p->drawPixmap(0-camX, 0-camY,FIELD_WIDTH*OBJECT_SIZE, FIELD_HEIGHT*OBJECT_SIZE, n);
}

void Game::moveCamera()
{
    if(car->getX()>=4*OBJECT_SIZE&&car->getX()<=22*OBJECT_SIZE)
        {
            camX = car->getX()-4*OBJECT_SIZE;
        }
     else if(car->getX()<4*OBJECT_SIZE)
    {
        camX=0;
    }
    else if(car->getX()>22*OBJECT_SIZE)
        {
            camX=18*OBJECT_SIZE;
        }
    else
        camX = car->getX()-4*OBJECT_SIZE;
    if(car->getY()>=4*OBJECT_SIZE&&car->getY()<=14*OBJECT_SIZE)
        {
            camY = car->getY()-4*OBJECT_SIZE;
        }
    else if(car->getY()<4*OBJECT_SIZE)
   {
       camY=0;
   }
   else if(car->getY()<14*OBJECT_SIZE)
       {
           camX=12*OBJECT_SIZE;
       }
}

void Game::drawGame(QPainter *painter)
{
    drawBackground(painter);
    for (auto& obj : gameCheckpointsObjects)
    {
        obj->draw(painter,camX,camY);
    }
    for (auto& obj : gameStaticObjects)
    {
        obj->draw(painter,camX,camY);
    }
    for (auto& obj : gameMovingObjects)
    {
        obj->draw(painter,camX,camY);
    }
}

bool Game::checkCollisions(StaticObject* obj1, StaticObject* obj2)
{
    auto rect1 = obj1->boundRect();
    auto rect2 = obj2->boundRect();
    if(rect1.intersects(rect2))
        return true;
    else return false;
}

void Game::createCheckpoint()
{
    for(auto&it : gameCheckpointsObjects)
    {
        for(auto& i: gameCheckpointsObjects)
        {
            if(it->getY() - i->getY() > 0 && it->getY() - i->getY() < 4*OBJECT_SIZE
                    && it->getX() == i->getX())
            {
                checkpoint.first = it;
                checkpoint.second = i;
                checks.push_back(checkpoint);
            }
        }
    }
    std::swap(checks[2], checks[3]);
}

void Game::staticCollision()
{
    if(!gameMovingObjects.empty() && !gameCheckpointsObjects.empty())
    {
        for(auto obj1: gameMovingObjects)
        {
            for (auto obj2 : gameCheckpointsObjects)
            {
                if(checkCollisions(obj1, obj2))
                {
                    obj1->collisionWithObject(obj2);
                    break;
                }
            }
        }
    }
}

void Game::movingCollision()
{
    if(!gameMovingObjects.empty())
    {
        for(auto obj1 : gameMovingObjects)
        {
            for (auto obj2 : gameMovingObjects)
            {
                if(obj1 != obj2&&checkCollisions(obj1, obj2))
                {
                    obj1->collisionWithObject(obj2);
                    break;
                }
            }
        }
    }
}


void Game::bridgeCollision()
{
    for (auto obj : gameMovingObjects)
    {
        if(checkCollisions(obj, bridge))
        {
           obj->setHighness(1);
        }
    }
}

void Game::abyssCollision()
{
    for (auto obj : gameMovingObjects)
    {
        if(checkCollisions(obj, abyss))
        {
            obj->collisionWithAbyss();
        }
    }
}

void Game::trampCollision()
{
    for (auto obj : gameMovingObjects)
    {
        if(checkCollisions(obj, tramp))
        {
            obj->jumpingZone(true);
        }
        else
        {
            obj->jumpingZone(false);
        }
    }
}

int Game::passedCheckpoints(MovingObject * obj,int count)
{
    if(count!=4)
    {
        auto cp = checks.at(static_cast<unsigned int>(count));
        if(obj->getY() < cp.first->getY() && obj->getY() > cp.second->getY() &&
               obj->getX() < cp.first->getX() + 10 && obj->getX() > cp.first->getX() - 10)
        {
            count++;
        }
    }
    return count;
}

void Game::gameOver()
{
    counterForCar =  passedCheckpoints(car,counterForCar);
    counterForOpponent = passedCheckpoints(opponent, counterForOpponent);
    if(car->finish()&&counterForCar==4)
    {
        m_gameOver = true;
        winMessage = "You win!";
    }

    if(opponent->finish()&&counterForOpponent==4)
    {
        m_gameOver = true;
        winMessage = "You lose!";
    }
}

bool Game::getGameState()
{
    return m_gameOver;
}

QString Game::getWinMessage()
{
    return winMessage;
}




