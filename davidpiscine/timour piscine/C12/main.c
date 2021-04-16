#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>
void print_node(t_list *begin_list);
t_list *ft_list_push_strs(int size, char **strs);


void freef(void *data)
{
    printf("%s\n", data);
}

int main(void)
{
    t_list  *list = 0;
    char *tab[100] = {"jarvis", "tom", "lea", "yannah"};
   
    list = ft_list_push_strs(4, tab);
    printf("------------------------------------------\n");
    print_node(list);
    printf("------------------------------------------\n");
    return (0);
}