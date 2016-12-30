// Mini_Ball.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
using namespace std;

int i, j;
// 当前横坐标x,当前纵坐标y,边界宽w，边界高h，横向速度v_x，纵向速度v_y,fps刷新频率fps，fps时间t
int x = 2, y = 1;
int w1 = 0, w2 = 26;
int h1 = 0, h2 = 15;
int v_x = 1, v_y = 1, t = 0;
const int fps = 20;

void A();
void B();
void Update();

int main()
{
	Update();
	return 0;
}

//更新
#pragma region 更新模块
void Update()
{
	for (t = 0; t <= fps; t++)
	{
		Sleep(1);
		t = t++;


		while (t >= fps)
		{
			t = 0;
			Sleep(t);
			system("cls");
			A();

		}
	}
}
#pragma endregion

//挡板
#pragma region 挡板模块
void B()
{
	cout << "" << endl;
}
#pragma endregion


//小球
#pragma	region 小球模块
void A()
{
	y = y + v_y;
	x = x + v_x;

	for (i = 0; i <= h2; i++)
	{
		if ((i == 0) || (i == h2))
		{
			//cout << "*" << flush;
			for (int b_x = 0; b_x <= w2; b_x++)
			{
				cout << "*" << flush;
			}
			for (j = 0; j <= w2; j++)
			{
				if (j == w2)
				{
					cout << "*" << flush;
				}
			}
			cout << endl;
		}
		else if (i == y)
		{
			for (j = 0; j <= w2; j++)
			{
				if ((j == w1) || (j == w2))
				{
					cout << "*" << flush;
				}
				else if (j == x)
				{
					cout << "〇" << flush;
				}
				else
				{
					cout << " " << flush;
				}
			}
			cout << "\n" << flush;
		}
		else
		{
			for (j = 0; j <= w2 + 1; j++)
			{
				if ((j == w1) || (j == w2 + 1))
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
		/*for (j = 0; j <= x; j++)
		{
			cout << " " << flush;
		}*/
	}

	if ((y == h1 + 1) || (y == h2 - 1))
	{
		v_y = -v_y;
		//cout << "\a" << endl;
	}
	if ((x == w1 + 1) || (x == w2 - 1))
	{
		v_x = -v_x;
	}
}
#pragma endregion