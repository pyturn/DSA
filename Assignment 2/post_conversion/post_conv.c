#include <stdio.h>
#include <stdlib.h>
struct stack{
    char string[50];
    int top;
};
char peep(struct stack *s);
char pop(struct stack *s);
void push(struct stack *s,char ch);
int isempty(struct stack *s);
int main()
{
    struct stack s;
    s.top = -1;
    int i,j;
    char ch;
    printf("                                                       EVAL POST \n\n");
    char infix[50];
    printf("Enter the infix expression having length less than 50\n");
    scanf("%s",infix);

    for(i=0;i<strlen(infix);i++)
    {
        if(infix[i]=='(')
        {
            push(&s,infix[i]);

        }
        else if(infix[i]==')')
        {


            ch=peep(&s);
            while(ch!='(')
            {
                pop(&s);

                printf("%c",ch);
                ch=peep(&s);
            }
            ch=pop(&s);
            printf("%c",ch);
            push(&s,infix[i]);


        }
        else if(infix[i]=='$')
        {
            push(&s,infix[i]);

        }
        else if(infix[i]=='*' )
        {

            ch=peep(&s);
            while(ch=='$' || ch=='*'|| ch=='/')
            {
                pop(&s);

                printf("%c",ch);
                ch=peep(&s);
            }
            push(&s,infix[i]);
        }
        else if(infix[i]=='/')
        {

            ch=peep(&s);
            while(ch=='$' || ch=='/' ||ch=='*')
            {
                pop(&s);
                printf("%c",ch);
                ch=peep(&s);
            }
            push(&s,infix[i]);
        }

        else if(infix[i]=='+')
        {

            ch=peep(&s);
          while(ch=='$' || ch=='*' || ch=='/' || ch=='-' || ch=='+')
          {

              ch=pop(&s);
              printf("%c",ch);
              ch=peep(&s);
          }
          push(&s,infix[i]);
        }
        else if(infix[i]=='-')
        {

            ch=peep(&s);
          while(ch=='$' || ch=='*' || ch=='/' || ch=='+' || ch=='-')
          {

              ch=pop(&s);
              printf("%c",ch);
              ch=peep(&s);
          }
          push(&s,infix[i]);
        }
        else
            printf("%c",infix[i]);

    }
    print(&s);

        return 0;
}
char peep(struct stack *s)
{
    char zr;
    if(isempty(&s)==-1)
    {
        return zr;
    }
    else
        zr=s->string[s->top];

    return zr;
}
void push(struct stack *s,char ch)
{

    s->top=s->top+1;
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
void print(struct stack *s)
{

    while(s->top != -1)
    {

        printf("%c",s->string[s->top]);
        s->top--;
    }
}
