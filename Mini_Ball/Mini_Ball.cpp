// Mini_Ball.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <time.h>
using namespace std;


int i, j;
// ��ǰ������x,��ǰ������y,�߽��w���߽��h�������ٶ�v_x�������ٶ�v_y,fpsˢ��Ƶ��fps��fpsʱ��t
int x = 2, y = 1;
int w1 = 0, w2 = 26;
int h1 = 0, h2 = 15;
int v_x = 1, v_y = 1, t = 0;
const int fps = 20;
int d_w1 = 5, d_w2 = 20, d_y = 10;

//
int temp = 0;
int t_0 = 0, t_s = 0, t_m = 0, t_h = 0;
int score = 0;
short kg = 0;
//

void A();
void B();
int C();
void Update();
void Change_A();
void Change_B();
time_t tt1, tt2;

string str1 = "*", str2 = "-", str3 = "O";


void test()
{
	cout << str1 << endl;
	cout << str2 << endl;
	cout << size(str1) << size(str2) << endl;
}
int main()
{
	//test();
	Update();
	return 0;
}

void Err()
{

	//cout << "\n\n\t" << tt1 << endl;

	cout << "\n\nscore\t" << score << endl;
	cout << "\n\ntime\t" << t_h << ":" << t_m << ":" << t_s << endl;
	cout << "\n\n\t" << tt2 << endl;

	cout << "\n\n" << "x=" << x << "   " << "y=" << y << endl;
	cout << "temp=" << temp << endl;
}

//����
#pragma region ����ģ��
void Update()
{
	//t = t++;	


	for (t = 0; t <= fps; t++)
	{
		tt1 = time(NULL);
		tt2 = tt1 % 2;
		if (tt2 == 1)
		{
			t_s = t_s++;
		}
		tt2 = tt2 - tt2;
		//tt1 = time(NULL) - tt1;
		//t_0 = t_0++;
		//if (t_0 == 1000)
		//{
		//	t_s = ++t_s;
		//	t_0 = 0;
		//}
		if (t_s == 59)
		{
			t_m = ++t_m;
			t_s = 0;
		}
		if (t_m == 59)
		{
			t_h = ++t_h;
			t_m = 0;
		}

		while (t >= fps)
		{
			Sleep(1000);
			system("cls");
			t = 0;
			//if (x >= w1 && x <= w2 && y >= h1 && y <= h2)
			//{
			A();
			Err();
			//}
			int p = 0;
			if (temp == 2)
			{
				p = ++p;
			}
			cout << p << endl;
		}
	}
}
#pragma endregion

//����
#pragma region ����ģ��
void B()
{
	if (i == d_y)
	{
		for (int k = d_w1; k <= d_w2; k++)
		{
			if (k >= d_w1 && k <= d_w2)
			{
				cout << str2 << flush;
			}
		}
	}
	j = j + d_w2 - d_w1 - 1;
	//cout << "" << endl;
}
#pragma endregion

void Change_A()
{
	if ((y == h1 + 1) || (y == h2 - 1))					//���С�������� y �Ƿ�ﵽ�߽磬���򻻷���
	{
		v_y = -v_y;
	}
	if ((x == w1 + 1) || (x == w2 - 1))					//���С������� x �Ƿ�ﵽ�߽磬���򻻷���
	{
		v_x = -v_x;
	}
	//cout << "\a" << endl;								//�����߽�������ʾ
	//Update();
}

void Change_B()
{
	if ((y == d_y + 1) || (y == d_y - 1))					//���С�������� y �Ƿ�ﵽ�߽磬���򻻷���
	{
		if ((x == d_w1) || (x == d_w2))					//���С������� x �Ƿ�ﵽ�߽磬���򻻷���
		{
			v_y = -v_y;
		}
		//cout << "\a" << endl;								//�����߽�������ʾ
		Update();
	}


}

//����
int static C()
{
	if (y == d_y && x >= d_w1 && x <= d_w2)
	{
		x = x - v_x - v_x;
		score = score+1;
		//cout << "C()" << endl;
		//Err();
		//Sleep(5000);
		//Change_B();
		return 1;
	}
return 3;
}

//С��
#pragma	region С��ģ��
void A()
{
begin:
	y = y + v_y;//С����һ֡ y ����
	x = x + v_x;//С����һ֡ x ����

	//temp = C();

	if (C() == 1)						//����
	{
		v_y = -v_y;
		goto begin;
	}

	//��ӡ���� �����߽硢С�򡢵���
	for (i = 0; i <= h2; i++)					//�������¼��ÿһ�� i Ӧ�ô�ӡ�Ķ���
	{
		if ((i == 0) || (i == h2))					//����Ƿ��ǵ�һ�С����һ�У������ӡ�ϡ��±߽�
		{

			for (int b_x = 0; b_x <= w2; b_x++)			//��ӡ�ϡ��±߽磬�����������δ�ӡ���߽�
			{
				cout << "*" << flush;
			}
			cout << "*" << flush;					//Ϊ�ϡ��±߽�����һλ�������νӺ������ұ߽����
			cout << endl;								//��ɵ��д������л���
		}
		else if (i == d_y)
		{
			for (j = 0; j <= w2; j++)					//ѭ����ӡ�����ж���
			{
				if ((j == w1) || (j == w2))					//����Ƿ������ұ߽磬�����ӡ�߽�
				{
					cout << "*" << flush;
				}
				else if (j == d_w1)							//����Ƿ��ǵ�������� x,�����ӡ����
				{
					B();
				}
				else 										//�Ե�������λ��ӡ�ո����
				{
					cout << " " << flush;
					//cout << j % 10 << flush;
				}
			}
			cout << endl;
		}
		else if (i == y)							//����Ƿ���С�������� y��������С�������еĶ���
		{
			for (j = 0; j <= w2; j++)					//ѭ����ӡ���ж���
			{
				if ((j == w1) || (j == w2))					//����Ƿ������ұ߽磬�����ӡ�߽�
				{
					cout << "*" << flush;
				}
				else if (j == x)							//����Ƿ���С������� x,�����ӡС��
				{
					cout << "O" << flush;
				}
				else										//�Ե�������λ��ӡ�ո����
				{
					cout << " " << flush;
				}
			}
			cout << "\n" << flush;						//��ɵ��д������л���
		}
		else											//�������н��б߽缶�ո���䴦��
		{
			for (j = 0; j <= w2 + 1; j++)
			{
				if ((j == w1) || (j == w2 + 1))				//���ұ߽紦��
				{
					cout << "*" << flush;
				}
				else
				{
					cout << " " << flush;
				}
			}
			cout << "" << endl;
		}
	}
	Change_A();
}
#pragma endregion