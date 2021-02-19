#include<iostream>
using namespace std;
void divideThenMerge(int arr[],int low,int high);
void mergeSort(int arr[], int low,int mid, int high);
void printArray(int arr[],int arrSize);
int main(){
    int arr[]={5,1,2,8,9,4,6,3,7,10};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    divideThenMerge(arr,0,arrSize-1);
    for(int i=0;i<arrSize;i++){
        cout<<arr[i]<<" ";
    }
}
/* 4 1 0 0 1 3 */
void divideThenMerge(int arr[],int low, int high){
    printArray(arr,high+1);
    int mid; mid=(low)+(high-1)/2;
    if(low<high){
        divideThenMerge(arr,low,mid);
        divideThenMerge(arr,mid+1,high);
        mergeSort(arr,low,mid,high);
       }
}
void mergeSort(int arr[],int low, int mid,int high){
    int firstArrSize = mid-low+1;
    int secArrSize = high-mid;
    int firstArr[firstArrSize], secArr[secArrSize];
    int i,j,k;
    for(i=0;i<firstArrSize;i++){
        firstArr[i]= arr[low+i];
    }
    for(j=0;j<secArrSize;j++){
        secArr[j]= arr[mid+1+j];
    }
    i=0;j=0;k=0;
    while(i<firstArrSize && j<secArrSize){
        if(firstArr[i]>secArr[j]){
            arr[k++]=secArr[j++];
        }
        else if(firstArr[i]<secArr[j]){
            arr[k++]=firstArr[i++];
        }
    }
    while(i<firstArrSize){
        arr[k++]= firstArr[i++];
    }
    while(j<secArrSize){
        arr[k++]= secArr[j++];
    }
}
void printArray(int arr[], int arrSize){
    for(int i=0;i<arrSize;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

