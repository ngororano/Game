#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>


FILE *fp, *fp1;
int cash;
char user[20];
int bonus = 20;

struct account
{
    char name[20];
    char pass[20];
    int balance;
}ac[100];

void menu(); void hold(); void instructions(); void play(); void login(); void create(); void deposit(); void withdraw(); void update();

void menu()
{
    int option;
    system("CLS");
    printf("\n\n\t\t\t****************************************\n\t\t\t****************************************\n\n\n\t\t\t    Welcome to the VIRTUAL CARDS GAME\n\n\n\t\t\t****************************************\n\t\t\t****************************************\n\n");
    printf("\n\t\t\tChoose one option\n\n\t\t\t1)Login: \n\t\t\t2)Create a new account: \n\t\t\t3)Game instructions: \n\t\t\t4)Quit: \n\t\t\t");
    scanf("\n\t\t\t%d",&option);
    switch(option)
    {
    case 1:
            login();

    case 2:
            create();

    case 3:
            instructions();

    case 4:
        exit(1);

    default:
        {
            printf("\n\t\t\tWRONG input\n");
            exit(1);
        }
    }
}

void instructions()
{
    system("CLS");
    printf("\n\n\t\t\t****************************************\n\t\t\t****************************************\n\n\n\t\t\t    Welcome to the VIRTUAL CARDS GAME\n\n\n\t\t\tINSTRUCTIONS\n\t\t\t*************\n\t\t\t    1)This is a simple cards game\n\t\t\t    2)there are 3 cards \"JACK QUEEN KING\" - computer shuffles the cards\n\t\t\t    3)Player has to guess the position of the QUEEN\n\t\t\t    4)if he/she wins, he/she takes 3 times the bet\n\t\t\t    5)if he/she looses, he/she simply looses the bet amount\n\t\t\t    6)Enjoy the game\n\n\t\t\t****************************************\n\t\t\t****************************************\n\n");
    getch();
    menu();
}
void hold()
{
    int c;
    if(cash > 1){
    do
    {
        printf("\n\t\t\tPress 1 to continue playing");
        printf("\n\t\t\tPress 0 to go to main menu");
        scanf("%d",&c);
        if(c == 1)
            play();

        else if (c == 0)
            menu();

        else
            printf("\n\t\t\tINVALID option  Please enter a valid option! ");
    }while(c!=1 || c != 0);
}else{
    printf("\n\n\t\t\tYou have no money left on your account.Please deposit to continue playing\n\t\t\tpress any key to go to menu...");
    getch();
    menu();
}
}

void login()
{
    char name[20];
    char pass[20];
    int i;
    do
    {
        i = 0;
        system("CLS");
        printf("\n\t\t\tLogin");
        printf("\n\t\t\tEnter username: ");
        scanf("\n\t\t\t%s",name);
        printf("\n\t\t\tEnter password: ");
        scanf("\n\t\t\t%s",pass);
        fp = fopen("users.txt","r");
        while(!feof(fp))
        {
            fscanf(fp, "\n%s%s%d",ac[i].name , ac[i].pass , &ac[i].balance);
            if((strcmp(ac[i].name,name) == 0) && (strcmp(ac[i].pass,pass) == 0))
            {
                printf("\n\t\t\tWELCOME  %s\tPress any key to continue...\n",name);
                strcpy(user,name);
                cash = ac[i].balance;
                fclose(fp);
                int ch;
                getch();
                do
                {
                    system("CLS");
                    printf("\n\t\t\tWELCOME : %s",name);
                    printf("\n\t\t\tChoose one option\n\t\t\t1)Play\n\t\t\t2)Deposit\n\t\t\t3)Withdraw\n\t\t\t4)Quit to main menu");
                    scanf("\n\t\t\t%d",&ch);
                    switch(ch)
                    {
                    case 1:
                            play();

                    case 2:
                            deposit();
                              case 3:
                            withdraw();

                    case 4:
                            menu();

                    default:
                            printf("\n\t\t\tINVALID option.Please try again!");
                    }
                }while(ch != 1 || ch != 2 || ch != 3);
            }
            i++;
        }
        printf("\n\t\t\tWRONG username or password.Please enter a valid username and password!\n\t\t\tPress any key to try again.");
        getch();
    }while(1);
}

