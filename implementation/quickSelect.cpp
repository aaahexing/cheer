//return the k'th element
//space complexity: O(1)
//time complexity: O(n) on average and O(n^2) in worst-case
int quickSelect(vecor<int> & in, int k){
	if(k >= in.size()){
		cout<<"k is out of range!"<<endl;
		return -1;
	}
	return quickSelect(in, 0, in.size()-1, k);
}

//main recursion function in quickSelect
int quickSelect(vector<int> & in, int left, int right, int k){
	if(left + 10 >= right){
		return InsertionSort(in, left, right, k);
	}

	int pivot = median(in, left, right);
	int i=left, j=right-1;
	while(i <= j){
		while(in[++i] < pivot){}
		while(in[--j] > pivot){}
		if(i <= j)
			swap(in[i], in[j])
	}
	swap(in[i], in[right-1]);

	if(k < i)
		return quickSelect(in, left, i-1, k);
	else if(k == i)
		return in[i];
	else
		return quickSelect(in, i+1, right, k);
}

int median(vector<int> & in, int left, int right){
	int mid = left + (right - left)/2;
	if(in[left] > in[mid])
		swap(in[left], in[mid]);
	if(in[left] > in[right])
		swap(in[left], in[right]);
	if(in[mid] > in[right])
		swap(in[mid], in[right]);

	swap(in[mid], in[right-1]);

	return in[right-1];
}

void swap(int & a, int & b){
	int tmp = a;
	a = b;
	b = tmp;
}

int insertionSort(vector<int> in, int left, int right, int k){
	for(int i = left+1; i <= right; i++){
		int tmp = in[i];
		int j = i-1;
		for(; j >= 0; j--){
			if(in[j] > tmp)
				in[j+1] = in[j];
			else
				break;
		}
		in[j+1] = tmp;
	}

	return in[k];
}