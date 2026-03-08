// area.cpp
#include "area.h"
#include <QTimerEvent>
#include <math.h>

Area::Area(QWidget *parent) : QWidget(parent), elapsedTime(0) {
    setFixedSize(500, 300);

    letters[0] = new I(100, 200, 40);
    letters[1] = new T(250, 200, 40);
    letters[2] = new H(400, 200, 40);

    amplitudes[0] = 0.1;
    amplitudes[1] = 0.3;
    amplitudes[2] = 0.5;

    for (int i = 0; i < 3; ++i)
        angles[i] = 0.0;
}

Area::~Area() {
    for (int i = 0; i < 3; ++i)
        delete letters[i];
}

void Area::showEvent(QShowEvent *) {
    myTimer = startTimer(50);
}

void Area::hideEvent(QHideEvent *) {
    killTimer(myTimer);
}

void Area::timerEvent(QTimerEvent *event) {
    if (event->timerId() == myTimer) {
        elapsedTime += 50;
        for (int i = 0; i < 3; ++i) {
            angles[i] += amplitudes[i] * 1;
        }
        update();
    } else {
        QWidget::timerEvent(event);
    }
}

void Area::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    painter.setPen(Qt::black);

    for (int i = 0; i < 3; ++i) {
        letters[i]->move(angles[i], &painter);
    }
}
