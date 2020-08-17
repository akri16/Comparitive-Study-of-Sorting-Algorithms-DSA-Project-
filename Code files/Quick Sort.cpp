/**Reference:
*@Link: https://www.youtube.com/watch?v=7h1s2SojIRw
*/

#include<iostream>
using namespace std;

void swap(long int *a, long int *b){
    long int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int partition(long int *arr, long int start, long int end){
    long int i=start+1, j=end, pivot=arr[start];

    while(i<j){
        while(arr[i]<=pivot)
            i++;
        while(arr[j]>pivot)
            j--;
        if(i<j){
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[start], &arr[j]);
    return j;
}

void quick_sort(long int *arr, long int start, long int end){
    long int part;

    if(start>=end){
        return;
    }
    part = partition(arr, start, end);
    quick_sort(arr, start, part-1);
    quick_sort(arr, part+1, end);
}


