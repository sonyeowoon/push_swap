#include "push_swap.h"

int cnt_a_inner(int a_size, int a_cnt, int b_cnt, int bn, int i)
{
    int r;
    int min;

    if ((b_cnt != i && a_cnt > (a_size - a_cnt)) || (b_cnt == i && a_cnt <= (a_size - a_cnt)))
    if (a_cnt > (a_size - a_cnt))
    {
        a_cnt = a_size - a_cnt;
        r = -1;
    }
}

int cnt_a(t_node *a, int bn, int b_cnt, int i, int a_size)
{
    int a_cnt;
    int flg;
    int prev;
    int min;

    flg = 0;
    a_cnt = 0;
    while (a)
    {
        if (flg == 0 && bn > a->n)
            flg = 1;
        else if ((flg == 1 && (bn < a->n || prev > a->n)) || (flg == 0 && (prev > a->n && bn < a->n)))
            break ;
        a_cnt++;
        prev = a->n;
        a = a->next;
    }
    a_cnt = cnt_a_inner(a_size, a_cnt, b_cnt, bn, i);
}

int get_paidx(t_node *a, t_node *b, int a_size, int b_size)
{
    int min;
    int i;
    int b_cnt;
    int a_cnt;
    int min_idx;

    i = 0;
    b_cnt = 0;
    while (b)
    {
        b_cnt = i;
        if (i > (b_size - i))
            b_cnt = b_size - i;
        a_cnt = cnt_a(a, b->n, b_cnt, i, a_size);
        i++;
        b = b->next;
    }
}