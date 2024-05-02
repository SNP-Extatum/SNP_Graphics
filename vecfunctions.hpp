#ifndef VecFUNCTIONS_HPP
#define VecFUNCTIONS_HPP

#define PI 3.1415926535

#include <math.h>

#include "vec2.hpp"
#include "vec3.hpp"

class VecFunctions {
 public:
  VecFunctions();

  static float clamp(float value, float min, float max) {
	return fmax(fmin(value, max), min);
  }
  static double sign(double a) { return (0 < a) - (a < 0); }
  static double step(double edge, double x) { return x > edge; }

  static float length(Vec2 const& v) { return sqrt(v.x * v.x + v.y * v.y); }

  static float length(Vec3 const& v) {
	return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
  }
  static Vec3 norm(Vec3 v) { return v / length(v); }
  static float dot(Vec3 const& a, Vec3 const& b) {
	return a.x * b.x + a.y * b.y + a.z * b.z;
  }
  static Vec3 cross(Vec3 const& a, Vec3 const& b) {
	return Vec3(a.y * b.z - a.z * b.y, a.z * b.x - a.x * b.z,
				a.x * b.y - a.y * b.x);
  }
  static Vec3 abs(Vec3 const& v) {
	return Vec3(fabs(v.x), fabs(v.y), fabs(v.z));
  }
  static Vec3 sign(Vec3 const& v) {
	return Vec3(sign(v.x), sign(v.y), sign(v.z));
  }
  static Vec3 step(Vec3 const& edge, Vec3 v) {
	return Vec3(step(edge.x, v.x), step(edge.y, v.y), step(edge.z, v.z));
  }
  static Vec3 reflect(Vec3 rd, Vec3 n) { return rd - n * (2 * dot(n, rd)); }

  static Vec3 rotateX(Vec3 a, double angle) {
	Vec3 b = a;
	b.z = a.z * cos(angle) - a.y * sin(angle);
	b.y = a.z * sin(angle) + a.y * cos(angle);
	return b;
  }

  static Vec3 rotateY(Vec3 a, double angle) {
	Vec3 b = a;
	b.x = a.x * cos(angle) - a.z * sin(angle);
	b.z = a.x * sin(angle) + a.z * cos(angle);
	return b;
  }

  static Vec3 rotateZ(Vec3 a, double angle) {
	Vec3 b = a;
	b.x = a.x * cos(angle) - a.y * sin(angle);
	b.y = a.x * sin(angle) + a.y * cos(angle);
	return b;
  }
};

#endif  // VecFUNCTIONS_HPP
