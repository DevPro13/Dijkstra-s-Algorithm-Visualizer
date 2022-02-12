#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){
	int *ptr=(int*)malloc(sizeof(int));
	*ptr=0;
	cout<<*ptr<<endl;
	*ptr+=1;
	cout<<*ptr<<endl;
	*ptr+=1;
	cout<<*ptr<<endl;
	*ptr+=1;
cout<<*ptr<<endl;


	return 0;
}
