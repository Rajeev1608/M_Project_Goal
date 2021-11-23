#include<stdio.h>
#include<conio.h>
#include<process.h>
void addTeam();
void print();
void deleteAll();

//Structure that contains  all details required for points table

struct pTable
{
  char team[30];
  int played,won,lost,draw,total;
}pt;

/*Main function that contains MEnu driven interface and calls respective function based  on user 
Input */

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
    return 0;
}

//function to add new team details  into points  table

void addTeam()
{
int games;
FILE *fp;//file pointer
    fp=fopen("points.txt","ab"); /*file pointer points to a file*/
    if(fp==NULL)  /*if file pointer  is null then  fiole might be missing  or error  while opening file*/
    {
	printf("\n ERROR while Creating file Or File does not exist...!");
	getch();
    }
    else  /*if  file pointer successfully open a file then  ask user to enter details required for points table by calling structure variable declared in pTable */
    {
		   printf("\nEnter Team data\n");

		   printf("\nName: ");
		   scanf("%s",pt.team);
		  Game:  /*label to hold return point if total number of matches is not equal to  sum of lost, won and draw. */
		   printf("\nNumber of games played: ");
		   scanf("%d",&pt.played);


		   printf("\nNumber of games won: ");
		   scanf("%d",&pt.won);

		   printf("\nNumber of games lose: ");
		   scanf("%d",&pt.lost);

		   printf("\nNumber of games drew: ");
		   scanf("%d",&pt.draw);
		   games=pt.won+pt.lost+pt.draw;/*calculating sum of los,won and draw games*/
			if(games!=pt.played)  /*checking if total games played iss equal to sum      
		   		                       matches won,lost and draw.*/

{
printf("\n Total Number of games won,lost and Draw should equals to Number of games Played..\n PLease Enter details again for %s \n",pt.team);
		   			goto Game; /*goto label to get input correct again from the user*/
				}
		   pt.total=(pt.won*3)+(pt.draw*1); /*calculating  the points based on win(3) and draw(1)*/
	   	   fwrite(&pt,sizeof(pt),1,fp); /*used to write into file*/
	       printf("\n %s Team details has been successfully added...\n",pt.team);
    }

fclose(fp); //close the file
}

/*function to print the points table details*/
void print()
{
int size;
FILE *fp; /*file  pointer*/
	    fp=fopen("points.txt","rb");/*open a file  in read mode*/
	    if(fp==NULL)  /*if file pointer  is null then  fiole might be missing  or error  while opening file*/
	    {
		printf("\n ERROR while Creating file Or File does not exist...!");
		getch();
	    }
	    else if (NULL != fp) /*if file pointer no null then check if  file has contents or not*/
		{
		fseek (fp, 0, SEEK_END); /*move file pointer from offset 0 to end*/
		size = ftell(fp); /*get  the size to the file*/
		fseek(fp, 0, SEEK_SET); /*move file pointer to offset 0 i.e starting of file*/
		if (0 == size) /*file  size is 0 the it has no  content*/
			{
	    printf("\nNo Team Records to display...!\n");
		}
		else /*if file has some content then display it in proper  format*/
			{
			printf("Name\t\tPlayed\tWon\tLose\tDrew\tPoints\n");
			printf("---------------------------------------------------------\n");
			while(fread(&pt,sizeof(pt),1,fp)==1)
				{
				printf("%s\t\t%d\t%d\t%d\t%d\t%d\n",pt.team,pt.played,pt.won,pt.lost,pt.draw,pt.total);
				}
				printf("---------------------------------------------------------\n");
			}
		}
fclose(fp);
}


/*function  to delete all details in the file*/
void deleteAll()
{
int size;
   FILE *fp; /*file  pointer*/
   if((fp=fopen("points.txt","r")) != NULL) /*check file  has content or not*/
		{
		fseek (fp, 0, SEEK_END);
		size = ftell(fp);
		if (0 == size) /*file size is 0 the file has no  content so nothing  to delete.*/
			{
	    printf("\nNo Team Records to delete...!\n");
			}

		else /*if file has some content then delete all content of file but not the  file.*/
			{
				fclose(fp);  /*close  the  file opened in read mode*/
				fopen("points.txt","w"); /*open same file in write mode so that all previous data is lost and new empty file with same overwrites.*/
				printf("\nAll records Successfully deleted...!\n");
		    }
		}
	else /*don't do anything if file does not exist*/
		{
		printf("\nERROR,File does not exist...!");
		}
   fclose(fp); /*close file  opened in write mode*/
}
