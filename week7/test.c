KeyType getData()
{
	int n;
	KeyType tmpKey;
	printf("\nEnter Value: ");
	scanf("%d", &n);
	tmpKey.value = n;
	return tmpKey;
}

TREE addLeft(TREE *root, KeyType newKey)
{
	NODE *newNODE = makeNODE(newKey);
	if (newNODE == NULL)
		return (newNODE);
	if ((*root) == NULL)
		(*root) = newNODE;
	else {
		NODE *leftNODE = (*root);
		while (leftNODE->left != NULL)
			leftNODE = leftNODE->left;
		leftNODE->left = newNODE;
	}
	return newNODE;
}