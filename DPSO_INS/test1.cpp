
//////////////////////////////////////////////////////////////////////////



////////////////////////////
#include "PSO.h"
#include "global.h"
////////////////////////////

void main()
{
	int i,j,k;
	double **pairs = new double*[78];

	for (j = 0;j < 78;j++ )
	{
		pairs[j] = new double[2];
	}
	cout<<"������������......."<<endl;
		
//	ReadFile(DataFile,AdjMatrix,vertices,vertices);
	ReadFile("karate.pairs",pairs,78,2);

	//*
	for (i = 0; i < 78; i++)
	{
		cout<<pairs[i][0]<<"  "<<pairs[i][1]<<endl;
	}//*/

//	CreateMatrix();
		

	cout<<"�����������"<<endl;

}//end main





