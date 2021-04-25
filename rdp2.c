#include <stdio.h>
#include <string.h>
char inp[10];
char l;
int i, error;
void E();
void T();
void E1(); //corresponds to E'
void F();
void T1(); //corresponds to T'
void main()
{
    i = 0;
    error = 0;
    printf("Enter the expression :  "); 
    gets(inp);
    E();
    int length=strlen(inp);
    if (error == 0)
        printf("Parse Succesful\n");
    else
        printf("Parse Failed\n");
}
void E()
{
    T();
    E1();
}
void T()
{
    F();
    T1();
}
void E1()
{
    if (inp[i] == '+')
    {
        i++;
        T();
        E1();
    }
}
void T1()
{
    if (inp[i] == '*')
    {
        i++;
        F();
        T1();
    }
}
void F()
{
    if (inp[i] == '(')
    {
        i++;
        E();
        if (inp[i] == ')')
        {
            i++;
        }
        else
        {
            error=1;
        }
        
    }
    else if (inp[i]== 'i'&&inp[i+1]== 'd')
        i=i+2;
    else
    {
        printf("Error: ");
        error = 1;
    }
}