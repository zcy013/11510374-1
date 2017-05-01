#include<stdio.h>
int main(void)
{
    int arr[] = {4, 3, 12, 30, 13, 14, 55, 44, 48, 57, 30};
    int *re;
    int len = liss(arr, 11, re);
    int i;
    for(i = 0; i < len; ++i)
    {
        printf("%2d ", re[i]);
    }
    return 0;
}

int liss(int *arr, int length, int *re)
{
    int i, j, end, max;
    int len[length];// 以当前元素为结尾的递增子段的长度
    int pre[length];// 以当前元素为结尾的递增子段的上一元素（的索引）
    for(i = 0; i < length; ++i)// 初始化两数组
    {
        len[i] = 1;
        pre[i] = i;
    }
    for(i = 1, end = 0, max = 1; i < length; ++i)// 确定以索引i处元素结尾的最长递增子段
    {
        for(j = 0; j < i; ++j)// 向前找已确定的子段
        {
            if(arr[i] > arr[j] && len[i] < len[j] + 1)
            {
                len[i] = len[j] + 1;
                pre[i] = j;
                if(max < len[i])
                {
                    max = len[i];
                    end = i;
                }
            }
        }
    }
    for(i = max - 1; i >= 0; --i)
    {
        re[i] = arr[end];
        end = pre[end];
    }
    return max;
}
