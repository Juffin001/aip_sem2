// area.h
#ifndef AREA_H
#define AREA_H

#include <QWidget>
#include "figura.h"

class Area : public QWidget {
    Q_OBJECT
public:
    Area(QWidget *parent = nullptr);
    ~Area();
protected:
    void paintEvent(QPaintEvent *) override;
    void timerEvent(QTimerEvent *) override;
    void showEvent(QShowEvent *) override;
    void hideEvent(QHideEvent *) override;
private:
    Figura *letters[3];
    double angles[3];
    double amplitudes[3];
    int myTimer;
    int elapsedTime;
};

#endif
