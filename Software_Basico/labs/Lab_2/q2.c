#include <ctype.h>
#include <stdio.h>

int string2num(char *s)
{
    int a = 0;
    for (; *s; s++)
        a = a * 10 + (*s - '0');
    return a;
}

int string2num_qb(char *s, int n)
{
    int a = 0;
    for (; *s; s++)
        a = a * n + (*s - '0');
    return a;
}

int string2num_qc(char *s, int n)
{
    int a = 0;
    for (; *s; s++)
    {
        if (isdigit(*s))
        {
            a = a * n + (*s - '0');
        }
        else
        {
            a = a * n + ((*s - '0') + 10);
        }
    }

    return a;
}

int main(void)
{
    printf("==> %d\n", string2num("1234"));
    printf("==> %d\n", string2num("1234") + 1);
    printf("==> %d\n", string2num("1234") + string2num("1"));

    // b)
    printf("\nb)\n");
    printf("==> %d\n", string2num_qb("777", 8));
    printf("==> %d\n", string2num_qb("777", 10));

    // c)
    printf("\nc)\n");
    printf("==> %d\n", string2num_qc("1a", 16));
    printf("==> %d\n", string2num_qc("a09b", 16));
    printf("==> %d\n", string2num_qc("z09b", 36));
    return 0;
}