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
 * add_nodeint_end - add node to end
 * @head: double pointer to head
*/

listint_t *add_nodeint_end(listint_t **head, const int n)
{
    listint_t *current;
    listint_t *new_node = malloc(sizeof(listint_t));
    
    if (new_node == NULL)
    {
        return (NULL);
    }
    new_node->n = n;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
        return (new_node);
    }

    current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = new_node;
    return (new_node);

}

/**
 * free_listint2 - free listint2
 * @head: double pointer to head
 * 
 */

void free_listint2(listint_t **head)
{
    listint_t *current, *temp;
    
    if (head == NULL)
    {
        return;
    }
    current = *head;

    while (current != NULL)
    {
        temp = current;
        current = current->next;
        free(temp);
    }
}

/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: pointer to the head of the list
 * @idx: index of the position where the new node should be added
 * @n: value to be added to the new node
 *
 * Return: address of the new node, or NULL if it failed
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
    unsigned int i;
    listint_t *new_node, *current;

    if (head == NULL)
    {
        return (NULL);
    }
    new_node = malloc(sizeof(listint_t));
    if (new_node == NULL)
    {
        return (NULL);
    }
    
    new_node->n = n;

    if (idx == 0)
    {
        new_node->next = *head;
        *head = new_node;
        return (new_node); 
    }
    current = *head;
    for (i = 0; i < idx - 1 && current != NULL; i++)
    {
        current = current->next;
    }
    if (current == NULL)
    {
        free(new_node);
        return (NULL);
    }
    new_node->next= current->next;
    current->next = new_node;

    return (new_node);

}


int main(void)
{
    listint_t *head;

    head = NULL;
    add_nodeint_end(&head, 0);
    add_nodeint_end(&head, 1);
    add_nodeint_end(&head, 2);
    add_nodeint_end(&head, 3);
    add_nodeint_end(&head, 4);
    add_nodeint_end(&head, 98);
    add_nodeint_end(&head, 402);
    add_nodeint_end(&head, 1024);
    print_listint(head);
    printf("-----------------\n");
    insert_nodeint_at_index(&head, 5, 4096);
    print_listint(head);
    free_listint2(&head);
    return (0);
}