#ifndef CARDWIDGET_H
#define CARDWIDGET_H

#include <QWidget>

#include "crypton.h"
#include "data.h"

namespace Ui {
class CardWidget;
}

class CardWidget : public QWidget {
  Q_OBJECT

 public:
  explicit CardWidget(const QString encScore, QWidget *parent = nullptr);
  ~CardWidget();

  void setScore(const int64_t score);
  const int64_t getScore();

 private slots:
  void on_scoreButton_clicked();

 private:
  Ui::CardWidget *ui;

  int64_t score = 0;
  QString encScore;
  Crypton crypton = Crypton(GOOD_PASSWORD);

 signals:
  void cardClicked(const int64_t score);

 public slots:
  void setScoreLabel(const QString score);
};

#endif  // CARDWIDGET_H
