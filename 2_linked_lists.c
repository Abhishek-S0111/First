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
struct node *join(struct node **head1, struct node **head2);
struct node *selection_sort(struct node **head);
struct node *bubble_sort(struct node **head);

int main()
{
    int ch,val,pos,c,choice;
    struct node *root1,*root2,*temp;
    root1 = root2 = NULL;

    while(1)
    {
        printf("\nChoose your linklist:\n1. List 1  2.List 2 3.Join List 4.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: 
                printf("1.Insert at Start  2.Insert at end  3.Insert at Specific Position\n4.Delete First  5.Delete End  6.Delete specific element 7.Delete Any Value\n8.Display  9.Count  10.Reverse\n11.Selection Sort  12.Bubble Sort  13.Exit\nEnter your choice:");
                scanf("%d",&ch);

                switch(ch)
                {
                    case 1: 
                    printf("Enter the value to enter:");
                    scanf("%d",&val);
                    insert_start(&root1,val);
                    break;

                    case 2: 
                    printf("Enter the value to enter:");
                    scanf("%d",&val);
                    insert_end(&root1,val);
                    break;

                    case 3: 
                    printf("Enter the value to enter:");
                    scanf("%d",&val);
                    printf("Enter the position at which you want to enter:");
                    scanf("%d",&pos);
                    insert_specific(&root1,val,pos);
                    break;
                    
                    case 4: 
                    delete_start(&root1);
                    break;
                
                    case 5: delete_end(&root1);
                    break;
                    
                    case 6: 
                    printf("Enter the position at which you want to delete:");
                    scanf("%d",&pos);
                    delete_specific(&root1, pos);
                    break;

                    case 7:
                    printf("What value do you want to delete:");
                    scanf("%d",&val);
                    root1 = delete_val(&root1, val);
                    break;

                    case 8: display(root1);
                    break;

                    case 9: c = count(root1);
                    printf("There are %d elements",c);
                    break;

                    case 10: root1 = reverse(&root1);
                    break;

                    case 11: root1 = selection_sort(&root1);
                    break;

                    case 12: root1 = bubble_sort(&root1);
                    break;

                    case 13: exit(0);

                    default: printf("^__^\n");
                    break;
                }
            break;
            case 2:
                printf("1.Insert at Start  2.Insert at end  3.Insert at Specific Position\n4.Delete First  5.Delete End  6.Delete specific element 7.Delete Any Value\n8.Display  9.Count  10.Reverse\n11.Sort  12.Bubble Sort  13.Exit\nEnter your choice:");
                scanf("%d",&ch);

                switch(ch)
                {
                    case 1: 
                    printf("Enter the value to enter:");
                    scanf("%d",&val);
                    insert_start(&root2,val);
                    break;

                    case 2: 
                    printf("Enter the value to enter:");
                    scanf("%d",&val);
                    insert_end(&root2,val);
                    break;

                    case 3: 
                    printf("Enter the value to enter:");
                    scanf("%d",&val);
                    printf("Enter the position at which you want to enter:");
                    scanf("%d",&pos);
                    insert_specific(&root2,val,pos);
                    break;
                    
                    case 4: 
                    delete_start(&root2);
                    break;
                
                    case 5: delete_end(&root2);
                    break;
                    
                    case 6: 
                    printf("Enter the position at which you want to delete:");
                    scanf("%d",&pos);
                    delete_specific(&root2, pos);
                    break;

                    case 7:
                    printf("What value do you want to delete:");
                    scanf("%d",&val);
                    root2 = delete_val(&root2, val);
                    break;

                    case 8: display(root2);
                    break;

                    case 9: c = count(root2);
                    printf("There are %d elements",c);
                    break;

                    case 10: root2 = reverse(&root2);
                    break;

                    case 11: root2 = selection_sort(&root2);
                    break;

                    case 12: root2 = bubble_sort(&root2);
                    break;

                    case 13: exit(0);

                    default: printf("^__^\n");
                    break;
                break;
                }
            break;

            case 3: temp = join(&root1,&root2);
            break;

            case 4: exit(0);

            default: printf("<(P_P)>");
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
        while (temp1 -> data != val && temp1 -> link != NULL) 
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
    if(c%2 != 0)
    {
        c--;
    }
    d = c/2;
        
        for(int j = b;j > b-d; j--)
        {
            temp1 = *head;
            int e = j;
            while(e>1)
            {
                //printf("%d",e);
                temp1 = temp1 ->link;
                e--;
            }
            temp2 -> data = temp2 -> data + temp1 -> data;
            temp1 -> data = temp2 -> data - temp1 -> data;
            temp2 -> data = temp2 -> data - temp1 -> data;
            temp2 = temp2 -> link;
        }
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

struct node *join(struct node **head1, struct node **head2)
{
    struct node *temp1, *temp2;  int ch;
    printf("\n1. List 1 to List 2\n2.List 2 to List 1\nChoose how to join:->");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: 
        if(*head1 == NULL && *head2 == NULL)
        {
            printf("No element entered in both lists.");
        }
        else if (*head1 == NULL)
        {
            printf("Only List 2 has been defined.");
        }
        else if(*head2 == NULL)
        {
            printf("Only List 1 has been defined.");
        }
        else
        {
            temp1 = *head1;
            temp2 = *head2;
            while(temp1 -> link != NULL)
            {
                temp1 = temp1-> link;
            }
            if (temp1 -> link == temp2)
            {
                printf("Lists are already joined.");
            }
            else
            {
                temp1 -> link = temp2;
                return temp1;
            }
        }
        break;
        
        case 2: 
        if(*head1 == NULL && *head2 == NULL)
        {
            printf("No element entered in both lists.");
        }
        else if (*head1 == NULL)
        {
            printf("Only List 2 has been defined.");
        }
        else if(*head2 == NULL)
        {
            printf("Only List 1 has been defined.");
        }
        else
        {
            temp1 = *head2;
            temp2 = *head1;
            while(temp1 -> link != NULL)
            {
                temp1 = temp1-> link;
            }
            if (temp1 -> link == temp2)
            {
                printf("Lists are already joined.");
            }
            else
            {
                temp1 -> link = temp2;
                return temp1;
            }
        }
        break;
        
    }
}

struct node *selection_sort(struct node **head)    //Selection Sort
{
    struct node *temp1, *temp2, *temp3, *temp4;    int c,t,m;
    if(*head == NULL)
    {
        printf("Lists have not been defined.");
    }
    else
    {
        temp1 = temp2 = temp3 = *head;
        c = count(temp1);
            for(int i = 1;i < c; i++)
            {
                for(int j = 1; j < c && temp2 -> link != NULL; j++)
                {
                    temp2 = temp2 -> link;
                    if (temp1 -> data > temp2 -> data)
                    {
                        temp1 -> data = temp1 -> data + temp2 -> data;
                        temp2 -> data = temp1 -> data - temp2 -> data;
                        temp1 -> data = temp1 -> data - temp2 -> data;
                    }
                    else
                    {
                        continue;
                    }
                }
                temp2 = temp1;
                if(temp1 -> link != NULL)
                    temp1 = temp1 -> link;
            }
    }
    return temp3;

}

struct node *bubble_sort(struct node **head)       //Bubble Sort
{
    struct node *temp1, *temp2, *temp3;
    temp1 = temp2 = temp3 = *head;
    int c = count(temp1);
    for(int i = 1; i <= c; i++)
    {
        temp1 = temp2 = *head;
        for(int j = 1; j < c; j++)
        {
            temp2 = temp2 -> link;
            if (temp2 -> data < temp1->data)
            {
                temp1->data = temp1->data + temp2->data;
                temp2->data = temp1->data - temp2->data;
                temp1->data = temp1->data - temp2->data;
            }
            temp1 = temp1->link;
        }
    }
    return temp3;
}

/*struct node *insertion_sort(struct node **head)    //Insertion Sort
{
    struct node *temp1, *temp2, *temp3;
    temp1 = temp2 = temp3 = *head;
    int c = count(temp1);
    for(int i = 0; i)
}*/