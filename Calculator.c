#include<stdio.h>
#include<math.h>
void Printmenu(){
    printf("--Welcome to simple Calculator--\n");
printf("Choose one of the following options:\n");
printf("1) Add\n");
printf("2) Subtract\n");
printf("3) Multiply\n");
printf("4) Divide\n");
printf("5) Modulus(Remainder)\n");
printf("6) power\n");
printf("7) Exit\n");
}

float divide(float a, float b){
if(b==0){
    printf("Infinity\n");
    return NAN;
}
else{
  return a/b;
}
}

float modulo(int a,int b){
if(b==0){
    printf("Invalid Argument\n");
    return NAN;
}
else{
  return a%b;
}
}

int main(){
    float a,b,result;
    int choice;
 while(1){
printf("----------------------------\n");
 Printmenu();
printf("Enter The choice number :");
scanf("%d",&choice);
 if(choice==7)  break;
 if(choice<1||choice>7){
    printf("Invalid menu choice.\n");
    continue;
 }
printf("Please enter the first number: ");
scanf("%f",&a);
printf("Please enter the Second number: ");
scanf("%f",&b);
switch(choice){
case 1: result=a+b; 
      break;
case 2: result=a-b; 
      break;
case 3: result=a*b;
      break;
case 4: result=divide(a,b);
      break;
case 5: result=modulo(a,b);
      break;
case 6: result=pow(a,b);
      break;
}
if(!isnan(result)){
printf("The answer is= %f\n",result);
 }
 }
printf("Thank you for using the Calculator.\n");
printf("Developed by : Chirag\n");

    return 0;

}