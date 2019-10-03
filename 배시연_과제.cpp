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

void print_card(int card);

int pointsum(int num[6]);
int cardpoint(int num);
int cardspled();
void start();
int playerturn(int my_num[6], int *my_num2, int *deal_num, int *deal_num2, int my_count, int deal_count);
int dealerturn(int my_num[6], int *my_num2, int *deal_num, int *deal_num2, int my_count, int deal_count);
int* carddeck();

int main(void)
{
	printf("===================================\n ");
	printf("     블랙잭 게임을 시작합니다\n");
	printf("===================================\n");
	
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
	if (card == BACK)
		printf("▒▒");
	else
		printf("%s%2s\t", card_suit[card / 13], card_num[card % 13]);
}
int cardspled() { //카드 한장씩 꺼내서 나눠주는 함수  //전역변수를 어떻게 안쓸지가 고민

	int num, i;

	for (i = 0; i < 52; i++) {
		if (deck[i] != -1) {
			num = deck[i];
			deck[i] = -1;
			break;
		}
	}
	
	return num;
}

int cardpoint(int num) { //카드가 수가 아니라 문자일경우가 있으니 이때, 수로 변환해주는 함수
	if ((num % 13) == 0) {
		num = 11;                   //A가 나왔을때는 11포인트
	}
	else if (((num % 13) == 10) || ((num % 13) == 11) || ((num % 13) == 12)) { //J 혹은 Q혹은 K가 나왔을때는 10포인트
		num = 10;
	}

	return(num);   // 수로 변환된 포인트를 리턴해준다.

}
int pointsum(int *num) {  //지금까지 보유하고 있는 카드들의 포인트 총 합, 배열을 받는다
	int i;
	int sum = 0;
	for (i = 0; i < 5; i++) {
		sum = sum + num[i];
	}
	return sum;
}
int* carddeck() {
	int i, j, k, flag;
	i = 0;
	flag = 0;
	srand((int)time(NULL));
	while (i < 52) {
		j = rand() % 52 + 0;

		for (k = 0; k < i; k++) {
			if (j == deck[k]) {
				flag = 1;
				break;
			}
		}
		if (flag != 1) {
			deck[i++] = j;
		}
		flag = 0;
	}
	return deck; //deck배열을 리턴
}





