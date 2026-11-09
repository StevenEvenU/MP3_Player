#ifndef SONGLIST_H
#define SONGLIST_H

#include <QDebug>
#include <QMediaMetaData>
#include <QMediaPlayer>
#include <QtCore>
#include <QtWidgets>
#include <iostream>
#include <taglib/fileref.h>
#include <taglib/tag.h>

class SongList : public QListView {
  Q_OBJECT
public:
  SongList(QWidget *parent);
  ~SongList();

private:
  QDir applicationDir = QDir::currentPath();
  QString songListDirName;
signals:
  void songRequested(const QString &songFileName);

protected:
  void sendSongNameNotification(QModelIndex indexOfList);
};

#endif // SONGLIST_H
