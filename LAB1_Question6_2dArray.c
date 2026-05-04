#include <stdio.h>

int main()
{
    int marks[5][5];
    int i, j;
    int total;
    float percentage;

    for(j = 0; j < 5; j++)
    {
        printf("\nEnter marks for Student %d:\n", j + 1);
        for(i = 0; i < 5; i++)
        {
            printf("Subject %d: ", i + 1);
            scanf("%d", &marks[i][j]);
        }
    }

    
    printf("\nMarks Table:\n\n");
    printf("Subjects\\Students");

    for(j = 0; j < 5; j++)
        printf("\tStudent %d", j + 1);

    printf("\n");

    for(i = 0; i < 5; i++)
    {
        printf("Subject %d\t", i + 1);
        for(j = 0; j < 5; j++)
        {
            printf("%d\t\t", marks[i][j]);
        }
        printf("\n");
    }

    
    printf("\nTotal Marks and Percentage:\n");
    for(j = 0; j < 5; j++)
    {
        total = 0;
        for(i = 0; i < 5; i++)
            total += marks[i][j];

        percentage = (total / 500.0) * 100;

        printf("Student %d , Total = %d, Percentage = %.2f%%\n",
               j + 1, total, percentage);
    }

    return 0;
}
