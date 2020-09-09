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
} 

void push(struct Stack* stack, char op) 
{ 
	stack->array[++stack->top] = op; 
} 

int peek1(struct Stack* stack) 
{ 
    if (isEmpty(stack)) 
        return 0; 
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
        if (checkIfOperand(expression[i]))
            expression[++j] = expression[i];

        else if (expression[i] == '(')
            push(stack, expression[i]);

        else if (expression[i] == ')')
        {
            while (!isEmpty(stack) && peek1(stack) != '(')
                {expression[++j] = pop(stack);}
            if (!isEmpty(stack) && peek1(stack) != '(')
                return -1; 
            else
                pop(stack);
        }
        else 
        {
            while (!isEmpty(stack) && precedence(expression[i]) <= precedence(peek(stack)))
                {expression[++j] = pop(stack);}
            push(stack, expression[i]);
        }
    }
    while (!isEmpty(stack))
        {expression[++j] = pop(stack);}

    expression[++j] = NULL;
    
}

void reverse (char *exp)
{
  int size = strlen (exp);
  int j = size, i = 0;
  char temp[size];

  temp[j--] = NULL;
  while (exp[i] != NULL)
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
  while (exp[i] != NULL)
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

int evaluatePostfix(char* exp) 
{ 
  	struct Stack* stack = new Stack(); 
	stack->top = -1; 
	stack->capacity = strlen(exp); 
	stack->array = new (int); 
	for (int i = 0; exp[i]; ++i) 
	{ 
		if (isdigit(exp[i])) 
			push(stack, exp[i] - '0'); 
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

int main() 
{ 
    cout<<" 0. To quit \n 1. To convert infix to prefix \n 2. To convert infix to postfix \n 3. To evaluate postfix expression \n 4. To evaluate prefix expression \n";
    while(true){
        int a;
        cout<<endl;
        cout<<"Enter case number: ";
        cin >> a;
        cout<<endl;
        if(a==0) break;
        else{
            switch(a){
            case 1:
                {
                char expression[100];
                cout<< "Enter infix expression to be converted into postfix: ";
                cin>>expression;
                cout<<endl;
                covertInfixToPostfix(expression,1);
                cout<<"The Postfix expression is: "<<expression<<endl;
                break;}
            case 2:
                {char expression[100];
                cout<<"Enter Infix expression to be converted into Prefix: ";
                cin>>expression;
                cout<<endl;
                conversionInfixToPrefix (expression);
                cout << "The prefix expression is: "<<expression<<endl;;
                
                break;}
            case 3:
                {
                char exp[100]; 
                cout<<"Enter postfix expression to be evaluated: ";
                cin>>exp;
                cout<<endl;
                cout<<"postfix evaluation: "<< evaluatePostfix(exp)<<endl; 	
                break;}
            }
        }    
    }
    return 0;
} 