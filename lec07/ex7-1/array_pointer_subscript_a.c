#include <stdio.h>

int main(){

/* variable declaration */
int a[5]={10,20,30,40,50};
int *p; /* pointer */
int i;

/* processing contents */
p = a; /* assign start

address into pointer */

for(i=0; i < 5; i++){
	printf("a[%d] = %d \n",i, a[i]);
}

return 0;
}
