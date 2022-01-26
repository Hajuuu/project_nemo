#pragma once
//Ű���尪�� 
#define LEFT 75 //�·� �̵�    
#define RIGHT 77 //��� �̵� 
#define UP 72 //���� �̵�
#define DOWN 80 //�Ʒ��� �̵�
#define ENTER 13   //�׸���� �Ϸ� -> ����Ȯ��
#define SPACE 32 //�׸�ĭ ĥ�ϱ� & ĥ�� �� ����ϱ�
#define XXKEY 88   //xǥ ĥ�ϱ�
#define XKEY 120   //xǥ ĥ�ϱ�
#define ONE 49   //������ �޴���ư 1
#define TWO 50   //������ �޴���ư 2
#define THREE 51   //������ �޴���ư 3
#define FOUR 52   //������ �޴���ư 4

#define SIZE 5 //�׸���� �� ũ�� (���簢���� ����)

class Nemo
{
private:
	int x = 5, y = 2;   //ȭ���� ù ��������
	int nX = x + 10, nY = y + 5;   //�׸���� ù ��������
	int kPosX = 0, kPosY = 0;   //Ŀ�� ��ġ
	int px = 0, py = 0;
	int pPos[2] = { px, py };   //�÷��̾� ��ġ -�׸���� �迭��ǥ ��
	int sucess = 0;   //Ŀ���� goto ���� if�� �����ϸ� 1, �ƴ� 0
	int key = 0;   //Ű���� � ������
	int player[SIZE][SIZE] = { {0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0} };
	int answer[SIZE][SIZE] = { {0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0} };
	int tHint[2][5][3] = { {{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}}, {{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}} };
public:
	void Answer(int type);   //���� ���� �迭 >>  ���� �ȵȰ� : 0 , ���� �� �� : 1, xǥ�õ� �� : 2
	void Print(int an[SIZE][SIZE]);   //�׸���� ����� ���� ���
	void Change(int an[SIZE][SIZE], int row, int col, int k);   //�׸���� ���� 0,1,2 ���̿��� ����
	void PageMain();   //���� ������ ��� -> �׵θ�
	void Start();   //ù ȭ�� -> ���� ���� ����
	void Keyboard(int key);   //Ű���� �Է� �� �ޱ�
	void Move(int dir);   //ȭ��ǥ ��ư ������ �̵�
	int Correct();   //����� ����� Ǯ�̰� �³� Ȯ��
	void IsAnswer(int cor);   //���� ���� �˷��ְ� -> ������ / �� ���� / �޴��� ���� ����
	void End();   //������ ������ ȭ��
	void LoopFunc();   //�׸���� ���� ȭ�� ����ϰ� Ű���� �� �޴� ���ѷ��� �����ϰ� ���
	void HintChange(int tHint[2][5][3], int zero, int one, int two, int i, int j);   //���� ��Ʈ�� �����ϴ� �Լ�
	void HintPrint(int h[2][5][3]);   //��Ʈ ���
	void AnswerPrint();   //���� ���� �������ֱ�
	void Clear();   //�迭 �� �ʱ�ȭ
	void GotoXY(int x, int y);
	void GotoForC(int x, int y);
};