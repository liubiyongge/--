#include <bits/stdc++.h>
using namespace std;
struct Node{
	int u,v,cost;
}M[100];
struct edge{
	int T1,T2,cost;
}Ed[100];
int Cnt=0;
int a,b;//a点的数目。b边的数目 
char na[100];
int pre[100];   //最小生成树 
char map1[100][100];
int map2[100][100];
//校园站点数据 
map <int,string> xm1;
map <string,int> xm2;
int xp,xe;  //xp点数，xe边数目 
int xo2[100][100];
char xo1[100][100];
int xyt=0;
string xs[20][20];//路径 
int xDis[50][50];
//
int find(int x){
	int fx=x;
	while(pre[fx]!=fx)
		fx=pre[fx];
	int i=x,j;
	while(pre[i]!=fx){
		j=pre[i];
		pre[i]=fx;
		i=j;
	}
	return fx;
}
void mix(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx!=fy) pre[fx]=fy;
}
bool cmp(Node a,Node b){
	return a.cost<b.cost;
}
bool cmp1(edge a,edge b){
	return a.cost<b.cost;
}
void e5(){			//输入的顶点值只能从A开始，如果有3各顶点则只能输入ABC，否则会有一些神奇的现象 
	cout<<"输入顶点个数:";
	cin>>a;
	cout<<"输入顶点值:"; 
 	for(int i=0;i<a;i++){
 		cin>>na[i];
	 }
	 for(int i=0;i<a;i++)
	 	for(int j=0;j<a;j++){
			if(i==j){
				map2[i][j]=0;
				map1[i][j]='0';
			}
			else {
				map2[i][j]=100000; 
				map1[i][j]='~';
			}
		 }
	 cout<<"输入边数:";
	 cin>>b;
	 char q1,q2,q3;
	 int q4;
	 for(int i=0;i<b;i++){
	 	cout<<"第"<<i+1<<"条边起点:"; 
	 	cin>>q1;
		cout<<"第"<<i+1<<"条边终点:"; 
		cin>>q2;
		cout<<"第"<<i+1<<"条边权值:";
		cin>>q3;
		q4=q3-'0';
		cout<<endl;
		map2[q1-'A'][q2-'A']=q4;
		map1[q1-'A'][q2-'A']=q3; 
		M[i].u=q1-'A';
		M[i].v=q2-'A';
		M[i].cost=q4;
	 }
	 cout<<"邻接矩阵如下:"<<endl;
	 for(int i=0;i<a;i++){
	 	cout<<"　　　"<<setw(3)<<na[i]; 
	 } 
	 cout<<endl<<" ";
	 for(int j=0;j<a;j++){
	 	cout<<"     "<<setw(2)<<"["<<j<<"]"; 
	 }
   	 cout<<endl;	
	 for(int i=0;i<a;i++){
	 	cout<<na[i]<<"　"<<"["<<i<<"]";
	 	for(int j=0;j<a;j++){
	 		cout<<setw(3)<<map1[i][j]<<"　　  ";
		 }
		 cout<<endl;
	 }
}
void show(){
	cout<<"当前邻接矩阵如下:"<<endl;
	 for(int i=0;i<a;i++){
	 	cout<<"　　　"<<setw(3)<<na[i]; 
	 } 
	 cout<<endl<<" ";
	 for(int j=0;j<a;j++){
	 	cout<<"     "<<setw(2)<<"["<<j<<"]"; 
	 }
   	 cout<<endl;	
	 for(int i=0;i<a;i++){
	 	cout<<na[i]<<"　"<<"["<<i<<"]";
	 	for(int j=0;j<a;j++){
	 		cout<<setw(3)<<map1[i][j]<<"　　  ";
		 }
		 cout<<endl;
	 }
}
int e1(){    //最小生成树 
	if(Cnt==0){
		cout<<"请有输入有向图!"<<endl;
		Cnt++;
		e5();  
	}
	show(); 
	char Q;
	cout<<"请输入起点：";
	cin>>Q;
	cout<<endl;
	cout<<"用普里姆从"<<Q<<"出发构造最小生成树如下："<<endl;
	int cost=0;
	memset(pre,0,sizeof(pre));
	for(int i=0;i<a;i++){
		pre[i]=i;
	}
	sort(M,M+b,cmp);
	for(int i=0;i<b;i++){
		Node e=M[i];
		if(find(e.u)!=find(e.v)){
			mix(e.u,e.v);
			cost+=e.cost;
			cout<<"("<<na[e.u]<<"--"<<na[e.v]<<")"<<e.cost<<"   ";
		}
	}
	cout<<"最小花费为："<<cost<<endl;
} 
int e2(){    //最小生成树 
	if(Cnt==0){
		cout<<"请有输入有向图!"<<endl;
		Cnt++;
		e5();  
	}
	show();
	char Q;
	cout<<"请输入起点：";
	cin>>Q;
	cout<<endl;
	cout<<"用克鲁思卡尔"<<a<<"出发构造最小生成树如下："<<endl;
	int cost=0;
	memset(pre,0,sizeof(pre));
	for(int i=0;i<a;i++){
		pre[i]=i;
	}
	sort(M,M+b,cmp);
	for(int i=0;i<b;i++){
		Node e=M[i];
		if(find(e.u)!=find(e.v)){
			mix(e.u,e.v);
			cost+=e.cost;
			cout<<"("<<na[e.u]<<"--"<<na[e.v]<<")"<<e.cost<<"   ";
		}
	}
	cout<<"最小花费为："<<cost<<endl;
} 
void e3(){  //Dijkstra
	if(Cnt==0){
		cout<<"请有输入有向图!"<<endl;
		Cnt++;
		e5();  
	}
	show();
	int dis[10000],vis[1000];
	char si;
	memset(vis,0,sizeof(vis));
	memset(dis,0,sizeof(dis));
	cout<<"输入顶点：";
	cin>>si;
	getchar();
	int s=si-'A';
	for(int i=0;i<a;i++)
		dis[i]=map2[s][i];
	dis[s]=0;
	for(int i=0;i<a;i++){
		int min=100000,flag;
		for(int r=0;r<a;r++){
			if(min>dis[r]&&!vis[r]){
				min=dis[r];
				flag=r;
				}
		}
		if(min==100000){
			break;
		}
		vis[flag]=1;
		for(int j=0;j<a;j++){
			if(!vis[j]&&dis[j]>dis[flag]+map2[flag][j])
				dis[j]=dis[flag]+map2[flag][j];
		}
	} 
	for(int i=0;i<a;i++){
		if(dis[i]!=100000)
			cout<<si<<"->"<<na[i]<<"的最短距离为:"<<dis[i]<<endl;
		else
			cout<<si<<"->"<<na[i]<<"的最短距离为:"<<"~"<<endl;
	}
	//return;
} 
int e4(){  //Floyd 
	if(Cnt==0){
		cout<<"请有输入有向图!"<<endl;
		Cnt++;
		e5();  
	}
	show();
	int Dis[50][50];
	for(int i=0;i<a;i++)
		for(int j=0;j<a;j++)
			Dis[i][j]=map2[i][j]; 
	for(int x=0;x<a;x++)
		for(int y=0;y<a;y++)
			for(int z=0;z<a;z++){
				if(Dis[y][x]!=100000&&Dis[x][z]!=100000&&Dis[y][x]+Dis[x][z]<Dis[y][z])
					Dis[y][z]=Dis[y][x]+Dis[x][z];
			}
	 cout<<"有向网各对顶点之间的最短路径（Floyd）："<<endl;
	 for(int i=0;i<a;i++){
	 	cout<<"　　　"<<setw(3)<<na[i]; 
	 } 
	 cout<<endl<<" ";
	 for(int j=0;j<a;j++){
	 	cout<<"     "<<setw(2)<<"["<<j<<"]"; 
	 }
   	 cout<<endl;	
	 for(int i=0;i<a;i++){
	 	cout<<na[i]<<"　"<<"["<<i<<"]";
	 	for(int j=0;j<a;j++){
	 		if(Dis[i][j]!=100000)
	 			cout<<setw(3)<<Dis[i][j]<<"　　  ";
	 		else
	 			cout<<setw(3)<<"~"<<"　　  ";
		 }
		 cout<<endl;
	 }
} 
int e6(){
	int con2[100][100];
	char con1[1000][1000];
	map <int,string> ma;
	map <string,int> ma2;
	int p,e,v;    //p村数目  e公路数目 
	cout<<"输入乡村公路无向网"<<endl;
	cout<<"输入乡村数：";
	cin>>p;
	for(int i=0;i<p;i++)
	 	for(int j=0;j<p;j++){
			if(i==j){
				con2[i][j]=0;
				con1[i][j]='0';
			}
			else {
				con2[i][j]=100000; 
				con1[i][j]='~';
			}
		 }
	
	cout<<"输入各村名字:"<<endl;
	string str;
	for(int i=0;i<p;i++){
		cout<<"第"<<i+1<<"个乡村名字为：";
		cin>>str;
		ma[i]=str;
		ma2[str]=i;
	} 
	cout<<"请输入所有可能修建的公路数：";
	cin>>e;
	cout<<"输入可能修建的每条公路及其费用"<<endl;
	for(int i=0;i<e;i++){
		string at,bt; 
		char co;
		int co1;
		cout<<"第"<<i+1<<"条公路"<<endl;
		cout<<"起点：";
		cin>>at;
		cout<<"终点：";
		cin>>bt;
		cout<<"费用：";
		cin>>co;
		co1=co-'0';	
		map<string,int>::iterator it1;
		map<string,int>::iterator it2;
		it1=ma2.find(at);
		it2=ma2.find(bt);
		Ed[i].T1=(*it1).second;
		Ed[i].T2=(*it2).second;
		Ed[i].cost=co1;
		con2[(*it1).second][(*it2).second]=co1;
		con2[(*it2).second][(*it1).second]=co1;
		con1[(*it1).second][(*it2).second]=co;
		con1[(*it2).second][(*it1).second]=co;
	}
	cout<<"乡村名字如下："<<endl;
	map<int,string>::iterator it;
	for(it=ma.begin();it!=ma.end();it++)
		cout<<"["<<(*it).first<<"]"<<"   ";
	cout<<endl;	
	for(it=ma.begin();it!=ma.end();it++)
		cout<<setw(2)<<(*it).second<<"    ";
	cout<<endl<<endl;
	cout<<"乡村公路无向图如下："<<endl;
	
	 cout<<" ";
	 for(int j=0;j<p;j++){
	 	cout<<"   "<<setw(2)<<"["<<j<<"]"; 
	 }
   	 cout<<endl;	
	 for(int i=0;i<p;i++){
	 	cout<<"["<<i<<"]";
	 	for(int j=0;j<p;j++){
	 		cout<<setw(3)<<con1[i][j]<<"　　 ";
		 }
		 cout<<endl;
	 }
	
	cout<<endl;
	cout<<"乡村公路最低造价求解"<<endl;
	int cost=0;
	memset(pre,0,sizeof(pre));
	for(int i=0;i<p;i++){
		pre[i]=i;
	}
	sort(Ed,Ed+e,cmp1);
	for(int i=0;i<e;i++){
		edge edg=Ed[i];
		if(find(edg.T1)!=find(edg.T2)){
			mix(edg.T1,edg.T2);
			cost+=edg.cost;
			map<int,string>::iterator it11;
			map<int,string>::iterator it22;
			it11=ma.find(edg.T1);
			it22=ma.find(edg.T2);
			cout<<"("<<(*it11).second<<"--"<<(*it22).second<<")"<<edg.cost<<"   ";
		}
	}
	cout<<"最小花费为："<<cost<<endl;
	
}

