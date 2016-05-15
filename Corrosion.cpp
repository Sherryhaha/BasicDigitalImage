//
// Created by sunguoyan on 16/5/12.
//

#include "Corrosion.h"

//计算腐蚀指定位置的像素值
int corrosion::Pixelcorrosion(Mat &src, int *tmp, int l, int x, int y) {
    int max = 0;
    x -= l / 2;
    y -= l / 2;
    int i, j;
    for (i = 0; i < l; i++) {
        for (j = 0; j < l; j++) {
            if (tmp[i * l + j] && src.at<uchar>(y + i, x + j) > max) {
                max = src.at<uchar>(y + i, x + j);
            }
        }
    }
    return max;
}
//计算膨胀指定位置的像素值
int corrosion::Pixelexpansion(Mat&src,int*tmp,int l,int x,int y){
    int min = 256;
    x -= l / 2;
    y -= l / 2;
    int i, j;
    for (i = 0; i < l; i++) {
        for (j = 0; j < l; j++) {
            if (tmp[i * l + j] && src.at<uchar>(y + i, x + j) < min) {
                min = src.at<uchar>(y + i, x + j);
            }
        }
    }
    return min;
}

void corrosion::corrosionFunc(Mat &src, Mat &dst, int *tmp, int l) {
    int i, j, i1, j1;

    int x, y;
    unsigned char t, max;
    max = 0;
    for (j = 1; j < Y_image - 1; j++) {
        for (i = 1; i < X_image - 1; i++) {
            dst.at<uchar>(j, i) = Pixelcorrosion(src, tmp, l, i, j);
//            dst.at<uchar>(j, i) = Pixelexpansion(src, tmp, l, i, j);

        }
    }
}


int main(){
    string filename="/Users/sunguoyan/Downloads/picture/lena2.bmp";
    Mat image ,dst;
    image = imread(filename,CV_LOAD_IMAGE_GRAYSCALE);
    dst.create(image.size(),image.type());
    corrosion c;
    c.X_image=image.cols;
    c.Y_image = image.rows;
    int tmp[] = {1,0,1,1,1,1,1,1,0};
    int l = 3;
    c.corrosionFunc(image,dst,tmp,l);

    namedWindow("src");
    namedWindow("test");
    imshow("src",image);
    imshow("test",dst);
    waitKey(0);
    return 0;
}