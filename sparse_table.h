#ifndef _Sparse_Table_
#define _Sparse_Table_

#include<bits/stdc++.h>

template<typename T>
class sparse_table{
	std::function<T(T,T)> op;
	T *st;
	size_t *log_id;
	size_t len,vlen;
	inline size_t id(size_t l,size_t v)const{
		return l+v*len;
	}
	void make_log(size_t n){
		log_id=(size_t*)malloc(sizeof(size_t)*(n+1));
		log_id[0]=log_id[1]=0;
		for(size_t i=2;i<=n;i++){
			log_id[i]=log_id[i>>1]+1;
		}
	}
public:
	sparse_table(std::function<T(T,T)> _operator,size_t _len,T *arr):op(_operator){
		len=_len;
		make_log(len);
		vlen=log_id[len]+1;
		st=(T*)malloc(sizeof(T)*len*vlen);
		for(size_t i=0;i<len;i++)st[i]=arr[i];
		for(size_t j=1;j<vlen;j++){
			for(size_t i=0;i<len-(1<<j)+1;i++){
				st[id(i,j)]=op(st[id(i,j-1)],st[id(i+(1<<(j-1)),j-1)]);
			}
		}
	}
	sparse_table(std::function<T(T,T)> _operator,const std::vector<T> &arr):op(_operator){
		len=arr.size();
		make_log(len);
		vlen=log_id[len]+1;
		st=(T*)malloc(sizeof(T)*len*vlen);
		for(size_t i=0;i<len;i++)st[i]=arr[i];
		for(size_t j=1;j<vlen;j++){
			for(size_t i=0;i<len-(1<<j)+1;i++){
				st[id(i,j)]=op(st[id(i,j-1)],st[id(i+(1<<(j-1)),j-1)]);
			}
		}
	}
	inline T query(size_t l,size_t r)const{
		size_t k=log_id[r-l+1];
		return op(st[id(l,k)],st[id(r-(1<<k)+1,k)]);
	}
};

#endif

