// Copyright 2021 NNTU-CS
#include <string>
#include "tstack.h"
#include <stack>
int priority(char n) {
    if ((n == '+') || (n == '-'))
      return 2;
    else 
      if ((n == '*') || (n == '/'))
        return 3;
    else
        return 0;
}

std::string infx2pstfx(std::string inf) {
  std::stack<char> stack;
  std::string str;
  for (int i = 0; i < inf.length(); i++) {
    if ((inf[i] >= '0') && (inf[i] <= '9')) {
      str = str + inf[i];
      str = str + " ";
    } 
    else 
      if ((stack.empty()) || (inf[i] == '(')
                 || (priority(inf[i] > priority(stack.top())))) {
        stack.push(inf[i]);
      } 
    else 
      if (inf[i] == ')') {
        while (stack.top() != '(') {
          str = str + stack.top();
          str = str + ' ';
          stack.pop();
        }
        stack.pop();
      } 
    else {
      while (!stack.empty() && (priority(stack.top()) >= priority(inf[i]))) {
        str = str + stack.top();
        str = str + ' ';
        stack.pop();
      }
      stack.push(inf[i]);
    }
  }
  if (!stack.empty()) {
    while (!stack.empty()) {
      str = str + stack.top();
      str = str + ' ';
      stack.pop();
    }
  }
  str.pop_back();
  return str;
  return std::string("");
}

int eval(std::string pst) {
  std::stack<char> stack;
  int resultat;
  for (int i = 0; i < pst.length(); i++) {
    if ((pst[i] >= '0') && (pst[i] <= '9')) {
      stack.push(pst[i] - '0');
    } 
    else 
      if (pst[i] != ' ') {
        int y = stack.top();
        stack.pop();
        int x = stack.top();
        stack.pop();
        if (pst[i] == '+')
          stack.push(x + y);
        if (pst[i] == '-')
          stack.push(x - y);
        if (pst[i] == '*')
          stack.push(x * y);
        if (pst[i] == '/')
          stack.push(x / y);
      }
  }
  resultat = stack.top();
  return resultat;
  return 0;
}
