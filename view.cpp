#include "view.hpp"
#include "ui_view.h"

#include <QtWidgets>
#include <algorithm>

View::View(QWidget *parent) : QWidget(parent), ui(new Ui::View) { ui->setupUi(this); }

View::~View() { delete ui; }

void View::paintEvent(QPaintEvent *e) {
  QPainter painter(this);
  painter.fillRect(this->rect(), Qt::black);
  painter.setPen(Qt::white);
  painter.drawText(this->rect(), QString::number(timestamp));
  painter.scale(scale, scale);
  if (bodies.size() > 1) {
    painter.translate((this->width() / 2 - bodies[bodyNum].x() * scale) / scale,
                      (this->height() / 2 - bodies[bodyNum].y() * scale) / scale);
  }
  for (Body &b : bodies) {

      painter.setBrush(b.cl());
      painter.setPen(b.cl());
      painter.drawEllipse(b.c(), std::min(50., std::max(log(100 * b.mm()), 1.0)), std::min(50., std::max(log(100 * b.mm()), 1.0)));
      if (tracks.count(b.i()) == 0 && tail != 0) {
        std::vector<QPointF> nv;
        nv.push_back(b.c());
        tracks[b.i()] = nv;
      } else if (tail != 0) {
        while (tracks[b.i()].size() > tail) {
          tracks[b.i()].erase(tracks[b.i()].begin());
        }
        auto v = tracks[b.i()];
        for (auto it = v.begin(); it != v.end() - 1; ++it) {
          painter.drawLine(*it, *(it + 1));
        }
        painter.drawLine(*(v.end() - 1), b.c());
        tracks[b.i()].push_back(b.c());
      }
    }

  e->accept();
}

void View::setScale(double value) { scale = value; }

void View::setTail(int value) { tail = value; }

void View::setBodyNum(int value) { bodyNum = value; }

void View::getBodies(double t, std::vector<Body> bs) {
  timestamp = t;
  bodies = bs;
  update();
}
