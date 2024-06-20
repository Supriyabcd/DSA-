#include<bits/stdc++.h>
using namespace std;

class Stack{
    private:
        stack<int> stack;

    public:
        void Push(int data){
            stack.push(data);
            cout << data << " pushed to the stack\n";
        }

        void Pop(){
            if(stack.empty()){
                cout << "Stack is empty. Cannot pop\n";
            } else {
                int topvalue = stack.top();
                stack.pop();
                cout << topvalue << " popped from the stack\n"; 
            }
        }

        void Top(){
            if(stack.empty()){
                cout << "Stack is empty. No top element \n";
            } else {
                cout << "Top element is:" << stack.top() << endl;
            }
        }

        void printStack(){
            if(stack.empty()){
                cout << "Stack is empty. \n";
            }else{
                std::stack<int> tempStack = stack;
                cout << "Stack elements: " <<endl;
                while(!(tempStack.empty())){
                    cout << tempStack.top() << " " ;
                    tempStack.pop();
                }
                cout << "\n" ;
            }    
        }

};

int main()
{
    Stack S;
    int choice, data;

    do
    {
    cout << "Menu:" <<endl;
    cout << "1. Push \n" ;
    cout << "2. Pop \n" ;
    cout << "3. Top \n" ; 
    cout << "4. Print Stack \n";
    cout << "0. Exit \n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice){
            case 1: { cout << "Enter the element to be pushed: " ;
                    cin >> data;
                    S.Push(data); 
                break; }
            case 2: S.Pop();
                    break;
            case 3: S.Top();
                break;
            case 4: S.printStack();
                break;
            case 0: cout << "Exiting..." << endl;
                break;
            default: cout << "Invalid choice. Please enter a valid integer";
                break;
        }
    } while( choice != 0);

    return 0;
}
