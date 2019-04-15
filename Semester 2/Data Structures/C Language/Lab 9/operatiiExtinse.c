#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct stiva
{
	char expr;
    struct stiva *next;
} STACK;

static STACK *top = NULL;

static STACK *NewStack(char expr)
{
    STACK *newp = (STACK*) malloc(sizeof(STACK));

    newp -> expr = expr;
    newp -> next = NULL;

    return newp;
}

static void Push(STACK *newp)
{
    STACK **tracer = &top;

    if(!(*tracer))  *tracer = newp;
    else
    {
        newp -> next = *tracer;
        *tracer = newp;
    }
    
}

static int Pop()
{
    STACK *_toRemove = NULL;
    STACK **tracer = &top;
    char expr;

    if(!(*tracer))  return -1;
    else
    {
        expr = (*tracer) -> expr;
        _toRemove = *tracer;
        *tracer = (*tracer) -> next;

        free(_toRemove);
        return expr;
    }
}

static int Peek()
{
	STACK **tracer = &top;

	if(!(*tracer))	return -1;
	else 	return (*tracer) -> expr;
}

static _Bool IsEmpty()
{
    STACK **tracer = &top;

    if(!(*tracer))  return 1;
    else            return 0;
}

typedef struct stiva1
{
	int numar;
    struct stiva1 *next;
} STACK1;

static STACK1 *top1 = NULL;

static STACK1 *NewStack1(int numar)
{
    STACK1 *newp = (STACK1*) malloc(sizeof(STACK1));

    newp -> numar = numar;
    newp -> next = NULL;

    return newp;
}

static void Push1(STACK1 *newp)
{
    STACK1 **tracer = &top1;

    if(!(*tracer))  *tracer = newp;
    else
    {
        newp -> next = *tracer;
        *tracer = newp;
    }
    
}

static int Pop1()
{
    STACK1 *_toRemove = NULL;
    STACK1 **tracer = &top1;
    int numar;

    if(!(*tracer))  return -1;
    else
    {
        numar = (*tracer) -> numar;
        _toRemove = *tracer;
        *tracer = (*tracer) -> next;

        free(_toRemove);
        return numar;
    }
}

static int Peek1()
{
	STACK1 **tracer = &top1;

	if(!(*tracer))	return -1;
	else 	return (*tracer) -> numar;
}

static _Bool IsEmpty1()
{
    STACK1 **tracer = &top1;

    if(!(*tracer))  return 1;
    else            return 0;
}


typedef struct coada
{
    char expr;
    struct coada *next;
} QUEUE;

static QUEUE *head = NULL;
static QUEUE *tail = NULL;


static QUEUE *NewQueue(char expr)
{
	QUEUE *newp = ((QUEUE*) malloc(sizeof(QUEUE)));

	newp -> expr = expr;
	newp -> next = NULL;

	return newp;
}

static void Enqueue(QUEUE *newp)
{
	QUEUE **tracer = &tail;

	if(!(*tracer))
	{
		*tracer = newp;
		head = newp;
	}
	else
	{
		(*tracer) -> next = newp;
		*tracer = newp;
	}
}

static void Clear(char *expression)
{
	QUEUE *_toRemove = NULL;
	QUEUE **tracer = &head;
	int i=0;

	if(!(*tracer))	;
	else
	{
		while(*tracer)
		{
			expression[i++] = (*tracer) -> expr;

			_toRemove = *tracer;
			*tracer = (*tracer) -> next;

			free(_toRemove);
		}

		expression[i] = '\0';
		tail = NULL;
	}
}

static void PrintQueue()
{
	QUEUE **tracer = &head;

	if(!(*tracer))	return;
	else
	{
		while(*tracer)
		{
			printf("%c", (*tracer) -> expr);

			tracer = &(*tracer) -> next;
		}

		puts("");
	}
}

static _Bool IsDigit(char expr)
{
	if (expr > 47 && expr < 58)	return 1;
	else						return 0;
}

static _Bool IsOperand(char expr)
{
	if ((expr > 64 && expr < 91) || (expr > 96 && expr < 123))	return 1;
	else														return 0;
}

static _Bool IsOperator(char expr)
{
	if(expr == '^' ||
		expr == '*' ||
		expr == '/' ||
		expr == '+' ||
		expr == '-' ||
		expr == '%')
		return 1;
	else	return 0;
}

static int Precedence(char expr)
{
	switch (expr) 
    { 
		case '+': 
		case '-': 
			return 1; 
	
		case '*': 
		case '/': 
		case '%':
			return 2; 
	
		case '^': 
			return 3; 
    } 

    return -1; 
}

static void InfixToPostfix(char *string)
{
	for(int i=0; i<strlen(string); ++i)
	{
		if(IsOperand(string[i]))
			Enqueue(NewQueue(string[i]));

		else if(IsDigit(string[i]))
		{
			do
			{
				Enqueue(NewQueue(string[i]));
			} while (IsDigit(string[++i]));

			--i;
			Enqueue(NewQueue(' '));
		}
		
		else if(string[i] == '(')
			Push(NewStack(string[i]));
		
		else if(IsOperator(string[i]))
		{
			while(!IsEmpty() && (Precedence(string[i]) <= Precedence(Peek())))
				Enqueue(NewQueue(Pop()));
			
			Push(NewStack(string[i]));
		}

		else if(string[i] == ')')
		{
			while(!IsEmpty() && (Peek() != '('))
				Enqueue(NewQueue(Pop()));

			Pop();
		}
	}

	while(!IsEmpty())	Enqueue(NewQueue(Pop()));
}

