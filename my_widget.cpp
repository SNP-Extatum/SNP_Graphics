#include "my_widget.hpp"

My_widget::My_widget(QWidget *parent) : QWidget(parent) {
  im_created = false;
}

void My_widget::create_image(int _sizeX, int _sizeY) {
  if (!im_created){
    image = QImage(_sizeX, _sizeY, QImage::Format_ARGB32_Premultiplied);
    im_created = true;
  }else{
    // sami
  }
}

void My_widget::paintEvent(QPaintEvent* ) {
  if (im_created){
    QPainter painter (this);
    painter.drawImage (0,0,image); // выводим готовое изображение
  }
}
