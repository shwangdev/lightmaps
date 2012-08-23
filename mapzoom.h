#ifndef MAPZOOM_H
#define MAPZOOM_H

#include <QMainWindow>

class QNetworkSession;
class LightMaps;

class MapZoom : public QMainWindow
{
    Q_OBJECT

public:
    MapZoom();

private slots:
    void sessionOpened();
    void chooseOslo();
    void chooseBerlin();
    void chooseJakarta();
    void aboutOsm();

private:
    LightMaps *map;
    QNetworkSession *networkSession;
};

#endif
