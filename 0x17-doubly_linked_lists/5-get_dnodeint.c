#include "lists.h"

/**
 * get_dnodeint_at_index - returns the nth node of
 * a dlistint_t linked list.
 * @head: pointer to the head of the list
 * @index: index of the node, starting from 0
 * Return: NULL if the node does not exist
 */

dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i = 0;
	dlistint_t *tmp;

	if (head == NULL)
		return (NULL);
	tmp = head;

	while (tmp)
	{
		if (index == i)
			return (tmp);
		i++;
		tmp = tmp->next;
	}
	return (NULL);
}
