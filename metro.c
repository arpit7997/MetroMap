#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#define V 9
int c=0,cost=7;
int minDistance(int dist[], bool sptSet[])
{

    int min = 65536, min_index;
 	int v;
    for (v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}
void printPath(int parent[], int j)
{

    if (parent[j]==-1)
        return;
    printPath(parent, parent[j]);
    c++;
    cost+=5;
    switch(j){
    	case 0:
    		printf("NOIDA CITY CENTRE-->");
    		break;
    	case 1:
    		printf("GOLF COURSE-->");
    		break;
    	case 2:
    		printf("RITHALA-->");
    		break;
    	case 3:
    		printf("ROHINI-->");
    		break;
    	case 4:
    		printf("RAJIV CHOWK-->");
    		break;
   		case 5:
    		printf("KARKARDOOMA-->");
    		break;
   		case 6:
    		printf("DILSHAD GARDEN-->");
    		break;
   		case 7:
    		printf("VAISHALI-->");
    		break;
    	case 8:
    		printf("CHANDNI CHOWK-->");
    		break;
	}
}
int printSolution(int dist[], int n, int parent[],int src)
{
	char sc[30],desti[30],ch;
	int dest;
    int i,d;
    	printf("\n                   Enter destination : ");
    	y:
 	scanf("%d",&dest);
 	if(dest<0||dest>9)
    {
        printf("                    Enter correct destination : ");
        goto y;
    }
 	switch(src){
    	case 0:
    		strcpy(sc," NOIDA CITY CENTRE");
    		break;
    	case 1:
    		strcpy(sc," GOLF COURSE");
    		break;
    	case 2:
    		strcpy(sc,"RITHALA");
    		break;
    	case 3:
    		strcpy(sc,"ROHINI");
    		break;
    	case 4:
    		strcpy(sc,"RAJIV CHOWK");
    		break;
   		case 5:
    		strcpy(sc,"KARKARDOOMA");
    		break;
   		case 6:
    		strcpy(sc,"DILSHAD GARDEN");
    		break;
   		case 7:
    		strcpy(sc,"VAISHALI");
    		break;
    	case 8:
    		strcpy(sc,"CHANDNI CHOWK");
    		break;
	}
		switch(dest){
    	case 0:
    		strcpy(desti," NOIDA CITY CENTRE");
    		break;
    	case 1:
    		strcpy(desti," GOLF COURSE");
    		break;
    	case 2:
    		strcpy(desti,"RITHALA");
    		break;
    	case 3:
    		strcpy(desti,"ROHINI");
    		break;
    	case 4:
    		strcpy(desti,"RAJIV CHOWK");
    		break;
   		case 5:
    		strcpy(desti,"KARKARDOOMA");
    		break;
   		case 6:
    		strcpy(desti,"DILSHAD GARDEN");
    		break;
   		case 7:
    		strcpy(desti,"VAISHALI");
    		break;
    	case 8:
    		strcpy(desti,"CHANDNI CHOWK");
    		break;
	}
    for (i = 0; i < V; i++)
    {
    	if(i==dest)
    	{
    	    printf("\nFROM-> TO");
        printf("\t\t%s -> %s", sc, desti);
        printf("\nDistance(Km)");
		printf("\t\t%d",dist[i]);
		printf("\nPath\t\t\t%s-->",sc);
        	printPath(parent,dest);
        	printf("Destination");
		}
    }
    				printf("\n\n                    Do you want to see more details? If yes press y : \n");
    				fflush(stdin);
    				scanf("%c",&ch);
    				if(ch=='y'||ch=='Y')
    				{
    				 printf("\n\n                 Total no of stations travelled =%d",c);
     				printf("\n\n                  Total no of Minutes =%d min",c*3);
     				printf("\n\n                  Total Cost Of traveling=Rs.%d",cost);
 					}
 					printf("\n");
 					printf("\n");
    				printf("\n**********************************************************************\n");
    				printf("\n*******                FOR BACK-->PRESS 5                 ************\n");
 					printf("\n*******                FOR EXIT-->PRESS 6                 ************\n");
 					printf("\n**********************************************************************\n");
 					int back;
 					c=0;
 					cost=7;
 				 F:	scanf("%d",&back);
 					if(back==5)
 						mainscreen();
 					else if(back==6)
 						endscreen();
 					else
 						printf("                      INVALID INPUT.....ENTER AGAIN!!!!!");
 						printf("\n");
 						goto F;
}
void dijkstra(int graph[V][V], int src)
{
	int i,v;
    int dist[V];
    bool sptSet[V];
    int parent[V];
    for (i = 0; i < V; i++)
    {
        parent[i] = -1;
        dist[i] = 65536;
        sptSet[i] = false;
    }
    dist[src] = 0;
 	int count;
    for (count = 0; count < V-1; count++)
    {
        int u = minDistance(dist, sptSet);
        sptSet[u] = true;
        for (v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] &&
                dist[u] + graph[u][v] < dist[v])
            {
                parent[v]  = u;
                dist[v] = dist[u] + graph[u][v];
            }
    }
    int dest;

    printSolution(dist, V, parent,src);
}
int route()
	{
		system("cls");
			printf("\nVarious stations:");
						printf("\n                  0 - NOIDA CITY CENTRE");
						printf("\n                  1 - GOLF COURSE");
						printf("\n                  2 - RITHALA");
						printf("\n                  3 - ROHINI");
						printf("\n                  4 - RAJIV CHOWK");
						printf("\n                  5 - KARKARDOOMA");
						printf("\n                  6 - DILSHAD GARDEN");
						printf("\n                  7 - VAISHALI");
						printf("\n                  8 - CHANDNI CHOWK");

   						 int graph[V][V] = {{0, 5, 0, 0, 0, 0, 0, 0, 0},
                                            {5, 0, 6, 10, 8, 0, 0, 0, 0},
                       				  	    {0, 6, 0, 0, 0, 0, 12, 0, 0},
                      						{0, 10, 0, 0, 0, 7, 0, 0, 0},
                      						{0, 8, 0, 0, 0, 0, 0, 1, 0},
                      						{0, 0, 0, 7, 0, 0, 6, 0, 0},
                      						{0, 0, 12,0, 0, 6, 0,3, 2},
                      						{0, 0, 0, 0, 1, 0, 3, 0, 0},
                      						{0, 0, 0, 0, 0, 0, 2, 0, 0}

                      };
					printf("\n");
					int src,ch,back;
 					printf("\n                     enter source from where you want to board : ");
 					x:
 					scanf("%d",&src);
    				if(src>=0&&src<=8)
        				dijkstra(graph, src);
    				else
      					 {
          			 		printf("            Please Enter your Source again : \n");
          					 goto x;
       					}
    				printf("\n");
    				printf("\n                    Do you want to see more details? If yes press y : \n");
    				fflush(stdin);
    				scanf("%c",&ch);
    				if(ch=='y'||ch=='Y')
    				{
    				 printf("\n\n                 Total no of stations =%d",c);
     				printf("\n\n                  Total no of Minutes =%d min",c*3);
     				printf("\n\n                  Total Cost Of traveling=Rs.%d",cost);
 					}
 					printf("\n");
 					printf("\n");
 					printf("\n**********************************************************************\n");
 					printf("************                     FOR BACK-->PRESS 5          ***********\n");
 					printf("************                     FOR EXIT-->PRESS 6          ***********\n");
 					printf("\n**********************************************************************\n");
 				 F:	scanf("%d",&back);
 					if(back==5)
 						mainscreen();
 					else if(back==6)
 						endscreen();
 					else
 						printf("                      INVALID INPUT..... ENTER AGAIN!!!!!");
 						printf("\n");
 						goto F;

	}

	int station_Information()
	{
		int ch2;
                            printf("\nVarious stations:");
                            printf("\n                    0 - NOIDA CITY CENTRE");
                            printf("\n                    1 - GOLF COURSE");
                            printf("\n                    2 - RITHALA");
                            printf("\n                    3 - ROHINI");
                            printf("\n                    4 - RAJIV CHOWK");
                            printf("\n                    5 - KARKARDOOMA");
                            printf("\n                    6 - DILSHAD GARDEN");
                            printf("\n                    7 - VAISHALI");
                            printf("\n                    8 - CHANDNI CHOWK");
                            printf("\n         ENTER STATION NO. OF WHICH YOU WANT TO SEE DETAILS!!!!!!\n");
                            scanf("%d",&ch2);
                            switch(ch2)
                                {
                                    case 0:
                                    {  nci();
									   break;}
                                    case 1:
                                    {gf();
									   break;}
                                    case 2:
                                    {ri();
									   break;}
                                    case 3:
                                    { ro();
									   break;}
                                    case 4:
                                    {  ra();
									   break;}
                                    case 5:
                                    {ka();
									   break;}
                                    case 6:
                                    {dg();
									   break;}
                                    case 7:
                                    { va();
									   break;}
                                    case 8:
                                    { cc();
									   break;}

                                    default:
                                    {
									   exit(0);
									}
									int back;
									printf("\n");
									printf("\n***********************************************************************\n");
									printf("**************                    FOR BACK-->PRESS 5            *********\n");
									printf("**************                    FOR EXIT-->PRESS 6            *********\n");
									printf("\n***********************************************************************\n");
 									 G:	scanf("%d",&back);
 										if(back==5)
 											mainscreen();
 										else if(back==6)
 											endscreen();
 										else
 											printf("INVALID INPUT..... ENTER AGAIN!!!!!");
 										goto G;

	}
}
void nci()
{
    system("cls");
    printf("\n                   FIRST TRAIN TIMING:    -->>            5:30:00AM\n\n");
    printf("                     LAST TRAIN TIMING :    -->>            10:30:00PM\n\n");
    printf("               GATE 1 -->>  ROADWAYS BUS STAND\t\t          GATE 2-->> AUTO STAND\n\n");
    printf("                     HELPLINE NUMBER!!  -->>   956874233\n\n");
    printf("                            PARKING:\n");
    printf("                     UP to 6hrs-->>Rs20/- \tMore than 6hrs-->>Rs40/-  \tMonthly->Rs1000/-\n\n");
    printf("                                         NIGHT CHARGES EXTRA!!!!!\n\n");
    printf("\n");
									printf("\n***********************************************************************\n");
									printf("**************                    FOR BACK-->PRESS 5            *********\n");
									printf("**************                    FOR EXIT-->PRESS 6            *********\n");
									printf("\n***********************************************************************\n");
									int back;
 									 G:	scanf("%d",&back);
 										if(back==5)
 										mainscreen();
 										else if(back==6)
 											endscreen();
 										else
 											printf("INVALID INPUT..... ENTER AGAIN!!!!!");
 										goto G;

}
void gf()
{
    system("cls");
    printf("                 FIRST TRAIN TIMING:    -->>                  5:50:00AM\n\n");
    printf("                 LAST TRAIN TIMING :    -->>                  10:32:00PM\n\n");
     printf("           GATE 1 -->>  NOT AVAILABLE\t\t           GATE 2-->>GOLF COURSE GROUND,NOIDA\n\n");
    printf("                 HELPLINE NUMBER!!  -->>   844736547\n\n");
    printf("                                  PARKING:\n");
    printf("           UP to 6hrs-->>Rs20/- \tMore than 6hrs-->>Rs40/-  \tMonthly->Rs1000/-\n\n");
    printf("                            NIGHT CHARGES EXTRA!!!!!\n\n");
   printf("\n");
									printf("\n***********************************************************************\n");
									printf("**************                    FOR BACK-->PRESS 5            *********\n");
									printf("**************                    FOR EXIT-->PRESS 6            *********\n");
									printf("\n***********************************************************************\n");
									int back;
 									 G:	scanf("%d",&back);
 										if(back==5)
 										mainscreen();
 										else if(back==6)
 											endscreen();
 										else
 											printf("INVALID INPUT..... ENTER AGAIN!!!!!");
 										goto G;
}
void ri()
{
    system("cls");
    printf("                              FIRST TRAIN TIMING:    -->>                6:00:00AM\n\n");
    printf("                              LAST TRAIN TIMING :    -->>                11:16:00PM\n\n");
     printf("                     GATE 1 -->>  DTU,MAHARAJA AGRASEN(IP)\t\t      GATE 2-->>ROHINI ,SEC-124\n\n");
    printf("                              CONTACT NUMBER  -->>    963214587\n\n");
    printf("                                            PARKING:\n");
    printf("                     UP to 6hrs-->>Rs20/- \tMore than 6hrs-->>Rs40/-  \tMonthly->Rs1000/-\n\n");
    printf("                                         NIGHT CHARGES EXTRA!!!!!");
    printf("\n");
									printf("\n***********************************************************************\n");
									printf("**************                    FOR BACK-->PRESS 5            *********\n");
									printf("**************                    FOR EXIT-->PRESS 6            *********\n");
									printf("\n***********************************************************************\n");
 									int back;
									  G:	scanf("%d",&back);
 										if(back==5)
 										mainscreen();
 										else if(back==6)
 											endscreen();
 										else
 											printf("INVALID INPUT..... ENTER AGAIN!!!!!");
 										goto G;

}
 void ro()
{
    system("cls");
    printf("                 FIRST TRAIN TIMING:    -->>                  6:05:00AM\n\n");
    printf("                 LAST TRAIN TIMING :    -->>                  11:21:00PM\n\n");
    printf("             GATE 1 -->>  OM SAI APPARTMENT\t\t          GATE 2-->>ADVENTURE WORLD\n\n");
    printf("                HELPLINE NUMBER  -->>    963587412\n\n");
    printf("                                           PARKING:\n");
    printf("                  UP to 6hrs-->>Rs20/- \tMore than 6hrs-->>Rs40/-  \tMonthly->Rs1000/-\n\n");
    printf("                                      NIGHT CHARGES EXTRA!!!!!");
   printf("\n");
									printf("\n***********************************************************************\n");
									printf("**************                    FOR BACK-->PRESS 5            *********\n");
									printf("**************                    FOR EXIT-->PRESS 6            *********\n");
									printf("\n***********************************************************************\n");
 									 int back;
									  G:	scanf("%d",&back);
 										if(back==5)
 										mainscreen();
 										else if(back==6)
 											endscreen();
 										else
 											printf("INVALID INPUT..... ENTER AGAIN!!!!!");
 										goto G;
}
 void ra()
{
    system("cls");
    printf("                FIRST TRAIN TIMING:    -->>                 5:45:00AM\n\n");
    printf("                LAST TRAIN TIMING :    -->>                 11:35:00PM\n\n");
    printf("            GATE 1 -->>  R.K. ASHRAM\t\t                  GATE 2-->>ODEON CINEMA,PALIKA BAZAR\n\n");
    printf("                HELPLINE NUMBER  -->>    863254178\n\n");
    printf("                                             PARKING:\n");
    printf("                       UP to 6hrs-->>Rs20/- \tMore than 6hrs-->>Rs40/-  \tMonthly->Rs1000/-\n\n");
     printf("                                          NIGHT CHARGES EXTRA!!!!!");
   printf("\n");
									printf("\n***********************************************************************\n");
									printf("**************                    FOR BACK-->PRESS 5            *********\n");
									printf("**************                    FOR EXIT-->PRESS 6            *********\n");
									printf("\n***********************************************************************\n");
 									int back;
									  G:	scanf("%d",&back);
 										if(back==5)
 										mainscreen();
 										else if(back==6)
 											endscreen();
 										else
 											printf("INVALID INPUT..... ENTER AGAIN!!!!!");
 										goto G;
}
 void ka()
{
    system("cls");
    printf("                          FIRST TRAIN TIMING:    -->>              6:08:00AM\n\n");
    printf("                          LAST TRAIN TIMING :    -->>              10:51:00PM\n\n");
    printf("                     GATE 1 -->>  KARKARDUMA COURT\t\t          GATE 2-->>METRO PARKING,JAI'S HOUSE\n\n");
    printf("                          CONTACT NUMBER  -->>   963254178\n\n");
    printf("                                               PARKING:\n");
    printf("                       UP to 6hrs-->>Rs20/- \tMore than 6hrs-->>Rs40/-  \tMonthly->Rs1000/-\n\n");
     printf("                                            NIGHT CHARGES EXTRA!!!!!");
printf("\n");
									printf("\n***********************************************************************\n");
									printf("**************                    FOR BACK-->PRESS 5            *********\n");
									printf("**************                    FOR EXIT-->PRESS 6            *********\n");
									printf("\n***********************************************************************\n");
 									 int back;
									  G:	scanf("%d",&back);
 										if(back==5)
 										mainscreen();
 										else if(back==6)
 											endscreen();
 										else
 											printf("INVALID INPUT..... ENTER AGAIN!!!!!");
 										goto G;
}
void  dg()
{
    system("cls");
    printf("                     FIRST TRAIN TIMING:    -->>              5:10:00AM\n\n");
    printf("                     LAST TRAIN TIMING :    -->>              11:30:00PM\n\n");
    printf("                GATE 1 -->>  HALDIRAMS,Mc DONALDS\n\n");
    printf("                CONTACT NUMBER  -->>  847596325\n\n");
    printf("                                     PARKING:\n");
    printf("                   UP to 6hrs-->>Rs20/- \tMore than 6hrs-->>Rs40/-  \tMonthly->Rs1000/-\n\n");
    printf("                                NIGHT CHARGES EXTRA!!!!!");
    printf("\n");
									printf("\n***********************************************************************\n");
									printf("**************                    FOR BACK-->PRESS 5            *********\n");
									printf("**************                    FOR EXIT-->PRESS 6            *********\n");
									printf("\n***********************************************************************\n");
 									 int back;
									  G:	scanf("%d",&back);
 										if(back==5)
 										mainscreen();
 										else if(back==6)
 											endscreen();
 										else
 											printf("INVALID INPUT..... ENTER AGAIN!!!!!");
 										goto G;
}
void va()
{
    system("cls");
    printf("FIRST TRAIN TIMING:    -->>   6:00:00AM\n\n");
    printf("LAST TRAIN TIMING :    -->>  10:45:00PM\n\n");
    printf("GATE 1 -->>  VAISHALI\t\tGATE 2-->>MAHAGUN MALL,\n\n");
    printf("CONTACT NUMBER  -->> 987452315\n\n");
    printf("PARKING:\n");
    printf("UP to 6hrs-->>Rs20/- \tMore than 6hrs-->>Rs40/-  \tMonthly->Rs1000/-\n\n");
    printf("                                NIGHT CHARGES EXTRA!!!!!");
    printf("\n");
									printf("\n***********************************************************************\n");
									printf("**************                    FOR BACK-->PRESS 5            *********\n");
									printf("**************                    FOR EXIT-->PRESS 6            *********\n");
									printf("\n***********************************************************************\n");
 									 int back;
									  G:	scanf("%d",&back);
 										if(back==5)
 										mainscreen();
 										else if(back==6)
 											endscreen();
 										else
 											printf("INVALID INPUT..... ENTER AGAIN!!!!!");
 										goto G;
}
void cc()
{
    system("cls");
     printf("                   FIRST TRAIN TIMING:    -->>              6:00:00AM\n\n");
    printf("                    LAST TRAIN TIMING :    -->>              10:30:00PM\n\n");
    printf("               GATE 1 -->>  DELHI PUBLIC LIBRARY\t\t        GATE 2-->>OLD DELHI RAILWAY STATION\n\n");
    printf("                    CONTACT NUMBER  -->>     968745213\n\n");
    printf("                                          PARKING:\n");
    printf("                     UP to 6hrs-->>Rs20/- \tMore than 6hrs-->>Rs40/-  \tMonthly->Rs1000/-\n\n");
     printf("                                NIGHT CHARGES EXTRA!!!!!");
    printf("\n");
									printf("\n***********************************************************************\n");
									printf("**************                    FOR BACK-->PRESS 5            *********\n");
									printf("**************                    FOR EXIT-->PRESS 6            *********\n");
									printf("\n***********************************************************************\n");
 									 int back;
									  G:	scanf("%d",&back);
 										if(back==5)
 										mainscreen();
 										else if(back==6)
 											endscreen();
 										else
 											printf("INVALID INPUT..... ENTER AGAIN!!!!!");
 										goto G;
}
int mainscreen()
 	{
 		int ch1;
 		system("cls");
        printf("         ****************************************************************\n");
        printf("         ****************************************************************\n");
        printf("         **                                                            **\n");
        printf("         **                      WELCOME TO DELHI METRO                **\n");
        printf("         **                                                            **\n");
        printf("         ****************************************************************\n");
        printf("         ****************************************************************\n");
        printf("\n\n\n\n");
        printf("Enter any options you want : \n\n");
        printf("1.ROUTE BETWEEN STATIONS\n");
        printf("2.STATION INFORMATION\n");
        printf("3.EXIT\n");
        scanf("%d",&ch1);
        switch(ch1)
        {
        	case 1:
        		route();
        	    break;
        	case 2:
        		station_Information();
        		break;
        	case 3:
        		 endscreen();
		}

	 }
