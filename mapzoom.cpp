#include <QtGui>
#include <QtNetwork>
#include "lightmaps.h"
#include "mapzoom.h"

MapZoom::MapZoom()
    : QMainWindow(0)
{
    map = new LightMaps(this);
    setCentralWidget(map);
    map->setFocus();

    QAction *osloAction = new QAction(tr("&Oslo"), this);
    QAction *berlinAction = new QAction(tr("&Berlin"), this);
    QAction *jakartaAction = new QAction(tr("&Jakarta"), this);
    QAction *nightModeAction = new QAction(tr("Night Mode"), this);
    nightModeAction->setCheckable(true);
    nightModeAction->setChecked(false);
    QAction *osmAction = new QAction(tr("About OpenStreetMap"), this);
    connect(osloAction, SIGNAL(triggered()), SLOT(chooseOslo()));
    connect(berlinAction, SIGNAL(triggered()), SLOT(chooseBerlin()));
    connect(jakartaAction, SIGNAL(triggered()), SLOT(chooseJakarta()));
    connect(nightModeAction, SIGNAL(triggered()), map, SLOT(toggleNightMode()));
    connect(osmAction, SIGNAL(triggered()), SLOT(aboutOsm()));

#if defined(Q_OS_SYMBIAN) || defined(Q_OS_WINCE_WM)
    menuBar()->addAction(osloAction);
    menuBar()->addAction(berlinAction);
    menuBar()->addAction(jakartaAction);
    menuBar()->addAction(nightModeAction);
    menuBar()->addAction(osmAction);
#else
    QMenu *menu = menuBar()->addMenu(tr("&Options"));
    menu->addAction(osloAction);
    menu->addAction(berlinAction);
    menu->addAction(jakartaAction);
    menu->addSeparator();
    menu->addAction(nightModeAction);
    menu->addAction(osmAction);
#endif

    QNetworkConfigurationManager manager;
    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired) {
        // Get saved network configuration
        QSettings settings(QSettings::UserScope, QLatin1String("Trolltech"));
        settings.beginGroup(QLatin1String("QtNetwork"));
        const QString id =
            settings.value(QLatin1String("DefaultNetworkConfiguration")).toString();
        settings.endGroup();

        // If the saved network configuration is not currently discovered use the system
        // default
        QNetworkConfiguration config = manager.configurationFromIdentifier(id);
        if ((config.state() & QNetworkConfiguration::Discovered) !=
            QNetworkConfiguration::Discovered) {
            config = manager.defaultConfiguration();
        }

        networkSession = new QNetworkSession(config, this);
        connect(networkSession, SIGNAL(opened()), this, SLOT(sessionOpened()));

        networkSession->open();
    } else {
        networkSession = 0;
    }

    setWindowTitle(tr("Light Maps"));
}

void MapZoom::sessionOpened()
{
    // Save the used configuration
    QNetworkConfiguration config = networkSession->configuration();
    QString id;
    if (config.type() == QNetworkConfiguration::UserChoice) {
        id = networkSession->sessionProperty(
                QLatin1String("UserChoiceConfiguration")).toString();
    } else {
        id = config.identifier();
    }

    QSettings settings(QSettings::UserScope, QLatin1String("Trolltech"));
    settings.beginGroup(QLatin1String("QtNetwork"));
    settings.setValue(QLatin1String("DefaultNetworkConfiguration"), id);
    settings.endGroup();
}

void MapZoom::chooseOslo()
{
    map->setCenter(59.9138204, 10.7387413);
}

void MapZoom::chooseBerlin()
{
    map->setCenter(52.52958999943302, 13.383053541183472);
}

void MapZoom::chooseJakarta()
{
    map->setCenter(-6.211544, 106.845172);
}

void MapZoom::aboutOsm()
{
    QDesktopServices::openUrl(QUrl("http://www.openstreetmap.org"));
}
