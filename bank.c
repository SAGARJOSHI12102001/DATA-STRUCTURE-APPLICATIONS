#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
    int data;
    struct node *link;
};

/*prototype declaration*/

void adb(struct node*,int);    /*function to add a node at the beginning of the linked-list*/
void ade(struct node*,int);    /*function to add a node at the end of the linked-list*/
void adl(struct node*,int,int);   /*function to add a node at a particular location  in the linked-list*/
void del(struct node*,int);        /*function to del a node from a particular location of the linked-list*/
void search(struct node*,int);    /*function to search a node in the linked-list*/
void display(struct node*);    /*function to display items of the linked-list*/
int displaymenu(void);   /*function to display the menu*/

struct node *p=NULL;

void main()
{
    int x,choice,l;
    do
    {
        choice=displaymenu();
        switch(choice)
        {
            case 1:
                printf("enter the no.#");
                scanf("%d",&x);
                adb(p,x);
                break;
        case 2:
                printf("enter the no.#");
                scanf("%d",&x);
                ade(p,x);
                break;
        case 3:
                printf("enter the no#");
                scanf("%d",&x);
                printf("enter the loc");
                scanf("%d",&l);
                adl(p,l,x);
                break;
        case 4:
                printf("enter the loc");
                scanf("%d",&l);
                del(p,l);
                break;
        case 5:
                printf("enter the no. you want to search for#");
                scanf("%d",&x);
                search(p,x);
                break;
        case 6:
                display(p);
                break;
        case 7:
                break;
        default:
                printf("Invalid choice");
        }
    }while(choice!=7);
}

/*function to add a node at the beginning of the linked-list*/

void adb(struct node *q,int x)
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=x;
    temp->link=q;
    q=temp;
    p=q;
}

/*function to add a node at the end of the linked-list*/

void ade(struct node *q,int x)
{
    struct node *temp,*r;
    if(q==NULL)
    {
        temp=(struct node*)malloc(sizeof(struct node));
        temp->data=x;
        temp->link=NULL;
        q=temp;
        p=q;
    }
    else
    {
        temp=q;
        while(temp->link!=NULL)
            temp=temp->link;
        r=(struct node*)malloc(sizeof(struct node));
        r->data=x;
        r->link=NULL;
        temp->link=r;
    }
}

/*function to add a node at a particular location in the linked-list*/

void adl(struct node *q,int loc,int x)
{
    struct node *temp,*r;
    int i;
    temp=q;
    for(i=1;i<loc-1;i++)
    {
        temp=temp->link;
        if(temp==NULL)
        {
            printf("location not found");
            return;
        }
    }
    r=(struct node*)malloc(sizeof(struct node));
    r->data=x;
    r->link=temp->link;
    temp->link=r;
}

/*function to del a node from a particular location of the linked-list*/

void del(struct node *q,int loc)
{
    struct node *temp,*r;
    int i;
    temp=q;
    r=q;
    if(loc==1)
    {
        temp=temp->link;
        q=temp;
        free((char *) r);
        p=q;
    }
    else
    {
        for(i=1;i<loc-1;i++)
        {
            temp=temp->link;
        }

        for(i=1;i<loc;i++)
        {
             r=r->link;
             if(r==NULL)
             {
                 printf("location not found");
                 return;
             }
        }
        temp->link=r->link;
        free((char *) r);
     }
}

/*function to search a node in the linked-list*/

void search(struct node *q,int x)
{
     struct node *temp;
     int loc=1;
     temp=q;
     while(temp->data!=x)
     {
          temp=temp->link;
          if(temp==NULL)
          {
               printf("number not found");
               return;
          }
          loc=loc+1;
     }
     printf("the location of the no.is %d",loc);
     return;
}

/*function to display items of the linked-list*/

void display(struct node *q)
{
    while(q!=NULL)
    {
    printf("\t%d",q->data);
    q=q->link;
    }
}

/*function to display the menu*/

int displaymenu()
{
    int c;
    printf("\nyou want to");
    printf("\n1.add node at beginning");
    printf("\n2.add node at end");
    printf("\n3.add node at particular location");
    printf("\n4.del node at particular location");
    printf("\n5.search a number");
    printf("\n6.display linklist");
    printf("\n7.exit");
    printf("\n\tchoice=");
    scanf("%d",&c);
    return c;
}