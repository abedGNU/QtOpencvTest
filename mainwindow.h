#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"

#include"cvmanipulation.h"

#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>

#include <QFileDialog>
#include <QScrollArea>

class MainWindow : public QMainWindow, public Ui::MainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    void showImage(cv::Mat &image, QLabel *label);

private slots:
    void pushButtonSalt_Click();
    void openDialog();
    void spinBoxSlatNumSetValue(int);
    void pushButtonColorReduction_Click();
    void pushButtonGrabImage_Click();
private:
    cv::Mat image;
    cv::Mat destImage;
    int saltNumber = 3000;
};

#endif // MAINWINDOW_H
