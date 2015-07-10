enum InfoStatus{EMPTY, ACTIVE, DELETED};

struct HashInfo
{
	int val;
	InfoStatus info;
};

class HashTable
{
public:
	HashTable(int size = 101)
	{
		arr.resize(nextPrime(size));
		makeEmpty();
	}

	bool contains(const int x) const
	{
		int pos = findPos(x);
		return arr[pos].val == x && arr[pos].info == ACTIVE;
	}

	bool remove(const int x)
	{
		int pos = findPos(x);
		if(arr[pos].info != ACTIVE)
			return false;
	
		arr[pos].info == DELETED;    //don't need to do currentSize--;
		return true;
	}

	bool insert(const int x)
	{
		int pos = findPos(x);
		if(arr[pos].info == ACTIVE)
			return false;
		
		arr[pos].val = x;
		arr[pos].info = ACTIVE;

		if(++currentSize >= arr.size()/2)  //load factor too big..
			rehash();

		return true;
	}

	void makeEmpty()
	{
		for(vector<HashInfo>::iterator itr = arr.begin(); itr != arr.end(); itr++)
			itr->info = EMPTY;
		currentSize = 0;
	}

private:
	vector<HashInfo> arr;
	int currentSize;

	void rehash()
	{
		vector<HashInfo> oldArr = arr;
		makeEmpty();
		arr.resize(oldArr.size()*2);

		for(vector<HashInfo>::iterator itr = oldArr.begin(); itr != oldArr.end(); itr++)
		{
			if(itr->info == ACTIVE)       //this condition must be added! 
				insert(itr->val);
		}
	}
	int myhash(const int key)
	{
		return key % currentSize;
	}

	int nextPrime(int size)         //I will go back to finish it when I finish reading chapter 4..
	{
		int res;
		return res;
	}

	int findPos(int x) const
	{
		int offset = 1;
		int curPos = myhash(x);

		while(arr[curPos].val != x && arr[curPos].info != EMPTY)
		{
			curPos -= (offset-1)*(offset-1);
			curPos += offset*offset;
			offset++;;
			if(curPos >= arr.size())
				curPos -= arr.size();
		}

		return curPos;
	}
};