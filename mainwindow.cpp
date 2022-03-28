#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <QtConcurrent/QtConcurrent>
#include <ctime>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  ui->settings->hide();
  srand(time(NULL));
  c = new Core;
  qRegisterMetaType<std::vector<Body>>("std::vector<Body>");
  connect(c, SIGNAL(sendBodies(double, std::vector<Body>)), ui->view, SLOT(getBodies(double, std::vector<Body>)), Qt::QueuedConnection);
}

MainWindow::~MainWindow() {
  c->stop = true;
  delete ui;
}

void MainWindow::on_start_clicked() {
  std::vector<Body> bs;
//          Body b1("Sun",Qt::white, 150000,{0,0},{0,0},{0,0});
//          Body b2("Earth",Qt::green, 1000,{0,150},{35,0},{0,0});
//          Body b3("Jupiter",Qt::yellow, 5000, {0, 800}, {15,0}, {0,0});
//          Body b4("Moon",Qt::blue, 10, {0, 154}, {19,0}, {0,0});
//          Body b5("Uranus",Qt::magenta, 3000, {0, 1200}, {12,0}, {0, 0});
//          Body b6("Ganimede",Qt::gray, 50, {0, 830}, {5, 0}, {0,0});
//          Body b7("Neptune", Qt::cyan, 2000, {0,1488}, {5, 0}, {0,0});
//          Body b8("Comet", Qt::white, 1, {0,5000}, {0.1,0}, {0,0});
//          bs.push_back(b1);
//          bs.push_back(b2);
//          bs.push_back(b3);
//          bs.push_back(b4);
//          bs.push_back(b5);
//          bs.push_back(b6);
//          bs.push_back(b7);
//          bs.push_back(b8);

//  Body b1("Sun", Qt::white, 332837, {0, 0}, {0.2, 0}, {0, 0});
//  Body b2("Earth", Qt::green, 332837, {0, 150}, {2.568, 0}, {0, 0});
//  Body b3("Jupiter", Qt::darkYellow, 332837, {0, 780}, {1.13, 0}, {0, 0});

          Body b1("Sun",Qt::white, 332837,{0,0},{0,0},{0,0});
          Body b2("Earth",Qt::green, 1,{0,150},{2.568,0},{0,0});
          Body b3("Jupiter",Qt::darkYellow, 317.83, {0, 780}, {1.13,0}, {0,0});
          Body b4("Saturn",Qt::yellow, 95.159, {0, 1437}, {0.837,0}, {0,0});
          Body b5("Uranus",Qt::cyan, 14.535, {0, 2884}, {0.588,0}, {0, 0});
          Body b6("Neptune",Qt::blue, 17.147, {0, 4515}, {0.469, 0}, {0,0});
          Body b7("Venus", Qt::magenta, 0.815, {0,108}, {-3.025, 0}, {0,0});
          Body b8("Mars", Qt::red, 0.107, {0,228}, {2.084,0}, {0,0});
          Body b9("Mercury", Qt::darkGray, 0.0562, {0,70}, {4.1,0}, {0,0});
          Body b10("Moon", Qt::gray, 0.0203, {0,150.3}, {2.56+8.83e-2,0}, {0,0});
          Body b11("Ceres", Qt::darkGray, 0.0004, {0, 414}, {1.545,0}, {0,0});
          Body b12("Titan", Qt::darkGray, 0.0660, {0, 1437+1.22}, {0.837+0.48,0}, {0,0});
          Body b13("Ganymede", Qt::darkGray, 0.0704, {0, 780+1.07}, {1.13+0.94,0}, {0,0});
          Body b14("Comet",Qt::darkRed,  3.68e-11, {0, 88}, {4.7,0}, {0,0});
  bs.push_back(b1);
  bs.push_back(b2);
  bs.push_back(b3);
          bs.push_back(b4);
          bs.push_back(b5);
          bs.push_back(b6);
          bs.push_back(b7);
          bs.push_back(b8);
          bs.push_back(b9);
          bs.push_back(b10);
          bs.push_back(b11);
          bs.push_back(b12);
          bs.push_back(b13);
          bs.push_back(b14);

  ui->center->setMaximum(bs.size() - 1);
  QtConcurrent::run(c, &Core::cycle, bs);
}

void MainWindow::on_stop_clicked() { c->stop = true; }

void MainWindow::on_scale_valueChanged(double arg1) {
  ui->view->setScale(arg1);
  ui->view->update();
}

void MainWindow::on_tail_valueChanged(int arg1) {
  ui->view->setTail(arg1);
  ui->view->update();
}

void MainWindow::on_center_valueChanged(int arg1) {
  ui->view->setBodyNum(arg1);
  ui->view->update();
}

void MainWindow::on_step_valueChanged(double arg1) { c->setStep(arg1); }

void MainWindow::on_time_valueChanged(int arg1) { c->setSimtime(arg1); }

void MainWindow::on_actionSettings_triggered(bool checked) { ui->settings->setVisible(checked); }

void MainWindow::on_speed_valueChanged(int arg1) { c->setDelay(arg1); }
