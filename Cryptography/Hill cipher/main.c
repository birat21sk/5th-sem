#include<stdio.h>
#include<string.h>
#include<ctype.h>

int key[2][2]= {4,1,3,2};
char alpha[26]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";


int position(char s){
	int i;
	for(i=0;i<strlen(alpha);i++)	
		if(s == alpha[i])
		 	return i;
	return -1;
}

void pass(char a, char b){
	int x,y,i,j,r1,r2;
	x=position(a);
	y=position(b);
	
	//printf("%d%d ",x,y);
	
	//multiplication with key
	r1=(key[0][0]*x+key[0][1]*y)%26;
	r2=(key[1][0]*x+key[1][1]*y)%26;
	
	//printf("%d %d\n",r1,r2);
	printf("%c%c",alpha[r1],alpha[r2]);
}

int inverse(int a){
	int i,n=26,p,r;
	for(i=1;i<n;i++){
		p=a*i;
		r=p%26;
		if(r==1){
			return i;
		}
	}
	return -1;
}
 

int main(){
	int i,j,c,sel,t;
	char x='X';
	char text[100];
	
	int kinv[2][2],detk,detkinv,adk[2][2];
	//Key Input
	
//	printf("Key: \n");
//	for(i=0;i<2;i++){
//		for(j=0;j<2;j++){
//			printf("k[%d][%d]: ",i,j);
//			scanf("%d",&key[i][j]);
//		}
//	}
 
	printf("Text:" );
	gets(text);
	
	//remove space
	c=0;
	for(i=0;i<strlen(text);i++){
		if(text[i]!=' '){
			text[c++]=text[i];
		}
	}
	text[c]='\0';
	
	//to Upper case
	for(i=0;i<strlen(text);i++){
		text[i]=toupper(text[i]);
	}
	
	printf("%s\n\n",text);
	
	//select encryption decryption
	printf("!-----Hill Cipher-----!");
	printf("1.Encryption\n2.Decryption\n\nEnter choice: ");
	scanf("%d",&sel);
	if(sel==1){		//Encryption	
		for(i=0;i<strlen(text);i+=2){
			if(text[i+1]!='\0')
				pass(text[i],text[i+1]);
			else
				pass(text[i],x);
		}
	}
	else if(sel==2){			//Decryption
		detk=key[0][0]*key[1][1]-key[0][1]*key[1][0];
		if(detk > 0){
			detkinv=inverse(detk);
		}
		else{
			detk*=-1;
			t=((detk%26)-26)*-1;
			detkinv=inverse(t);
		}
		
	}
	else{
		printf("Make a valid choice!!");
	}
	
	return 0;
}




