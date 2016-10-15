#include "LevelLoader.h"

LevelLoader::LevelLoader(QObject *parent) : QObject(parent)
{
    qDebug() << "LevelLoader constructor";
}

void LevelLoader::loadLevel(int levelNumber)
{
    if(levelNumber == 1)
    {
        mapSettingsFile = "config.ini";
    }
    QSettings settings(mapSettingsFile, QSettings::IniFormat);
    int height = settings.value("map_height").toInt();
    int width = settings.value("map_width").toInt();

    QVector<QVector<int>> map;
    settings.beginReadArray("line");
    for(int i = 0; i < height; i++)
    {
        QVector<int> tmp;
        map.push_back(tmp);
        settings.setArrayIndex(i-1);
        for (int j=0; j < width; j++)
        {
            map[i].append(settings.value("map").toString()[j].digitValue());
         //   qDebug() << "i: " << i << ", j: " << j << ", val= " <<settings.value("map").toString()[j];
        }
    }

    qDebug() << settings.allKeys();
}
