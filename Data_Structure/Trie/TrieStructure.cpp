#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// As Trie data structure is k-ary data structure
// and here we storing characters, so maximum no of unique characters that can be possible in one level is 26, so for that, each node will atmost have 26 nodes

class TrieNode {
public:
    char data;
    TrieNode* children[26];
    bool endOfWord;

    TrieNode(char ch) {
        data = ch;
        for (int i = 0; i < 26; i++){
            children[i] = NULL;
        }
        endOfWord = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }


    // Time complexity:- O(l)
    // recursive insert utility function
    void insertUtil(TrieNode* root, string word){
        // base case
        if (word.size() == 0){
            root->endOfWord = true;
            return ;
        }
        
        // assumption: word will be in CAPS
        int index = word[0] - 'A';
        TrieNode* child;
        
        // present
        if (root -> children[index] != NULL) child = root->children[index];
        // absent
        else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        
        // Recursion
        insertUtil(child, word.substr(1));
    }
    
    // Insertion
    void insertWord(string word){
        insertUtil(root, word);
    }
    
    
    // Time complexity:- O(l)
    // Similarly, recursive search utility function
    bool searchUtil(TrieNode* root, string word){
        //base case
        if (word.size() == 0){
            return root->endOfWord;
        }

        // assumption: word will be in CAPS
        int index = word[0] - 'A';
        TrieNode* child;

        //present
        if (root->children[index] != NULL) child = root->children[index];
        //absent
        else return false;

        //RECURSION
        return searchUtil(child, word.substr(1));
    }

    // Searching
    bool searchWord(string word){
        return searchUtil(root, word);
    }
    
    
    // Time complexity:- O(l)
    // Similarly, recursive search utility function
    void removeUtil(TrieNode* root, string word){
        //base case
        if (word.size() == 0){
            root->endOfWord = false; // delete node by marking the last node of the word as endOfWord false
            return ;
        }

        int index = word[0] - 'A';
        TrieNode* child = root->children[index];

        if (root->children[index] == NULL) return ;

        removeUtil(child, word.substr(1));
    }

    void removeUtilSpaceOptimised(TrieNode* root, string word){
        // base case
        if (word.size() == 0){
            root->endOfWord = false;
            return ;
        }

        int index = word[0] - 'A';

        // No word like that exists in the trie
        if (root->children[index] == NULL) return;

        TrieNode* child = root->children[index];

        // Go down
        removeUtilSpaceOptimised(child, word.substr(1));

        // Coming back up
        if (child->endOfWord == false){
            bool hasChildren = false;

            for (int i = 0; i < 26; i++){
                if (child->children[i] != NULL){
                    hasChildren = true;
                    break;
                }
            }

            if (!hasChildren) {
                delete child;
                root->children[index] = NULL;
            }
        }
    }

    // Removing
    void removeWord(string word, bool spaceOptimisation = false){
        if (spaceOptimisation) removeUtilSpaceOptimised(root, word);
        else removeUtil(root, word);
    }
};

int main(){
    Trie* t = new Trie();

    t->insertWord("ARM");
    t->insertWord("DO");
    t->insertWord("TIME");
    cout << "Present or not: " << t->searchWord("DO") << endl;
    t->removeWord("DO", true);
    cout << "Present or not: " << t->searchWord("DO") << endl;

    return 0;
}