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
 * delete_nodeint_at_index - deletes the node at index of a listint_t linked list
 * @head: pointer to pointer to the first node of the list
 * @index: index of the node to delete
 *
 * Return: 1 if succeeded, -1 if failed
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
    listint_t *prev_node, *node_to_delete;
    unsigned int i;

    if (head == NULL || *head == NULL)
    {
        return (-1);
    }
    if (index == 0)
    {
        node_to_delete = *head;
        *head = (*head)->next;
        free(node_to_delete);
        return (1);
    }
    prev_node = *head;

    for (i = 0; i < index - 1 && prev_node->next != NULL; i++)
    {
        prev_node = prev_node->next;
    }
    if (i < index - 1 || prev_node->next == NULL)
    {
        return (-1);
    }
    node_to_delete = prev_node->next;
    prev_node->next = node_to_delete->next;
    free(node_to_delete);

    return (1);

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
    delete_nodeint_at_index(&head, 5);
    print_listint(head);
    printf("-----------------\n");
    delete_nodeint_at_index(&head, 0);
    print_listint(head);
    printf("-----------------\n");
    delete_nodeint_at_index(&head, 0);
    print_listint(head);
    printf("-----------------\n");
    delete_nodeint_at_index(&head, 0);
    print_listint(head);
    printf("-----------------\n");
    delete_nodeint_at_index(&head, 0);
    print_listint(head);
    printf("-----------------\n");
    delete_nodeint_at_index(&head, 0);
    print_listint(head);
    printf("-----------------\n");
    delete_nodeint_at_index(&head, 0);
    print_listint(head);
    printf("-----------------\n");
    delete_nodeint_at_index(&head, 0);
    printf("-----------------\n");
    delete_nodeint_at_index(&head, 0);
    printf("-----------------\n");
    delete_nodeint_at_index(&head, 0);
    printf("-----------------\n");
    delete_nodeint_at_index(&head, 0);
    printf("-----------------\n");
    delete_nodeint_at_index(&head, 0);
    printf("-----------------\n");
    delete_nodeint_at_index(&head, 0);
    printf("-----------------\n");
    delete_nodeint_at_index(&head, 0);
    printf("-----------------\n");
    delete_nodeint_at_index(&head, 0);
    printf("-----------------\n");
    delete_nodeint_at_index(&head, 0);
    printf("-----------------\n");
    delete_nodeint_at_index(&head, 0);
    print_listint(head);
    return (0);
}