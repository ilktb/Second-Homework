struct Node
{
	int data;
	struct Node *next;
}

Node* RemoveDuplicates(Node *head)
{
	if (head == NULL)
		return NULL;
	else {
		Node* p = head;
		while (p->next)	{
			Node* q = p->next;
			if (p->data == q->data) {
				p->next = q->next;
				delete q;
			}
			else {
				p = p->next;
			}
		}
	}
	return head;
}