#include "cardwidget.h"

#include "ui_cardwidget.h"

CardWidget::CardWidget(const QString encScore, QWidget* parent)
    : QWidget(parent), ui(new Ui::CardWidget) {
  ui->setupUi(this);
  this->encScore = encScore;
  ui->scoreButton->setText("");
}

void CardWidget::setScoreLabel(const QString score) {
  ui->scoreButton->setText(score);
}

CardWidget::~CardWidget() { delete ui; }

void CardWidget::on_scoreButton_clicked() {
  ui->scoreButton->setEnabled(false);

  const auto decScore = crypton.decrypt(encScore);
  setScoreLabel(decScore);

  score = decScore.toLongLong();
  emit cardClicked(score);
}
