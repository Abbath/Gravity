#ifndef CORE_HPP
#define CORE_HPP

#include <QObject>
#include <vector>
#include <defs.hpp>

class Core : public QObject
{
    Q_OBJECT
    double step = 0.01;
    double simtime = 1000000;
    int delay = 10;
public:
    bool stop = false;
    explicit Core(QObject *parent = 0);
    void cycle(const std::vector<Body> &init);
    void setStep(double value);

    void setSimtime(double value);

    void setDelay(int value);

signals:
    void sendBodies(double, std::vector<Body>);
public slots:
};

#endif // CORE_HPP
