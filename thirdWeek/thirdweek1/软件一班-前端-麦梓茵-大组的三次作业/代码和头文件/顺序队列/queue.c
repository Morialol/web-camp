#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void InitAQueue(AQueue *Q)//初始化队列
{
    Q->front = 0;
    Q->rear = 0;
    Q->data_size=0;
    printf("初始化成功！\n");
}

Status EnAQueue(AQueue *Q, int *data)//入队操作
{
    if ((Q->rear + 1) % MAXQUEUE == Q->front)//尾指针加1追上头指针，标志队列已经满了
	{
		return FLASE;
	}
	Q->data[Q->rear] = *data;
	Q->rear = (Q->rear + 1) % MAXQUEUE;//重新设置队尾指针
	Q->data_size++;
	printf("%d ",*data);
	return TRUE;
}

Status DeAQueue(AQueue *Q)//出队操作
{
    if (Q->rear == Q->front)//队列为空
	{
	    printf("队列为空！\n");
		return FLASE;
	}
	else if ( Q->front==Q->rear&&Q->rear != NULL)
    {
        printf("出队的数据是%d\n", Q->data[Q->front]);
        Q->front = 0;
        Q->rear = 0;
    }
    else
    {
        printf("出队的数据是:");
        printf("%d\n",Q->data[Q->front]);
        Q->front = (Q->front + 1) % MAXQUEUE;//重新设置队头指针
    }
    Q->data_size--;
	return TRUE;
}

Status IsEmptyAQueue(const AQueue *Q)//判断队列是否为空
{
    if (Q->rear == Q->front) return TRUE;
    return FLASE;
}

Status IsFullAQueue(const AQueue *Q)//判断队列是否满
{
    if ((Q->rear + 1) % MAXQUEUE == Q->front)//尾指针加1追上头指针，标志队列已经满了
	{
		return FLASE;
	}
	else return TRUE;
}

Status GetHeadAQueue(AQueue *Q, int *e)//查看队头元素
{
    if(Q->data_size==0)
    {
        printf("队列为空！\n");
        return FLASE;
    }
    else{
        *e=Q->data[Q->front];
        return TRUE;
    }
}

int LengthAQueue(AQueue *Q)//确定队列长度
{
    return Q->data_size;
}

void ClearAQueue(AQueue *Q)//清空队列
{
    Q->front=0;
    Q->rear=0;
    Q->data_size=0;
    printf("已清空\n");
}

void DestoryAQueue(AQueue *Q)//销毁队列
{
    while ( Q->front!= Q->rear)
    {
        free(&Q->data[Q->front]);
        Q->front=(Q->front+1)%MAXQUEUE;
    }
    printf("已销毁！\n");
}

Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))//遍历函数操作
{
     int i=Q->front;
     printf("遍历结果为：");
    while (i!=Q->rear)
     {
      printf("%5d",Q->data[i]);
      i++;
     }
     printf("\n");
     return TRUE;
}
