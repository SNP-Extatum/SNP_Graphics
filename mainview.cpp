#include "mainview.hpp"

MainView::MainView() {}

QRectF MainView::boundingRect() const {
  return QRectF(0, 0, windowXsize, windowYsize);
}

void MainView::paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
					 QWidget* widget) {
  time.start();
  qDebug() << "red" << pointsColor[150][500].red;
  qDebug() << "green" << pointsColor[12][0].green;
  qDebug() << "blue" << pointsColor[809][700].blue;
  for (int x = 0; x < windowXsize; ++x) {
	for (int y = 0; y < windowYsize; ++y) {
	  colorValue = qRgb(pointsColor[x][y].red, pointsColor[x][y].green,
						pointsColor[x][y].blue);
	  // colorValue = qRgb (100, 0, 0);
	  image.setPixel(x, y, colorValue);
	}
  }
  // pixmap.convertFromImage(image);
  // painter->drawPixmap(0, 0, windowXsize, windowYsize, pixmap);
  painter->drawImage(0, 0, image);

  qDebug() << time.elapsed() << " <- paintingIm";

  // painter->drawImage ()
}
