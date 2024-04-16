#include "plane.hpp"

Plane::Plane() {
  setMainPoint(0, 0, -1);
  setColor(qRgb(62, 117, 59));
}

double Plane::calculatePlane(Vec3 ro, Vec3 rd, Vec3 p, float w) {
  return -(VecFunctions::dot(ro, p) + w) / VecFunctions::dot(rd, p);
}
