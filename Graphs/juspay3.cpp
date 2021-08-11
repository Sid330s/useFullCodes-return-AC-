public static int solution(int arr[])
{
    ArrayList<Integer> sum = new ArrayList<>();
    for(int i = 0; i < arr.length; i ++)
    {
        ArrayList<Integer> path = new ArrayList<>();
        int j = i;
        int tempSum = 0;
        while(arr[j]<arr.length && arr[j]!=i && arr[j]!=-1 && !path.contains(j))
        {
            path.add(j);
            tempSum+=j;
            j=arr[j];
            if(arr[j]==i)
            {
                tempSum+=j;
                break;
            }
        }
        if(j<arr.length && i == arr[j])
            sum.add(tempSum);
    }
        if(sum.isEmpty())
            return -1;
        return Collections.max(sum);
}
