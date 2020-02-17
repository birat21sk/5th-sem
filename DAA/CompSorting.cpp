#include <iostream>
#include <ctime>
#include <time.h>

using namespace std;
time_t req;
void selection(int ar[],int n){

	int imin,temp;
	req =clock();
	for(int i=0;i<n-1;i++){
		imin=i;
		for(int j=i+1;j<n;j++){
			if(ar[imin]>ar[j])
				imin=j;
		}
		temp=ar[i];
		ar[i]=ar[imin];
		ar[imin]=temp;
	} 
	req = clock()-req;
	for(int i=0;i<n;i++)
		cout<<ar[i]<<" ";
	cout<<"Time taken: "<<(float)req/CLOCKS_PER_SEC; 
}

void bubble(int ar[],int n){
	int temp;
	req =clock();
	for(int i=0;i<n;i++){
		for(int j = 0;j<n-i-1;j++){
			if(ar[j+1]<ar[j]){
				temp=ar[j+1];
				ar[j+1]=ar[j];
				ar[j]=temp;
			}
		}
	}	
	req =clock()-req;
	for(int i=0;i<n;i++)
		cout<<ar[i]<<" ";
	cout<<"Time taken: "<<(float)req/CLOCKS_PER_SEC; 
}

void insertion(int ar[],int n){
	int temp;
	req =clock();
	for(int i=0;i<n;i++){
		for(int j=i;j>0;j--){
			if(ar[j-1]>ar[j]){
				temp=ar[j]	;
				ar[j]=ar[j-1];
				ar[j-1]=temp;
			}
		}	
	}	
	req =clock()-req;	
	for(int i=0;i<n;i++)
		cout<<ar[i]<<" ";
	cout<<"Time taken: "<<(float)req/CLOCKS_PER_SEC; 
}


int main() { 
	int n,ar[100];
	cout<<"Number of elements in list: ";
	cin>>n;
	
	for(int i=0;i<n;i++){
		cout<<"list["<<i+1<<"]: ";
		cin>>ar[i];
	} 
	
	cout<<"Selection sort!!"<<endl;
	selection(ar,n);
	cout<<"\n\n"<<"Bubble sort!!"<<endl;
	bubble(ar,n);
	cout<<"\n\n"<<"Insertion sort!!"<<endl;
	insertion(ar,n);
	return 0;
}
