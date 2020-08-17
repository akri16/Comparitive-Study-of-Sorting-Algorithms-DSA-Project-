#include<iostream>
using namespace std;

void merge(long int* arr, long int start, long int mid, long int end){
    long int i, j, k, L[100000], R[10000], m, n;

    m = mid-start+1;
    n = end-mid;
    for(i=start;i<=mid;i++){
        L[i-start] = arr[i];
    }
    for(i=mid+1;i<=end;i++){
        R[i-mid-1] = arr[i];
    }
    i=j=0;
    k=start;
    while(i<m && j<n){
        if(L[i]<=R[j]){
            arr[k] = L[i];
            i++;
        }
        else if(L[i]>R[j]){
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i<m){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(i<n){
        arr[k] = R[j];
        i++;
        k++;
    }
}

void merge_sort(long int *arr, long int start, long int end){
    long int mid;
    if(start>=end){
        return;
    }

    mid = start + (end-start)/2;
    merge_sort(arr, start, mid);
    merge_sort(arr, mid+1, end);
    merge(arr, start, mid, end);
}



