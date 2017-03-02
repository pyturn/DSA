#include<stdio.h>
#include<math.h>
struct node
{
    int coeff,pow;
    struct node *next;
};
void append(struct node **head,int coeff,int pow);
struct node *getnode();
void print(struct node **head);
void add(struct node *head1,struct node *head2,struct node **head3);
struct node *mult(struct node *head1,struct node *head2);

int main()
{
    int coeff,pow,n1,n2,i,j;
    struct node *head1,*head2,*head3;
    head1=NULL;
    head2=NULL;
    head3=NULL;
    printf("Enter number of terms in first equation\n");
    scanf("%d",&n1);
    for(i=0;i<n1;i++)
    {
        printf("Enter coefficient and power of x\n");
        scanf("%d %d",&coeff,&pow);
        append(&head1,coeff,pow);
    }
    //print(&head1);
    printf("Enter number of terms in second equation\n");
    scanf("%d",&n2);
    for(i=0;i<n2;i++)
    {
        printf("Enter coefficient and power of x\n");
        scanf("%d %d",&coeff,&pow);
        append(&head2,coeff,pow);
    }
    printf("First Equation is\n");
    print(&head1);
    printf("Second Equation is\n");
    print(&head2);
    printf("1.Press 1 to add a polynomial equations.\n2.Press 2 to multiply polynomial equations\n");
    scanf("%d",&j);
    if(j==1)
    {
     printf("Addition of equations is \n");
     add(head1,head2,&head3);
     print(&head3);
    }
    else
    {
     printf("Multiplication of equations is \n");
     head3=mult(head1,head2);
     print(&head3);
    }

}
struct node *getnode()
{
        struct node *ptr;
        ptr=(struct node *)malloc(sizeof(struct node));
        return ptr;
}
void append(struct node **head,int coeff,int pow)
{
    struct node *ptr,*temp;
    ptr=getnode();
    ptr->coeff=coeff;
    ptr->pow=pow;
    if(*head==NULL)
    {
        *head=ptr;
    }
    else
    {
        temp=*head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=ptr;
    }
    ptr->next=NULL;
}
void print(struct node **head)
{
    struct node *ptr1;
    ptr1=*head;
    //printf("PRINT\n");
    while(ptr1!=NULL)
    {
        //printf("123456789\n");
        printf("+%dx^%d",ptr1->coeff,ptr1->pow);
        ptr1=ptr1->next;
    }
    printf("\n\n");
}
void add(struct node *head1,struct node *head2,struct node **head3)
{
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->pow==head2->pow)
        {
            append(head3,head1->coeff+head2->coeff,head1->pow);
            head1=head1->next;
            head2=head2->next;
        }
        else if(head1->pow>head2->pow)
        {
            append(head3,head1->coeff,head1->pow);
            head1=head1->next;
        }
        else
        {
            append(head3,head2->coeff,head2->pow);
            head2=head2->next;
        }
    }
    if(head1!=NULL)
    {
        append(head3,head1->coeff,head1->pow);
        head1=head1->next;
    }
    else if(head2!=NULL)
    {
        append(head3,head2->coeff,head2->pow);
        head2=head2->next;
    }
}
struct node *mult(struct node *head1,struct node *head2)
{
    struct node *p1,*p2,*p3;
    int coeff,pow;
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;
    p3=NULL;
    p1=head1;
    while(p1!=NULL)
    {
        p2=head2;
        while(p2!=NULL)
        {
            coeff=p1->coeff*p2->coeff;
            pow=p1->pow+p2->pow;
            append(&p3,coeff,pow);
            p2=p2->next;
        }
        p1=p1->next;
    }
    return p3;
}
