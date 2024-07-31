#ifndef _Graph_
#define _Graph_

#include<bits/stdc++.h>

const double _dInf=1.0/0.0;


class MatrixGraph{
public:
	std::vector<std::vector<double>> g;
	MatrixGraph(size_t vertexCount){
		g=std::vector<std::vector<double>>(vertexCount,std::vector<double>(vertexCount,_dInf));
	}
	void removeEdge(size_t vertexA,size_t vertexB){
		g[vertexA][vertexB]=_dInf;
	}
	void removeDoubleEdge(size_t vertexA,size_t vertexB){
		g[vertexA][vertexB]=_dInf;
		g[vertexB][vertexA]=_dInf;
	}
	void setEdge(size_t vertexA,size_t vertexB,double weight){
		g[vertexA][vertexB]=weight;
	}
	void setDoubleEdge(size_t vertexA,size_t vertexB,double weight){
		g[vertexA][vertexB]=weight;
		g[vertexB][vertexA]=weight;
	}
	std::vector<std::vector<double>> floyd(){
		std::vector<std::vector<double>> _g(g);
		size_t n=g.size();
		for(size_t k=0;k<n;k++){
	        for(size_t i=0;i<n;i++){
	            for(size_t j=0;j<n;j++){
	                _g[i][j]=std::min(_g[i][j],
	                    _g[i][k]+_g[k][j]);
	            }
        	}
    	}
    	return _g;
	}
	void print(std::ostream& out){
		for(auto& vec:g){
			for(double weight:vec){
				out<<weight<<' ';
			}
			out<<std::endl;
		}
	}
};

#endif

