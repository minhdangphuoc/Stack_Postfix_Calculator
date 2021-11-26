#include <iostream>
#include "Stack.hpp"

void introduction();
void instructions();
char get_command();
bool do_command(char, Stack &);

int main()
/*
Post: The program has executed simple arithmetic
      commands entered by the user.
Uses: The class Stack and the functions
      introduction, instructions, do_command, and get_command.
*/

{
   Stack stored_numbers;
   introduction();
   instructions();
   while (do_command(get_command(), stored_numbers));
}

void introduction()
{
   std::cout << "PostFix calculator" << std::endl;
}

void instructions()
{
   std::cout << "Please enter a valid command:"   << std::endl
              << "[?]push to stack   [=]print top" << std::endl
              << "[+] [-] [*] [/]   are arithmetic operations" << std::endl
              << "[x] exchange two tops" << std::endl
              << "[s] sum of all numbers" << std::endl
              << "[Q]uit." << std::endl;
}

char get_command()
{
   char command;
   bool waiting = true;
   std::cout << "Select command and press <Enter>:";

   while (waiting) {
      std::cin >> command;
      command = tolower(command);
      if (command == '?' || command == '=' || command == '+' ||
          command == '-' || command == '*' || command == '/' ||
          command == 'q' || command == 'x' || command == 's') waiting = false;


      else {
         std::cout << "Please enter a valid command:"   << std::endl
              << "[?]push to stack   [=]print top" << std::endl
              << "[+] [-] [*] [/]   are arithmetic operations" << std::endl
              << "[x] exchange two tops" << std::endl
              << "[s] sum of all numbers" << std::endl
              << "[Q]uit." << std::endl;
      }
   }
   return command;
}


bool do_command(char command, Stack &numbers)
/*
Pre:  The first parameter specifies a valid calculator command.
Post: The command specified by the first parameter
      has been applied to the Stack of numbers given by the second parameter.
      A result of true is returned unless command == 'q'.
Uses: The class Stack.
*/

{
   double p, q;
   switch (command) {
   case '?':
      std::cout << "Enter a real number: " << std::flush;
      std::cin >> p;
      if (numbers.push(p) == overflow)
         std::cout << "Warning: Stack full, lost number" << std::endl;
      break;

   case '=':
      if (numbers.top(p) == underflow)
         std::cout << "Stack empty" << std::endl;
      else
         std::cout << p << std::endl;
      break;

   case '+':
      if (numbers.top(p) == underflow)
         std::cout << "Stack empty" << std::endl;
      else {
         numbers.pop();
         if (numbers.top(q) == underflow) {
            std::cout << "Stack has just one entry" << std::endl;
            numbers.push(p);
         }

         else {
            numbers.pop();
            if (numbers.push(q + p) == overflow)
               std::cout << "Warning: Stack full, lost result" << std::endl;
         }
      }
      break;
   
   //   Add options for further user commands.
   case '-':
      if (numbers.top(p) == underflow)
         std::cout << "Stack empty" << std::endl;
      else {
         numbers.pop();
         if (numbers.top(q) == underflow) {
            std::cout << "Stack has just one entry" << std::endl;
            numbers.push(p);
         }

         else {
            numbers.pop();
            if (numbers.push(q - p) == overflow)
               std::cout << "Warning: Stack full, lost result" << std::endl;
         }
      }
      break;
   
   case '*':
      if (numbers.top(p) == underflow)
         std::cout << "Stack empty" << std::endl;
      else {
         numbers.pop();
         if (numbers.top(q) == underflow) {
            std::cout << "Stack has just one entry" << std::endl;
            numbers.push(p);
         }

         else {
            numbers.pop();
            if (numbers.push(q * p) == overflow)
               std::cout << "Warning: Stack full, lost result" << std::endl;
         }
      }
      break;
   
   case '/':
      if (numbers.top(p) == underflow)
         std::cout << "Stack empty" << std::endl;
      else {
         numbers.pop();
         if (numbers.top(q) == underflow) {
            std::cout << "Stack has just one entry" << std::endl;
            numbers.push(p);
         }

         else {
            numbers.pop();
            if (numbers.push(q / p) == overflow)
               std::cout << "Warning: Stack full, lost result" << std::endl;
         }
      }
      break;

   case 'x':
      if (numbers.top(p) == underflow)
         std::cout << "Stack empty" << std::endl;
      else {
         numbers.pop();
         if (numbers.top(q) == underflow) {
            std::cout << "Stack has just one entry" << std::endl;
            numbers.push(p);
         }
         else {
            numbers.pop();
            numbers.push(p);
            numbers.push(q);
         }
      }
      break;

      case 's':
      while (true){
         if (numbers.top(p) == underflow)
            std::cout << "Stack empty" << std::endl;
         else {
            numbers.pop();
            if (numbers.top(q) == underflow) {
               // std::cout << "Stack has just one entry" << std::endl;
               numbers.push(p);
               break; 
            }
            else {
               numbers.pop();
               if (numbers.push(q + p) == overflow)
               std::cout << "Warning: Stack full, lost result" << std::endl;
            }
         }
      }
      break;

    case 'q':
      std::cout << "Calculation finished.\n";
      return false;
   }
   return true;
}