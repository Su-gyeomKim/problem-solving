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

int cal_point(int *arr);
int cardspled();
int* carddeck();
int p_turn();
int d_turn();
void start();

int main(void)
{
	printf("===================================\n\t���� ������ �����մϴ�\n===================================\n");

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
	if (card == BACK)		printf("�Ƣ�");
	else		printf("%s%2s\t", card_suit[card / 13], card_num[card % 13]);
}

int cardspled() { //ī�� ���徿 ������ �����ִ� �Լ�  //���������� ��� �Ⱦ����� ���
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
	return deck; //deck�迭�� ����
}

int cal_point(int *arr) {
	int sum = 0;
	for (int i = 0; i < sizeof(arr); i++) sum += arr[i];
	return sum;
}

void start() {
	int d_c[6]; //������ ī���
	int p_c[6]; //�÷��̾��� ī���
	int d_p[6];//����Ʈ���ڼ��°����� ���� deal_num�� �ֵ��̹迭, A,J,K,Q�� ������� ���ڷ� ��ȯ�Ǿ��
	int p_p[6];// ����Ʈ���ڼ��°����� ���� my_num�� �ֵ��̹迭,A,J,K,Q�� ���������ڷ� ��ȯ�Ǿ��

	money = 200; //�����ݾ�
	int bet = 0;  //�÷��̾��� ���øӴ�

	int turn = 1; //��Ƚ��
	int d_cnt = 0;  //������ ī�尳��
	int p_cnt = 0;   //�÷��̾��� ī���
	int i = 0; //while�� �˻縦 ���� ���� ����
	int bust_p = 0;  //����Ʈ�Ǿ� �������� Ȯ�ο����� ���� ����
	int bust_d = 0;
	int cnt = 0; //ī�嵦���� ���� ������ ī�尡 ������������

	printf(" CASH : %d\n", money);
	printf(" �󸶸� �����Ͻðڽ��ϱ�?\n ");
	while (1) {
		scanf("%d", &bet);
		if (bet > money) 			printf("���� �ݾ׺��� �����ϴ�. �ٽ� �Է����ּ���\n");
		else 			break;
	}

	printf("Bet : %d\n\n", bet);  //�����ϴ� �ݾ��� �Է¹޾Ƽ� ǥ������

	///////////////////���� ī�����
	printf("Dealer : \n");
	for (int i = 0; i <= turn; i++)			d_c[i] = cardspled();


	d_cnt = d_cnt + 2; //������ ī�尡 �����̵Ǿ���.
	print_card(BACK); //ù��° ī��� ���ܼ� ������
	printf("    ");	print_card(d_c[1]); /*�ι�° ī�� ���*/	printf("\n");

	////////////// �÷��̾�ī�����
	printf("Player : \n");

	for (int i = 0; i <= turn; i++)			p_c[i] = cardspled();
	for (int i = 0; i <= turn; i++)			print_card(p_c[i]);
	p_cnt = p_cnt + 2;   /*�÷��̾��� ���� ī�尡 ������ �Ǿ��ٴ� ��.*/	printf("\n");

	//�������� Ȯ��
	if (cal_point(p_c) == 21)
	{
		bet *= 2.5; //�¸��Ұ�� ���ñݾ��� �ι踦 �����ް�, �÷��̾�� 50�ۼ�Ʈ�� �߰��� ��´�.
		printf(" Black Jack !! �¸��߽��ϴ�\n %d�� �����޽��ϴ�\n", bet);
		exit;
	}

	bust_p = p_turn();
	bust_d = d_turn();

	if (!bust_p && !bust_d) { //�Ѵ� bust���� �ʰ� ������ ���� �����ٸ� ����Ʈ��
		printf("������ ���� ��� �������ϴ�\nDealer�� ����Ʈ : %d\nplayer�� ����Ʈ : %d\n", cal_point(d_p), cal_point(p_p));
		if (cal_point(p_p) > cal_point(d_p)) { money *= 2;				printf("player�� �¸��Դϴ�!\n "); }
		else if (cal_point(d_p) > cal_point(p_p)) { money -= bet;		printf("dealer�� �¸��Դϴ�!\n ���ñݾ��� �Ҿ� %d��ŭ�� �ݾ��� ���ҽ��ϴ�", money); }
		else				printf("���º��Դϴ�!\n ");
	}
	

}  //start �Լ���

int p_turn(int Turn) {
	char	input;
	printf("player�� ���Դϴ�! \n\n");
	while (1) {
		printf("Choose One [h: hits, s:Stay, d: Double down]\n");
		scanf("%c", &input);

		if (input == 's') { //�������� ��� ���̻� ī�带 �����ʴ´�
			printf("������! ���� �����մϴ�\n");
			Turn++;
			break;  //�� ����
		}
}

int d_turn() {

}