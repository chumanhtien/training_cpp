// Predict the output of following program. Assume that the numbers are stored in 2's complement form.
#include<stdio.h> 
int  main() 
{ 
   unsigned int x = -1; 
   int y = ~0; 
   printf("%ud %d: ", x, y);
   if (x == y) 
      printf("same"); 
   else
      printf("not same"); 
   return 0; 
}