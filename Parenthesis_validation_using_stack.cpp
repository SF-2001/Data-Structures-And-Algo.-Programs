#include<iostream>
#include<string.h>
using namespace std;
#define max 30

int top=-1;
char stack[max];

void push(char x){
	top+=1;
	stack[top]=x;
}

void pop(char t){
	if(t=='}'){
		if(stack[top]=='{')
			top-=1;
		
	}
	else if(t==')'){
		if(stack[top]=='(')
			top-=1;
		
	}
	else if(t==']'){
			if(stack[top]=='[')
				top-=1;
			
	}
  }
  void display(){
  	int i;
  	if(top==-1)
  	  cout<<"Balanced Paranthesis";
  	else{
  	  cout<<"Un-Balanced Paranthesis";
	  }  
  }
  int main()
  {
  	char exp[20],x,t;
  	int k,i;
  	cout<<"Enter a expression:";
  	cin>>exp;
  	k = strlen(exp);
  	for(i=0;i<k;i++){
  		if((exp[i]=='{')||(exp[i]=='(')||(exp[i]=='['))
		  {
              x = exp[i];
			  push(x);			
		  }
		else if((exp[i]=='}')||(exp[i]==')')||(exp[i]==']'))
		{
 			t = exp[i];
 			pop(t);
		}
    }
		display();
		return 0;
	}

