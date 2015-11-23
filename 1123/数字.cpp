#include "stdafx.h"
#include "cv.h"
#include "highgui.h"
 
IplImage preprocessing(IplImage* imgSrc,int new_width, int new_height) {

IplImage* result;
}

IplImage* scaledResult; CvMat data; CvMat dataA; CvRect bb;//bounding box
CvRect bba;//boundinb box maintain aspect ratio 
//Find bounding box�ҵ��߽�� 
bb=findBB(imgSrc);
cvGetSubRect(imgSrc, &data, cvRect(bb.x, bb.y, bb.width, bb.height));
int size=(bb.width>bb.height)?bb.width:bb.height;
result=cvCreateImage( cvSize( size, size ), 8, 1 );
cvSet(result,CV_RGB(255,255,255),NULL);
//��ͼ����м䣬��С��һ��
int x=(int)floor((float)(size-bb.width)/2.0f); 
int y=(int)floor((float)(size-bb.height)/2.0f); 
cvGetSubRect(result, &dataA, cvRect(x,y,bb.width, bb.height));
cvCopy(&data, &dataA, NULL); //Scale result
scaledResult=cvCreateImage( cvSize( new_width, new_height ), 8, 1 ); 
cvResize(result, scaledResult, CV_INTER_NN); 
//Return processed data 
return *scaledResult;//ֱ�ӷ��ش�����ͼƬ
}
void basicOCR::getData()

{

IplImage* src_image;

IplImage prs_image;

CvMat row,data;

char file[255];

int i,j;

for(i =0; i<classes; i++)//�ܹ�10������

{

for( j = 0; j< train_samples; j++)//ÿ������50������

{
} }

 

} //�������е�����pbm��ʽͼ����Ϊѵ��
if(j<10) 
	sprintf(file,"%s%d/%d0%d.pbm",file_path, i, i , j); 
else
	sprintf(file,"%s%d/%d%d.pbm",file_path, i, i , j);
src_image = cvLoadImage(file,0);
if(!src_image)
{ 
	printf("Error: Cant load image %s\n", file);
	//exit(-1); 
} 
//process file 
prs_image = preprocessing(src_image, size, size); //����ѵ������ÿ��ͼ����Ϊһ������
cvGetRow(trainClasses, &row, i*train_samples + j); 
cvSet(&row, cvRealScalar(i)); 
//Set data
cvGetRow(trainData, &row, i*train_samples + j);
IplImage* img = cvCreateImage( cvSize( size, size ), IPL_DEPTH_32F, 1 );
//ת���� 8 bits image to 32 λ������ͼƬȡֵ����Ϊ[0,1]
//scale = 0.0039215 = 1/255; 
cvConvertScale(&prs_image, img, 0.0039215, 0);
cvGetSubRect(img, &data, cvRect(0,0, size,size));
CvMat row_header, *row1; //convert data matrix sizexsize to vecor 
row1 = cvReshape( &data, &row_header, 0, 1 ); 
cvCopy(row1, &row, NULL);
}
}
}
