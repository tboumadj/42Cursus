#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>

int		ft_list_size(t_list *begin_list)
{
	t_list *list;
	int i;

	list = begin_list;
	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

int	main(void)
{
    int n = 0;

 	t_list *c = malloc(sizeof(t_list));
 	c->next = 0;
 	c->data = &n;

 	t_list *b = malloc(sizeof(t_list));
 	b->next = c;
 	b->data = &n;

 	t_list *a = malloc(sizeof(t_list));
 	a->next = b;
 	a->data = &n;

 	printf("%d\n", ft_list_size(a));
 }