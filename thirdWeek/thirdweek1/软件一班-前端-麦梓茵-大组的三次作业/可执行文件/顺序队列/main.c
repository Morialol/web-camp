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
        printf("�����������ģ�\n");
        printf("1.��ʼ������\n");
        printf("2.��Ӳ���\n");
        printf("3.���Ӳ���\n");
        printf("4.�ж϶����Ƿ�Ϊ��\n");
        printf("5.�ж϶����Ƿ���\n");
        printf("6.�鿴��ͷԪ��\n");
        printf("7.ȷ�����г���\n");
        printf("8.��ն���\n");
        printf("9.���ٶ���\n");
        printf("10.������������\n");
        printf("0.�˳�ϵͳ\n");
        printf("*********************\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1:InitAQueue(&Q);break;
            case 2:printf("�������Ԫ�أ�");scanf("%d",&data);
                   if(EnAQueue(&Q,&data)) printf("��ӳɹ���\n");break;
            case 3:if(DeAQueue(&Q)) printf("���ӳɹ���\n");break;
            case 4:if(IsEmptyAQueue(&Q)) printf("Ϊ�գ�\n");
                   else printf("��Ϊ�գ�\n");break;
            case 5:if(IsFullAQueue(&Q)) printf("������\n");
                   else printf("������\n");break;
            case 6:if(GetHeadAQueue(&Q, &e)) printf("%d\n",e);break;
            case 7:printf("����Ϊ��%d\n",LengthAQueue(&Q));break;
            case 8:ClearAQueue(&Q);break;
            case 9:DestoryAQueue(&Q);break;
            case 10:if(TraverseAQueue(&Q, &foo)) printf("�ɹ���\n");break;
            default :break;
        }
    }
    return 0;
}
