#include "gamewindow.h"

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
    auto score = QRandomGenerator::global()->generate();
    addCard(score);
  }
}

void GameWindow::addCard(const int score) {
  auto listItemW = new QListWidgetItem();
  auto itemW = new CardWidget(score, this);

  listItemW->setSizeHint(itemW->sizeHint());

  ui->cardsListWidget->addItem(listItemW);
  ui->cardsListWidget->setItemWidget(listItemW, itemW);

  QObject::connect(itemW, SIGNAL(cardClicked(const int)), this,
                   SLOT(cardPressed(const int)));
}

void GameWindow::cardPressed(const int score) {
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
