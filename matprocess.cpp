#include "matprocess.hpp"

QRgb MatProcess::pointsColor[windowXsize][windowYsize];

MatProcess::MatProcess() { time.start(); }

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

float MatProcess::clamp(float _value, float _min, float _max) {
  return fmax(fmin(_value, _max), _min);
}

void MatProcess::calculateFrame() {
  // time.start();
  for (int y = 0; y < windowYsize; y++) {
	for (int x = 0; x < windowXsize; x++) {
	  // vec2 uv = vec2(x, y) / vec2(windowXsize, windowYsize) * 2.0f - 1.0f;
	  QVector2D uv =
		  QVector2D(x, y) / QVector2D(windowXsize, windowYsize) * 2.0 -
		  QVector2D(1, 1);
	  uv.setX(uv.x() * aspect + (t % 2));
	  if (uv.x() * uv.x() + uv.y() * uv.y() < 0.5) {
		setPoint(x, y, qRgb(100, 100, 100));
	  } else {
		setPoint(x, y, qRgb(0, 0, 0));
	  }
	}
  }
  ++t;
  // allt += time.elapsed();
  // qDebug() << 1000 / time.elapsed() << " <- FPS-calculating";
  // qDebug() << 1000 / (allt / t) << " <- FPS-mid-calculating";
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
