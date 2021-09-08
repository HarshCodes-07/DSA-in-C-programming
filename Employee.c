// Read n emplyee and get gross
#include <stdio.h>
struct employee{
    char    name[30];
    char     gender[30];
    float   bp;
};

int main()
{
    int n;
    printf("\nEnter the no of Employee : ");
    scanf("%d",&n);
    struct employee emp[n];
    for(int i=0;i<n;i++){
    printf("\nEnter details of Employee %d :\n",i+1);
    printf("Name :");
    scanf("%s",emp[i].name);
    printf("gender :");
    scanf("%s",&emp[i].gender);
    printf("Salary :");
    scanf("%f",&emp[i].bp);
}
    for(int i=0;i<n;i++){
    printf("\nEntered detail is:");
    printf("\nName: %s",emp[i].name);
    printf("\nGender: %s",emp[i].gender);
    printf("\nSalary: %f\n",(emp[i].bp+0.25*emp[i].bp+0.75*emp[i].bp));
    }
    return 0;
}
