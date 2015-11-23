 #include <opencv2\opencv.hpp>
  #include <iostream>
  #include <string>
  using namespace cv;
  using namespace std;
 int main()
 {
    Mat img = imread("1.jpg");
     if(img.empty())
     {         cout<<"error";
         return -1;
     }
     imshow("xxµÄö¦ÕÕ",img);
     waitKey();
 
     return 0;
 }