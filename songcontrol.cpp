#include "songcontrol.h"

SongControl::SongControl(QWidget *parent) : QWidget(parent) {
  setupSongControlPanel();
  createLayouts();
  connectSignals();
}

void SongControl::changePlayableState() {
  switch (musicPlayer->playbackState()) {
  case QMediaPlayer::PlayingState:
    musicPlayer->pause();
    break;
  default:
    musicPlayer->play();
    break;
  }
}

void SongControl::updateMetaData() {
  QMediaMetaData currentlyPlayingMetaData = musicPlayer->metaData();
  songTitle->setText(
      currentlyPlayingMetaData.stringValue(QMediaMetaData::Title));
  songArtist->setText(
      currentlyPlayingMetaData.stringValue(QMediaMetaData::ContributingArtist));
  songAlbumTitle->setText(
      currentlyPlayingMetaData.stringValue(QMediaMetaData::AlbumTitle));
  songTotalDuration->setText(
      QTime::fromMSecsSinceStartOfDay(musicPlayer->duration()).toString());
  audioProgressBar->setMaximum(musicPlayer->duration());
}

void SongControl::updatePosition() {
  QString songCurrentTimestampValue =
      QTime::fromMSecsSinceStartOfDay(musicPlayer->position()).toString();
  songCurrentTimestampLabel->setText(songCurrentTimestampValue);
  audioProgressBar->setValue(musicPlayer->position());
}

void SongControl::createNavigationButtons() {
  playPauseButton = new QPushButton("Play/Pause", this);
  forwardButton = new QPushButton("Forward", this);
  backwardButton = new QPushButton("Backward", this);
}

void SongControl::createLayouts() {
  QHBoxLayout *currentSongPanelLayout = new QHBoxLayout(this);
  QVBoxLayout *songControlLayout = new QVBoxLayout();
  QVBoxLayout *songInformationLayout = new QVBoxLayout();
  currentSongPanelLayout->addLayout(songInformationLayout);
  currentSongPanelLayout->addLayout(songControlLayout);
  QHBoxLayout *songNavigationButtonLayout = new QHBoxLayout();
  QHBoxLayout *songAudioBarLayout = new QHBoxLayout();
  songControlLayout->addLayout(songAudioBarLayout);
  songControlLayout->addLayout(songNavigationButtonLayout);

  songInformationLayout->addWidget(songTitle);
  songInformationLayout->addWidget(songArtist);
  songInformationLayout->addWidget(songAlbumTitle);
  songAudioBarLayout->addWidget(songCurrentTimestampLabel);
  songAudioBarLayout->addWidget(audioProgressBar);
  songAudioBarLayout->addWidget(songTotalDuration);
  songNavigationButtonLayout->addWidget(backwardButton);
  songNavigationButtonLayout->addWidget(playPauseButton);
  songNavigationButtonLayout->addWidget(forwardButton);
}

void SongControl::createSongInformationLabels() {
  songTitle = new QLabel("", this);
  songArtist = new QLabel("", this);
  songAlbumTitle = new QLabel("", this);
  songTotalDuration = new QLabel("", this);
  songCurrentTimestampLabel = new QLabel("00:00:00", this);
}

void SongControl::setupSongControlPanel() {
  createNavigationButtons();
  createSongInformationLabels();
  audioProgressBar = new QProgressBar(this);

  musicPlayer = new QMediaPlayer(this);
  QAudioOutput *audioOutput = new QAudioOutput(musicPlayer);
  QDir applicationDir = QDir::currentPath();
  applicationDir.cd(QString("Song_List"));
  QString songListDirName = applicationDir.dirName();
  QString tempSongChoice = songListDirName.append("/International Love.mp3");
  musicPlayer->setAudioOutput(audioOutput);
  QUrl tempMusicSource = QUrl::fromLocalFile(tempSongChoice);
  musicPlayer->setSource(tempMusicSource);
}

void SongControl::connectSignals() {
  connect(playPauseButton, &QPushButton::clicked, this,
          &SongControl::changePlayableState);
  connect(musicPlayer, &QMediaPlayer::metaDataChanged, this,
          &SongControl::updateMetaData);
  connect(musicPlayer, &QMediaPlayer::positionChanged, this,
          &SongControl::updatePosition);
}

SongControl::~SongControl() {}
