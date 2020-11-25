#include<bits/stdc++.h>
using namespace std;

struct process {
    int pid;
    int at;
    int bt;
    int st;
    int ct;
    int tat;
    int wt;
    int rt;
};

bool compareArrival(process p1, process p2)
{
    return p1.at < p2.at;
}

bool compareID(process p1, process p2)
{
    return p1.pid < p2.pid;
}

int main() {

    int n;
    struct process p[100];
    float avg_tat;
    float avg_wt;
    float avg_rt;
    float cpu_utilisation;
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
        cout<<endl;
    }

    sort(p,p+n,compareArrival);

    for(int i = 0; i < n; i++) {
        p[i].st = (i == 0) ? p[i].at : max(p[i-1].ct,p[i].at);
        p[i].ct = p[i].st + p[i].bt;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        p[i].rt = p[i].st - p[i].at;

        avg_tat += p[i].tat;
        avg_wt += p[i].wt;
        avg_rt += p[i].rt;
    }

    avg_tat = (float) avg_tat / n;
    avg_wt = (float) avg_wt / n;
    avg_rt = (float) avg_rt / n;
    throughput = float(n) / (p[n-1].ct - p[0].at);

    sort(p,p+n,compareID);

    cout<<endl;
    cout<<"PID\t"<<"AT\t"<<"BT\t"<<"ST\t"<<"CT\t"<<"TAT\t"<<"WT\t"<<"RT\t"<<"\n"<<endl;

    for(int i = 0; i < n; i++) {
        cout<<p[i].pid<<"\t"<<p[i].at<<"\t"<<p[i].bt<<"\t"<<p[i].st<<"\t"<<p[i].ct<<"\t"<<p[i].tat<<"\t"<<p[i].wt<<"\t"<<p[i].rt<<"\t"<<"\n"<<endl;
    }
    cout<<"Average Turnaround Time: "<<avg_tat<<endl;
    cout<<"Average Waiting Time: "<<avg_wt<<endl;
    cout<<"Average Response Time: "<<avg_rt<<endl;
    cout<<"Throughput: "<<throughput<<" process/unit time"<<endl;


}
