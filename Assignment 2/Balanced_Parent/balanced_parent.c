#include <stdio.h>
#include <stdlib.h>
struct stack{
    char string[50];
    int top;
};
char pop(struct stack *s);
int isempty(struct stack *s);
void push(struct stack *s,char ch);
int main()
{
    struct stack s;
    s.top=-1;
    int i,flag;
    char ch;
    char statement[50];
    printf("Enter the equation whose length is less than 50\n");
    scanf("%s",statement);
    for(i=0;i<strlen(statement);i++)
    {
        if(statement[i]=='(' || statement[i]=='[' || statement[i]=='{')
            {
                //printf("%d\n",i);
                push(&s,statement[i]);
            }
        else if(statement[i]=='}')
        {
            ch=pop(&s);
            if(ch=='{')
                continue;
            else
            {
                printf("Not Balanced\n");
                return;
            }
        }
        else if(statement[i]==')')
        {
            ch=pop(&s);
            if(ch=='(')
                continue;
            else
            {
                printf("Not Balanced\n");
                return;
            }
        }
        else if(statement[i]==')')
        {
            ch=pop(&s);
            if(ch=='(')
                continue;
            else
            {
                printf("Not Balanced\n");
                return;
            }
        }
        else if(statement[i]==']')
        {
            ch=pop(&s);
            if(ch=='[')
                continue;
            else
            {
                printf("Not Balanced\n");
                return;
            }
        }
        else
            continue;
    }
    int t;
    t=isempty(&s);
    //printf("top=%d\n",t);
    if(t==-1)
        printf("Balanced\n");
    else
        printf("Not Balanced\n");

    return 0;
}
void push(struct stack *s,char ch)
{
    s->top++;
    s->string[s->top]=ch;
}
char pop(struct stack *s)
{
    char z;
    if(isempty(&s)==-1)
    {
        return z;
    }
    else
        z=s->string[s->top];
        s->top--;
    return z;
}
int isempty(struct stack *s)
{
    return s->top;
}
