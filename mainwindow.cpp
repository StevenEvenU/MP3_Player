#include "mainwindow.h"
#include "songcontrol.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  QWidget *mainWidget = new QWidget(this);
  setCentralWidget(mainWidget);

  QVBoxLayout *mainLayout = new QVBoxLayout(mainWidget);
  QListWidget *songListWidget = new QListWidget(mainWidget);
  SongControl *songControlWidget = new SongControl(mainWidget);

  mainLayout->addWidget(songListWidget);
  mainLayout->addWidget(songControlWidget);
}

MainWindow::~MainWindow() {}