void start() {
	int deal_num[6]; //딜러의 카드들
	int my_num[6]; //플레이어의 카드들
	int deal_num2[6];//포인트숫자세는걸위해 만든 deal_num의 쌍둥이배열, A,J,K,Q가 있을경우 숫자로 변환되어들어감
	int my_num2[6];// 포인트숫자세는걸위해 만든 my_num의 쌍둥이배열,A,J,K,Q가 있을경우숫자로 변환되어들어감

	int money		=	200; //보유금액
	int playerbet	=	0;  //플레이어의 배팅머니

	int turn		=	1; //턴횟수
	int deal_count	=	0;  //딜러의 카드개수
	int my_count	=	0;   //플레이어의 카드들
	int i			=	0; //while문 검사를 위한 변수 선언
	int bust_1		=	0;  //버스트되어 끝났는지 확인용으로 만든 변수
	int bust_2		=	0;
	int count		=	0; //카드덱에서 현재 몇장의 카드가 빠져나갔는지

	printf(" CASH : %d\n", money);
	printf(" 얼마를 배팅하시겠습니까?\n ");
	while (1) {
		scanf("&d", &playerbet);
		scanf("%d", &playerbet);
		if (playerbet > money) {  //보유금액보다 배팅금액이 큰경우 다시입력하게 한다.
			printf("보유 금액보다 많습니다. 다시 입력해주세요\n");
		}
		else {
			break;
		}
	}

	printf("Bet : %d\n", playerbet);  //배팅하는 금액을 입력받아서 표시해줌
	printf("\n");

	///////////////////딜러 카드출력
	printf("Dealer : \n");
	deal_num[0] = cardspled();

	deal_num[1] = cardspled();


	deal_count = deal_count + 2; //딜러의 카드가 두장이되었다.
	print_card(BACK); //첫번째 카드는 숨겨서 보여줌
	printf("    ");
	print_card(deal_num[1]); //두번째 카드 출력
	printf("\n");
							 ////////////// 플레이어카드출력
	printf("Player : \n");

	my_num[0] = cardspled();  //카드를 받는다

	my_num[1] = cardspled();  //두번째카드를 받는다


	print_card(my_num[0]);
	print_card(my_num[1]);
	printf("\n");
	my_count = my_count + 2;   //플레이어의 현재 카드가 두장이 되었다는 뜻.
	printf("\n");

	//블랙잭인지 확인
	if (cardpoint(my_num[0]) + cardpoint(my_num[1]) == 21)
	{
		printf(" Black Jack !! 승리했습니다\n ");
		playerbet = playerbet * 2.5; //승리할경우 배팅금액의 두배를 돌려받고, 플레이어는 50퍼센트를 추가로 얻는다.
		printf("%d를 돌려받습니다\n", playerbet);
		
	}

	else {
		//플레이어 턴  이부분을 따로 뺄까 생각중.
		playerturn(my_num, my_num2, deal_num, deal_num2, my_count, deal_count);   //배열을 넣어준다

							   //딜러의턴이 시작됨
		dealerturn(my_num, my_num2, deal_num, deal_num2, my_count, deal_count); //배열을 넣어준다



							  //최종승부결정
		if ((bust_1 == 0) && (bust_2 == 0)) { //둘다 bust되지 않고 각자의 턴이 끝났다면 포인트비교

			printf("각자의 턴이 모두 끝났습니다\n");
			printf("Dealer의 포인트 : %d\n", pointsum(deal_num2));
			printf("player의 포인트 : %d\n", pointsum(my_num2));
			if (pointsum(my_num2) > pointsum(deal_num2))
			{
				printf("player의 승리입니다!\n ");
				money = money * 2;

			}
			else if (pointsum(deal_num2) > pointsum(my_num2)) {
				printf("dealer의 승리입니다!\n ");
				money = money - playerbet;
				printf("배팅금액을 잃어 %d만큼의 금액이 남았습니다", money);
			}
			else
				printf("무승부입니다!\n ");
		}
	}

}  //start 함수끝

