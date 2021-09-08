#include <stdio.h>
#include <string.h>
void main()
{
        int i, j, n;
        printf("Enter the value of n: \n");
        scanf("%d", &n);
        char name[n][50],tname[n][50],temp[50];
        printf("Enter %d names: \n", n);
        for (i = 0; i < n; i++)
        {
            scanf("%s", name[i]);
            strcpy(tname[i], name[i]);
        }
        for (i = 0; i < n - 1 ; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (strcmp(name[i], name[j]) > 0)
                {
                    strcpy(temp, name[i]);
                    strcpy(name[i], name[j]);
                    strcpy(name[j], temp);
                }
            }
        }
        printf("\n----------------------------------------\n");
        printf("Input Name\t\tSorted names\n");
        printf("------------------------------------------\n");
        for (i = 0; i < n; i++)
        {
            printf("%s\t\t\t%s\n", tname[i], name[i]);
        }

        printf("------------------------------------------\n");
}
