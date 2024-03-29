#include "binary_trees.h"
#include <stdio.h>
/**
  * binary_tree_is_full - checks if a binary tree is full
  * @tree: pointer to the root node of the tree to measure the nodes
  * Return: 1 if it's full, 0 if not or tree is NULL
  */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (tree->left && tree->right)
		return (binary_tree_is_full(tree->left)
			&& binary_tree_is_full(tree->right));
	return (0);
}
