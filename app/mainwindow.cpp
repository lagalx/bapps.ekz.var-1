#include "mainwindow.h"

#include <QMessageBox>

#include "data.h"
#include "gamewindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

inline void goToNextWindow(MainWindow* w) {
  auto nextWindow = new GameWindow();
  nextWindow->show();
  w->close();
}

void MainWindow::on_loginButton_clicked() {
  const auto PASSWORD = ui->passwordEdit->text();

  if (PASSWORD != GOOD_PASSWORD) {
    QMessageBox::critical(this, "Login Failed", "Try to type password again.");
    return;
  }

  goToNextWindow(this);
}