int playerturn(int my_num[6],int *my_num2, int *deal_num,int *deal_num2, int my_count, int deal_count) { //내 카드덱 배열을 받는다
	int newcard		=	0;
	int turn		=	1; //double down 조건인 '첫번째턴'인지 확인을 위한 변수
	int bust_1		=	0; //bust로 끝났는지 확인을 위해 넣은 변수
	int i			=	0;
	int money		=	0; //보유금액
	int playerbet	=	0;  //플레이어의 배팅머니
	char choosewhat	=	' ';
	//int deal_count	=	0;
	//int my_num[6];
	//int deal_num[6] =	{};
	//int my_num2[6]	=	{};
	//int deal_num2[6]=	{};


	printf("player의 턴입니다! \n");
	printf("\n");
	while (1) {
		printf("Choose One [h: hits, s:Stay, d: Double down]\n");
		scanf("%c", &choosewhat);
		scanf("%c", &choosewhat);

		if (choosewhat == 's') { //스테이인 경우 더이상 카드를 받지않는다
			printf("스테이! 턴을 종료합니다\n");
			turn++;
			break;  //턴 종료

		}
		else if (choosewhat == 'd') { //더블다운인 경우,
			
			printf("\n");
			if ((money > playerbet) && (turn == 1))
			{    //이 조건에서만 실행가능
				printf("더블다운! 배팅금액을 두배로 늘리고 카드를 한장 더 받습니다\n");
				playerbet = playerbet * 2; //배팅금액을 두배로 늘리고
				newcard = cardspled(); //카드 한장받기
				my_count = my_count + 1; //보유하고 있는 카드 갯수가 늘어남
				my_num[my_count - 1] = newcard;  //새로뽑은 카드를 보유카드배열에 넣어줌
				turn++;

				//현재 카드상태 출력
				printf("Dealer :\n");
				print_card(BACK); //딜러의 첫번째 카드는 숨겨서 보여줌
				printf("     ");
				print_card(deal_num[1]); //두번째 카드 출력
				printf("Player :\n");   //현재 까지 카드 출력
				for (i = 0; i < 6; i++) {
					print_card(my_num[i]);
				}

				for (i = 0; i < 6; i++) {  //A나 J,Q,K가 있는 경우 알파벳을 숫자로 변환시켜줌
					my_num2[i] = cardpoint(my_num[i]);
				}
				if (pointsum(my_num2) > 21) { //카드포인트들의 합이 21보다 커서 버스트 된 상황
					printf(" Bust !! 딜러의 승입니다\n");
					bust_1 = 1;   //버스트되어 종료되었다는 뜻
					break;
				}
				break; //플레이어의 턴을 종료
			}
			else {  //더블다운 조건이 충족되지 않는 상황
				printf("더블다운이 불가능합니다\n"); //그리고 다시받아야됨
			}
		}
		else if (choosewhat == 'h') {
			printf("히트! 카드를 한장 더 받습니다\n");
			printf("\n");
			newcard = cardspled();//카드 한장더받기
			my_count = my_count + 1; //보유하고 있는 카드 갯수가 늘어남
			my_num[my_count - 1] = newcard;  //새로뽑은 카드를 보유카드배열에 넣어줌
											 //현재카드 출력
			printf("Dealer :\n");
			print_card(BACK); //딜러의 첫번째 카드는 숨겨서 보여줌
			printf("    ");
			print_card(deal_num[1]); //두번째 카드 출력
			printf("\n");
			printf("Player :\n");  // 플레이어한테 현재 까지 있는 모든 카드 출력
			for (i = 0; i < my_count; i++) {
				print_card(my_num[i]);
			}
			printf("\n");
			for (i = 0; i < deal_count; i++) {  //A나 J,Q,K를 숫자로 변환시켜서 쌍둥이배열에 넣어줌
				deal_num2[i] = cardpoint(deal_num[i]);
			}
			if (pointsum(deal_num2) > 21) { //버스트 된 상황
				printf(" Bust !! 딜러의 승입니다\n");
				bust_1 = 1;
				break;
			}

		}



	}
	return bust_1;  //버스트말고 쌍둥이배열을 넘겨줘야하는걸까

}



int dealerturn(int my_num[6], int *my_num2, int *deal_num, int *deal_num2, int my_count, int deal_count) {
	int i;
	int newcard;
	int bust_2 = 0;
	//int my_num[6];
	//int deal_num[6];
	//int deal_num2[6];
	printf(" Dealer의 턴입니다!!\n ");

	while (1) {
		//딜러 카드출력
		printf("Delaer :\n");
		for (i = 0; i < 2; i++) { //숨겼던 카드를 포함하여 다 보여준다.
			print_card(deal_num[i]);
		}
		printf("\n");
		// 플레이어카드도 출력
		printf("Player :\n");
		for (i = 0; i < 6; i++) {
			print_card(my_num[i]);
		}
		printf("\n");
		////////////////////////////////////
		for (i = 0; i < 6; i++) {  //A나 J,Q,K를 숫자로 변환시켜줌
			deal_num2[i] = cardpoint(deal_num[i]);
		}

		if (pointsum(deal_num2) < 17) {  //카드합산포인트가 16이하인 경우 hit
			printf("Hit !! 카드를 한장더 받습니다\n ");
			newcard = cardspled();//카드 한장더받기
			deal_count = deal_count + 1; //보유하고 있는 카드 갯수가 늘어남
			deal_num[deal_count - 1] = newcard;  //새로뽑은 카드를 보유카드배열 뒤에 넣어줌

		}

		else if ((pointsum(deal_num2) >= 17) && (pointsum(deal_num2) <= 21))
		{ //17이상이되 버스트는 아닌상황
			printf("Stay !!\n ");
			break;
		}
		else // (pointsum(deal_num) > 21)  //버스트 된 상황
		{
			printf(" Bust !! 플레이어의 승입니다\n");
			bust_2 = 1;  //버스트되어 끝난다는 표시
			break;
		}
	}
	return bust_2;

}

