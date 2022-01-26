/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findpeak(MountainArray &arr)
    {  
        int start=0;
        int n=arr.length();
        int end=n-1;
        while(start<end)
        {    int mid=start +(end-start)/2;
             int lft,rgt;
             int midele=arr.get(mid);
             if(mid>0 && mid<n-1)    //This check if mid is not first and last ele,If mid is 0,we cannot find its left element
              {  lft=arr.get(mid-1); 
                 rgt=arr.get(mid+1);
                 if(lft< midele && midele>rgt )  //Ele is peak ele if middle ele is greater than both lft and rgt
                    return mid;
                 else if(lft<midele)
                   start=mid;
                 else 
                  end=mid;
              }
         else if(mid==0 && midele>arr.get(mid+1)) return mid; //If mid =0, Only check right ele
         else if(midele>arr.get(mid-1)) return mid;  //If mid==n-1 check only left ele
         }
        return -1;
    }
              
    int leftbsearch(MountainArray &arr,int s,int e,int target) //Simple binary search
    {
         while(s<=e)
          {  int mid=s +(e-s)/2;
             int mide=arr.get(mid);
             if(mide==target)
                 return mid;
             else if(mide>target)
                  e=mid-1;
             else 
                  s=mid+1;
            }
        return -1;
        
    }
    int rightbsearch(MountainArray &arr,int s,int e,int target) //Reverse binary search
    {
         while(s<=e)
           {  int mid=s +(e-s)/2;
              int mide=arr.get(mid);
              if(mide==target)
                return mid;
              else if(mide>target)
                 s=mid+1;
              else 
                e=mid-1;
              }
        return -1;
     }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peakindex=findpeak(mountainArr);      //Index of Peak element in array
        int n=mountainArr.length();
        int lft=leftbsearch(mountainArr,0,peakindex,target);     //Binary search in left part
        int rgt=rightbsearch(mountainArr,peakindex+1,n-1,target);  //Binary search in right part
        if(lft==-1)                     //If target is present in left return left,If in right return right
            return rgt;                //else return -1{All 3 cases covered in these 2 condition}//
        return lft;
    }
};
