#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAX 1000
char st[MAX];
int top=-1;
void push(char st[],char);
char pop(char st[]);
void InfixToPostfix(char source[],char target[]);
int getPriority(char);
int main()
{
    char infix[1000],postfix[1000];
    printf("\nEnter any infix expression : ");
    gets(infix);
    strcpy(postfix,"");
    InfixToPostfix(infix,postfix);
    printf("\nThe corresponding postfix expression is : ");
    puts(postfix);
    return 0;
}
void InfixToPostfix(char source[],char target[])
{
    int i=0,j=0;
    char temp;
    strcpy(target,"");
    while(source[i]!='\0')
    {
        if(source[i]=='(')
        {
            push(st,source[i]);
            i++;
        }
        else if(source[i]==')')
        {
            while(top!=-1&&st[top]!='(')
            {
                target[j++]=pop(st);
            }
            if(top==-1)
            {
                printf("\nInvalid Expression");
                exit(1);
            }
            temp=pop(st);
            i++;
        }
        else if(isdigit(source[i])||isalpha(source[i]))
        {
            target[j++]=source[i++];
        }
        else if (source[i] == '+' || source[i] == '-' || source[i] == '*' ||
                 source[i] == '/' || source[i] == '%')
        {
            while(top!=-1&&st[top]!='('&&getPriority(source[i])<=getPriority(st[top]))
            {
                target[j++]=pop(st);
            }
            push(st,source[i]);
            i++;
        }
        else
        {
            printf("\nIncorrect Element in expression.");
            exit(1);
        }
    }
    while((top!=-1) && (st[top]!='('))
    {
        target[j++] = pop(st);
    }
    target[j]='\0';
}
int getPriority(char c)
{
    if(c=='/'||c=='*'||c=='%')
        return 1;
    else return 0;
}
void push(char st[],char c)
{
    if(top==MAX-1)
        printf("\nSTACK OVERFLOW");
    else
    {
        st[++top]=c;
    }
}
char pop(char st[])
{
    if(top==-1)
        printf("\nSTACK UNDERFLOW");
    return st[top--];
}
