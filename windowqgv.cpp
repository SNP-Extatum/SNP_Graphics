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

  connect(&paintTimer, &QTimer::timeout, this, &WindowQGV::drawScene);
}

void WindowQGV::initializeScene() {
  mainView.setPos(0, 0);
  mainScene.addItem(&mainView);
}

void WindowQGV::keyPressEvent(QKeyEvent* event) {
  switch (event->key()) {
	case Qt::Key_Space:
	  if (paintTimer.isActive()) {
		paintTimer.stop();
	  } else {
		paintTimer.start(20);
	  }
	  break;
	case Qt::Key_R:
	  matProcess.randomize();
	  mainView.update();
	  break;
  }
}
void WindowQGV::drawScene() {
  // FPStime.start();
  matProcess.calculateFrame();
  mainView.update();
  // qDebug() << FPStime.elapsed() << " <- FPS";
}
