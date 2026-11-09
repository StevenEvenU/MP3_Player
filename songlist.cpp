#include "songlist.h"

SongList::SongList(QWidget *parent) : QListView(parent) {
  this->setEditTriggers(QAbstractItemView::NoEditTriggers);
  applicationDir.cd("Song_List");
  songListDirName = applicationDir.absolutePath();
  QStringList songList =
      applicationDir.entryList(QStringList() << "*.mp3" << "*.mp4");
  QStandardItemModel *songListModel = new QStandardItemModel(this);
  QMediaPlayer *tempPlayer = new QMediaPlayer(this);
  // Filtering files for only .mp3 and .mp4
  int tempCounterToBeDeleted = 0;
  for (const QString &songFileName : songList) {
    QString songFilePath = songListDirName + '/' + songFileName;
    TagLib::FileRef songTagInfo =
        TagLib::FileRef(songFilePath.toStdString().c_str());
    TagLib::String songTitleTag = songTagInfo.tag() == nullptr
                                      ? songFileName.toStdString()
                                      : songTagInfo.tag()->title();
    QStandardItem *songItem =
        new QStandardItem(QString::fromStdString(songTitleTag.to8Bit()));
    songItem->setData(songFilePath, Qt::UserRole);
    songListModel->appendRow(songItem);
    tempCounterToBeDeleted += 1;
    if (tempCounterToBeDeleted == 21)
      break;
  };
  this->setModel(songListModel);
  connect(this, &SongList::doubleClicked, this,
          &SongList::sendSongNameNotification);
};

void SongList::sendSongNameNotification(QModelIndex indexOfList) {
  if (indexOfList.isValid()) {
    qDebug() << indexOfList.data(Qt::UserRole).toString();
    emit songRequested(
                       indexOfList.data(Qt::UserRole).toString());
  }
};

SongList::~SongList() {};
