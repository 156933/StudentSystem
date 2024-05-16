#include "StudentSystemManger.h"

int main()
{
    int choose;

    Node *head = malloc(sizeof(Node));
    head->next = NULL;

    LoadStudent(head);
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
            break;
        case 4:
            CountStudent(head);
            break;
        case 5:
            ReviseStudent(head);
            break;
        case 6:
            return 0;
            break;
        case 7:
            SortScore(head);
            break;
        default:
            break;
        }


        system("cls");
    }
    
    return 0;
}


void Welcome()
{   
    printf("**************\n");
    printf("ѧ������ϵͳ\n");
    printf("**************\n");
    printf("1.¼��ѧ����Ϣ\n");
    printf("2.��ӡѧ����Ϣ\n");
    printf("3.ɾ��ѧ��\n");
    printf("4.ͳ��ѧ����Ϣ\n");
    printf("5.�޸�ѧ����Ϣ\n");
    printf("6.�˳�ϵͳ\n");
    printf("7.����\n");
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
    SaveStdent(head);
    
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
                SaveStdent(head);

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
                SaveStdent(head);

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


void ReviseStudent(Node *head)
{
    int dNum;
    Node *move = head->next;
    PrintStudent(head);
    int j = 0; //�ж��Ƿ��������
    
    printf("��������Ҫ�޸�ѧ����ѧ��:");
    scanf("%d",&dNum);

    while(move)
    {
        if(move->stu.stuNum == dNum)
        {
            j = 1;
            break;
        }
        move = move->next;
    }

    if( j == 1)
    {
        printf("��������Ҫ�޸ĵ�����(ѧ�� ���� �ɼ�):");
        scanf("%d %s %d",&move->stu.stuNum,move->stu.name,&move->stu.score);
        SaveStdent(head);
        system("pause");
        printf("�޸ĳɹ�\n");
    }else{
        printf("���޴���\n");
        system("pause");
    }
}

void SaveStdent(Node *head)
{
    FILE *file = fopen("./student.info","w");

    Node *move = head->next;

    while(move)
    {
        if((fwrite(&move->stu,sizeof(Student),1,file))!=1)
        {
            printf("����ʧ��\n");
            return;
        };
        move = move->next;
    }
    fclose(file);
}

void LoadStudent(Node *head)
{
    FILE *file = fopen("./student.info","r");

    if(!file)
    {
        printf("�ļ�������\n");
        return;
    }

    Node *new = malloc(sizeof(Node));
    new->next = NULL;

    Node *move = head;

    while(fread(&new->stu,sizeof(Student),1,file)==1)
    {
        move->next = new;
        move = new;

        new = malloc(sizeof(Node));
        new->next = NULL;
    }
    free(new);
    fclose(file);
    printf("�������\n");
}


void SortScore(Node* head)
{
    for(Node* turn = head->next;turn->next != NULL ; turn = turn->next)
    {
        for(Node *move = head->next;move->next!=NULL ; move= move->next)
        {
            if(move->stu.score > move->next->stu.score)
            {
                int temp = move->stu.score;
                move->stu.score = move->next->stu.score;
                move->next->stu.score = temp;
            }
        }
    }
    SaveStdent(head);
}

