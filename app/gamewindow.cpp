#include "gamewindow.h"

#include <QDebug>
#include <QMessageBox>
#include <QRandomGenerator>

#include "cardwidget.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::GameWindow) {
  ui->setupUi(this);
  ui->cardsListWidget->setSelectionRectVisible(false);

  initGame();
}

GameWindow::~GameWindow() { delete ui; }

void GameWindow::initGame() {
  scoreSum = 0;
  clickedAmount = 0;

  ui->cardsListWidget->clear();
  ui->scoreLabel->setText(QString::number(scoreSum));

  for (auto i = 0; i < FIELD_SIZE; i++) {
    const auto score = QRandomGenerator::global()->generate();
    const auto encScore = crypton.encrypt(QString::number(score));
    qDebug() << score << " : " << encScore;
    addCard(encScore);
  }
}

void GameWindow::addCard(const QString encScore) {
  auto listItemW = new QListWidgetItem();
  auto itemW = new CardWidget(encScore, this);

  listItemW->setSizeHint(itemW->sizeHint());

  ui->cardsListWidget->addItem(listItemW);
  ui->cardsListWidget->setItemWidget(listItemW, itemW);

  QObject::connect(itemW, SIGNAL(cardClicked(const int64_t)), this,
                   SLOT(cardPressed(const int64_t)));
}

void GameWindow::cardPressed(const int64_t score) {
  scoreSum += score;
  ui->scoreLabel->setText(QString::number(scoreSum));

  clickedAmount++;
  if (clickedAmount != MAX_CLICKED) {
    return;
  }

  endGame();
}

void GameWindow::endGame() {
  QMessageBox::information(this, "Game Results",
                           QString("Your gained score: %1").arg(scoreSum));

  initGame();
}

void GameWindow::on_restartButton_clicked() { initGame(); }
