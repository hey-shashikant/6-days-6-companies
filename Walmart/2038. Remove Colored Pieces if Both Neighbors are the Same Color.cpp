class Solution {
public:
    bool winnerOfGame(string colors) 
    {
        int alice = 0,bob = 0;
        int i = 0;
        while(i < colors.size())
        {
            int countA = 0,countB = 0;
            if(colors[i] == 'A')while(colors[i] == 'A' and i < colors.size()){countA++;i++;}
            else while(colors[i] == 'B' and i < colors.size()){countB++;i++;}
            if(countA > 2)alice += countA-2;
            else if(countB > 2)bob += countB-2;
        }
        return alice > bob;
    }
};
