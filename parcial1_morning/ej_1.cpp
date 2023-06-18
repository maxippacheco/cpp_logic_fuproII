

#include<iostream>
#include<vector>
using namespace std;

int buscar_pos(vector<string> &v, string s, int p);
int reemplazar_por_s2(vector<string> &v, string s1, string s2);


int buscar_pos(vector<string> &v, string s, int p){
	
	p = -1;
	for (size_t i = 0; i < v.size(); i++)
	{
		if(v[i] == s){
			p = i;
		}
	}

	return p;
	
}

int reemplazar_por_s2(vector<string> &v, string s1, string s2){
	
	int cant_reemplazos = 0, pos = buscar_pos(v, s1, 0);
	
	while( pos != -1)
	{
		v[pos] = s2;
		++cant_reemplazos;
	}
	
	
	return cant_reemplazos;
}