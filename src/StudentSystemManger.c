#include "StudentSystemManger.h"

int main()
{
    int choose;

    Node *head = malloc(sizeof(Node));
    head->next = NULL;


    
    while(1)
    {
        Welcome();

        scanf("%d",&choose);

        switch (choose)
        {
        case 1:
            InputStudent(head);
            break;
        case 2:
            PrintStudent(head);
            break;
        case 3:
            DeleteStudent(head);
        case 4:
            CountStudent(head);
        default:
            break;
        }


        system("cls");
    }
    
    return 0;
}


void Welcome()
{
    printf("1.¼��ѧ����Ϣ\n");
    printf("2.��ӡѧ����Ϣ\n");
    printf("3.ɾ��ѧ��\n");
    printf("4.ͳ��ѧ����Ϣ\n");
    printf("**************\n");
    printf("ѡ��:");
}

void InputStudent(Node *head)
{   
    Node *new = malloc(sizeof(Node));
    //������Ϣ
    new->next = NULL;
    printf("������ѧ����ѧ�ţ��������ɼ�:");
    scanf("%d %s %d",&new->stu.stuNum,new->stu.name,&new->stu.score);

    Node *move = head;

    while( move->next != NULL)
    {
        move = move->next;
    }

    move->next = new;
    
}

void PrintStudent(Node *head)
{
    Node* move = head->next;

    while(move)
    {
        printf("ѧ��: %d \t ����:%s \t �ɼ�:%d \n",move->stu.stuNum,move->stu.name,move->stu.score);
        move = move->next;
    }

    system("pause");
}

void DeleteStudent(Node *head)
{
    printf("��������ҵķ�ʽ\n1.ѧ��\n2.����");

    int choose;
    scanf("%d",&choose);

    Node* move = head;

    
    switch(choose)
    {
        case 1:
            {
                printf("������Ҫɾ����ѧ��:");
                int dStu;
                scanf("%d",&dStu);

                while(move->next)
                {
                    if(move->next->stu.stuNum == dStu)
                    {
                        move->next = move->next->next;
                    }
                    move = move->next;
                }

             break;   
            }
        case 2:
            {
                printf("������Ҫɾ��������:");
                char dname[20];
                scanf("%s",dname);

                while(move->next)
                {
                    if(move->next->stu.name == dname)
                    {
                        move->next = move->next->next;
                    }
                    move = move->next;
                }

             break;   
            }
    }

}

void CountStudent(Node *head)
{
    int cont = 0;

    Node *move = head->next;

    while(move)
    {
        cont++;
        move = move->next;
    }

    printf("����%dѧ��\n",cont);
    system("pause");
}