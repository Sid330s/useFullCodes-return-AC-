
#include<bits/stdc++.h>
using namespace std;

int  quantum = 2;

struct process {
    int pid;
    int at;
    int st;
    int bt;
    int remaining_time;
    int ct;
    int tat;
    int wt;
    int rt;
    bool is_first;

};

bool compareArrival(process p1, process p2)
{
    return p1.at < p2.at;
}

bool compareID(process p1, process p2)
{
    return p1.pid < p2.pid;
}

int main(){

      int n;
      struct process p[100];

      float avg_tat;
      float avg_wt;
      float avg_rt;
      float cpu_utilisation;

      int total_tat = 0;
      int total_wt = 0;
      int total_rt = 0;

      float throughput;

      cout << setprecision(2) << fixed;

      cout<<"Enter the number of processes: ";
      cin>>n;

      for(int i = 0; i < n; i++) {
          cout<<"Arrival time: "<<i+1<<": ";
          cin>>p[i].at;
          cout<<"Burst time: "<<i+1<<": ";
          cin>>p[i].bt;
          p[i].pid = i+1;
          p[i].remaining_time=p[i].bt;
          p[i].is_first=true;
          cout<<endl;
      }

      sort(p,p+n,compareArrival);

      queue<process> RQ;

      for(int i = 0; i < n; i++) RQ.push(p[i]);

      int time_now=0;
      int i=0;
      while(!RQ.empty()){
          process curr = RQ.front();
          RQ.pop();

          if(curr.is_first){
            if(time_now < curr.at) time_now = curr.at;
            curr.st = time_now;
            curr.rt = curr.st - curr.at;
            curr.is_first = false;
          }

          if(curr.remaining_time > quantum ){
            time_now = time_now + quantum;
            curr.remaining_time-=quantum;
            RQ.push(curr);
          }
          else{

            time_now = time_now + curr.remaining_time;
            curr.remaining_time=0;
            curr.ct = time_now;
            curr.tat = curr.ct - curr.at;
            curr.wt = curr.tat - curr.bt;
            p[i]=curr;
            total_tat += p[i].tat;
            total_wt += p[i].wt;
            total_rt += p[i].rt;
            i++;

          }
          avg_tat = (float) total_tat / n;
          avg_wt = (float) total_wt / n;
          avg_rt = (float) total_rt / n;
          throughput = float(n) / (p[n-1].ct - p[0].at);


      }

      sort(p,p+n,compareID);


      cout<<endl;

      cout<<"PID\t"<<"AT\t"<<"BT\t"<<"ST\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<"RT\t"<<"\n"<<endl;

      for(int i = 0; i < n; i++) {
          cout<<p[i].pid<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].st<<"\t"<<p[i].ct<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<"\t"<<p[i].rt<<"\t"<<"\n"<<endl;
      }
      cout<<"Average Turnaround Time: "<<avg_tat<<endl;
      cout<<"Average Waiting Time: "<<avg_wt<<endl;
      cout<<"Average Response Time:  "<<avg_rt<<endl;
      cout<<"Throughput: "<<throughput<<" process/unit time"<<endl;


return 0;

}


/*
Processes  Arrival Time      Burst time  completion time Turn Around Time  Waiting time
 1        0        5     12        12         7
 2        1        4     11        10         6
 3        2        2     6        4         2
 4        3        1     7        4         3
Average waiting time = 4.5
Average turn around time = 7.5


*/
