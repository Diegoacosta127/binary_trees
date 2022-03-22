#include "binary_trees.h"
#include <stdio.h>
/**
  * binary_tree_nodes - measures the amount of nodes on a binary tree w/ child
  * @tree: pointer to the root node of the tree to measure the nodes
  * Return: the amount of nodes with child, 0 if tree is NULL
  */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 1;

	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (0);

	nodes += binary_tree_nodes(tree->left);
	nodes += binary_tree_nodes(tree->right);

	return (nodes);
}
