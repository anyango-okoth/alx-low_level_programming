#include "hash_tables.h"

/**
 * hash_table_set - function that adds an element to the hash table
 * @ht: pointer to hash table
 * @key: key to add the element
 * @value: value to add the element
 *
 * Return: 1 if it succeeded, 0 otherwise
 */

int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_table;
	char *node;
	unsigned long int index, n;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	node = strdup(value);
	if (node == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	for (n = index; ht->array[n]; n++)
	{
		if (strcmp(ht->array[n]->key, key) == 0)
		{
			free(ht->array[n]->value);
			ht->array[n]->value = node;
			return (1);
		}
	}

	new_table = malloc(sizeof(hash_node_t));
	if (new_table == NULL)
	{
		free(node);
		return (0);
	}
	new_table->key = strdup(key);
	if (new_table->key == NULL)
	{
		free(new_table);
		return (0);
	}
	new_table->value = node;
	new_table->next = ht->array[index];
	ht->array[index] = new_table;

	return (1);
}
