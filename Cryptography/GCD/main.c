#include <stdio.h>

int main() {
	int a,b,r1,r2,r,q;
	printf("GCD(a,b):\n");
	printf("a,b : ");
	scanf("%d%d",&a,&b);
	r1=a;r2=b;
	while(r2>0){
		q=r1/r2;
		r=r1-q*r2;
		r1=r2;
		r2=r;
	}
	printf("GCD(%d,%d) : %d",a,b,r1);
	return 0;
}
