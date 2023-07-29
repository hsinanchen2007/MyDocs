class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr)
	{
		

    }
};

class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        Arrays.sort(arr);
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> l = new ArrayList<>();
        int tmp=Integer.MAX_VALUE;
        for(int i=0;i<arr.length-1;i++)tmp=(tmp>arr[i+1]-arr[i]?arr[i+1]-arr[i]:tmp);
        for(int i=0;i<arr.length-1;i++){
            if(arr[i+1]-arr[i]==tmp){
                l.add(arr[i]);
                l.add(arr[i+1]);
                ans.add(new ArrayList<>((l)));
                l.clear();
            }
        }
        return ans;
    }
}


