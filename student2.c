#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    int roll;
    char name[10];
    int subject1, subject2, subject3, subject4, subject5;
    int avg;
    int highest;
    int lowest;
};

struct student *s;

char getGrade(int average)
{
    if (average > 80)
        return 'A';
    else if (average > 60)
        return 'B';
    else if (average > 45)
        return 'C';
    else
        return 'F';
}

int main()
{
    int i, n;
    printf("Enter number of students:");
    scanf("%d", &n);
    s = (struct student *)malloc(sizeof(struct student) * n);

    for (i = 0; i < n; i++)
    {
        printf("Enter roll number of %d student:", i + 1);
        scanf("%d", &s[i].roll);
        printf("Enter name of %d student:", i + 1);
        scanf(" %s", s[i].name);
        printf("Enter marks of eee:");
        scanf("%d", &s[i].subject1);
        printf("Enter marks of discrete:");
        scanf("%d", &s[i].subject2);
        printf("Enter marks of digital:");
        scanf("%d", &s[i].subject3);
        printf("Enter marks of oopm:");
        scanf("%d", &s[i].subject4);
        printf("Enter marks of ds:");
        scanf("%d", &s[i].subject5);

        // Calculate average
        s[i].avg = (s[i].subject1 + s[i].subject2 + s[i].subject3 + s[i].subject4 + s[i].subject5) / 5;

        // Calculate highest and lowest
        s[i].highest = s[i].subject1;
        s[i].lowest = s[i].subject1;

        if (s[i].subject2 > s[i].highest)
            s[i].highest = s[i].subject2;
        else if (s[i].subject2 < s[i].lowest)
            s[i].lowest = s[i].subject2;

        if (s[i].subject3 > s[i].highest)
            s[i].highest = s[i].subject3;
        else if (s[i].subject3 < s[i].lowest)
            s[i].lowest = s[i].subject3;

        if (s[i].subject4 > s[i].highest)
            s[i].highest = s[i].subject4;
        else if (s[i].subject4 < s[i].lowest)
            s[i].lowest = s[i].subject4;

        if (s[i].subject5 > s[i].highest)
            s[i].highest = s[i].subject5;
        else if (s[i].subject5 < s[i].lowest)
            s[i].lowest = s[i].subject5;
    }

    printf("\nYou have entered:\n");
    printf("Roll\tName\tSubject1\tSubject2\tSubject3\tSubject4\tSubject5\tAverage\tGrade\tHighest\tLowest\n");
    for (i = 0; i < n; i++)
    {
        char grade = getGrade(s[i].avg);
        printf("%d\t%s\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%c\t%d\t%d\n", s[i].roll, s[i].name, s[i].subject1, s[i].subject2, s[i].subject3, s[i].subject4, s[i].subject5, s[i].avg, grade, s[i].highest, s[i].lowest);
    }

    free(s);

    return 0;
}
