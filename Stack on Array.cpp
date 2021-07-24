#include <iostream>
#include <cstring>
using namespace std;
#define STACK_MAX_SIZE 20
#define STACK_OVERFLOW -100
#define STACK_UNDERFLOW -101

struct Stack_t
{
	int data[STACK_MAX_SIZE];
	int size;
};

void Push(Stack_t *stack, const int value)
{
	if ((*stack).size >= STACK_MAX_SIZE) {
		exit(STACK_OVERFLOW); 
	}
	stack->data[stack->size] = value;
	stack->size += 1;
}

int Pop(Stack_t *stack)
{
	if (stack->size <= 0) {
		exit(STACK_UNDERFLOW); 
	}
	stack->size--;
	return stack->data[stack->size];
}

int Peek(Stack_t *stack)
{
	if (stack->size <= 0) {
		exit(STACK_UNDERFLOW);
	}
	return stack->data[stack->size - 1];
}

void PrintStack(Stack_t *stack)
{
	int i=0;
	for (int i = 0; i < (*stack).size; i++) {
		if (i == stack->size - 1) cout << stack->data[i] << endl;
		else cout << stack->data[i] << "|";
	}
}

int main()
{
	Stack_t stack;
	stack.size = 0;
	Push(&stack, 3);
	PrintStack(&stack);
	Push(&stack, 5);
	PrintStack(&stack);
	Pop(&stack);
	PrintStack(&stack);
	Push(&stack, -2);
	PrintStack(&stack);
	Push(&stack, 56);
	PrintStack(&stack);
	Pop(&stack);
	PrintStack(&stack);
	Pop(&stack);
	PrintStack(&stack);
	cout << Peek(&stack) << endl;
	return 0;
}