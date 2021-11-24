#include "unity.h"
#include "football_league.h"

#include "football_league.h"
#define PROJECT_NAME    "football_league"

/* prototypes for test functions */

void display( ) ;
void changecol ( struct ball * ) ;
struct ball * add ( int, int, int, int ) ;
void del ( struct name * ) ;
void getfreerowcol ( int, int * ) ;
void getrcbyinfo ( int, int, int * ) ;
void show() ;
int randint();
int backupw();
int backupr();
struct ball * addonstart ( int, int, int, int ) ;
void total_bill(int ,struct tm *ct1,struct tm *ct2);
void get_time(int);

/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

/* Start of the application test */
int main( )
{
	int choice, type, number, row = 0, col = 0 ;
	int i, tarr[2] ;
	int finish = 1 ;
	backupr();



  system ( "cls" ) ;

	/* displays menu and calls corresponding functions */
	while ( finish )
	{
    system ( "cls" ) ;

		printf ( "\nCar ball\n" ) ;
		printf ( "1. Arrival of a ball\n" ) ;
		printf ( "2. Total no. of points\n" ) ;
		printf ( "3. Display the records\n" ) ;
		printf ( "4. Chek History\n" ) ;
		printf ( "5. Exit\n" ) ;

		scanf ( "%d", &choice ) ;

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

