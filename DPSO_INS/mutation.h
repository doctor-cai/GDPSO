#ifndef _MUTATION_H_H_
#define _MUTATION_H_H_

#include "LS.h"

/********************************************************/
/* we randomly pick a chromosome to be mutated.then we	*/
/********************************************************/
/*
void NborBasedMutate(int* p)

{
	for ( int i = 0;i < vertices;i++ )
	{
		double randnum = rnd_uni(&rnd_uni_init);
		int nborsize = node[i].neighbours.size();
		//每条染色体以pm概率变异，待变异染色体每个基因都变异
		if ( randnum < 0.9 )
		{	
			if (nborsize > 1)
			{
			//	int position = nborsize * rnd_uni(&rnd_uni_init);
			//	p[i] = p[node[i].neighbours[position]];

				p[i] = nborsize * rnd_uni(&rnd_uni_init);
					//	int randj = nodes * rnd_uni(&rnd_uni_init);
					//	int position = node[randj].neighbours.size() * rnd_uni(&rnd_uni_init);
					//	p[i].gene[randj] = p[i].gene[node[randj].neighbours[position]];
			}
			else
			{
				if (nborsize == 1)
					p[i] = p[node[i].neighbours[0]];
			}
		}
	}//end i

	sorting(p);
}//*/


//*
void NborBasedMutate(int* p)

{
	vector<int>nborlabel;
	int counter = 0;
	int randnum = vertices*rnd_uni(&rnd_uni_init);
	
	while (!CheckDiffNeibor(randnum,p,nborlabel))
	{
		randnum = vertices * rnd_uni(&rnd_uni_init);
		counter++;
		if (counter == 10) break;
	}

	if ( rnd_uni(&rnd_uni_init) < pm )
	{	
		int diff = nborlabel.size();
		int rndnode = diff * rnd_uni(&rnd_uni_init);
		p[randnum] = nborlabel[rndnode];
	}
	
//	sorting(p);
}//*/


void realmutation(int* x_var)  //NBM mutation
{

	for (int j = 0; j < vertices; j++)
	{
		if (rnd_uni(&rnd_uni_init) <= pm)
		{						
			int rand_v_ns = node[j].neighbours.size();

			if (rand_v_ns > 1)
			{
				for (int i = 0; i < rand_v_ns; i++)
				{
					int neighborX = node[j].neighbours[i];
					x_var[neighborX] = x_var[j];
				}
			} 
			else
			{
				if (rand_v_ns == 1)
					x_var[j] = x_var[node[j].neighbours[0]]; 
			}		
		}
	}

	sorting(x_var);
}


#endif