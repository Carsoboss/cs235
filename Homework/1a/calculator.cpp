#include <iostream>
#include <string>
using std::cout, std::cin, std::endl;
using std::string;

int main()
{
    cout << "operation: ";
    string operation;
    while (cin >> operation)
    {
        if (operation == "quit")
        {
            return 0;
        }
        else if (operation == "add" || operation == "subtract" || operation == "multiply" || operation == "divide" || operation == "mod")
        {
            int a, b;

            cout << "left operand: ";
            cin >> a;
            cout << "right operand: ";
            cin >> b;

            if (operation == "add")
            {
                cout << a + b << endl;
            }
            else if (operation == "subtract")
            {
                cout << a - b << endl;
            }
            else if (operation == "multiply")
            {
                cout << a * b << endl;
            }
            else if (operation == "divide")
            {
                if (b != 0)
                {
                    cout << a / b << endl;
                }
                else
                {
                    cout << "Error: Division by zero" << endl;
                }
            }
            else if (operation == "mod")
            {
                if (b != 0)
                {
                    cout << a % b << endl;
                }
                else
                {
                    cout << "Error: Modulus by zero" << endl;
                }
            }
        }
        else
        {
            cout << operation << " isn't a valid operation" << endl;
        }
        cout << "operation: ";
    }
}
