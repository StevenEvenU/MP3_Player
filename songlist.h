#ifndef SONGLIST_H
#define SONGLIST_H

#include <QDebug>
#include <QtCore>
#include <QtWidgets>

class SongList : public QListView {
  Q_OBJECT
public:
  SongList(QWidget *parent);
  ~SongList();
signals:
  void songRequested(const QString &songFileName);

protected:
  void sendSongNameNotification(QModelIndex indexOfList);
};

#endif // SONGLIST_H
