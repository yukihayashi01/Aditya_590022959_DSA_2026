#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student 
{
    char name[20];
    int roll_number;
    float marks;
    long DOB; 
};

int main() 
{
    int n;
    struct Student *s;

    printf("How many students?? ");
    scanf("%d", &n);
    getchar(); 

    s = (struct Student*)malloc(n * sizeof(struct Student));

    if (s == NULL) 
    {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (int i = 0; i < n; i++) 
    {
        printf("\n--- Student %d ---\n", i + 1);

        printf("Enter student name: ");
        fgets(s[i].name, sizeof(s[i].name), stdin);
        s[i].name[strcspn(s[i].name, "\n")] = 0; 

        printf("Enter roll number: ");
        scanf("%d", &s[i].roll_number);

        printf("Enter marks: ");
        scanf("%f", &s[i].marks);

        printf("Enter DOB in DDMMYYYY format: ");
        scanf("%ld", &s[i].DOB);
        getchar();
    }

    printf("\n%-20s %-10s %-10s %-10s\n", "NAME", "ROLL", "MARKS", "DOB");
    printf("----------------------------------------------------\n");

    for (int i = 0; i < n; i++) 
    {
        printf("%-20s %-10d %-10.2f %08ld\n", 
               s[i].name, s[i].roll_number, s[i].marks, s[i].DOB);
    }
    free(s);

    return 0;
}
