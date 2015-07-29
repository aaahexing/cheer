#include <vector>
#include <string>
using namespace std;

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

//Radix sort variable length string
//Assume all string elements are ASCII
//Assume all have length bounded by maxLen
void radixSort(vector<string> & in, int maxLen){
	const int BUCKETS = 256;
	vector<vector<string> > sortLenth(maxLen+1);
	vector<vector<string> > bucket(BUCKETS);
	
	for(int i = 0; i < in.size(); i++){
		vector[in[i].size()].push_back(in[i]);
	}

	int idx = 0;
	for(int i = 0; i < sortLenth.size(); i++){
		for(int j = 0; j < sortLenth[i].size(); j++)
			in[idx++] = sortLenth[i][j];
	}

	int startIdx = maxLen;
	for(int pos = maxLen - 1; pos >= 0; pos--){
		startIdx -= sortLenth[pos+1].size();         // startIdx should be defined and initialized outside of the for loop. Otherwise, a bug would occur.

		for(idx = startIdx; idx < in.size(); idx++){
			bucket[in[idx][pos]].push_back(in[idx]);
		}

		idx = startIdx;
		for(int i = 0; i < bucket.size(); i++){
			for(int j = 0; j < bucket[i].size(); j++)
				in[idx++] = bucket[i][j];
			bucket[i].clear();
		}
	}
}