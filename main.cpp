#include <QApplication>
#include <windowqgv.hpp>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  WindowQGV mainwindow;
  mainwindow.show();
  return a.exec();
}
