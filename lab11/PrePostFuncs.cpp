/*==================================================================================
  Luisel A. Muller Rodriguez
  #S01394043
  11/17/2021
  This file contains function definitions used to convert from infix
  to postfix, infix to prefix and evaluate a postfix expression. It
  also contains "helper" functions like eprint(), isOperator(), 
  chckpr(), and solve() which help with printing outputs, checking if a character
  is an operator, checking an operators presedence and doing operations
  when evaluating a postfix expression. More details about these functions
  are available in the comments in this file or PrePostDefs.h
 ==================================================================================*/
#include <iostream>
#include <string>
#include <stack>
#include "PrePostDefs.h"

using namespace std;

/***************************************************************
* Function that asks the user to input an expression and then
* converts it to postfix using the stack
* @param:
*	   string inf -> The infix expression entered by the user.
* 
* Tested with expression: A-B+(M^N)*(O+P)-Q/R^S*T+Z
* Output: AB-MN^OP+*+QRS^/T*-Z+
***************************************************************/
string infpos(string inf)
{
    //Creating the stack that will be used to store operators
    stack<char> stackp;
   
    string post = "";   //Used to store the result (the converted expression).
   
    //Iterates through the infix expression.
    for (int i = 0; i < (int)inf.length(); i++)
    {
        //If the character is a space then it continues to the next one
        if (inf[i] == ' ') continue;

        //If the character is an operator we check if we push into the stack or pop from it.
        if (isOperator(inf[i]))
        {
            /**********************************************************************************************
            * If the stack is empty or the character at the top of the stack is an opening parenthesis ')'
            * the operator will be pushed into the stack without checking precedence
            **********************************************************************************************/
            if (stackp.empty() || stackp.top() == '(')
            {
                stackp.push(inf[i]);
            }
            else
            {
                /**********************************************************************************************
                * While the stack isn't empty and the precedence of the infix expressions character currently 
                * selected is less or equal to the precedence of the character that's at the top of the stack
                * the character at the top of the stack is inserted into the 'post' string. After inserting
                * the top of the stack into the string we then pop that character from the stack.
                * 
                * When the loop is exited or when the presedence is not less or equal then the character 
                * that is currently selected from the infix expression is pushed into the stack.
                *********************************************************************************************/
                while (!stackp.empty() && chckpr(inf[i]) <= chckpr(stackp.top()))
                {
                    post += stackp.top();
                    stackp.pop();
                }
                stackp.push(inf[i]);
            }
        }
        else if (inf[i] == '(')
        {
            //If the character is an opening parenthesis then the character is pushed into the stack.
            stackp.push(inf[i]);
        }
        else if (inf[i] == ')')
        {
            /******************************************************************************************
            * If the character is the closing parenthesis, then while the top of the stack isn't the
            * opening parenthesis and the stack isn't empty, the operators in the stack will be added
            * to the 'post' string and the character will be popped from the stack each time.
            * 
            * When the loop is exited the opening parenthesis is popped from the stack.
            *****************************************************************************************/
            while (stackp.top() != '(' && !stackp.empty())
            {
                post += stackp.top();
                stackp.pop();
            }
            stackp.pop();
        }
        else
        {
            //If the character is not an operator, we assume it's an operand and directly insert it to the string.
            post.insert(post.end(), inf[i]);
        }
    }

    /***************************************************************************************************************
    * After we iterate through the infix expression there will still be operators inside of the stack,
    * so after iterating, while the stack isn't empty every operator left in the stack is inserted into the string
    * and then popped out of the stack.
    ***************************************************************************************************************/
    while (!stackp.empty())
    {
        post += stackp.top();
        stackp.pop();
    }
   
    //Returns the converted postfix expression.
    return post;
}

/***************************************************************
* Function that asks the user to input an expression and then
* converts it to prefix by reversing the expression, converting
* the reversed expression to postfix and then reversing that
* string.
* @param:
*	   string inf -> The infix expression entered by the user.
*
* Tested with expression: A-B+(M^N)*(O+P)-Q/R^S*T+Z
* Output: -A+B-*^MN+OP+/Q*^RSTZ
***************************************************************/
string infpre(string inf)
{
    /***************************************************************************************
    * Uses the eprint() function to reverse the infix expression, then that reversed string
    * is passed into the infpos() function to convert it to postfix, after converting it
    * the postfix expression is assigned to the 'prefix' string variable
    ***************************************************************************************/
    string prefix = infpos(eprint(inf, 1));

    //Returns the reverse of the prefix variable, finally converting the expression to prefix
    return eprint(prefix, 1);
}

