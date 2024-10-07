#ifndef _String_Utils_20241001_
#define _String_Utils_20241001_

#include<bits/stdc++.h>

size_t longestCommonSubsequence(const std::string& a,const std::string& b){
	std::vector< std::vector<size_t> > dp(a.size()+1,std::vector<size_t>(b.size()+1,0));
	for(size_t i=1;i<=a.size();i++){
		for(size_t j=1;j<=b.size();j++){
			if(a[i-1]==b[j-1])dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=std::max(dp[i-1][j],dp[i][j-1]);
		}
	}
	return dp[a.size()][b.size()];
}

struct hashed_string{
	size_t radix,mod,len;
	size_t *hashed;
	size_t *mod_pow;
	~hashed_string(){
		delete hashed;
		delete mod_pow;
	}
};

hashed_string* hash_string(const std::string& str,const size_t radix,const size_t mod){
	hashed_string* res=new hashed_string{radix,mod,str.size(),nullptr,nullptr};
	size_t* hashed=new size_t[res->len+1];
	size_t* mod_pow=new size_t[res->len+1];
	hashed[0]=0;
	mod_pow[0]=1;
	for(size_t i=1;i<=res->len;i++){
		hashed[i]=(hashed[i-1]*radix+str[i-1])%mod;
		mod_pow[i]=(mod_pow[i-1]*radix)%mod;
	}
	res->hashed=hashed;
	res->mod_pow=mod_pow;
	return res;
}

inline size_t get_substring_hash(const hashed_string* str,const size_t left,const size_t right){
	return (str->hashed[right+1]-str->hashed[left]*str->mod_pow[right-left+1]%str->mod)%str->mod;
}

#endif
