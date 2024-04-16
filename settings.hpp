#ifndef SETTINGS_HPP
#define SETTINGS_HPP
#include <QColor>
#include <QDebug>
#include <QRandomGenerator>
#include <QTime>

#define small

#if defined(small)
#define windowXsize 640
#define windowYsize 360
#elif defined(verysmall)
#define windowXsize 128
#define windowYsize 72
#elif defined(mid)
#define windowXsize 1280
#define windowYsize 720
#endif
#define aspect 1.777777777777778
#define drawingRange 100

#endif  // SETTINGS_HPP
