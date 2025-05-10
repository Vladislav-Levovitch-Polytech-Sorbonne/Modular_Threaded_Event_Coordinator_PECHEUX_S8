#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

int deck[13]={0,1,2,3,4,5,6,7,8,9,10,11,12};
int tableCartes[3][8];

void melangerDeck()
{
        int i;
        int index1,index2,tmp;

        for (i=0;i<1000;i++)
        {
                index1=rand()%13;
                index2=rand()%13;

                tmp=deck[index1];
                deck[index1]=deck[index2];
                deck[index2]=tmp;
        }
}

void createTable()
{
	// Le joueur 0 possede les cartes d'indice 0,1,2,3
	// Le joueur 1 possede les cartes d'indice 4,5,6,7
	// Le joueur 2 possede les cartes d'indice 8,9,10,11 
	// Le coupable est la carte d'indice 12
	int i,j,c;

	// Re-init
	for (i=0;i<3;i++)
		for (j=0;j<8;j++)
			tableCartes[i][j]=0;

	for (i=0;i<3;i++) //Nb player
	{
		for (j=0;j<4;j++) //Mul offset
		{
			c=deck[i*4+j];
			switch (c)
			{
				case 0: // Sebastian Moran
					tableCartes[i][7]++;
					tableCartes[i][2]++;
					break;
				case 1: // Irene Adler
					tableCartes[i][7]++;
					tableCartes[i][1]++;
					tableCartes[i][5]++;
					break;
				case 2: // Inspector Lestrade
					tableCartes[i][3]++;
					tableCartes[i][6]++;
					tableCartes[i][4]++;
					break;
				case 3: // Inspector Gregson 
					tableCartes[i][3]++;
					tableCartes[i][2]++;
					tableCartes[i][4]++;
					break;
				case 4: // Inspector Baynes 
					tableCartes[i][3]++;
					tableCartes[i][1]++;
					break;
				case 5: // Inspector Bradstreet 
					tableCartes[i][3]++;
					tableCartes[i][2]++;
					break;
				case 6: // Inspector Hopkins 
					tableCartes[i][3]++;
					tableCartes[i][0]++;
					tableCartes[i][6]++;
					break;
				case 7: // Sherlock Holmes 
					tableCartes[i][0]++;
					tableCartes[i][1]++;
					tableCartes[i][2]++;
					break;
				case 8: // John Watson 
					tableCartes[i][0]++;
					tableCartes[i][6]++;
					tableCartes[i][2]++;
					break;
				case 9: // Mycroft Holmes 
					tableCartes[i][0]++;
					tableCartes[i][1]++;
					tableCartes[i][4]++;
					break;
				case 10: // Mrs. Hudson 
					tableCartes[i][0]++;
					tableCartes[i][5]++;
					break;
				case 11: // Mary Morstan 
					tableCartes[i][4]++;
					tableCartes[i][5]++;
					break;
				case 12: // James Moriarty 
					tableCartes[i][7]++;
					tableCartes[i][1]++;
					break;
			}
		}
	}
} 

void printDeck()
{
        int i,j;

        for (i=0;i<13;i++)
                printf("%d:%d\n",i,deck[i]);

	for (i=0;i<4;i++)
	{
		for (j=0;j<8;j++)
			printf("%2.2d ",tableCartes[i][j]);
		switch (i)
			{
				case 0: // Thibault
					printf("\tPlayers Test 0 - Thibault");
					break;
				case 1: // Francois
					printf("\tPlayers Test 1 - Francois");
					break;
				case 2: // Bob
					printf("\tPlayers Test 2 - Bob");
					break;
				default :
					printf("\tPlayers Ghost X - Chost Test");
					break;
			}
		puts("");
	}
}

int main(int argc, char *argv[])
{
	srand(time(NULL));

	printDeck();
	melangerDeck();
	createTable();
	printDeck();

     return 0; 
}
