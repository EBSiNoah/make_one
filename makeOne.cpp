#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;
vector<int> Ones;
vector<int> move;
vector< vector<int> > way;

int restore=0;

int find(vector<int> input)
{
	int least=0;
	vector<int>::iterator itr;
	for(least= *input.begin(), itr=input.begin()+1;itr!=input.end();++itr)
	{
		if(least>*itr)
		{
			least= *itr;
		}
	}
	return least;
}

vector <int> sort(vector<int> before)
{
	vector<int> after;
	vector<int>::iterator itr;
	vector<int>::iterator itr_after;
	int count=0;
	int idx=0;
	bool isinsert=0;
	int len=0;
	int loopnum=0;

	for(itr=before.begin();itr!=before.end();++itr)
	{
		if(after.size()==0)
		{
			after.push_back((*itr));
		}
		else
		{
			for(count=0, itr_after=after.begin();itr_after!=after.end();++itr_after)
			{
				++loopnum;
				len=after.size();
				if((*itr)<=(*itr_after))
				{
					after.insert(after.begin()+count, (*itr));
					isinsert=1;
					break;
				}
				else
				{
					isinsert=0;
					++count;
					continue;
				}
			}
			if(!isinsert)
			{
				after.push_back((*itr));
			}
		}
	}
	return after;
}

int makeOne01(int num, int count)
{
	cout<<"numbers : "<<num<<", count : "<<count<<endl;
	if(num==1)
	{
		return count;
	}
	
	if(num%5==0)
	{
		return makeOne01(num/5, ++count);
	}
	
	if(num%3==0)
	{
		return makeOne01(num/3, ++count);
	}
	
	if(num%2==0)
	{
		return makeOne01(num/2, ++count);
	}
	return makeOne01(--num, ++count);
}

int makeOne02(int num)
{
	int restore=0;
	int count=0;
	
	while(num!=1)
	{
		if(num%5==0)
		{
			num/=5;
			++count;
		}
		if(num%3==0)
		{
			num/=3;
			++count;
		}
		if(num%2==0)
		{
			num/=2;
			++count;
		}

		--num;
		++count;
		cout<<"number : "<<num<<", count : "<<count<<endl;	
	}	
	return count;
}

int makeOne03(int num, int count)
{
	int change=0;
	cout<<"numbers : "<<num<<", count : "<<count<<endl;
	if(num==1)
	{
		vector<int> sorted;
		sorted=sort(move);
		Ones.push_back(count);
//		way.push_back(sorted);
		way.push_back(move);
		move.clear();
//		sorted.clear();
//		num=makeOne03(restore, 0);
		return find(Ones);
	}
	if(num>1)
	{
		change=num-1;
	}

	if(num%5==0)
	{
		move.push_back(5);
		return makeOne03(num/5, ++count);
	}
	
	if(num%3==0)
	{
		move.push_back(3);
		return makeOne03(num/3, ++count);
	}
	
	if(num%2==0)
	{
		move.push_back(2);
		return makeOne03(num/2, ++count);
	}
	
	if(change%5==0)
	{
		move.push_back(-1);
		move.push_back(5);
		return makeOne03(change/5, count+2);
	}
	
	if(change%3==0)
	{
		move.push_back(-1);
		move.push_back(3);
		return makeOne03(change/3, count+2);
	}
	
	if(change%2==0)
	{
		move.push_back(-1);
		move.push_back(2);
		return makeOne03(change/2, count+2);
	}
}

