#include "Game.h"

Game::Game()
{
    //for now it's gonna be a constant, but later this may be changed to level selection
    currentLevel = loadLevel(Game::LEVEL_1);
    drawLevel(currentLevel);
    initViewScene();
    bulletTimer = new QTimer();
    bulletTimer->setInterval(30);
    bulletTimer->setSingleShot(false);
    spawnTimer = new QTimer();
    spawnTimer->setInterval(5000);
    spawnTimer->setSingleShot(false);
    AIControlTimer = new QTimer();
    AIControlTimer->setInterval(200);
    AIControlTimer->setSingleShot(false);

    connect(bulletTimer,    &QTimer::timeout, [this]() {onBulletTimeout();   });
    connect(spawnTimer,     &QTimer::timeout, [this]() {onSpawnTimeout();    });
    connect(AIControlTimer, &QTimer::timeout, [this]() {onAIControlTimeout();});
    spawnTimer->start();
}

Game::~Game()
{
    delete bulletTimer;
}

Level Game::loadLevel(uint Id)
{
    return levelLoader.loadLevel(Id);
}


void Game::drawLevel(Level & level)
{
    QVector<int> tempLevel = level.getMap();
    for (int i=0; i<tempLevel.length();i++)
    {
        if (tempLevel[i]==Level::ENEMY_SPAWN)
        {
            level.addEnemySpawnPoint(i);
        }
        //GameObject *item = new GameObject(level.getMap()[i]);
        if (tempLevel[i] != Level::TILE_EMPTY
                && tempLevel[i] != Level::ENEMY_SPAWN)
        {
            GameObject * item = createObject(tempLevel[i]);

            if(item!=nullptr)
            {
                //scene.addItem(item);
                //addItem(item);
                item->setPos(((i%level.getWidth()))*16, i/level.getWidth()*16);
            }
        }
    }
}

