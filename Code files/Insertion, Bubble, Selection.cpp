
#include<iostream>
using namespace std;

void bubble_sort(long int *arr, long int start, long int end){
    long int i, j, temp, n=end+1;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j] ;
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selection_sort(long int *arr, long int start, long int end){
    long int i, j, temp, n=end+1;
    long int smallest;
    for(i=0;i<n-1;i++){
            smallest=i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[smallest]){
                smallest = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;
    }
}

void insertion_sort(long int *arr, long int start, long int end){
    long int i, j, temp, n=end+1;
    for(i=0;i<n;i++){
        temp = arr[i];
        j = i;

        while(j>0 && temp<arr[j-1]){
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = temp;
    }
}


