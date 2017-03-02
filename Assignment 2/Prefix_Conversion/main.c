#include <stdio.h>
#include <stdlib.h>
#include<string.h>
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
    int i,j=0;
    char ch;
    printf("                                                       EVAL POST \n\n");
    char infix[50],prefix[50];
    printf("Enter the infix expression having length less than 50\n");
    scanf("%s",infix);

    for(i=strlen(infix)-1;i>=0;i--)
    {

        if(infix[i]=='$')
        {
            push(&s,infix[i]);
            printf("1\n");

        }
        else if(infix[i]=='*' )
        {
            printf("2\n");
            ch=peep(&s);
            while(ch=='$' || ch=='/')
            {
                pop(&s);

                prefix[j]=ch;
                ch=peep(&s);
                j++;
            }
            push(&s,infix[i]);
        }
        else if(infix[i]=='/')
        {
            printf("3\n");
            ch=peep(&s);
            while(ch=='$' || ch=='*')
            {
                pop(&s);
                prefix[j]=ch;
                ch=peep(&s);
                j++;
            }
            push(&s,infix[i]);
        }

        else if(infix[i]=='+')
        {printf("4\n");

            ch=peep(&s);
          while(ch=='$' || ch=='*' || ch=='/' || ch=='-' )
          {

              ch=pop(&s);
              prefix[j]=ch;
              ch=peep(&s);
              j++;
          }
          push(&s,infix[i]);
        }
        else if(infix[i]=='-')
        {printf("5\n");

            ch=peep(&s);
          while(ch=='$' || ch=='*' || ch=='/' || ch=='+')
          {

              ch=pop(&s);
              prefix[j]=ch;
              ch=peep(&s);
              j++;
          }
          push(&s,infix[i]);
        }
        else
        {printf("6\n");
            prefix[j]=infix[i];
            j++;
        }

    }


    while(s.top!=-1)
    {
        ch=pop(&s);
        prefix[j]=ch;

        j++;
    }
    prefix[j]='\0';

    printf("%s",prefix);

    //printf("")

    for(i=strlen(prefix)-1;i>=0;i--)
    {
        printf("%c",prefix[i]);
    }
        return 0;
}
char peep(struct stack *s)
{
    char zr='_';
    if(isempty(s)==-1)
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
    if(isempty(s)==-1)
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
/*void print(struct stack *s)
{

    while(s->top != -1)
    {

        printf("%c",s->string[s->top]);
        s->top--;
    }
}*/
