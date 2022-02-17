#include "queue_test.h"

void queue_demo_int(){
    cout << "Initialize a queue list first."<<endl;
    Queue<int> queue;
    cout << "Print the queue."<<endl;
    cout << "Expect: H->|||  (empty)"<<endl;
    cout << queue;

    cout <<"Test for empty():"<<endl;
    cout <<"Expect: empty is true"<<endl;
    if(queue.empty()){
        cout << "ture"<<endl;
    }else{
        cout << "false"<<endl;
    }

    cout << "Test for push:"<<endl;
    cout << "Push 88 45 69 34 22 into the queue."<<endl;
    queue.push(88);
    queue.push(45);
    queue.push(69);
    queue.push(34);
    queue.push(22);
    cout <<"Expect: 88-45-69-34-22"<<endl;
    cout << queue;

    cout << "Test for pop:"<<endl;
    cout << "Pop once:"<<endl;
    queue.pop();
    cout << "Expect: 45-69-34-22"<<endl;
    cout << queue;

    cout << "Psuh a new number in:"<<endl;
    cout << "Push 55 in:"<<endl;
    queue.push(55);
    cout << "Expect: 45-69-34-22-55"<<endl;
    cout << queue;

    cout << "Test front():"<<endl;
    cout << "Expect: 45"<<endl;
    cout << "queue front: " << queue.front()<<endl;

    cout << "Pop all the item out one by one."<<endl;
    queue.pop();
    cout <<queue;
    queue.pop();
    cout <<queue;
    queue.pop();
    cout <<queue;
    queue.pop();
    cout <<queue;
    queue.pop();
    cout <<queue;

    /*cout << "Pop again, It should be assert, because the queue empty.\n";
    queue.pop();
    cout <<queue;*/
}

void queue_demo_char(){
    cout << "Initialize a queue list first."<<endl;
    Queue<char> queue;
    cout << "Print the queue."<<endl;
    cout << "Expect: H->|||  (empty)"<<endl;
    cout << queue;

    cout <<"Test for empty():"<<endl;
    cout <<"Expect: empty is true"<<endl;
    if(queue.empty()){
        cout << "ture"<<endl;
    }else{
        cout << "false"<<endl;
    }

    cout << "Test for push:"<<endl;
    cout << "Push I T G H J into the queue."<<endl;
    queue.push('I');
    queue.push('T');
    queue.push('G');
    queue.push('H');
    queue.push('J');
    cout <<"Expect: I-T-G-H-J"<<endl;
    cout << queue;

    cout << "Test for pop:"<<endl;
    cout << "Pop twice:"<<endl;
    queue.pop();
    queue.pop();
    cout << "Expect: G-H-J"<<endl;
    cout << queue;

    cout << "Psuh a new char in:"<<endl;
    cout << "Push B in:"<<endl;
    queue.push('B');
    cout << "Expect: G-H-J-B"<<endl;
    cout << queue;

    cout << "Test front():"<<endl;
    cout << "Expect: G"<<endl;
    cout << "queue front: " << queue.front()<<endl;
}

void queue_demo_int_copy(){
    cout << "Initialize a queue list first."<<endl;
    Queue<int> queue;
    cout << "Push 88 45 69 34 22 into the queue."<<endl;
    queue.push(88);
    queue.push(45);
    queue.push(69);
    queue.push(34);
    queue.push(22);
    cout <<"Expect: 88-45-69-34-22"<<endl;
    cout << queue;

    cout <<endl<<"Test copy CORT: copy_queue(queue)"<<endl;
    Queue<int> copy_queue(queue);
    cout <<"Expect: 88-45-69-34-22"<<endl;
    cout << "copy_queue: " << copy_queue;

    cout << "Then pop the copy_queue, the queue should not change."<<endl;
    copy_queue.pop();
    cout <<"Expect: 88-45-69-34-22"<<endl;
    cout << "queue: " << queue;
    cout <<"Expect: 45-69-34-22    (copy_queue)"<<endl;
    cout << "copy_queue: " << copy_queue;

    cout <<endl<<"Test the = copy operator: queue2 = queue"<<endl;
    cout << "Initialize the queue2 list first."<<endl;
    Queue<int> queue2;
    cout << "Push 10 into the queue2."<<endl;
    queue2.push(10);
    cout <<"Expect: 10"<<endl;
    cout << "queue2: " << queue2;
    cout << "Copy the queue to queue2:  (queue2 = queue)"<<endl;
    queue2 = queue;
    cout <<"Expect: 88-45-69-34-22"<<endl;
    cout << "queue2: " << queue2;
    cout << "Pop the queue2 twice. The queue should not change."<<endl;
    queue2.pop();
    queue2.pop();
    cout <<"Expect: 88-45-69-34-22"<<endl;
    cout << "queue: " << queue;
    cout <<"Expect: 69-34-22    (queue2)"<<endl;
    cout << "queue2: " << queue2;

}

void queue_demo_general(){
    cout << "===========================Queue Int=========================\n";
    queue_demo_int();
    cout << "=========================Queue Char=========================\n";
    queue_demo_char();
    cout << "=========================Queue copy=========================\n";
    queue_demo_int_copy();
    cout << "=========================End Queue=========================\n";
}
