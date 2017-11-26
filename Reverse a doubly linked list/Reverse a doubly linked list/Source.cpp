struct Node
{
	int data;
	Node *next;
	Node *prev;
};

Node* Reverse(Node* head)
{
	if (head != NULL) {
		Node* p = head;
		p->prev = p->next;
		p->next = NULL;
		Node* temp;
		while (p->prev)	{
			p = p->prev;
			temp = p->next;
			p->next = p->prev;
			p->prev = temp;
		}
		return p;
	}
	else {
		return NULL;
	}
	
}
