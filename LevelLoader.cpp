#include "LevelLoader.h"

LevelLoader::LevelLoader()
{
    qDebug() << "LevelLoader constructor";
}

Level LevelLoader::loadLevel(int levelNumber)
{
    if(levelNumber == 1)
    {
        mapSettingsFile = ":/config.ini";
    }
    QSettings settings(mapSettingsFile, QSettings::IniFormat);
    int height = settings.value("map_height").toInt();
    int width = settings.value("map_width").toInt();

    QVector<int> map;
    settings.beginReadArray("line");
    for (int i = 0; i < height; i++)
    {
        settings.setArrayIndex(i);
        QString tmpString;
        tmpString = settings.value("map").toString();
        if (tmpString.length() == width)
        {
            for (int j=0; j < width; j++)
            {
                map.append(tmpString[j].digitValue());
            }
        }
        else
        {
            qDebug() << "Error: line #" << i << " doesn't match width.";
        }
    }
    Level newLevel = {height, width, map};
    return newLevel;
}
