#include <iostream>
#include <windows.h>
#include <conio.h>
#include "nemo.h"
using namespace std;

//���ϴ� ��ġ�� Ŀ�� �ű��
void Nemo::GotoXY(int x, int y)
{
	COORD Cur;   //(x,y) ��ġ�� ����
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

//����� Ŀ���� goto
void Nemo::GotoForC(int x, int y)
{
	if ((kPosX >= nX && kPosX < nX + 10) && kPosY >= nY && kPosY <= nY + 5) {   //�׸���� �ȿ����� Ŀ�� ������ �� �ְ� ���� ����
		COORD Cur;   //(x,y) ��ġ�� ����
		Cur.X = x;
		Cur.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
		sucess = 1;
	}
	else {
		sucess = 0;
	}
}



//���ѷ��� ���� �Լ��� ����
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

//���� ���ȵ�
void Nemo::Answer(int type)
{
	switch (type)
	{
	case 1:   //�ź���
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

	case 2:   //������ ���̽�
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

	case 3: //�Ѹ�
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

//�׸���� ĭ ���
void Nemo::Print(int an[SIZE][SIZE])
{
	for (int i = 0; i < SIZE; i++) {
		GotoXY(nX, nY + i);
		for (int j = 0; j < SIZE; j++) {
			if (an[i][j] == 0) {
				printf("��");
			}
			else if (an[i][j] == 2) {
				printf("��");
			}
			else {
				printf("��");
			}
		}
		printf("\n");
	}

	HintPrint(tHint);   //��Ʈ�� ����ϱ�
}

//��Ʈ ���
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

//���ϴ� �ڸ��� 0,1 ���� ���� -> 1�� ��ĥ
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

//��Ʈ ���ڵ� ����
void Nemo::HintChange(int tHint[2][5][3], int zero, int one, int two, int i, int j)
{
	tHint[i][j][0] = zero;
	tHint[i][j][1] = one;
	tHint[i][j][2] = two;
}

//�׸���� Ŀ���� ȭ��
void Nemo::PageMain()
{
	system("cls");   //ȭ�� �����
	system("mode con cols=70 lines=40");
	for (int i = 0; i < SIZE * 3; i++) {
		for (int j = 0; j < SIZE * 3; j++) {
			switch (i) {
			case 0:
			case 14:
				GotoXY(x + (2 * i), y + j);
				printf("��");
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
					printf("��");
				}
				break;
			}
		}
	}
	Print(player);
}

//�� ù ȭ��, ���ϴ� ���� ���� �� �� �ְ�
void Nemo::Start()
{
	system("cls");   //ȭ�� �����
	system("mode con cols=70 lines=40");
	int num;
	printf("<<�׸����>>\n");
	printf("1�� �ź��� , 2�� ������ ���̽�, 3�� �Ѹ�\n");
	printf("���ϴ� �׸���� ��ȣ�� �Է��� �ּ��� : ");
	scanf("%d", &num);

	Answer(num);
}

//Ű���� -> �� �޾ƿ���
void Nemo::Keyboard(int key)
{
	key = 0;

	if (_kbhit()) {   //Ű���� ������ �Է��� ������
		key = _getch();   //key ������ Ű���� �� ���ȳ� �� �޾Ƽ� �־���

		if (key == 224) {   //����Ű�� ��� (����Ű 224�� ���� , 2�� �� �޾Ƽ� ����)
			key = _getch();   //224�� �� ����
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
		else {   //����Ű�� �ƴ� ���
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

//����Ű ������ �� 1)Ŀ�� �ű�, 2)Ŀ�� ��ġ ����
void Nemo::Move(int dir)
{
	switch (dir)
	{
	case LEFT:
	
		
		GotoForC(kPosX = kPosX - 2, kPosY);
		if ((kPosX >= nX && kPosX < nX + 10) && (kPosY >= nY && kPosY <= nY + 5))
		{
			if (sucess == 1) {
				pPos[0] = --px;   //����!!! px�� ���� �����ؼ� ����� px ���� �ؾ��� + px ���� // px-- �� �ϸ� px���� ����ż� �з��� �� 
				pPos[1] = py;
			}
		}
		else
			sucess == 0;
		//if (sucess == 1) {
		//	pPos[0] = --px;   //����!!! px�� ���� �����ؼ� ����� px ���� �ؾ��� + px ���� // px-- �� �ϸ� px���� ����ż� �з��� �� 
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

//����� ����� Ǯ�̿� ��
int Nemo::Correct()
{
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (player[i][j] == 1 || answer[i][j] == 1) {   //1 (����) �̿ܿ��� 2 (Xǥ��) �� 0 (��ĭ) �����ϹǷ� 1�϶��� ������ Ȯ���������
				if (player[i][j] != answer[i][j]) {   //����� �ٸ��� �ϳ��� ������
					return 0;
				}
			}

		}
	}
	return 1;
}

//���� ���� �˷��ִ� ȭ��
void Nemo::IsAnswer(int cor)
{
	system("cls");   //ȭ�� �����
	system("mode con cols=70 lines=40");

	printf("<<������ ���纾�ô�!>>\n\n");

	if (cor == 0) {
		printf("�ƽ��Ե� Ʋ�ȳ׿�!\n\n");
	}
	else {
		printf("�����ؿ� �����Դϴ�!\n\n");
	}

	printf("1. �ϴ� ������ ��� �Ϸ��� 1���� �����ּ���\n");
	printf("2. ���� �������� ������ 2���� �����ּ���\n");
	printf("3. �����Ϸ��� 3���� �����ּ���\n");
	printf("4. ������ ���� �ʹٸ� 4���� �����ּ���\n");

}

//������ ȭ��
void Nemo::End()
{
	system("cls");   //ȭ�� �����
	system("mode con cols=70 lines=40");

	printf("<<�׸���� ��!!>>\n\n");

	printf("*�����ϼ̽��ϴ�*\n");

	Sleep(3000);   //3���� ����
	system("cls");   //ȭ�� �����
	exit(0);   //����
}

//���� ����Ʈ���ֱ�
void Nemo::AnswerPrint()
{
	PageMain();
	Print(answer);

	Sleep(3000);
	return;
}

//���� �� ���� ���� �� ����
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