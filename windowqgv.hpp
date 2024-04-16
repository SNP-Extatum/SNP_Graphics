#ifndef WINDOWQGV_HPP
#define WINDOWQGV_HPP

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QObject>
#include <QTimer>

#include "mainview.hpp"
#include "matprocess.hpp"
#include "settings.hpp"

class WindowQGV : public QGraphicsView {
  Q_OBJECT
 public:
  WindowQGV();
  QTime FPStime;
  QTimer paintTimer;
  void initializeScene();
  void keyPressEvent(QKeyEvent* event);
  void keyReleaseEvent(QKeyEvent* event);

  MainView mainView;
  QGraphicsScene mainScene;
  MatProcess matProcess;
  void drawScene();
  void calcScene();
};

#endif  // WINDOWQGV_HPP
