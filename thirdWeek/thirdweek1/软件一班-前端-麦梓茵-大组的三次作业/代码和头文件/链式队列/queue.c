#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void InitLQueue(LQueue *Q)//初始化
{
    Q->front=NULL;
    Q->rear=NULL;
    Q->data_size=0;
    printf("初始化成功！\n");
}

Status EnLQueue(LQueue *Q, int *data)//入队
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

Status DeLQueue(LQueue *Q)//出队
{
    if (Q->rear==NULL)
    {
        printf("队列为空!\n");
        return FALSE;
    }
    else if ( Q->front==Q->rear&&Q->rear != NULL)
    {
        printf("出队的数据是%d\n", Q->front->data);
        Q->front =NULL;
        Q->rear = NULL;
    }
    else
    {
        printf("出队的数据是:");
        printf("%d\n",Q->front->data);
        Q->front = Q->front->next;
    }
    Q->data_size--;
    return TRUE;
}

Status IsEmptyLQueue(const LQueue *Q)//判断是否为空
{
    if(Q->rear==NULL) return TRUE;
    else return FALSE;
}

int LengthLQueue(LQueue *Q)//确定队列长度
{
    return Q->data_size;
}


void DestoryLQueue(LQueue *Q)//销毁队列
{
    if (Q->front == Q->rear == NULL)
    {
        printf("队列为空\n");
    }
    else if (Q->rear == Q->front != NULL)
        free(Q);
    else
    while (Q->front != NULL)
   {
        free(Q->front);
        Q->front = Q->front->next;
   }
        printf("队列已经销毁!\n");
}

Status GetHeadLQueue(LQueue *Q, int *e)//查看队头元素
{
    if(Q->front == NULL)
    {
        printf("队列已空无数据元素出队列！\n");
        return FALSE;
    }
    else
    {
        e = Q->front->data;
        return TRUE;
    }
}

void ClearLQueue(LQueue *Q)//清空队列
{
    Q->front=NULL;
    Q->rear=NULL;
    Q->data_size=0;
    printf("已清空\n");
}

Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))//遍历函数操作
{
    Node *f,*r;
    if(Q->front == NULL)
    {
        printf("队列已空无数据元素出队列！\n");
        return FALSE;
    }
    f = (Node*)malloc(sizeof(Node));
    r = (Node*)malloc(sizeof(Node));
    f= Q->front;
    r = Q->rear;
    if (r == NULL) printf("队列为空!\n");
    else
        while (f != NULL)
        {
            printf("%d ",f->data);
            f = f->next;
        }
    return TRUE;
}
