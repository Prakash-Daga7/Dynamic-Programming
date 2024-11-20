int f(int day,int ind,vector<vector<int>> &points)
{
    if(day==0)
    {
        int maxi=0;
        for(int task=0;task<3;task++)
        {
            if(task !=last)
            {
                maxi=max(maxi,points[0][task]);
            }
        }
        return maxi;
    }
    int maxi=0;
    for(int task=0;task<3;task++)
    {
        if(task!=last)
        {
            int point=point[day][]
        }
    }
}