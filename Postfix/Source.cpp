#include <iostream>
#include "Header.h"
using namespace std;

bool checkOperand(char e){
	if ((e <= 'z' && e >= 'a') || (e <= 'Z' && e >= 'A') || (e <= '9' && e >= '0'))
		return true;
	else
		return false;
}

bool checkOperator(char e){
	if (e == '#' || e == '*' || e == '/' || e == '%' || e == '+' || e == '-' || e == '!')
		return true;
	else
		return false;
}

void setPriority(char e, int* priority, int i){
	if (e == '(')
		priority[i] = 4;
	else if (e == '#' || e == '!')
		priority[i] = 3;
	else if (e == '*' || e == '/' || e == '%')
		priority[i] = 2;
	else if (e == '+' || e == '-')
		priority[i] = 1;
}

int getInteger(char* postfix, int size){
	
	int var, j = 8;
	char* temp = new char[10];
	for (int i = 0; i < 9; i++)
		temp[i] = '0';
	temp[9] = '\0';

	for (int i = size - 1; i >= 0; i--){
		if (!(postfix[i] >= '0' && postfix[i] <= '9'))
			break;
		temp[j] = postfix[i];
		j--;
	}
	var = atoi(temp);
	delete[]temp;
	temp = NULL;

	return var;
}

int performOperation(int operator1, int operator2, char operand){
	int ans = 0;

	if (operand == '+')
		ans = operator1 + operator2;
	else if (operand == '-')
		ans = operator1 - operator2;
	else if (operand == '*')
		ans = operator1 * operator2;
	else if (operand == '/')
		ans = operator1 / operator2;
	else if (operand == '%')
		ans = operator1 % operator2;

	return ans;
}

void Postfix_convert(char* exp, char* postfix, Stack<char> &stk, int length){

	int* priority_number = new int[length];
	int j = 0, size = 0;
	char ch, last_operator = '&', last_operand = '&';

	for (int i = 0; i < length; i++)
		priority_number[i] = 0;

	for (int i = 0; i < length; i++)
	{
		size = stk.getSize();
		if (checkOperand(exp[i])){               //Pushing Operand in Postfix
			postfix[j] = exp[i];
			j++;
			last_operator = ' ';
			last_operand = exp[i];
		}
		else if (exp[i] == ')'){                 //Poping all operators till (
			stk.pop(ch);

			while (ch != '('){
				postfix[j] = ch;
				j++;
				stk.pop(ch);
			}
			last_operator = ' ';
			last_operand = ' ';
		}
		else {                                   //Pushing Operators in Stack
			if (exp[i] != '(' && last_operator == ' ' && last_operand != ' '){
				postfix[j] = ' ';
				j++;
			}
			setPriority(exp[i], priority_number, size);

			for (int k = size - 1; k >= 0; k--){

				if (priority_number[size] > priority_number[k]){

					if ((k + 1) != size){
						priority_number[k + 1] = priority_number[size];
						priority_number[size] = 0;
					}

					stk.push(exp[i]);

					if (exp[i] == '(')
						priority_number[size] = 0;

					break;
				}
				else{
					stk.pop(ch);
					postfix[j] = ch;
					j++;
					priority_number[k] = 0;
				}
			}
			if (stk.isEmpty()){
				setPriority(exp[i], priority_number, 0);
				stk.push(exp[i]);
				if (exp[i] == '(')
					priority_number[0] = 0;
			}
			last_operator = exp[i];
			last_operand = ' ';
		}
	}
	size = stk.getSize();
	for (int i = 0; i < size; i++)                     //Poping all Operators
	{
		stk.pop(ch);
		if (ch != '('){
			postfix[j] = ch;
			j++;
		}
	}
	postfix[j] = '\0';
	return;
}

int fact(int x){
	for (int k = x - 1; k > 0; k--)
		x = x * k;
	return x;
}

int Postfix_evaluate(Stack<int>& stk, char* postfix){
	
	int length = strlen(postfix);
	int k = 0, operator1, operator2, ans;

	for (int i = 0; i < length; i++){

		if (postfix[i] == ' ')                           //Check Operand
			stk.push(getInteger(postfix, i));            

		else if (checkOperator(postfix[i])){             //Check Operator
		
			if ((!checkOperator(postfix[i - 1]) && postfix[i - 1] != ' '))
				stk.push(getInteger(postfix, i));

			if (postfix[i] == '#'){                    //Uniary - Operator
				stk.pop(operator1);
				stk.push(-operator1);
			}
			else if (postfix[i] == '!'){               //Factorial operator
				stk.pop(operator1);
				stk.push(fact(operator1));
			}
			else{                                      //Other Operators
				stk.pop(operator2);                    //Poping Operands
				stk.pop(operator1);

				stk.push(performOperation(operator1, operator2, postfix[i]));        //Pushing Result
			}
		}
	}
	stk.pop(ans);
	return ans;
}

int main(){

	Stack<char> stk1;
	Stack<int>	stk2;

	char* exp = new char[100];
	cout << "\nEnter Expression:  ";
	cin.getline(exp, 100, '\n');

	for (int i = 0; i < strlen(exp); i++){
		if ((!checkOperand(exp[i])) && (!checkOperator(exp[i])) && exp[i] != '(' && exp[i] != ')'){
			cout << "Invalid Input ... Please Enter Again (no spaces): ";
			cin >> exp;
		}
	}

	int length = strlen(exp);
	char* postfix = new char[length + 1];
	
	Postfix_convert(exp, postfix, stk1, length);                //Convert Infix to Postfix by Stack stk1
	
	cout << "\nExpression in Postfix:  " << postfix << endl;    

	cout << "\nExpression Result: " << Postfix_evaluate(stk2, postfix) << endl;        //Evaluating Postfix using Stack stk2

	return 0;
}