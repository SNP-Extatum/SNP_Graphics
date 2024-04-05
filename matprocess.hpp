#ifndef MATPROCESS_HPP
#define MATPROCESS_HPP

#include <QObject>
#include <QPointF>
#include <QVector2D>
#include <QVector3D>
#include <QtMath>

#include "settings.hpp"

struct vec2 {
  float x, y;

  vec2(float _value) : x(_value), y(_value) {}
  vec2(float _x, float _y) : x(_x), y(_y) {}

  vec2 operator+(vec2 const& other) { return vec2(x + other.x, y + other.y); }
  vec2 operator-(vec2 const& other) { return vec2(x - other.x, y - other.y); }
  vec2 operator*(vec2 const& other) { return vec2(x * other.x, y * other.y); }
  vec2 operator/(vec2 const& other) { return vec2(x / other.x, y / other.y); }
};

class MatProcess {
  // Q_OBJECT

 private:
  static QRgb pointsColor[windowXsize][windowYsize];

 public:
  static QRgb getPoint(int _x, int _y) { return pointsColor[_x][_y]; }

  static void setPoint(int _x, int _y, QRgb _color) {
	pointsColor[_x][_y] = _color;
  }

 public:
  MatProcess();
  void calculateFrame();
  void testing();
  void randomize();

 private:
  QTime time;
  int t = 0;
  int allt = 0;
  float clamp(float _value, float _min, float _max);
};

#endif  // MATPROCESS_HPP