int exshow(){
	cout<<"校园各站点代码及名字如下："<<endl;
	map<int,string>::iterator it;
	for(it=xm1.begin();it!=xm1.end();it++)
		cout<<"["<<(*it).first<<"]"<<"   ";
	cout<<endl;	
	for(it=xm1.begin();it!=xm1.end();it++)
		cout<<setw(2)<<(*it).second<<"    ";
	cout<<endl<<endl; 
	cout<<"校园站点无向图如下："<<endl;
	
	 cout<<" ";
	 for(int j=0;j<xp;j++){
	 	cout<<"   "<<setw(2)<<"["<<j<<"]"; 
	 }
   	 cout<<endl;	
	 for(int i=0;i<xp;i++){
	 	cout<<"["<<i<<"]";
	 	for(int j=0;j<xp;j++){
	 		cout<<setw(3)<<xo1[i][j]<<"　　 ";
		 }
		 cout<<endl;
	 }
	
	cout<<endl;
}
int ex1(){
	cout<<"输入校园各站点的无向图"<<endl;
	cout<<"输入校园站点数：";
	cin>>xp;
	for(int i=0;i<xp;i++)
	 	for(int j=0;j<xp;j++){
			if(i==j){
				xo2[i][j]=0;
				xo1[i][j]='0';
			}
			else {
				xo2[i][j]=100000; 
				xo1[i][j]='~';
			}
		 }
	string xstr;
	for(int i=0;i<xp;i++){ 
		cout<<"第"<<i+1<<"个站点的名字为：";
		cin>>xstr;
		xm1[i]=xstr;
		xm2[xstr]=i;
	} 
	cout<<"请输入校园的道路数：";
	cin>>xe;
	cout<<"请输入每条的道路的起点，终点与长度"<<endl;
	for(int i=1;i<=xe;i++){
		string at,bt; 
		char co;
		int co1;
		cout<<"第"<<i<<"条路"<<endl;
		cout<<"		起点：";
		cin>>at;
		cout<<"		终点：";
		cin>>bt;
		cout<<"		长度：";
		cin>>co;
		co1=co-'0';	
		map<string,int>::iterator it1;
		map<string,int>::iterator it2;
		it1=xm2.find(at);
		it2=xm2.find(bt);
		xo2[(*it1).second][(*it2).second]=co1;
		xo2[(*it2).second][(*it1).second]=co1;
		xo1[(*it1).second][(*it2).second]=co;
		xo1[(*it2).second][(*it1).second]=co;
	}
	exshow();
}
int ex2(){
	for(int i=0;i<xp;i++){
		char a='0'+i;
		for(int j=0;j<xp;j++){
			char b='0'+j;
			if(i!=j){
				xs[i][j]=xs[i][j]+a+b;
			}
			else {
				xs[i][j]="0";
			}
		}
	} 
	for(int i=0;i<xp;i++)
		for(int j=0;j<xp;j++)
			xDis[i][j]=xo2[i][j]; 
	for(int x=0;x<xp;x++)
		for(int y=0;y<xp;y++)
			for(int z=0;z<xp;z++){
				if(xDis[y][x]!=100000&&xDis[x][z]!=100000&&xDis[y][x]+xDis[x][z]<xDis[y][z]){ 
					string s;
					s=xs[y][x];
					string::iterator it=s.end();
					s.erase(it-1);
					xs[y][z]=s+xs[x][z];
					xDis[y][z]=xDis[y][x]+xDis[x][z];
				} 
			}
	cout<<"生成校园各站点之间的最短路径（Floyd）："<<endl;
	for(int i=0;i<xp;i++){
	 	cout<<"　　　"<<setw(3)<<na[i]; 
	 } 
	 cout<<endl<<" ";
	 for(int j=0;j<xp;j++){
	 	cout<<"  "<<setw(3)<<"["<<j<<"]"; 
	 }
   	 cout<<endl;	
	 for(int i=0;i<xp;i++){
	 	cout<<"["<<i<<"]"<<" ";
	 	for(int j=0;j<xp;j++){
	 		if(xDis[i][j]!=100000)
	 			cout<<setw(2)<<xDis[i][j]<<"　   ";
	 		else
	 			cout<<setw(2)<<"~"<<"　   ";
		 }
		 cout<<endl;
		 for(int j=0;j<xp;j++){
		 	cout<<"    "<<setw(2)<<xs[i][j]<<" ";
		 }
		 cout<<endl;
	 }
}
int ex3(){
	cout<<endl<<"校园导游（查询任意两点间的最短路径）"<<endl;
	while(1){
		cout<<"输入你要查询路径的起点与终点站点的名字"<<endl;
		string str1,str2;
		cout<<"    起点：";
		cin>>str1;
		cout<<"    终点：";
		cin>>str2;
		map<string,int> ::iterator it1;
		map<string,int> ::iterator it2;
		it1=xm2.find(str1);
		it2=xm2.find(str2);
		int Q=(*it1).second;
		int Z=(*it2).second;
		cout<<"从 "<<str1<<" 到 "<<str2<<" 的最短路径长度为："<<xDis[Q][Z]<<endl;
		cout<<"途径的站点如下图所示："<<endl;
		string sp=xs[Q][Z];
		for(int i=0;i<sp.length();i++){
			int fw=sp[i]-'0';
			map<int,string> ::iterator it3;
			it3=xm1.find(fw);
			cout<<(*it3).second;
			if(i!=sp.length()-1)
				cout<<"--->";
		}
		cout<<endl<<"*********************************"<<endl<<endl; 
		cout<<"还继续吗？（Y.继续      N.结束）";
		char xon;
		cin>>xon;
		if(xon == 'N' || xon == 'n')
			break;	
		else continue; 
	}
} 
int e7(){  
	while(1){
		cout<<endl<<"1.输入校园各站点的无向网络图"<<endl; 
		cout<<"2.生成校园各站点之间的最短路径"<<endl; 
		cout<<"3.校园导游（查询任意站点之间的最短路径）"<<endl;
		cout<<"其他.结束"<<endl;
		cout<<"///////////////////////////////"<<endl;
		if(xyt==0){
			cout<<"还没有输入校园站点无向图！"<<endl;
			xyt++;
		}
		cout<<"///////////////////////////////"<<endl;
		cout<<"请选择操作代码（1-3）"<<endl;
		int cho;
		cin>>cho;
		while(1){
			if(cho==1)
				ex1();
			else if(cho==2)
				ex2();
			else if(cho==3)
			    ex3();
			break;
			cout<<endl<<endl;
		}
		cout<<"还继续吗?(Y.继续\tN.结束)"<<endl;
		char XYesNO;
		cin >> XYesNO;
		if(XYesNO == 'N' || XYesNO == 'n')
			break;	
		else continue;
	} 	
} 
int main(){
	while(1){
		cout<<"1.用普里姆算法从某个顶点出发构造最小生成树"<<endl;
		cout<<"2.用克鲁思卡尔算法构造最小生成树"<<endl;
		cout<<"3.有向网从某个顶点出发到其余各店的最短路径(Dijkstra)"<<endl;
		cout<<"4.有向网各对顶点之间的最短路径(Floyd)"<<endl;
		cout<<"5.输入图的领接矩阵"<<endl;    
		cout<<"6.乡村公路造价"<<endl;
		cout<<"7.校园导游"<<endl;
		cout<<"其他.结束"<<endl;
		cout<<"/////////////////////////////////"<<endl;
		if(Cnt==0){
			cout<<"还没有输入有向图!"<<endl; 
		}
		cout<<"/////////////////////////////////"<<endl;
		cout<<"选择操作代码(1-7)"<<endl;
		int choose;
		cin >> choose;
		while(1){
			if(choose==1)
				e1();
			else if(choose==2)
				e2();
			else if(choose==3)
			    e3();
			else if(choose==4)
				e4();
			else if(choose==5)
				e5();
			else if(choose==6)
				e6();
			else if(choose==7)
				e7(); 
			break;
			cout<<endl<<endl;
		} 
		cout<<"是否继续?(Y.继续\tN.结束)"<<endl;
		char YesNO;
		cin >> YesNO;
		if(YesNO == 'N' || YesNO == 'n')
			break;	
		else continue;
	}
	return 0;
}
