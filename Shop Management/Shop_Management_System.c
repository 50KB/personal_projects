#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<windows.h>


//LOGIN:
struct person
{
    int id;
    char username[20];
    char password[20];
};
struct person A[10],S[10];
int user;
int currentid=-1;
FILE *r,*w,*a;
//CONTANTS:
typedef struct
{
    char name[20],code[20];
    float rate;
    int quantity;
}contant;
contant item;
contant content[20];
FILE *g ,*h,*zb;
j=0;

typedef struct s{
  int serial;
  char name[20];
  float rate;
  int quantity;
  float total;
}bill;
bill M[20];
int countpersonA()
{
    char ch;
    int lines = 0;
    r = fopen("FadminLogin.txt","r");
    while(!feof(r))
    {
        ch = fgetc(r);
        if(ch == '\n')
        {
            ++lines;
        }
    }
    fclose(r);
    return lines;
}

int countpersonS()
{
    char ch;
    int lines = 0;
    r = fopen("FselLogin.txt","r");
    while(!feof(r))
    {
        ch = fgetc(r);
        if(ch == '\n')
        {
            ++lines;
        }
    }
    fclose(r);
    return lines;
}

void registration()
{
    int asr;
   printf("\n\n");
   printf("\t\t\t\tPress 1: ADMIN REG\n");
   printf("\t\t\t\tPress 2: SELLER REG\n");
   printf("\t\t\t\tPress 3: MAIN MENU\n");
   printf("\t\t\t\tYOUR CHOICE(1/2/3):");
 scanf("%d",&asr);
 printf("\n\n");
switch(asr)
{
case 1:
    system("cls");
    adminreg();
    main();
    break;
case 2:
    system("cls");
    sellerreg();
    main();
    break;
case 3:
    system("cls");
     main();
    break;
}

}
void adminreg()
{
   printf("\n\t\t\t\t\tADMIN REGISTRATION\n\n");
        char pass[20];
w = fopen("FadminLogin.txt","a");

    user = countpersonA()+1;

   printf("\t\t\t\tEnter Username: ");
   scanf("%s",A[user].username);

   printf("\t\t\t\tEnter Password: ");
   scanf("%s",A[user].password);
   printf("\t\t\t\tConfirm Password: ");
   scanf("%s",pass);
     if(strcmp(A[user].password,pass)==0)
     {
    A[user].id = user;
    fprintf(w,"%d %s %s\n",user,A[user].username,A[user].password);
   printf("\n\t\t\t\t%s, Registration Successful! Your UserID: %d\n\n",A[user].username,user);
     }
     else
     {
   printf("\t\t\t\t\tPassword Doesn't Match!!!\n");
   printf("\t\t\t\t\t  Try Again!!!");
   printf("\n\n");
        system("pause");
        system("cls");
        adminreg();
     }
    fclose(w);
    LoadA();
}
void sellerreg()
{
    printf("\n\t\t\t\tSELLER REGISTRATION\n\n");
    char pass[20];
w = fopen("FselLogin.txt","a");

    user = countpersonS()+1;

    printf("\t\t\tEnter Username: ");
    scanf("%s",S[user].username);

    printf("\t\t\tEnter Password: ");
    scanf("%s",S[user].password);
    printf("\t\t\tEnter Password: ");
    scanf("%s",pass);
    if(strcmp(S[user].password,pass)==0)
    {
    S[user].id = user;
    fprintf(w,"%d %s %s\n",user,S[user].username,S[user].password);
    printf("\n\t\t\t%s, Registration Successful! Your UserID: %d\n\n",S[user].username,user);
    }
    else
    {
         printf("      \t\t\t\t\tPassword Doesn't Match!!! Try Again!!!");
         printf("\n\n");
         sellerreg();
    }
    fclose(w);
    LoadS();
}
void adminlogin()
{

   printf("\n\t\t\t\t\tADMIN LOGIN\n\n");
    int i, total = countpersonA();
    char name[20],pass[20];

   printf("\t\t\t\tEnter Username: ");
   scanf("%s",name);

   printf("\t\t\t\tEnter Password: ");
   scanf("%s",pass);

    LoadA();

    for(i=1; i<=total; i++)
    {
        if(strcmp(A[i].username, name)==0)
        {
            currentid = A[i].id;
            break;
        }
    }

    if(strcmp(A[currentid].username,name)==0)
    {
        if(strcmp(A[currentid].password,pass)==0)
        {
            printf("\n\n\t\t\t\tWelcome %s, Login successful!\n\n",name);
            //ADMIN WORKS****
            system("pause");
            system("cls");
            //adminwork();
        }
        else
        {
            printf("\n\t\t\t\t\tWrong Password!");
            printf("\n\t\t\t\t\t Try Again!\n\n");
            system("pause");
            system("cls");
            adminlogin();
        }
    }
    else
    {
        printf("\n\t\t\t\t\tUser doesn't exist\n");
        printf("\n\t\t\t\t\tRegister Admin!\n");
        system("pause");
        system("cls");
        adminreg();
    }

}
void sellerlogin()
{
    printf("\n\t\t\t\t\tSELLER LOGIN\n\n");
int i, total = countpersonS();
char name[20],pass[20];

    printf("\t\t\t\tEnter Username: ");
    scanf("%s",name);

    printf("\t\t\t\tEnter Password: ");
    scanf("%s",pass);

    LoadS();

    for(i=1; i<=total; i++)
    {
        if(strcmp(S[i].username, name)==0)
        {
            currentid = S[i].id;
            break;
        }
    }

    if(strcmp(S[currentid].username,name)==0)
    {
        if(strcmp(S[currentid].password,pass)==0)
        {
            printf("\n\n\t\t\t\tWelcome %s, Login successful!\n\n",name);
            //SELLER WORK:
            system("pause");
            system("cls");
            //sellerwork();
        }
        else
        {
            printf("\n\t\t\t\t\tWrong Password!");
            printf("\n\t\t\t\t\t Try Again!\n\n");
            system("pause");
            system("cls");
            sellerlogin();
        }
    }
    else
    {
        printf("\n\t\t\t\t\tUser doesn't exist\n");
        printf("\t\t\t\t\t Register Seller!\n");
        printf("\n\n\n");
        system("pause");
        system("cls");
        sellerreg();
    }

}


