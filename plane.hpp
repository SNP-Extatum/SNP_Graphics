#ifndef PLANE_HPP
#define PLANE_HPP

#include "sceneobject.hpp"

class Plane : public SceneObject {
 public:
  Plane();
  double calculatePlane(Vec3 ro, Vec3 rd);
  Vec3 normal = VecFunctions::norm(Vec3(0, 0, 1));
  void updatePosition(Vec3 _shift, double _sinY, double _cosY, double _sinZ,
					  double _cosZ) override;
};

#endif  // PLANE_HPP
