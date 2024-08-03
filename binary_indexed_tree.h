
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
	binary_indexed_tree(const size_t len){
		tree=std::vector<T>(len+1);
	}
	
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
	
	inline T sum(const size_t l,const size_t r){
		return sum(r-1)-sum(l-1);
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


