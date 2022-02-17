#include "shunting_yard.h"

shunting_yard::shunting_yard(Queue<token*> infix)
{
    _postfix = _get_postfix(infix);    //get the postfix for infix
}


Queue<token*> shunting_yard::postfix(){
    return _postfix;      //return the post fix form
}

Queue<token*> shunting_yard::_get_postfix(Queue<token*> infix){
    Queue<token*> result;       //queue for result
    Stack<token*> operators;      //stack to store operators
    Queue<token*>::Iterator walker = infix.begin();    //walker in infix

    while(walker != infix.end()){      //when it not reach end
        switch((*walker)->type()){      //get the type of token
        case 0:
            result.push(*walker);    //number or varible into result
            break;
        case 1:
            result.push(*walker);    //number or varible into result
            break;
        case 2:
            operators.push(*walker);   // ( in to operator list
            break;
        case 3:
            while(operators.top()->type() != 2){    //when not reach the )
                result.push(operators.pop());   //push the operator in stack
                                                //to result until (
            }
            operators.pop();         //pop the ( out
            break;
        case 4:
            if(operators.empty() || operators.top()->type() == 2){
                operators.push(*walker);   //when empty or top is (
            }else{
                while(!operators.empty() && operators.top()->type() != 2 &&
                      static_cast<Operator*>(*walker)->get_prec() <
                      static_cast<Operator*>(operators.top())->get_prec()){
                    //when then coming operator prec is lower then the top
                    result.push(operators.pop());
                    //pop the top to push into result
                }
                operators.push(*walker);   //add the ooperator into stack
            }
            break;
        default:
            break;
        }
        walker++;      //next element
    }
    while(!operators.empty()){
        result.push(operators.pop());
        //at the end, push all operator back to result
    }
    return result;
}
