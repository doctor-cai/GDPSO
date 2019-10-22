#ifndef _COMMON_H_H_H
#define _COMMON_H_H_H


#include "global.h"
#include "random.h"



void AllocateMemory()
{	
	AdjMatrix = new int *[vertices];
	pairs = new double*[edges];

	for ( int k = 0;k < vertices;k++ )
	{
		AdjMatrix[k] = new int[vertices];
	}

	if (NULL == AdjMatrix)
		cerr<<"邻接矩阵分配内存失败"<<endl;

	for ( int j = 0;j < edges;j++ )
	{
		pairs[j] = new double[2];
	}
	
	node = new network[vertices];

	gbest_pos = new int[vertices];
}

/*
 *检查数据是否有真实类标
*/
int checkLabelFile(char* strlabel)
{
	if (!strcmp(strlabel,"E:\\我搞定的程序\\SI\\DPSOCD\\does not exist"))
		return 0;
	else return 1;
}

/*
 *	将一个系列的元素顺序打乱
 */
void perturbation(int* a,int N)
{
    int i;
    int index;
    int temp;
    srand((unsigned)time(NULL));
    for (i = N - 1; i > 0; i--)
    {
        index = rand() % i;
        temp = a[i];
        a[i] = a[index];
        a[index] = temp;
    }
}

int deltafun(int a, int b)
{
	if (a==b)
		return 1;
	else return 0;
}

/*
 *	calculate the nearest integer to a given real number
 */
int   NearestInt2 (double F)
{
	return (int)(F)+(F>=0?(int)(10*F)%10<5?0:1:-(int)(10*F)%10<5?0:-1);
}



/*
 *	read matrix file,matrix = row X col
 *  for .pairs file, col = 2,为什么pairs
 *  文件读取的时候，必须是double类型？？
 */
template<class T>
void ReadFile(char *filepath,T** m,int row,int col)

{
	int i;
	int j;
	ifstream input(filepath,ios::in);
	
	if(input.fail())
	{
		cout<<"Oops! Couldn't open file\n";
		exit(1);
	}
	
	for ( i = 0;i < row;i++ )
	{
		for ( j = 0;j < col;j++ )
		{
			input >> m[i][j];
			input.get();
		}
	}

	input.close();
}



/*
 *	Create Matrix using edge pairs
 */
void CreateMatrix()
{		
	for ( int k = 0;k < vertices;k++ )
		for ( int j = 0;j < vertices;j++ )
			AdjMatrix[k][j] = 0;
	
	for (int i = 0; i < edges; i++)
	{
		int a = pairs[i][0]-1;
		int b = pairs[i][1]-1;

// 		int a = pairs[i][0];
// 		int b = pairs[i][1];

		AdjMatrix[a][b] = 1;
		AdjMatrix[b][a] = 1;
	}
}


/*
 *	calculate neighbors and degrees of a node
 */
void NodeInformation(network* node,int** Matrix,int nodes)

{
	for ( int i = 0;i < nodes;i++ )
	{
		int sum = 0;
		
		for ( int j = 0;j < nodes;j++ )
		{
			if ( Matrix[i][j] == 1 )
			{
				node[i].neighbours.push_back(j);
			}
			sum += Matrix[i][j];
		}
		node[i].degree = sum;
	}
}


/*
 *	cluster the permutation into n clusters
 */
vector<vector<int> >clustering(int* gene, int nodes)

{
	int i, j;

	vector<int>copylabel;
	for (i = 0; i < vertices; i++)
		copylabel.push_back(gene[i]);
		
	vector<vector<int> >A;  //the detected community
	
	for ( i = 0;i < nodes;i++ )
	{	//calculate A				
		if ( copylabel[i] != -1 )
		{
			vector<int> s1;	//store every component in each cluster
			s1.push_back(i);
			for ( j = i+1;j < nodes;j++ )
			{
				if ( copylabel[i] == copylabel[j] )
				{
					s1.push_back(j);
					copylabel[j] = -1;
				}
			}//end j
			copylabel[i] = -1;
			A.push_back(s1);
		}//end if
	}//end i	

	return A;
}


/*
 *	sort a permutation with a starting number begaining from 1
 */
void sorting(int* x)

