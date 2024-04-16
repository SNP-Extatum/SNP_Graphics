#ifndef VEC2_HPP
#define VEC2_HPP

class Vec2 {
 public:
  float x, y;

  Vec2(float value) : x(value), y(value) {}
  Vec2(float _x, float _y) : x(_x), y(_y) {}

  void setVec2(float _x, float _y) {
	x = _x;
	y = _y;
  };

  Vec2 operator+(Vec2 const& other) { return Vec2(x + other.x, y + other.y); }
  Vec2 operator-(Vec2 const& other) { return Vec2(x - other.x, y - other.y); }
  Vec2 operator*(Vec2 const& other) { return Vec2(x * other.x, y * other.y); }
  Vec2 operator/(Vec2 const& other) { return Vec2(x / other.x, y / other.y); }
};

#endif  // VEC2_HPP
