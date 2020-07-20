#include <iostream>
using namespace std;

int main() {
   int a[10][10], t[10][10], row, column, i, j;

   cout<<"Enter no. of rows and columns of matrix: ";
   cin>>row>>column;

   cout<<"\nEnter the elements of matrix: "<<endl;

   for (int i = 0; i < row; ++i) {
      for (int j = 0; j < column; ++j) {
         cout<<"Enter matrix element:";
         cin>>a[i][j];
      }
   }

   cout << "\nEntered Matrix: " << endl;
   for (int i=0; i<row;i++) {
      for (int j=0; j<column;j++) {
         cout<< " " <<a[i][j];
         if (j==column - 1)
            cout << endl << endl;
      }
   }
   
   for (int i=0;i<row;i++)
      for (int j=0;j<column;j++) {
         t[j][i] = a[i][j];
      }

   cout << "\nTranspose of Matrix: " << endl;
   for (int i=0; i<column;i++)
      for (int j=0;j<row;j++) {
         cout << " " << t[i][j];
         if (j == row-1)
            cout << endl << endl;
      }

   return 0;
}
