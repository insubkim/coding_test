#include <stdio.h>
#include <string.h>

int set_num_arr(int num[])
{
    int size;
    int i;

    scanf("%d", &size);
    i = 0;
    while (i < size)
        scanf("%d", &(num[i++]));
    return (size);
}

void    print(int num[], int size)
{
    while (size-- > 0)
        printf("%d\n", *num++);
}

int tmp[1000000] = {0,};

int *merge(int *tmp1, int *tmp2, int t1_size, int t2_size)
{
    
    int i;
    int j;
    int k;

    i = j = k = 0;
    while (j < t1_size && k < t2_size)
    {
        if (tmp1[j] <= tmp2[k])
            tmp[i++] = tmp1[j++];
        else
            tmp[i++] = tmp2[k++];        
    }
    while (j < t1_size)
        tmp[i++] = tmp1[j++];
    while (k < t2_size)
        tmp[i++] = tmp2[k++];
    i = 0;
    while (i < t1_size + t2_size)
    {
        tmp1[i] = tmp[i];
        i++;
    }
    return (tmp1);
}

int *merge_sort(int *num, int size)
{
    int mid;
    int *tmp1;
    int *tmp2;

    if (size > 1)
    {
        mid = size / 2;
        tmp1 = merge_sort(num, mid);
        tmp2 = merge_sort(num + mid, size - mid);
        num = merge(tmp1, tmp2, mid, size - mid);
    }
    return (num);
}

int main(int argc, char *argv[])
{
    int size;
    int num[1000000] = {0,};

    //get num
    size = set_num_arr(num);
    //sort num
    merge_sort(num, size);
    //print num
    print(num, size);
    return (0); 
}