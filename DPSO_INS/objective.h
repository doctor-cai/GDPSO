#ifndef _OBJ_H_H_
#define _OBJ_H_H_


#include "global.h"
//#include "common.h"



double modularity(int* pos)
{
	int i,j;
    double fitQ = 0;
	double R = 0.5/edges;

	for ( i = 0;i < vertices;i++ )
	{
		int di = node[i].degree;
		int u = pos[i];
		for ( j = 0;j < vertices;j++ )
		{		
			int v = pos[j];
			if (u == v)
			{
				int dj = node[j].degree;
				fitQ += (AdjMatrix[i][j] - di * dj * R);
			}			
		}
	}
	fitQ *=  R;
	return fitQ;
}

#endif