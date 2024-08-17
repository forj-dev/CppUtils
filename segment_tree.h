#ifndef _SegmentTree_20240801_
#define _SegmentTree_20240801_

#include<bits/stdc++.h>

namespace segment_tree{
	
	template<typename T>
	struct node{
		node *l,*r;
		T data,lazy;
		bool leaf;
		node():l(nullptr),r(nullptr),data(0),lazy(0),leaf(false){}
	};
	
	
	template<typename T>
	class sum_tree{
		node<T>* root;
		size_t len;
		node<T>* build_empty(size_t l,size_t r){
			if(l==r){
				node<T>* ret=new node<T>();
				ret->leaf=true;
				return ret;
			}
			size_t mid=((r-l)>>1)+l;
			node<T>* ret=new node<T>();
			ret->l=build_empty(l,mid);
			ret->r=build_empty(mid+1,r);
			return ret;
		}
		node<T>* build(size_t l,size_t r,T *arr){
			if(l==r){
				node<T>* ret=new node<T>();
				ret->data=arr[l];
				ret->leaf=true;
				return ret;
			}
			size_t mid=((r-l)>>1)+l;
			node<T>* ret=new node<T>();
			ret->l=build(l,mid,arr);
			ret->r=build(mid+1,r,arr);
			ret->data=ret->l->data+ret->r->data;
			return ret;
		}
		void pushdown(node<T>* nod,size_t l,size_t r,size_t mid){
			T lazy=nod->lazy;
			if(lazy){
//				if(nod.l){
					nod->l->data+=(mid-l+1)*lazy;
					nod->l->lazy+=lazy;
//				}
//				if(nod.r){
					nod->r->data+=(r-mid)*lazy;
					nod->r->lazy+=lazy;
//				}
				nod->lazy=0;
			}
		}
		void change(node<T>* nod,size_t l,size_t r,size_t start,size_t end,const T& num){
			if(start<=l&&r<=end){
				nod->data+=(r-l+1)*num;
				if(!nod->leaf)nod->lazy+=num;
				return;
			}
			size_t mid=((r-l)>>1)+l;
			pushdown(nod,l,r,mid);
			if(start<=mid)change(nod->l,l,mid,start,end,num);
			if(end>mid)change(nod->r,mid+1,r,start,end,num);
			nod->data=nod->l->data+nod->r->data;
		}
		T sum(node<T>* nod,size_t l,size_t r,size_t start,size_t end){
			if(start<=l&&r<=end){
				return nod->data;
			}
			size_t mid=((r-l)>>1)+l;
			pushdown(nod,l,r,mid);
			T res=0;
			if(start<=mid)res+=sum(nod->l,l,mid,start,end);
			if(end>mid)res+=sum(nod->r,mid+1,r,start,end);
			return res;
		}
	public:
		sum_tree(size_t _len){
			len=_len;
			root=build_empty(0,len-1);
		}
		sum_tree(size_t _len,T *arr){
			len=_len;
			root=build(0,len-1,arr);
		}
		size_t size(){
			return len;
		}
		void update(size_t start,size_t end,const T& offset){
			change(root,0,len-1,start,end,offset);
		}
		inline T sum(size_t start,size_t end){
			return sum(root,0,len-1,start,end);
		}
	};
	
}

#endif

