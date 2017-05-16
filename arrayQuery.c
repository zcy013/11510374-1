#include<stdio.h>
int outtaOrder(int[], int, int);
int inOrder(int[], int, int, int);
int main(void)
{
    int key1, key2, in1, in2;
    int len = 10;

    printf("Now query an out-of-order array\n");
    int nums1[] = {1, 10, 6, 296, 177, 23, 0, 100, 34, 999};
    printf("Please input an integer: ");
    scanf("%d", &key1);
    in1 = outtaOrder(nums1, len, key1);
    if(in1 < 0)
        printf("%d isn't in the array\n", key1);
    else
        printf("%d is in the array, and its subscript is %d\n", key1, in1);

    printf("\nNow query an in-order array\n");
    int nums2[] = {0, 1, 6, 10, 23, 34, 100, 177, 296, 999};
    printf("Please input an integer: ");
    scanf("%d", &key2);
    in2 = inOrder(nums2, 0, len-1, key2);
    if(in2 < 0)
        printf("%d isn't in the array\n", key2);
    else
        printf("%d is in the array, and its subscript is %d\n", key2, in2);

    return 0;
}

int outtaOrder(int* arr, int len, int key)
{
    int i;
    for(i = 0; i < len; ++i)
        if(arr[i] == key)
            return i;
    return -1;
}

int inOrder(int* arr, int start, int end, int key)
{
    while(start <= end){
        int mid = start + (end - start)/ 2;
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return -1;
}
