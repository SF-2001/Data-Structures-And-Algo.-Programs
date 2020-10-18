#include<iostream>
using namespace std;
#define max 15
int stack[max],top=-1,count=0;

void push(int);
void pop();
int initialise();
void display();

int main(){
	int res = initialise();
	cout<<"No. of matched pairs:"<<endl<<count/2;
	cout<<"No. of unmatched pairs:"<<res-count;
}
int initialize(){
	int i,size,element;
	cout<<"Enter the no. of elements:";
	cin>>size;
	cout<<"\n";
	for(i=0;i<size;i++){
		cout<<"Enter the element:";
		cin>>element;
		push(element);
	}
	for(i=0;i<size-1;i++){
		if(stack[i]==stack[i+1]){
			count++;
		}
	}
	return size;
}
void push(int item){
	if(top==max){
		cout<<"Stack Overflow";
	}else{
		top+=1;
		stack[top]=item;
	}
}
void pop(){
	if(top==-1){
		cout<<"Stack is empty now!\n";
	}else{
		top=top-1;
	}
}
void display(){
	int i;
	for(i=0;i<=top;i++){
		cout<<stack[i];
	}
	cout<<"\n";
}
