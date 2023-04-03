#include "lists.h"

/**
 * print_listint - Prints all the elements of a listint_t list.
 * @h: Pointer to the head node of the list.
 *
 * Return: The number of nodes in the list.
 */

size_t print_listint(const listint_t *h)
{
    size_t i = 0;

    while (h != NULL)
    {
        printf("%d\n", h->n);
        h = h->next;
        i++;
    }

    return (i);
}

/**
 * add_nodeint - add node to first
 * @head: double pointer to first node
 * @n 
*/

listint_t *add_nodeint(listint_t **head, const int  n)
{
    listint_t *new_node;
    new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)
    {
        return (NULL);
    }
    new_node->n = n;
    new_node->next = *head;
    *head = new_node;
    
    return (new_node);

}

/**
 * main - check the code
 *
 * Return: Always 0.
 */

int main(void)
{
    listint_t *head = NULL;
    add_nodeint(&head, 0);
    add_nodeint(&head, 1);
    add_nodeint(&head, 2);
    add_nodeint(&head, 3);
    add_nodeint(&head, 4);
    add_nodeint(&head, 98);
    add_nodeint(&head, 402);
    add_nodeint(&head, 1024);
    print_listint(head);
    return (0);
}