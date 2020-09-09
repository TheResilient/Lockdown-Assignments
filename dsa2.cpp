// C++ program to evaluate value of a postfix expression 
#include <limits.h>
#include <iostream> 
#include <string.h> 

using namespace std; 

// Stack type 
struct Stack 
{ 
	int top; 
	unsigned capacity; 
	int* array; 
}; 

// Stack Operations 


int isEmpty(struct Stack* stack) 
{ 
	return stack->top == -1 ; 
} 

char peek(struct Stack* stack) 
{ 
	return stack->array[stack->top]; 
} 

char pop(struct Stack* stack) 
{ 
	if (!isEmpty(stack)) 
		return stack->array[stack->top--] ; 
	return '$'; 
} 

void push(struct Stack* stack, char op) 
{ 
	stack->array[++stack->top] = op; 
} 

int peek1(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return INT_MIN; 
    return stack->array[stack->top]; 
} 


int checkIfOperand(char ch) 
{ 
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'); 
} 



int precedence(char ch) 
{ 
    switch (ch) 
    { 
    case '+': 
    case '-': 
        return 1; 

    case '*': 
    case '/': 
        return 2; 

    case '^': 
        return 3; 
    } 
    return -1; 
}

int covertInfixToPostfix(char *expression, int no)
{
    struct Stack *stack = new (Stack);
    stack->capacity = strlen(expression);
    stack->top = -1;
    stack->array = new (int);
    int i, j;
    for (i = 0, j = -1; expression[i]; ++i)
    {
        // Here we are checking is the character we scanned is operand or not
        // and this adding to to output.
        if (checkIfOperand(expression[i]))
            expression[++j] = expression[i];

        // Here, if we scan character ‘(‘, we need push it to the stack.
        else if (expression[i] == '(')
            push(stack, expression[i]);

        // Here, if we scan character is an ‘)’, we need to pop and print from the stack
        // do this until an ‘(‘ is encountered in the stack.
        else if (expression[i] == ')')
        {
            while (!isEmpty(stack) && peek1(stack) != '(')
                {expression[++j] = pop(stack);}
            if (!isEmpty(stack) && peek1(stack) != '(')
                return -1; // invalid expression
            else
                pop(stack);
        }
        else // if an opertor
        {
            while (!isEmpty(stack) && precedence(expression[i]) <= precedence(peek(stack)))
                {expression[++j] = pop(stack);}
            push(stack, expression[i]);
        }
    }
    while (!isEmpty(stack))
        {expression[++j] = pop(stack);}

    expression[++j] = '\0';
    if (no==1)
        printf("%s", expression);
    else ;

}

void reverse (char *exp)
{				//reverse function for expression

  int size = strlen (exp);
  int j = size, i = 0;
  char temp[size];

  temp[j--] = '\0';
  while (exp[i] != '\0')
    {
      temp[j] = exp[i];
      j--;
      i++;
    }
  strcpy (exp, temp);
}

void brackets (char *exp)
{
  int i = 0;
  while (exp[i] != '\0')
    {
      if (exp[i] == '(')
	exp[i] = ')';
      else if (exp[i] == ')')
	exp[i] = '(';
      i++;
    }
}

void conversionInfixToPrefix (char *exp)
{
  int size = strlen (exp);
  reverse (exp);
  brackets (exp);
  covertInfixToPostfix (exp,0);
  reverse (exp);
}


// The main function that returns value of a given postfix expression 
int evaluatePostfix(char* exp) 
{ 
  	struct Stack* stack = new Stack(); 
	stack->top = -1; 
	stack->capacity = strlen(exp); 
	stack->array = (int*) malloc(stack->capacity * sizeof(int)); 

	
  	
	// Create a stack of capacity equal to expression size 
	// See if stack was created successfully 
	

	// Scan all characters one by one 
	for (int i = 0; exp[i]; ++i) 
	{ 
		// If the scanned character is an operand (number here), 
		// push it to the stack. 
		if (isdigit(exp[i])) 
			push(stack, exp[i] - '0'); 

		// If the scanned character is an operator, pop two 
		// elements from stack apply the operator 
		else
		{ 
			int val1 = pop(stack); 
			int val2 = pop(stack); 
			switch (exp[i]) 
			{ 
			case '+': push(stack, val2 + val1); break; 
			case '-': push(stack, val2 - val1); break; 
			case '*': push(stack, val2 * val1); break; 
			case '/': push(stack, val2/val1); break; 
			} 
		} 
	} 
	return pop(stack); 
} 

// Driver program to test above functions 
int main() 
{ 
  	char expression[] = "a+b-e*(h+r)";
  	covertInfixToPostfix(expression,1);
  	cout<<endl;
  	cout << "The infix expression is: \n";
    char expression1[] = "(P+(Q*R)/(S-T))";
    cout << expression1 << "\n";
    conversionInfixToPrefix (expression1);
    cout << "The prefix expression is: \n";
    cout << expression1<<endl;
	char exp[] = "231*+9-"; 
	cout<<"postfix evaluation: "<< evaluatePostfix(exp); 
	
} 
