

//Used Stack DS in this question.

/*Evaluate the expression. Return an integer that represents the value of the expression. The valid operators are '+', '-', '*', and '/'

Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22

*/



class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        for(string x:tokens)
        {
            if(x=="+")
            {
                int a = s.top();//2
                s.pop();
                int b = s.top();//3
              //a+b=>2+3=>5
                s.pop();
                s.push(a+b);
            }
            else if(x=="-")
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b-a);
            }
            else if(x=="*")
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a*b);
            }
            else if(x=="/")
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b/a);
            }
            else s.push(stoi(x));
        }
        return s.top();
        }
};
