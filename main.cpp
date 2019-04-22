#include "My_Table.h"
#include "My_Table_Module.cpp"
void menu(int);
void menu_fill(int);
void menu_table(int);
void null(int&,int&,int&);
void Size(int&,int&);
struct Node{
	table<TElem> a;
	Node *next;
};
typedef Node *PNode;
int main()
{
	srand(time(NULL));
	table<TElem> a;
	char s[8]=".txt";
    int chm=0,Number_table=1,chm_fill=0,chm_table=0,_row,_col,err=0,num;
    while(chm!=5){
		menu(Number_table);
		cin>>chm;
		while((!cin)||(chm<1)||(chm>5)){
			system("cls");
			menu(Number_table);
			cin.clear();
			cin.ignore(32767,'\n');
			cin>>chm;
		}
//=========================================================================
		if(chm==1){
			system("cls");
			menu_fill(Number_table);
            cin>>chm_fill;
            while((!cin)||(chm_fill<1)||(chm_fill>4)){
				system("cls");
				menu_fill(Number_table);
				cin.clear();
				cin.ignore(32767,'\n');
				cin>>chm_fill;
            }
            if(chm_fill==1){ //FROM KEYBOARD FILL
				err=0;num=0;
				a.del();
				TElem el;
				Size(_row,_col);
				a.create(_row,_col);
				for(unsigned i=0;((i<_row)&&(err==0));i++){
					for(unsigned j=0;((j<_col)&&(err==0));j++){
						system("cls");
						cout<<"Press elem ["<<i<<"]"<<"["<<j<<"] >>";
						cin>>el;
						while(!cin){
							system("cls");
							cout<<"Press elem ["<<i<<"]"<<"["<<j<<"] >>";
							cin.clear();
							cin.ignore(32767,'\n');
							cin>>el;
						}
						a.Set(i,j,el);
						num++;
					}
				}
				if(num<_row*_col){
					cout<<"ERROR FILL"<<endl;
					a.del();
				}
				null(chm,chm_fill,chm_table);
            }
            if(chm_fill==2){  // RANDOM FILL
				a.del();
				TElem el;
				err=0;num=0;
				Size(_row,_col);
				a.create(_row,_col);
				for(unsigned i=0;((i<_row)&&(err==0));i++){
					for(unsigned j=0;((j<_col)&&(err==0));j++){
						el=(TElem)(rand()%2000-1000);
						a.Set(i,j,el);
						num++;
					}
				}
				if((num<_row*_col)||(err!=0)){
					cout<<"ERROR FILL"<<endl;
					a.del();
				}
				else{
					cout<<"Excellent fill"<<endl;
				}
				null(chm,chm_fill,chm_table);
            }
            if(chm_fill==3){
				system("cls");
				err=0;
				char name[50];
				cout<<"press filename >>";
				cin>>name;
				strcat(name,s);
				ifstream fin;
				fin.open(name);
				err=getfile(fin,a);
				if(err==ERR_FILE)cout<<"ERROR OPEN FILE"<<endl;
				if(err==EMPTY_FILE)cout<<"EMPTY FILE"<<endl;
				if(err==INNCORECT_DATA)cout<<"INNCORRECT DATA"<<endl;
				if(err==0)cout<<"EXCELENT FILL"<<endl;
				fin.close();
				null(chm,chm_fill,chm_table);
            }
            if(chm_fill==4){
				system("cls");
				null(chm,chm_fill,chm_table);
            }
		}
//=========================================================================
		if(chm==2){
			err=0;
			TElem el;
			system("cls");
			_row=a.get_row();
			_col=a.get_col();
			if((_row==0)||(_col==0))cout<<"EMPTY TABLE"<<endl;
			else{
				for(unsigned i=0;((i<_row)&&(err==0));i++){
					for(unsigned j=0;((j<_col)&&(err==0));j++){
						err=a.Get(i,j,el);
						cout.width(6);
						cout<<el<<" ";
					}
					cout<<endl;
				}
			}
			null(chm,chm_fill,chm_table);
		}
//==================================================================================
		if(chm==3){
			err=0;
			err=Sort(a);
			if(err==EMPTY_TABLE)cout<<"EMPTY TABLE"<<endl;
			else cout<<"TABLE SORT"<<endl;
			null(chm,chm_fill,chm_table);
		}
    }
    return 0;
}
void Size(int &row,int& col){
	system("cls");
	cout<<"press row>>";
	cin>>row;
	while(!cin){
		system("cls");
		cout<<"press row>>";
		cin.clear();
		cin.ignore(32767,'\n');
		cin>>row;
	}
	system("cls");
	cout<<"press row>>";
	cin>>col;
	while(!cin){
		system("cls");
		cout<<"press row>>";
		cin.clear();
		cin.ignore(32767,'\n');
		cin>>col;
	}
}
void null(int &t1,int &t2,int &t3){
	t1=0;
	t2=0;
	t3=0;
}
void menu_fill(int Number_table){
	cout<<"======================="<<endl;
	cout<<"Table :["<<Number_table<<"]"<<endl;
	cout<<"======================="<<endl;
	cout<<"1.Fill from keyboard"<<endl;
	cout<<"2.Random "<<endl;
	cout<<"3.From txt file"<<endl;
	cout<<"4.Exit"<<endl;
	cout<<"======================="<<endl;
}
void menu_table(int Number_table){
	cout<<"======================="<<endl;
	cout<<"Table :["<<Number_table<<"]"<<endl;
	cout<<"======================="<<endl;
	cout<<"1.Create new table"<<endl;
	cout<<"2.Go to start/Head list"<<endl;
	cout<<"3.Go to next table"<<endl;
	cout<<"4.Exit"<<endl;
	cout<<"======================="<<endl;
}
void menu(int Number_table){
	cout<<"======================="<<endl;
	cout<<"Table :["<<Number_table<<"]"<<endl;
	cout<<"======================="<<endl;
	cout<<"1.Fill table"<<endl;
	cout<<"2.Redact and see table"<<endl;
	cout<<"3.Sort table"<<endl;
	cout<<"4.Table menu"<<endl;
	cout<<"5.Exit"<<endl;
	cout<<"======================="<<endl;
}
