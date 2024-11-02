#include<stdio.h>

int main()
{
    /// id, value, deadline
    int job[5][3] = {
        {1, 50, 3},
        {2, 100, 2},
        {3, 40, 3},
        {4, 60, 1},
        {5, 80, 2}
    };

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            if(job[i][1]>job[j][1])
            {
                int sl = job[i][0];
                int val = job[i][1];
                int dl = job[i][2];

                job[i][0] = job[j][0];
                job[i][1] = job[j][1];
                job[i][2] = job[j][2];

                job[j][0] = sl;
                job[j][1] = val;
                job[j][2] = dl;
            }
        }
    }
    for(int i=0; i<5; i++)
    {
        printf("%d %d %d\n", job[i][0],job[i][1],job[i][2]);
    }

    int schedule[4];
    for(int i=0; i<4; i++)
    {
        schedule[i] = -1;
    }

    for(int i=0; i<5; i++)
    {
        for(int j=job[i][2]; j>=1; j--)
        {
            if(schedule[j]==-1)
            {
                schedule[j] = i; //job[i][0];
                break;
            }
        }
    }
    printf("\n\n");

    int totalProfit = 0;
    for(int i=1; i<4; i++)
    {
        printf("%d %d\n", schedule[i], job[schedule[i]][1]);

        totalProfit += job[schedule[i]][1];
    }
    printf("\nTotal profit = %d \n", totalProfit);
}