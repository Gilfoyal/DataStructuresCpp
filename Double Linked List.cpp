#include <iostream>
#include <ctime>
using namespace std;

struct Node
{
	void *value;
	Node *next;
	Node *prev;
};

typedef struct DoubleLinkedList
{
	size_t size;
	Node *head;
	Node *tail;
} DbList;

DbList *CreateDbList()
{
	DbList *tmp = new DbList[sizeof(DbList)];
	tmp->size = 0;
	tmp->head = tmp->tail = NULL;
	return tmp;
}

void deleteDbList(DbList **list)
{
	Node *tmp = (*list)->head;
	Node *next = NULL;
	while (tmp) {
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	free(*list);
	(*list) = NULL;
}

void PushFront(DbList *list, void *data)
{
	Node *tmp = new Node[sizeof(Node)];
	if (tmp == NULL) {
		exit(-1);
	}
	tmp->value = data;
	tmp->next = list->head;
	tmp->prev = NULL;
	if (list->head) {
		list->head->prev = tmp;
	}
	list->head = tmp;
	if (list->tail == NULL) {
		list->tail = tmp;
	}
	list->size += 1;
}

void *PopFront(DbList *list)
{
	Node *prev;
	void *tmp;
	if (list->head == NULL) {
		exit(2);
	}
	prev = list->head;
	list->head = list->head->next;
	if (list->head) {
		list->head->prev = NULL;
	}
	if (prev == list->tail) {
		list->tail = NULL;
	}
	tmp = prev->value;
	free(prev);
	list->size -= 1;
	return tmp;
}

void PushBack(DbList *list, void* value)
{
	Node *tmp = new Node[sizeof(Node)];
	if (tmp == NULL) {
		exit(3);
	}
	tmp->value = value;
	tmp->next = NULL;
	tmp->prev = list->tail;
	if (list->tail) {
		list->tail->next = tmp;
	}
	list->tail = tmp;
	if (list->head == NULL) {
		list->head = tmp;
	}
	list->size += 1;
}

void *PopBack(DbList *list)
{
	Node *next;
	void *tmp;
	if (list->tail == NULL) {
		exit(4);
	}
	next = list->tail;
	list->tail = list->tail->prev;
	if (list->tail) {
		list->tail->next = NULL;
	}
	if (next == list->head) {
		list->head = NULL;
	}
	tmp = next->value;
	free(next);
	list->size -= 1;
	return tmp;
}

Node* GetNthElement(DbList *list, size_t index)
{
	Node *tmp = list->head;
	size_t i = 0;
	while (tmp && i < index) {
		tmp = tmp->next;
		i += 1;
	}
	return tmp;
}

void Insert(DbList *list, size_t index, void* value)
{
	Node *elm = NULL;
	Node *ins = NULL;
	elm = GetNthElement(list, index);
	if (elm == NULL) {
		exit(5);
	}
	ins = new Node[sizeof(Node)];
	ins->value = value;
	ins->prev = elm;
	ins->next = elm->next;
	if (elm->next) {
		elm->next->prev = ins;
	}
	elm->next = ins;
	if (!elm->prev) {
		list->head = elm;
	}
	if (!elm->next) {
		list->tail = elm;
	}
	list->size += 1;
}

void* DeleteNode(DbList *list, size_t index)
{
	Node *elm = NULL;
	void *tmp = NULL;
	elm = GetNthElement(list, index);
	if (elm == NULL) {
		elm->prev->next = elm->next;
	}
	tmp = elm->value;
	if (!elm->prev) {
		list->head = elm->next;
	}
	if (!elm->next) {
		list->tail = elm->prev;
	}
	free(elm);
	list->size -= 1;
	return tmp;
}

void PrintList(DbList *list)
{
	Node *tmp = list->head;
	while (tmp) {
		cout << *((int*)tmp->value) << " ";
		tmp = tmp->next;
	}
	cout << "\n";
}

int main()
{
	DbList *list = CreateDbList();
	int a = 0, b = 1, c = 2;
	PushBack(list, &a);
	PushFront(list, &b);
	PrintList(list);
	Insert(list, 1, &c);
	PrintList(list);
	DeleteNode(list, 0);
	PrintList(list);
	return EXIT_SUCCESS;
}