// Dijiktra's Algorithm
#include <stdio.h>
#include <limits.h>
#include<stdbool.h>
#include<stdlib.h>
// Number of vertices in the graph
#define V 9
int c,cost=7;

int minDistance(int dist[], bool sptSet[])
{
    // Initialize min value
    int min = INT_MAX, min_index;
 	int v;
    for (v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

// Function to print shortest path from source to j
// using parent array
void printPath(int parent[], int j)
{
    // Base Case : If j is source
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

//Printing solution
int printSolution(int dist[], int n, int parent[],int src)
{
	char sc[30],desti[30];
	int dest;
    int i,d;
    	printf("\nEnter destination : ");
    	y:
 	scanf("%d",&dest);
 	if(dest<=0||dest>9)
    {
        printf("Enter correct destination : ");
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


}


// Funtion that implements Dijkstra's single source shortest path
// algorithm for a graph represented using adjacency matrix
// representation
void dijkstra(int graph[V][V], int src)
{
	int i,v;
    int dist[V];  // The output array. dist[i] will hold
                  // the shortest distance from src to i

    // sptSet[i] will true if vertex i is included / in shortest
    // path tree or shortest distance from src to i is finalized
    bool sptSet[V];

    // Parent array to store shortest path tree
    int parent[V];

    // Initialize all distances as INFINITE and stpSet[] as false
    for (i = 0; i < V; i++)
    {
        parent[i] = -1;
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;
 	int count;
    // Find shortest path for all vertices
    for (count = 0; count < V-1; count++)
    {
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as true
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

    // print the constructed distance array
    printSolution(dist, V, parent,src);
}

// main
int main()
{
    int input;
    printf("        \n\n\n\n\n                                      *PROJECT ON SHORTEST PATH FOR METRO LINE* \n");
    printf("                            __________________________________________________________\n\n\n\n\n\n\n\n\n\n");
    printf("\n\n                                                                              CREATED BY:");
    printf("\n                                                                                 ASHWIN SINGH 991510114");
    printf("\n                                                                                 ARPIT GUPTA   9915103113");
    printf("\n                                                                                 SHALVI LALE   99151031");
    printf("\n                                                                                 VIDHI MARKHEDKAR 9915103136");
    printf("\n\n\n                                            Enter 1 to continue :  ");
    scanf("%d",&input);
    if(input==1)
        system("cls");
    else
        return 0;
	char ch;
	int src,dest;
	printf("\nVarious stations:");
	printf("\n0 - NOIDA CITY CENTRE");
	printf("\n1 - GOLF COURSE");
	printf("\n2 - RITHALA");
	printf("\n3 - ROHINI");
	printf("\n4 - RAJIV CHOWK");
	printf("\n5 - KARKARDOOMA");
	printf("\n6 - DILSHAD GARDEN");
	printf("\n7 - VAISHALI");
	printf("\n8 - CHANDNI CHOWK");

    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 0, 10, 0, 2, 0, 0},
                       {0, 0, 0, 14, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}

                      };

 	printf("\nenter source from where you want to board : ");
 	x:
 	scanf("%d",&src);
    if(src>=0&&src<=8)
        dijkstra(graph, src);
    else
       {
           printf("Please Enter your Source again : ");
           goto x;
       }
    printf("\n");
    printf("\nDo you want to see more details? If yes press y : ");
    fflush(stdin);
    scanf("%c",&ch);
    if(ch=='y'||ch=='Y')
    {
    //Printing no of stations
     printf("\n\nTotal no of stations =%d",c);
     //Time taken to reach
     printf("\n\nTotal no of Minutes =%d min",c*3);
     //Cost of Travel
     printf("\n\nTotal Cost Of traveling=Rs.%d",cost);
 	}
    return 0;
}
