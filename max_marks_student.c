// Read 5 student details and display the student with maximum marks
#include <stdio.h>
void read();
void display();
struct student {
    char name[50];
    int roll;
    float marks;
} s[5];

int main() {
    printf("Enter information of students:\n");
    // storing information
    read();
    printf("Displaying Information:\n\n");
    // displaying information
    display();
    return 0;
}
void read(){
    for (int i = 0; i < 5; ++i) {
        s[i].roll = i + 1;
        printf("\nFor roll number%d,\n", s[i].roll);
        printf("Enter first name: ");
        scanf("%s", s[i].name);
        printf("Enter marks: ");
        scanf("%f", &s[i].marks);
    }
}
void display(){
    int ans_index=-1;
    int max=0;
for (int i = 0; i <5; ++i) {
    if(s[i].marks>max)
      {max=s[i].marks;
      ans_index=i;
    }
}       printf("Student with maximum marks : \n");
        printf("Name: %s",s[ans_index].name);
        printf("\nRoll number: %d\n", ans_index + 1);
        printf("Marks: %f", s[ans_index].marks);
}
