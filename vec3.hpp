#ifndef VEC3_HPP
#define VEC3_HPP

#include "vec2.hpp"

class Vec3 {
 public:
  float x, y, z;

  Vec3() : x(1), y(1), z(1){};
  Vec3(float _value) : x(_value), y(_value), z(_value){};
  Vec3(float _x, Vec2 const& v) : x(_x), y(v.x), z(v.y){};
  Vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z){};

  void setVec3(float _x, float _y, float _z) {
	x = _x;
	y = _y;
	z = _z;
  };

  Vec3 operator+(Vec3 const& other) {
	return Vec3(x + other.x, y + other.y, z + other.z);
  }
  Vec3 operator+(double const& other) {
	return Vec3(x + other, y + other, z + other);
  }
  Vec3 operator-(Vec3 const& other) {
	return Vec3(x - other.x, y - other.y, z - other.z);
  }
  Vec3 operator-(double const& other) {
	return Vec3(x - other, y - other, z - other);
  }
  Vec3 operator*(Vec3 const& other) {
	return Vec3(x * other.x, y * other.y, z * other.z);
  }
  Vec3 operator*(double const& other) {
	return Vec3(x * other, y * other, z * other);
  }
  Vec3 operator/(Vec3 const& other) {
	return Vec3(x / other.x, y / other.y, z / other.z);
  }
  Vec3 operator/(double const& other) {
	return Vec3(x / other, y / other, z / other);
  }
  Vec3 operator-() { return Vec3(-x, -y, -z); }

  // Vec3& operator=(Vec3 const& other) {
  // x = other.x;
  // y = other.y;
  // z = other.z;
  // return *this;
  //}

  Vec3& operator+=(Vec3 const& other) {
	x += other.x;
	y += other.y;
	z += other.z;
	return *this;
  }

  Vec3& operator-=(Vec3 const& other) {
	x -= other.x;
	y -= other.y;
	z -= other.z;
	return *this;
  }

  Vec3& operator*=(Vec3 const& other) {
	x *= other.x;
	y *= other.y;
	z *= other.z;
	return *this;
  }

  Vec3& operator/=(Vec3 const& other) {
	x /= other.x;
	y /= other.y;
	z /= other.z;
	return *this;
  }
};

#endif  // VEC3_HPP
