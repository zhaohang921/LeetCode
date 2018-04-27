// Combinations：
// Given two integers n and k,return all possible combinations of k numbersout of 1 ... n. 
// For example, If n = 4 and k =2, a solution is:
// [[2,4],
 // [3,4],
 // [2,3],
 // [1,2],
 // [1,3],
 // [1,4],]
 
 // 给你两个整数 n和k，从1-n中选择k个数字的组合。
 // 比如n=4，那么从1,2,3,4中选取两个数字的组合，包括图上所述的六种。
 
 
class Solution{
public:
    List<List<int>> combine(int n,int k){
        
        
    }
    void BackTracking(int n,int k,int start,List<int> list){
        if(k<0) return;
        else if(k==0)
            result.push(list);
        else{
            for(int i=start;i<=n;i++){
                list.push(i);
                BackTracking(n,k-1,i+1,list);
                list.pop_back();
            }
        }
    }
private:
    List<List<int>> result=new ;
};
