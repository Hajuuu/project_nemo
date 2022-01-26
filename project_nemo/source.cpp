#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "nemo.h"
using namespace std;

//메인함수!!
int main(void)
{
	Nemo nemo;
	nemo.LoopFunc();
	nemo.Clear();
	system("pause>null");   //마지막에 "계속하려면 아무 키나 누르세요.." 안나오게 
	return 0;
}