#include<bits/stdc++.h>
using namespace std;

bool binarySearch(vector<vector<int>> &matrix, int target){
	int n=matrix.size();
	int m=matrix[0].size();

	int low=0;
	int high=m*n-1;

	while(low!=high)
	{
		int mid=(low+high-1)/2;
		if(matrix[mid/m][mid%m]<target)
			low=mid+1;
		else
			high=mid;
	}
	if(matrix[high/m][high%m]==target)
		return true;

	return false;	
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<vector<int>>matrix={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	int target=11;

	cout << binarySearch(matrix, target) << endl;

	return 0;

}