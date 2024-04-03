#include "windowqgv.hpp"

WindowQGV::WindowQGV() {
  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setFrameStyle(0);
  setSceneRect(0, 0, windowXsize, windowYsize);
  setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed));
  setFixedSize(windowXsize, windowYsize);
  setWindowTitle("TryToGraphics");

  setScene(&mainScene);
  mainScene.setItemIndexMethod(QGraphicsScene::NoIndex);
  initializeScene();
}

void WindowQGV::initializeScene() {
  mainView.setPos(0, 0);
  mainScene.addItem(&mainView);
}

void WindowQGV::keyPressEvent(QKeyEvent* event) {
  switch (event->key()) {
	case Qt::Key_Space:
	  //matProcess.randomize();
	  //matProcess.calculateFrame();
		  matProcess.testing ();
	  mainView.update();
	  qDebug() << "UPDATE!";
	  break;
  }
}
