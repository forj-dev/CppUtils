
#ifndef _Disjoint_Set_
#define _Disjoint_Set_

#include<bits/stdc++.h>

class Disjoint_Set{
private:
	std::vector<size_t> fa;
public:
	Disjoint_Set(size_t size){
		fa=std::vector<size_t>(size);
		for(size_t i=0;i<size;i++)
			fa[i]=i;
	}
	
	size_t getFather(size_t node){
		if(fa[node]==node)
			return node;
		return fa[node]=getFather(fa[node]);
	}
	
	bool merge(size_t a,size_t b){
		size_t f_a=getFather(a);
		size_t f_b=getFather(b);
		if(f_a==f_b)
			return false;
		fa[f_a]=f_b;
		return true;
	}
	
	inline bool query(size_t a,size_t b){
		return getFather(a)==getFather(b);
	}
};

#endif

