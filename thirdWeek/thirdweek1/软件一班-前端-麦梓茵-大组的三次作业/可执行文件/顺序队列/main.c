#include <stdio.h>
#include <stdlib.h>
#include "queue.c"

int main()
{
    AQueue Q;
    int n=1;
    int data;int e;
    void (*foo)(void *q);
    while(n!=0)
    {
        printf("********************\n");
        printf("输入你想做的：\n");
        printf("1.初始化队列\n");
        printf("2.入队操作\n");
        printf("3.出队操作\n");
        printf("4.判断队列是否为空\n");
        printf("5.判断队列是否满\n");
        printf("6.查看队头元素\n");
        printf("7.确定队列长度\n");
        printf("8.清空队列\n");
        printf("9.销毁队列\n");
        printf("10.遍历函数操作\n");
        printf("0.退出系统\n");
        printf("*********************\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:InitAQueue(&Q);break;
            case 2:printf("输入入队元素：");scanf("%d",&data);
                   if(EnAQueue(&Q,&data)) printf("入队成功！\n");break;
            case 3:if(DeAQueue(&Q)) printf("出队成功！\n");break;
            case 4:if(IsEmptyAQueue(&Q)) printf("为空！\n");
                   else printf("不为空！\n");break;
            case 5:if(IsFullAQueue(&Q)) printf("不满！\n");
                   else printf("已满！\n");break;
            case 6:if(GetHeadAQueue(&Q, &e)) printf("%d\n",e);break;
            case 7:printf("长度为：%d\n",LengthAQueue(&Q));break;
            case 8:ClearAQueue(&Q);break;
            case 9:DestoryAQueue(&Q);break;
            case 10:if(TraverseAQueue(&Q, &foo)) printf("成功！\n");break;
            default :break;
        }
    }
    return 0;
}
