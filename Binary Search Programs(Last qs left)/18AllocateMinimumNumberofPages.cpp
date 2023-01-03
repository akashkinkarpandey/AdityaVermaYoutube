//https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool isPossibletoAllocate(int A[],int N,int M,int maxPagesYouCanAllocate)
    {
        int student=1;
        int countPagestillNow=0;
        for(int i=0;i<N;i++)
        {
            if(countPagestillNow+A[i]>maxPagesYouCanAllocate)
            {
                student++;
                if(student>M)
                return false;
                countPagestillNow=A[i];
            }
            else countPagestillNow+=A[i];
        }
        return true;
    }
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(N<M)
        return -1;
        int low=A[N-1];
        int high=accumulate(A,A+N,0);
        int res=INT_MAX;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            //mid is a possible max number of pages
            if(isPossibletoAllocate(A,N,M,mid))
            {
                res=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        if(res==INT_MAX)
        return -1;
        return res;
    }
};
// You are given N number of books. Every ith book has Ai number of pages. 
// You have to allocate contiguous books to M number of students. There can be many ways or permutations to do so.
//In each permutation, one of the M students will be allocated the maximum number of pages. Out of all these permutations, 
//the task is to find that particular permutation in which the maximum number of pages allocated to a student is 
//the minimum of those in all the other permutations and print this minimum value.

// Each book will be allocated to exactly one student. Each student has to be allocated at least one book.

// Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).
// Example 1:

// Input:
// N = 4
// A[] = {12,34,67,90}
// M = 2
// Output:113
// Explanation:Allocation can be done in 
// following ways:{12} and {34, 67, 90} 
// Maximum Pages = 191{12, 34} and {67, 90} 
// Maximum Pages = 157{12, 34, 67} and {90} 
// Maximum Pages =113. Therefore, the minimum 
// of these cases is 113, which is selected 
// as the output.
