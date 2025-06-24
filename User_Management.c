#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include <termios.h>  //controlls terminal



#define MAX_USER 10
#define CREDENTIAL_LENGTH 30


typedef struct {
char username[CREDENTIAL_LENGTH];
char password[CREDENTIAL_LENGTH];

}User;

User users[MAX_USER];
int user_count=0;  //initiall no. of user registered
int user_index;

int printMenu();
void register_user();
int login_user();//returns index of the user.
void fix_fgets_input(char*);  //to fix '\n' to '\0'
void input_credentials(char*,char*);//to input passsword and user name


int main(){

while(1){
    int option=printMenu();
switch(option){
case 1:
      register_user();
      break;
case 2:
      user_index=login_user();
      if(user_index>=0){//correct user
       printf("Login Successful!! Welcome, %s!",users[user_index].username);      
      }
      else{//invalid user
      printf("Login failed!! Incorrect username or password.\n");
      }
      break;
case 3:printf("Exiting Program.\n");
       return 0;
      break;
default :
      printf("Invalid option!!. Please try again\n");
      break;
   }
}

    return 0;
}

int printMenu(){
    int option;
printf("---Welcome to User Management---\n");
printf("1. Register\n");
printf("2. Login\n");
printf("3. Exit\n");
printf("Select an Option: ");
scanf("%d",&option);
return option;
}

void register_user(){
    if(user_count==MAX_USER){
        printf("Maximum %d users are supported! No more registrations are Allowed.\n");
        return;
    }

int new_index=user_count;
printf("Register a new user\n");
input_credentials(users[new_index].password,users[new_index].username);
user_count++;
printf("Registration Successful!!.\n");

}

void input_credentials(char*password,char* username){
    printf("Enter the user name: ");
fgets(username,CREDENTIAL_LENGTH, stdin );//fgets makes the last char as '\n' so we dont want since the
                                                           // computer may think that '\n' is also the part of password or username
fix_fgets_input(username);
printf("Enter the password(masking enabled): ");
fflush(stdout);// to flush the screen to run forward code

// Change terminal Properties
struct termios old_props,new_props; //terminal properties
tcgetattr(STDIN_FILENO, &old_props);
new_props=old_props;
new_props.c_lflag = ~(ECHO | ICANON);
tcsetattr(STDIN_FILENO,TCSANOW, &new_props)

char ch;
int i=0;
while((ch=getchar())!='\n' && ch !=EOF){
    if(ch=='\b' || ch==127){// backspace /delete, 127 ASCII value of delete
         if(i>0){//otherwise it will delete the messages too
         i--;
         printf("\b \b");}  //moves corser backwards, first to go back, then print space inplace of * and then move again back to original place
    }else{
     password[i++]=ch;
     print("*");
    }
password[i]='\0';
tcsetattr(STDIN_FILENO,TCSANOW, &old_props);

// fgets(password,CREDENTIAL_LENGTH,stdin);
// fix_fgets_input(password);
}


int login_user(){
    char username[CREDENTIAL_LENGTH], password[CREDENTIAL_LENGTH];//two new variable to check

// printf("Enter the user name: ");
// fgets(username,CREDENTIAL_LENGTH, stdin );//fgets makes the last char as '\n' so we dont want since the
//                                                            // computer may think that '\n' is also the part of password or username
// fix_fgets_input(username);
// input_password(password);
input_credentials(password,username);
for(int i=0; i< user_count;i++){//check for the user 
   if(strcmp(username,users[i].username)==0 && 
           strcmp(password,users[i].password)==0){//string compare returns 0 if both matches
       return i;    
     }
}

return -1;  //for invalid user.
}

void fix_fgets_input(char* string){
int index=strcspn(string,"\n"); //used to find index of characters u want 
string[index]='\0';  //replacing '\n' to '\0'
}