int makeOne04(int num)
{
	vector< vector<int> > stem;
	vector<int> branch;
	vector< vector<int> >::iterator row;
	vector<int>::iterator col;
	vector<int>::iterator brc_itr;
	int count=0;//stem idx
	bool isout=0;
	int loopnum=0;
	
	branch.push_back(num);
	stem.push_back(branch);
	branch.clear();
	while(count<num&&!isout)
	{
		row=stem.begin()+count;
		for(col=row->begin();col!=row->end();++col)
		{
			++loopnum;
			if((*col)%5==0)
			{
				if((*col)/5==1)
				{
					isout=1;
					break;
				}
				else
				{
					branch.push_back((*col)/5);
				}
			}
			else
			{
				branch.push_back(0);
			}
			
			if((*col)%3==0)
			{
				if((*col)/3==1)
				{
					isout=1;
					break;
				}
				else
				{
					branch.push_back((*col)/3);
				}
			}
			else
			{
				branch.push_back(0);
			}
			
			if((*col)%2==0)
			{
				if((*col)/2==1)
				{
					isout=1;
					break;
				}
				else
				{
					branch.push_back((*col)/2);
				}
			}
			else
			{
				branch.push_back(0);
			}
			
			if((*col)-1==1)
			{
				isout=1;
				break;
			}
			else
			{
				branch.push_back((*col)-1);
			}
		}
		stem.push_back(branch);
		branch.clear();
		++count;
	}
	cout<<"original : "<<loopnum<<endl;
/*	for(row=stem.begin();row!=stem.end();++row)
	{
		for(col=row->begin();col!=row->end();++col)
		{
			cout<<*col<<" | ";
		}
		cout<<endl;
	}*/
	return count;
}

void makeTable(int num)
{
	for(int i=1;i<32;++i)
	{
		cout<<i<<"	|";
	}
	cout<<endl;
	cout<<endl;
	for(int i=1;i<32;++i)
	{
		cout<<i%5<<"	|";
	}
	cout<<endl;
	for(int i=1;i<32;++i)
	{
		cout<<i%3<<"	|";
	}
	cout<<endl;
	for(int i=1;i<32;++i)
	{
		cout<<i%2<<"	|";
	}
	cout<<endl;
	for(int i=1;i<32;++i)
	{
		cout<<(i%5)*(i%3)*(i%2)<<"	|";
	}
}

void makeTable02A(void)
{
	int arr05[5]={0,1,1,1,1};
	int arr03[3]={0,1,1};
	int arr02[2]={0,1};
	
	for(int i=1;i<32;++i)
	{
		cout<<i<<"  |";
	}
	cout<<endl;
	cout<<endl;
	for(int i=1;i<32;++i)
	{
		cout<<arr05[i%5]<<"  |";
	}
	cout<<endl;
	for(int i=1;i<32;++i)
	{
		cout<<arr03[i%3]<<"  |";
	}
	cout<<endl;
	for(int i=1;i<32;++i)
	{
		cout<<arr02[i%2]<<"  |";
	}
	cout<<endl;
	for(int i=1;i<32;++i)
	{
		cout<<arr05[i%5]*arr03[i%3]*arr02[i%2]<<"  |";
	}
}

void makeTable02A1(void)
{
	int A[5]={0,1,1,1,1};
	
	for(int i=1;i<32;++i)
	{
		cout<<i<<"  |";
	}
	cout<<endl;
	cout<<endl;
	for(int i=1;i<32;++i)
	{
		cout<<A[i%5]<<"  |";
	}
	cout<<endl;
	for(int i=1;i<32;++i)
	{
		cout<<A[i%3]<<"  |";
	}
	cout<<endl;
	for(int i=1;i<32;++i)
	{
		cout<<A[i%2]<<"  |";
	}
	cout<<endl;
	for(int i=1;i<32;++i)
	{
		cout<<A[i%5]*A[i%3]*A[i%2]<<"  |";
	}
}

void makeTable02C(void)
{
	for(int i=1;i<32;++i)
	{
		cout<<i<<"	|";
	}
	cout<<endl;
	cout<<endl;
	for(int i=1;i<32;++i)
	{
		cout<<static_cast<bool>(i%5)<<"	|";
	}
	cout<<endl;
	for(int i=1;i<32;++i)
	{
		cout<<static_cast<bool>(i%3)<<"	|";
	}
	cout<<endl;
	for(int i=1;i<32;++i)
	{
		cout<<static_cast<bool>(i%2)<<"	|";
	}
	cout<<endl;
	for(int i=1;i<32;++i)
	{
		cout<<static_cast<bool>((i%5)*(i%3)*(i%2))<<"	|";
	}
}

