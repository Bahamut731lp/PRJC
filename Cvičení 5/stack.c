#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
    struct stack test = {NULL};
    char str1[] = "Hello World";
    char str2[] = "Fag";
    char str3[] = "Pavel Vacha";

    printf("%d %d %d\n", sizeof(str1), sizeof(str2), sizeof(str3));

    struct Node *temp = new_node(&str1, sizeof(str1));
    struct Node *temp1 = new_node(&str2, sizeof(str2));
    struct Node *temp2 = new_node(&str3, sizeof(str3));

    push(&test, temp);
    push(&test, temp1);
    push(&test, temp2);

    display(&test);

    struct Node *t = pop(&test);
    display(&test);

    printf("%s", t->data);
}

/**
 * Funkce pro přidání položky do zásobníku
 * @param stck Pointer na zásobník, do kterého se má přidat prvek
 * @param item Položka, která se má přidat do zásobníku
 */
void push(struct stack *stck, struct Node *item)
{
    // Vytáhnutí aktuálního vrcholu zásobníku
    struct Node *current_top = stck->top;

    // Pokud zásobník už má nějaký vrchol,
    // tak se nastaví vazba mezi novým vrcholem a starým vrcholem
    if (current_top != NULL)
    {
        item->next = current_top;
    }

    // Nastavení vrcholu zásobníku na přidávanou položku
    stck->top = item;
}

struct Node *pop(struct stack *stck)
{
    if (stck->top == NULL)
    {
        return NULL;
    }
    else
    {
        struct Node *current_top = stck->top;
        stck->top = stck->top->next;
        current_top->next = NULL;

        return current_top;
    }
}

/**
 * Funkce pro kontrolní výpis zásobníku
 * @param stck Pointer na zásobník
 */
void display(struct stack *stck)
{
    // Display the elements of the stack
    if (stck->top == NULL)
    {
        printf("\nStack Underflow\n");
    }
    else
    {
        printf("The stack is \n");
        struct Node *temp = stck->top;
        while (temp->next != NULL)
        {
            printf("%s--->", temp->data);
            temp = temp->next;
        }
        printf("%s--->NULL\n\n", temp->data);
    }
}

/**
 * Pomocná funkce pro vytvoření nové položky zásobníku
 * @return Pointer na položku zásobníku v paměti
 */
struct Node *new_node(char *data, int size)
{
    struct Node *pointer_to_node = (struct Node *)malloc(sizeof(struct Node));
    pointer_to_node->data = data;
    pointer_to_node->size = size;
    pointer_to_node->next = NULL;

    return pointer_to_node;
}