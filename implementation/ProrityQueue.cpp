#include <iostream>
using namespace std;

//minimum heap
template <typename ObjectType>
class priorityQueue
{
public:
	priorityQueue(const vector<ObjectType> & obj){
		queue.clear();
		queue.resize(obj.size() + 10);
		numElement = obj.size();
		
		for(int i = numElement/2; i > 0; i--)       //start from queue[1] to queue[numElement]
			queue[i] = obj[i-1];
	}

	priorityQueue(int capacity = 10){
		queue.clear();
		queue.resize(capacity);
		numElement = 0;
	}

	bool isEmpty() const {
		return numElement > 0;
	}

	const ObjectType & findMin() const {
		return queue[numElement];
	}

	void insert(ObjectType obj)
	{
		if(++numElement >= queue.size())
			queue.resize(2 * queue.size());
		queue[numElement] = obj;
		percolateUp(numElement);
	}

	void deleteMin()
	{
		if(isEmpty())
			return;

		queue[1] = queue[numElement--];
		percolateDown(1);
	}

	void deleteMin(ObjectType & tar)
	{
		if(isEmpty())
			return;

		tar = queue[1];
		queue[1] = queue[numElement--];
		percolateDown(1);
	}

	void decreaseKey(int pos, int delta){
		if(pos <= 0 || delta <= 0)
			return;
		queue[pos] -= delta;          //ObjectType should define operation '-'
		percolateUp(pos);
	}

	void increaseKey(int pos, int delta){
		if(pos <= 0 || delta <= 0)
			return;
		queue[pos] += delta;         //ObjectType should define operation '+'
		percolateDown(pos);
	}

	void remove(int pos){
		decreaseKey(pos, INT_MAX);
		deleteMin();
	}

private:
	vector<ObjectType> queue;
	int numElement;

	void buildHeap(){
		for(int i = numElement/2; i > 0; i--)       
			percolateDown(i);
	}

	void percolateDown(int i){
		int father = i;
		int child = 2 * i;
		ObjectType tar = queue[i];

		for( ; child <= numElement; father = child){
			child = 2 * father;
			if(child < numElement && queue[child] > queue[child + 1])
				child++;
			if(queue[child] < tar)
				queue[father] = queue[child];
			else
				break;
		}

		queue[father] = tar;
	}

	void percolateUp(int i){
		int child = i;
		int father = i/2;
		queue[0] = queue[i];

		for( ; child > 0; child = father){
			father = child / 2;
			if(queue[father] > queue[0])
				queue[child] = queue[father];
			else
				break;
		}
		queue[child] = queue[0];
	}
}