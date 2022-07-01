#include "cardwidget.h"

#include "ui_cardwidget.h"

CardWidget::CardWidget(const int score, QWidget* parent)
    : QWidget(parent), ui(new Ui::CardWidget) {
  ui->setupUi(this);

  ui->scoreButton->setText("");
  setScore(score);
}

const int CardWidget::getScore() { return score; }

void CardWidget::setScore(const int score) { this->score = score; }

CardWidget::~CardWidget() { delete ui; }

void CardWidget::on_scoreButton_clicked() {
  ui->scoreButton->setText(QString::number(score));
  ui->scoreButton->setEnabled(false);

  emit cardClicked(score);
}
