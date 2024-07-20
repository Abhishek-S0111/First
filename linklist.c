#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
};

void insert_start(struct node **head,int val);
void insert_end(struct node **head, int val);
void insert_specific(struct node **head, int val, int pos);
void delete_start(struct node **head);
void delete_end(struct node **head);
void delete_specific(struct node **head, int pos);
struct node * delete_val(struct node **head, int val);
void display(struct node *head);
struct node * reverse(struct node **head);
int count(struct node *head);

int main()
{
    int ch,val,pos,c;
    struct node *root;
    root = NULL;

    while(1)
    {
        printf("\n1.Insert at Start  2.Insert at end  3.Insert at Specific Position\n4.Delete First  5.Delete End  6.Delete specific element 7.Delete Any Value\n8.Display  9.Count  10.Reverse\n11.Exit\nEnter your choice:");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: 
            printf("Enter the value to enter:");
            scanf("%d",&val);
            insert_start(&root,val);
            break;

            case 2: 
            printf("Enter the value to enter:");
            scanf("%d",&val);
            insert_end(&root,val);
            break;

            case 3: 
            printf("Enter the value to enter:");
            scanf("%d",&val);
            printf("Enter the position at which you want to enter:");
            scanf("%d",&pos);
            insert_specific(&root,val,pos);
            break;
            
            case 4: 
            delete_start(&root);
            break;
           
            case 5: delete_end(&root);
            break;
            
            case 6: 
            printf("Enter the position at which you want to delete:");
            scanf("%d",&pos);
            delete_specific(&root, pos);
            break;

            case 7:
            printf("What value do you want to delete:");
            scanf("%d",&val);
            root = delete_val(&root, val);
            break;

            case 8: display(root);
            break;

            case 9: c = count(root);
            printf("There are %d elements",c);
            break;

            case 10: root = reverse(&root);
            break;

            case 11: exit(0);

            default: printf("^__^\n");
            break; 
        }
    }
    return 0;
}

void insert_start(struct node **head,int val)
{
    struct node *k,*temp1;
    //temp1 = head;
    if (*head == NULL)
    {    
        k =(struct node *)malloc(sizeof(struct node));
        k -> data = val;
        k -> link = NULL;
        *head = k;
    }
    else
    {
        temp1 = *head;
        k =(struct node *)malloc(sizeof(struct node));
        k -> data = val;
        k -> link = temp1;
        *head = k;
    }
}

void insert_end(struct node **head, int val)
{
    struct node *k,*temp1,*temp2;
    temp1 = *head;
    if (*head == NULL)
    {
        k = (struct node*)malloc(sizeof(struct node));
        k ->data = val;
        k ->link = NULL;
        *head = k;
    }
    else
    {
        while(temp1 -> link != NULL)
        {
            temp1 = temp1->link;
        }
        k = (struct node*)malloc(sizeof(struct node));
        k ->data = val;
        k ->link = NULL;
        temp1->link = k;
    }
}

void insert_specific(struct node **head, int val,int pos)
{
    struct node *k, *temp1, *temp2;
    temp1 = *head;
    for(int i=1; i<pos-1; i++)
    {
        temp1 = temp1 -> link;
    }
    k = (struct node*)malloc(sizeof(struct node));
    k ->data = val;
    k ->link = temp1 -> link;
    temp1 -> link = k;

}

void delete_start(struct node **head)
{
    struct node *temp1;
    temp1 = *head;
    *head = temp1 -> link;
    temp1 -> link = NULL;
    free(temp1);
}

void delete_end(struct node **head)
{
    struct node *temp1,*temp2;
    temp1 = *head;
    while(temp1 -> link != NULL)
    {
        temp2 = temp1;
        temp1 = temp1 -> link;
    }
    temp2 -> link = NULL;
    free(temp1);
}

struct node * delete_val(struct node **head, int val)
{
    struct node *temp1,*temp2,*temp3;
    temp1 = temp2 = temp3 = *head;
    if (*head == NULL)
    {
        printf("The list is empty.");
    }
    else
    {
        while (temp1 -> data != val)
        {
            temp2 = temp1;
            temp1 = temp1 -> link;
        }
        if (temp1->data == val)
        {
            temp2 -> link = temp1 -> link;
            temp1 -> link = NULL;
            free(temp1);
        }
        else
        {
            printf("Element not found.");
        }
    }
    return temp3;
    
}

void delete_specific(struct node **head, int pos)
{
    struct node *temp1,*temp2;
    temp1 = *head;
    for(int i=1;i<pos;i++)
    {
        temp2 = temp1;
        temp1 = temp1 -> link;
    }
    temp2 -> link = temp1 -> link;
    temp1 -> link = NULL;
    free(temp1);
}

void display(struct node *head)
{
    struct node *temp;
    if (head == NULL)
    {
        printf("The list is empty.\n");
    }
    else
    {
        temp = head;
        while(temp -> link != NULL)
        {
            printf("%d ", temp->data);
            temp = temp -> link;
        }
        printf("%d \n",temp -> data);
    }
}

struct node * reverse(struct node **head)
{
    struct node *temp1, *temp2, *temp3;
    temp1 = temp2 = temp3 = *head;
    int c = count(temp1),d;
    int b = c;
    //printf("%d",b);
    if(c%2 != 0)
    {
        c--;
    }
    d = c/2;
    
    //for (int i = 1; i<=d; i++)
    //{
        
        for(int j = b;j > b-d; j--)
        {
            temp1 = *head;
            int e = j;
            while(e>1)
            {
                //printf("%d",e);
                temp1 = temp1 ->link;
                e--;
                printf("%d",temp1->data);
            }
            //printf("%d",temp1->data);
            temp2 -> data = temp2 -> data + temp1 -> data;
            temp1 -> data = temp2 -> data - temp1 -> data;
            temp2 -> data = temp2 -> data - temp1 -> data;
            temp2 = temp2 -> link;
        }
    //}
    return temp3;
}

int count(struct node *head)
{
    struct node *temp1; int c = 0;
    temp1 = head;
    if(head == NULL)
    {
        printf("The list is empty.");
        return c;
    }
    else
    {
        while(temp1 != NULL)
        {
            temp1 = temp1 -> link;
            c++;
        }
        return c;
    }
}

