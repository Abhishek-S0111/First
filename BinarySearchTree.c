#include<stdio.h>
#include<stdlib.h>

struct bstree{
    int data;
    struct bstree *l_child,*r_child;
};

void insert(struct bstree **head);
void preorder(struct bstree *head);
void inorder(struct bstree *head);
void postorder(struct bstree *head);

int main()
{
    int ch;
    struct bstree *root;
    root = NULL;

    while(1)
    {
        printf("\nEnter your choice:\n1.Insert\n2.Display Preorder\n3.Display Inorder\n4.Display Postorder\n5.Exit\n");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1: insert(&root);
            break;

            case 2: preorder(root);
            break;

            case 3: inorder(root);
            break;

            case 4: postorder(root);
            break;

            case 5: exit(0);

            default: printf("(^__^)\n");
        }
    }
    return 0;
}

void insert(struct bstree **head)
{
    int val;
    printf("Enter the value you want to insert:");
    scanf("%d",&val);

    if (*head == NULL)
    {
        *head = (struct bstree *)malloc(sizeof(struct bstree));

        (*head) -> data = val;
        (*head) -> r_child = NULL;
        (*head) -> l_child = NULL;
    }
    else
    {
        if (val > (*head)->data)
        {
            insert(&((*head) -> r_child));
        }
        else
        {
            insert(&((*head) -> l_child));
        }
    }
}

void preorder(struct bstree *head)
{
    if (head != NULL)
    {
        printf("%d ", head -> data);
        preorder(head ->l_child);
        preorder(head ->r_child);
    }
}


void inorder(struct bstree *head)
{
    if (head != NULL)
    {
        inorder(head ->l_child);
        printf("%d ", head -> data);
        inorder(head ->r_child);
    }
}

void postorder(struct bstree *head)
{
    if (head != NULL)
    {
        postorder(head ->l_child);
        postorder(head ->r_child);
        printf("%d ", head -> data);
    }
}