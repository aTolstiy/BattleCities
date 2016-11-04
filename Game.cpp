#include "Game.h"

Game::Game()
{
    //for now it's gonna be a constant, but later this may be changed to level selection
    currentLevel = loadLevel(Game::LEVEL_1);
    drawLevel(currentLevel);
    initViewScene();

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
        if (tempLevel[i]!=Level::TILE_EMPTY
                ||tempLevel[i]!=Level::ENEMY_SPAWN)
        {
            GameObject * item = createObject(tempLevel[i]);

            if(item!=nullptr)
            {
                scene.addItem(item);
                item->setPos(((i%level.getWidth()))*16, i/level.getWidth()*16);
                //objects.append(item);
            }
        }
    }
}

void Game::initViewScene(void)
{
    view.setScene(&scene);
    view.setFixedSize(640, 480);
    scene.setBackgroundBrush(Qt::black);
    scene.setSceneRect(0,0, 640, 480);
    view.fitInView(scene.sceneRect(), Qt::KeepAspectRatio);
    view.show();
    view.setFocusPolicy(Qt::StrongFocus);//remove me
    scene.setFocus();

}
void Game::keyPressEvent(QKeyEvent * event)
{
    //todo:make distinction between the menu and actual game
    if (player1Tank != nullptr)
    {
        QRectF playerRect = player1Tank->boundingRect();
        if (event->key() == Qt::Key_Left)
        {
            if(playerRect.x() > 0)
            {
                player1Tank->setPos(playerRect.x()-10, playerRect.y());
            }
        }
        else if (event->key() == Qt::Key_Right)
        {
            if (playerRect.right() < scene.width())
            {
                player1Tank->setPos(playerRect.x()+10, playerRect.y());
            }
        }
        else if (event->key() == Qt::Key_Up)
        {
            if(playerRect.top() > 0)
            {
                player1Tank->setPos(playerRect.x(), playerRect.y()-10);
            }
        }
        else if (event->key() == Qt::Key_Down)
        {
            if(playerRect.bottom() < scene.height())
            {
                player1Tank->setPos(playerRect.x(), playerRect.y()+10);
            }
        }
        else if(event->key() == Qt::Key_Space)
        {
            //pew
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
        Tank * tank = new Tank(type);
        newObject = static_cast<GameObject*>(tank);
        player1Tank = newObject;
    }
        break;
    default:
        qDebug() << "request of unknown object creation";
    }
    if(newObject !=nullptr)
    {
        objects.append(newObject);
    }
    return newObject;
}
