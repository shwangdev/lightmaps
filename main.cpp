#include <QApplication>
#include "mapzoom.h"

int main(int argc, char **argv)
{
#if defined(Q_WS_X11)
     QApplication::setGraphicsSystem("raster");
#endif

     QApplication app(argc, argv);
     app.setApplicationName("LightMaps");

     MapZoom w;
 #if defined(Q_OS_SYMBIAN) || defined(Q_OS_WINCE_WM)
     w.showMaximized();
 #else
     w.resize(600, 450);
     w.show();
 #endif

     return app.exec();
}
