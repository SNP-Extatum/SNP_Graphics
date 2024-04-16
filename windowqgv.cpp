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
	case Qt::Key_W:
	  matProcess.setCameraShift(Vec3(1, 0, 0));
	  mainView.update();
	  break;
	case Qt::Key_S:
	  matProcess.setCameraShift(Vec3(-1, 0, 0));
	  mainView.update();
	  break;
	case Qt::Key_A:
	  matProcess.setCameraShift(Vec3(0, 1, 0));
	  mainView.update();
	  break;
	case Qt::Key_D:
	  matProcess.setCameraShift(Vec3(0, -1, 0));
	  mainView.update();
	  break;
	case Qt::Key_Shift:
	  matProcess.setCameraShift(Vec3(0, 0, 1));
	  mainView.update();
	  break;
	case Qt::Key_Control:
	  matProcess.setCameraShift(Vec3(0, 0, -1));
	  mainView.update();
	  break;
	case Qt::Key_Right:
	  matProcess.setCameraDirection(Vec2(-0.01, 0));
	  mainView.update();
	  break;
	case Qt::Key_Left:
	  matProcess.setCameraDirection(Vec2(0.01, 0));
	  mainView.update();
	  break;
	case Qt::Key_Up:
	  matProcess.setCameraDirection(Vec2(0, 0.01));
	  mainView.update();
	  break;
	case Qt::Key_Down:
	  matProcess.setCameraDirection(Vec2(0, -0.01));
	  mainView.update();
	  break;
  }
}

void WindowQGV::keyReleaseEvent(QKeyEvent* event) {
  switch (event->key()) {
	case Qt::Key_W:
	  matProcess.setCameraShift(Vec3(-1, 0, 0));
	  mainView.update();
	  break;
	case Qt::Key_S:
	  matProcess.setCameraShift(Vec3(1, 0, 0));
	  mainView.update();
	  break;
	case Qt::Key_A:
	  matProcess.setCameraShift(Vec3(0, -1, 0));
	  mainView.update();
	  break;
	case Qt::Key_D:
	  matProcess.setCameraShift(Vec3(0, 1, 0));
	  mainView.update();
	  break;
	case Qt::Key_Shift:
	  matProcess.setCameraShift(Vec3(0, 0, -1));
	  mainView.update();
	  break;
	case Qt::Key_Control:
	  matProcess.setCameraShift(Vec3(0, 0, 1));
	  mainView.update();
	  break;
	case Qt::Key_Right:
	  matProcess.setCameraDirection(Vec2(0.01, 0));
	  mainView.update();
	  break;
	case Qt::Key_Left:
	  matProcess.setCameraDirection(Vec2(-0.01, 0));
	  mainView.update();
	  break;
	case Qt::Key_Up:
	  matProcess.setCameraDirection(Vec2(0, -0.01));
	  mainView.update();
	  break;
	case Qt::Key_Down:
	  matProcess.setCameraDirection(Vec2(0, 0.01));
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