void LoadA()
{
    int i,lines = countpersonA();
    r = fopen("FadminLogin.txt","r");

    printf("\n\t\t\t\tLoading.....\n\n");
    for(i=1; i<=lines; i++)
    {
        fscanf(r,"%d %s %s",&A[i].id,&A[i].username,&A[i].password);
        //printf("\n%d %s %s",A[i].id,A[i].username,A[i].password);
    }
    printf("\n\t\t\t\t\tAdmin Database Loaded!\n\n");

    fclose(r);
}

void LoadS()
{
    int i,lines = countpersonS();
    r = fopen("FselLogin.txt","r");

    printf("\n\nLoading.....\n\n");
    for(i=1; i<=lines; i++)
    {
        fscanf(r,"%d %s %s",&S[i].id,&S[i].username,&S[i].password);
        //printf("\n%d %s %s",S[i].id,S[i].username,S[i].password);
    }
    printf("\nSeller Database Loaded!\n\n");
    fclose(r);
}

void ReloadA()
{
    int i=1;
    int total = countpersonA();
    w = fopen("tempA.txt","w");

    for(i=1; i<=total; i++)
    {
        fprintf(w,"%d %s %s\n",A[i].id,A[i].username,A[i].password);
    }

    fclose(w);

    remove("FadminLogin.txt");
    rename("tempA.txt","FadminLogin.txt");
}

void ReloadS()
{
    int i=1;
    int total = countpersonS();
    w = fopen("tempS.txt","w");

    for(i=1; i<=total; i++)
    {
        fprintf(w,"%d %s %s\n",S[i].id,S[i].username,S[i].password);
    }

    fclose(w);

    remove("FselLogin.txt");
    rename("tempS.txt","FselLogin.txt");
}

void UpdateA()
{
    char pass[20];
    adminlogin();

    printf("\t\t\t\tEnter New Password: ");
    scanf("%s",pass);

    strcpy(A[currentid].password,pass);

    ReloadA();

    printf("\t\t\t\t\tPassword Updated!\n\n");
    system("pause");
    system("cls");
}

