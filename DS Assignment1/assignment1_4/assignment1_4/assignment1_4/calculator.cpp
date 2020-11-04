#include<iostream>
#include<stack>
using namespace std;

int precedence(char op) {
	if (op == '+' || op == '-')
		return 1;
	if (op == '*' || op == '/')
		return 2;
	return 0;
}

int calculate(int a, int b, char op) {
	switch (op) {
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a * b;
	case '/': return a / b;
	}
}

int calculator(string number) {
	int i;

	stack <double> num;
	stack <char> ops;

	for (i = 0; i < number.length(); i++) {
		if (number[i] == ' ')
			continue;
		else if (number[i] == '(') {
			ops.push(number[i]);
		}
		else if (isdigit(number[i])) {
			double val = 0;

			while (i < number.length() &&
				isdigit(number[i]))
			{
				val = (val * 10) + (number[i] - '0');
				i++;
			}

			num.push(val);
		}

		else if (number[i] == ')')
		{
			while (!ops.empty() && ops.top() != '(')
			{
				double val2 = num.top();
				num.pop();

				double val1 = num.top();
				num.pop();

				char op = ops.top();
				ops.pop();

				num.push(calculate(val1, val2, op));
			}
			ops.pop();
		} 
		else
		{
			while (!ops.empty() && precedence(ops.top())
				>= precedence(number[i])) {
				double val2 = num.top();
				num.pop();

				double val1 = num.top();
				num.pop();

				char op = ops.top();
				ops.pop();

				num.push(calculate(val1, val2, op));
			}
			ops.push(number[i]);
		}
	}
	while (!ops.empty()) {
		double val2 = num.top();
		num.pop();

		double val1 = num.top();
		num.pop();

		char op = ops.top();
		ops.pop();

		num.push(calculate(val1, val2, op));
	}
	return num.top();
}

int main() {
	cout << calculator("(1 + ((5 + 8) * (10 + 7.5)))") << "\n";
	cout << calculator("((2 + pow(5.0, 3.0) + log(7.0)) / 3.0)") << "\n";
	cout << calculator("((2 + sqrt(10.0)) * (log(2.0) + 5))") << "\n";

	return 0;
}