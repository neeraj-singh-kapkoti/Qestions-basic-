#include <stdio.h>
#include <stdlib.h>

struct build_stack
{
    int size;
    int top;
    int *s;
};

void create(struct build_stack *st)
{
    printf("Enter size of stack: ");
    scanf("%d", &st->size);
    st->top = -1;
    st->s = (int *)malloc(st->size * sizeof(int));
}

void display(struct build_stack st)
{
    int i;
    for (i = st.top; i >= 0; i--)
    {
        printf("%d ", st.s[i]);
    }
    printf(" \n");
}

int pop(struct build_stack *st)
{
    int x = -1;
    if (st->top == -1)
    {
        printf("Stack is empty /n");
    }
    else
    {
        x = st->s[st->top--];
    }
    return x;
}

void push(struct build_stack *st, int x)
{
    if (st->top == st->size - 1)
    {
        printf("Stack overflow /n");
    }
    else
    {
        st->top++;
        st->s[st->top] = x;
    }
}

int peak(struct build_stack st, int index)
{
    int x = -1;
    if (st.top - index + 1 < 0)
        printf("Invalid Index \n");
    x = st.s[st.top - index + 1];
    return x;
}

int main()
{
    struct build_stack st;
    int n = 0;
    create(&st);
    printf("Enter number of elements to push: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x = 0;
        printf("Enter element to push: ");
        scanf("%d", &x);
        push(&st, x);
    }
    printf("Stack is: ");
    display(st);
    printf("Popped element is: %d /n", pop(&st));
    printf("Stack is: ");
    display(st);
    return 0;
}