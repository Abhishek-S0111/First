/*Algorithm

1-> Input expression/equation from user in the form of string.
2-> Add a ')' after the last input element of expression.
3-> Create a stack and push '(' into it.
4-> Read the expression from right to letf one by one using a loop.
6-> If an operand is encountered then push it into postfix stack.
7-> If an operator is encountered, check the precendence of the read operator and the operator at top in stack:
        if precedence(read_operator)>precedence(stack_top_operator)
            push the operator in stack
        else
            pop all the operators from stack which have less than or equal precedence than the read operator.
            After this push read operator in the stack.
8-> If a closing bracket is encountered then pop all the operators from stack until an opening bracket is encountered as stack_top.
        After this pop the opening bracket.
9-> If an opening bracket is encountered then directly push it into the postfix stack.
10-> End of step 4 loop.
11-> Return the finalized postfix expression to the user.
12-> END.*/

#include<stdio.h>
#include<string.h>

struct stack{
    char data[20];
    int p; 
}st;
struct postfix{
    char ans[50];
    int p;
}pos;

void push_st(char a);
void push_pos(char b);
char pop();
int precedence(char c);
void display_pos();

int main()
{
    char eq[50];  int i,ch,j=0;  st.p=-1;pos.p=-1;
    printf("Enter your equation:");
    scanf("%s",&eq);
    i=strlen(eq);
    printf("\n%d\n",i);
    eq[i]=')';
    push_st('(');
    while(j!=i+1)
    {
        if (eq[j]=='(')
        {
            push_st(eq[j]);
        }
        else if (eq[j]=='+' || eq[j]=='-' || eq[j]=='/' || eq[j]=='*' || eq[j]=='^')
        {
            if (precedence(eq[j])>precedence(st.data[st.p]))
            {
                push_st(eq[j]);
            }
            else
            {
                while(precedence(eq[j])<precedence(st.data[st.p]) && st.data[st.p]!='(')
                {
                    push_pos(pop());
                }
                push_st(eq[j]);
            }
        }
        else if (eq[j]==')')
        {
            while(st.data[st.p]!='(')
            {
                push_pos(pop());
            }
            pop();
        }
        else
        {
            push_pos(eq[j]);
        }
        j++;
    }
    display_pos();
    //printf("\n%d",count(eq));
    return 0;
}

void push_st(char a)
{
    st.data[++st.p]=a;
}
void push_pos(char b)
{
    pos.ans[++pos.p]=b;
}
char pop()
{
    return st.data[st.p--];
}
int precedence(char c)
{
    if (c=='^')
        return 4;
    else if (c=='/' || c=='*')
        return 3;
    else if (c=='+' || c=='-')
        return 2;
    else
        return 1;
}
void display_pos()
{
    for(int h=0;h<=pos.p;h++)
    {
        printf("%c",pos.ans[h]);
    }
}


