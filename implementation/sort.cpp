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

//space complexity: O(n)
//time complexity: O(nlogn) in worst-case and on average.
//stable sort
void mergeSort(vector<int> & in){
	vector<int> mg(in.size());
	mergeSort(in, 0, in.size()-1, mg);
}

void mergeSort(vector<int> & in, int leftIdx, int rightIdx, vector<int> & mg){
	if(leftIdx >= rightIdx)
		return;
	int mid = leftIdx + (rightIdx - leftIdx)/2;
	mergeSort(in, left, mid, mg);
	mergeSort(in, mid+1, rightIdx, mg);
	merge(in, mg, leftIdx, mid, rightIdx);
}

void merge(vector<int> & in, vector<int> & mg, int leftStart, int leftEnd, int rightEnd){
	int rightStart = leftEnd + 1;
	int idxL = leftStart, idxR = rightStart, idx = leftStart;
	
	while(idxL <= leftEnd && idxR <= rightEnd){
		if(in[idxL] <= in[idxR])                //<= operation promises the stable sort
			mg[idx++] = in[idxL++];
		else
			mg[idx++] = in[idxR++];
	}

	if(idxL > leftEnd){                        //In fact, this if condition can be removed.
		while(idxR <= rightEnd){               //copy the other elements to mg
			mg[idx++] = in[idxR++];
		}
	}

	if(idxR > rightEnd){
		while(idxL <= leftEnd){
			mg[idx++] = in[idxL++];
		}
	}

	for(idx = leftStart; idx <= rightEnd; idx++){
		in[idx++] = mg[idx++];
	}
}

//quick sort
//space complexity: O(1)
//time complexity: O(nlogn) on average time and O(n^2) in worst case
void quitSort(vector<int> & in){
	quitSort(in, 0, in.size()-1);
}

void quitSort(vector<int> & in, int start, int end){
	if(start + 10 >= end)
	{
		return insertionSort(in, start, end);
	}

	int pivot = median(vector<int> & in, start, end);
	int i=start, j=end-1;

	while(i <= j){
		while(in[++i] < pivot){}       
		while(in[--j] > pivot){}
		if(i <= j)
			swap(in[i], in[j]); 
	}

	swap(in[i], in[end-1]);
	quitSort(in, start, i-1);
	quitSort(in, i+1, end);
}

int median(vector<int> & in, int start, int end){
	int middle = start + (end - start)/2;
	if(in[start] > in[middle]){
		swap(in[start], in[middle]);
	}
	if(in[start] > in[end]){
		swap(in[start], in[end]);
	}
	if(in[middle] > in[end]){
		swap(in[middle], in[end]);
	}

	swap(in[middle], in[end-1]);
	return in[end-1];
}

void swap(int & a, int & b){
	int tmp = a;
	a = b;
	b = tmp;
}

void insertionSort(vector<int> & in, int start, int end){
	for(int i = start+1; i <= end; i++){
		int j = i-1;
		int tmp = in[i];
		for(; j >= 0; j--){
			if(in[j] > tmp){
				in[j+1] = in[j];
			}
			else
				break;
		}
		in[j+1] = tmp;
	}
}