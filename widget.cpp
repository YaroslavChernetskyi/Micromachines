#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QMessageBox>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    game = &this->game->getInstance();

    setFixedSize(600,400);
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(gameUpdate()));
    timer->start(17);
}

Widget::~Widget()
{
    delete ui;
    delete timer;
}

void Widget::gameUpdate()
{
    if(game->getGameState())
        {
            timer->stop();
            QMessageBox::warning(this,"Micro", game->getWinMessage());
            this->close();
        }
    else
    {
        game->moveCamera();
        game->staticCollision();
        game->movingCollision();
        game->bridgeCollision();
        game->abyssCollision();
        game->trampCollision();
        game->gameOver();
        game->objectsMoving();
        update();
    }
}

void Widget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    game->drawGame(&painter);

}


void Widget::keyPressEvent(QKeyEvent *keyEvent)
{
    game->reactionToKeyPress(keyEvent);
}

void Widget::keyReleaseEvent(QKeyEvent *event)
{
    game->reactionToKeyRelease(event);
}



























//    pen.setWidth(1);
//    painter.setPen(pen);
//    for(int i =50; i <450; i+=25 )
//    {
//        //QLine(0,i,750,i);
//        painter.drawLine(QLine(0,i,750,i));
//    }
//    for(int i =50; i <750; i+=25 )
//    {
//        //QLine(0,i,750,i);
//        painter.drawLine(QLine(i,0,i,450));
//    }
//    pen.setColor(Qt::red);
//    painter.setPen(pen);
//    painter.drawLine(QLine(12*OBJECT_WIDTH,0,12*OBJECT_WIDTH,450));
//    painter.drawLine(QLine(17*OBJECT_WIDTH+15,0,17*OBJECT_WIDTH+15,450));
//    painter.drawLine(QLine(0,3*OBJECT_WIDTH,750,3*OBJECT_WIDTH));
//    painter.drawLine(QLine(0,5*OBJECT_WIDTH,750,5*OBJECT_WIDTH));
