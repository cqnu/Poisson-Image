#ifndef POISSON_H
#define POISSON_H
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <cv.h>
#include <vector>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include "type.h"
#include "color.h"

using namespace cv;
class Poisson
{
private:
	float PI;
	Mat* gradient; //�ݶȾ���
	Mat* srcImg; //ԭͼ
	Mat* addImg; //���ϵ�ͼ
	Mat* maskImg; //����ͼ

	Mat* magnitude;

	Mat tmp; //��ʱͼ�������Ϣ��ROIͼ�񣨸���Ȥ����,����

	Color color;//��ɫ

				//ѡ��λ��
	int beginw;
	int beginh;
	int width;
	int height;

	float alpha;
	float beta;

	int iterTimes;// iterTimes��������
	int factor;
	float max;
	float min;
	bool isMask;//�Ƿ�������ͼ
	Mat* mkTempCos(int m, int n);//�Ż�����
	void calculate(int i, int j);//��Ⲵ�ɷ���
	void subtract(int num, Mat* mat);//���ּ�ȥ����
	float pow2(float x);

	void run_normal();
	void run_gradient();
	void run_color();
	void run_texture();
	void run_light();

	void cal_light(float& g,float m);
	void multi_light();
	void multi_color();//��ɫͨ���˷�
	void cal_gradient(Mat* img);//��
	void cal_magnitude();
	void cal_magnitude(int i, int j, int k);

	void print(Mat* temp);//�������
	void solve_poisson1();//��Ⲵ�ɷ���1
	void solve_poisson2();//��Ⲵ�ɷ���2

	void init();

public:
	Poisson();
	void set(Mat* src, Mat* mask, Color c, int times, int x, int y, int w, int h);
	void set(Mat* src, Color c, int times, int x, int y, int w, int h);
	void set(Mat* src, Mat* mask, float alpha, float beta, int times, int x, int y, int w, int h);
	void set(Mat* src, float a, float b, int times, int x, int y, int w, int h);
	void set(Mat* src, Mat* add, Mat* mask, int times, int x, int y, int w, int h, float min = 0, float max = 1, int factor = 10);
	void set(Mat* src, Mat* add, int times, int x, int y, int w, int h, float min = 0, float max = 1, int factor = 10);

	Mat* run(Type type);

};
#endif