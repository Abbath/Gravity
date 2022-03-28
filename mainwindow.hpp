#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include "core.hpp"
#include "view.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_start_clicked();

    void on_stop_clicked();

    void on_scale_valueChanged(double arg1);

    void on_tail_valueChanged(int arg1);

    void on_center_valueChanged(int arg1);

    void on_step_valueChanged(double arg1);

    void on_time_valueChanged(int arg1);

    void on_actionSettings_triggered(bool checked);

    void on_speed_valueChanged(int arg1);

private:
    Core *c;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_HPP
