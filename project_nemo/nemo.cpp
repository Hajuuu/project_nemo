#include <iostream>
#include <windows.h>
#include <conio.h>
#include "nemo.h"
using namespace std;

//원하는 위치로 커서 옮기기
void Nemo::GotoXY(int x, int y)
{
	COORD Cur;   //(x,y) 위치값 저장
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

//사용자 커서용 goto
void Nemo::GotoForC(int x, int y)
{
	if ((kPosX >= nX && kPosX < nX + 10) && kPosY >= nY && kPosY <= nY + 5) {   //네모로직 안에서만 커서 움직일 수 있게 범위 지정
		COORD Cur;   //(x,y) 위치값 저장
		Cur.X = x;
		Cur.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		sucess = 1;
	}
	else {
		sucess = 0;
	}
}



//무한루프 내용 함수로 묶음
void Nemo::LoopFunc()
{
	Start();
	while (1) {
		PageMain();
		GotoXY(nX, nY);
		kPosX = nX;
		kPosY = nY;
		while (1) {
			Keyboard(key);
		}
	}
}

//정답 도안들
void Nemo::Answer(int type)
{
	switch (type)
	{
	case 1:   //거북이
	{
		int cPos1[14][2] = { {0,0 }, { 0,2 }, { 0,4 },{1,1}, {1,2}, {1,3}, {2,1}, {2,2}, {2,3}, {3,1}, {3,2}, {3,3}, {4,0},{4,4} };
		int hint1[2][5][3] = { {{1,1},{3},{4},{3},{1,1}},{ {1,1,1},{3},{3},{3},{1,1} } };
		for (int i = 0; i < 14; i++) {
			Change(answer, cPos1[i][0], cPos1[i][1], 1);
		}
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 5; j++) {
				HintChange(tHint, hint1[i][j][0], hint1[i][j][1], hint1[i][j][2], i, j);
			}
		}
		break;
	}

	case 2:   //스마일 페이스
	{
		int cPos2[20][2] = { {0,0}, {0,1}, {0,2}, {0,3}, {0,4}, {1,0}, {1,2}, {1,4}, {2,0}, {2,1}, {2,2}, {2,3}, {2,4}, {3,0}, {3,4}, {4,0}, {4,1}, {4,2}, {4,3}, {4,4} };
		int hint2[2][5][3] = { {{5},{1,1,1},{1,3},{1,1,1},{5}},{{5},{1,1,1},{5},{1,1},{5}} };
		for (int i = 0; i < 20; i++) {
			Change(answer, cPos2[i][0], cPos2[i][1], 1);
		}
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 5; j++) {
				HintChange(tHint, hint2[i][j][0], hint2[i][j][1], hint2[i][j][2], i, j);
			}
		}
		break;
	}

	case 3: //팩맨
	{
		int cPos3[11][2] = { {0, 1}, { 0,2 }, { 0,3 }, { 1,0 }, { 1,4 }, { 2,3 }, { 3,0 }, { 3,4 }, { 4,1 }, { 4,2 }, { 4,3 } };
		int hint3[2][5][3] = { {{1,1},{1,1},{1,1},{1,1,1},{1,1}},{{3},{1,1},{1},{1,1},{3} } };
		for (int i = 0; i < 11; i++) {
			Change(answer, cPos3[i][0], cPos3[i][1], 1);
		}
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 5; j++) {
				HintChange(tHint, hint3[i][j][0], hint3[i][j][1], hint3[i][j][2], i, j);
			}
		}
		break;
	}
	}

}

//네모로직 칸 출력
void Nemo::Print(int an[SIZE][SIZE])
{
	for (int i = 0; i < SIZE; i++) {
		GotoXY(nX, nY + i);
		for (int j = 0; j < SIZE; j++) {
			if (an[i][j] == 0) {
				printf("■");
			}
			else if (an[i][j] == 2) {
				printf("Ⅹ");
			}
			else {
				printf("□");
			}
		}
		printf("\n");
	}

	HintPrint(tHint);   //힌트도 출력하기
}

