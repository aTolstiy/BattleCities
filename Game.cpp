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
    for (int i=0; i<level.getMap().length();i++)
    {
        GameObject *item = new GameObject(level.getMap()[i]);

        scene.addItem(item);
        item->setPos(((i%level.getWidth()))*32, i/level.getWidth()*32);
        objects.append(item);
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
    scene.setFocus();
}
