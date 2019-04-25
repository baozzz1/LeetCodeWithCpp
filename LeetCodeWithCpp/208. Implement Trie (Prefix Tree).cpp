// Easy, Medium or Hard
// 
#include"ListNode.h"
#include"TreeNode.h"
#include"Interval.h"
class Trie {
	class TrieNode {
	public:
		vector<TrieNode*> ch;
		bool endHere;
		TrieNode() :ch(vector<TrieNode*>(26, nullptr)), endHere(false) {}
	};
	TrieNode* root;
public:
	/** Initialize your data structure here. */
	Trie() :root(new TrieNode()) {

	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		auto ptr = root;
		for (auto &c : word) {
			auto &hasChar = ptr->ch[c - '0'];
			if (hasChar == nullptr) {
				hasChar = new TrieNode();
			}
			ptr = hasChar;
		}
		ptr->endHere = true;
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		return search(word, 0, root, false);
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		return search(prefix, 0, root, true);
	}
private:
	bool search(const string &word, int index, TrieNode *ptr, const bool &isStartsWith) {
		if (ptr == nullptr)
			return false;
		if (index == word.length())
			return ptr->endHere || isStartsWith;
		if (word[index] == '.') {
			for (int i = 0; i < 26; i++) {
				if (search(word, index + 1, ptr->ch[word[index] - 'a'], isStartsWith))
					return true;
			}
			return false;
		}
		else
			return search(word, index + 1, ptr->ch[word[index] - 'a'], isStartsWith);
	}
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
