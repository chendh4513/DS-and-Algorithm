#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"

#define MIN_PER_HR 60.0

/* �Ƿ����¿ͻ�����*/
bool NewCustomer(double x);

/* ��д�˿���Ϣ*/
Item CustomerTime(long when);

int main(void)
{
	Queue line; //�ȴ�����
	Item temp;  //��ǰ�����Ĺ˿�
	int hours; //ģ���Сʱ��
	int perhour; //ÿСʱƽ���˿���Ŀ
	long cycle, cyclelimit; //��ʱ�������Է���Ϊ��λ������ʱ������
	long turnaways = 0; //���ܿͻ���
	long customers = 0; //�����й˿�����
	long served = 0; //�ѷ��������
	long sum_line = 0; //�ۼƶ����ܳ�
	int served_time = 0; //��ǰ�˿ͻ������ʱ��
	double min_per_cust; //�˿͵�����ƽ��ʱ��
	long line_wait = 0; //�����ۼ��ܵȴ�ʱ��

	InitQueue(&line);
	srand((unsigned int)time(0));
	printf("���в���");
	printf("������ģʽСʱ����");
	scanf_s("%d", &hours);
	cyclelimit = MIN_PER_HR * hours;
	printf("������ƽ��ÿСʱ�����Ŀͻ�������");
	scanf_s("%d", &perhour);
	min_per_cust = MIN_PER_HR / perhour;

	for (cycle = 0; cycle < cyclelimit; cycle++)
	{
		if (NewCustomer(min_per_cust))//�Ƿ����¿ͻ�����
		{
			if (QueueIsFull(&line))//�ͻ���������
				turnaways++;
			else//�ͻ�����δ�� �������
			{
				customers++;
				temp = CustomerTime(cycle);
				Enqueue(temp, &line);
			}
		}
		if (served_time <= 0 && !QueueIsEmpty(&line))//��һ���ͻ��Է����꣬�Ӷ����г���һ���ͻ���ʼ����
		{
			DeQueue(&temp, &line);
			served_time = temp.processtime;
			line_wait += cycle - temp.arrive;
			served++;
		}
		if (served_time > 0)//�ͻ�δ�����꣬��������
			served_time--;
		sum_line += QueueLen(&line);
	}
	if (customers > 0)
	{
		printf("�ۼƽ��ܹ˿�����%1d\n", customers);
		printf("�ۼƷ���ͻ�����%1d\n", served);
		printf("�ۼƾܾ��û�����%1d\n", turnaways);
		printf("ƽ���ͻ����г��ȣ�%.2f\n", (double)sum_line / cyclelimit);
		printf("ƽ���ͻ��ȴ�ʱ����%.2f\n", (double)line_wait / served);
	}
	else
		printf("δ�пͻ�������\n");
	EmptyTheQueue(&line);
	puts("�ټ���");

	return 0;
}

bool NewCustomer(double x)
{
	if (rand() * x / RAND_MAX < 1)
		return true;
	else
		return false;
}

Item CustomerTime(long when)
{
	Item cust;

	cust.arrive = when;
	cust.processtime = rand() % 3 + 1;

	return cust;
}