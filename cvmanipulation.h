#ifndef CVMANIPULATION_H
#define CVMANIPULATION_H

#include"cvmanipulation.h"

//#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <QtGlobal>

class cvManipulation
{
public:
    cvManipulation();
    static  void salt(cv::Mat &srcImage, cv::Mat &destImage, int n);
    //static void showImage(cv::Mat &image, QLabel label);
    static void colorReduction(cv::Mat &srcImage, cv::Mat &destImage, int n=64);
    static void imageCapture(int idDevice, cv::Mat &outImage);
};

#endif // CVMANIPULATION_H
