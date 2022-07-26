#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
struct node
{
    char name[20];
    char phone[11];
    char address[100];
    char pass[50];
    char profession[50];
    char id[10];
    struct node *next;
};
struct node *head=NULL;

int addvol()
{
    getchar();
    printf("*********** Apply to become volunteer *************\n");
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    printf("Volunteer Name: ");
    gets(temp -> name);
    printf("Phone number: ");
    gets(temp -> phone);
    printf("Volunteer profession: ");
    gets(temp->profession);
    printf("Volunteer id: ");
    gets(temp -> id);
    printf("Address : ");
    gets(temp -> address);
    char password[128], c;
    int index = 0;

    printf("Enter Password : ");
    while((c = getch()) != 13)
    {
        if(index < 0)
            index = 0;
        if(c == 8)
        {
            putch('\b');
            putch(NULL);
            putch('\b');
            index--;
            continue;
        }
        password[index++] = c;
        putch('*');
    }
    password[index] = '\0';
    strcpy(temp->pass,password);
    temp->next = head;
    head = temp;
    return 0;
}
int update()
{
    char volI[50],idd[20];
    int found = 0;
    struct node *temp = head;
    printf("\n******************* Update information **********************\n");
    printf("Volunteer Id :");
    scanf("%s",idd);
    char password[128], c;
    int index = 0;

    printf("Enter Password : ");
    while((c = getch()) != 13)
    {
        if(index < 0)
            index = 0;
        if(c == 8)
        {
            putch('\b');
            putch(NULL);
            putch('\b');
            index--;
            continue;
        }
        password[index++] = c;
        putch('*');
    }
    password[index] = '\0';
    strcpy(volI,password);
    fflush(stdin);
    while(temp!=NULL)
    {
        if(!strcmp(volI,temp->pass))
        {
            found = 1;
        }
        if(found!=1)
        {
            temp= temp->next;
            if(temp->next==NULL)
            {
                printf("\nNO data found\n");
            }
            continue;
        }
        if(found==1)
        {
            printf("\nOld data:\n");
            printf("Volunteer Name : %s\n",temp->name);
            printf("Profession : %s\n",temp->profession);
            printf("Volunteer Id : %s\n",temp->id);
            printf("Address : %s\n",temp->address);
            //printf("Phone : %s\n",temp->phone);
            printf("\n------------------------------------\n");
            printf("\n------------------------------------\n");
            printf("New Data:\n\n\n ");
            printf("Volunteer Name: ");
            scanf("%s",temp->name);
            printf("Phone number: ");
            scanf("%s",temp -> phone);
            fflush(stdin);
            printf("Volunteer profession: ");
            scanf("%s",temp->profession);
            printf("Address : ");
            fflush(stdin);
            scanf("%s",temp->address);
            printf("\nData Updated\n");
            break;
        }
        /*else{
            printf("No data with id %s !!\n",volI);
         }*/
    }
    int p;
    printf("\n Enter 1 to goto the main manue and 0 to exit : ");
    scanf("%d",&p);
    if(!p)
    {
        exit(0);
    }
    return 0;
}
void listof()
{
    struct node *temp = head;
    printf(" *#*#*#*#*#*#*#*# All Volunteers *#*#*#*#*#*#*#*#*#*# \n");
    if(head==NULL){
        printf("\nNo data avaiable\n");
    }
    while(temp!=NULL)
    {
        printf("Volunteer Name : %s\n",temp->name);
        printf("Profession : %s\n",temp->profession);
        printf("Volunteer Id : %s\n",temp->id);
        printf("Address : %s\n",temp->address);
        printf("Phone : %s\n",temp->phone);
        printf("\n------------------------------------\n");
        temp = temp->next;
    }
    int p;
    printf("\n Enter 1 to goto the main manue and 0 to exit : ");
    scanf("%d",&p);
    if(!p)
    {
        exit(0);
    }
}
int rmv() //remove data
{
    char volI[50];
    int found = 0;
    struct node *temp = head, *preTemp;
    getchar();
    printf("\n--------- Remove volunteer ID -----------\n");
    char password[128], c;
    int index = 0;

    printf("Enter Password : ");
    while((c = getch()) != 13)
    {
        if(index < 0)
            index = 0;
        if(c == 8)
        {
            putch('\b');
            putch(NULL);
            putch('\b');
            index--;
            continue;
        }
        password[index++] = c;
        putch('*');
    }
    password[index] = '\0';
    strcpy(volI,password);
    if(!strcmp(volI,temp->pass))
    {
        head = temp->next;
        free(temp);
        printf("\nData Removed\n");
        int p;
        printf("\nEnter 1 to goto the main manue and 0 to exit : ");
        scanf("%d",&p);
        if(!p)
        {
            exit(0);
        }
        return 0;

    }
    while(temp!=NULL)
    {
        if(strcmp(temp->pass,volI)==0)
        {
            found = 1;
            break;
        }
        preTemp = temp;
        temp = temp->next;

    }
    if(found = 1)
    {
        preTemp->next = temp->next;
        free(temp);
        printf("\nData Removed\n");
    }
    else
    {
        printf("No data found with id %s !\n");
    }
    int p;
    printf("\nEnter 1 to goto the main manue and 0 to exit : ");
    scanf("%d",&p);
    if(!p)
    {
        exit(0);
    }
    return 0;
}
int admin()
{
    char admin[]="saiful";
    char password[128], c;
    int index = 0;

    printf("Enter Password : ");
    while((c = getch()) != 13)
    {
        if(index < 0)
            index = 0;
        if(c == 8)
        {
            putch('\b');
            putch(NULL);
            putch('\b');
            index--;
            continue;
        }
        password[index++] = c;
        putch('*');
    }
    password[index] = '\0';
    if(!strcmp(password,admin))
    {
        struct node *temp = head;
        printf("\m*#*#*#*#*#*#*#*# All Volunteers *#*#*#*#*#*#*#*#*#*# \n");
        while(temp!=NULL)
        {
            printf("Volunteer Name : %s\n",temp->name);
            printf("Profession : %s\n",temp->profession);
            printf("Volunteer Id : %s\n",temp->id);
            printf("Address : %s\n",temp->address);
            //printf("Phone : %s\n",temp->phone);
            printf("\n------------------------------------\n");
            temp = temp->next;
        }
        char volI[50];
        int found = 0;
        struct node *preTemp;
        temp=head;
        getchar();
        printf("\n--------- Remove volunteer ID -----------\n");
        printf("Whose ID do you want to remove?\nID : ");
        gets(volI);
        if(!strcmp(volI,temp->id))
        {
            head = temp->next;
            free(temp);
            printf("\nData Removed\n");
            int p;
            printf("\nEnter 1 to goto the main manue and 0 to exit : ");
            scanf("%d",&p);
            if(!p)
            {
                exit(0);
            }
            return 0;

        }
        while(temp!=NULL)
        {
            if(strcmp(temp->pass,volI)==0)
            {
                found = 1;
                break;
            }
            preTemp = temp;
            temp = temp->next;

        }
        if(found = 1)
        {
            preTemp->next = temp->next;
            free(temp);
            printf("\nData Removed\n");
        }
        else
        {
            printf("No data found with id %s !\n");
        }
        int p;
        printf("\nEnter 1 to goto the main manue and 0 to exit : ");
        scanf("%d",&p);
        if(!p)
        {
            exit(0);
        }
    }
    else
    {
        printf("\nWrong password!!!\n");
    }
    return 0;
}
int manue(int op)
{
    switch(op)
    {
    case 1:
        system("cls");
        system("COLOR 0D");
        addvol();
        break;
    case 2:
        system("cls");
        update();
        break;
    case 3:
        system("cls");
        rmv();
        break;
    case 4:
        system("cls");
        listof();
        break;
    case 5:
        system("cls");
        admin();
        break;
    case 6:
        exit(0);
    default:
        system("cls");
        printf("\nInvalid selection\n");
        int p;
        printf("\nEnter 1 to goto the main manue and 0 to exit : ");
        scanf("%d",&p);
        if(!p)
        {
            exit(0);
        }
        break;
    }
    return 0;
}
int main()
{
    while(1)
    {
        system("cls");
        system("COLOR 0A");
        printf("#################### Main menu ########################\n");
        printf("-------------------------------------------------------\n");
        printf("########## 1. Become a volunteer               ########\n");
        printf("########## 2. Update volunteer information     ########\n");
        printf("########## 3. Remove volunteer data            ########\n");
        printf("########## 4. volunteer list                   ########\n");
        printf("########## 5. Admin control                    ########\n");
        printf("########## 6. Exit                             ########\n");
        printf("#######################################################\n");
        int op;
        printf("\nEnter your choice: ");
        scanf("%d",&op);
        manue(op);
    }
    return 0;
}
