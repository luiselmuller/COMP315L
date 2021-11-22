#ifndef PrePostDefs_H
#define PrePostDefs_H

/*=====================================================================
  Luisel A. Muller Rodriguez
  #S01394043
  11/17/2021
  This file contains function declarations for infix to postfix/prefix
  conversion and evaluation using a stack.
 =====================================================================*/
 
/***************************************************************
* Function that asks the user to input an expression and then
* converts it to postfix using the stack
* @param:
*	   string inf -> The infix expression entered by the user.
* 
* Returns the converted postfix expression as a string.
***************************************************************/
std::string infpos(std::string inf);

/***************************************************************
* Function that asks the user to input an expression and then
* converts it to prefix by reversing the expression, converting
* the reversed expression to postfix and then reversing that 
* string.
* @param:
*	   string inf -> The infix expression entered by the user.
* 
* Returns the converted prefix expression as a string.
***************************************************************/
std::string infpre(std::string inf);

/*************************************************************
* Function that evaluates a postfix expression.
* @param:
*	   string pos -> The postfix expression to be evaluated.
* 
* Returns the result of the evaluation as a string.
*************************************************************/
double evalpos(std::string pos);

/******************************************************
* Function used to check the presedence of an operator
* with the highest presedence being 3 and the lowest 0,
* @param:
*      char o -> The operator to be checked.
* 
* Returns the presedence as an integer value.
******************************************************/
int chckpr(char o);

/******************************************************
* Function used to check if a character is an operator.
* @param:
*	   char o -> The operator to be checked.
* 
* Returns true or false, true meaning that o is an 
* operator and false means it's not.
******************************************************/
bool isOperator(char o);

/*********************************************************************
* Function used to print a string either normally or reversed,
* for the string to be reversed an int value of 1 must be used
* as 's'.
* @param:
*      string e -> The string to be printed or reversed.
*	   int s	-> Used to decide whether to reverse the string or
*				   not, if its value is 1 it will be reversed,
*				   otherwise the string will be kept the same.
* 
* Returns a string, depending on the value of the integer s
* the string will be reversed. If 's' is equal to 1 then the string
* will be reversed, if it is any other number then the string
* will not be reversed.
********************************************************************/
std::string eprint(std::string e, int s);

/****************************************************************
* Helps solve operations when evaluating a postfix expression.
* @params:
*      o1 -> An operand.
*      o2 -> The other operand.
*      op -> The operator used in the operation.
*
* Returns the result as an integer value.
****************************************************************/
double solve(char op, double o1, double o2);

#endif