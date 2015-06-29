#include <algorithm>
using namespace std;

template <typename Comparable>
class BinarySearchTree
{
  public:
    BinarySearchTree();
    BinarySearchTree(const BinarySearchTree & rhs);
    BinarySearchTree(BinarySearchTree && rhs);
    ~BinarySearchTree();
    
    const Comparable & findMax() const;
    const Comparable & findMin() const;
    bool Contains(const Comparable & x) const;
    bool isEmpty() const;
    
    void makeEmpty();
    void insert(const Comparable & x);
    void insert(Comparable && x);
    void remove(const Comparable & x);
    
    BinarySearchTree & operator= (const BinarSearchTree & rhs);
    BinarySearchTree & operator= (BinarySearchTree && rhs);
    
  private:
    struct BinaryNode
    {
      Comparable element;
      BinaryNode * left;
      BinaryNode * right;
      
      BinaryNode(const Comparable & theElement = Comparable(), BinaryNode * l = nullptr, BinaryNode * r = nullptr): element{theElement}, left{l}, right{r}
      {}
      BinaryNode(Comparable && theElement, BinaryNode * l = nullptr, BinaryTree * r = nullptr): element{std::move(theElement)}, left{l}, right{r}
      {}
    }
    
    BinaryNode * root;
    
    BinaryNode * findMax(BinaryNode * t) const;
    bool Contains(const Comaprable & x, BinaryNode * t) cosnt;
    void makeEmpty(BinaryNode *& t);
    BinaryNode * clone(BinaryNode * t);
    void insert(const Comparable & x, BinaryNode *& t);
    void insert(Comparable && x, BinaryNode *& t);
    void remove(const Comparable & x, BinaryNode *& t);
}

BinarySearchTree::BinarySearchTree()
{
  root = nullptr;
}

BinarySearchTree::BinarySearchTree(const BinarySearchTree & rhs)
{
  root = clone(rhs.root);
}

BinarySearchTree::BinarySearchTree(BinarySearchTree && rhs)
{
  root = clone(rhs.root);
}

BinarySearchTree::~BinarySearchTree()
{
  makeEmpty();
}

BinarySearchTree & BinarySearchTree::operator= (const BinarySearchTree & rhs)
{
  BinarySearchTree copy = rhs;
  std::swap(*this, copy);
  return *this;
}

BinarySearchTree & BinarySearchTree::operator= (BinarySearchTree && rhs)
{
  std::swap(this->root, rhs.root);
}

const Comparable & BinarySearchTree::findMax() const
{
  if(root == nullptr)             // consider the empty binarySearchTree
    return nullptr;
  BinaryNode * temp = root;
  while(temp->right)
  {
    temp = temp->right;
  }
  return temp->element;
}

//other Implementation of findMax()
// const Comparable & BinarySearchTree::findMax() const
// {
//    BinaryNode * temp = findMax(root);
//    if(temp == nullptr)
//      return nullptr;
//    else
//      return temp->element;
// }
  
  BinaryNode * BinarySearchTree::findMax(BinaryNode * t) const
  {
    if(t == nullptr)
      return nullptr;
    if(t->right == nullptr)
      return t;
    else
      return findMax(t->right);
  }
  
  const Comparable & BinarySearchTree::findMin() const
  {
    if(root == nullptr)             // consider the empty binarySearchTree
      return nullptr;
    BinaryNode * temp = root;
    while(temp->left)
    {
      temp = temp->left;
    }
    return temp->element;
  }
  
  bool BinarySearchTree::Contains(const Comparable & x) const
  {
    return Contains(x, root);
  }
  
  bool BinarySearchTree::Contains(const Comaprable & x, BinaryNode * t) cosnt
  {
    if(t == nullptr)
      return false;
    if(x < t->element)
      return Contains(x, t->left);
    else if(x > t->element)
      return Contains(x, t->right);
    else
      return true;
  }
  
  bool BinarySearchTree::isEmpty() const
  {
    return root == nullptr ? true : false;
  }
  
  void BinarySearchTree::makeEmpty()
  {
    makeEmpty(root);
  }
  
  void BinarySearchTree::makeEmpty(BinaryNode *& t)
  {
    if(t == nullptr)
      return;
    
    makeEmpty(t->left);
    makeEmpty(t->right);
    delete t;
    t = nullptr;
  }
  
  void BinarySearchTree::insert(const Comparable & x)
  {
    insert(x, root);
  }
  
  void BinarySearchTree::insert(Comparable && x)
  {
    insert(std::move(x), root);
  }
  
  void BinarySearchTree::remove(const Comparable & x)
  {
    remove(x, root);
  }
  
  BinaryNode * BinarySearchTree::clone(BinaryNode * t)
  {
    if(t == nullptr)
      return nullptr;
    return new BinaryNode(t->element, clone(t->left), clone(t->right));
  }
  
  void BinarySearchTree::insert(const Comparable & x, BinaryNode *& t)
  {
    if(t == nullptr)
      t = new BinaryNode(x);
    if(x < t->element)
      insert(x, t->left);
    else if(x > t->element)
      insert(x, t->right);
    else
      return;
  }
  
  void BinarySearchTree::insert(Comparable && x, BinaryNode *& t)
  {
    if(t == nullptr)
      t = new BinaryNode(std::move(x));
    if(x < t->element)
      insert(std::move(x), t->left);
    else if(x > t->element)
      insert(std::move(x), t->right);
    else
      return;
  }
  
  void BinarySearchTree::remove(const Comparable & x, BinaryNode *& t)
  {
    if(t == nullptr)
      return
    if(x < t->element)
      remove(x, t->left);
    else if(x > t->element)
      remove(x, t->right);
    else
    {
      if(t->left == nullptr && t->right == nullptr)
      {
        delete t;
        t = nullptr;
      }
      else if(t->left == nullptr || t->right == nullptr)
      {
        BinaryNode * temp = t;
        t = t->left == nullptr ? t->right : t->left;
        delete temp;
      }
      else
      {
        t->element = findMax(t->left)->element;
        remove(t->element, t->left);
      }
    }
  }
