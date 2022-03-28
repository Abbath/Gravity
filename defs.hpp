#ifndef DEFS_HPP
#define DEFS_HPP

#include  <QtCore>
#include <QtGui>

class Body{
    static constexpr double sol = 25380;
    int id;
    QString name;
    QColor color;
    double mass;
    double move_mass;
    QPointF coords;
    QPointF velocity;
    QPointF acceleration;
public:
    Body() { id = rand();}
    Body (QString n, QColor cl, double m, QPointF c, QPointF v, QPointF a) : name(n), color(cl), mass(m), coords(c), velocity(v), acceleration(a) {id = rand();}
    ~Body(){}
    QString getName() const { return name; }
    double m() const {return mass;}
    int i() const {return id;}
    QPointF c() const {return coords;}
    QColor cl() const {return color;}
    QPointF v() const {return velocity;}
    QPointF a() const {return acceleration;}
    double r(const Body& b) const {return sqrt((coords.x()-b.x())*(coords.x()-b.x())+(coords.y()-b.y())*(coords.y()-b.y()));}
    double r3(const Body& b) const {auto rb = r(b); return 1/(rb*rb*rb);}
    double x() const {return coords.x();}
    double y() const {return coords.y();}
    double vx() const {return velocity.x();}
    double vy() const {return velocity.y();}
    double ax() const {return acceleration.x();}
    double ay() const {return acceleration.y();}
    double mm() const {
        double vel = velocity.x()*velocity.x()+velocity.y()*velocity.y();
        return mass/sqrt(1-vel/(sol*sol));
    }
    double& rm() {return mass;}
    double& rx() {return coords.rx();}
    double& ry() {return coords.ry();}
    double& rvx() {return velocity.rx();}
    double& rvy() {return velocity.ry();}
    double& rax() {return acceleration.rx();}
    double& ray() {return acceleration.ry();}
    static double getSol() { return sol; }
};
#endif // DEFS_HPP
