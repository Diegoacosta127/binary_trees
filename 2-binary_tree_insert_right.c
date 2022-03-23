#include "binary_trees.h"
/**
  * binary_tree_insert_right - insert a node as the right child of another node
  * @parent: pointer to the node to insert the right-child in
  * @value: value to store in the new node
  * Return: pointer to the created node, NULL if fails or parent is NULL
  */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_bt_node = malloc(sizeof(binary_tree_t));

	if (!new_bt_node)
	{
		return (NULL);
	}
	if (parent == NULL)
	{
		free(new_bt_node);
		return (NULL);
	}
	new_bt_node->n = value;
	new_bt_node->parent = parent;
	new_bt_node->left = NULL;
	if (parent->right != NULL)
	{
		parent->right->parent = new_bt_node;
		new_bt_node->right = parent->right;
		parent->right = new_bt_node;
	}
	else
	{
		new_bt_node->right = NULL;
		parent->right = new_bt_node;
	}
	return (new_bt_node);
}
