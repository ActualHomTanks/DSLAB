#include "Stack.hpp"
#include <iostream>

bool palindrome(char const a[])
{
	Stack s;
	for (int i = 0; a[i] != '\0'; i++) {
		s.push(a[i]);
	}

	for (int i = 0; a[i] != '\0'; i++) {
		if (s.pop() != a[i]) {
			return false;
		}
	}

	return true;
}


void convert(int n, int b)
{
	IntStack s;
	while (n > 0) {
		s.push(n % b);
		n = n / b;
	}

	while (!s.empty()) {
		std::cout << s.pop();
	}

	std::cout << '\n';
}


int precedence(char e)
{
	switch (e) {
		case '(': return 1;
		case '+':
		case '-': return 2;
		case '*':
		case '/': return 3;
		case '^': return 4;
		default: return 0;
	}

	return -1;
}


void infix_postfix(char const infix[])
{
	char e1;
	Stack s;
	Stack output;

	for (int i = 0; i < infix[i] != '\0'; i++) {
		e1 = infix[i];

		switch (e1) {
			case '(': s.push(e1); break;
			case ')': {
				while (s.peek() != '(') {
					output.push(s.pop());
				}
				s.pop();
				break;
			}
			case '-':
			case '+':
			case '*':
			case '/': {
				char e2 = s.peek();
				if (precedence(e1) > precedence(e2)) {
					s.push(e1);
					break;
				}
				else {
					do {
						output.push(s.pop());
						e2 = s.peek();
					} while (precedence(e1) <= precedence(e2));

					s.push(e1); break;
				}
			}

			default: output.push(e1); break;
		}
	}

	while (!s.empty()) {
		output.push(s.pop());
	}

	output.display();
}


double charToDouble(char a)
{
	a = a - 48; //48 is ASCII value of 0. for eg) If a = '5' <-- char, ASCII of 5 is 53. So 53-48 = 5 //
	a = double(a);
	return a;
}


void evaluate_postfix(char postfix[])
{
	DoubleStack evaluate;
	double result = 0;
	double el1 = 0;
	double el2 = 0;

	for (int i = 0; postfix[i] != '\0'; i++) {
		char element = postfix[i];

		switch (element) {
			case '-': {
				el1 = evaluate.pop();
				el2 = evaluate.pop();
				result = el2 - el1;
				evaluate.push(result);
				break;
			}
			case '+': {
				el1 = evaluate.pop();
				el2 = evaluate.pop();
				result = el2 + el1;
				evaluate.push(result);
				break;
			}
			case '*': {
				el1 = evaluate.pop();
				el2 = evaluate.pop();
				result = el2 * el1;
				evaluate.push(result);
				break;
			}
			case '/': {
				el1 = evaluate.pop();
				el2 = evaluate.pop();
				result = el2 / el1;
				evaluate.push(result);
				break;
			}

			default: evaluate.push(charToDouble(element)); break;
		}
	}

	std::cout << result << std::endl;
}


void postfix_infix(char post[])
{
	StringStack s;
	char element[2];
	char operand1[MAX];
	char operand2[MAX];
	char result[MAX];

	//Reads LEFT TO RIGHT
	for (int i = 0; post[i] != '\0'; i++) {
		element[0] = post[i];
		element[1] = '\0';

		//Checks if element[0] is an operator
		if (element[0] == '-' || element[0] == '+' || element[0] == '*' || element[0] == '/' || element[0] == '^') {
			strcpy_s(operand1, s.pop());
			strcpy_s(operand2, s.pop());
			//(operand2 + element + operand1)
			strcpy_s(result, "(");
			strcat_s(result, operand2);
			strcat_s(result, element);
			strcat_s(result, operand1);
			strcat_s(result, ")");
			s.push(result);
		}
		else {
			s.push(element);  //pushes operand to stack
		}
	}

	//prints postfix expression
	for (int i = 0; result[i] != '\0'; i++) {
		std::cout << result[i];
	}
	std::cout << "\n\n";
}

int precedence_prefix(char c)
{
	switch (c) {
		case ')': return 1;
		case '+':
		case '-': return 2;
		case '*':
		case '/': return 3;
		case '^': return 4;
		default: return 0;
	}
	return -1;
}

void infix_prefix(char infix[])
{
	char e1;
	Stack s; //stack which holds the operators
	Stack output; //output stack
	Stack reverseOutput; //stack which contains the reverse of output stack

	//infix expression is read from right to left
	for (int i = strlen(infix) - 1; i >= 0; i--) {
		e1 = infix[i];

		switch (e1) {
			case ')': s.push(e1); break;

			case '(': {
				while (s.peek() != ')') {
					output.push(s.pop());
				}
				s.pop();
				break;
			}

			case '-':

			case '+':

			case '*':

			case '/': {
				char e2 = s.peek();
				if (precedence_prefix(e1) > precedence_prefix(e2)) {
					s.push(e1);
					break;
				}
				else {
					do {
						output.push(s.pop());
						e2 = s.peek();
					} while (precedence_prefix(e1) <= precedence_prefix(e2));

					s.push(e1);
					break;
				}
			}

			default: output.push(e1); break;  //pushes operand to stack
		}
	}
	//pop stack s until it's empty
	while (!s.empty()) {
		output.push(s.pop());
	}

	//now we need to reverse the output, we could have used the now empty stack s too!
	//I'm using a new empty stack reverseOutput for clarity's sake
	while (!output.empty()) {
		reverseOutput.push(output.pop());
	}

	reverseOutput.display();
}


void evaluate_prefix(char prefix[])
{
	DoubleStack evaluate;
	double el1 = 0, el2 = 0, result = 0;

	for (int i = strlen(prefix); i >= 0; i--) {
		char element = prefix[i];

		switch (element) {
			case '-': {
				el1 = evaluate.pop();
				el2 = evaluate.pop();
				result = el1 - el2;
				evaluate.push(result);
				break;
			}
			case '+': {
				el1 = evaluate.pop();
				el2 = evaluate.pop();
				result = el1 + el2;
				evaluate.push(result);
				break;
			}
			case '*': {
				el1 = evaluate.pop();
				el2 = evaluate.pop();
				result = el1 * el2;
				evaluate.push(result);
				break;
			}
			case '/': {
				el1 = evaluate.pop();
				el2 = evaluate.pop();
				result = el1 / el2;
				evaluate.push(result);
				break;
			}
			default: {
				evaluate.push(charToDouble(element));
				break;
			}
				
		}
	}

	std::cout << result << std::endl;
}


int main()
{
	Stack s;

	s.push('a');
	s.push('b');
	s.push('c');
	s.push('d');

	s.pop();
	s.pop();

	s.display();

	convert(3370, 8);

	char a[] = "racecar";
	std::cout << palindrome(a) << '\n';

	char in[] = "3+4*5/6";
	infix_postfix(in);

	char post[] = "231*+9-";
	evaluate_postfix(post);

	char post1[] = "AB+CD+*";
	postfix_infix(post1);

	char pre[] = "(A+B)*(C+D)";
	infix_prefix(pre);

	char pre1[] = "-+7*45+20";
	evaluate_prefix(pre1);
}