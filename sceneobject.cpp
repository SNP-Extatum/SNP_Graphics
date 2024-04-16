#include "sceneobject.hpp"

SceneObject::SceneObject() {}

void SceneObject::setMainPoint(double _x, double _y, double _z) {
  mainPoint.setVec3(_x, _y, _z);
}

Vec3 SceneObject::getCurrPoint() { return currPoint; }

void SceneObject::setAngles(double _anX, double _anY, double _anZ) {
  angles.setVec3(_anX, _anY, _anZ);
}

void SceneObject::setAngleX(double _anX) { angles.x = _anX; }

void SceneObject::setAngleY(double _anY) { angles.y = _anY; }

void SceneObject::setAngleZ(double _anZ) { angles.z = _anZ; }

void SceneObject::setColor(QRgb _color) { color = _color; }

QRgb SceneObject::getColor() { return color; }

void SceneObject::updatePosition(Vec3 _shift, double _sinY, double _cosY,
								 double _sinZ, double _cosZ) {
  currPoint = mainPoint - _shift;
  // around Y
  Vec3 savePoint = currPoint;
  currPoint.x = savePoint.x * _cosY - savePoint.z * _sinY;
  currPoint.z = savePoint.x * _sinY + savePoint.z * _cosY;
  // around Z
  savePoint = currPoint;
  currPoint.x = savePoint.x * _cosZ - savePoint.y * _sinZ;
  currPoint.y = savePoint.x * _sinZ + savePoint.y * _cosZ;
}
