#ifndef CARDWIDGET_H
#define CARDWIDGET_H

#include <QWidget>

namespace Ui {
class CardWidget;
}

class CardWidget : public QWidget {
  Q_OBJECT

public:
  explicit CardWidget(const int score, QWidget *parent = nullptr);
  ~CardWidget();

  int score = 0;

  void setScore(const int score);
  const int getScore();

private slots:
  void on_scoreButton_clicked();

private:
  Ui::CardWidget *ui;

signals:
  void cardClicked(const int score);
};

#endif // CARDWIDGET_H
