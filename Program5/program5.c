#include<stdio.h>
#include<string.h>
#include<ctype.h>

char input[10];
int i,error;
void E();
void T();
void Edash();
void Tdash();
void F();
int main()
{
  i=0;
  error=0;
  printf("\n Enter the arithmetic expression:");
  gets(input);
  E();
  if(strlen(input)==i&&error==0)
      printf("\nAccepted...!!!\n");
  else
      printf("\n Rejected..!!\n");
}
void E()
{
  T();
  Edash();
}
void Edash()
{
  if(input[i]=='+')
  {
    i++;
    T();
    Edash();
  }
}
void T()
{
  F();
  Tdash();
}
void Tdash()
{
  if(input[i]=='*')
  {
    i++;
    F();
    Tdash();
  }
}
void F()
{
  if(isalnum(input[i]))i++;
  else if(input[i]=='(')
  {
    i++;
    E();
    if(input[i]==')')
      i++;
    else
        error=1;
  }
  else
      error=1;
} 
