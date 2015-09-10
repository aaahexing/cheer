/******************
Add and Search Word - Data structure design : https://leetcode.com/problems/add-and-search-word-data-structure-design/

Design a data structure that supports the following two operations: 
void addWord(word)
bool search(word)

search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.
For example:
addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
**/

class trieNode {
public:
    trieNode * child;
    trieNode * nextSibling;
    char val;
    bool isFullWord;
    trieNode() {
        child = nextSibling = NULL;
        isFullWord = false;
    }
};

//time complexity: O(n) for addWord function and search function
//time limit exceeded ??? why????
class WordDictionary {
private: 
    trieNode * root;
public:
    WordDictionary() {
        root = new trieNode();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        trieNode * curNode = root;
        trieNode * childNode;
        for (int i = 0; i < word.size(); i++) {
            childNode = curNode->child;
            if (!childNode) {
                curNode->child = new trieNode();
                curNode->child->val = word[i];
                curNode = curNode->child;
                continue;
            }
            while (childNode->nextSibling) {
                if (childNode->val == word[i]) {
                    curNode = childNode;
                    continue;
                }
                childNode = childNode->nextSibling;
            }
            if (childNode->val == word[i]) {
                curNode = childNode;
                continue;
            }
            childNode->nextSibling = new trieNode();
            childNode->nextSibling->val = word[i];
            curNode = childNode->nextSibling;
        }
        curNode->isFullWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        if (word.size() <= 0) {
            return false;
        }
        return search(word, root);
    }
    
    bool search(string word, trieNode * root) {
        trieNode * curNode = root;
        for (int i = 0; i < word.size(); i++) {
            bool ret = false;
            trieNode * childNode;
            if (word[i] == '.') {
                childNode = curNode->child;
                while(childNode) {
                    if (i == word.size() -1) {
                        if (childNode->isFullWord) {
                            return true;
                        }
                    } else {
                        ret = ret || search(word.substr(i + 1), childNode);
                        if (ret) {
                            return true;
                        }
                    }
                    childNode = childNode->nextSibling;
                }
                return false;
            } else {
                childNode = curNode->child;
                while (childNode) {
                    if (childNode->val == word[i]) {
                        curNode = childNode;
                        break;
                    }
                    childNode = childNode->nextSibling;
                }
                if (!childNode) {
                    return false;
                }
            }
        }
        return curNode->isFullWord;
    }
};