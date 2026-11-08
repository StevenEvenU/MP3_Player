#include "songlist.h"

SongList::SongList(QWidget *parent) : QListView(parent) {
  this->setEditTriggers(QAbstractItemView::NoEditTriggers);
  applicationDir.cd("Song_List");
  songListDirName = applicationDir.absolutePath();
  QStringListModel *songList = new QStringListModel(this);
  // Filtering files for only .mp3 and .mp4
  songList->setStringList(
      applicationDir.entryList(QStringList() << "*.mp3" << "*.mp4"));
  this->setModel(songList);
  connect(this, &SongList::doubleClicked, this,
          &SongList::sendSongNameNotification);
};

void SongList::sendSongNameNotification(QModelIndex indexOfList) {
  if (indexOfList.isValid()) {
    emit songRequested(songListDirName + '/' +
                       indexOfList.data(Qt::DisplayRole).toString());
  }
};

SongList::~SongList() {};
