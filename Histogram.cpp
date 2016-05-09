//
// Created by sunguoyan on 16/5/9.
//

#include "Histogram.h"

void Histogram::histogram(Mat&src,Mat&dst){
    int hist[maxPixel+1];
    double fhist[maxPixel+1];
    double eqhistT[maxPixel+1];
    int eqhist[maxPixel+1];
    int size = X_image*Y_image;
    int i,j;
    int tmp;
    memset(&hist,0,sizeof(int)*(maxPixel+1));
    memset(&fhist,0,sizeof(double)*(maxPixel+1));
    memset(&eqhistT,0,sizeof(double)*(maxPixel+1));
    memset(&eqhist,0,sizeof(int)*(maxPixel+1));


    //计算差分矩阵直方图
    for(j = 0;j < Y_image;j++){
        for(i = 0;i < X_image;i++){
            tmp = src.at<uchar>(j,i);
            hist[tmp]++;
        }
    }
    //计算灰度分布密度
    for(i = 0;i < maxPixel+1;i++){
        fhist[i] = (double)hist[i] / (double)size;
    }
    //计算直方图分布密度
    for(i = 0;i < maxPixel+1;i++){
        if(i==0){
            eqhistT[i] = fhist[i];
        }else{
            eqhistT[i] = eqhistT[i-1]+fhist[i];
        }

    }
    //累计分布取整
    for(i=0;i<maxPixel+1;i++){
        eqhist[i] = (int)(maxPixel*eqhistT[i]+0.5);
    }

    for(j=0;j<Y_image;j++){
        for(i=0;i<X_image;i++){
            tmp = src.at<uchar>(j,i);
            dst.at<uchar>(j,i) = eqhist[tmp];
        }
    }
}

int main(){
    string filename="/Users/sunguoyan/Downloads/picture/lena2.bmp";
    Mat image ,dst;
    image = imread(filename,CV_LOAD_IMAGE_GRAYSCALE);
    dst.create(image.size(),image.type());
    Histogram h;
    h.X_image=image.cols;
    h.Y_image = image.rows;
    h.maxPixel = 255;
    h.histogram(image,dst);

    namedWindow("src");
    namedWindow("test");
    imshow("src",image);
    imshow("test",dst);
    waitKey(0);
    return 0;
}