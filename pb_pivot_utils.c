#include "push_swap.h"

void    find_pivot(t_node **a, int pivot[4])
{
    pivot[2] = get_min(*a);
    pivot[1] = find_median(*a, 0, 0, 0);
    pivot[0] = find_median(*a, 1, pivot[2], pivot[1]);
    pivot[2] = find_median(*a, 1, pivot[2], pivot[0]);
    pivot[3] = find_median(*a, 1, pivot[0], pivot[1]);
    pivot[0] = pivot[2];
    pivot[2] = pivot[1];
    pivot[1] = pivot[3];
    pivot[3] = get_max(*a);
    pivot[3] = find_median(*a, 1, pivot[2], pivot[3]);
    pivot[2] = find_median(*a, 1, pivot[2], pivot[3]);
    pivot[3] = find_median(*a, 1, pivot[3], get_max(*a));
}

int get_moveidx(t_node *a, int pivot[4], int quantile_top[5], int a_size, int b_size)
{
    int idx;
    int i;
    int cnt;
    int min_cnt;
    int r;

    i = 0;
    while (a)
    {
        cnt = i;
        r = 1;
        if (cnt > a_size - cnt)
            (r = -1), (cnt = a_size - cnt);
        if (a->n <= pivot[0])
        {
            if (quantile_top[0] <= quantile_top[4] && quantile_top[0] != 0)
                {
                }
            else if ()
        }
        if (cnt < min_cnt)
        {
            min_cnt = cnt;
            idx = i;
        }
        a = a->next;
        i++;
    }
    return (idx);
}

void    divide_pivot(t_node **a, t_node**b, int pivot[4])
{
    int quantile_top[5];
    int i;
    int a_size;
    int b_size;

    i = 0;
    while (i < 5)
    {
        quantile_top[i] = 0;
        i++;
    }
    a_size = ft_lstsize(*a);
    b_size = 0;
    while (a_size > 3)
    {
        get_moveidx(*a, pivot, quantile_top, a_size, b_size);
    }
}