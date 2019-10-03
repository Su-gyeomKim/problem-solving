#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#define CARDS 52
#define BACK -1 
//추가적인 전역변수 선언 금지
static char card_suit[4][3] = { "♠", "◆", "♥", "♣" };
static char card_num[13][3] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };

int deck[CARDS];

int money;
int num;

int cal_point(int *arr);
int cardspled();
int* carddeck();
int p_turn();
int d_turn();
void start();

int main(void)
{
	printf("===================================\n\t블랙잭 게임을 시작합니다\n===================================\n");

	carddeck();
	start();

	return 0;
}


/*
제공, 카드 한 장 출력
매개변수 card는 int형 변수로 0~51의 범위를 가지며 트럼프 카드 총 52장을 나타낸다
카드 모양의 순서는  ♠, ◆, ♥, ♣이고 각각의 모양에서 A, 2, 3, ……, 10, J, Q, K 이다
ex) 0 ->  ♠A,  1 -> ♠2,  51 -> ♣K
*/
void print_card(int card) {
	if (card == BACK)		printf("▒▒");
	else		printf("%s%2s\t", card_suit[card / 13], card_num[card % 13]);
}

int cardspled() { //카드 한장씩 꺼내서 나눠주는 함수  //전역변수를 어떻게 안쓸지가 고민
	int num, i;
	for (i = 0; i < 52; i++)	if (deck[i] != -1) {			num = deck[i];			deck[i] = -1;			break;		}
	return num;
}

int* carddeck() {
	int i=0, j, k, flag=0;	srand((int)time(NULL));

	while (i < 52) {
		j = rand() % 52 + 0;
		for (k = 0; k < i; k++) 
			if (j == deck[k]) {				flag = 1;				break;			}
		if (flag != 1) 			deck[i++] = j;
		flag = 0;
	}
	return deck; //deck배열을 리턴
}

int cal_point(int *arr) {
	int sum = 0;
	for (int i = 0; i < sizeof(arr); i++) sum += arr[i];
	return sum;
}

void start() {
	int d_c[6]; //딜러의 카드들
	int p_c[6]; //플레이어의 카드들
	int d_p[6];//포인트숫자세는걸위해 만든 deal_num의 쌍둥이배열, A,J,K,Q가 있을경우 숫자로 변환되어들어감
	int p_p[6];// 포인트숫자세는걸위해 만든 my_num의 쌍둥이배열,A,J,K,Q가 있을경우숫자로 변환되어들어감

	money = 200; //보유금액
	int bet = 0;  //플레이어의 배팅머니

	int turn = 1; //턴횟수
	int d_cnt = 0;  //딜러의 카드개수
	int p_cnt = 0;   //플레이어의 카드들
	int i = 0; //while문 검사를 위한 변수 선언
	int bust_p = 0;  //버스트되어 끝났는지 확인용으로 만든 변수
	int bust_d = 0;
	int cnt = 0; //카드덱에서 현재 몇장의 카드가 빠져나갔는지

	printf(" CASH : %d\n", money);
	printf(" 얼마를 배팅하시겠습니까?\n ");
	while (1) {
		scanf("%d", &bet);
		if (bet > money) 			printf("보유 금액보다 많습니다. 다시 입력해주세요\n");
		else 			break;
	}

	printf("Bet : %d\n\n", bet);  //배팅하는 금액을 입력받아서 표시해줌

	///////////////////딜러 카드출력
	printf("Dealer : \n");
	for (int i = 0; i <= turn; i++)			d_c[i] = cardspled();


	d_cnt = d_cnt + 2; //딜러의 카드가 두장이되었다.
	print_card(BACK); //첫번째 카드는 숨겨서 보여줌
	printf("    ");	print_card(d_c[1]); /*두번째 카드 출력*/	printf("\n");

	////////////// 플레이어카드출력
	printf("Player : \n");

	for (int i = 0; i <= turn; i++)			p_c[i] = cardspled();
	for (int i = 0; i <= turn; i++)			print_card(p_c[i]);
	p_cnt = p_cnt + 2;   /*플레이어의 현재 카드가 두장이 되었다는 뜻.*/	printf("\n");

	//블랙잭인지 확인
	if (cal_point(p_c) == 21)
	{
		bet *= 2.5; //승리할경우 배팅금액의 두배를 돌려받고, 플레이어는 50퍼센트를 추가로 얻는다.
		printf(" Black Jack !! 승리했습니다\n %d를 돌려받습니다\n", bet);
		exit;
	}

	bust_p = p_turn();
	bust_d = d_turn();

	if (!bust_p && !bust_d) { //둘다 bust되지 않고 각자의 턴이 끝났다면 포인트비교
		printf("각자의 턴이 모두 끝났습니다\nDealer의 포인트 : %d\nplayer의 포인트 : %d\n", cal_point(d_p), cal_point(p_p));
		if (cal_point(p_p) > cal_point(d_p)) { money *= 2;				printf("player의 승리입니다!\n "); }
		else if (cal_point(d_p) > cal_point(p_p)) { money -= bet;		printf("dealer의 승리입니다!\n 배팅금액을 잃어 %d만큼의 금액이 남았습니다", money); }
		else				printf("무승부입니다!\n ");
	}
	

}  //start 함수끝

int p_turn(int Turn) {
	char	input;
	printf("player의 턴입니다! \n\n");
	while (1) {
		printf("Choose One [h: hits, s:Stay, d: Double down]\n");
		scanf("%c", &input);

		if (input == 's') { //스테이인 경우 더이상 카드를 받지않는다
			printf("스테이! 턴을 종료합니다\n");
			Turn++;
			break;  //턴 종료
		}
}

int d_turn() {

}