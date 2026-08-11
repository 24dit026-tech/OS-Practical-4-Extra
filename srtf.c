#include <stdio.h>

int main()
{
    int n, i, time = 0, completed = 0;
    int at[10], bt[10], rem[10], ct[10], wt[10], tat[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("P%d Arrival Time: ", i + 1);
        scanf("%d", &at[i]);

        printf("P%d Burst Time: ", i + 1);
        scanf("%d", &bt[i]);

        rem[i] = bt[i];
    }

    while(completed < n)
    {
        int min = 9999, p = -1;

        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && rem[i] > 0 && rem[i] < min)
            {
                min = rem[i];
                p = i;
            }
        }

        if(p == -1)
        {
            time++;
            continue;
        }

        rem[p]--;
        time++;

        if(rem[p] == 0)
        {
            ct[p] = time;
            tat[p] = ct[p] - at[p];
            wt[p] = tat[p] - bt[p];
            completed++;
        }
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}
