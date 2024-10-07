#ifndef _Trie_20241001_
#define _Trie_20241001_
#include<bits/stdc++.h>

class trie{
	std::unordered_map<char,trie*> next;
	bool isEnd=false;
	size_t count=0;
public:
	bool insert(const std::string& str){
		trie* node=this;
		std::vector<trie*> update_nodes;
		update_nodes.reserve(str.size());
		for(char c:str){
			if(!node->next.count(c))node->next[c]=new trie();
			node=node->next[c];
			update_nodes.push_back(node);
		}
		if(!node->isEnd){
			node->isEnd=true;
			count++;
			for(trie* update_node:update_nodes)update_node->count++;
			return true;
		}
		return false;
	}
	bool contain(const std::string& str){
		trie* node=this;
		for(char c:str){
			if(!node->next.count(c))return false;
			node=node->next[c];
		}
		return node->isEnd;
	}
	size_t prefix_count(const std::string& str){
		trie* node=this;
		for(char c:str){
			if(!node->next.count(c))return 0;
			node=node->next[c];
		}
		return node->count;
	}
	~trie(){
		for(auto& p:next)delete p.second;
	}
};

#endif

