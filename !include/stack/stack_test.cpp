#include "stack_test.h"

void stack_demo_int(){
    cout << "Initialize a Stack list first."<<endl;
    Stack<int> stack;
    cout << "Print the Stack."<<endl;
    cout << "Expect: H->|||  (empty)"<<endl;
    cout << stack;

    cout <<"Test for empty():"<<endl;
    cout <<"Expect: empty is true"<<endl;
    if(stack.empty()){
        cout << "ture"<<endl;
    }else{
        cout << "false"<<endl;
    }

    cout << "Test for push:"<<endl;
    cout << "Push 88 45 69 34 22 into the Stack."<<endl;
    stack.push(88);
    stack.push(45);
    stack.push(69);
    stack.push(34);
    stack.push(22);
    cout <<"Expect: 22-34-69-45-88"<<endl;
    cout << stack;

    cout << "Test for pop:"<<endl;
    cout << "Pop once:"<<endl;
    stack.pop();
    cout << "Expect: 34-69-45-88"<<endl;
    cout << stack;

    cout << "Psuh a new number in:"<<endl;
    cout << "Push 55 in:"<<endl;
    stack.push(55);
    cout << "Expect: 55-34-69-45-88"<<endl;
    cout << stack;

    cout << "Test top():"<<endl;
    cout << "Expect: 55"<<endl;
    cout << "Stack top: " << stack.top()<<endl;

    cout << "Pop all the item out one by one."<<endl;
    stack.pop();
    cout <<stack;
    stack.pop();
    cout <<stack;
    stack.pop();
    cout <<stack;
    stack.pop();
    cout <<stack;
    stack.pop();
    cout <<stack;

}
void stack_demo_int_copy(){
    cout << "Initialize a stack list first."<<endl;
    Stack<int> stack;
    cout << "Push 88 45 69 34 22 into the stack."<<endl;
    stack.push(88);
    stack.push(45);
    stack.push(69);
    stack.push(34);
    stack.push(22);
    cout <<"Expect: 22-34-69-45-88"<<endl;
    cout << stack;

    cout <<endl<<"Test copy CORT: copy_stack(stack)"<<endl;
    Stack<int> copy_stack(stack);
    cout <<"Expect: 22-34-69-45-88"<<endl;
    cout << "copy_stack: " << copy_stack;

    cout << "Then pop the copy_stack, the stack should not change."<<endl;
    copy_stack.pop();
    cout <<"Expect: 22-34-69-45-88"<<endl;
    cout << "stack: " << stack;
    cout <<"Expect: 34-69-45-88    (copy_stack)"<<endl;
    cout << "copy_stack: " << copy_stack;

    cout <<endl<<"Test the = copy operator: stack2 = stack"<<endl;
    cout << "Initialize the stack2 list first."<<endl;
    Stack<int> stack2;
    cout << "Push 10 into the stack2."<<endl;
    stack2.push(10);
    cout <<"Expect: 10"<<endl;
    cout << "stack2: " << stack2;
    cout << "Copy the stack to stack2:  (stack2 = stack)"<<endl;
    stack2 = stack;
    cout <<"Expect: 22-34-69-45-88"<<endl;
    cout << "stack2: " << stack2;
    cout << "Pop the stack2 twice. The stack should not change."<<endl;
    stack2.pop();
    stack2.pop();
    cout <<"Expect: 22-34-69-45-88"<<endl;
    cout << "stack: " << stack;
    cout <<"Expect: 69-45-88    (stack2)"<<endl;
    cout << "stack2: " << stack2;

}

void stack_demo_general(){
    cout << "===========================Stack Int=========================\n";
    stack_demo_int();
    cout << "=========================Stack copy=========================\n";
    stack_demo_int_copy();
    cout << "=========================End Stack=========================\n";
}
