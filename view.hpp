#ifndef VIEW_HPP
#define VIEW_HPP

#include <QWidget>
#include <vector>
#include <map>
#include <defs.hpp>

namespace Ui {
class View;
}

class View : public QWidget
{
    Q_OBJECT

public:
    explicit View(QWidget *parent = 0);
    ~View();
    void paintEvent(QPaintEvent *e);

    void setScale(double value);

    void setTail(int value);

    void setBodyNum(int value);

private:
    double scale = 1.0;
    int tail = 0;
    double timestamp = 0;
    int bodyNum = 0;
    Ui::View *ui;
    std::vector<Body> bodies;
    std::map<int, std::vector<QPointF>> tracks;
public slots:
    void getBodies(double t, std::vector<Body> bs);
};

#endif // VIEW_HPP
