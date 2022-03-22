#include "binary_trees.h"
#include <stdio.h>
/**
  * binary_tree_size - measures the size of a binary tree
  * @tree: pointer to the root node of the tree to measure the size
  * Return: the size of a node, 0 if tree is NULL
  */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 1;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	if (tree->left)
		size += binary_tree_size(tree->left);
	if (tree->right)
		size += binary_tree_size(tree->right);

	return (size);
}
