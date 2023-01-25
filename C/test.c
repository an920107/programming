#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 200000
#define MAX_LINE 1024
//#define INFINITE 1000000

void swap(int *x, int *y){
    // 變數為address
    int temp;
    temp=*y;
    *y=*x;
    *x=temp;
}

void Merge(int arr[], int front, int mid, int end){
    int left_index = front;
    int right_index = mid+1;
    int tempArr_size = end-front+1;
    int tempArr[MAX_SIZE];
    int tempArr_index = 0;
    int arr_index;

    while(left_index <= mid && right_index <= end){
        if(arr[left_index] <= arr[right_index]){
            tempArr[tempArr_index] = arr[left_index];
            left_index++;
        }
        else{
            tempArr[tempArr_index] = arr[right_index];
            right_index++;
        }
        tempArr_index++;
    }
    if(left_index > mid){
        while(right_index <= end){
            tempArr[tempArr_index]=arr[right_index];
            right_index++;
            tempArr_index++;
        }
    }
    if(right_index > end){
        while(left_index <= mid){
            tempArr[tempArr_index] = arr[left_index];
            left_index++;
            tempArr_index++;
        }
    }
    arr_index = front;
    for(tempArr_index = 0;tempArr_index < tempArr_size;tempArr_index++){
        arr[arr_index] = tempArr[tempArr_index];
        arr_index++;
    }
}
void Merge_sort(int arr[], int front, int end){
    if(front < end){
        int mid = (front+end)/2;
        Merge_sort(arr, front, mid);
        Merge_sort(arr, mid+1, end);
        Merge(arr, front, mid, end);
        if(mid == 0){
            printf("First pass: ");
            for(int i=0;i<=20;i++){
                if(i == 20){
                    printf("\n");
                    break;
                }
                printf("%d ", arr[i]);
            }
        }
        if(mid == 1){
            printf("Second pass: ");
           for(int i=0;i<=20;i++){
                if(i == 20){
                    printf("\n");
                    break;
                }
                printf("%d ", arr[i]);
            } 
        }
    }
}

void Radix_sort(int arr[]){}

int main()
{
    int arr[MAX_SIZE];
    char striline[MAX_LINE];
    int front = 0;
    int end = sizeof(arr) / sizeof(int);
    // or int end = sizeof(a) / sizeof(int);
    FILE *fptr;
    fptr = fopen("sort的input file.txt", "r");
    if(fptr == NULL){
        printf("%s\n", "Failed.");
        return -1;
    }
    int i=0;
    while(!feof(fptr)){
        fgets(striline, MAX_LINE, fptr);
        //printf("%s", striline);
        arr[i] = atoi(striline);
        i++;
    }
    // int arr[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    printf("%d\n", end);
    printf("\n");
    Merge_sort(arr, 0, end);
    /*printf("%d\n", arr[0]);
    printf("%d\n", arr[1]);
    printf("%d\n", arr[2000]);
    printf("%d\n", arr[2001]);*/
    printf("\n");
    return 0;
}