int makeOne04A(int num)
{
	int table[30][4]={/*30*/{0,0,0,1},/*1*/{1,1,1,0},/*2*/{1,1,0,1},/*3*/{1,0,1,1},/*4*/{1,1,0,1},/*5*/{0,1,1,1},/*6*/{1,0,0,1},/*7*/{1,1,1,0},/*8*/{1,1,0,1},/*9*/{1,0,1,1},/*10*/{0,1,0,1},/*11*/{1,1,1,0},/*12*/{1,0,0,1},/*13*/{1,1,1,0},/*14*/{1,1,0,1},/*15*/{0,0,1,1},/*16*/{1,1,0,1},/*17*/{1,1,1,0},/*18*/{1,0,0,1},/*19*/{1,1,1,0},/*20*/{0,1,0,1},/*21*/{1,0,1,1},/*22*/{1,1,0,1},/*23*/{1,1,1,0},/*24*/{1,0,0,1},/*25*/{0,1,1,1},/*26*/{1,1,0,1},/*27*/{1,0,1,1},/*28*/{1,1,0,1},/*29*/{1,1,1,0}};
	int idx[4]={0};
	int count=0;
	int i=0;
	int loopnum=0;
	
	while(num>1)
	{
		idx[0]=num/5;
		idx[1]=num/3;
		idx[2]=num/2;
		idx[3]=num-1;
		for(i=0;table[num%30][i]!=0;++i)
		{
			++loopnum;
		}
		num=idx[i];
		++count;
		cout<<"index : "<<i<<" value : "<<num<<endl;
	}
	cout<<"various 1 : "<<loopnum<<endl;
	return count;
}

int makeOne04B(int num)//think about exception
{
	int table[30][4]={/*30*/{0,0,0,1},/*1*/{1,1,1,0},/*2*/{1,1,0,1},/*3*/{1,0,1,1},/*4*/{1,1,0,1},/*5*/{0,1,1,1},/*6*/{1,0,0,1},/*7*/{1,1,1,0},/*8*/{1,1,0,1},/*9*/{1,0,1,1},/*10*/{0,1,0,1},/*11*/{1,1,1,0},/*12*/{1,0,0,1},/*13*/{1,1,1,0},/*14*/{1,1,0,1},/*15*/{0,0,1,1},/*16*/{1,1,0,1},/*17*/{1,1,1,0},/*18*/{1,0,0,1},/*19*/{1,1,1,0},/*20*/{0,1,0,1},/*21*/{1,0,1,1},/*22*/{1,1,0,1},/*23*/{1,1,1,0},/*24*/{1,0,0,1},/*25*/{0,1,1,1},/*26*/{1,1,0,1},/*27*/{1,0,1,1},/*28*/{1,1,0,1},/*29*/{1,1,1,0}};
	int idx[4]={0};
	int count=0;
	int i=0;
	int j=0;
	int loopnum=0;
	bool isOne=0;
	vector<int> numbers;
	vector< vector<int> > tree;
	vector<int>::iterator num_itr;
	vector< vector<int> >:: iterator row;
	vector<int>::iterator col;
	numbers.push_back(num);
	tree.push_back(numbers);
	numbers.clear();
	
	for(row=tree.begin();row!=tree.end()&&!isOne;++row)
	{
		for(col=row->begin();col!=row->end();++col)
		{
			cout<<"work?"<<(*col)<<endl;
			if((*col)==1)
			{
				isOne=1;
				break;
			}
			idx[0]= (*col)/5;
			idx[1]= (*col)/3;
			idx[2]= (*col)/2;
			idx[3]= (*col)-1;
			for(i=0;table[(*col)%30][i]!=0;++i)
			{
				cout<<"what?"<<endl;
				++loopnum;
			}
			numbers.push_back(idx[i]);
			numbers.push_back(idx[3]);
		}
		tree.push_back(numbers);
		numbers.clear();
		++count;
		cout<<"index : "<<i<<" value : "<<num<<endl;
	}
	
	return count;
}

