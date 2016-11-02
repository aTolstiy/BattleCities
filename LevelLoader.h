#ifndef LEVELLOADER_H
#define LEVELLOADER_H

#include <QFile>
#include <QDebug>
#include <QSettings>

#include <Level.h>

class LevelLoader
{
public:
    explicit LevelLoader();
    Level loadLevel(int);
private:
    QString mapSettingsFile;

signals:

public slots:
};

#endif // LEVELLOADER_H
