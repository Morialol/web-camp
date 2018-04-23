#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void InitLQueue(LQueue *Q)//��ʼ��
{
    Q->front=NULL;
    Q->rear=NULL;
    Q->data_size=0;
    printf("��ʼ���ɹ���\n");
}

Status EnLQueue(LQueue *Q, int *data)//���
{
    Node *p;
    p=(Node *)malloc(sizeof(Node));
    p->data=*data;
    p->next=NULL;
    if(Q->rear!=NULL) Q->rear->next=p;
    Q->rear=p;
    if(Q->front == NULL) Q->front=p;
    Q->data_size++;
    printf("%d",p->data);
    return TRUE;
}

Status DeLQueue(LQueue *Q)//����
{
    if (Q->rear==NULL)
    {
        printf("����Ϊ��!\n");
        return FALSE;
    }
    else if ( Q->front==Q->rear&&Q->rear != NULL)
    {
        printf("���ӵ�������%d\n", Q->front->data);
        Q->front =NULL;
        Q->rear = NULL;
    }
    else
    {
        printf("���ӵ�������:");
        printf("%d\n",Q->front->data);
        Q->front = Q->front->next;
    }
    Q->data_size--;
    return TRUE;
}

Status IsEmptyLQueue(const LQueue *Q)//�ж��Ƿ�Ϊ��
{
    if(Q->rear==NULL) return TRUE;
    else return FALSE;
}

int LengthLQueue(LQueue *Q)//ȷ�����г���
{
    return Q->data_size;
}


void DestoryLQueue(LQueue *Q)//���ٶ���
{
    if (Q->front == Q->rear == NULL)
    {
        printf("����Ϊ��\n");
    }
    else if (Q->rear == Q->front != NULL)
        free(Q);
    else
    while (Q->front != NULL)
   {
        free(Q->front);
        Q->front = Q->front->next;
   }
        printf("�����Ѿ�����!\n");
}

Status GetHeadLQueue(LQueue *Q, int *e)//�鿴��ͷԪ��
{
    if(Q->front == NULL)
    {
        printf("�����ѿ�������Ԫ�س����У�\n");
        return FALSE;
    }
    else
    {
        e = Q->front->data;
        return TRUE;
    }
}

void ClearLQueue(LQueue *Q)//��ն���
{
    Q->front=NULL;
    Q->rear=NULL;
    Q->data_size=0;
    printf("�����\n");
}

Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))//������������
{
    Node *f,*r;
    if(Q->front == NULL)
    {
        printf("�����ѿ�������Ԫ�س����У�\n");
        return FALSE;
    }
    f = (Node*)malloc(sizeof(Node));
    r = (Node*)malloc(sizeof(Node));
    f= Q->front;
    r = Q->rear;
    if (r == NULL) printf("����Ϊ��!\n");
    else
        while (f != NULL)
        {
            printf("%d ",f->data);
            f = f->next;
        }
    return TRUE;
}