void UpdateS()
{
    char pass[20];
    sellerlogin();

    printf("\t\t\t\tEnter New Password: ");
    scanf("%s",pass);

    strcpy(S[currentid].password,pass);

    ReloadS();

    printf("\t\t\t\t\tPassword Updated!\n\n");
    system("pause");
    system("cls");
}


int countcontent()
{
    char ch;
    int lines = 0;
    g= fopen("content.txt","r");
    while(!feof(g))
    {
        ch = fgetc(g);
        if(ch == '\n')
        {
            ++lines;
        }
    }
    fclose(g);
    return lines;
}


void LoadC()
{
    int i, lines = countcontent();
    g = fopen("content.txt","r");

    for(i=0; i<lines; i++)
    {
        fscanf(g,"%s\t%s\t%f\t%d\n",content[i].code,content[i].name,&content[i].rate,&content[i].quantity);
        //printf("\n%s\t%s\t%.2f\t%d\n",content[i].code,content[i].name,content[i].rate,content[i].quantity);
    }

    fclose(g);
}

void code(char y[])
{
    int fog;
    FILE *g;
    g=fopen("content.txt","r");
    while(1)
    {
        fog=1;
        rewind(g);
        printf("\t\t\t\tEnter New Code Of The Content:");
        scanf("%s",y);
        while(fscanf(g,"%s",item.code)==1)
        {
            if (strcmp(y,item.code)==0)
            {
                fog=0;
                printf("\t\t\t\tCode Already Exists\n");
                printf("\t\t\t\tEnter Again\n");
                //system("pause");
                //system("cls");
                getch();
                break;
            }
        }
        if (fog==1)
            break;
    }
}

void ReloadC()
{
    int i=1;
    int total = countcontent();
    g = fopen("tempC.txt","w");

    for(i=0; i<total; i++)
    {
        fprintf(g,"%s\t\t%s\t\t%.2f\t\t%d\n",content[i].code,content[i].name,content[i].rate,content[i].quantity);
    }

    fclose(g);

    remove("content.txt");
    rename("tempC.txt","content.txt");
}

int checkS( char name[])
{
    int i,flag=1, con=countpersonS();
    LoadS();
    for(i=1;i<=con;i++)
    {
        if(strcmp(S[i].username,name)==0)
        {
            flag=0;
            break;
        }
    }
   return flag;
}

int checkD( char code[])
{
    int i,flag=1, con=countcontent();
    LoadC();
    for(i=0;i<con;i++)
    {
        if(strcmp(code,content[i].code)==0)
        {
            flag=0;
            break;
        }
    }
   return flag;
}

void checkC(int c)
{
    int i,flag, con=countcontent();
    char code[20];
    while(1)
    {
        flag=1;
    printf("\t\t\t\tEnter New Code:");
    scanf("%s",code);
    LoadC();
    for(i=0;i<con;i++)
     {
        if(strcmp(code,content[i].code)==0)
        {
            printf("\t\t\t\t\tCode Already Exist\n");
            printf("\t\t\t\t\t Try Again!!\n\n");
            flag=0;
            system("pause");
            system("cls");
            break;
        }
     }
   if(flag==1)
   {
        strcpy(content[c].code,code);
        ReloadC();
        printf("\t\t\t\t\tItem Updated!\n");
        system("pause");
        system("cls");
        break;
   }

    }
}
int checknB(char code[])
{
     int i,flag=1, con=countcontent();
    LoadC();
    for(i=0;i<con;i++)
    {
        if(strcmp(code,content[i].code)==0||strcmp(code,content[i].name)==0)
        {
            flag=0;
            break;
        }
    }
   return flag;
}

 int checkqB(int q[],int i,int j)
  {
    int fog=1;
    LoadC();
   int quantity=content[i].quantity-q[j];
   if(quantity<0)
   {
       printf("\n\n\t\t\t\t\tInsufficient!!!\n\n");
       fog=0;
       system("pause");
       system("cls");
   }
   else
   {
    content[i].quantity=quantity;
    ReloadC();
   }
  return fog;
 }
