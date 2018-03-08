
#include "cvmanipulation.h"

cvManipulation::cvManipulation(){

}

void cvManipulation::salt(cv::Mat &srcImage, cv::Mat &destImage, int n=300) {
    if (srcImage.empty())
        return;
    srcImage.copyTo(destImage);
    for (int k=0; k<n; k++) {
        // rand() is the MFC random number generator
        // try qrand() with Qt
        //cv::Mat::copyTo(destImage,srcImage);
        int i= qrand() % destImage.cols;
        int j= qrand() % destImage.rows;

        if (destImage.channels() == 1) { // gray-level image
            destImage.at<uchar>(j,i) = 255;
        } else if (destImage.channels() == 3) { // color image
            destImage.at<cv::Vec3b>(j,i)[0] = 255;
            destImage.at<cv::Vec3b>(j,i)[1] = 255;
            destImage.at<cv::Vec3b>(j,i)[2] = 255;
        }
    }
}

void cvManipulation::colorReduction(cv::Mat &srcImage, cv::Mat &destImage, int n){
    if (srcImage.empty())
        return;
    srcImage.copyTo(destImage);
    /*
     * if the image is continous we can reshape the image. reshape adjuste only the
     * numeber of rows and columns without reallocating the memory
     */
    //destImage.reshape(1,destImage.cols * destImage.rows);
    if (true){
        int nR = srcImage.rows;
        int nC = srcImage.cols * srcImage.channels();
        if (srcImage.isContinuous()){
            // if the image is continous then no padding pixels are present
            nC = nC * nR;
            nR=1;
        }
        // if the image is contunous the loop is excuted once
        for(int j=0 ; j<nR; j++){
            uchar* data=destImage.ptr<uchar>(j);// pointer to the j-th row
            for(int i=0 ; i<nC ; i++){
                data[i] = data[i]/n*n + n/2;
            }
        }
    }
    else{
        cv::Mat_ <cv::Vec3b>::iterator it = destImage.begin<cv::Vec3b>();
        cv::Mat_ <cv::Vec3b>::iterator itEnd = destImage.end<cv::Vec3b>();
        for(;it != itEnd; ++it){
            (*it)[0] = (*it)[0] / n * n + n/2; // Blue
            (*it)[1] = (*it)[1] / n * n + n/2; // Green
            (*it)[2] = (*it)[2] / n * n + n/2; // Red
        }
    }

}

void cvManipulation::imageCapture(int idDevice, cv::Mat &outImage){
    cv::VideoCapture cap(idDevice);
    if( !cap.isOpened() )
        return;
    else{
        cap >> outImage;
    }
}
