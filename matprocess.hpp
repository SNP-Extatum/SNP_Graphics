#ifndef MATPROCESS_HPP
#define MATPROCESS_HPP

#include <QList>
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
  static Vec3 cameraVectors[windowXsize][windowYsize];

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
  void moveCamera();
  void setCameraSpeedPos(Vec2 _speedX, Vec2 _speedY, Vec2 _speedZ);
  void setCameraSpeedDir(Vec2 _vRotateY, Vec2 _vRotateZ);
  void updateFocusPlate();

  void setCameraMoveForward(bool isGo) { isMoveForward = isGo; };
  void setCameraMoveBack(bool isGo) { isMoveBack = isGo; };
  void setCameraMoveRight(bool isGo) { isMoveRight = isGo; };
  void setCameraMoveLeft(bool isGo) { isMoveLeft = isGo; };
  void setCameraMoveUp(bool isGo) { isMoveUp = isGo; };
  void setCameraMoveDown(bool isGo) { isMoveDown = isGo; };
  void setCameraMoveAroundYto(bool isGo) { isMoveAroundYto = isGo; };
  void setCameraMoveAroundYfrom(bool isGo) { isMoveAroundYfrom = isGo; };
  void setCameraMoveAroundZto(bool isGo) { isMoveAroundZto = isGo; };
  void setCameraMoveAroundZfrom(bool isGo) { isMoveAroundZfrom = isGo; };

 private:
  QList<Sphere> spheresList;
  QList<Plane> planesList;

  QTime time;
  int t = 0;
  int allt = 0;
  Vec3 shiftPosition = Vec3(0);
  Vec2 shiftDirection = Vec2(0);
  Vec3 cameraPosition = Vec3(0, 0, 1);
  Vec2 cameraDirection = Vec2(0, 0);  // в радианах угол наклона камеры
  Vec3 cameraShift = Vec3(1);
  double cameraSpeed = 0.1;
  bool isMoveForward = false;
  bool isMoveBack = false;
  bool isMoveRight = false;
  bool isMoveLeft = false;
  bool isMoveUp = false;
  bool isMoveDown = false;
  bool isMoveAroundYto = false;
  bool isMoveAroundYfrom = false;
  bool isMoveAroundZto = false;
  bool isMoveAroundZfrom = false;

  double focus = PI / 4;  // in radians from 0 to PI/2
};

#endif  // MATPROCESS_HPP
