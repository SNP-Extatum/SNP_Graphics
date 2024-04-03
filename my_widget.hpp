#ifndef MY_WIDGET_HPP
#define MY_WIDGET_HPP

#include <QObject>
#include <QWidget>
#include <QPainter>

class My_widget : public QWidget {
Q_OBJECT
 public:
  explicit My_widget(QWidget *parent = nullptr);
  //bool flag_drow;
  QImage image; //тоже плохо потому что в паблике
  void create_image(int _sizeX, int _sizeY);// метод создания изображения

 private:
  bool im_created; // признак создания изображения


 protected:
  void paintEvent (QPaintEvent*)override;

};

#endif // MY_WIDGET_HPP
