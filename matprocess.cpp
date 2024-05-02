#include "matprocess.hpp"

QRgb MatProcess::pointsColor[windowXsize][windowYsize];
Vec3 MatProcess::cameraVectors[windowXsize][windowYsize];

MatProcess::MatProcess() {
  time.start();

  updateFocusPlate();

  qDebug() << time.elapsed() << " <- MatProcess()";
  Sphere sphere1;
  sphere1.setMainPoint(5, 0, 1);
  sphere1.setColor(qRgb(150, 0, 0));
  spheresList.append(sphere1);
  Sphere sphere2;
  sphere2.setMainPoint(5, 5, 1);
  sphere2.setColor(qRgb(0, 150, 0));
  spheresList.append(sphere2);
  Sphere sphere3;
  sphere3.setMainPoint(5, 0, 5);
  sphere3.setColor(qRgb(200, 200, 200));
  spheresList.append(sphere3);

  // Plane plane;
  // planesList.append(plane);

  // time.start();
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

void MatProcess::moveCamera() {
  cameraDirection +=
	  Vec2(cameraSpeed * ((int)isMoveAroundYto - (int)isMoveAroundYfrom),
		   cameraSpeed * ((int)isMoveAroundZto - (int)isMoveAroundZfrom));
  cameraPosition += Vec3(cameraSpeed * ((int)isMoveForward - (int)isMoveBack),
						 cameraSpeed * ((int)isMoveLeft - (int)isMoveRight),
						 cameraSpeed * ((int)isMoveUp - (int)isMoveDown));
  double sinY = sin(cameraDirection.x);
  double cosY = cos(cameraDirection.x);
  double sinZ = sin(cameraDirection.y);
  double cosZ = cos(cameraDirection.y);
  for (int i = spheresList.size() - 1; i >= 0; i--) {
	spheresList[i].updatePosition(cameraPosition, sinY, cosY, sinZ, cosZ);
  }
  for (int i = planesList.size() - 1; i >= 0; i--) {
	planesList[i].updatePosition(cameraPosition, sinY, cosY, sinZ, cosZ);
  }
}

void MatProcess::updateFocusPlate() {
  Vec2 shift = Vec2(tan(focus) / (windowXsize / 2));
  // shift.y = shift.x / aspect;
  Vec3 startPoint =
	  Vec3(cameraPosition.x + 1, cameraPosition.y + shift.x * (windowXsize / 2),
		   cameraPosition.z + shift.y * (windowYsize / 2));
  Vec3 currentPoint = startPoint;
  for (int x = 0; x < windowXsize; x++) {
	for (int y = 0; y < windowYsize; y++) {
	  currentPoint.y = startPoint.y - shift.x * x;
	  currentPoint.z = startPoint.z - shift.y * y;
	  cameraVectors[x][y] = VecFunctions::norm(currentPoint - cameraPosition);
	}
  }
}

void MatProcess::calculateFrame() {
  // time.start();
  //  sphere.setMainPoint(t / 10.0, 0, 1);

  Vec2 crossed = Vec2(drawingRange);
  Vec2 current = Vec2(-1);
  bool isCrossed = false;
  for (int y = 0; y < windowYsize; y++) {
	for (int x = 0; x < windowXsize; x++) {
	  crossed.setVec2(drawingRange, drawingRange);
	  current = crossed;
	  isCrossed = false;
	  for (int i = spheresList.size() - 1; i >= 0; i--) {
		current = spheresList[i].calculateSphere(-spheresList[i].getCurrPoint(),
												 cameraVectors[x][y]);
		if (current.x > 0 && current.x < crossed.x) {
		  crossed = current;
		  MatProcess::setPoint(x, windowYsize - y, spheresList[i].getColor());
		  isCrossed = true;
		}
	  }
	  for (int i = planesList.size() - 1; i >= 0; i--) {
		current = planesList[i].calculatePlane(0, cameraVectors[x][y]);
		if (current.x > 0 && current.x < crossed.x) {
		  crossed = current;
		  MatProcess::setPoint(x, windowYsize - y, planesList[i].getColor());
		  isCrossed = true;
		}
	  }
	  if (!isCrossed) MatProcess::setPoint(x, windowYsize - y, qRgb(0, 0, 25));
	}
  }

  // qDebug() << ++t;
  //   allt += time.elapsed();
  //   qDebug() << 1000 / time.elapsed() << " <- FPS-calculating";
  //   qDebug() << 1000 / (allt / t) << " <- FPS-mid-calculating";
}

void MatProcess::testing() {
  qDebug() << "0 ms <- v testing() v";
  time.start();

  for (int y = 0; y < windowYsize; y++) {
	for (int x = 0; x < windowXsize; x++) {
	  float X = (float)x / windowXsize * 2.0f - 1.0f;
	  float Y = (float)y / windowYsize * 2.0f - 1.0f;
	  X *= aspect;
	  if (X * X + Y * Y < 1.0) {
		setPoint(x, y, qRgb(100, 100, 100));
	  }
	}
  }

  qDebug() << time.elapsed() << "ms <- ^ testing() ^";
};
