#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct stack{
    char string[100];
    int top;
};
char pop(struct stack *s);
void push(struct stack *s,char ch);
int isempty(struct stack *s);
int main()
{
    char ch;
    int i,j;
    struct stack s;
    s.top = -1;
    printf("Enter a String whose length is less than 100\n");
    char str[100];
    scanf("%[^\n]",str);
    for(i=0;i<strlen(str);i++)
    {
        push(&s,str[i]);
    }
    printf("Reverse of the input String is\n");
    j=isempty(&s);
    while(j!=-1)
    {
        ch=pop(&s);
        printf("%c",ch);
        j=isempty(&s);
    }
}

void push(struct stack *s,char ch)
{

    s->top=s->top+1;
    s->string[s->top]=ch;

}
char pop(struct stack *s)
{
    char z;
    z=s->string[s->top];
    s->top--;
    return z;
}
int isempty(struct stack *s)
{
    return s->top;
}
