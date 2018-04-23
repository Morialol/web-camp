#include <stdio.h>
#include <stdlib.h>
#include "queue.c"

int main()
{
    LQueue Q;
    int n=1;
    int data;int e;
    void (*foo)(void *q);
    while(n!=0)
    {   printf("**********************\n");
        printf("输入你想做的：\n");
        printf("1.初始化队列\n");
        printf("2.入队操作\n");
        printf("3.出队操作\n");
        printf("4.判断队列是否为空\n");
        printf("5.查看队头元素\n");
        printf("6.确定队列长度\n");
        printf("7.清空队列\n");
        printf("8.销毁队列\n");
        printf("9.遍历函数操作\n");
        printf("0.退出程序\n");
        printf("***********************\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:InitLQueue(&Q);break;
            case 2:printf("输入入队元素：");scanf("%d",&data);
                   if(EnLQueue(&Q, &data)) printf("入队成功！\n");break;
            case 3:if(DeLQueue(&Q)) printf("出队成功！\n");break;
            case 4:if(IsEmptyLQueue(&Q)) printf("为空！");
                   else printf("不为空！\n");break;
            case 5:if(GetHeadLQueue(&Q, &e)) printf("%d",e);break;
            case 6:printf("长度为：%d\n",LengthLQueue(&Q));break;
            case 7:ClearLQueue(&Q);break;
            case 8:DestoryLQueue(&Q);break;
            case 9:if(TraverseLQueue(&Q, &foo)) printf("成功！\n");break;
            default :break;
        }
    }
    return 0;
}
