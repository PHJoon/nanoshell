#include "test.h"

t_node	*insert(t_node *root, char *str)
{
	if (root == NULL)
	{
		root = (t_node *)malloc(sizeof(t_node));
		root->right = NULL;
		root->left = NULL;
		root->str = str;
		root->type = check_av(str);
		return (root);
	}
	else
	{
		if (check_av(str) < root->type)
			root->left = insert(root->left, str);
		else
			root->right = insert(root->right, str);
	}
	return (root);
}

t_node	*fMin(t_node *root)
{
	t_node	*min = root;

	while (min->left != NULL)
		min = min->left;
	return (min);
}

t_node	*delete(t_node *root, char *str)
{
	t_node	*tmproot = NULL;

	if (root == NULL)
		return (NULL);
	if (check_av(str) < root->type)
		root->left = delete(root->left, str);
	else if (check_av(str)> root->type)
		root->right = delete(root->right, str);
	else
	{
		if (root->left != NULL && root->right != NULL)
		{
			tmproot = fMin(root->right);
			root->type = tmproot->type;
			root->right = delete(root->right, tmproot->str);
		}
		else
		{
			tmproot = (root->left == NULL) ? root->right : root->left;
			free(root);
			return (tmproot);
		}
	}
	return (root);
}

void	print(t_node *root)
{
	if (root == NULL)
	{
		printf("\n");
		return ;
	}
	printf("%s:%d ", root->str, root->type);
	print(root->left);
	print(root->right);
}

void	preorderprint(t_node *root)
{
	if (root == NULL)
		return ;
	printf("%s:%d ", root->str, root->type);
	print(root->left);
	print(root->right);
}