/*void deleteS()
{
    int c=0,a,i;
    char x[20];
    char n;
    int con=countpersonS();

    printf("\t\t\t\t\tDELETE SELLER INFORMATION\n\n\n");
    printf("\t\t\t\tEnter Seller Name:");
    scanf("%s",x);
    a=checkS(x);
    if(a==0)
    {
         for(i=0;i<=con;i++)
         {

        if(strcmp(x,S[i].username)==0)
        {
            c=i;
            break;
        }
         }

        r=fopen("FselLogin.txt","w");
        for(i=1;i<=con;i++)
         {
            if(i!=c)
                {
                 fprintf(r,"%d  %s  %s\n",S[i].id,S[i].username,S[i].password);
                }
        }

        fclose(r);
        printf("\t\t\t\t\tITEM DELETED!!\n\n\n");
    }
  if(a==1)
  {
            printf("\t\t\t\t\tCode Doesn,t Exist\n");
            printf("\t\t\t\t\t Try Again!!\n\n");
  }
}*/
void adminwork()
{
    int g;
           printf("\t\t\t\tPress 1: ADD CONTENT\n");
           printf("\t\t\t\tPress 2: EDIT CONTENT\n");
           printf("\t\t\t\tPress 3: DELETE CONTANT\n");
           printf("\t\t\t\tPress 4: SEARCH CONTENT\n");
           printf("\t\t\t\tPress 5: DISPLAY ALL CONTENT\n");
           printf("\t\t\t\tPress 6: MAIN MENU\n");
           printf("\n\n");
           printf("\t\t\t\tYOUR CHOICE(1/2/3/4/5/6):");
           scanf("%d",&g);
           printf("\n\n\n");
      switch(g)
     {
      case 1:
      add();
      //adminwork();
      break;
      case 2:
      edit();
      //adminwork();
      break;
      case 3:
      delete1();
      adminwork();
      break;
      case 4:
      search();
      //adminwork();
      break;
      case 5:
      display();
      break;
      case 6:
      main();
      break;

     }
}
void add()
{
    FILE *g;
    char y[20];
    char n;
            printf("\t\t\t\t\tADD CONTENT ");
        printf("\n\n\n");
        g=fopen("content.txt","a");
        code(y);
        strcpy(item.code,y);
            printf("\t\t\t\tEnter Name Of The Item:");
        scanf("%s",item.name);
            printf("\t\t\t\tEnter Rate Of The Item:");
        scanf("%f",&item.rate);
            printf("\t\t\t\tEnter Quantity Of The Item:");
        scanf("%d",&item.quantity);
        fseek(g,sizeof(item),SEEK_END);
           fprintf(g,"%s  %s  %.2f  %d\n",item.code,item.name,item.rate,item.quantity);
        fclose(g);

            printf("\t\t\t\tEnter New Record(Y/N)?");
        scanf("%s",&n);
        if(n=='y'||n=='Y')
        {
            add();
        }
        else
        {
            system("cls");
            adminwork();
        }
}
void edit()
{
 int c,flag=1,choice,i,quantity;
    char x[20],name[20],code[20];
    char n,s;
    float rate;
    int con=countcontent();

            printf("\t\t\t\t\tEDIT RECORDS\n\n\n");
            printf("\t\t\t\tEnter a Content Code:");
    scanf("%s",x);
    LoadC();
    for(i=0;i<con;i++)
    {
        if(strcmp(x,content[i].code)==0)
        {
            c=i;
            flag=0;
            printf("\t\t\t\tName       = %s\n",content[i].name);
            printf("\t\t\t\tCode       = %s\n",content[i].code);
            printf("\t\t\t\tRate       = %.2f\n",content[i].rate);
            printf("\t\t\t\tQuantity   = %d\n",content[i].quantity);
            printf("\t\t\t\tDo You Want To Edit This Record?(y/n):");
                scanf("%s",&n);
                if(n=='y'||n=='Y')
                {
            printf("\t\t\t\t1- Edit Name \n");
            printf("\t\t\t\t2- Edit Code\n ");
            printf("\t\t\t\t3- Edit Rate\n ");
            printf("\t\t\t\t4- Edit Quantity\n ");
            printf("\t\t\t\t5- Back\n ");
            printf("\t\t\t\tEnter Your Choice(1, 2, 3, 4, 5): ");
                    scanf("%d",&choice);
                    system("cls");
                    switch(choice)
                    {
                    case 1:
                     printf("\t\t\t\tEnter New Name: ");
                     scanf("%s",name);
                     strcpy(content[i].name,name);
                     ReloadC();
                     printf("\t\t\t\t\tItem Updated!\n");
                     break;
                    case 2:
                     checkC(i);

                     break;
                    case 3:
                     printf("\t\t\t\tEnter New Rate: ");
                     scanf("%f",&rate);
                     content[i].rate=rate;
                     ReloadC();
                     printf("\n\t\t\t\t\tItem Updated!\n");
                     break;
                    case 4:
                     printf("\t\t\t\tEnter New Quantity: ");
                     scanf("%d",&quantity);
                     content[i].quantity=quantity;
                     ReloadC();
                     printf("\t\t\t\t\tItem Updated!\n");
                     break;
                    case 5:
                      system("cls");
                      adminwork();
                       break;

                    }
                }
                printf("\t\t\t\tEdit More?(Y/N):");
                     scanf("%s",&s);
                     if(s=='y'||s=='Y')
                     {
                         printf("\n\n\n");
                         system("cls");
                         edit();
                     }
                     else
                     {
                        printf("\n\n\n");
                        system("cls");
                        adminwork();
                     }

        }

    }
if (flag==1)
    {
        printf("\n\n");
        printf("\t\t\t\t\tItem Does Not Exist.");
        printf("\t\t\t\t\t TRY AGAIN!!!!");
        printf("\n\n\n");
        system("pause");
        system("cls");
        edit();
    }

}



