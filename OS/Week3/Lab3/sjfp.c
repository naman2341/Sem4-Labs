#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct proc {
  int id_;
  int burst_;
  int copy_;
  int arrival_;
};
struct executed {
  int wait_;
  int tat_; 
  int end_;
};

typedef struct executed exec_t;
typedef struct proc proc_t;

void fetch_proc(proc_t **list, int n);
void exec_proc(proc_t **list, exec_t **exec_list, int n);
void print(int n, exec_t **exec_list);

int main() {
  int n;
  printf("Enter number of processes : ");
  scanf("%d", &n);
  proc_t *list[1024] = {NULL}; 
  exec_t *exec_list[1024] = {NULL};
  fetch_proc(list, n); 
  exec_proc(list, exec_list, n);
  print(n, exec_list);
  return 0;
}

void fetch_proc(proc_t **list, int n) {
  printf("Enter process details : \n");
  for (int i = 0; i < n; i++) {

    printf("Next process : \n");
    printf("\t Enter process id : ");
    int c;
    scanf("%d", &c);
    bool present = false; 
    for (int j = 0; j < 1024; j++) {
      if (list[j] != NULL &&
          list[j]->id_ == c) { 
        printf("\n Process with same ID has already arrived! \n");
        printf("previous input discarded! \n");
        printf(
            "If you want to enter a dummy process enter burst time as 0 \n \n");
        present = true;
      }
    }

    if (!present) {
      list[i] = (proc_t *)malloc(sizeof(proc_t));
      list[i]->id_ = c;
      printf("\t Enter process arrival time : ");
      scanf("%d", &(list[i]->arrival_));
      printf("\t Enter process burst time : ");
      scanf("%d", &(list[i]->burst_));
      list[i]->copy_ = list[i]->burst_;
    } else {
      i--; 
    }
  }
}

void exec_proc(proc_t **list, exec_t **exec_list, int n) {
  list[1023] = (proc_t *)malloc(sizeof(proc_t));
  int count = 0; 
  for (int time = 1; count != n; time++) {
    int smallest = 1023; 
    list[1023]->burst_ = 99999;
    for (int i = 0; i < n; i++) {
      if (list[i] != NULL) {
        if (list[i]->arrival_ <= time &&
            list[i]->burst_ <= list[smallest]->burst_ && list[i]->burst_ > 0) {

          smallest = i;
        }
      }
    }
    list[smallest]->burst_--;
    if (list[smallest]->burst_ == 0) { 
      count++;
      exec_list[smallest] = (exec_t *)malloc(sizeof(exec_t));
      exec_list[smallest]->end_ = time + 1;
      exec_list[smallest]->wait_ = exec_list[smallest]->end_ -
                                   list[smallest]->arrival_ -
                                   list[smallest]->copy_;
      exec_list[smallest]->tat_ =
          exec_list[smallest]->end_ - list[smallest]->arrival_;
    }
  }
}

void print(int n, exec_t **exec_list) {
  double wait_sum = 0.0;
  double tat_sum = 0.0;
  for (int i = 0; exec_list[i] != NULL; i++) {
    wait_sum += exec_list[i]->wait_;
    tat_sum += exec_list[i]->tat_;
  }
  printf("Average wait time : %f \n", wait_sum / n);
  printf("Average turnaround time : %f \n", tat_sum / n);
}