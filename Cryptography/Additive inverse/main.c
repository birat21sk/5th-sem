#include <stdio.h>

int main() {
	int n,i,j;
	printf("n (Zn): ");
	scanf("%d",&n);
	printf("All additive pairs in z%d:\n\n",n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if((i+j)%n==0){
				printf("(%d,%d),",i,j);
			}
		}
	}
	return 0;
}
