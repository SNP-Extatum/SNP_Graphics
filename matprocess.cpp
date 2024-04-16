#include "matprocess.hpp"

QRgb MatProcess::pointsColor[windowXsize][windowYsize];
Vec3 MatProcess::cameraBasicVectors[windowXsize][windowYsize];
Vec3 MatProcess::cameraCurrentVectors[windowXsize][windowYsize];

MatProcess::MatProcess() {
  time.start();

  updateFocusPlate();

  qDebug() << time.elapsed() << " <- MatProcess()";

  time.start();
  updateRotatedPlate();
  qDebug() << time.elapsed() << " <- MatProcess()";

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

void MatProcess::setCameraShift(Vec3 _shift) {
  cameraShift = cameraShift + _shift;
}

void MatProcess::setCameraDirection(Vec2 _dir) {
  cameraDirectionShift = cameraDirectionShift + _dir;
  updateRotatedPlate();
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
	  cameraBasicVectors[x][y] =
		  VecFunctions::norm(currentPoint - cameraPosition);
	}
  }
}

void MatProcess::updateRotatedPlate() {
  for (int x = 0; x < windowXsize; x++) {
	for (int y = 0; y < windowYsize; y++) {
	  cameraCurrentVectors[x][y] =
		  VecFunctions::rotateZ(cameraBasicVectors[x][y], cameraDirection.x);
	  cameraCurrentVectors[x][y] =
		  VecFunctions::rotateY(cameraCurrentVectors[x][y], cameraDirection.y);
	}
  }
}

void MatProcess::calculateFrame() {
  // time.start();
  // sphere.setMainPoint(t / 10.0, 0, 1);
  cameraPosition.setVec3(cameraPosition.x + cameraShift.x * cameraSpeed,
						 cameraPosition.y + cameraShift.y * cameraSpeed,
						 cameraPosition.z + cameraShift.z * cameraSpeed);
  cameraDirection.setVec2(cameraDirection.x + cameraDirectionShift.x,
						  cameraDirection.y + cameraDirectionShift.y);

  Vec2 crossed = Vec2(-1);
  for (int y = 0; y < windowYsize; y++) {
	for (int x = 0; x < windowXsize; x++) {
	  crossed = sphere.calculateSphere(cameraPosition - sphere.getMainPoint(),
									   cameraCurrentVectors[x][y],
									   sphere.getRadius());
	  // qDebug() << crossed.x;
	  // qDebug() << crossed.y;
	  if (crossed.x > 0)
		MatProcess::setPoint(x, y, sphere.getColor());
	  else {
		crossed =
			plane.calculatePlane(cameraPosition, cameraCurrentVectors[x][y],
								 plane.getMainPoint(), 1);
		if (crossed.x > 0)
		  MatProcess::setPoint(x, y, plane.getColor());
		else
		  MatProcess::setPoint(x, y, qRgb(135, 206, 235));
	  }
	}
  }

  // qDebug() << ++t;
  //  allt += time.elapsed();
  //  qDebug() << 1000 / time.elapsed() << " <- FPS-calculating";
  //  qDebug() << 1000 / (allt / t) << " <- FPS-mid-calculating";
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
