#include "mainview.hpp"
#include "matprocess.hpp"


MainView::MainView() {}

QRectF MainView::boundingRect() const {
  return QRectF(0, 0, windowXsize, windowYsize);
}

void MainView::paint(QPainter* painter, const QStyleOptionGraphicsItem* option,
					 QWidget* widget) {
  time.start();
  qDebug() << "red" << qRed(MatProcess::getPoint(150,500));
  qDebug() << "green" << qGreen(MatProcess::getPoint(12,0));
  qDebug() << "blue" << qBlue(MatProcess::getPoint(809,700));
  for (int x = 0; x < windowXsize; ++x) {
	for (int y = 0; y < windowYsize; ++y) {
      image.setPixel(x, y,  MatProcess::getPoint(x, y));
	}
  }
  // pixmap.convertFromImage(image);
  // painter->drawPixmap(0, 0, windowXsize, windowYsize, pixmap);
  painter->drawImage(0, 0, image);

  qDebug() << time.elapsed() << " <- paintingIm";

  // painter->drawImage ()
}
