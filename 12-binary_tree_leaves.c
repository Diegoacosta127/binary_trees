#include "binary_trees.h"
#include <stdio.h>
/**
  * binary_tree_leaves - measures the amount of leaves on a binary tree
  * @tree: pointer to the root node of the tree to measure the leaves
  * Return: the amount of leaves, 0 if tree is NULL
  */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);
	else
	{
		leaves += binary_tree_leaves(tree->left);
		leaves += binary_tree_leaves(tree->right);
	}
	return (leaves);
}
