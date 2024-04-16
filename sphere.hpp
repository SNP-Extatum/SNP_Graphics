#ifndef SPHERE_HPP
#define SPHERE_HPP

// #include "myMath.hpp"
#include "sceneobject.hpp"

class Sphere : public SceneObject {
 public:
  Sphere();
  void setRadius(double _radius);
  double getRadius();
  Vec2 calculateSphere(Vec3 ro, Vec3 rd);

 private:
  double radius = 1;
};

#endif  // SPHERE_HPP
