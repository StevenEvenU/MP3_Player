#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "songcontrol.h"
#include <QtWidgets>

class MainWindow : public QMainWindow {
public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private:
  SongControl *songControlWidget = nullptr;
  void playNewSongRequest(const QString data);
};

#endif // MAINWINDOW_H
