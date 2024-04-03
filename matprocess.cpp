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
	  pointsColor[x][y].red = QRandomGenerator::global()->generate() % 255;
	  pointsColor[x][y].green = QRandomGenerator::global()->generate() % 255;
	  pointsColor[x][y].blue = QRandomGenerator::global()->generate() % 255;
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
		pointsColor[x][y].red = 100;
		pointsColor[x][y].green = 100;
		pointsColor[x][y].blue = 100;
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
	  pointsColor[x][y].red = 255;
	  pointsColor[x][y].green = 255;
	  pointsColor[x][y].blue = 255;
	}
  }
  qDebug() << "red" << pointsColor[150][500].red;
  qDebug() << "green" << pointsColor[12][0].green;
  qDebug() << "blue" << pointsColor[809][700].blue;

  qDebug() << time.elapsed() << "ms <- ^ testing() ^";
};
