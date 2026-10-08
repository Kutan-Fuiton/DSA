// Trie Data Structure

// different names exists:- Prefix tree, digital search tree, and its famous name is retrieval tree
// Retrieval tree ==> Re`trie`val tree, the word trie came from there, this trie DS is used to retrieve data.

// For example:- largest common prefix in two strings. example:- "there" and "their", here largest common prefix is "the"



// What is a Trie?

// For example:- we take a string array 
// words[] = {"the", "a", "there", "their", "any"};

// Now we know the tree which have at most 2 childrens are called binary tree, but if a tree have more than 2 childrens, like lets say it have k childrens, each parent have k childrens, then we will called that tree as `k-ary tree`
// Trie is a k-ary tree.

// In BST, in worst case, skewed BST is the worst case bst, where time complexity becomes O(h), h -> height of the tree and h == n, so it becomes O(n).
// but in case of AVL, which is a balanced AVL tree, and its time complexity always be O(logn)

// but in case of trie, we get more better time complexity, its time complexity is O(L), where L is the length of the word
// so in searching any words, we use trie data structure cuzz that is always preferred than any other tree structure

// trie features notes:- 
// 1. fast search words  
// 2. root is an empty node
// 3. prefix is not repeated

// words[] = {"the", "a", "there", "their", "any"};

//                      empty node
//                      /        \    
//                     /          \
//                   't'          'a'(eow)  
//                   /              \
//                  /                \ 
//                'h'                'n'
//                /                    \
//               /                      \
//        (eow)'e'                      'y' (eow) 
//             / \      
//            /   \
//          'r'   'i'
//          /       \ 
//         /         \
//  (eow)'e'         'r'(eow)


// Process:-
// i> first traverse each words, so lets say first word is "the", so will traverse each characters, and will connect to the previous words as parent, like see, t is connected to empty node, h is connected to t, and e is connected to h, will put end of word (eow) to it. 
// ii> now for next word check whether the first letter of that word is already present on very first children of empty node or not, we will not store the prefix again, as the word is "a", and its first letter is 'a'. and its not in the children of root, so will put another children as 'a' and mark (eow).
// iii> now for next word, "there", as you can see, 't' is in children of root, now see 'h' is there in children of 't' or not, i can see there it is, upto "the", there it is, now, we get new letters 'r' and 'e', so what will do is will simply connect r to the last node that ended which was e and last e will connect to r
// iv> next "their", after covering the will make another children of i and then r
// v> next "any", after a will make another children n and then y