int makeOne04C(int num)//think about exception
{
	int table[30][4]={/*30*/{0,0,0,1},/*1*/{1,1,1,0},/*2*/{1,1,0,1},/*3*/{1,0,1,1},/*4*/{1,1,0,1},/*5*/{0,1,1,1},/*6*/{1,0,0,1},/*7*/{1,1,1,0},/*8*/{1,1,0,1},/*9*/{1,0,1,1},/*10*/{0,1,0,1},/*11*/{1,1,1,0},/*12*/{1,0,0,1},/*13*/{1,1,1,0},/*14*/{1,1,0,1},/*15*/{0,0,1,1},/*16*/{1,1,0,1},/*17*/{1,1,1,0},/*18*/{1,0,0,1},/*19*/{1,1,1,0},/*20*/{0,1,0,1},/*21*/{1,0,1,1},/*22*/{1,1,0,1},/*23*/{1,1,1,0},/*24*/{1,0,0,1},/*25*/{0,1,1,1},/*26*/{1,1,0,1},/*27*/{1,0,1,1},/*28*/{1,1,0,1},/*29*/{1,1,1,0}};
	int idx[4]={0};
	int count=0;
	int i=0;
	int j=0;
	int l=0;
	int k=0;
	int loopnum=0;
	bool isOne=0;
	int Btree[num][num]={0};
	Btree[0][0]=num;
	
	for(j=0;j<num;++j)
	{
		for(l=0;Btree[j][l]!=0;++l)
		{
			if(Btree[j][l]==1)
			{
				isOne=1;
				break;
			}
			idx[0]= Btree[j][l]/5;
			idx[1]= Btree[j][l]/3;
			idx[2]= Btree[j][l]/2;
			idx[3]= Btree[j][l]-1;
			for(i=0;table[Btree[j][l]%30][i]!=0;++i)
			{
				++loopnum;
			}
			Btree[j+1][2*l]=idx[i];
			Btree[j+1][2*l+1]=idx[3];
		}
		if(isOne)
		{
			k=j;
			break;
		}
		++count;
	}

	cout<<"various 2 :"<<loopnum<<endl;
	return count;
}

int makeOne04C01(int num)//think about exception
{
	int table[30][4]={/*30*/{0,0,0,1},/*1*/{1,1,1,0},/*2*/{1,1,0,1},/*3*/{1,0,1,1},/*4*/{1,1,0,1},/*5*/{0,1,1,1},/*6*/{1,0,0,1},/*7*/{1,1,1,0},/*8*/{1,1,0,1},/*9*/{1,0,1,1},/*10*/{0,1,0,1},/*11*/{1,1,1,0},/*12*/{1,0,0,1},/*13*/{1,1,1,0},/*14*/{1,1,0,1},/*15*/{0,0,1,1},/*16*/{1,1,0,1},/*17*/{1,1,1,0},/*18*/{1,0,0,1},/*19*/{1,1,1,0},/*20*/{0,1,0,1},/*21*/{1,0,1,1},/*22*/{1,1,0,1},/*23*/{1,1,1,0},/*24*/{1,0,0,1},/*25*/{0,1,1,1},/*26*/{1,1,0,1},/*27*/{1,0,1,1},/*28*/{1,1,0,1},/*29*/{1,1,1,0}};
	int idx[4]={0};
	int count=0;
	int i=0;
	int j=0;
	int l=0;
	int k=0;
	int m=0;
	int n=0;
	int loopnum=0;
	bool isOne=0;
	int Btree[10][1024]={0};
	Btree[0][0]=num;
	
//	cout<<"work?"<<endl;
	for(j=0;j<num;++j)
	{
		for(l=0;Btree[j][l]!=0;++l)
		{
//			cout<<"j : "<<j<<" l : "<<l<<endl;
			if(Btree[j][l]==1)
			{
				m=j;
				n=l;
				isOne=1;
				break;
			}
			idx[0]= Btree[j][l]/5;
			idx[1]= Btree[j][l]/3;
			idx[2]= Btree[j][l]/2;
			idx[3]= Btree[j][l]-1;
			for(i=0;table[Btree[j][l]%30][i]!=0;++i)
			{
				++loopnum;
			}
			Btree[j+1][2*l]=idx[i];
			Btree[j+1][2*l+1]=idx[3];
		}
		if(isOne)
		{
			k=j;
			break;
		}
		++count;
	}
	for(i=0;i<count;++i)
	{
		for(j=0;Btree[i][j]!=0;++j)
		{
			cout<<Btree[i][j]<<" | ";
		}
		cout<<endl;
	}

	cout<<"various 2A loopcount : "<<loopnum<<", answer : "<<count<<endl;
	return count;
}

