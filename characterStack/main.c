#include <stdio.h>
#include "Cstack.h"
int main()
{
char bs[] = {"{(}"};
int d = isBalanced(bs);
if (d){
    printf("The stack is balanced\n");
}
else{
    printf("The stack is not balanced\n");
}
return 0;
}