#include<iostream>
#include<time.h>
#include<iomanip>
#include<cstdio>
#include<stdlib.h>

using namespace std;

void insertion_sort(long int*, long int, long int);
void selection_sort(long int*, long int, long int);
void bubble_sort(long int*, long int, long int);
void merge_sort(long int*, long int, long int);
void quick_sort(long int*, long int, long int);

typedef struct array_wrapper{
    long int *arr;
}Array;

void arr_print(long int *arr, long int n){
    for(long int i=0;i<n;i++){
        cout<<arr[i]<<' ';
    }
}

void timed_exec(void sort_func(long int*, long int, long int), Array array, long int n, char *disp_name){
    clock_t begin_time, end_time;
    double exec_time;

    cout<<"\n\n"<<setw(25)<<setfill('.')<<disp_name<<setw(25)<<setfill('.');
    begin_time = clock();
    sort_func(array.arr, 0, n-1);
    end_time = clock();
    exec_time = (double)(end_time-begin_time)/CLOCKS_PER_SEC;
//    cout<<"\nSorted Array:";
//    arr_print(array.arr, n);
    cout<<"\nExecution Time:"<<exec_time<<'s';
}

int main()
{
    long int n, i, ch, temp, seed;
    Array array;
    double exec_time;
    array.arr = new long int[100000];
    cout<<"Enter the size of the array:";
    cin>>n;
    cout<<"Enter a number to seed the random generator:";
    //cout<<"Enter a number to fill the array with:";
    cin>>seed;

    for(i=0;i<n;i++){
        array.arr[i] = rand();
    }
    srand(seed);
    cout<<"\nGenerating random numbers......";
    cout<<"\n\nFirst sorting the array using bubble sort";
    bubble_sort(array.arr, 0, n-1);
    //arr_print(array.arr, n);
    //for(i=0;i<n;i++){
     //   temp = rand();
//        cout<<"\nElement "<<i+1<<':'<<temp;
     //   array.arr[i] = temp;
   // }
////    cout<<"\nUnsorted array:";
////    arr_prlong int(array.arr, n);
    cout<<"\nNow Processing "<<n<<" records....";

    timed_exec(bubble_sort, array, n, "Bubble Sort");
    timed_exec(selection_sort, array, n, "Selection Sort");
    timed_exec(insertion_sort, array, n, "Insertion Sort");
    timed_exec(merge_sort, array, n, "Merge Sort");
    timed_exec(quick_sort, array, n, "Quick Sort");
    cin>>temp;
    return 0;
}
