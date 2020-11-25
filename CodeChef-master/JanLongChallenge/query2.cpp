#include<iostream>

using namespace std;

int n , q , l, r, ans1, ans2;

long int arr[100000];

struct node{

    int l1;
    int r1;
    int m;
    int l2;
    int r2;
    bool ch;

};

node tree1[200000];
node tree2[200000];

void build1(int low, int high, int index)
{

    if (low == high) {
        if(arr[low]>arr[low-1]) tree1[index].l1 = 1;
        else tree1[index].l1 = 0;

        tree1[index].l2=tree1[index].l1;



        if(arr[high]>arr[high+1]) tree1[index].r2 = 1;
        else tree1[index].r2 = 0;

        tree1[index].r1=tree1[index].r2;

        tree1[index].m=0;

        tree1[index].ch=true;

    }
    else {

        tree1[index].ch=false;

        int mid = (low + high) / 2;

        // left subtree
        build1(low, mid, 2 * index + 1);

        // right subtree
        build1(mid + 1, high, 2 * index + 2);

        tree1[index].l1 = tree1[2 * index + 1].l1,
        tree1[index].r1 = tree1[2 * index + 1].r1,

        tree1[index].l2 = tree1[2 * index + 2].l2;
        tree1[index].r2 = tree1[2 * index + 2].r2;



        tree1[index].m = tree1[2 * index + 1].m + tree1[2 * index + 2].m;


        if(tree1[2 * index + 1].ch && tree1[2 * index + 2].ch && tree1[2 * index + 1].r2==0) tree1[index].m++;
        else if(tree1[2 * index + 1].ch && tree1[2 * index + 1].r2==0 && tree1[2 * index + 2].l1==1 && tree1[2 * index + 2].r1==1) tree1[index].m++;
        else if(tree1[2 * index + 2].ch && tree1[2 * index + 1].l2==0 && tree1[2 * index + 1].r2==0 && tree1[2 * index + 2].l1==1) tree1[index].m++;
        else if( tree1[2 * index + 1].l2==0 && tree1[2 * index + 1].r2==0 && tree1[2 * index + 2].l1==1 && tree1[2 * index + 2].r1==1 ) tree1[index].m++;
        else if( tree1[2 * index + 1].l2==1 && tree1[2 * index + 1].r2==0 && tree1[2 * index + 2].l1==1 && tree1[2 * index + 2].r1==0 ) tree1[index].m--;





    }
}

void build2(int low, int high, int index)
{

    if (low == high) {
        if(arr[low]>arr[low-1]) tree2[index].l1 = 1;
        else tree2[index].l1 = 0;

        tree2[index].l2=tree2[index].l1;

        if(arr[high]>arr[high+1]) tree2[index].r2 = 1;
        else tree2[index].r2 = 0;

        tree2[index].r1=tree2[index].r2;

        tree2[index].m=0;

        tree2[index].ch=true;

    }
    else {

        tree2[index].ch=false;

        int mid = (low + high) / 2;

        // left subtree
        build2(low, mid, 2 * index + 1);

        // right subtree
        build2(mid + 1, high, 2 * index + 2);

        tree2[index].l1 = tree2[2 * index + 1].l1,
        tree2[index].r1 = tree2[2 * index + 1].r1,

        tree2[index].l2 = tree2[2 * index + 2].l2;
        tree2[index].r2 = tree2[2 * index + 2].r2;



        tree2[index].m = tree2[2 * index + 1].m + tree2[2 * index + 2].m;
        if(tree2[2 * index + 1].ch && tree2[2 * index + 2].ch && tree2[2 * index + 1].r2==1) tree2[index].m++;
        else if(tree2[2 * index + 1].ch && tree2[2 * index + 1].r2==1 && tree2[2 * index + 2].l1==0 && tree2[2 * index + 2].r1==0) tree2[index].m++;
        else if(tree2[2 * index + 2].ch && tree2[2 * index + 1].l2==1 && tree2[2 * index + 1].r2==1 && tree2[2 * index + 2].l1==0) tree2[index].m++;
        else if( tree2[2 * index + 1].l2==1 && tree2[2 * index + 1].r2==1 && tree2[2 * index + 2].l1==0 && tree2[2 * index + 2].r1==0 ) tree2[index].m++;
        else if( tree2[2 * index + 1].l2==0 && tree2[2 * index + 1].r2==1 && tree2[2 * index + 2].l1==0 && tree2[2 * index + 2].r1==1 ) tree2[index].m--;





    }
}

node query1(int index, int low,
           int high, int l, int r)
{

    node result;



    if (r < low || high < l)
        return result;


    if (l <= low && high <= r)
        return tree1[index];

    int mid = (low + high) / 2;


    if (l > mid)
        return query1(2 * index + 2,
                     mid + 1, high, l, r);


    if (r <= mid)
        return query1(2 * index + 1,
                     low, mid, l, r);

    node left = query1(2 * index + 1,
                      low, mid, l, r);
    node right = query1(2 * index + 2,
                        mid + 1, high, l, r);

  
    result.l1 = left.l1,
    result.r1 = left.r1,

    result.l2 = right.l2;
    result.r2 = right.r2;



    result.m = left.m + right.m;
    if(left.ch && right.ch && left.r2==0) result.m++;
    else if(left.ch && left.r2==0 && right.l1==1 && right.r1==1) result.m++;
    else if(right.ch && left.l2==0 && left.r2==0 && right.l1==1) result.m++;
    else if( left.l2==0 && left.r2==0 && right.l1==1 && right.r1==1 ) result.m++;
    else if( left.l2==1 && left.r2==0 && right.l1==1 && right.r1==0 ) result.m--;


    return result;
}



node query2(int index, int low,
           int high, int l, int r)
{

    node result;



    if (r < low || high < l)
        return result;


    if (l <= low && high <= r)
        return tree2[index];

    int mid = (low + high) / 2;


    if (l > mid)
        return query2(2 * index + 2,
                     mid + 1, high, l, r);


    if (r <= mid)
        return query2(2 * index + 1,
                     low, mid, l, r);

    node left = query2(2 * index + 1,
                      low, mid, l, r);
    node right = query2(2 * index + 2,
                        mid + 1, high, l, r);


    result.l1 = left.l1,
    result.r1 = left.r1,

    result.l2 = right.l2;
    result.r2 = right.r2;



    result.m = left.m + right.m;


    if(left.ch && right.ch && left.r2==1) result.m++;
    else if(left.ch && left.r2==1 && right.l1==0 && right.r1==0) result.m++;
    else if(right.ch && left.l2==1 && left.r2==1 && right.l1==0) result.m++;
    else if( left.l2==1 && left.r2==1 && right.l1==0 && right.r1==0 ) result.m++;
    else if( left.l2==0 && left.r2==1 && right.l1==0 && right.r1==1 ) result.m--;


    return result;
}




int main(){

      cin>>n>>q;


      for(int i=0;i<n;i++) cin>>arr[i];

      build1(0, n - 1, 0);
      build2(0, n - 1, 0);

      while(q--){

           cin>>l>>r;

         ans1=query1(0, 0, n - 1, l-1, r-1 ).m;
         ans2=query2(0, 0, n - 1, l-1, r-1 ).m;
         if(ans1==ans2) cout<<"YES"<<endl;
         else cout<<"NO"<<endl;

      }



    return 0;


}
