#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"

#define MIN_PER_HR 60.0

/* 是否有新客户到来*/
bool NewCustomer(double x);

/* 填写顾客信息*/
Item CustomerTime(long when);

int main(void)
{
	Queue line; //等待队列
	Item temp;  //当前到来的顾客
	int hours; //模拟的小时数
	int perhour; //每小时平均顾客数目
	long cycle, cyclelimit; //计时器器（以分钟为单位），计时器上限
	long turnaways = 0; //被拒客户数
	long customers = 0; //队列中顾客数量
	long served = 0; //已服务的数量
	long sum_line = 0; //累计队列总长
	int served_time = 0; //当前顾客还需服务时间
	double min_per_cust; //顾客到来的平均时间
	long line_wait = 0; //队列累计总等待时间

	InitQueue(&line);
	srand((unsigned int)time(0));
	printf("队列测试");
	printf("请输入模式小时数：");
	scanf_s("%d", &hours);
	cyclelimit = MIN_PER_HR * hours;
	printf("请输入平均每小时到来的客户数量：");
	scanf_s("%d", &perhour);
	min_per_cust = MIN_PER_HR / perhour;

	for (cycle = 0; cycle < cyclelimit; cycle++)
	{
		if (NewCustomer(min_per_cust))//是否有新客户到来
		{
			if (QueueIsFull(&line))//客户队列已满
				turnaways++;
			else//客户队列未满 加入队列
			{
				customers++;
				temp = CustomerTime(cycle);
				Enqueue(temp, &line);
			}
		}
		if (served_time <= 0 && !QueueIsEmpty(&line))//上一个客户以服务完，从队列中出队一个客户开始服务
		{
			DeQueue(&temp, &line);
			served_time = temp.processtime;
			line_wait += cycle - temp.arrive;
			served++;
		}
		if (served_time > 0)//客户未服务完，继续服务
			served_time--;
		sum_line += QueueLen(&line);
	}
	if (customers > 0)
	{
		printf("累计接受顾客数：%1d\n", customers);
		printf("累计服务客户数：%1d\n", served);
		printf("累计拒绝用户数：%1d\n", turnaways);
		printf("平均客户队列长度：%.2f\n", (double)sum_line / cyclelimit);
		printf("平均客户等待时长：%.2f\n", (double)line_wait / served);
	}
	else
		printf("未有客户到来！\n");
	EmptyTheQueue(&line);
	puts("再见！");

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