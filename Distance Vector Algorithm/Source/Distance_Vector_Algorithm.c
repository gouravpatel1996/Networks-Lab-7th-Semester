#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h>

//get min of 2 integers. 
int min(int a, int b) {
	//if a is less than b return a else return b
	return (a < b) ? a : b;
}


void dist(int p[10][10], int n) {
	int i, j, k;
	//keep k constant and run through j
	for(k = 1;k <= n; k++){
		//keep j constant and run through i
		for(j = 1;j <= n; j++){
			for(i = 1;i <= n; i++){
				p[i][j]=min(p[i][j], p[i][k] + p[k][j]);
			}
		}
	}
}

int main( ) {

	int a[10][10], i, j, n, flag, temp = 1;

	//get data
	printf("enter the number of nodes\n");
	scanf("%d",&n);
	printf("enter the matrix 0 for self loop and 999 for no path \n"); 
	for(i = 1;i <= n; i++){
		for(j = 1;j <= n; j++) {
			scanf("%d",&a[i][j]);
		}
	}

	//display the data as node to node cost
	for(i = 1;i <= n; i++) {
		printf("initial record of %d is \n",i); for(j = 1;j <= n; j++)
		printf("%d to %d is %d\n",i, j, a[i][j]);
	}

	//apply distance vector algorithm
	dist(a,n);

	//display updated data
	for(i = 1;i <= n; i++) {

		printf("updated record of %d is \n",i);

		for(j = 1;j <= n; j++){
			printf("%d to %d is %d\n",i, j, a [i][j]);
		}

	}

	//show node to node cost on demand.
	//nothing complicated below this. essentially program ends here.
	do {
		printf("enter 1 to find shortest path or 0 to exit n"); scanf("%d", &flag);
		if(flag == 0)
			printf("enter two nodes \n"); scanf("%d %d", &i, &j);
			printf("%d to %d is %d\n",i, j, a[i][j]);		
	}while(flag != 0); 
	exit(0); 
}