#include "binary_trees.h"
#include <stdio.h>
/**
  * binary_tree_sibling - returns the sibling of a node in a binary tree
  * @node: pointer to a node of the tree
  * Return: pointer to the sibling
  */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node)
		return (0);

	if (!node->parent)
		return (NULL);
	/*
	 * printf("address of the node: %p\n", (void *)node);
	 * printf("adress of the parent: %p\n", (void *)node->parent);
	 * printf("adress of the right child: %p\n", (void *)node->parent->right);
	 * printf("adress of the left child: %p\n", (void *)node->parent->left);
	 */

	if ((void *)node == (void *)node->parent->left)
		return (node->parent->right);
	else
		return (node->parent->left);
}