void maxInteger(void)
{
	int arr[512][512];
	for(int i=0;i<512;++i)
	{
		for(int j=0;j<512;++j)
		{
			arr[i][j]=1;
		}
	}
	for(int i=0;i<512;++i)
	{
		for(int j=0;j<512;++j)
		{
			cout<<arr[i][j]<<" | ";
		}
		cout<<endl;
	}
}
/*
void maxIntegerA(void)
{
	#define AK	512
	#define BK	512
	int arr[AK][BK];
	for(int i=0;i<AK;++i)
	{
		for(int j=0;j<BK;++j)
		{
			arr[i][j]=AK*BK-i*j;
		}
	}
	for(int i=0;i<AK;++i)
	{
		for(int j=0;j<BK;++j)
		{
			if(arr[i][j]=!(AK*BK-i*j))
			{
				cout<<"i : "<<i<<", j : "<<j<<endl;
				return ;				
			}
		}
	}
	cout<<AK<<", "<<BK<<endl;
}*/
/*
#define MAXINTERGERB_FUNC

# if defined(MAXINTERGERB_FUNC)
void maxIntegerB(int AK, int BK)
{
	int arr[AK][BK];
	for(int i=0;i<AK;++i)
	{
		for(int j=0;j<BK;++j)
		{
			arr[i][j]=AK*BK-i*j;
		}
	}
	for(int i=0;i<AK;++i)
	{
		for(int j=0;j<BK;++j)
		{
			if(arr[i][j]=!(AK*BK-i*j))
			{
				cout<<"i : "<<i<<", j : "<<j<<endl;
				return ;
			}
		}
	}
	cout<<AK<<", "<<BK<<endl;
}
# endif
*//*
void maxIntegerB_test(void)
{
# if defined(MAXINTERGERB_FUNC)
	maxIntegerB(512, 512);
#endif
}*/

void maxIntegerC(void)
{
	int max=0;
	int min=0;
	int result=0;
	int compare=1;
	int count=0;

	for(count=1;count<32;++count)
	{
		compare*=2;
	}
	compare--;
	cout<<compare<<endl;

	for(max=0;max<compare;++max,--min)
	{
		result+=(max+min);
	}
	cout<<"max : "<<max<<" min : "<<min<<endl;
	cout<<result<<endl;
}

void maxIntegerC01A(void)
{
	int min=-1;

	while(min<0)
	{
		--min;
	}
	min++;
	cout<<min<<endl;
}

void maxIntegerC01B(void)
{
	int value=-1;
	long long count=1;
	
	do
	{
		--value;
		++count;
	}
	while(value!=0);
	
	cout<<value<<", "<<count<<endl;
}

void maxIntegerC01C(void)
{
	int size=0;
	int compare=1;
	int count=0;
	vector<int> arr;

	for(count=1;count<20;++count)
	{
		compare*=2;
	}
	while(size<compare)
	{
		arr.push_back(1);
		++size;
	}
	cout<<*(arr.begin()+compare-1)<<endl;
}

void maxIntegerC_test(void)
{
	int i=0,j=0;
	maxIntegerC01C();
}

int main(void)
{
	int answer=0;
	vector<int>::iterator itr;
//	answer=makeOne04(199);
//	answer=makeOne04A(199);
	answer=makeOne04C01(30000);	
//	makeTable02C();
//	maxIntegerA();
//	maxIntegerB_test();
//	maxIntegerC_test();
/*	for(itr=Ones.begin();itr!=Ones.end();++itr)
	{
		cout<<*itr<<endl;
	}*/
//	cout<<answer<<endl;
	return 0;
}
