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
		paintTimer.start(10);
	  }
	  break;
	case Qt::Key_R:
	  matProcess.randomize();
	  break;
	case Qt::Key_W:
	  matProcess.setCameraMoveForward(true);
	  break;
	case Qt::Key_S:
	  matProcess.setCameraMoveBack(true);
	  break;
	case Qt::Key_A:
	  matProcess.setCameraMoveLeft(true);
	  break;
	case Qt::Key_D:
	  matProcess.setCameraMoveRight(true);
	  break;
	case Qt::Key_Shift:
	  matProcess.setCameraMoveDown(true);
	  break;
	case Qt::Key_Control:
	  matProcess.setCameraMoveUp(true);
	  break;
	case Qt::Key_Right:
	  matProcess.setCameraMoveAroundZto(true);
	  break;
	case Qt::Key_Left:
	  matProcess.setCameraMoveAroundZfrom(true);
	  break;
	case Qt::Key_Up:
	  matProcess.setCameraMoveAroundYto(true);
	  break;
	case Qt::Key_Down:
	  matProcess.setCameraMoveAroundYfrom(true);
	  break;
  }

  // matProcess.moveCamera();
  // mainView.update();
}

void WindowQGV::keyReleaseEvent(QKeyEvent* event) {
  switch (event->key()) {
	case Qt::Key_W:
	  matProcess.setCameraMoveForward(false);
	  break;
	case Qt::Key_S:
	  matProcess.setCameraMoveBack(false);
	  break;
	case Qt::Key_A:
	  matProcess.setCameraMoveLeft(false);
	  break;
	case Qt::Key_D:
	  matProcess.setCameraMoveRight(false);
	  break;
	case Qt::Key_Shift:
	  matProcess.setCameraMoveDown(false);
	  break;
	case Qt::Key_Control:
	  matProcess.setCameraMoveUp(false);
	  break;
	case Qt::Key_Right:
	  matProcess.setCameraMoveAroundZto(false);
	  break;
	case Qt::Key_Left:
	  matProcess.setCameraMoveAroundZfrom(false);
	  break;
	case Qt::Key_Up:
	  matProcess.setCameraMoveAroundYto(false);
	  break;
	case Qt::Key_Down:
	  matProcess.setCameraMoveAroundYfrom(false);

	  break;
  }
  // matProcess.moveCamera();
  // mainView.update();
}

void WindowQGV::drawScene() {
  // FPStime.start();
  matProcess.moveCamera();

  matProcess.calculateFrame();
  mainView.update();
  // qDebug() << FPStime.elapsed() << " <- FPS";
}
