#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>

#include "crypton.h"
#include "data.h"

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit GameWindow(QWidget *parent = nullptr);
  ~GameWindow();

  void addCard(const QString encScore);
  void initGame();
  void endGame();

 public slots:
  void cardPressed(const int64_t score);

 private slots:
  void on_restartButton_clicked();

 private:
  Ui::GameWindow *ui;

  const uint FIELD_SIZE = 3 * 3;
  const uint MAX_CLICKED = 3;
  uint clickedAmount = 0;
  int64_t scoreSum = 0;
  Crypton crypton = Crypton(GOOD_PASSWORD);
 signals:
  void setCardScoreLabel(const QString score);
};

#endif  // GAMEWINDOW_H
