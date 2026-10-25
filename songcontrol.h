#ifndef SONGCONTROL_H
#define SONGCONTROL_H

#include <QDebug>
#include <QtMultimedia>
#include <QtWidgets>

class SongControl : public QWidget {
  Q_OBJECT

public:
  SongControl(QWidget *parent);
  ~SongControl();

private:
  QMediaPlayer *musicPlayer = nullptr;
  QPushButton *playPauseButton = nullptr;
  QPushButton *forwardButton = nullptr;
  QPushButton *backwardButton = nullptr;
  QLabel *songTitle = nullptr;
  QLabel *songArtist = nullptr;
  QLabel *songAlbumTitle = nullptr;
  QLabel *songTotalDuration = nullptr;
  QLabel *songCurrentTimestampLabel = nullptr;
  QProgressBar *audioProgressBar = nullptr;
  void createNavigationButtons();
  void createLayouts();
  void createSongInformationLabels();
  void setupSongControlPanel();
  void connectSignals();
private slots:
  void changePlayableState();
  void updateMetaData();
  void updatePosition();
};

#endif // SONGCONTROL_H