void create()
{
    char name[20];
    char pass[20];
    int i;
    do
    {
        i = 0;
        system("CLS");
        printf("\n\n\t\t\tCreate a new account");
        printf("\n\t\t\tEnter username: ");
        scanf("\n\t\t\t%s",name);
        printf("\n\t\t\tEnter password: ");
        scanf("\n\t\t\t%s",pass);
        fp = fopen("users.txt","r");
        while(!feof(fp))
        {
            fscanf(fp, "\n%s%s%d",ac[i].name,ac[i].pass, &ac[i].balance);
            if(strcmp(ac[i].name,name) == 0)
                {
                    printf("\n\t\t\tThe name already exists. Please choose another name! press any key to try again");
                    getch();
                    fclose(fp);
                    break;
                }
            i++;
        }
    }while(strcmp(ac[i].name,name) == 0);
    fp = fopen("users.txt","a");
    fprintf(fp, "\n%s\t%s\t%d",name,pass,bonus);
    fclose(fp);
    printf("\n\t\t\tThank you %s.Your account is created.You are given $%d bonus to start with!!!",name,bonus);
    printf("\n\t\t\tPress any key to go to main menu...");
    getch();
    menu();
}

void deposit()
{
    printf("\n\t\t\t\"ASK THE PERSON WHO WORKS AT THE VIRTUAL CARDS SHOP TO HELP YOU MAKE A DEPOSIT\"\n\t\t\t press any key to go back to menu...");
    getch();
    menu();
}

void withdraw()
{
    printf("\n\t\t\t\"ASK THE PERSON WHO WORKS AT THE VIRTUAL CARDS SHOP TO HELP YOU WITHDRAW\"\n\t\t\t press any key to go back to menu...");
    getch();
    menu();
}

void update()
{
    int i=0;
    fp=fopen("users.txt","r");
    fp1=fopen("users_temp.txt","w");
    while(!feof(fp))
    {
        fscanf(fp,"%s%s%d",ac[i].name,ac[i].pass,&ac[i].balance);
        if(strcmp(ac[i].name,user)!=0)
            fprintf(fp1,"\n%s\t%s\t%d",ac[i].name,ac[i].pass,ac[i].balance);
        else
            fprintf(fp1,"\n%s\t%s\t%d",ac[i].name,ac[i].pass,cash);
        i++;
    }
    fclose(fp);
    fclose(fp1);
    remove("users.txt");
    rename("users_temp.txt","users.txt");
}

void play()
{
    system("CLS");
    printf("\n\t\t\tPlaying as %s",user);
    printf("\n\t\t\tcash = %d\n\t\t\t********************\n", cash);
    int bet;
    char cards[3] = {'J','Q','K'};
    int playerGuess, i;
    if(cash > 0)
    {
        do
        {
            printf("\n\n\t\t\tWhat is your bet? $ ");
            scanf("%d",&bet);
            if (bet < 1)
                printf("\n\n\t\t\tbet amount NOT ALLOWED Please enter a valid amount! ");
            else if (bet > cash)
                printf("\n\n\t\t\tyou have only $%d on your account balance.Please enter a valid amount! ",cash);
        }while(bet < 1 || bet > cash);
        printf("\n\t\t\tShuffling cards ...\n\n");
        for (double j=0;j<9999999;j++)
        {
            j++;j--;
            for(double j=0;j<12;j++)
                {
                    j++;j--;
                }
        }
        srand(time(NULL));
        for(i=0; i<10; i++)
        {
        int x = rand() % 3;
        int y = rand() % 3;
        int temp = cards[x];
        cards[x] = cards[y];
        cards[y] = temp;
        }
        do
        {
            printf("\n\t\t\tWhat is the position of the queen - 1,2 or 3 ? ");
            scanf("%d",&playerGuess);
            if(playerGuess !=1 && playerGuess != 2 && playerGuess !=3)
            {
                printf("\n\t\t\tINVALID input.please enter 1 or 2 or 3.Press any key to continue...");
                getch();
                system("CLS");
                printf("\n\t\t\tPlaying as %s",user);
                printf("\n\t\t\tcash = %d\n\t\t\t********************\n", cash);
            }
        }while(playerGuess !=1 && playerGuess != 2 && playerGuess !=3);
        if(cards[playerGuess - 1] == 'Q')
            {
                cash = (cash - bet) + (bet*3);
                printf("\n\t\t\tYou WIN ! \n\t\t\tResult = \"%c %c %c\"",cards[0],cards[1],cards[2]);
                update();
                hold();
            }
        else
            {
                cash = cash - bet;
                printf("\n\t\t\tYou LOOSE ! \n\t\t\tResult = \"%c %c %c\"",cards[0],cards[1],cards[2]);
                update();
                hold();
            }
    }else printf("\n\t\t\tyou have no money left on your account");
}


int main()
{
    menu();
}

