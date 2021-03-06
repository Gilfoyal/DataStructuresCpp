#include <iostream>
using namespace std;

#define STACK_OVERFLOW -100
#define STACK_UNDERFLOW -101
#define OUT_OF_MEMORY -102

struct Node
{
	int value;
	Node *next;
};

void Push(Node **head, int value)
{
	Node *tmp = new Node[sizeof(Node)];
	if (tmp == NULL) {
		exit(STACK_OVERFLOW);
	}
	tmp->next = *head;
	tmp->value = value;
	*head = tmp;
}

Node *Pop(Node **head)
{
	Node *out;
	if (*head == NULL) {
		exit(STACK_UNDERFLOW);
	}
	out = *head;
	*head = (*head)->next;
	return out;
}

int PopT(Node **head)
{
	Node *out;
	int value;
	if (*head == NULL) {
		exit(STACK_UNDERFLOW);
	}
	out = *head;
	*head = (*head)->next;
	value = out->value;
	free(out);
	return value;
}

int Peek(const Node *head)
{
	if (head == NULL) {
		exit(STACK_UNDERFLOW);
	}
	return head->value;
}

size_t StackSize(const Node *head)
{
	size_t size = 0;
	while (head) {
		size++;
		head = head->next;
	}
	return size;
}

void PrintStack(const Node *head)
{
	cout << "Stack -> ";
	while (head) {
		cout << head->value;
		head = head->next;
	}
	cout << endl;
}

int main()
{
	Node *head = NULL;
	for (int i = 0; i < 10; i++) {
		Push(&head, i);
	}
	cout << "Stack size is " << StackSize(head) << endl;
	while (head) {
		cout << PopT(&head) << " ";
	}
	return 0;
}