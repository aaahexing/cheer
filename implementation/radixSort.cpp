//radix sort an array of string
//assume all the string have the same length
//space complexity: O(256)
//time complexity: O(L(N+256))

void radixSort(vector<string> & arr){
	int strLen = arr[0].size();
	const int BUCKETS = 256;
	vector<vector<string> > bucket<BUCKETS>;
	for(int i = 0; i < bucket.size(); i++){
		bucket[i].clear();
	}

	for(int i = strLen; i >= 0; i--){
		for(int j = 0; j < arr.size(); j++){
			bucket[arr[j][i]].push_back(arr[j]);
		}

		arr.clear();
		for(int j = 0; j < bucket.size(); j++){
			for(int k = 0; k < bucket[i].size(); k++)
				arr.push_back(bucket[i][k]);
		}

		for(int j = 0; j < bucket.size(); j++){
			bucket[j].clear();
		}
	}
}