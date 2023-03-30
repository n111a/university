#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;
void polinom(int length, int *arr, int *arr2) 
{
    int i,j;
    for(i=0;i<length;i++)   
    {
        arr2[i]=arr[0]; 
        
        for(j=0;j<length;j++)
        {
            arr[j]=(arr[j]+arr[j+1])%2; 
        }
    }
}
void bin(int j, int n, int **arr3)
{   
   int i;
    for(i=0;i<n;i++){     
        (*arr3)[n-1-i]= j%2;
        j=j/2;
    }
}
int main(int argc, char *argv[])
{
    int k, n, length=1, i, j, m, f=0;
    freopen(argv[1], "r", stdin);
    freopen(argv[2], "w", stdout);
    cin >> k;
    cin >> n;
    for(i=0;i<n;i++) length*=k;  
    int *arr = new int[length]; 
    int *arr2 = new int[length]; 
    cin >> m;
    for(i=0;i<length;i++)  
    {
        arr[length-1-i]=m%10;
        m=m/10;
    }
    polinom(length, arr, arr2); 
    for(i=0; i<length; i++)
    if(arr2[i]>0) f++;
    cout << k << " " << n << " " << f << endl;
    int *arr3= new int[n];
     for(i=0;i<length;i++) 
	  {
        if(arr2[i]>0) 
        {
           bin(i, n, &arr3); 
           for(j=0;j<n;j++) 
                cout << arr3[j];
            cout << " " << arr2[i] << endl;
         }
      }
    return 0;
   }
