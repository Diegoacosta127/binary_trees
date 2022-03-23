#include "binary_trees.h"
#include <stdio.h>
/**
  * binary_tree_sibling - returns the sibling of a node in a binary tree
  * @tree: pointer to the root node of the tree
  * Return: pointer to the sibling
  */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node)
		return (0);

	if (!node->parent)
		return (NULL);

	if ((void *)node == (void *)node->parent->left)
		return (node->parent->right);
	else
		return (node->parent->left);
}

/**
  * binary_tree_uncle - returns the uncle of a node in a binary tree
  * @tree: pointer to the root node of the tree
  * Return: pointer to the uncle
  */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
        if (!node)
                return (0);

        if (!node->parent)
                return (NULL);

	return (binary_tree_sibling(node->parent));
}
