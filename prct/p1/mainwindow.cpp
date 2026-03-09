#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <fstream>
#include <sstream>
#include <unordered_set>
#include "showwindow.h"
#include <QMessageBox>
#include "deletewindow.h"
#include "addwindow.h"
#include "yearchartdialog.h"

GalleryDatabase::GalleryDatabase(std::string file) : filename(file), paintings() {}
GalleryDatabase::GalleryDatabase() : filename(""), paintings() {}

void GalleryDatabase::load() {
    paintings.clear();
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string title, artist, yearStr, location;

        std::getline(ss, title, ',');
        std::getline(ss, artist, ',');
        std::getline(ss, yearStr, ',');
        std::getline(ss, location, ',');

        int year = std::stoi(yearStr);
        paintings.push_back({title, artist, year, location});
    }
}

std::vector<std::string> GalleryDatabase::getAllArtists() {
    std::vector<std::string> res;
    std::unordered_set<std::string> s;
    for (int i = 0; i < paintings.size(); ++i) {
        if (!s.count(paintings[i].artist)) {
            s.insert(paintings[i].artist);
            res.push_back(paintings[i].artist);
        }
    }
    return res;
}

std::vector<Painting> GalleryDatabase::getPaintingsInPeriod(int from, int to) {
    std::vector<Painting> ans;
    for (int i = 0; i < paintings.size(); ++i) {
        if (from <= paintings[i].year && paintings[i].year <= to) {
            ans.push_back(paintings[i]);
        }
    }
    return ans;
}

int GalleryDatabase::countInStorage(QString artist) {
    int ans = 0;
    for (int i = 0; i < paintings.size(); ++i) {
        if (paintings[i].artist == artist && paintings[i].location == "Запасник") {
            ans++;
        }
    }
    return ans;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), gb("gallery.csv")
{
    ui->setupUi(this);
    resize(800, 200);
    gb.load();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_3_clicked() //showAll
{
    ShowWindow w;
    w.showVector(gb.getAllArtists());
    w.exec();
}


void MainWindow::on_pushButton_4_clicked() // duration
{
    try {
        if (ui->lineEdit->text() == "" || ui->lineEdit_2->text() == "") throw NoDurationException("Не введен период времени");
        bool ok1, ok2;
        int from = ui->lineEdit->text().toInt(&ok1);
        int to = ui->lineEdit_2->text().toInt(&ok2);
        if (!ok1 || !ok2) throw NoDurationException("некорректно введен период времени");
        ShowWindow w;
        w.showPainting(gb.getPaintingsInPeriod(from, to));
        w.exec();
    } catch (NoDurationException& e) {
        QMessageBox::critical(this, "Ошибка", e.what());
    }
}


void MainWindow::on_pushButton_5_clicked() //cnt storage
{
    try {
        if (ui->lineEdit_3->text() == "") throw NoArtistException("Не введен художник");
        ShowWindow w;
        QString first_str = "Количество работ ";
        first_str += ui->lineEdit_3->text();
        first_str += ": ";
        w.showVector({first_str.toStdString(), std::to_string(gb.countInStorage(ui->lineEdit_3->text()))});
        w.exec();
    } catch (NoArtistException& e) {
        QMessageBox::critical(this, "Ошибка", e.what());
    }
}


void MainWindow::on_pushButton_2_clicked() //delete
{
    DeleteWindow w;
    GalleryDatabase* ptr = &gb;
    w.setGallery(ptr);
    w.exec();
}


void MainWindow::on_pushButton_clicked() //add
{
    AddWindow w;
    w.setgallery(&gb);
    w.exec();
}

std::map<int, int> GalleryDatabase::getYearCounts(std::string artist) {
    std::map<int, int> counts;
    for (const auto& p : paintings) {
        if (p.artist == artist) {
            counts[p.year]++;
        }
    }
    return counts;
}

void MainWindow::on_pushButton_6_clicked()
{
    QString artist = ui->lineEdit_4->text().trimmed();
    std::map<int, int> yearData = gb.getYearCounts(artist.toStdString());
    YearChartDialog *dialog = new YearChartDialog(yearData, artist, this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->show();
}

