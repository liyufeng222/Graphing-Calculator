#include "rpn.h"

rpn::rpn(Queue<token*> post_fix)
{
    _post_fix = post_fix;   //assign the postfix to rpn postfix
}

double rpn::eval(double x_value){
    //Queue<token*> post_fix = _post_fix;    //make a copy
    Stack<token*> container;    //use to store number
    double temp_result;    //every calculation result
    token* num_1;   //the first number
    token* num_2;     //the second number
    Queue<token*>::Iterator walker = _post_fix.begin();    //walker in postfix

    while(walker != _post_fix.end()){      //when it not reach end
        switch((*walker)->type()){      //get the type of token
        case 0:
            container.push(new number(x_value));    //get a new number for x
            break;
        case 1:
            container.push(*walker);    //number into container
            break;
        case 4:
            if(static_cast<Operator*>(*walker)->get_prec() == 9){
                //when it is a function
                num_1 = container.pop();   //pop the number
                temp_result = static_cast<Function*>(*walker)->
                        calculate(static_cast<number*>(num_1)->get_num());
                //get the temp result
                container.push(new number(temp_result));
            }else{
                num_2 = container.pop();    //the first one is the right
                num_1 = container.pop();    //pop two number
                temp_result = static_cast<Operator*>(*walker)->
                        calculate(static_cast<number*>(num_1)->get_num(),
                                  static_cast<number*>(num_2)->get_num());
                //get the temp result
                container.push(new number(temp_result));
            }
            break;
        default:
            break;
        }
        walker++;      //next element
    }
    return static_cast<number*>(container.pop())->get_num();
    //the last number in the contain is the final result;
}