int endscreen()
{
	system("cls");
        printf("         ****************************************************************\n");
        printf("         ****************************************************************\n");
        printf("         **                                                            **\n");
        printf("         **                      THANKYOU.......                       **\n");
        printf("         **                  VISIT US AGAIN!!!!!!!!                    **\n");
        printf("         **                                                            **\n");
        printf("         ****************************************************************\n");
        printf("         ****************************************************************\n");
        printf("\n\n\n\n");
        exit(0);
}
int main()
{
	system("cls");
	system("color 81");
    int input;
    printf("        \n\n\n\n\n                                      *PROJECT ON SHORTEST PATH FOR METRO LINE* \n");
    printf("                            __________________________________________________________\n\n\n\n\n\n\n\n\n\n");

    printf("                   ******   \n");
	printf("                *          *   \n");
	printf("             *                 *       \n");
	printf("           *                     * \n");
	printf("          *-----------------------*\n");
	printf("         *-------------------------*               WELCOME TO DELHI METRO            \n");
	printf("         *           / /           *\n");
	printf("         *          / /            *              DELHI METRO ME AAPKA SWAGAT HAI\n");
	printf("         *         / /             *\n");
	printf("          *-----------------------*\n");
	printf("           *--------------------*\n");
	printf("             *                * \n");
	printf("               *           *   \n");
	printf("                  ******   \n");
	printf("\n");
	printf("             _____    ______                 _______                         _______  ______  _____     ____ \n");
	printf("            ||   \\   ||      ||     ||    ||    ||              ||\\    //|| ||         ||    ||   \\\  //    \\\n");
	printf("            ||    \\  ||_____ ||     ||____||    ||              ||  \\//  || ||_____    ||    ||___|| ||    ||\n");
	printf("            ||    // ||      ||     ||    ||    ||              ||       || ||         ||    ||\\\     ||    ||\n");
	printf("            ||___//  ||_____ ||____ ||    ||  __||___           ||       || ||_____    ||    || \\\     \\____//\n");


    printf("\n\n                                                                                                     CREATED BY:");
    printf("\n                                                                                                       ASHWIYN SINGH 9915103114");
    printf("\n                                                                                                       ARPIT GUPTA   9915103113");
    printf("\n                                                                                                       SHALVI LALE   9915103129");
    printf("\n\n\n                                    Enter 1 to continue :");
    scanf("%d",&input);
    if(input==1)
    	mainscreen();
    else
        return 0;
}
