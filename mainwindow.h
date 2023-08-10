#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void mousePressEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    bool isMouseInRect(int x, int y, QRect rect);
    QLabel *xMouseLabel;
    QLabel *flagLabel;
    QRect redButtonRect;
    const int LeftRedButton = 100;
    const int TopRedButton = 150;
    const int WidthRedButton = 300;
    const int HeightRedButton = 150;
    bool flagRedButtonClick = false;
};
#endif // MAINWINDOW_H
