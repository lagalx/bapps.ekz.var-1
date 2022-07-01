#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QMainWindow>

namespace Ui {
class GameWindow;
}

class GameWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit GameWindow(QWidget *parent = nullptr);
  ~GameWindow();

  void addCard(const int score);
  void initGame();
  void endGame();

public slots:
  void cardPressed(const int score);

private slots:
  void on_restartButton_clicked();

private:
  Ui::GameWindow *ui;

  const size_t FIELD_SIZE = 3 * 3;  
  const size_t MAX_CLICKED = 3;
  size_t clickedAmount = 0;
  int scoreSum = 0;
};

#endif // GAMEWINDOW_H
