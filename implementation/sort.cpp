#include <iostream>
using namespace std;

//time complexity: O(n^2) in worst-case and on average.
//space complexity: O(1)
//stable sort
void insertionSort(vector<int> & in){
	int i, j;
	for(i=1; i<in.size(); i++){
		int tmp = in[i];
		for(j=i-1; j>=0; j--){
			if(in[j] <= tmp)
				break;
			else
				in[j+1] = in[j];
		}
		in[j+1] = tmp;
	}
}

//stable sort
//space complexity: O(1)
//time complexity: O(n^2) in worst-case and on average.
void shellSort(vector<int> &in){
	for(int gap = in.size()/2; gap >= 1; gap /= 2){
		int i,j;
		for(i = gap; i < in.size(); i++){
			int tmp = in[i];
			for(j = i-gap; i >= 0; j -= gap){
				if(in[j] <= tmp)
					break;
				else
					in[j] = in[j+gap];
			}
			in[j+gap] = tmp;
		}
	}
}

//unstable sort
//space complexity: O(1)
//time complexity: O(nlogn) in worst-case and on average.
void heapSort(vector<int> & in){
	for(int i=(in.size()-2)/2; i>=0; i--){      //build heap
		downPercolate(in, in.size(), i);
	}

	for(int i=in.size()-1; i>=0; i--){
		int tmp = in[0];
		in[0] = in[i];
		in[i] = tmp;
		downPercolate(in, i, 0);
	}
}

void downPercolate(vector<int> & in, int size, int pos){
	int tmp = in[pos];
	int child = 2 * pos + 1;
	for(; child < size; pos = child){
		if(child+1 < size && in[child+1] > in[child]){
			child++;
		}
		if(in[child] > tmp){
			in[pos] = in[child];
		}
		else
			break;
	}
	in[pos] = tmp;
}

