#ifndef WINDOWQGV_HPP
#define WINDOWQGV_HPP

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QObject>

#include "mainview.hpp"
#include "matprocess.hpp"
#include "settings.hpp"

class WindowQGV : public QGraphicsView {
  Q_OBJECT
 public:
  WindowQGV();
  void initializeScene();
  void keyPressEvent(QKeyEvent* event);

  MainView mainView;
  QGraphicsScene mainScene;
  MatProcess matProcess;
};

#endif  // WINDOWQGV_HPP
