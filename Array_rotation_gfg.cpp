#include<iostream>
using namespace std;
void rotarray(){
	
}

int main(){
	int n=7;
	int arr[]={1,2,3,4,5,6,7};
	int s = 3;
	int d[s];
	int i,j;
	cout<<"Array before rotation:"<<endl;
	for(i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	cout<<"\n";
	for(i=0;i<s;i++){
		d[i] = arr[i];
	}
	for(i=0;i<n-1;i++){
		arr[i]=arr[s+i];
	}
	for(j=0;j<s;j++){
		arr[n-s+j]=d[j];
	}
	cout<<"Array after rotation:"<<endl;
	for(i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}
