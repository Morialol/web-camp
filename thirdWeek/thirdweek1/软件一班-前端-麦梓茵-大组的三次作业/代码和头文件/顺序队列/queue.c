#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void InitAQueue(AQueue *Q)//��ʼ������
{
    Q->front = 0;
    Q->rear = 0;
    Q->data_size=0;
    printf("��ʼ���ɹ���\n");
}

Status EnAQueue(AQueue *Q, int *data)//��Ӳ���
{
    if ((Q->rear + 1) % MAXQUEUE == Q->front)//βָ���1׷��ͷָ�룬��־�����Ѿ�����
	{
		return FLASE;
	}
	Q->data[Q->rear] = *data;
	Q->rear = (Q->rear + 1) % MAXQUEUE;//�������ö�βָ��
	Q->data_size++;
	printf("%d ",*data);
	return TRUE;
}

Status DeAQueue(AQueue *Q)//���Ӳ���
{
    if (Q->rear == Q->front)//����Ϊ��
	{
	    printf("����Ϊ�գ�\n");
		return FLASE;
	}
	else if ( Q->front==Q->rear&&Q->rear != NULL)
    {
        printf("���ӵ�������%d\n", Q->data[Q->front]);
        Q->front = 0;
        Q->rear = 0;
    }
    else
    {
        printf("���ӵ�������:");
        printf("%d\n",Q->data[Q->front]);
        Q->front = (Q->front + 1) % MAXQUEUE;//�������ö�ͷָ��
    }
    Q->data_size--;
	return TRUE;
}

Status IsEmptyAQueue(const AQueue *Q)//�ж϶����Ƿ�Ϊ��
{
    if (Q->rear == Q->front) return TRUE;
    return FLASE;
}

Status IsFullAQueue(const AQueue *Q)//�ж϶����Ƿ���
{
    if ((Q->rear + 1) % MAXQUEUE == Q->front)//βָ���1׷��ͷָ�룬��־�����Ѿ�����
	{
		return FLASE;
	}
	else return TRUE;
}

Status GetHeadAQueue(AQueue *Q, int *e)//�鿴��ͷԪ��
{
    if(Q->data_size==0)
    {
        printf("����Ϊ�գ�\n");
        return FLASE;
    }
    else{
        *e=Q->data[Q->front];
        return TRUE;
    }
}

int LengthAQueue(AQueue *Q)//ȷ�����г���
{
    return Q->data_size;
}

void ClearAQueue(AQueue *Q)//��ն���
{
    Q->front=0;
    Q->rear=0;
    Q->data_size=0;
    printf("�����\n");
}

void DestoryAQueue(AQueue *Q)//���ٶ���
{
    while ( Q->front!= Q->rear)
    {
        free(&Q->data[Q->front]);
        Q->front=(Q->front+1)%MAXQUEUE;
    }
    printf("�����٣�\n");
}

Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))//������������
{
     int i=Q->front;
     printf("�������Ϊ��");
    while (i!=Q->rear)
     {
      printf("%5d",Q->data[i]);
      i++;
     }
     printf("\n");
     return TRUE;
}
