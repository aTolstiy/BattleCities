#ifndef LEVELLOADER_H
#define LEVELLOADER_H

#include <QObject>
#include <QFile>
#include <QDebug>
#include <QSettings>

#include <Level.h>

class LevelLoader : public QObject
{
    Q_OBJECT
public:
    explicit LevelLoader(QObject *parent = 0);
    void loadLevel(int);
private:
    QString mapSettingsFile;

signals:

public slots:
};

#endif // LEVELLOADER_H
