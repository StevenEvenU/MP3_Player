#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "songcontrol.h"
#include <QtWidgets>

class MainWindow : public QMainWindow {
public:
  MainWindow(QWidget *parent = 0);
  ~MainWindow();

private:
  SongControl *songControlWidget;
  void playNewSongRequest(const QString &data);
};

#endif // MAINWINDOW_H
