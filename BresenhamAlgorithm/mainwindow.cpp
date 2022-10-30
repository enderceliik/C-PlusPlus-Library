//https://github.com/Enderceliik
//Ender CELIK

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setGeometry(0,0,600,600);
    ui->label->setFrameShape(QFrame::Box);
    ui->label->show();
    color=qRgb(255,255,255);
    QImage env(600,600,QImage::Format_RGB32);
    ui->label->setPixmap(QPixmap::fromImage(env));
    image=env;
    mouseClickCounter = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(mouseClickCounter==0)
        {
            pointFirst=event->pos(); // get the coordinate of first mouse click point
            mouseClickCounter++;
        }
        else
        {
            pointSecond=event->pos(); // get the coordinate of second mouse click point
            mouseClickCounter=0;
            BresenhamCircleAlgorithm(); // call Bresenham Function
        }
}

void MainWindow::BresenhamCircleAlgorithm()
{
    // determine the radius value with the second click
    int radius = pointSecond.x() - pointFirst.x(); // Our radius value
    int radius2 = pointSecond.y() - pointFirst.y();
    if(radius2 < 0)
        radius2 = - radius2;
    if(radius < 0)
        radius = - radius; // If the value is negative, we have to convert it to positive
    if(radius < radius2)
        radius = radius2;

    int x = radius;
    int y = 0;
    int mistakeValue = 0;

    int mistakeValueOne, mistakeValueTwo;

    int xCenter = pointFirst.x();
    int yCenter = pointFirst.y();

    pixelDrawer8(x, y, xCenter, yCenter);

    while(x >= y)
    {
        mistakeValueOne = mistakeValue + (2 * y + 1);
        mistakeValueTwo = mistakeValue + (2 * y + 1) - (2 * x - 1);
        if(abs(mistakeValueOne) < abs(mistakeValueTwo))
        {
            y++;
            mistakeValue = mistakeValueOne;
        }
        else
        {
            x--;
            y++;
            mistakeValue = mistakeValueTwo;
        }
        pixelDrawer8(x, y, xCenter, yCenter);
    }
}

void MainWindow::pixelDrawer8(int x, int y, int xCenter, int yCenter)
{
    image.setPixel(round(xCenter + x),round(yCenter + y),color);
    image.setPixel(round(xCenter - x),round(yCenter + y),color);
    image.setPixel(round(xCenter + x),round(yCenter - y),color);
    image.setPixel(round(xCenter - x),round(yCenter - y),color);
    image.setPixel(round(xCenter + y),round(yCenter + x),color);
    image.setPixel(round(xCenter - y),round(yCenter + x),color);
    image.setPixel(round(xCenter + y),round(yCenter - x),color);
    image.setPixel(round(xCenter - y),round(yCenter - x),color);
    ui->label->setPixmap(QPixmap::fromImage(image));
}

