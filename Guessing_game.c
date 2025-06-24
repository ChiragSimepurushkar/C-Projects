#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(){
srand(time(NULL));//seed for current time
printf("Welcome to the world of guessing game\n");

int random, guess,no_guess=0;
random=rand()%100+1;  //  % 100 (0-99)+1 =0-100

do{
printf("Enter your Guess Between(1-100): ");
scanf("%d",&guess);
no_guess++;

if(guess>random){
printf("Guess a smaller number.\n");
}
else if(guess<random){
printf("Guess a Larger number.\n");
}

else//guess=rand
printf("Congratulation!! You Guessed the correct Number in %d attempes.\n",no_guess);

}while(guess!=random);
printf("Bye Bye, Thanks for playing.\n");
printf("Developed by: Chirag");
    return 0;
}