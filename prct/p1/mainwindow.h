#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <string>
#include <map>
#include "painting.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class GalleryDatabase {
public:
    std::vector<Painting> paintings;
    std::string filename;

    void load();
    void save();
    GalleryDatabase(std::string file);
    GalleryDatabase();

    void addPainting(Painting p);
    bool deletePainting(std::string title);

    std::vector<std::string> getAllArtists();
    std::vector<Painting> getPaintingsInPeriod(int from, int to);
    int countInStorage(QString artist);
    std::map<int, int> getYearCounts(std::string artist);
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    GalleryDatabase gb;

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
};

class NoDurationException : public std::exception {
private:
    std::string message_;
public:
    explicit NoDurationException(const QString& msg) : message_(msg.toStdString()) {}
    const char* what() const noexcept override { return message_.c_str(); }
};

class NoArtistException : public std::exception {
private:
    std::string message_;
public:
    explicit NoArtistException(const QString& msg) : message_(msg.toStdString()) {}
    const char* what() const noexcept override {return message_.c_str();}
};

#endif // MAINWINDOW_H
