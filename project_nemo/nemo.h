#pragma once
//키보드값들 
#define LEFT 75 //좌로 이동    
#define RIGHT 77 //우로 이동 
#define UP 72 //위로 이동
#define DOWN 80 //아래로 이동
#define ENTER 13   //네모로직 완료 -> 정답확인
#define SPACE 32 //네모칸 칠하기 & 칠한 것 취소하기
#define XXKEY 88   //x표 칠하기
#define XKEY 120   //x표 칠하기
#define ONE 49   //마지막 메뉴버튼 1
#define TWO 50   //마지막 메뉴버튼 2
#define THREE 51   //마지막 메뉴버튼 3
#define FOUR 52   //마지막 메뉴버튼 4

#define SIZE 5 //네모로직 판 크기 (정사각형만 지원)

class Nemo
{
private:
	int x = 5, y = 2;   //화면의 첫 시작지점
	int nX = x + 10, nY = y + 5;   //네모로직 첫 시작지점
	int kPosX = 0, kPosY = 0;   //커서 위치
	int px = 0, py = 0;
	int pPos[2] = { px, py };   //플레이어 위치 -네모로직 배열좌표 상
	int sucess = 0;   //커서용 goto 에서 if문 성립하면 1, 아님 0
	int key = 0;   //키보드 어떤 값인지
	int player[SIZE][SIZE] = { {0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0} };
	int answer[SIZE][SIZE] = { {0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0} };
	int tHint[2][5][3] = { {{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}}, {{0,0,0},{0,0,0},{0,0,0},{0,0,0},{0,0,0}} };
public:
	void Answer(int type);   //정답 설정 배열 >>  선택 안된것 : 0 , 선택 된 것 : 1, x표시된 것 : 2
	void Print(int an[SIZE][SIZE]);   //네모로직 저장된 값들 출력
	void Change(int an[SIZE][SIZE], int row, int col, int k);   //네모로직 값들 0,1,2 사이에서 변경
	void PageMain();   //메인 페이제 출력 -> 테두리
	void Start();   //첫 화면 -> 도안 고를수 있음
	void Keyboard(int key);   //키보드 입력 값 받기
	void Move(int dir);   //화살표 버튼 누르면 이동
	int Correct();   //정답과 사용자 풀이가 맞나 확인
	void IsAnswer(int cor);   //정답 유무 알려주고 -> 끝낼지 / 더 할지 / 메뉴로 갈지 정함
	void End();   //끝내는 마지막 화면
	void LoopFunc();   //네모로직 게임 화면 출력하고 키보드 값 받는 무한루프 간결하게 떼어냄
	void HintChange(int tHint[2][5][3], int zero, int one, int two, int i, int j);   //최종 힌트를 변경하는 함수
	void HintPrint(int h[2][5][3]);   //힌트 출력
	void AnswerPrint();   //정답 뭔지 보게해주기
	void Clear();   //배열 다 초기화
	void GotoXY(int x, int y);
	void GotoForC(int x, int y);
};