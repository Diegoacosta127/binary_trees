#include "binary_trees.h"
#include <stdio.h>
/**
  * binary_tree_depth - measures the depth of a binary tree
  * @tree: pointer to the root node of the tree to measure the depth
  * Return: the depth of a node, 0 if tree is NULL
  */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree || !tree->parent)
		return (0);
	return (1 + binary_tree_depth(tree->parent));
}
/**
  * binary_trees_ancestor - finds the lowest common ancestor of two nodes
  * @first: pointer to first node
  * @second: pointer to second node
  * Return: pointer to the lowest common ancestor node, NULL if not found
  */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	size_t d_fst = binary_tree_depth(first);
	size_t d_snd = binary_tree_depth(second);
	int diff = d_fst - d_snd;

	if (!first || !second)
		return (NULL);
	if (first->parent == second)
		return ((binary_tree_t *)second);
	if (first == second->parent)
		return ((binary_tree_t *)first);

	if (first == second)
		return ((binary_tree_t *)first);

	while (diff != 0)
	{
		/*printf("diff: %d\n", diff);*/
		if (diff < 0)
		{
			second = second->parent;
			diff++;
		}
		else
		{
			first = first->parent;
			diff--;
		}
		/*printf("f: %d\n2: %d\n", first->n, second->n);*/
	}
	while (first && second)
		if (first->parent != second->parent)
		{
			first = first->parent;
			second = second->parent;
		}
		else
			return (first->parent);
	return (NULL);
}
