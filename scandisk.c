/*SCAN disk scheduling algorithm*/
#include <stdio.h>
int main()
{
    int a[20], b[20], n, i, j, temp, p, s, m, x, t = 0;
    printf("Enter head pointer position:");
    scanf("%d", &a[0]);
    s = a[0];
    printf("\nEnter previous head position:");
    scanf("%d", &p);
    printf("\nEnter max track limit:");
    scanf("%d", &m);
    printf("\nEnter number of processes:");
    scanf("%d", &n);
    printf("\nEnter processes in request order");
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    a[n + 1] = m;
    a[n + 2] = 0;
    for (i = n + 1; i >= 0; i--)
    {
        for (j = 0; j <= i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    for (i = 1; i <= n + 1; i++)
    {
        if (s == a[i])
            x = i;
    }
    j = 0; i--;
    if (s)
    {
        t += (a[i] - a[i - 1]);
        b[j++] = a[i];

        t += a[x + 1] - a[0];
        b[j++] = a[0];
        for (i = x + 1; i < n + 1; i++)
        {
            t += (a[i + 1] - a[i]);
            b[j++] = a[i];
            b[j++] = a[i];
        }
    }
    else
    {
        for (i = x; i < n + 2; i++)
        {
            t += (a[i + 1] - a[i]);
            b[j++] = a[i];
        }
        t += a[n + 2] - a[x - 1];
        b[j++] = a[n + 2];
        for (i = x - 1; i > 1; i--)
        {
            t += (a[i] - a[i - 1]);
            b[j++] = a[i];
        }
        b[j++] = a[i];
    }
    printf("\nProcessing order:");
    for (i = 0; i <= n + 1; i++)
        printf("%d->", b[i]);
    printf("\n\nTotal Head Movement:%d", t);
    return 0;
}
