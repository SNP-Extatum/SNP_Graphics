#include "plane.hpp"

Plane::Plane() {
  setMainPoint(0, 0, -0.5);
  setColor(qRgb(62, 117, 59));
}
// w = 1
double Plane::calculatePlane(Vec3 ro, Vec3 rd) {
  // double d = VecFunctions::dot(normal, currPoint - ro);
  // double e = VecFunctions::dot(normal, rd);
  // return VecFunctions::length(rd * (d / e));
  // return -(VecFunctions::dot(ro, normal) + mainPoint.z) /
  //	 VecFunctions::dot(rd, normal);
}

void Plane::updatePosition(Vec3 _shift, double _sinY, double _cosY,
						   double _sinZ, double _cosZ) {
  return;
  // currPoint = mainPoint - _shift;
  //// around Y
  // Vec3 savePoint = currPoint;
  // Vec3 saveNormal = normal;
  // currPoint.x = savePoint.x * _cosY - savePoint.z * _sinY;
  // currPoint.z = savePoint.x * _sinY + savePoint.z * _cosY;
  // normal.x = saveNormal.x * _cosY - saveNormal.z * _sinY;
  // normal.z = saveNormal.x * _sinY + saveNormal.z * _cosY;
  //// around Z
  // savePoint = currPoint;
  // saveNormal = normal;
  // currPoint.x = savePoint.x * _cosZ - savePoint.y * _sinZ;
  // currPoint.y = savePoint.x * _sinZ + savePoint.y * _cosZ;
  // normal.x = saveNormal.x * _cosZ - saveNormal.y * _sinZ;
  // normal.y = saveNormal.x * _sinZ + saveNormal.y * _cosZ;
  // normal = VecFunctions::norm(normal);
}