void Game::initViewScene(void)
{
    view.setScene(this);
    view.setFixedSize(640, 480);
    setBackgroundBrush(Qt::black);
    setSceneRect(0,0, 640, 480);
    view.fitInView(sceneRect(), Qt::KeepAspectRatio);
    view.show();
    view.setFocusPolicy(Qt::StrongFocus);//remove me
    setFocus();

}
#include <QDateTime>
void Game::keyPressEvent(QKeyEvent * event)
{
    static quint64 prevTime;
    auto currentTime = QDateTime::currentMSecsSinceEpoch();

    if (currentTime - prevTime < 60) {
        return;
    }

    prevTime = currentTime;

    //todo:make distinction between the menu and actual game
    if (player1Tank != nullptr)
    {
        QRectF playerRect = player1Tank->boundingRect();
        QPointF initialPos = player1Tank->pos();
        QPoint nextMovementPos;
        //make switch
        if (event->key() == Qt::Key_Left)
        {
            if(player1Tank->pos().x() > 0)
            {
                nextMovementPos.setX(player1Tank->pos().x()-8);
                nextMovementPos.setY(player1Tank->pos().y());

                player1Tank->setPos(nextMovementPos);
                //TODO: move to separate func
                if(!player1Tank->collidingItems().isEmpty())
                {
                    foreach(QGraphicsItem *obj, player1Tank->collidingItems())
                    {
                        GameObject * gameObj = static_cast<GameObject*>(obj);
                        qDebug() << "collides: " << gameObj->getObjectType();
                        switch(gameObj->getObjectType())
                        {
                        case Level::TILE_BRICK:
                        case Level::TANK:
                        case Level::TILE_STEEL:
                        case Level::GOBLET:
                            player1Tank->setPos(initialPos);
                            break;
                        default:
                            qDebug() << "collision with uknown object";
                        }
                    }
                }
                else
                {
                    player1Tank->setOrientation(PlayerTank::left);
                }
            }
        }
        else if (event->key() == Qt::Key_Right)
        {

            if (player1Tank->pos().x()+playerRect.width() < width())
            {
                nextMovementPos.setX(player1Tank->pos().x()+8);
                nextMovementPos.setY(player1Tank->pos().y());

                player1Tank->setPos(nextMovementPos);
                //TODO: move to separate func
                if(!player1Tank->collidingItems().isEmpty())
                {
                    foreach(QGraphicsItem *obj, player1Tank->collidingItems())
                    {
                        GameObject * gameObj = static_cast<GameObject*>(obj);
                        qDebug() << "collides: " << gameObj->getObjectType();
                        switch(gameObj->getObjectType())
                        {
                        case Level::TILE_BRICK:
                        case Level::TANK:
                        case Level::TILE_STEEL:
                        case Level::GOBLET:
                            player1Tank->setPos(initialPos);
                            break;
                        default:
                            qDebug() << "collision with uknown object";
                        }
                    }
                }
                else
                {
                    player1Tank->setOrientation(PlayerTank::right);
                }
            }
        }
        else if (event->key() == Qt::Key_Up)
        {
            if(player1Tank->pos().y() > 0)
            {

                nextMovementPos.setX(player1Tank->pos().x());
                nextMovementPos.setY(player1Tank->pos().y()-8);//magic number, make const and name like STEP

                player1Tank->setPos(nextMovementPos);
                //TODO: move to separate func
                if(!player1Tank->collidingItems().isEmpty())
                {
                    foreach(QGraphicsItem *obj, player1Tank->collidingItems())
                    {
                        GameObject * gameObj = static_cast<GameObject*>(obj);
                        qDebug() << "collides: " << gameObj->getObjectType();
                        switch(gameObj->getObjectType())
                        {
                        case Level::TILE_BRICK:
                        case Level::TANK:
                        case Level::TILE_STEEL:
                        case Level::GOBLET:
                            player1Tank->setPos(initialPos);
                            break;
                        default:
                            qDebug() << "collision with uknown object";
                        }
                    }
                }
                else
                {
                    player1Tank->setOrientation(PlayerTank::up);
                }
            }
        }
        else if (event->key() == Qt::Key_Down)
        {
            if(player1Tank->pos().y() + playerRect.height() < height())
            {

                nextMovementPos.setX(player1Tank->pos().x());
                nextMovementPos.setY(player1Tank->pos().y()+8);//todo: magnum

                player1Tank->setPos(nextMovementPos);
                //TODO: move to separate func
                if(!player1Tank->collidingItems().isEmpty())
                {
                    foreach(QGraphicsItem *obj, player1Tank->collidingItems())
                    {
                        GameObject * gameObj = static_cast<GameObject*>(obj);
                        qDebug() << "collides: " << gameObj->getObjectType();
                        switch(gameObj->getObjectType())
                        {
                        case Level::TILE_BRICK:
                        case Level::TANK:
                        case Level::TILE_STEEL:
                        case Level::GOBLET:
                            player1Tank->setPos(initialPos);
                            break;
                        default:
                            qDebug() << "collision with uknown object";
                        }
                    }
                }
                else
                {
                    player1Tank->setOrientation(PlayerTank::down);
                }
            }
        }
        else if(event->key() == Qt::Key_Space)
        {
            Bullet * bullet = new Bullet(player1Tank->getOrientation());
            //bullets.append(static_cast<GameObject*>(bullet));
            bullets.append(bullet);

            addItem(bullet);

            //positioning bullet
            switch(player1Tank->getOrientation())
            {
            case (PlayerTank::up):
                bullet->setPos(player1Tank->x() + playerRect.width()/2 - bullet->boundingRect().width()/2,player1Tank->y() - bullet->boundingRect().height() );
                break;
            case (PlayerTank::right):
                bullet->setPos(player1Tank->x() + playerRect.width()+3,player1Tank->y() + playerRect.height()/2-bullet->boundingRect().height()/2);
                break;
            case (PlayerTank::down):
                bullet->setPos(player1Tank->x() + playerRect.width()/2 - bullet->boundingRect().width()/2,player1Tank->y() + playerRect.height());
                break;
            case (PlayerTank::left):
                bullet->setPos(player1Tank->x()- bullet->boundingRect().width()-3, player1Tank->y() + playerRect.height()/2 - bullet->boundingRect().height()/2);
                break;
            default:
                qDebug() << "uknkown player1Tank orientation";
            }
            if (!bulletTimer->isActive())
            {
                bulletTimer->start();
            }
        }
    }
}

GameObject* Game::createObject(uint type)
{
    GameObject * newObject = nullptr;
    switch(type)
    {
    case Level::TILE_BRICK:
    {
        Brick * brick = new Brick();
        newObject = static_cast<GameObject*>(brick);
    }
        break;
    case Level::TILE_STEEL:
    {
        SteelBlock * steelBlock = new SteelBlock();
        newObject = static_cast<GameObject*>(steelBlock);
    }
        break;
    case Level::GOBLET:
    {
        Goblet * goblet = new Goblet();
        newObject = static_cast<GameObject*>(goblet);
    }
        break;
    case Level::PLAYER1_SPAWN:
    {
        //Tank * tank = new Tank(type);
        PlayerTank * tank = new PlayerTank(type);
        newObject = static_cast<GameObject*>(tank);
        player1Tank = static_cast<PlayerTank*>(newObject);
    }
        break;
    case Level::TANK:
    {   Tank * tank = new Tank(type);
        newObject = static_cast<GameObject*>(tank);
    }
        break;
    case Level::BULLET:
    {
        Bullet * bullet = new Bullet();
        newObject = static_cast<GameObject*>(bullet);
    }
        break;
    default:
        qDebug() << "request of unknown object creation";
    }
    if(newObject != nullptr)
    {
        objects.append(newObject);
        addItem(newObject);
    }
    return newObject;
}

