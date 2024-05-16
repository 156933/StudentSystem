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
    printf("学生管理系统\n");
    printf("**************\n");
    printf("1.录入学生信息\n");
    printf("2.打印学生信息\n");
    printf("3.删除学生\n");
    printf("4.统计学生信息\n");
    printf("5.修改学生信息\n");
    printf("6.退出系统\n");
    printf("7.排序\n");
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
    SaveStdent(head);
    
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
                SaveStdent(head);

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

    printf("共有%d学生\n",cont);
    system("pause");
}


void ReviseStudent(Node *head)
{
    int dNum;
    Node *move = head->next;
    PrintStudent(head);
    int j = 0; //判断是否有这个人
    
    printf("请输入你要修改学生的学号:");
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
        printf("请输入你要修改的内容(学号 姓名 成绩):");
        scanf("%d %s %d",&move->stu.stuNum,move->stu.name,&move->stu.score);
        SaveStdent(head);
        system("pause");
        printf("修改成功\n");
    }else{
        printf("查无此人\n");
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
            printf("保存失败\n");
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
        printf("文件不存在\n");
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
    printf("载入完成\n");
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

