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
    printf("1.录入学生信息\n");
    printf("2.打印学生信息\n");
    printf("3.删除学生\n");
    printf("4.统计学生信息\n");
    printf("**************\n");
    printf("选择:");
}

void InputStudent(Node *head)
{   
    Node *new = malloc(sizeof(Node));
    //输入信息
    new->next = NULL;
    printf("请输入学生的学号，姓名，成绩:");
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
        printf("学号: %d \t 姓名:%s \t 成绩:%d \n",move->stu.stuNum,move->stu.name,move->stu.score);
        move = move->next;
    }

    system("pause");
}

void DeleteStudent(Node *head)
{
    printf("请输入查找的方式\n1.学号\n2.姓名");

    int choose;
    scanf("%d",&choose);

    Node* move = head;

    
    switch(choose)
    {
        case 1:
            {
                printf("请输入要删除的学号:");
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
                printf("请输入要删除的姓名:");
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

    printf("共有%d学生\n",cont);
    system("pause");
}