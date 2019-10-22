#ifndef _NMI_H_H_
#define _NMI_H_H_


#include "common.h"
//#include "global.h"


/*
 *	calculate NMI for the detected partition
 */
int calc_NMI(int* gene,char *filepath)
{
	//*
	int i,j,k,m;
	int* p = new int[vertices];

	ifstream input(filepath,ios::in);
		
	if(input.fail())
	{
		cout<<"Oops!Couldn't open real label file\n";
		exit(1);
	}
		
	for ( i = 0;i < vertices;i++ )
	{
		input >> p[i];
		input.get();
	}

	vector<vector<int> >A;  //the detected community
	vector<vector<int> >B;  //the real community
	
	A = clustering(gene, vertices);
	B = clustering(p, vertices);
		
// //*/////////////////////////////////////////
// 		cout<<"detected A"<<endl;
// 	for ( i = 0;i < A.size();i++ )
// 	{
// 		cout<<"第 "<<i+1<<" 类:"<<endl;
// 		for ( k = 0;k < A[i].size();k++ )
// 		{
// 		//	cout<<A[i][k]+1<<' ';
// 			cout<<A[i][k]<<' ';
// 		}
// 		cout<<endl;
// 	}cout<<endl;
/////////////////////////////////////////////*/

/////*/////////////////////////////////////////
// 		cout<<"real ones"<<endl;
// 	for ( i = 0;i < B.size();i++ )
// 	{
// 		cout<<"第 "<<i+1<<" 类:"<<endl;
// 		for ( k = 0;k < B[i].size();k++ )
// 		{
// 		//	cout<<A[i][k]+1<<' ';
// 			cout<<B[i][k]<<' ';
// 		}
// 		cout<<endl;
// 	}cout<<endl;
//// ////////////////////////////////////////////
	double x = 0.0;
	double y = 0.0;
	int *ci = new int[A.size()];//sum of row
	int *cj = new int[B.size()];//sum of col
//	vector<vector<int> >C;		//the fuzzy matrix
	vector<vector<int> >C(A.size(),vector<int>(B.size()));

	for ( i = 0;i < A.size();i++ )
		ci[i] = 0;
	for ( j = 0;j < B.size();j++ )
		cj[j] = 0;

	for ( i = 0;i < A.size();i++ )
		for ( j = 0;j < B.size();j++ )
			C[i][j] = 0;

	for ( i = 0;i < A.size();i++ )
	{
		for ( j = 0;j < B.size();j++ )
		{
			for ( k = 0;k < A[i].size();k++ )
			{
				for ( m = 0;m < B[j].size();m++ )
				{
					if ( A[i][k] == B[j][m] )
					{
						C[i][j] += 1;
						break;
					}//end if
				}//end m
			}//end k
		}//end j	
	}//end i

	for ( i = 0;i < A.size();i++ )
	{
		for ( j = 0;j < B.size();j++ )
		{
			ci[i] += C[i][j];
		}
	}

	for ( j = 0;j < B.size();j++ )
	{
		for ( k = 0;k < A.size();k++ )
		{
			cj[j] += C[k][j];
		}
	}
	
	double temp1 = 0.0;

	for ( i = 0;i < A.size();i++ )
	{
		temp1 += 1.0*ci[i]*log10(1.0*ci[i]/vertices);
		for ( j = 0;j < B.size();j++ )
		{
			if ( C[i][j] != 0 )
			{
				x += 1.0*C[i][j]*log10(1.0*C[i][j]*vertices/(ci[i]*cj[j]));
			}
		}		
	}

	for ( j = 0;j < B.size();j++ )
		y += 1.0*cj[j]*log10(1.0*cj[j]/vertices);

	NMI = -2*x/(temp1 + y);
	
	delete[] ci;
	delete[] cj;
	delete[] p;
	return 1;
}

#endif
