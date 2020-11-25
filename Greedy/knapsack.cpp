bool comparator(Item a,Item b){
   return ((double)a.value/a.weight) > ((double)b.value/b.weight);
}
// function to return fractionalweights
double fractionalKnapsack(int W, Item arr[], int n)
{
    sort(arr,arr+n,comparator);
    double ans=0;
    for(int i=0;i<n;i++){
        if(W==0) break;
        if(W>=arr[i].weight) ans=ans+arr[i].value,W=W-arr[i].weight;
        else ans=ans + (double)arr[i].value*W/arr[i].weight,W=0;
    }

    return ans;
}
