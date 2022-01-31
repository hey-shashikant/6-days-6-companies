class Solution {
public:
    bool stoneGame(vector<int>& a) {
        int p1 = 0, p2 = 0, i = 0;
        int start = 0, end = a.size()-1;
        while(start <= end)
        {
                if(i%2 == 0)
                {
                    if(a[start] > a[end])
                    {
                        p1+=a[start];
                        start++;
                    }
                    else if(a[start] < a[end])
                    {
                        p1+=a[end];
                        end--;
                    }
                    else
                    {
                        p1+=a[start];
                        start++;
                    }
                }
                else
                {
                    if(a[start] < a[end])
                    {
                        p2+=a[start];
                        start++;
                    }
                    else if(a[start] > a[end])
                    {
                        p2+=a[end];
                        end--;
                    }
                    else
                    {
                        p2+=a[start];
                        start++;
                    }
                }
                i++;
        }
        if(p1 > p2)
            return true;
        return false;
    }
};
