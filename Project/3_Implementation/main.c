#include<stdio.h>
#include<conio.h>
#include<process.h>
void addTeam();
void print();
void deleteAll();
struct pTable
{
  char team[30];
  int played,won,lost,draw,total;
}pt;
int main()
{
int ch;
    while(1)
    {
        printf("\n1) Add Team\n");
        printf("\n2) View Points table\n");
        printf("\n3) Delete all records\n");
        printf("\n4) Exit");
        printf("\n\tEnter Your Choice:- ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            	addTeam();
            break;
            case 2:
            	print();
            break;
            case 3:
            	deleteAll();
            	break;
            case 4:
            exit(1);
            default:
	    printf("\n\tInvalid option\n");
	    break;
		}
    }
