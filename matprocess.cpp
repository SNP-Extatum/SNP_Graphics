#include "matprocess.hpp"

MatProcess::MatProcess() {
  time.start();
  // pointMas = new Point[windowXsize * windowYsize];
  // vectorMas = new QVector3D[windowXsize * windowYsize];
  randomize();
  cameraPoint.setX(0);
  cameraPoint.setY(0);
  cameraPoint.setZ(5);
  cameraDirect.setX(1);
  cameraDirect.setY(0);
  cameraDirect.setZ(0);
  viewAngle.setX(qDegreesToRadians(45.0));
  viewAngle.setY(qDegreesToRadians(45.0));
  qDebug() << time.elapsed() << " <- Creating MatProcess";
}

void MatProcess::randomize() {
  qDebug() << " <- randomize";
  time.start();
  for (int x = 0; x < windowXsize; x++) {
	for (int y = 0; y < windowYsize; y++) {
        QRgb clr = qRgb(QRandomGenerator::global()->generate() % 255,
                        QRandomGenerator::global()->generate() % 255,
                        QRandomGenerator::global()->generate() % 255);
        MatProcess::setPoint(x, y, clr);
	}
  }
  qDebug() << time.elapsed() << " <- randomize";
}

void MatProcess::calculateFrame() {
  time.start();

  for (int y = 0; y < windowYsize; y++) {
	for (int x = 0; x < windowXsize; x++) {
	  float X = (float)x / windowXsize * 2.0f - 1.0f;
	  float Y = (float)y / windowYsize * 2.0f - 1.0f;
	  if (X * X + Y * Y < 0.5) {
        setPoint(x, y, qRgb(100, 100, 100));
	  }
	}
  }

  qDebug() << time.elapsed() << " <- calculateFrame()";
}

void MatProcess::calculateDirectionVectors() {}

void MatProcess::testing() {
  qDebug() << "0 ms <- v testing() v";
  time.start();

  for (int y = 0; y < windowYsize; y++) {
	for (int x = 0; x < windowXsize; x++) {
        setPoint(x, y, qRgb(255, 255, 255));
	}
  }
  qDebug() << "red" << qRed(getPoint(150, 500));
  qDebug() << "green" << qGreen(getPoint(12, 0));
  qDebug() << "red" << qBlue(getPoint(809, 700));

  qDebug() << time.elapsed() << "ms <- ^ testing() ^";
};