//힌트 출력
void Nemo::HintPrint(int h[2][5][3])
{
	int a = 0;
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 3; k++) {
				if (h[i][j][k] != 0) {
					if (i == 0) {
						GotoXY(nX + (2 * j), (y + 4) - a);
					}
					else {
						GotoXY((x + 4 * 2) - (2 * a), nY + j);
					}
					printf("%d", h[i][j][k]);
					a++;
				}
			}
			a = 0;
		}
	}
}

//원하는 자리에 0,1 설정 가능 -> 1이 색칠
void Nemo::Change(int an[SIZE][SIZE], int row, int col, int k)
{
	switch (k)
	{
	case 0:
		an[row][col] = 0;
		break;
	case 1:
		an[row][col] = 1;
		break;
	case 2:
		an[row][col] = 2;
		break;
	}
}

//힌트 숫자들 설정
void Nemo::HintChange(int tHint[2][5][3], int zero, int one, int two, int i, int j)
{
	tHint[i][j][0] = zero;
	tHint[i][j][1] = one;
	tHint[i][j][2] = two;
}

//네모로직 커스텀 화면
void Nemo::PageMain()
{
	system("cls");   //화면 재출력
	system("mode con cols=70 lines=40");
	for (int i = 0; i < SIZE * 3; i++) {
		for (int j = 0; j < SIZE * 3; j++) {
			switch (i) {
			case 0:
			case 14:
				GotoXY(x + (2 * i), y + j);
				printf("▩");
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
			case 10:
			case 11:
			case 12:
			case 13:
				if (j == 0 || j == 14) {
					GotoXY(x + (2 * i), y + j);
					printf("▩");
				}
				break;
			}
		}
	}
	Print(player);
}

//맨 첫 화면, 원하는 로직 도면 고를 수 있게
void Nemo::Start()
{
	system("cls");   //화면 재출력
	system("mode con cols=70 lines=40");
	int num;
	printf("<<네모로직>>\n");
	printf("1번 거북이 , 2번 스마일 페이스, 3번 팩맨\n");
	printf("원하는 네모로직 번호를 입력해 주세요 : ");
	scanf("%d", &num);

	Answer(num);
}

//키보드 -> 값 받아오기
void Nemo::Keyboard(int key)
{
	key = 0;

	if (_kbhit()) {   //키보드 눌러서 입력이 있으면
		key = _getch();   //key 변수에 키보드 뭐 눌렸나 값 받아서 넣어줌

		if (key == 224) {   //방향키일 경우 (방향키 224로 통일 , 2번 값 받아서 구별)
			key = _getch();   //224번 값 버림
			switch (key)
			{
			case LEFT:
				Move(LEFT);
				break;
			case RIGHT:
				Move(RIGHT);
				break;
			case UP:
				Move(UP);
				break;
			case DOWN:
				Move(DOWN);
				break;
			}
		}
		else {   //방향키가 아닐 경우
			switch (key) {
			case SPACE:
				if (player[pPos[1]][pPos[0]] == 1) {
					Change(player, pPos[1], pPos[0], 0);
				}
				else {
					Change(player, pPos[1], pPos[0], 1);
				}
				PageMain();
				break;
			case XXKEY:
			case XKEY:
				if (player[pPos[1]][pPos[0]] == 2) {
					Change(player, pPos[1], pPos[0], 0);
				}
				else {
					Change(player, pPos[1], pPos[0], 2);
				}
				PageMain();
				break;
			case ENTER:
				IsAnswer(Correct());
				break;
			case ONE:
				GotoXY(kPosX, kPosY);
				PageMain();
				break;
			case TWO:
				Clear();
				LoopFunc();
				break;
			case THREE:
				Clear();
				End();
				break;
			case FOUR:
				AnswerPrint();
				Clear();
				End();
				break;
			}
		}
	}
}

