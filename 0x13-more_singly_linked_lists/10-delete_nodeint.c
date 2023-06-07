#include "lists.h"

/**
 * delete_nodeint_at_index - deletes a node in a linked list at a certain index
 * @head: pointer to the first element in the list
 * @index: position of the node to delete
 *
 * Return: 1 (Success), or -1 (Fail)
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp = *head;
	listint_t *current = *head;
	listint_t *previous = NULL;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	if (index == 0)
	{
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	for (i = 0; current != NULL && i < index; i++)
	{
		previous = current;
		current = current->next;
	}

	if (current == NULL)
		return (-1);

	previous->next = current->next;
	free(current);
	return (1);
}


