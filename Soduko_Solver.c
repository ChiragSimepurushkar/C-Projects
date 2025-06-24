#include<stdio.h>


int puzzle[9][9]={
    {          },
    {          },
    {          },
    {          },
    {          },
    {          },
    {          },
    {          },
    {          },
  };

void print_puzzle(int puzzle[9][9]);

int main(){


print_puzzle(puzzle);

    return 0;
}

void print_puzzle(int puzzle[9][9]){
      printf("\n\n+-------+-------+-------+");
      for(int row=0;row<9;row++){
        if(row%3==0 &&row!=0){
            printf("\n|-------+-------+-------|");
        }
        printf("\n");
          for(int col=0;col<9;col++){
                if(col%3==0){
                    printf("| ");
                }
                if(puzzle[row][col]!=0){
                printf("%d ",puzzle[row][col]);
                }else{
                    printf("  ");
                }
          }
          
        printf("|");
      }
      printf("\n+-------+-------+-------+");

}


































































































