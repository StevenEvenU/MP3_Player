#include "mainwindow.h"
#include "songcontrol.h"
#include "songlist.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  QWidget *mainWidget = new QWidget(this);
  setCentralWidget(mainWidget);

  QVBoxLayout *mainLayout = new QVBoxLayout(mainWidget);
  SongList *songListWidget = new SongList(mainWidget);
  songControlWidget = new SongControl(mainWidget);
  connect(songListWidget, &SongList::songRequested, this,
          &MainWindow::playNewSongRequest);

  mainLayout->addWidget(songListWidget);
  mainLayout->addWidget(songControlWidget);
}

void MainWindow::playNewSongRequest(const QString &data) {
  songControlWidget->setPlayingSong(data);
}

MainWindow::~MainWindow() {}
