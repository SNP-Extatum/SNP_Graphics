#include "sphere.hpp"

Sphere::Sphere() {}

void Sphere::setRadius(double _radius) { radius = _radius; }

double Sphere::getRadius() { return radius; }

Vec2 Sphere::calculateSphere(Vec3 ro, Vec3 rd, float r) {
  float b = VecFunctions::dot(ro, rd);
  float c = VecFunctions::dot(ro, ro) - r * r;
  float h = b * b - c;
  if (h < 0.0) return Vec2(-1.0);
  h = sqrt(h);
  return Vec2(-b - h, -b + h);
}
