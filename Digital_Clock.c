#include<stdio.h>
#include<unistd.h>  //header file where sleep function is there
#include<time.h>
#include<stdlib.h> //clear function 

void clearScreen(){
#ifdef _WIN32//if using windows PC ->then use this command to clear the output
    system("cls"); //system command to clear the screen
#else
    system("clear");  //Mac users
#endif
}

void data(){
    printf("Time formats:\n");
printf("1)12 Hours(Default)\n");
printf("2)24 Hours\n");
printf("Choose The Time format(1/2):");
}

void fill_time(char*buffertime,int format){//pointer callby refference,array of pointer char--> strings
time_t raw_time;   //variable of time_t named raw_time
struct tm *current_time; //struct of time func 'tm' we have declared pointer of it
//char buffer[50];       //string to show the formatted time
time(&raw_time); //time func fills/seeds the raw_time by current time
current_time=localtime(&raw_time); //local time-in specic area (so the local time is stored in the structure)

if(format==1){
strftime(buffertime,50,"%I:%M:%S",current_time);   //(where u want to store, size,format(%d,%f..?),current time) 
//   %S-seconds  %M-minutes %I-hours in 12 hours clock
//stringformattime(function in time.h)
}
else{//default
       strftime(buffertime,50,"%H:%M:%S %p",current_time);}
       //%p-PM/AM ,%H-hours in 24 hours clock 

}

void fill_date(char*buffer){//pointer callby refference,array of pointer char--> strings
time_t raw_time;   //variable of time_t named raw_time
struct tm *current_time; //struct of time func 'tm' we have declared pointer of it
//char buffer[50];       //string to show the formatted time
time(&raw_time); //time func fills/seeds the raw_time by current time
current_time=localtime(&raw_time); //local time-in specic area (so the local time is stored in the structure)

strftime(buffer,50,"%A %B %d %Y",current_time);   //(where u want to store, size,format(%d,%f..?),current time) 
//%A-weekdays    %B-month  %d-day of the month %Y-year
//stringformattime(function in time.h)

}

int main(){
    int format;
char time[50],date[50];
data();
scanf("%d",&format);
while(1){
     fill_time(time,format);  
     fill_date(date);
     clearScreen(); //clear the previous output
     printf("Current Time:%s\n",time);//(%s string)
     printf("Current Date:%s\n",date);
     sleep(1); //sleep for 1 seconds
}

    return 0;
}
