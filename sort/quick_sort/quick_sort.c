#include <stdio.h>

void quick_sort(int arr[],int low,int high){

    int i,j,temp;
    if (low > high){
        return;
    }

    i = low;
    j = high;

    temp = arr[low];

    while (i < j){
        while (temp <= arr[j] && i<j){
            j--;
        }
        while (temp >= arr[i] && i<j){
            i++;
        }

        if (i < j){
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }

    arr[low] = arr[i];
    arr[i] = temp;

    quick_sort(arr,low,j-1);
    quick_sort(arr,j+1,high);
}

int main(){

    int arr[] = {3,1,2,5,4,6,9,7,10,8};
    quick_sort(arr,0,sizeof arr/sizeof(int));
    for (int i = 0; i < sizeof arr/sizeof(int); ++i) {
        printf("%d\n",arr[i]);
    }

    return 0;
}
