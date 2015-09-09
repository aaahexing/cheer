/********************
Implement Trie (Prefix Tree) : https://leetcode.com/problems/implement-trie-prefix-tree/

Implement a trie with insert, search, and startsWith methods. 

Note:
You may assume that all inputs are consist of lowercase letters a-z. 
**/

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        child = nextSibling = NULL;
        fullWord = false;
    }
    TrieNode * child;
    TrieNode * nextSibling;
    char val;
    bool fullWord;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
	// time complexity: O(n)
    void insert(string word) {
        TrieNode * curNode = root;
        for (int i = 0; i < word.size(); i++) {
            if (curNode->child == NULL) {
                TrieNode * tmp = new TrieNode();
                tmp->val = word[i];
                if (i == word.size() -1) {
                    tmp->fullWord = true;
                }
                curNode->child = tmp;
                curNode = curNode->child;
            } else {
                TrieNode * child = curNode->child;
                int flag = 0;
                while (child->nextSibling) {
                    if (child->val == word[i]) {
                        flag = 1;
                        if (i == word.size() -1) {
                            child->fullWord = true;
                        }
                        break;
                    }
                    child = child->nextSibling;
                }
                
                if (!flag) {
                    if (child->val != word[i]) {
                        TrieNode * tmp = new TrieNode();
                        tmp->val = word[i];
                        child->nextSibling = tmp;
                        child = child->nextSibling;
                    }
                    if (i == word.size() -1) {
                        child->fullWord = true;
                    }
                }
                curNode = child;
            }
        }
    }

    // Returns if the word is in the trie.
	// time complexity: O(n)
    bool search(string word) {
        TrieNode * curNode = root->child;
        for (int i = 0; i < word.size(); i++) {
            while (curNode) {
                if (curNode->val == word[i]) {
                    break;
                }
                curNode = curNode->nextSibling;
            }
            
            if (curNode) {
                if (i != word.size() -1) {
                    curNode = curNode->child;
                } else {
                    if (curNode->fullWord) {
                        return true;
                    } else {
						return false;
					}
                }
            } else {
                return false;
            }
        }
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
	// time complexity: O(n)
    bool startsWith(string prefix) {
        TrieNode * curNode = root->child;
        for (int i = 0; i < prefix.size(); i++) {
            while (curNode) {
                if (curNode->val == prefix[i]) {
                    break;
                }
                curNode = curNode->nextSibling;
            }
            
            if (curNode) {
                if (i != prefix.size() -1) {
                    curNode = curNode->child;
                } else {
                    return true;
                }
            } else {
                return false;
            }
        }
    }

private:
    TrieNode* root;
};