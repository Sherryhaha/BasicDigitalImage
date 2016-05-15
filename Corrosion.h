//
// Created by sunguoyan on 16/5/12.
//

#ifndef BASICDIGITALIMAGE_CORROSION_H
#define BASICDIGITALIMAGE_CORROSION_H
#include<iostream>
#include<cv.h>
#include<opencv2/highgui.hpp>
using namespace std;
using namespace cv;

class corrosion{
public:
    int X_image,Y_image;
    void corrosionFunc(Mat&src,Mat&dst,int*tmp,int l);
    int Pixelcorrosion(Mat&src,int*tmp,int l,int x,int y);
    int Pixelexpansion(Mat&src,int*tmp,int l,int x,int y);
};


#endif //BASICDIGITALIMAGE_CORROSION_H
