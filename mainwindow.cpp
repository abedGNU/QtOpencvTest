#include "mainwindow.h"
#include <QtWidgets>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setupUi(this);
    //label->setStyleSheet("border: 2px solid grey");
    connect(actionOpen, SIGNAL( triggered() ), this, SLOT(openDialog()));

    connect(pushButtonSalt, SIGNAL(clicked()), this, SLOT(pushButtonSalt_Click()));
    connect(spinBoxSlatNum,SIGNAL(valueChanged(int)),this,SLOT(spinBoxSlatNumSetValue(int)));
    connect(pushButtonColorReduction, SIGNAL(clicked()), this, SLOT(pushButtonColorReduction_Click()) );
    connect( pushButtonGrabImage, SIGNAL(clicked()), this, SLOT(pushButtonGrabImage_Click()) );
}


void MainWindow::openDialog()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open Image"), ".", tr("Image Files (*.png *.jpg *.bmp)"));

    if (fileName.isEmpty())
        return;
    image= cv::imread(fileName.toStdString());
    showImage(image,label);
}

void MainWindow::pushButtonSalt_Click()
{

    if (image.empty())
        return;
    else{
        cvManipulation::salt(image, destImage,saltNumber);
        showImage(destImage,label_dest);
    }
}

void MainWindow::pushButtonColorReduction_Click(){
    cvManipulation::colorReduction(image,destImage);
    showImage(destImage,label_dest);
}

void MainWindow::showImage(cv::Mat &image, QLabel *label){
    if (image.empty())
        return;
    else {
        //cv::namedWindow("Image");
        //cv::imshow("Image",image);
        //cv::flip(image,image,1); // process the image
        cv::Mat tmpImg;
        image.copyTo(tmpImg);
        // Since OpenCV uses BGR order, we need to convert it to RGB
        cv::cvtColor(image,tmpImg,CV_BGR2RGB);  // change color channel ordering
        QImage img= QImage((const unsigned char*)(tmpImg.data),  // Qt image structure
                           tmpImg.cols,tmpImg.rows,QImage::Format_RGB888);
        label->setPixmap(QPixmap::fromImage(img).scaled(label->size(),Qt::KeepAspectRatio,
                                                        Qt::SmoothTransformation));  // display on label
        //label->resize(label->pixmap()->size()); // resize the label to fit the image
    }
}

void MainWindow::spinBoxSlatNumSetValue(int num){
    saltNumber=num;
}

void MainWindow::pushButtonGrabImage_Click(){
    cvManipulation::imageCapture(0,destImage);
     showImage(destImage,label_dest);
}
