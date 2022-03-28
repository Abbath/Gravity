#include "core.hpp"

void Core::setStep(double value)
{
    step = value;
}

void Core::setSimtime(double value)
{
    simtime = value;
}

void Core::setDelay(int value)
{
    delay = value;
}

Core::Core(QObject *parent) : QObject(parent)
{

}

void Core::cycle(const std::vector<Body>& init)
{
    std::vector<Body> v = init;
//    double step = 0.01;
//    double simtime = 1000000;
    for(int i = 0; i < v.size(); ++i){
        double sumx = 0, sumy = 0;
        for(int j = 0; j < v.size(); ++j){
            if(i != j){
                auto r=v[i].r3(v[j]);
                sumx += -1*v[j].mm()*(v[i].x()-v[j].x())*r;
                sumy += -1*v[j].mm()*(v[i].y()-v[j].y())*r;
            }
        }
        v[i].rax() = sumx;
        v[i].ray() = sumy;
    }
    for(Body& x : v){
        x.rvx() += x.ax()*0.5*step;
        x.rvy() += x.ay()*0.5*step;
    }
    for(double t = 0;t < simtime; t+= step){
        for(Body& b : v){
            b.rx() += (b.vx()*step)*sqrt(1-(b.vx()/b.getSol())*(b.vx()/b.getSol()));
            b.ry() += (b.vy()*step)*sqrt(1-(b.vy()/b.getSol())*(b.vy()/b.getSol()));
        }
        for(int i = 0; i < v.size(); ++i){
            double sumx = 0, sumy = 0;
            for(int j = 0; j < v.size(); ++j){
                if(i != j){
                    auto r=v[i].r3(v[j]);
                    sumx += -2.975e-3*v[j].mm()*(v[i].x()-v[j].x())*r;
                    sumy += -2.975e-3*v[j].mm()*(v[i].y()-v[j].y())*r;
                }
            }
            v[i].rax() = sumx;
            v[i].ray() = sumy;
        }
        for(Body& b : v){
            b.rvx() += b.ax()*step;
            b.rvy() += b.ay()*step;
        }

        emit sendBodies(t, v);
        QThread::currentThread()->usleep(delay);
        if(stop){
            stop = false;
            break;
        }
    }
}
