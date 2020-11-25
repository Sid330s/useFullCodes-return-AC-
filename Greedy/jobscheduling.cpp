
bool comparison(Job a, Job b)
{
     return (a.profit > b.profit);
}

// Returns minimum number of platforms reqquired
pair<int,int> JobScheduling(Job arr[], int n)
{

    sort(arr, arr+n, comparison);
    int result[n];
    bool slot[n];

    for (int i=0; i<n; i++) slot[i] = false;


    for (int i=0; i<n; i++)
    {

       for (int j=min(n, arr[i].dead)-1; j>=0; j--)
       {

          if (slot[j]==false)
          {
             result[j] = arr[i].profit;
             slot[j] = true;
             break;
          }
       }
    }

    int cnt=0;
    int maxprofit=0;
    for (int i=0; i<n; i++)
       if (slot[i]) cnt++,maxprofit=maxprofit+result[i];
    return  make_pair(cnt,maxprofit);
}
  