static int Power(int a, int b)
{
	int value = a;

	for(int i=1; i<b; ++i)
		value *= a;

	return value;
}

static int Compute(char expr, int a, int b)
{
	switch(expr)
	{
		case '+':
			printf("%d + %d = %d\n", b, a, b+a);
			return b+a;
			break;
		case '-':
			printf("%d - %d = %d\n", b, a, b-a);
			return b-a;
			break;
		case '*':
			printf("%d * %d = %d\n", b, a, b*a);
			return b*a;
			break;
		case '/':
			printf("%d / %d = %d\n", b, a, b/a);
			return b/a;
			break;
		case '%':
			printf("%d %% %d = %d\n", b, a, b%a);
			return b%a;
			break;
		case '^':
			printf("%d ^ %d = %d\n", b, a, Power(b,a));
			return Power(b,a);
			break;
	}
}

static void EvaluateExpression(char *expression)
{
	for(int i=0; i<strlen(expression); ++i)
	{
		if(expression[i] == ' ')	continue;
		else if(IsDigit(expression[i]))
		{
			int nr = 0;
			do
			{
				nr *= 10;
				nr += expression[i] - '0';
			} while(IsDigit(expression[++i]));

			--i;
			Push1(NewStack1(nr));
		}
		else if(IsOperator(expression[i]))
		{
			int nr1 = Pop1();
			int nr2 = Pop1();

			Push1(NewStack1(Compute(expression[i], nr1, nr2)));
		}
	}

	printf("Expression Evaluates to: %d\n", Pop1());
}


// expression tree
typedef struct ArboreExpresie
{
	char ch;
	int nr;
	// 0 for operands or operators
	// 1 for numbers
	_Bool type;
	struct ArboreExpresie *left;
	struct ArboreExpresie *right;
} TREE;

static TREE *headTree = NULL;

static void *NewElement(char ch, int nr, _Bool option)
{
	TREE *newp = (TREE*) malloc(sizeof(TREE));

	if(option)
	{
		newp -> type = option;
		newp -> nr = nr;
		newp -> left = NULL;
		newp -> right = NULL;
	}
	else
	{
		newp -> type = option;
		newp -> ch = ch;
		newp -> left = NULL;
		newp -> right = NULL;
	}

	return newp;
}

static void InOrder(TREE **tracer)
{
	if(*tracer)
	{
		InOrder(&(*tracer) -> left);
		if((*tracer) -> type)
			printf("%d", (*tracer) -> nr);
		else
			printf("%c", (*tracer) -> ch);
		InOrder(&(*tracer) -> right);
	}
}

static void DeleteTree(TREE **tracer)
{
	if(*tracer)
	{
		DeleteTree(&(*tracer) -> left);
		DeleteTree(&(*tracer) -> right);

		free(*tracer);
	}
}


typedef struct stivaArbore
{
	TREE *arbore;
	struct stivaArbore *next;
} STACKTREE;

static STACKTREE *topTree = NULL;

static STACKTREE *NewStackTree(TREE *arbore)
{
	STACKTREE *newp = (STACKTREE*) malloc(sizeof(STACKTREE));

	newp -> arbore = arbore;
	newp -> next = NULL;

	return newp;
}

static void PushStackTree(STACKTREE *newp)
{
	STACKTREE **tracer = &topTree;

	if(!(*tracer))	*tracer = newp;
	else
	{
		newp -> next = *tracer;
		*tracer = newp;
	}
}

static TREE* PopTree()
{
	STACKTREE *_toRemove = NULL;
	STACKTREE **tracer = &topTree;
	TREE *_toReturn;

	if(!(*tracer))	return NULL;

	_toReturn = (*tracer) -> arbore;
	_toRemove = *tracer;
	(*tracer) = (*tracer) -> next;

	free(_toRemove);
	return _toReturn;
}

static TREE *CreateExpressionTree(char *postfix)
{
	TREE *t;
	for(int i=0; i<strlen(postfix); ++i)
	{
		if(postfix[i] == ' ')	continue;

		if(IsDigit(postfix[i]))
		{
			int nr=0;
			do
			{
				nr *= 10;
				nr += postfix[i] - '0';
			} while(IsDigit(postfix[++i]));
			--i;

			PushStackTree(NewStackTree(NewElement('\0', nr, 1)));
		}
		else if(IsOperand(postfix[i]))
		{
			PushStackTree(NewStackTree(NewElement(postfix[i], -1, 0)));
		}
		else
		{
			t = NewElement(postfix[i], -1, 0);
			
			t -> right = PopTree();
			t -> left = PopTree();

			PushStackTree(NewStackTree(t));
		}
	}

	t = PopTree();

	return t;
}

void ControlOE(int option, char *expression)
{
    char *expr = (char*) malloc(MAX);
    switch (option)
    {
        case 1:
            InfixToPostfix(expression);
            Clear(expr);

            EvaluateExpression(expr);

            free(expr);
            break;
        case 2:
            InfixToPostfix(expression);
            Clear(expr);
            
            headTree = CreateExpressionTree(expr);
            printf("Expresia este:\n");
            InOrder(&headTree);
            puts("");
            DeleteTree(&headTree);

            free(expr);
            break;
        default:
            free(expr);
            printf("\nSomething went Wrong with ControlOE!\n");
            break;
    }
}