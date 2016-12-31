// Mini_Ball.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <time.h>
using namespace std;


int i, j;
// 当前横坐标x,当前纵坐标y,边界宽w，边界高h，横向速度v_x，纵向速度v_y,fps刷新频率fps，fps时间t
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

//更新
#pragma region 更新模块
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

//挡板
#pragma region 挡板模块
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
	if ((y == h1 + 1) || (y == h2 - 1))					//检测小球纵坐标 y 是否达到边界，是则换方向
	{
		v_y = -v_y;
	}
	if ((x == w1 + 1) || (x == w2 - 1))					//检测小球横坐标 x 是否达到边界，是则换方向
	{
		v_x = -v_x;
	}
	//cout << "\a" << endl;								//触碰边界响铃提示
	//Update();
}

void Change_B()
{
	if ((y == d_y + 1) || (y == d_y - 1))					//检测小球纵坐标 y 是否达到边界，是则换方向
	{
		if ((x == d_w1) || (x == d_w2))					//检测小球横坐标 x 是否达到边界，是则换方向
		{
			v_y = -v_y;
		}
		//cout << "\a" << endl;								//触碰边界响铃提示
		Update();
	}


}

//裁判
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

//小球
#pragma	region 小球模块
void A()
{
begin:
	y = y + v_y;//小球下一帧 y 坐标
	x = x + v_x;//小球下一帧 x 坐标

	//temp = C();

	if (C() == 1)						//裁判
	{
		v_y = -v_y;
		goto begin;
	}

	//打印画面 包括边界、小球、挡板
	for (i = 0; i <= h2; i++)					//从上向下检查每一行 i 应该打印的对象
	{
		if ((i == 0) || (i == h2))					//检查是否是第一行、最后一行，是则打印上、下边界
		{

			for (int b_x = 0; b_x <= w2; b_x++)			//打印上、下边界，从左向右依次打印出边界
			{
				cout << "*" << flush;
			}
			cout << "*" << flush;					//为上、下边界增加一位，用于衔接后续左、右边界对齐
			cout << endl;								//完成单行处理，进行换行
		}
		else if (i == d_y)
		{
			for (j = 0; j <= w2; j++)					//循环打印挡板行对象
			{
				if ((j == w1) || (j == w2))					//检查是否是左、右边界，是则打印边界
				{
					cout << "*" << flush;
				}
				else if (j == d_w1)							//检查是否是挡板横坐标 x,是则打印挡板
				{
					B();
				}
				else 										//对单行其他位打印空格填充
				{
					cout << " " << flush;
					//cout << j % 10 << flush;
				}
			}
			cout << endl;
		}
		else if (i == y)							//检查是否是小球纵坐标 y，是则处理小球所在行的对象
		{
			for (j = 0; j <= w2; j++)					//循环打印单行对象
			{
				if ((j == w1) || (j == w2))					//检查是否是左、右边界，是则打印边界
				{
					cout << "*" << flush;
				}
				else if (j == x)							//检查是否是小球横坐标 x,是则打印小球
				{
					cout << "O" << flush;
				}
				else										//对单行其他位打印空格填充
				{
					cout << " " << flush;
				}
			}
			cout << "\n" << flush;						//完成单行处理，进行换行
		}
		else											//对其他行进行边界级空格填充处理
		{
			for (j = 0; j <= w2 + 1; j++)
			{
				if ((j == w1) || (j == w2 + 1))				//左右边界处理
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