//방향키 움직일 때 1)커서 옮김, 2)커서 위치 저장
void Nemo::Move(int dir)
{
	switch (dir)
	{
	case LEFT:
	
		
		GotoForC(kPosX = kPosX - 2, kPosY);
		if ((kPosX >= nX && kPosX < nX + 10) && (kPosY >= nY && kPosY <= nY + 5))
		{
			if (sucess == 1) {
				pPos[0] = --px;   //주의!!! px값 먼저 연산해서 연산된 px 들어가게 해야함 + px 변경 // px-- 로 하면 px들어가고 연산돼서 밀려서 들어감 
				pPos[1] = py;
			}
		}
		else
			sucess == 0;
		//if (sucess == 1) {
		//	pPos[0] = --px;   //주의!!! px값 먼저 연산해서 연산된 px 들어가게 해야함 + px 변경 // px-- 로 하면 px들어가고 연산돼서 밀려서 들어감 
		//	pPos[1] = py;
		//}
		break;
	case RIGHT:
		GotoForC(kPosX = kPosX + 2, kPosY);
		if ((kPosX >= nX && kPosX < nX + 10) && (kPosY >= nY && kPosY <= nY + 5))
		{
			if (sucess == 1) {
				pPos[0] = ++px;
				pPos[1] = py;
			}
		}
		else
			sucess == 0;
		break;
		
	case UP:
		
		GotoForC(kPosX, kPosY = kPosY - 1);
		if ((kPosX >= nX && kPosX < nX + 10) && (kPosY >= nY && kPosY <= nY + 5)) {
			if (sucess == 1) {
				pPos[0] = px;
				pPos[1] = --py;
			}
		}
		else
			sucess == 0;
		break;
	case DOWN:
		
		GotoForC(kPosX, kPosY = kPosY + 1);
		if ((kPosX >= nX && kPosX < nX + 10) && (kPosY >= nY && kPosY <= nY + 5)) {
			if (sucess == 1) {
				pPos[0] = px;
				pPos[1] = ++py;
			}
		}
		else
			sucess == 0;
		break;
	}

}

//정답과 사용자 풀이와 비교
int Nemo::Correct()
{
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (player[i][j] == 1 || answer[i][j] == 1) {   //1 (정답) 이외에도 2 (X표시) 와 0 (빈칸) 존재하므로 1일때만 같은지 확인해줘야함
				if (player[i][j] != answer[i][j]) {   //정답과 다른게 하나라도 있으면
					return 0;
				}
			}

		}
	}
	return 1;
}

//정답 유무 알려주는 화면
void Nemo::IsAnswer(int cor)
{
	system("cls");   //화면 재출력
	system("mode con cols=70 lines=40");

	printf("<<정답을 맞춰봅시다!>>\n\n");

	if (cor == 0) {
		printf("아쉽게도 틀렸네요!\n\n");
	}
	else {
		printf("축하해요 정답입니다!\n\n");
	}

	printf("1. 하던 로직을 계속 하려면 1번을 눌러주세요\n");
	printf("2. 메인 페이지로 가려면 2번을 눌러주세요\n");
	printf("3. 종료하려면 3번을 눌러주세요\n");
	printf("4. 정답을 보고 싶다면 4번을 눌러주세요\n");

}

//마지막 화면
void Nemo::End()
{
	system("cls");   //화면 재출력
	system("mode con cols=70 lines=40");

	printf("<<네모로직 끝!!>>\n\n");

	printf("*수고하셨습니다*\n");

	Sleep(3000);   //3초후 종료
	system("cls");   //화면 재출력
	exit(0);   //종료
}

//정답 프린트해주기
void Nemo::AnswerPrint()
{
	PageMain();
	Print(answer);

	Sleep(3000);
	return;
}

//로직 값 저장 버퍼 다 비우기
void Nemo::Clear()
{
	px = 0;
	py = 0;

	kPosX = nX;
	kPosY = nY;

	for (int i = 0; i < 2; i++) {
		pPos[i] = 0;

	}

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			player[i][j] = 0;
			answer[i][j] = 0;
		}
	}

}