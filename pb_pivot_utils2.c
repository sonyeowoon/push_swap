#include "push_swap.h"

static void get_topbot_inner(t_node *b, int i, int pivot[4], int *top, int *bot)
{
    int j;
    t_node  *temp;
    int top_flg;
    int bot_flg;

    temp = b;
    top_flg = 0;
    bot_flg = 0;
    j = 0;
    while ((top_flg == 0 || bot_flg == 0) && j < 3)
    {
        j++;
    }
}

void    get_topbot(t_node *b, int i, int pivot[4], int *top, int *bot)
{
    int j;
    int flg;
    t_node  *temp;

    temp = b;
    flg = 0;
    j = 0;
    while (b)
    {
        if (flg == 0 && ((i == 0 && (b->n <= pivot[0])) || (i != 0 && ((b->n > pivot[i - 1]) && (b->n <= pivot[i])))))
            (*top = j), (flg = 1);
        else if (flg == 1 && !((i == 0 && (b->n <= pivot[0])) || (i != 0 && ((b->n > pivot[i - 1]) && (b->n <= pivot[i])))))
            (*bot = j), (flg = 2), break;
        j++;
        b = b->next;
    }
    if (flg == 0)
        get_topbot_inner(temp, i, pivot, top, bot);
    else if (flg == 1)
        *bot = j;
}

