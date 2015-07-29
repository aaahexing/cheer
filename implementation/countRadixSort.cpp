#include <vector>
#include <string>
using namespace std;

//Implement count radix sorting. 
//Assume the string element are ASCII
//Assume all string have the same length
//time complexity: O(strLen*(arrSize + BUCKETS)
//space complexity: O(max(strLen, arrSize)
//strLen represents the length of a string adn arrSize represents the array's size
void countRadixSort(vector<string> & in){
	if(in.empty())
		return;

	const int BUCKETS = 256;
	int strLen = in[0].size();
	vector<string> temp(in.size());
	vector<int> count(BUCKETS+1);

	for(int i = strLen -1; i >= 0; i--){
		temp.clear();
		temp.resize(in.size());

		count.assign(count.size(), 0);
		for(int j = 0; j < in.size(); j++){
			count[in[j][i] + 1]++;
		}

		for(int j = 1; j <= BUCKETS; j++){
			count[j] += count[j-1];
		}

		for(int j = 0; j < in.size(); j++){
			temp[count[in[j][i]]++] = in[j];
		}

		in = temp;

	}
}