/*************************************************************
* Function that evaluates a postfix expression.
* @param:
*	   string pos -> The postfix expression to be evaluated.
* 
* Tested with expressions: 2 20 * 2 / 3 4 + 3 2 ^ * + 6 - 15 +
* and 78 30 0.5 28 8 + * - 6 / +
* Output: first one is equal to 92
*         and the second one to 80
*************************************************************/
double evalpos(string pos)
{
    //Creating the stack.
    stack<double> stacke;

    /***************************************
    * Variables:
    *     Integers:
    *         o1  -> Stores an operand.
    *         o2  -> Stores anoter operand.
    *     Strings:
    *         operand -> If there is an
    *                    operand with 2
    *                    digits it's stored 
    *                    in this variable.
    ***************************************/
    double o1, o2;
    string operand;
    
    //Iterating through the postfix expression.
    for (int i = 0; i < (int)pos.length(); i++)
    {
        if (pos[i] == ' ') continue;
        /********************************************************************************
        * If the current character is an operator then 'o1' is assigned the 
        * element at the top of the stack and then it's popped, 'o2' is assgined
        * the next element in the stack and then it's popped. After the result of
        * o2 (operator) o1 is pushed to the stack.
        * 
        * (operator) = the operator that was found while iterating throught the string.
        ********************************************************************************/
        if (isOperator(pos[i]))
        {
 
            o1 = stacke.top();
            stacke.pop();

            o2 = stacke.top();
            stacke.pop();

            stacke.push(solve(pos[i], o1, o2));
        }
        else
        {
            //The character is added to operand, this helps when an operand is 2 digits or more
            operand += pos[i];

            if (pos[i + 1] == ' ')
            {
                /*************************************************************************************************
                * Here we're converting a character to integer and pushing it to the stack, so we
                * need to subtract '0' to convert the ASCII character to the numeric values.
                * Here we are basically subtracting the character to the character 0, which
                * has a value of 48 ('0' == 48). ex '1' - 48 == 1 since '1' == 49.
                *
                * More information on how this works is available at:
                * https://stackoverflow.com/questions/3195028/please-explain-what-this-code-is-doing-somechar-48
                **************************************************************************************************/
                stacke.push(stod(operand));   //stod(operand) is converting operand from string to double
                operand = " ";                //Setting operand to to be empty
            }
        }
    }
    //Returning the result.
    return stacke.top();
}

/** "HELPER" FUNCTIONS **/

/******************************************************
* Function used to check the presedence of an operator
* with the highest presedence being 3 and the lowest 0,
* @param:
*      char o -> The operator to be checked.
******************************************************/
int chckpr(char o) 
{
    return o == '^' ? 3 : o == '*' || o == '/' ? 2 : o == '+' || o == '-' ? 1 : 0;
}

/******************************************************
* Function used to check if a character is an operator.
* @param:
*	   char o -> The operator to be checked.
******************************************************/
bool isOperator(char o)
{
    return  o == '^' || o == '*' || o == '/' || o == '+' || o == '-' ? true : false;
}

/*********************************************************************
* Function used to print a string either normally or reversed,
* for the string to be reversed an int value of 1 must be used
* as 's'.
* @param:
*      string e -> The string to be printed or reversed.
*	   int s	-> Used to decide whether to reverse the string or
*				   not, if its value is 1 it will be reversed,
*				   otherwise the string will be kept the same.
********************************************************************/
string eprint(string e, int s)
{
    //Variable used to store the results.
    string r;

    //If 's' is 1 then the string is inverted
    if (s == 1)
    {
        for (int i = e.length() - 1; i >= 0; i--)
        {
            /**************************************************
            * This makes sure that when the string is reversed
            * the parenthesis are still facing the correct way
            **************************************************/
            if (e[i] == '(')
                r += ')';
            else if (e[i] == ')')
                r += '(';
            else
                r += e[i];
        }
    }
    else //The string is not reversed.
    {
        for (int i = 0; i < (int)e.length(); i++)
            r += e[i];
    }
    //Returns the string.
    return r;
}

/****************************************************************
* Helps solve operations when evaluating a postfix expression.
* @params:
*      o1 -> An operand.
*      o2 -> The other operand.
*      op -> The operator used in the operation.
* 
* Depending on the operator it will return o2 (operator) o1
* with (operator) being the operator that is selected at the
* time. The result is stored in r and then returned. 
* Else it will return 0.
****************************************************************/
double solve(char op, double o1, double o2)
{
    double r;
    switch (op)
    {
        case '+':
            r = o2 + o1;
            break;
        case '-':
            r = o2 - o1;
            break;
        case '*':
            r = o2 * o1;
            break;
        case '/':
            r = o2 / o1;
            break;
        case '^':
            r = (double)pow(o2, o1);
            break;
        default:
            r = 0;
    }
    return r;
}