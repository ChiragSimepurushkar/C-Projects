#include<stdio.h>
#include<string.h>


int Menu();
void Create_account();
void deposit_money();
void withdraw_money();
void check_balance();

typedef struct Bank_Management{
    char name[50];
    int acc_no;
    float balance;
}Account;

const char* ACCOUNT_FILE="account.dat";

int main(){
    while(1){
        int a;
printf("\n\n****Bank Management System****\n");
printf("1. Create Account\n2. Deposite Money\n");
printf("3. Withdraw Money\n4. Check Balance\n5. Exit\n");
printf("Enter your Choice: ");
scanf("%d",&a);
// int choice=Menu();

switch(a){
    case 1:
          Create_account();
          break;
    case 2:
          deposit_money();
          break;
    case 3:
          withdraw_money();
          break;
    case 4:
          check_balance();
          break;
    case 5:
          printf("Exiting!!. Thank you for visiting!!\n");
          return 0;
          break;
    default:
          printf("Invalid Choice!!\n");
          break;

      }
    }

    return 0;
}

void Create_account(){
        Account acc;
        FILE *file=fopen(ACCOUNT_FILE,"ab+"); //binary file(dat)  , ab(append binary)
        if(file==NULL){
            printf("Unable to open file!!!\n");
            return;
        }

        char c;
        do {
            c=getchar();
        }while(c!='\n' && c!=EOF);

        printf("Enter your name: ");
        fgets(acc.name,sizeof(acc.name),stdin);  //fgets bcz we need to take space as a character
        //fgets puts '\n' at last we need ot remove that
        int index=strcspn(acc.name,"\n");
        acc.name[index]='\0';
        printf("Enter your Account number: ");
        scanf("%d",&acc.acc_no);
        acc.balance=0;  //initialise balance to zero
        
        fwrite(&acc,sizeof(acc),1,file);  //one varaible we are writing so 1
        fclose(file);
        printf("Your account is created successfully!!!\n");
}

void deposit_money(){
    FILE *file=fopen(ACCOUNT_FILE,"rb+");//i have to read the data to find the account and also write is(overwrite) the blance with new one so 'b'
       if(file==NULL){
           printf("Unable to open the account file!!\n");
           return;
           }
       int acc_no;
       float money;
       Account acc_to_read;
       printf("Enter your account No: ");
       scanf("%d",&acc_no);

       printf("Enter the amount to be deposited: ");
       scanf("%f",&money);
       while(fread(&acc_to_read,sizeof(acc_to_read),1,file)){
            if(acc_to_read.acc_no == acc_no){
                    acc_to_read.balance+=money;
                    //to overwrite it I have to mave the corser backward inside the file//since after reading the account no. the corser will be in front
                    //to do this we use fseek()
                    fseek(file,-(sizeof(acc_to_read)),SEEK_CUR);//(-)backward from current position
                    fwrite(&acc_to_read,sizeof(acc_to_read),1,file);
                    fclose(file);
                    printf("Successfully deposited Rs.%.2f .\nYour new balance is Rs.%.2f",money,acc_to_read.balance);
                    return ;
                }
            }
    fclose(file);
    printf("Money could not be deposited as Account No.%d is not found in Records\n",acc_no);
}

void withdraw_money(){
       FILE *file= fopen(ACCOUNT_FILE,"rb+");
       if(file==NULL){
        printf("Unable to open account file!!!.\n");
        return;
       }

       Account acc_read;
       int acc_no;
       float money;

       printf("Enter your Account No: ");
       scanf("%d",&acc_no);
       printf("Enter amount to be withdrawn: ");
       scanf("%f",&money);

       while(fread(&acc_read,sizeof(acc_read),1,file)){
           if(acc_read.acc_no == acc_no){
                 if(acc_read.balance>=money){
                     acc_read.balance-=money;
                     fseek(file,-(sizeof(acc_read)),SEEK_CUR);
                     fwrite(&acc_read,sizeof(acc_read),1,file);
                     printf("Successfully withdrawn Rs.%.2f!!!.Your new balance is Rs.%.2f",money,acc_read.balance);  
                 }else{
                    printf("Insufficient balance!!");
                 }
                 fclose(file);
                 return;
              }
           }
fclose(file);
printf("Money could not be withdrawn as Account No.%d is found in Records",acc_no);


}

void check_balance(){
    FILE *file=fopen(ACCOUNT_FILE,"rb");
    if(file==NULL){
            printf("Unable to open file!!!\n");
            return;
        }

    int acc_no;

    Account acc_read;
    printf("Enter your Account number: ");
    scanf("%d",&acc_no);

    while(fread(&acc_read,sizeof(acc_read),1,file)){//return 0 if EOF
               if(acc_read.acc_no==acc_no){
                   printf("Your account balance is Rs.%.2f\n",acc_read.balance);
                   fclose(file);
                   return;
          }
    }
    fclose(file);
    printf("Account no:%d was not found.\n",acc_no);
}


int Menu(){
int a;
printf("\n\n****Bank Management System****\n");
printf("1. Create Account\n2. Deposite Money\n");
printf("3. Withdraw Money\n4. Check Balance\n5. Exit\n");
printf("Enter your Choice: ");
scanf("%d",&a);
return a;
}