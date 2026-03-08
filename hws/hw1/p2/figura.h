#ifndef FIGURA_H
#define FIGURA_H

#include <QPainter>

class Figura
{
protected:
    int x,y,halflen,dx,dy;
public:
    Figura(int X, int Y, int Halflen): x(X), y(Y), halflen(Halflen) {
    };
    void move(float Alpha, QPainter *Painter) {
        dx = static_cast<int>(halflen * cos(Alpha));
        dy = static_cast<int>(halflen * sin(Alpha));
        draw(Painter);
    }
    virtual void draw(QPainter *Painter)=0;
    virtual ~Figura() {};
};

class I : public Figura {
protected:

public:
    I(int cx, int cy, int h) : Figura(cx, cy, h) {};
    void draw(QPainter *p) override {
        p->drawLine(x, y, x + 2*dx, y + 2*dy);
        p->drawLine(x + 2*dx - 0.5*dy, y + 2*dy + 0.5*dx, x + 2*dx + 0.5*dy, y + 2*dy - 0.5*dx);
        p->drawLine(x - 0.5*dy, y + 0.5*dx, x + 0.5*dy, y - 0.5*dx);
    }
};

class T : public Figura {
public:
    T(int cx, int cy, int h) : Figura(cx, cy, h) {};
    void draw(QPainter *p) override {
        p->drawLine(x, y, x + 2*dx, y + 2*dy);
        p->drawLine(x + 2*dx - dy, y + 2*dy + dx, x + 2*dx + dy, y + 2*dy - dx);
        p->drawLine(x + 2*dx - dy, y + 2*dy + dx, x + 2*dx - dy - 0.5*dx, y + 2*dy + dx - 0.5*dy);
        p->drawLine(x + 2*dx + dy, y + 2*dy - dx, x + 2*dx + dy - 0.5*dx, y + 2*dy - dx - 0.5*dy);
    }
};

class H : public Figura {
public:
    H(int cx, int cy, int h) : Figura(cx, cy, h) {};
    void draw(QPainter *p) override {
        p->drawLine(x, y, x + dx, y + dy);
        p->drawLine(x, y, x - dx, y - dy);
        p->drawLine(x, y, x + dy, y - dx);
        p->drawLine(x + dy, y - dx, x + dx + dy, y + dy - dx);
        p->drawLine(x + dy, y - dx, x - dx + dy, y - dy - dx);
    }
};

#endif
