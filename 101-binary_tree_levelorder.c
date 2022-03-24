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
  * binary_tree_level - prints all values of nodes in a certain level
  * @tree: pointer to the root node of the tree to traverse
  * @level: number of the level to print
  * @func: function used to print
  * Return: void
  */
void binary_tree_level(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (!tree)
		return;
	if (level == 0)
	{
		func(tree->n);
	}
	else
	{
		binary_tree_level(tree->left, level - 1, func);
		binary_tree_level(tree->right, level - 1, func);
	}
}
/**
  * binary_tree_levelorder - goes through a tree using level-order traversal
  * @tree: pointer to the root node of the tree to traverse
  * @func: pointer to function to call for each node
  * Return: void
  */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height = binary_tree_height(tree);
	size_t i;

	if (!tree)
		return;
	if (func == NULL)
		return;
	for (i = 0; i < height + 1; i++)
		binary_tree_level(tree, i, func);
}
