//
// Created by sunguoyan on 16/5/9.
//

#ifndef PMGRADENHENCE_HISTOGRAM_H
#define PMGRADENHENCE_HISTOGRAM_H
#include<opencv2/highgui.hpp>
#include<cv.h>
#include<iostream>
#include<fstream>
using namespace std;
using namespace cv;

class Histogram{
public:
    int X_image,Y_image;
    int maxPixel;
    void histogram(Mat&src,Mat&dst);

};

#endif //PMGRADENHENCE_HISTOGRAM_H
