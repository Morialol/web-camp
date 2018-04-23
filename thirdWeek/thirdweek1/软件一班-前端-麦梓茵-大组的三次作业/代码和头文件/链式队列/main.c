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
        printf("�����������ģ�\n");
        printf("1.��ʼ������\n");
        printf("2.��Ӳ���\n");
        printf("3.���Ӳ���\n");
        printf("4.�ж϶����Ƿ�Ϊ��\n");
        printf("5.�鿴��ͷԪ��\n");
        printf("6.ȷ�����г���\n");
        printf("7.��ն���\n");
        printf("8.���ٶ���\n");
        printf("9.������������\n");
        printf("0.�˳�����\n");
        printf("***********************\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:InitLQueue(&Q);break;
            case 2:printf("�������Ԫ�أ�");scanf("%d",&data);
                   if(EnLQueue(&Q, &data)) printf("��ӳɹ���\n");break;
            case 3:if(DeLQueue(&Q)) printf("���ӳɹ���\n");break;
            case 4:if(IsEmptyLQueue(&Q)) printf("Ϊ�գ�");
                   else printf("��Ϊ�գ�\n");break;
            case 5:if(GetHeadLQueue(&Q, &e)) printf("%d",e);break;
            case 6:printf("����Ϊ��%d\n",LengthLQueue(&Q));break;
            case 7:ClearLQueue(&Q);break;
            case 8:DestoryLQueue(&Q);break;
            case 9:if(TraverseLQueue(&Q, &foo)) printf("�ɹ���\n");break;
            default :break;
        }
    }
    return 0;
}
