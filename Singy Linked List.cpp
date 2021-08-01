#include <iostream>
using namespace std;

struct Node
{
	int value;
	Node* back;
};

void Push(Node **head, int data)
{
	Node *tmp = new Node[sizeof(Node)];
	tmp->value = data;
	tmp->back = *head;
	*head = tmp;
}

int Pop(Node **head)
{
	Node *prev = NULL;
	int value;
	if (head == NULL) {
		exit(-1);
	}
	value = (*head)->value;
	prev = *head;
	*head = (*head)->back;
	free(prev);
	return value;
}

Node* getPointer(Node *head, int n)
{
	int counter = 0;
	while (counter < n && head) {
		head = head->back;
		counter += 1;
	}
	return head;
}

Node* getLast(Node *head)
{
	if (head == NULL) {
		return NULL;
	}
	while (head) {
		head = head->back;
	}
	return head;
}

void Pushback( Node *head, int value)
{
	Node *last = getLast(head);
	Node *tmp = new Node[sizeof(Node)];
	tmp->value = value;
	tmp->back = NULL;
	last->back = tmp;
}

Node* getpredLast(Node* head)
{
	if (head == NULL) {
		exit(-2);
	}
	if (head->back == NULL) {
		return NULL;
	}
	while (head->back->back) {
		head = head->back;
	}
	return head;
}

void PopBack(Node **head)
{
	Node *lastel = NULL;
	if (!head) {
		exit(-1);
	}
	if (!(*head)) {
		exit(-1);
	}
	lastel = getpredLast(*head);
	if (lastel == NULL) {
		free(*head);
		*head = NULL;
	}
}

void Insert(Node *head, unsigned n, int value)
{
	unsigned counter = 0;
	Node *tmp = NULL;
	while (head->back && counter < n) {
		counter += 1;
		head = head->back;
	}
	tmp = new Node[sizeof(Node)];
	tmp->value = value;
	if (head->back) {
		tmp->back = head->back;
	}
	else {
		head->back = tmp;
	}
}

int deleteNode(Node **head, int n)
{
	if (n == 0) {
		return Pop(head);
	}
	Node *prev = getPointer(*head, n - 1);
	Node *elm = prev->back;
	int value = elm->value;
	prev->back = elm->back;
	free(elm);
	return value;
}

void deleteList(Node **head)
{
	Node *prev = NULL;
	while ((*head)->back) {
		prev = *head;
		*head = (*head)->back;
		free(prev);
	}
	free(*head);
}

void printList(const Node *head)
{
	while (head) {
		cout << head->value << " ";
		head = head->back;
	}
	cout << "\n";
}

int main()
{
	Node *head = NULL;
	Push(&head, 10);
	Push(&head, 21);
	printList(head);
	Pop(&head);
	deleteList;
	return 0;
}
