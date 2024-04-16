#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int elements;
    char* pData;
};

int stack_init(struct Stack* s)
{
    s->elements = 0;
    s->pData = NULL;
    return 0;
}

int stack_init(Stack& s, const Stack& other)
{
    s.elements = 0;
    s.pData = NULL;

    if (other.elements != 0 && other.pData != NULL)
    {
        char *temp = (char*) malloc(other.elements * sizeof(char));
        if (temp == NULL)
            return -1;

        for(int i = 0; i < other.elements; i++)
            temp[i] = other.pData[i];
        s.pData = temp;
        s.elements = other.elements;
    }
    return 0;
}

void stack_cleanUp(struct Stack* s)
{
    s->elements = 0;
    free(s->pData);
    s->pData = NULL;
}

int stack_push(struct Stack* s, char newElement)
{
    // Itt új elemet fuzünk az s->pData végére.
    char* temp = (char*) malloc ((s->elements + 1) * sizeof(char));
    if (temp == NULL)
        return -1;
    for(int i = 0; i < s->elements; i++)
        temp[i] = s->pData[i];
    temp[s->elements] = newElement;
    s->pData = temp;
    s->elements++;
    return 0;
}

int stack_pop(struct Stack* s)
{
    if (s->elements == 0 || s->pData == NULL) //ha ures nem veszek ki semmit
        return -1;

    char* temp = (char*) malloc((s->elements - 1) * sizeof(char));
    if (temp != NULL)
        for (int i = 0; i < s->elements - 1; i++)
            temp[i] = s->pData[i];
    char ans = s->pData[s->elements - 1];
    s->elements--;
    if (s->elements == 0)
        s->pData = NULL;
    else
        s->pData = temp;
    return ans;
}

int stack_isEmpty(struct Stack* s)
{
    return s->elements == 0 || s->pData == NULL ? 1 : 0;
}

int main(void)
{
    struct Stack s;
    char i;

    printf("Initializing stack...\n");
    stack_init(&s);

    for (i = 'A'; i <= 'Z'; i++)
    {
        printf("push: %c\n",i);
        stack_push(&s, i);
    }

    while (!stack_isEmpty(&s))
    {
        printf("pop: %c\n", (char)stack_pop(&s));
    }

    printf("pop non existent: %d\n", stack_pop(&s));

    printf("Cleaning up stack...\n");
    stack_cleanUp(&s);
    return 0;
}