void delete1()
{
 int c,a,i;
    char x[20];
    char n;
    float rate;
    int con=countcontent();

    printf("\t\t\t\t\tDELETE RECORDS\n\n\n");
    printf("\t\t\t\tEnter a Content Code:");
    scanf("%s",x);
    a=checkD(x);
    if(a==0)
    {
    for(i=0;i<con;i++)
    {
        if(strcmp(x,content[i].code)==0)
        {
            c=i;
                printf("\t\t\t\tName       = %s\n",content[i].name);
                printf("\t\t\t\tCode       = %s\n",content[i].code);
                printf("\t\t\t\tRate       = %.2f\n",content[i].rate);
                printf("\t\t\t\tQuantity   = %d\n",content[i].quantity);
                printf("\t\t\t\tDo You Want To Delete This Record?(y/n):");
                scanf("%s",&n);
                if(n=='y'||n=='Y')
                {
                    g=fopen("content.txt","w");
                        for(i=0;i<con;i++)
                        {
                            if(i!=c)
                            {
                                fprintf(g,"%s  %s  %.2f  %d\n",content[i].code,content[i].name,content[i].rate,content[i].quantity);
                            }
                        }

                    fclose(g);
                 printf("\t\t\t\t\tITEM DELETED!!\n\n\n");
                 system("pause");
                 system("cls");
                }
                break;
        }

    }
  }
  if(a==1)
  {
      printf("\n\n");
      printf("\t\t\t\t\tCode Doesn,t Exist\n");
      printf("\t\t\t\t\t Try Again!!\n\n\n");
      system("pause");
      system("cls");
     delete1();
  }
}

void search()
{
 int flag=1,i;
    char x[20];
    char n;
    int con=countcontent();

    printf("\t\t\t\t\tSEARCH CONTENT\n\n\n");
    printf("\t\t\t\tEnter a Content Code or name:");
    scanf("%s",x);
    LoadC();
    for(i=0;i<con;i++)
    {
        if(strcmp(x,content[i].code)==0||strcmp(x,content[i].name)==0)
        {
            flag=0;
                printf("\t\t\t\tName       = %s\n",content[i].name);
                printf("\t\t\t\tCode       = %s\n",content[i].code);
                printf("\t\t\t\tRate       = %.2f\n",content[i].rate);
                printf("\t\t\t\tQuantity   = %d\n",content[i].quantity);
                printf("\t\t\t\tBack To previous Menu?(y/n):");
                scanf("%s",&n);
                printf("\n\n\n");
                if(n=='y'||n=='Y')
                {
                    printf("\n\n\n");
                    system("cls");
                    adminwork();
                    break;
                }
        }
    }
    if (flag==1)
    {
        printf("\t\t\t\tItem Does Not Exist.\n");
        printf("\t\t\t\t\t TRY AGAIN!!!!");
        printf("\n\n\n");
        system("pause");
        system("cls");
        search();
    }
}
void display()
{
    char n;
    LoadC();

    int i;
    int total = countcontent();
    printf("\t\t\t\t\tALL CONTENTS\n\n");
    printf("\t\t\t\tCode\t\tName\t\tRate\t\tQuantity\n");
    for(i=0; i<total; i++)
    {
        printf("\t\t\t\t%s\t\t%s\t\t%.2f\t\t %d\n",content[i].code,content[i].name,content[i].rate,content[i].quantity);
    }
    printf("\n\n\n");
    printf("\t\t\t\tBack To Previous Menu Press(y/y):");
     scanf("%s",&n);
        if(n=='y'||n=='Y')
        {

            system("cls");
            adminwork();
        }
        printf("\n\n\n");
}

