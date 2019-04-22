#include "My_Table.h"
template<typename T>
table<T>::table(){
	row=0;
	col=0;
	body=NULL;
}
template<typename T>
int table<T>::get_row(){
	return row;
}
template<typename T>
int table<T>::get_col(){
	return col;
}
template<typename T>
int table<T>::Set(int i,int j,T _data){
	errcode=0;
	if((i>row)||(i<0)||(j<0)||(j>col))errcode=INNCORECT_DATA;
	else{
		this->body[i][j]=_data;
	}
	return errcode;
}
template<typename T>
int table<T>::Get(int i,int j,T &_data){
	errcode=0;
	if((i>row)||(i<0)||(j>col)||(j<0))errcode=INNCORECT_DATA;
	else{
		if(body==NULL)errcode=EMPTY_TABLE;
		else{
			_data=body[i][j];
		}
	}
	return errcode;
}
template<typename T>
int table<T>::create(int _row,int _col){
	errcode=0;
	if((_row<0)||(_col<0))errcode=INNCORECT_DATA;
	else{
		this->row=_row;
		this->col=_col;
		body=new T*[row];
		for(unsigned i=0;i<row;i++){
			body[i]=new T[col];
		}
	}
	return errcode;
}
template<typename T1>
int getfile(std::ifstream &in,table<T1> &t){
    int num=0,_row=0,_col=0;
    int errcode=0;
    if(!in.is_open())errcode=ERR_FILE;
    else{
		in.seekg(0,ios::end);
		if(in.tellg()==0)errcode=EMPTY_FILE;
		else{
			in.seekg(0,ios::beg);
			in>>_row;
			if(in.fail())errcode=INNCORECT_DATA;
			in>>_col;
			if(in.fail())errcode=INNCORECT_DATA;
			if(errcode==0)t.create(_row,_col);
			for(unsigned i=0;((i<t.row)&&(errcode==0));i++){
				for(unsigned j=0;((j<t.col)&&(errcode==0));j++){
					in>>t.body[i][j];
					if(in.fail()){
						errcode=INNCORECT_DATA;
						num=0;
					}
					num++;
				}
			}
			if(num!=0||(num!=_row*_col))t.del();
		}
    }
    return errcode;
}
template<typename T1>
int Sort(table<T1> &t){
	int errcode=0;
	if(t.body==NULL)errcode=EMPTY_TABLE;
	else{
		int loc_sum=0,temp;
		int *tmp;
		int k,l;
		int *key=new int[t.row];
		for(int i=0;i<t.row;i++){
			loc_sum=0;
			for(int j=0;j<t.col;j++){
				loc_sum=loc_sum+t.body[i][j];
			}
			key[i]=abs(loc_sum);
			//cout<<key[i]<<endl;
		}
		k=1;
		for(int i=1;i<t.row;i++){
			l=t.row+1;
			for(int j=t.row-1;j>=k;j--){
				if(key[j-1]>key[j]){
					temp=key[j-1];
					key[j-1]=key[j];
					key[j]=temp;
					l=j;
					tmp=t.body[j-1];
					t.body[j-1]=t.body[j];
					t.body[j]=tmp;
				}
				k=1;
			}
		}
	}
	return errcode;
}
template<typename T>
int Save(std::ostream& out,table<T> &t){
	int errcode;
	if(t.body==NULL)errcode=EMPTY_TABLE;
	else{
		out<<t.row<<endl;
		out<<t.col<<endl;
		for(unsigned i=0;i<t.row;i++){
			for(unsigned j=0;j<t.col;j++){
				out<<t.body[i][j]<<" ";
			}
			out<<endl;
		}
	}
	return errcode;
}
template<typename T>
void table<T>::del(){
	if(body!=NULL){
		for(unsigned i=0;i<row;i++)delete[]body[i];
		delete[]body;
		body=NULL;
		row=0;
		col=0;
	}
}
template<typename T>
table<T>::~table(){
	if(body!=NULL){
		for(unsigned i=0;i<row;i++)delete[]body[i];
		delete[]body;
		body=NULL;
		row=0;
		col=0;
	}
}
