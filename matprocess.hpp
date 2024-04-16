#ifndef MATPROCESS_HPP
#define MATPROCESS_HPP

#include <QObject>
#include <QPointF>
#include <QVector2D>
#include <QVector3D>
#include <QtMath>

#include "plane.hpp"
#include "settings.hpp"
#include "sphere.hpp"
#include "vecfunctions.hpp"

class MatProcess {
  // Q_OBJECT

 private:
  static QRgb pointsColor[windowXsize][windowYsize];
  static Vec3 cameraBasicVectors[windowXsize][windowYsize];
  static Vec3 cameraCurrentVectors[windowXsize][windowYsize];

 public:
  static QRgb getPoint(int _x, int _y) { return pointsColor[_x][_y]; }

  static void setPoint(int _x, int _y, QRgb _color) {
	pointsColor[_x][_y] = _color;
  }

 public:
  MatProcess();
  void calculateFrame();
  void testing();
  void randomize();
  void setCameraShift(Vec3 _shift);
  void setCameraDirection(Vec2 _dir);

  void updateFocusPlate();
  void updateRotatedPlate();

 private:
  Sphere sphere;
  Plane plane;
  QTime time;
  int t = 0;
  int allt = 0;
  Vec3 cameraPosition = Vec3(0, 0, 1);
  Vec2 cameraDirection = Vec2(0, 0);  // в радианах угол наклона камеры
  Vec3 cameraShift = Vec3(0);
  Vec2 cameraDirectionShift = Vec2(0, 0);
  double cameraSpeed = 0.05;

  double focus = PI / 4;  // in radians from 0 to PI/2
};

#endif  // MATPROCESS_HPP