void displayC()
{
    char n;
LoadC();

    int i;
    int total = countcontent();
    printf("\t\t\t\t\tALL CONTENTS\n\n");
    printf("\t\t\t\tCode\t\tName\t\tRate\t\tQuantity\n");
    for(i=0; i<total; i++)
    {
        printf("\t\t\t\t%s\t\t%s\t\t%.2f\t\t %d\n",content[i].code,content[i].name,content[i].rate,content[i].quantity);
    }
    printf("\n\n\n");

}


void searchS()
{
 int flag=1,i;
    char x[20];
    char n;
    int con=countcontent();

    printf("\t\t\t\t\tSEARCH CONTENT\n\n\n");
    printf("\t\t\t\tEnter a Content Code or name:");
    scanf("%s",x);
    LoadC();
    for(i=0;i<con;i++)
    {
        if(strcmp(x,content[i].code)==0||strcmp(x,content[i].name)==0)
        {
            flag=0;
                printf("\t\t\t\tName       = %s\n",content[i].name);
                printf("\t\t\t\tCode       = %s\n",content[i].code);
                printf("\t\t\t\tRate       = %.2f\n",content[i].rate);
                printf("\t\t\t\tQuantity   = %d\n",content[i].quantity);
                printf("\t\t\t\tBack To previous Menu?(y/n):");
                scanf("%s",&n);
                printf("\n\n\n");
                if(n=='y'||n=='Y')
                {

                    system("cls");
                    sellerwork();
                    break;
                }
        }
    }
    if (flag==1)
    {
        printf("\t\t\t\t\tItem Does Not Exist.\n");
        printf("\t\t\t\t\t TRY AGAIN!!!!");
        printf("\n\n\n");
        system("pause");
        system("cls");
        search();
    }
}
void displayS()
{
   char n;
LoadC();

    int i;
    int total = countcontent();
    printf("\t\t\t\t\tALL CONTENTS\n\n");
    printf("\t\t\t\tCode\t\tName\t\tRate\t\tQuantity\n");
    for(i=0; i<total; i++)
    {
        printf("\t\t\t\t%s\t\t%s\t\t%.2f\t\t %d\n",content[i].code,content[i].name,content[i].rate,content[i].quantity);
    }
    printf("\n\n\n");
    printf("\t\t\t\tBack To Previous Menu Press(y/y):");
     scanf("%s",&n);
        if(n=='y'||n=='Y')
        {
            system("cls");
            sellerwork();
        }
        printf("\n\n\n");
}
void bill1()
{
    printf("\n\t\t\t\t\tBILLING");
    printf("\n\n");
    printf("\t\t\t\tEnter 'end' To Calculate The Bill\n\n");
    int flag=1,i,q[100],c;
    char x[20],name[20];
    char n;
    int con=countcontent();
    float total[100],gtotal=0,rate[20];
    LoadC();
    h=fopen("bill.txt","w");
 while(1)
  {
    printf("\t\t\t\tEnter a Content Code or name:");
    scanf("%s",x);
    if(strcmp(x,"end")==0)
    {
      break;
    }
    else
    {
    c=checknB(x);
       if(c==0)
       {
        printf("\t\t\t\tEnter Quantity:");
        scanf("%d",&q[j]);
        for(i=0;i<con;i++)
         {
         if(strcmp(x,content[i].code)==0||strcmp(x,content[i].name)==0)
           {
             int d=checkqB(q,i,j);
             if(d==1)
             {
             total[j]=content[i].rate*q[j];
             gtotal=gtotal+total[j];
             fprintf(h,"%d  %s\t  %.2f\t   %d\t%.2f\n",j+1,content[i].name,content[i].rate,q[j],total[j]);
             j++;
             }

           }
         }
       }
       else
       {
        printf("\t\t\t\t\tCode Doesn't Exist\n");
        printf("\t\t\t\t\t  Try Again!!\n\n");
       }

    }
  }
    fclose(h);
    printf("\n\n\n");
    system("cls");
    printf("\t\t\t\t\tCUSTOMAR'S BILL\n\n");
    zb = fopen("bill.txt","r");
    bill M[20];
    printf("\t\t\t\tSN.\tNAME\tRATE\tQUANTITY\tTOTAL\n");
    for(i=0;i<j;i++)
        {
        fscanf(zb,"%d %s %f %d %f",&M[i].serial,M[i].name,&M[i].rate,&M[i].quantity,&M[i].total);
        printf("\t\t\t\t%d\t%s\t%.2f\t   %d\t\t%.2f\n",M[i].serial,M[i].name,M[i].rate,M[i].quantity,M[i].total);
        }
    fclose(zb);

    //remove("bill.txt");

    printf("\n\n\t\t\t\tTOTAL BILL: %.2f\n\n\n",gtotal);
    printf("\t\t\t\t<<<<<THANK YOU FOR SHOPING>>>>>\n");
    printf("\t\t\t\tM.A.S DEPARTMENTAL STORE");
    printf("\n\n\n");
    system("pause");
    system("cls");
}

 void sellerwork()
 {
     system("color 80");
            int g;
            printf("\n\n\n");
            printf("\t\t\t\tPress 1: BILLING\n");
            printf("\t\t\t\tPress 2: SEARCH CONTENT\n");
            printf("\t\t\t\tPress 3: DISPLAY ALL CONTANT\n");
            printf("\t\t\t\tPress 4: MAIN MENU\n");
            printf("\n\n");
            printf("\t\t\t\tYOUR CHOICE(1/2/3/4):");
            scanf("%d",&g);
            printf("\n\n\n");
      switch(g)
     {
      case 1:
      displayC();
      bill1();
      sellerwork();
      break;
      case 2:
      searchS();
      //sellerwork();
      break;
      case 3:
      displayS();
      //sellerwork();
      break;
      case 4:
      system("cls");
      main();
      break;
     }
 }

