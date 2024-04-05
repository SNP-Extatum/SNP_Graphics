#ifndef MATPROCESS_HPP
#define MATPROCESS_HPP

#include <QObject>
#include <QPointF>
#include <QVector2D>
#include <QVector3D>
#include <QtMath>

#include "settings.hpp"

class MatProcess {
  // Q_OBJECT

private:
    static QRgb pointsColor[windowXsize][windowYsize];
public:
    static QRgb getPoint(int _x, int _y){
        return pointsColor[_x][_y];
    }

    static void setPoint(int _x, int _y, QRgb _color){
        pointsColor[_x][_y] = _color;
    }

public:
  MatProcess();
  QVector3D* vectorMas;
  QTime time;
  void randomize();
  QVector3D cameraPoint;
  QVector3D cameraDirect;
  QVector2D viewAngle;
  void calculateFrame();
  void calculateDirectionVectors();
  void testing();

};

#endif  // MATPROCESS_HPP