void Game::onBulletTimeout()
{
    if (bullets.isEmpty())
    {
        bulletTimer->stop();
        return;
    }
    else
    {
        auto it = bullets.begin();
        while(it != bullets.end())
        {
            Bullet *bullet = (*it);
            if (bullet->collidingItems().isEmpty() &&//doesn't collides with anything
                sceneRect().contains(bullet->pos()))//out of scene
            {
                switch (bullet->getDirection())
                {
                case Tank::up:
                    bullet->setY(bullet->y()-8);
                    break;
                case Tank::right:
                    bullet->setX(bullet->x()+8);
                    break;
                case Tank::down:
                    bullet->setY(bullet->y()+8);
                    break;
                case Tank::left:
                    bullet->setX(bullet->x()-8);
                    break;
                default:
                    qDebug() << "dfq";
                }
            }
            else
            {
                qDebug() << "number of colliding items beside bullet: " << bullet->collidingItems().length();
                {
                    //while(bullet->collidingItems().length())
                    for (int i = 0; i < bullet->collidingItems().length(); i++)
                    {
                        qDebug() << "number of colliding items: " << bullet->collidingItems().length();
                        GameObject * collidingItem = static_cast<GameObject*>(bullet->collidingItems()[0]);
                        switch(collidingItem->getObjectType())
                        {
                            case Level::TILE_STEEL:
                            {
                                //launch animation and delete bullet only
                                break;
                            }
                            break;
                            case Level::TILE_BRICK:
                            {
                                objects.removeOne(collidingItem);
                                delete collidingItem;//guess this need to be moved to separate function for animation&health calculations
                                i--;
                                break;
                            }
                            case Level::BULLET:
                            {
                                  qDebug() << "bad";
                            }
                            case Level::TANK:
                            {
                                //launch explosion animation and delete both of items
                                //objects.removeOne(collidingItem);
                                qDebug() << objects.removeOne(collidingItem);
                                //tanks.removeOne(collidingItem);
                                qDebug() << tanks.removeOne(collidingItem);
                                delete collidingItem;//guess this need to be moved to separate function for animation&health calculations
                                i--;//wtf, change this to while
                            }
                            break;
                        }
                    }
                }
                delete bullet;
                it = bullets.erase(it);
                continue;
            }
            it++;
        }
    }
}

void Game::onSpawnTimeout()
{
    if (tanksSpawned < 20)
    {
        //check if ! intersects with existing tank
        GameObject * enemyTank = createObject(Level::TANK);
        auto spawnPointLoc = currentLevel.getEnemySpawnPoints()[qrand()%currentLevel.getEnemySpawnPoints().length()];
        enemyTank->setPos((((spawnPointLoc)%currentLevel.getWidth())*16 + enemyTank->boundingRect().width()), (((spawnPointLoc)/currentLevel.getWidth())*16) + enemyTank->boundingRect().height());
        if (enemyTank->collidingItems().length())
        {
            objects.removeOne(enemyTank);
            delete enemyTank;
        }
        else
        {
            //objects.append(enemyTank);
            tanks.append(static_cast<Tank*>(enemyTank));
            tanksSpawned++;
            if(!AIControlTimer->isActive())
            {
                AIControlTimer->start();
            }
        }
    }
    else
    {
        spawnTimer->stop();
    }
}

void Game::onAIControlTimeout()
{
    qDebug() << "aiTimer, tanks.length(): " << tanks.length();
    if (tanks.length())
    {
        for (int i = 0; i < tanks.length(); i++)
        {
            qDebug() << qrand()%5;
            switch(qrand()%5)
            {
            case 0:
            {
                qDebug() << "move up";
                break;
            }
            case 1:
            {
                qDebug() << "move right";
                break;
            }
            case 2:
            {
                qDebug() << "move down";
                break;
            }
            case 3:
            {
                qDebug() << "move left";
                break;
            }
            case 4:
            {
                qDebug() << "fire";
                break;
            }
                default:
            {
                qDebug() << "dfq";
            }
            }
            //tanks[0]
        }
    }
}
