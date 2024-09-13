#include "push_swap.h"

void    find_pivot(t_node **a, int pivot[4])
{
    pivot[2] = get_min(*a);
    pivot[1] = find_median(*a, 0, 0, 0);
    pivot[0] = find_median(*a, 1, pivot[2], pivot[1]);
    pivot[2] = find_median(*a, 1, pivot[2], pivot[0]);
    pivot[3] = find_median(*a, 1, pivot[0], pivot[1]);
    pivot[0] = find_median(*a, 1, pivot[2], pivot[0]);
    pivot[2] = pivot[1];
    pivot[1] = pivot[3];
    pivot[3] = get_max(*a);
    pivot[3] = find_median(*a, 1, pivot[2], pivot[3]);
    pivot[2] = find_median(*a, 1, pivot[2], pivot[3]);
    pivot[3] = find_median(*a, 1, pivot[3], find_median(*a, 1, pivot[3], get_max(*a)));
}

void    divide_pb_inner(t_node **a, t_node **b, int pivot[4], int *a_size)
{
    int cnt;

    cnt = *a_size;
    while (cnt != 0 && !(chk_ascending(*a)))
    {
        if ((**a).n <= pivot[0] || ((**a).n > pivot[2] && (**a).n <= pivot[3]))
        {
            ft_push("pb", a, b);
            (*a_size)--;
            if ((**b).n <= pivot[0])
                ft_rotate("rb", b);
        }
        else
            ft_rotate("ra", a);
        cnt--;
    }
}

void    divide_pb(t_node **a, t_node **b, int pivot[4], int *a_size)
{
    int cnt;

    cnt = *a_size;
    while (cnt != 0 && !(chk_ascending(*a)))
    {
        if ((**a).n > pivot[0] && (**a).n <= pivot[2])
        {
            ft_push("pb", a, b);
            (*a_size)--;
            if ((**b).n <= pivot[1])
                ft_rotate("rb", b);
        }
        else
            ft_rotate("ra", a);
        cnt--;
    }
    divide_pb_inner(a, b, pivot, a_size);
}

void    divide_pivot(t_node **a, t_node**b, int pivot[4])
{
    int a_size;

    a_size = ft_lstsize(*a);
    if (a_size >= 10)
        divide_pb(a, b, pivot, &a_size);
    while (a_size > 3 && !(chk_ascending(*a)))
    {
        ft_push("pb", a, b);
        a_size--;
    }
}