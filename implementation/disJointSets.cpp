class DisjSets{
public:
	void DisjSets(int numElement){
		arr.resize(numElement, -1);
	}

	int Find(int num) const;
	void Union(int num1, int num2);
private:
	vector<int> arr;
}

//find the root of the tree including num
//time complexity: O(logn) in worst-case
int DisjSets::Find(int num) const{
	if(arr[num] < 0)
		return num;
	else
		return arr[num] = Find(arr[num]);
}

//num1 and num2 represents root
//union by size
//time complexity: O(1)
void DisjSets::Union(int num1, int num2){
	if(arr[num1] < arr[num2]){
		arr[num1] += arr[num2];
		arr[num2] = num1;
	}
	else{
		arr[num2] += arr[num1];
		arr[num1] = num2;
	}
}

//num1 and num2 represents root
//union by rank
void DisjSets::Union(int num1, int num2){
	if(arr[num1] < arr[num2])
		arr[num2] = num1;
	else
	{
		if(arr[num1] == arr[num2])
			arr[num2]--;
		arr[num1] = num2;
	}
}