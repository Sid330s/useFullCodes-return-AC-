Input: coins[] = {25, 10, 5}, V = 30
Output: Minimum 2 coins required
We can use one coin of 25 cents and one of 5 cents

Input: coins[] = {9, 6, 5, 1}, V = 11
Output: Minimum 2 coins required
We can use one coin of 6 cents and 1 coin of 5 cents

                0 1 2 3 4 5 6 7 8 9 10 11
             1  0 1 2 3 4 5 6 7 8 9 10 11
             5  0 1 2 3 4 1 2 3 4 5 2  3
             6  0 1 2 3 4 1 1 2 3 4 2  2
             9


 // m is size of coins array (number of different coins)
 int minCoins(int coins[], int m, int V)
 {

     int table[V+1];
     table[0] = 0;
     for (int i=1; i<=V; i++) table[i] = INT_MAX;

     for (int i=1; i<=V; i++)
     {
         for (int j=0; j<m; j++)
           if (coins[j] <= i)
           {
               int sub_res = table[i-coins[j]];
               if (sub_res != INT_MAX && sub_res + 1 < table[i])
                   table[i] = sub_res + 1;
           } 
     }
     return table[V];
 }
