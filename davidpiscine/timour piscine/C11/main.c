#include <stdio.h>

int	ft_is_sort(int *tab, int length, int (*f)(int, int));

int sort(int nb1, int nb2)
{
    return (nb1 - nb2);
}

int main()
{
    int test[100] = {1, 2, 3, 4, 5, 6, 0};
    printf("%d\n", ft_is_sort(test, 7, sort));
    
    return 0;
}