#include <algorithm>
template <typename Object>

class List
{
  private:
    struct Node{};          //declaration ??
  public:
    class const_iterator
    {};
    class iterator: public const_iterator
    {};
  public:                   //functions  
    List()
    {
      init();
    }
    
    List(const List & rhs)
    {
      init();
      for(List<Object>::iterator iter = rhs.begin(); iter != rhs.end(); iter++)
        push_back(*iter);
    }
    
    ~List()
    {
      clear();
      delete head;
      delete tail;
    }
    
    List & operator= (const List & rhs)
    {
      List copy = rhs;
      std::swap(*this, copy);
      return *this;                        // copy will be destructed when this function is completed
    }
    
    List operator= (List && rhs)
    {
      std::swap(theSize, rhs.theSize);
      std::swap(head, rhs.head);
      std::swap(tail, rhs.tail);
      
      return *this;
    }
    
    List(List && rhs): theSize{rhs.theSize}, head{rhs.head}, tail{rhs.tail}
    {
      rhs.theSize = 0;
      rhs.head = nullptr;                      //when this function is completed, rhs should be destructed. Wouldn't this cause the memory leak?? The original memory of this->head is not delete??
      rhs.tail = nullptr;
    }
    
    iterator begin()
    {
      return iterator{*this, head->next};      //if the List is empty, pointer to tail would be returned
    }
    
    const_iterator begin() const
    {
      return const_iterator{*this, head->next}；
    }
    
    iterator end()
    {
      iterator itr
      return iterator{*this, tail};
    }
    
    const_iterator end() const
    {
      return const_iterator{*this, tail};
    }
    
    int size() const
    {
      return theSize;
    }
    
    bool empty() const
    {
      return size() == 0;
    }
    
    void clear()
    {
      while(!empty())
        pop_front();
    }
    
    Object & front()
    {
      if(empty())
        throw ListEmptyException{};
      return *begin();
    }
    
    const Object & front() const
    {
      if(empty())
        throw ListEmptyException{};
      return *begin();
    }
    
    Object & back()
    {
      if(empty())
        throw ListEmptyException{};
      return *--end();        
    }
    
    const Object & back() const
    {
      if(empty())
        throw ListEmptyException{}; 
      return *--end();
    }
    
    void push_front(const Object & x)
    {
      insert(begin(), x);
    }
    
    void push_front(Object && x)
    {
      insert(begin(), std::move(x));
    }
    
    void push_back(const Object & x)
    {
      insert(end(), x);
    }
    
    void push_back(Object && x)
    {
      insert(end(), std::move(x));
    }
    
    void pop_front()
    {
      erase(begin());
    }
    
    void pop_back()
    {
      erase(--end());
    }
    
    iterator insert(iterator itr, const Object & x)        //insert x before itr
    {
      its.assertIsValid();
      if(itr.theList != this)
        throw IteratorMismatchException{};
        
      Node * p = itr.current;
      theSize++;
      return {p->prev = p->prev->next = new Node(x, p->prev, p)};
    }
    
    iterator insert(iterator iter, Object && x)
    {
      its.assertIsValid();
      if(itr.theList != this)
        throw IteratorMismatchException{};
        
      Node * p = itr.current;             //since List is a frient of iterator, so current can be obtained here
      theSize++;
      return {p->prev = p->prev->next = new Node(std::move(x), p->prev, p)};
    }
    
    iterator erase(iterator itr)
    {
      its.eraseIsValid();
      if(itr.theList != this)
        throw IteratorMismatchException{};
        
      Node * p = itr.current; 
      iterator retVal{p->next};
      p->prev->next = p->next;
      p->next-prev = p->prev;
      delete p;
      theSize--;
      return retVal;
    }
    
    iterator erase(iterator from, iterator to)
    {
      for(iterator itr = from; itr != to; )
        itr = erase(itr);
        
      return itr;
    }
    
  private:
    int theSize;
    Node * head;
    Node * tail;
    
    void init()
    {
      theSize = 0;
      head = new Node;
      tail = new Node;
      head->next = tail;
      tail->prev = head;
    }
};

struct Node
{
  Object data;
  Node * prev;
  Node * next;
  
  Node(const Object & d = Object(), Node * p = nullptr, Node * n = nullptr): data{d}, prev{p}, next{n}
  {}
  Node(Object && d, Node * p = nullptr, Node * n = nullptr): data{std::move(d)}, prev{p}, next{n}
  {}
};                        //not forget the ';'

class const_iterator
{
  public:
    const_iterator(): current{nullptr}, theList{nullptr}
    {}
    
    const Object & operator* () const
    {
      return retrieve();
    }
    
    const_iterator & operator++ ()
    {
      current = current->next;
      return * this;
    }
    
    const_iterator operator++(int)       // no &
    {
      const_iterator old = *this;
      ++(*this);
      return old;
    }
    
    bool operator== (const_iterator & rhs) const
    {
      return current == rhs.current;
    }
    
    bool operator!= (const_iterator & rhs) const
    {
      return !(*this == rhs);    //why not wrriten as {return current != rhs.current} ?...
    }
    
  protected:                            //This is defined as protected to do inheritance of iterator and also to protect its member
    Node * current;
    List<Object> * theList;
    
    Object & retrieve() const
    {
      return current->data;
    }
    
    const_iterator(const List<Object> & lst, Node * p): theList{&lst}, current{p}
    {}
    
    void assertIsValid()
    {
      if(theList == nullptr || current == nullptr || current == theList->head)     //current == theList->tail is right since it can point to the next of the last node  
        throw IteratorOutOfBandsException{};   // should this be further defined? not familiar with C++
    }
    
    void eraseIsValid()
    {
      if(theList == nullptr || current == nullptr || current == theList->head || current == theList->tail)
        throw EraseOutOfBandsException{}; 
    }
    
    friend class List<Object>;           //List can access any member in const_iterator
}; 

class iterator: public const_iterator
{
  public:
    iterator()
    {}
    
    Object & operator* ()
    {
      return const_iterator::retrieve();
    }
    
    const Object & operator* () const
    {
      return const_iterator::operator*();
    }
    
    iterator & operator++ ()           // new implementation should be provided since the return type is changed, compared with overload of operator ++
    {
      this->current = this->current->next;
      return *this;
    }
    
    iterator operator++ (int)
    {
      iterator old = *this;
      ++(*this);
      return old;
    }
    
  protected:
    iterator(const List<Object> & lst, Node * p):const_iterator{lst, p}
    {}
    friend class List<Object>;
};
