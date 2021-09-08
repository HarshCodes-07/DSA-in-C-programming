#include <stdio.h>
#include <string.h>
struct Student {
    char name[15] ;
    char branch[6]
};
void value(struct Student info);

int main()
{
            struct Student info;

            strcpy(info.branch, "CSE");
            strcpy(info.name, "HARSH");
            value(info);
            return 0;
}

void value(struct Student info)
{
            printf(" Name is: %s \n", info.name);
            printf(" Percentage is: %s \n", info.branch);
}
