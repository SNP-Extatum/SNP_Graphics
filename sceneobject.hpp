#ifndef SCENEOBJECT_HPP
#define SCENEOBJECT_HPP

#include <QRgb>

#include "vecfunctions.hpp"

class SceneObject {
 public:
  SceneObject();
  void setMainPoint(double _x, double _y, double _z);
  Vec3 getMainPoint();
  void setAngles(double _anX, double _anY, double _anZ);
  void setAngleX(double _anX);
  void setAngleY(double _anY);
  void setAngleZ(double _anZ);
  void setColor(QRgb _color);
  QRgb getColor();

 private:
  Vec3 mainPoint = Vec3(5, 0, 1);
  Vec3 angles = Vec3(0);
  QRgb color = qRgb(150, 150, 150);
};

#endif  // SCENEOBJECT_HPP
