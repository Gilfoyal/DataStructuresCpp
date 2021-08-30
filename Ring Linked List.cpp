#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node* prev;
};

struct Ring
{
	size_t size;
	Node* current;
};

Ring* createRing
{
	Ring * tmp = new Ring[sizeof(Ring)];
	tmp->size = 0;
	tmp->current = NULL;
	return tmp;
};

void addElement(Ring* ring, int value)
{
	Node* prev = NULL;
	Node* tmp = new Node[sizeof(Node)];
	tmp->data = value;
	if (ring->current == NULL) {
		ring->current = tmp;
		tmp->next = tmp->prev = tmp;
	} else {
		prev = ring->current->next->prev;
		tmp->next = ring->current->next;
		tmp->prev = ring->current;
		prev->prev = tmp;
		ring->current->next = tmp;
		ring->current = tmp;
	}
	ring->size += 1;
}

int removeElement(Ring* ring)
{
	Node* afterTarget = NULL;
	int retValue;
	if (ring->current == NULL) {
		exit(1);
	}
	if (ring->current->next == ring->current) {
		retValue = ring->current->data;
		free(ring->current);
		ring->current == NULL;
	}
	else {
		afterTarget = ring->current->next;
		ring->current->prev->next = afterTarget;
		afterTarget->prev = ring->current->prev;
		retValue = ring->current->data;
		free(ring->current);
		ring->current = afterTarget;
	}
	ring->size -= 1;
	return retValue;
}

Node* next(Ring* ring)
{
	Node* retValue = NULL;
	if (ring->current) {
		ring->current = ring->current->next;
		retValue = ring->current;
	}
	return retValue;
}

Node* prev(Ring* ring)
{
	Node* retValue = NULL;
	if (ring->current) {
		ring->current = ring->current->prev;
		retValue = ring->current;
	}
	return retValue;
}

void circle(const Ring* ring, void (*f)(Node* node))
{
	Node* anchor = ring->current;
	if (anchor) {
		do {
			f(anchor);
			anchor = anchor->next;
		} while (anchor != ring->current);
	}
}

void printNode(Node* node) {
	printf("%d ", node->data);
}

int main()
{
	return 0;
}

