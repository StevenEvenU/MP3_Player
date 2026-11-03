#include "songlist.h"

SongList::SongList(QWidget *parent) : QListView(parent) {
  this->setEditTriggers(QAbstractItemView::NoEditTriggers);
  QDir applicationDir = QDir::currentPath();
  applicationDir.cd("Song_List");
  QStringListModel *songList = new QStringListModel(this);
  songList->setStringList(applicationDir.entryList(QStringList() << "*.mp3"));
  this->setModel(songList);
  connect(this, &SongList::doubleClicked, this,
          &SongList::sendSongNameNotification);
};

void SongList::sendSongNameNotification(QModelIndex indexOfList) {
  if (indexOfList.isValid()) {
    emit songRequested(indexOfList.data(Qt::DisplayRole).toString());
  }
};

SongList::~SongList() {};
