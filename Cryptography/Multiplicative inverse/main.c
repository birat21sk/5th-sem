#include <stdio.h>

int main() {
	int n,b,r1,r2,r,q;
	int t1=0,t2=1,t;
	
	printf("n (Zn):");
	scanf("%d",&n);
	printf("b:");
	scanf("%d",&b);
	
	r1=n;r2=b;
	
	while(r2>0){
		q=r1/r2;
		r=r1-q*r2;
		r1=r2;
		r2=r;
		t=t1-q*t2;
		t1=t2;
		t2=t;
	}
	if(r1==1){
		printf("Multiplicative inverse of %d in Z%d is: ",b,n);
		if(t1>0)
			printf("%d",t1%n);
		else{
			t1*=-1;
			printf("%d",((t1%n)-n)*-1);	
		}
			
	}
	
	return 0;
}
