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
    int len[length];// �Ե�ǰԪ��Ϊ��β�ĵ����Ӷεĳ���
    int pre[length];// �Ե�ǰԪ��Ϊ��β�ĵ����Ӷε���һԪ�أ���������
    for(i = 0; i < length; ++i)// ��ʼ��������
    {
        len[i] = 1;
        pre[i] = i;
    }
    for(i = 1, end = 0, max = 1; i < length; ++i)// ȷ��������i��Ԫ�ؽ�β��������Ӷ�
    {
        for(j = 0; j < i; ++j)// ��ǰ����ȷ�����Ӷ�
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
