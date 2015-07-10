class HashTable
{
public:
	HashTable(int size = 101)
	{
		theLists.resize(size);
		makeEmpty();
	}

	bool contains(const int x) const
	{
		list<int> & curList = theLists[myhash(x)];
		return find(curList.begin(), curList.end(), x) != curList.end();
	}

	bool remove(const int x)
	{
		list<int>¡¡& curList = theLists[myhash(x)];
		list<int>::iterator itr = find(curList.begin(), curList.end(), x);

		if(itr == curList.end())
			return false;
		
		curList.erase(itr);
		currentSize--;
		return true;
	}

	bool insert(const int x)
	{
		list<int> & curList = theLists[myhash(x)];
		list<int>::iterator itr = find(curList.begin(), curList.end(), x);
		
		if(itr == curList.end())
			return false;

		curList.insert(curList.begin(),x);
		currentSize++;
		
		if(currentSize == theLists.size())  //load factor too big..
			rehash();

		return true;
	}

	void makeEmpty()
	{
		for(vector<list<int> >::iterator itr = theLists.begin(); itr != theLists.end(); itr++)
			itr->clear();
		currentSize = 0;
	}

private:
	vector<list<int> > theLists;
	int currentSize;

	void rehash()
	{
		vector<list<int> > oldLists = theLists;
		makeEmpty();
		theLists.resize(nextPrime(2*oldLists.size()));

		for(vecotr<list<int> >::iterator itr = oldLists.begin(); itr != oldLists.end(); itr++)
		{
			for(list<int>::iterator itrIn = itr->begin(); itrIn != itr->end(); itrIn()++)
				insert(*itrIn);
		}
	}

	int myhash(const int key)
	{
		return key % theLists.size();
	}

	int nextPrime(int size)         //I will go back to finish it when I finish reading chapter 4..
	{
		int res;
		return res;
	}

};