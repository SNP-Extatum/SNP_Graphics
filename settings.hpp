#ifndef SETTINGS_HPP
#define SETTINGS_HPP
#include <QColor>
#include <QDebug>
#include <QRandomGenerator>
#include <QTime>

#define windowXsize 1280
#define windowYsize 720

struct Colors {
  uint8_t red;
  uint8_t green;
  uint8_t blue;
};

static Colors pointsColor[windowXsize][windowYsize];

#endif  // SETTINGS_HPP