int main()
{
    int asl,p;
    system("COLOR F9");
    printf("\n\n\n");

printf("\t\t\t\t\tM.A.S\n");
printf("\t\t\t\tDEPARTMENTAL STORE\n");
printf("\n\n");
printf("\t\t\t\tPress 1: REGISTRATION\n");
printf("\t\t\t\tPress 2: ADMIN LOGIN\n");
printf("\t\t\t\tPress 3: SELLER LOGIN\n");
printf("\t\t\t\tPress 4: CHANGE PASSWORD\n");
printf("\t\t\t\tPress 5: EXIT\n");
printf("\n\n");
printf("\t\t\t\tYOUR CHOICE(1/2/3/4/5):");
scanf("%d",&asl);
printf("\n\n");
system("cls");
switch(asl)
{
case 1:
    registration();
    break;
case 2:
    adminlogin();
    adminwork();
    break;
case 3:
    sellerlogin();
    sellerwork();
    break;
case 4:
    printf("\t\t\t\tPress 1: ADMIN\n");
    printf("\t\t\t\tPress 2: SELLER\n");
    printf("\n\n\t\t\t\tYOUR CHOICE(1/2):");
    scanf("%d",&p);
    printf("\n\n");
    system("cls");
    switch(p)
    {
      case 1:
      UpdateA();
      main();
      break;
      case 2:
      UpdateS();
      main();
      break;
    }
case 5:
    printf("\t\t\t\t<<<<<<<<<<THANK YOU>>>>>>>>>>");
    printf("\n\n\n");
    break;
}
return 0;
}
