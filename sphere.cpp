#include "sphere.hpp"

Sphere::Sphere() {}

void Sphere::setRadius(double _radius) { radius = _radius; }

double Sphere::getRadius() { return radius; }

Vec2 Sphere::calculateSphere(Vec3 ro, Vec3 rd) {
  float b = VecFunctions::dot(ro, rd);
  float c = VecFunctions::dot(ro, ro) - radius * radius;
  float h = b * b - c;
  if (h < 0.0) return Vec2(-1.0);
  h = sqrt(h);
  return Vec2(-b - h, -b + h);
}

void Sphere::updatePosition(Vec3 _shift, double _sinY, double _cosY,
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
