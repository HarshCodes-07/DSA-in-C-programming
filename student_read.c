//Read the details of the student using function and structure
#include <stdio.h>
void read();
void display();
struct student {
    char name[50];
    int roll;
    float marks;
} s;

int main() {
        read();
    display();
    return 0;
}
void read(){
    printf("Enter name: ");
    scanf("%s",&s.name);
    printf("Enter roll number: ");
    scanf("%d", &s.roll);
    printf("Enter marks: ");
    scanf("%f", &s.marks);
}
void display(){
printf("Displaying Information:\n");
    printf("Name: %s\n", s.name);
    printf("Roll number: %d\n", s.roll);
    printf("Marks: %f\n", s.marks);
}
