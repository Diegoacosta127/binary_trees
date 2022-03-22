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

/**
  * binary_tree_balance - measures the balance of a binary tree
  * @tree: pointer to the root node of the tree to measure the nodes
  * Return: the balance of the tree, 0 if tree is NULL
  */
int binary_tree_balance(const binary_tree_t *tree)
{
	int h_left = 0, h_right = 0;

	if (!tree || (!tree->left && !tree->right))
		return (0);
	if (tree->left)
		h_left = 1 + binary_tree_height(tree->left);
	if (tree->right)
		h_right = 1 + binary_tree_height(tree->right);

	return (h_left - h_right);
}
