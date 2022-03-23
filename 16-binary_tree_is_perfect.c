#include "binary_trees.h"
#include <stdio.h>
/**
  * b_t_height - measures the height of a binary tree
  * @tree: pointer to the root node of the tree to measure the height
  * Return: the height of the leaf, 0 if tree is NULL
  */
size_t b_t_height(const binary_tree_t *tree)
{
	size_t h_left = 0, h_right = 0;

	if (!tree || (!tree->left && !tree->right))
		return (0);

	h_left = 1 + b_t_height(tree->left);
	h_right = 1 + b_t_height(tree->right);

	if (h_left > h_right)
		return (h_left);
	else
		return (h_right);


}

/**
  * b_t_balance - measures the balance of a binary tree
  * @tree: pointer to the root node of the tree to measure the nodes
  * Return: the balance of the tree, 0 if tree is NULL
  */
int b_t_balance(const binary_tree_t *tree)
{
	int h_left = 0, h_right = 0;

	if (!tree || (!tree->left && !tree->right))
		return (0);
	if (tree->left)
		h_left = 1 + b_t_height(tree->left);
	if (tree->right)
		h_right = 1 + b_t_height(tree->right);

	return (h_left - h_right);
}

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
/**
  * binary_tree_is_perfect - checks if a binary tree is perfect
  * @tree: pointer to the root node of the tree to check
  * Return: 1 if is perfect, 0 if not or tree is NULL
  */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (binary_tree_is_full(tree))
		if (b_t_balance(tree->left) == 0 && b_t_balance(tree->right) == 0)
			return (1);
	return (0);
}
