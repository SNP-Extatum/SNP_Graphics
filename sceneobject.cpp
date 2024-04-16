#include "sceneobject.hpp"

SceneObject::SceneObject() {}

void SceneObject::setMainPoint(double _x, double _y, double _z) {
  mainPoint.setVec3(_x, _y, _z);
}

Vec3 SceneObject::getMainPoint() { return mainPoint; }

void SceneObject::setAngles(double _anX, double _anY, double _anZ) {
  angles.setVec3(_anX, _anY, _anZ);
}

void SceneObject::setAngleX(double _anX) { angles.x = _anX; }

void SceneObject::setAngleY(double _anY) { angles.y = _anY; }

void SceneObject::setAngleZ(double _anZ) { angles.z = _anZ; }

void SceneObject::setColor(QRgb _color) { color = _color; }

QRgb SceneObject::getColor() { return color; }
