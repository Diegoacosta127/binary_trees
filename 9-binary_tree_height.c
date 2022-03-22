#include "binary_trees.h"
#include <stdio.h>
/**
  * binary_tree_height - measures the height of a binary tree
  * @tree: pointer to the root node of the tree to measure the height
  * Return: the height of the leaf, 0 if tree is NULL
  */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t h_left = 0, h_right = 0;

	if (!tree || (!tree->left && !tree->right))
		return (0);

	h_left = 1 + binary_tree_height(tree->left);
	h_right = 1 + binary_tree_height(tree->right);
	
	if (h_left > h_right)
		return (h_left);
	else
		return (h_right);
	
	
}
