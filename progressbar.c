#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<time.h>




const int BAR_LENGTH=50;
const int MAX_TASK =5;

typedef struct {
  int id;
  int progress;
  int step;
}Task;

void print_bar(Task task);
void clear_Screen();

int main(){
    Task task[MAX_TASK];
    srand(time(NULL));

for(int i=0;i<MAX_TASK;i++){
    task[i].id = i+1;
    task[i].progress = 0;
    task[i].step=rand()%5+1;   
}

int task_incomplete=1;
while(task_incomplete){
      task_incomplete=0;
      clear_Screen();
    for(int i=0;i<MAX_TASK;i++){
     task[i].progress+=task[i].step;
       if(task[i].progress>100){
            task[i].progress=100;
       }
       else if(task[i].progress<100){
        task_incomplete=1;
       }
       print_bar(task[i]);
    }
   sleep(1);  //sleep for one seconds
  }

  printf("All tasks completed!!\n");


    return 0;
}


void print_bar(Task task){
int bars_to_show= (task.progress * BAR_LENGTH)/100;
    printf("Task %d: [",task.id);
for(int i=0;i<BAR_LENGTH;i++){
        if(i<bars_to_show){
           printf("=");
        }else{
            printf(" ");
        }

}
printf("] %d%%\n",task.progress);
}


void clear_Screen(){
   #ifdef _Win32
      system("cls");
   #else
     system("Clear");
   #endif
}

















