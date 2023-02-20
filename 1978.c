
#include <stdio.h>
#include <stdlib.h>

/*
    제곱근 혹은 그보다 큰 가장 작은 자연수 반환
*/
int	sqrts(int nb)
{
	unsigned int	i;
	unsigned int	u_nb;

	if (nb <= 0)
		return (0);
	i = 1;
	u_nb = nb;
	while (i * i < u_nb)
		i++;
	return (i);
}

int	ft_is_prime(int nb)
{
	int	sq;
	int	i;

	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	sq = sqrts(nb);
	i = 2;
	while (i <= sq)
	{
		if (nb % i++ == 0)
			return (0);
	}
	return (1);
}

int main()
{
    int n;
    int *arr;

    scanf("%d", &n);
    arr = (int *)malloc(sizeof(int) * n);
    if (!arr)
        return (0);
    int i = 0;
    while (i < n)
        scanf("%d", &(arr[i++]));
    i = 0;
    int cnt = 0;
    while (i < n)
        if (ft_is_prime(arr[i++]))
            cnt++;
    printf("%d", cnt);       
}