#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#define CARDS 52
#define BACK -1 
//�߰����� �������� ���� ����
static char card_suit[4][3] = { "��", "��", "��", "��" };
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
	printf("     ���� ������ �����մϴ�\n");
	printf("===================================\n");
	
	carddeck();
	start();

	return 0;
}




/*
����, ī�� �� �� ���
�Ű����� card�� int�� ������ 0~51�� ������ ������ Ʈ���� ī�� �� 52���� ��Ÿ����
ī�� ����� ������  ��, ��, ��, ���̰� ������ ��翡�� A, 2, 3, ����, 10, J, Q, K �̴�
ex) 0 ->  ��A,  1 -> ��2,  51 -> ��K
*/
void print_card(int card) {
	if (card == BACK)
		printf("�Ƣ�");
	else
		printf("%s%2s\t", card_suit[card / 13], card_num[card % 13]);
}
int cardspled() { //ī�� ���徿 ������ �����ִ� �Լ�  //���������� ��� �Ⱦ����� ���

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

int cardpoint(int num) { //ī�尡 ���� �ƴ϶� �����ϰ�찡 ������ �̶�, ���� ��ȯ���ִ� �Լ�
	if ((num % 13) == 0) {
		num = 11;                   //A�� ���������� 11����Ʈ
	}
	else if (((num % 13) == 10) || ((num % 13) == 11) || ((num % 13) == 12)) { //J Ȥ�� QȤ�� K�� ���������� 10����Ʈ
		num = 10;
	}

	return(num);   // ���� ��ȯ�� ����Ʈ�� �������ش�.

}
int pointsum(int *num) {  //���ݱ��� �����ϰ� �ִ� ī����� ����Ʈ �� ��, �迭�� �޴´�
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
	return deck; //deck�迭�� ����
}





void start() {
	int deal_num[6]; //������ ī���
	int my_num[6]; //�÷��̾��� ī���
	int deal_num2[6];//����Ʈ���ڼ��°����� ���� deal_num�� �ֵ��̹迭, A,J,K,Q�� ������� ���ڷ� ��ȯ�Ǿ��
	int my_num2[6];// ����Ʈ���ڼ��°����� ���� my_num�� �ֵ��̹迭,A,J,K,Q�� ���������ڷ� ��ȯ�Ǿ��

	int money		=	200; //�����ݾ�
	int playerbet	=	0;  //�÷��̾��� ���øӴ�

	int turn		=	1; //��Ƚ��
	int deal_count	=	0;  //������ ī�尳��
	int my_count	=	0;   //�÷��̾��� ī���
	int i			=	0; //while�� �˻縦 ���� ���� ����
	int bust_1		=	0;  //����Ʈ�Ǿ� �������� Ȯ�ο����� ���� ����
	int bust_2		=	0;
	int count		=	0; //ī�嵦���� ���� ������ ī�尡 ������������

	printf(" CASH : %d\n", money);
	printf(" �󸶸� �����Ͻðڽ��ϱ�?\n ");
	while (1) {
		scanf("&d", &playerbet);
		scanf("%d", &playerbet);
		if (playerbet > money) {  //�����ݾ׺��� ���ñݾ��� ū��� �ٽ��Է��ϰ� �Ѵ�.
			printf("���� �ݾ׺��� �����ϴ�. �ٽ� �Է����ּ���\n");
		}
		else {
			break;
		}
	}

	printf("Bet : %d\n", playerbet);  //�����ϴ� �ݾ��� �Է¹޾Ƽ� ǥ������
	printf("\n");

	///////////////////���� ī�����
	printf("Dealer : \n");
	deal_num[0] = cardspled();

	deal_num[1] = cardspled();


	deal_count = deal_count + 2; //������ ī�尡 �����̵Ǿ���.
	print_card(BACK); //ù��° ī��� ���ܼ� ������
	printf("    ");
	print_card(deal_num[1]); //�ι�° ī�� ���
	printf("\n");
							 ////////////// �÷��̾�ī�����
	printf("Player : \n");

	my_num[0] = cardspled();  //ī�带 �޴´�

	my_num[1] = cardspled();  //�ι�°ī�带 �޴´�


	print_card(my_num[0]);
	print_card(my_num[1]);
	printf("\n");
	my_count = my_count + 2;   //�÷��̾��� ���� ī�尡 ������ �Ǿ��ٴ� ��.
	printf("\n");

	//�������� Ȯ��
	if (cardpoint(my_num[0]) + cardpoint(my_num[1]) == 21)
	{
		printf(" Black Jack !! �¸��߽��ϴ�\n ");
		playerbet = playerbet * 2.5; //�¸��Ұ�� ���ñݾ��� �ι踦 �����ް�, �÷��̾�� 50�ۼ�Ʈ�� �߰��� ��´�.
		printf("%d�� �����޽��ϴ�\n", playerbet);
		
	}

	else {
		//�÷��̾� ��  �̺κ��� ���� ���� ������.
		playerturn(my_num, my_num2, deal_num, deal_num2, my_count, deal_count);   //�迭�� �־��ش�

							   //���������� ���۵�
		dealerturn(my_num, my_num2, deal_num, deal_num2, my_count, deal_count); //�迭�� �־��ش�



							  //�����ºΰ���
		if ((bust_1 == 0) && (bust_2 == 0)) { //�Ѵ� bust���� �ʰ� ������ ���� �����ٸ� ����Ʈ��

			printf("������ ���� ��� �������ϴ�\n");
			printf("Dealer�� ����Ʈ : %d\n", pointsum(deal_num2));
			printf("player�� ����Ʈ : %d\n", pointsum(my_num2));
			if (pointsum(my_num2) > pointsum(deal_num2))
			{
				printf("player�� �¸��Դϴ�!\n ");
				money = money * 2;

			}
			else if (pointsum(deal_num2) > pointsum(my_num2)) {
				printf("dealer�� �¸��Դϴ�!\n ");
				money = money - playerbet;
				printf("���ñݾ��� �Ҿ� %d��ŭ�� �ݾ��� ���ҽ��ϴ�", money);
			}
			else
				printf("���º��Դϴ�!\n ");
		}
	}

}  //start �Լ���

int playerturn(int my_num[6],int *my_num2, int *deal_num,int *deal_num2, int my_count, int deal_count) { //�� ī�嵦 �迭�� �޴´�
	int newcard		=	0;
	int turn		=	1; //double down ������ 'ù��°��'���� Ȯ���� ���� ����
	int bust_1		=	0; //bust�� �������� Ȯ���� ���� ���� ����
	int i			=	0;
	int money		=	0; //�����ݾ�
	int playerbet	=	0;  //�÷��̾��� ���øӴ�
	char choosewhat	=	' ';
	//int deal_count	=	0;
	//int my_num[6];
	//int deal_num[6] =	{};
	//int my_num2[6]	=	{};
	//int deal_num2[6]=	{};


	printf("player�� ���Դϴ�! \n");
	printf("\n");
	while (1) {
		printf("Choose One [h: hits, s:Stay, d: Double down]\n");
		scanf("%c", &choosewhat);
		scanf("%c", &choosewhat);

		if (choosewhat == 's') { //�������� ��� ���̻� ī�带 �����ʴ´�
			printf("������! ���� �����մϴ�\n");
			turn++;
			break;  //�� ����

		}
		else if (choosewhat == 'd') { //����ٿ��� ���,
			
			printf("\n");
			if ((money > playerbet) && (turn == 1))
			{    //�� ���ǿ����� ���డ��
				printf("����ٿ�! ���ñݾ��� �ι�� �ø��� ī�带 ���� �� �޽��ϴ�\n");
				playerbet = playerbet * 2; //���ñݾ��� �ι�� �ø���
				newcard = cardspled(); //ī�� ����ޱ�
				my_count = my_count + 1; //�����ϰ� �ִ� ī�� ������ �þ
				my_num[my_count - 1] = newcard;  //���λ��� ī�带 ����ī��迭�� �־���
				turn++;

				//���� ī����� ���
				printf("Dealer :\n");
				print_card(BACK); //������ ù��° ī��� ���ܼ� ������
				printf("     ");
				print_card(deal_num[1]); //�ι�° ī�� ���
				printf("Player :\n");   //���� ���� ī�� ���
				for (i = 0; i < 6; i++) {
					print_card(my_num[i]);
				}

				for (i = 0; i < 6; i++) {  //A�� J,Q,K�� �ִ� ��� ���ĺ��� ���ڷ� ��ȯ������
					my_num2[i] = cardpoint(my_num[i]);
				}
				if (pointsum(my_num2) > 21) { //ī������Ʈ���� ���� 21���� Ŀ�� ����Ʈ �� ��Ȳ
					printf(" Bust !! ������ ���Դϴ�\n");
					bust_1 = 1;   //����Ʈ�Ǿ� ����Ǿ��ٴ� ��
					break;
				}
				break; //�÷��̾��� ���� ����
			}
			else {  //����ٿ� ������ �������� �ʴ� ��Ȳ
				printf("����ٿ��� �Ұ����մϴ�\n"); //�׸��� �ٽù޾ƾߵ�
			}
		}
		else if (choosewhat == 'h') {
			printf("��Ʈ! ī�带 ���� �� �޽��ϴ�\n");
			printf("\n");
			newcard = cardspled();//ī�� ������ޱ�
			my_count = my_count + 1; //�����ϰ� �ִ� ī�� ������ �þ
			my_num[my_count - 1] = newcard;  //���λ��� ī�带 ����ī��迭�� �־���
											 //����ī�� ���
			printf("Dealer :\n");
			print_card(BACK); //������ ù��° ī��� ���ܼ� ������
			printf("    ");
			print_card(deal_num[1]); //�ι�° ī�� ���
			printf("\n");
			printf("Player :\n");  // �÷��̾����� ���� ���� �ִ� ��� ī�� ���
			for (i = 0; i < my_count; i++) {
				print_card(my_num[i]);
			}
			printf("\n");
			for (i = 0; i < deal_count; i++) {  //A�� J,Q,K�� ���ڷ� ��ȯ���Ѽ� �ֵ��̹迭�� �־���
				deal_num2[i] = cardpoint(deal_num[i]);
			}
			if (pointsum(deal_num2) > 21) { //����Ʈ �� ��Ȳ
				printf(" Bust !! ������ ���Դϴ�\n");
				bust_1 = 1;
				break;
			}

		}



	}
	return bust_1;  //����Ʈ���� �ֵ��̹迭�� �Ѱ�����ϴ°ɱ�

}



int dealerturn(int my_num[6], int *my_num2, int *deal_num, int *deal_num2, int my_count, int deal_count) {
	int i;
	int newcard;
	int bust_2 = 0;
	//int my_num[6];
	//int deal_num[6];
	//int deal_num2[6];
	printf(" Dealer�� ���Դϴ�!!\n ");

	while (1) {
		//���� ī�����
		printf("Delaer :\n");
		for (i = 0; i < 2; i++) { //����� ī�带 �����Ͽ� �� �����ش�.
			print_card(deal_num[i]);
		}
		printf("\n");
		// �÷��̾�ī�嵵 ���
		printf("Player :\n");
		for (i = 0; i < 6; i++) {
			print_card(my_num[i]);
		}
		printf("\n");
		////////////////////////////////////
		for (i = 0; i < 6; i++) {  //A�� J,Q,K�� ���ڷ� ��ȯ������
			deal_num2[i] = cardpoint(deal_num[i]);
		}

		if (pointsum(deal_num2) < 17) {  //ī���ջ�����Ʈ�� 16������ ��� hit
			printf("Hit !! ī�带 ����� �޽��ϴ�\n ");
			newcard = cardspled();//ī�� ������ޱ�
			deal_count = deal_count + 1; //�����ϰ� �ִ� ī�� ������ �þ
			deal_num[deal_count - 1] = newcard;  //���λ��� ī�带 ����ī��迭 �ڿ� �־���

		}

		else if ((pointsum(deal_num2) >= 17) && (pointsum(deal_num2) <= 21))
		{ //17�̻��̵� ����Ʈ�� �ƴѻ�Ȳ
			printf("Stay !!\n ");
			break;
		}
		else // (pointsum(deal_num) > 21)  //����Ʈ �� ��Ȳ
		{
			printf(" Bust !! �÷��̾��� ���Դϴ�\n");
			bust_2 = 1;  //����Ʈ�Ǿ� �����ٴ� ǥ��
			break;
		}
	}
	return bust_2;

}

