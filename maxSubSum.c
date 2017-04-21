//11510374 周宸宇

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define NUM 10000 // 随机数个数
#define SCALE 40 // 随机数范围
#define FILELOC "R:\\maxSubSum.txt" // 随机生成的数组

int divAndCon(int arr[], int start, int end);
int dyn(int arr[], int number);
int max3(int a, int b, int c);
void rand_arr(int arr[], int n);
void print_arr(int arr[], int n);
int main(void)
{
    int arr1[NUM], arr2[NUM];
    FILE *fp;
    int persize = sizeof(int);
    if((fp = fopen(FILELOC, "wb+")) == NULL)
    {
        printf("Error on open %s !", FILELOC);
        system("pause");
        exit(1);
    }

    rand_arr(arr1, NUM);
    fwrite(arr1, persize, NUM, fp);
    rewind(fp);
    fread(arr2, persize, NUM, fp);
    fclose(fp);
    printf("Arr1 is a random generated array\n");
    printf("Store arr1 in a file then read the file to generate arr2\n");
    printf("Thus data in arr1 and arr2 should be exactly the same\n\n");
    printf("Use Divide and Conquer to calculate LIS of arr1\n");
    printf("The result is %d\n", divAndCon(arr1, 0, NUM - 1));
    printf("And use dynamic programming to calculate LIS of arr2\n");
    printf("The result is %d\n", dyn(arr2, NUM));
    printf("Equality of the two results means validity of this program\n");
    return 0;
}

int divAndCon(int arr[], int start, int end)// 分治法
{
    if(start == end)
        return arr[start] > 0 ? arr[start] : 0;
    else
    {
        int mid = start + (end - start)/ 2;
        int leftMax = divAndCon(arr, start, mid);// 左子段最大和
        int rightMax = divAndCon(arr, mid+1, end);// 右子段最大和
        int sum, midMax, midLeft, midRight, i;
        for(i = mid, sum = 0, midLeft = 0; i>= start; --i)// 包含左中点的左子段最大和
        {
            sum += arr[i];
            if(sum > midLeft)
                midLeft = sum;
        }
        for(i = mid+1, sum = 0, midRight = 0; i <= end; ++i)// 包含右中点的右子段最大和
        {
            sum += arr[i];
            if(sum > midRight)
                midRight = sum;
        }
        midMax = midLeft + midRight;// 包含中点的最大子段和
        return max3(leftMax, midMax, rightMax);
    }
}

int dyn(int arr[], int number)// 动态规划法
{
    int sum, b, i;
    for(i = 0, b = 0, sum = 0; i < number; ++i)
    {
        b += arr[i];
        if(b < 0)
            b = 0;
        if(b > sum)
            sum = b;
    }
    return sum;
}

int max3(int a, int b, int c)// 返回三个数中最大值
{
    if(a >= b)
    {
        if(a >= c)
            return a;
        return c;
    }
    if(b >= c)
        return b;
    return c;
}

void rand_arr(int arr[], int n)// 随机生成数组
{
    srand(time(NULL));
    int i;
    for(i = 0; i < n; ++i)
        arr[i] = rand() % SCALE - SCALE / 2;
}

void print_arr(int arr[], int n)// 打印数组
{
    int i;
    for(i = 0; i < n; ++i)
    {
        printf("%3d ", arr[i]);
        if((i + 1) % 15 == 0)
            putchar('\n');
    }
    putchar('\n');
}
