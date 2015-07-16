//definition of class Vector

#include <algorith>

template<typename object>
class Vector{
  public:
    explict Vecotr(int initSize = 0): theSize{initSize}, theCapacity{initSize + SPARE_CAPACITY}  //new feature in C++11, using {} to assignment
    {
      objects = new Object[theCapacity];
    }
    
    Vector(const Vector & rhs): theSize{rhs.theSize}, theCapacity{rhs.theCapacity}, objects{nullptr}  //why should the objects be initilized as null? 
    {
      objects = new Object[theCapacity];
      for(int i=0; i<theSize; i++)
        objects[i] = rhs.objects[i];
    }
    
    Vector & operator= (const Vecotr & rhs)
    {
      Vector copy = rhs;    //should check further which functions are called when doing this copy constructor
      std::swap(*this, copy);
      return *this;
    }
    
    ~Vector()
    {
      delete [] objects;
    }
    
    Vector(Vector && rhs): theSize{rhs.theSize}, theCapacity{rhs.theCapacity}, objects{rhs.objects}
    {
      rhs.theSize = 0;
      rhs.theCapacity = 0;
      rhs.objects = nullptr;  // since rhs.objects is assigned to objects, rhs.objects can be assigned as nullptr
    }
    
    Vector & operator= (Vector && rhs)       
    {
    //since rhs is a temporary Vector, it will be destructed when this operator is done, so, when doing swapping, the space of original objects will be reclaimed.
      std::swap(theSize, rhs.theSize);
      std::swap(theCapacity, rhs.theCapacity);
      std::swap(objects, rhs.objects);     
      
      // this function can be realized by the following noted codes?? As I think swaping objects and rhs.objects is the key point of this function. Assignment of rhs.theSize and rhs.theCapacity can be done by either swap or move or assignment statement. 
      //theSize = rhs.theSize;
      //theCapacity = rhs.theCapacity;
      //std::swap(objects, rhs.objects);
      
      return *this;
    }
    
    void resize(int newSize)
    {
      if(newSize > theCapacity)
        reserve(newSize * 2);
      theSize = newSize;
    }
    
    void reserve(int newCapacity)
    {
      if(newCapacity < theSize)
        return;
        
      Object * newArray = new Object[newCapacity];
      for(int i=0; i<theSize; i++)
        newArray[i] = std::move(objects[i]);  //why use move function? not directly assignment?? check move function further..
      
      theCapacity = newCapacity;
      std::swap(objects, newArray);
      delete [] newArray;            //since objects and newArray is swapped, this reclaimed the original space
    }
    
    Object & operator[] (int index)
    {
      return objects[index];        //no error check is done?? why??
    }
    
    const Object & operator[] (int index) const
    {
      return objects[index];
    }
    
    bool empty() const
    {
      return size() == 0; 
    }
    
    int size() const
    {
      return theSize;
    }
    
    int capacity() const
    {
      return theCapacity;
    }
    
    void push_back(Object & x)
    {
      if(theSize == theCapacity)
        reserve(theCapacity * 2 + 1);  // in case of theCapacity is equal to 0
      objects[theSize++] = x;
    }
    
    void push_back(Object && x)
    {
      if(theSize == theCapacity)
        reserve(theCapacity * 2 + 1);
      objects[theSize++] = std::move(x);  //maybe std::move is used for temporary variables? check this function further...
    }
    
    void pop_back()
    {
      theSize--;                 //still not check the size, if size equal to 0? why not? not necessary? 
    }
    
    const Object & back() const
    {
      return objects[theSize-1];
    }
    
    typedef Object * iterator;
    typedef const Object * const_iterator;         //the object const_iterator pointing to is const
    
    iterator begin()
    {
      return &objects[0];
    }
    
    const_iterator begin() const
    {
      return &objects[0];
    }
    
    iterator end()
    {
      return &objects[size()];
    }
    
    const_iterator end() const
    {
      return &objects[size()];
    }
    
    static const int SPARE_CAPACITY = 16;
    
  private:
    int theSize;
    int theCapacity;
    Object * objects;
}
