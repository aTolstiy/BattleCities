#ifndef LEVEL_H
#define LEVEL_H

#include <QObject>
#include <QVector>

class Level : public QObject
{
    Q_OBJECT
public:
    explicit Level(QObject *parent = 0);
    void setMapHeight(int);
    void setMapWidth(int);
    void setMapElement(int,int,int);
private:
    int mapHeight, mapWidth;
    QVector<QVector<int>> map;

signals:

public slots:
};

#endif // LEVEL_H
