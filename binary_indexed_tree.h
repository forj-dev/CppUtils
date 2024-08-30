
#ifndef _binary_indexed_tree
#define _binary_indexed_tree

#include<bits/stdc++.h>


#define BIT binary_indexed_tree


template<typename T>
class binary_indexed_tree{

private:
	std::vector<T> tree;
	
	inline static size_t lowbit(const size_t x){
		return x&(-x);
	}

public:
	binary_indexed_tree(size_t len){
		tree=std::vector<T>(len+1);
	}
	
	binary_indexed_tree()=default;
	
	void update(size_t index,const T& offset){
		++index;
		while(index<tree.size()){
			tree[index]+=offset;
			index+=lowbit(index);
		}
	}
	
	T sum(size_t index){
		++index;
		T result=0;
		while(index){
			result+=tree[index];
			index-=lowbit(index);
		}
		return result;
	}
	
	/*[l,r]*/
	inline T sum(const size_t l,const size_t r){
		return sum(r)-sum(l-1);
	}
	
	binary_indexed_tree& operator=(const binary_indexed_tree& other){
		if(this!=&other){
			tree=other.tree;
		}
		return *this;
	}
};


#define SBIT section_binary_indexed_tree


template<typename T>
class section_binary_indexed_tree{
private:
	size_t len;
	binary_indexed_tree<T> base_tree;
	binary_indexed_tree<T> base_tree_id_mul;
public:
	section_binary_indexed_tree(size_t _len){
		len=_len;
		base_tree=binary_indexed_tree<T>(len);
		base_tree_id_mul=binary_indexed_tree<T>(len);
	}
	
	/*[l,r]*/
	void update(size_t left,size_t right,const T& offset){
		base_tree.update(left,offset);
		base_tree_id_mul.update(left,offset*(left+1));
		if(right+1<len){
			base_tree.update(right+1,-offset);
			base_tree_id_mul.update(right+1,-offset*(right+2));
		}
	}
	
	inline void update(size_t index,const T& offset){
		update(index,index,offset);
	}
	
	inline T sum(size_t index){
		return (index+2)*base_tree.sum(index)-base_tree_id_mul.sum(index);
	}
	
	/*[l,r]*/
	inline T sum(size_t l,size_t r){
		return sum(r)-sum(l-1);
	}
	
	inline T get(size_t index){
		return sum(index,index);
	}
	
	section_binary_indexed_tree& operator=(const section_binary_indexed_tree& other){
		if(this!=&other){
			len=other.len;
			base_tree=other.base_tree;
			base_tree_id_mul=other.base_tree_id_mul;
		}
		return *this;
	}
};

#endif



#ifndef _discretize_
#define _discretize_


template<typename T>
std::vector<size_t> discretize(const std::vector<T>& nums){
	size_t n=nums.size();
	if(n==0){
		return std::vector<size_t>();
	}
    std::vector<std::pair<T,size_t>> to_sort(n);
    for(size_t i=0;i<n;i++){
    	to_sort[i]=std::make_pair(nums[i],i);
	}
	std::sort(to_sort.begin(),to_sort.end());
	std::vector<size_t> res(n);
	res[0]=0;
	size_t c=0;
    for(size_t i=1;i<n;i++){
        if(to_sort[i].first!=to_sort[i-1].first)++c;
        res[to_sort[i].second]=c;
    }
    return res;
}

#endif


