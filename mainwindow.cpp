#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMouseEvent>
#include <QString>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << "Test QDebug.";
    QFont labelFont("Times", 14, QFont:: Bold);

    setWindowTitle("Mouse v18.1");
    setFixedSize(900,700);

    redButtonRect.setRect(LeftRedButton,TopRedButton, WidthRedButton, HeightRedButton);

    xMouseLabel = new QLabel("Mouse X: ", this);
    xMouseLabel->setGeometry(0,0,200,50);
    xMouseLabel->setFont(labelFont);

    flagLabel = new QLabel("Mouse X: ",this);
    flagLabel->setGeometry(0,100,200,50);
    flagLabel->setFont(labelFont);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event) {
    int xMouse = event->x();
    int yMouse = event->y();
    qDebug() << "Mouse X: " << xMouse;
    qDebug() << "Mouse Y: " << yMouse;
    xMouseLabel->setText("Mouse Y: "
                         + QString("%1").arg(xMouse,3,10,QChar('0'))
                         + "\n"
                         + "Mouse Y: "
                         + QString("%1").arg(yMouse, 3, 10, QChar('0')));
    qDebug() << "Is Mouse in Rect: " << isMouseInRect(xMouse, yMouse, redButtonRect);
    if (isMouseInRect(xMouse, yMouse, redButtonRect)) {
        flagRedButtonClick = true;
    }
    else {
        flagRedButtonClick = false;
    }
    flagLabel->setText("Flag: "
                       + QString("%1").arg(flagRedButtonClick,1,10,QChar(' ')));
}

void MainWindow::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QPen redPen4(Qt::red, 4, Qt::SolidLine);
    painter.setPen(redPen4);
    painter.drawRect(redButtonRect);
}

bool MainWindow::isMouseInRect(int x, int y, QRect rect) {
    return x>rect.x() and y>rect.y()
        and x<(rect.x() + rect.width())
        and y<(rect.y() + rect.height());

}
