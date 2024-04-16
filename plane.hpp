#ifndef PLANE_HPP
#define PLANE_HPP

#include "sceneobject.hpp"

class Plane : public SceneObject {
 public:
  Plane();
  double calculatePlane(Vec3 ro, Vec3 rd, Vec3 p, float w);
};

#endif  // PLANE_HPP
