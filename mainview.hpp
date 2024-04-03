#ifndef MAINVIEW_HPP
#define MAINVIEW_HPP

#include <QGraphicsItem>
#include <QImage>
#include <QObject>
#include <QPainter>
#include <QPixmap>
#include <QSize>

#include "settings.hpp"

class MainView : public QGraphicsItem {
  // Q_OBJECT
 public:
  MainView();
  QImage image = QImage(windowXsize, windowYsize, QImage::Format_RGB32);
  QPixmap pixmap;
  QRgb colorValue;
  QTime time;
  QRectF boundingRect() const override;
  void paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
			 QWidget* widget) override;
};

#endif  // MAINVIEW_HPP
