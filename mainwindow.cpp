#include "mainwindow.hpp"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  // создадим изображение для рисования
  ui->widget->create_image(ui->widget->width(), ui->widget->height());
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_action_CreateTesting_triggered() {
  flag_draw = !flag_draw;
  QPainter painter(&ui->widget->image);
  QPen pen;      // карандаш
  QBrush brush;  // кисть
  QColor pen_color, brush_color;
  if (flag_draw) {
	pen_color.setRgb(127, 0, 0, 127);
	pen.setColor(pen_color);
	painter.setPen(pen);
	for (int i = 0; i < 720; ++i) {
	  for (int j = 0; j < 1280; ++j) {
		painter.drawPoint(j, i);
	  }
	}
  } else {
	// стираем все
	ui->widget->image.fill(0);
  }
  ui->widget->update();
  // ui->widget->repaint();
}

void MainWindow::on_pushButton_drowButton_clicked() {
  flag_draw = !flag_draw;
  QPainter painter(&ui->widget->image);
  QPen pen;      // карандаш
  QBrush brush;  // кисть
  QColor pen_color, brush_color;
  if (flag_draw) {
	pen_color.setRgb(127, 0, 0, 127);
	pen.setColor(pen_color);
	painter.drawPoint(10, 10);
	for (int i = 0; i < 450; ++i) {
	  for (int j = 0; j < 900; ++j) {
		painter.drawPoint(j, i);
	  }
	}
	/*
	pen.setStyle(Qt::DashDotLine);
	pen.setWidth(5);
	painter.setPen(pen);
	brush_color.setRgb(75, 0, 130, 70);
	brush.setColor(brush_color);
	brush.setStyle(Qt::SolidPattern);
	painter.setBrush(brush);
	painter.drawEllipse(50, 50, 150, 150);
	painter.drawRect(20, 20, 400, 200);


pen_color.setRgb (127,0,0,27);
pen.setColor (Qt::green);
pen.setStyle (Qt::DashDotLine);
pen.setWidth (5);
painter.setPen (pen);
painter.drawEllipse (50,50,150,150);
painter.drawLine (100,100,300,300);
painter.drawRect (20,20,400,200);

pen.setColor (Qt::blue);
pen.setStyle (Qt::SolidLine);
pen.setWidth (10);
painter.setPen (pen);

pen.setCapStyle (Qt::FlatCap);
painter.setPen (pen);
painter.drawLine (10,10,100,10);
pen.setCapStyle (Qt::SquareCap);
painter.setPen (pen);
painter.drawLine (10,30,100,30);
pen.setCapStyle (Qt::RoundCap);
painter.setPen (pen);
painter.drawLine (10,50,100,50);
*/
	// а еще есть соединение линий на стыках при помощи joinStyle

  } else {
	// стираем все
	ui->widget->image.fill(0);
  }
  ui->widget->repaint();
}

void MainWindow::on_pushButton_polygon_clicked() {
  //  QPainter painter (&ui->widget->image);
  //  QPen pen; // карандаш
  //  QBrush brush; // кисть
  //  QColor pen_color, brush_color;
  //  QPoint* points;
  //  points = new QPoint[5];

  //  points[0].setX (20);
  //  points[0].setY (20);
  //  points[1].setX (200);
  //  points[1].setY (20);
  //  points[2].setX (20);
  //  points[2].setY (200);
  //  points[3].setX (200);
  //  points[3].setY (200);
  //  points[4].setX (20);
  //  points[4].setY (20);
  //  pen.setJoinStyle (Qt::MiterJoin);
  //  painter.setPen (pen);
  //  painter.drawPolygon (points,4);
  //  for (int i = 0; i < 5; ++i) {
  //    points[i].setX (points[i].x () +200);
  //  }
  //  painter.drawPolygon (points,4,Qt::OddEvenFill);
  //  delete points;
  repaint();
}

/*
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																для реализации
   вывода изображения в QT необходимо переопределить зону рисования, например
   QWidget для этого необходимо: 1)создать новый класс с++, наследник от QWidget
   и добавить его в проект 2)на форме разместить базовый элемент QWidget
   3)командой контекстного меню "преобразовать в" вызвать окно преобразования
   4)указать имя созданного класса в качестве базового


																																в QT
   нежелательно задавать координаты вне диапозона от -32К до +32К при рисовании
   изображений с очень большими координатами рекомендуется считать их проекцию
   или точку пересечения с "виртуальной" рамкой, находящейся вне зоны
   отображения виджета разница между прямоугольников - отступ превышающий
   половину максимальной толщины линии

																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																Для
   принудительного вызова события paintEvent необходимо вызвать метод repaint(),
   repaint() вызывает каскадный вызов методов repaint() на всех внутренних
   элементах
*/
