//https://github.com/Enderceliik
//Ender CELIK

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QRgb color;
    QImage image;
    QPoint pointFirst;
    QPoint pointSecond;
    int mouseClickCounter;
    void mousePressEvent(QMouseEvent*);
    void BresenhamCircleAlgorithm();
    void pixelDrawer8(int x, int y, int xCenter, int yCenter);


};
#endif // MAINWINDOW_H
