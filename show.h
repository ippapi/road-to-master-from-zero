#include <iostream>
using namespace std;
void show(int x, int *arr){
    for(int i=0;i<x;i++){
        if(arr[i]==1){
            cout<<"A ";
        }else if(arr[i]==11){
            cout<<"J ";
        }else if(arr[i]==12){
            cout<<"Q ";
        }else if(arr[i]==13){
            cout<<"K ";
        }else{
            cout<<arr[i]<<" ";
        }
    }
    cout<<"\n";
}