{	
//  method one
// 	vector<vector<int> >A = clustering(x,vertices);
// 	
// 	for (int t_row = 0; t_row < A.size(); t_row++)
// 	{
// 		for (int t_col = 0; t_col < A[t_row].size(); t_col++)
// 		{
// 			int fku = A[t_row][t_col];
// 			x[fku] = t_row+1;
// 		}
// 	}

//  method two
	int counter = 1;
	int i, j;
	int* copylabel = new int[vertices];

	for (i = 0; i < vertices; i++)
		copylabel[i] = x[i];
	
	for (i = 0; i < vertices; i++)
	{
		if (copylabel[i] != -1)
		{
			for (j = i+1; j < vertices; j++)
			{
				if (copylabel[j] == copylabel[i])
				{
					x[j] = counter;
					copylabel[j] = -1;
				}
			}
			copylabel[i] = -1;
			x[i] = counter;
			counter++;
		}
	}
	delete[] copylabel;
}


/*
 *	print the detected partitions into file with .CLU format
 */
void PrintPartition(int trial,int*  gene,char *filepath,int nodes)

{
	int i, k;

	vector<vector<int> >A = clustering(gene,nodes);
	int* p = new int[nodes];

	for ( i = 0;i < A.size();i++ )
	{
		for ( k = 0;k < A[i].size();k++ )
		{
			int pi = A[i][k];
			p[pi] = i + 1;
		}
	}

	ofstream output(filepath,ios::out|ios_base::app);
	output<<"the "<<trial<<" th running......"<<endl;
	output<<"*vertices "<<nodes<<endl;
				
	for ( i = 0;i < nodes;i++ )
		output<<p[i]<<endl;

	output.close();

	delete[] p;
}


void PrintConvergence(int trial, vector<double> Q)

{
	ofstream output("convergence.txt",ios::out|ios_base::app);
	output<<"the convergence curve of the "<<trial<<" th run of GDPSO on "<<DataFile<<" data:"<<endl;
			
	for (int k = 0; k < PSO_maxgen; k++)	
		output<<Q[k]<<" ";
	output<<endl;
		
	output.close();
}


void PrintResult()

{
	ofstream output("result.txt",ios::out|ios_base::app);
	output<<RUNTIMES<<" runs' results of GDPSO on "<<DataFile<<" data:"<<endl;
	output<<"popsize="<<PSO_popsize<<"; gmax="<<PSO_maxgen<<endl;

	if (checkLabelFile(DataLabelFile))
	{
		output<<"max NMI = "<<NMImax<<"   "<<"avg NMI = "<<NMIavg<<endl;
	}
		
	Qmax = *max_element(Thirty_Run_modularity.begin(),Thirty_Run_modularity.end());
		
	output<<"max Q = "<<Qmax<<"    "<<"avg Q = "<<Qavg<<endl;
		
	for (int k = 0; k < RUNTIMES; k++)	
		output<<Thirty_Run_modularity[k]<<" ";
	output<<endl;

	output<<"averaged time = "<<timeavg<<"秒"<<endl<<endl<<endl<<endl;
	
	output.close();
}


// vector A 储存和被选节点id是一个社区的节点
// vector B 储存和id的某个邻居属于一个社区的节点
double deltaQ_function(vector<int> A,vector<int> B,int id)

{
	double q1 = 0, q2 = 0, deltaQ, R = 1.0/edges, R1 = 0.5*R*R;

	/*
	for (int i = 0; i < A.size(); i++)
	{
		q1 += AdjMatrix[id][A[i]] - node[id].degree * node[A[i]].degree * R;
	}
	for (int j = 0; j < B.size(); j++)
	{
		q2 += AdjMatrix[id][B[j]] - node[id].degree * node[B[j]].degree * R;
	}
	deltaQ = q2 - q1;//*/


	//*
	int aij = 0, aik = 0, kij = 0, kik = 0;
	for (int i = 0; i < A.size(); i++)
	{
		aij += AdjMatrix[id][A[i]];
		kij += node[A[i]].degree;
	}
		
	for (int j = 0; j < B.size(); j++)
	{
		aik += AdjMatrix[id][B[j]];
		kik += node[B[j]].degree;
	}	
	
	deltaQ = R*(aik - aij) - R1*node[id].degree*(kik - kij);//*/
	
	return deltaQ;
}



#endif