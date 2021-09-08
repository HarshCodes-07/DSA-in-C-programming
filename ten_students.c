// Read 10 student details and display it
#include <stdio.h>
void read();
void display();
struct student {
    char name[50];
    int roll;
    float marks;
} s[10];

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
    for (int i = 0; i < 10; ++i) {
        s[i].roll = i + 1;
        printf("\nFor roll number%d,\n", s[i].roll);
        printf("Enter first name: ");
        scanf("%s", s[i].name);
        printf("Enter marks: ");
        scanf("%f", &s[i].marks);
    }
}
void display(){
for (int i = 0; i < 10; ++i) {
        printf("Name: %s",s[i].name);
        printf("\nRoll number: %d\n", i + 1);
        printf("Marks: %f", s[i].marks);
    }
}
