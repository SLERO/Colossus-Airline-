#include <stdio.h>
#include "secondary_funk.h"
#include "head_crab.h"

void line_painter (char bord)
{
    int i;
    int end = 56;

    for (i = 0; i < end; i++)
        putc(bord, stdout);
    putc('\n',stdout);
}


void cleaner_input (void)
{
    while (getchar() != '\n')
        continue;
}

int race_num_check (int fly_num)
{
    int check[5] = {102,311,444,519,999};
    int z , rrr;

    for (z = 0; z < 5; z++)
            {
                if (fly_num == z)
                    {
                        rrr = check[z];
                        break;
                    }
            }

    return rrr;
}
