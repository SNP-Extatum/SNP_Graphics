#include "plane.hpp"

Plane::Plane() {
  setMainPoint(0, 0, -1);
  setColor(qRgb(62, 117, 59));
}
// w = 1
double Plane::calculatePlane(Vec3 ro, Vec3 rd) {
  return -(VecFunctions::dot(ro, getCurrPoint()) + 1) /
		 VecFunctions::dot(rd, getCurrPoint());
}
