#ifndef _LS_H_
#define _LS_H_


#include "random.h"
#include "individual.h"
//#include "global.h"


/*
 * check whether the chose node has neighbors that have different 
 * label identifiers with it, if yes, then undergo the LS step,
 * otherwise, choose another vertex untill it has that kind of neighbors
 */
int CheckDiffNeibor(int nodeid,int* pos,vector<int>&nborlabel)
{
	nborlabel.clear();
	int nborsize = node[nodeid].degree;

	for (int i = 0; i < nborsize; i++)
	{
		int temp = node[nodeid].neighbours[i];
		nborlabel.push_back(pos[temp]);
	}
 
	sort(nborlabel.begin(), nborlabel.end());
	//把重复部分挪到最后然后一起删除 
	nborlabel.resize(unique(nborlabel.begin(), nborlabel.end()) - nborlabel.begin());

	for(vector<int>::iterator iter=nborlabel.begin(); iter!=nborlabel.end(); )
	{
		if(*iter == pos[nodeid])
		{
			iter = nborlabel.erase(iter);
			break;
		}
		else iter++;                                                                                                                                                                                                                                                                                                                                   
	}

// 	for (int s = 0; s < nborsize; s++)
// 		cout<<nborlabel[s]<<" ";cout<<endl;
		
	if (nborlabel.size() != 0)
	{
		return 1;
	} 
	else
	{
		return 0;
	}
}

/*
 * neighbor based greedy local search on a particle
 * implement the LS step on every vertex (too slow)
 */
void LS_All_Node(int* pos,double currentfit)
{
	int i,j,k;
	vector<int>difflabel;
	double BestFit = 0;			            //best chrom's density
	
	//*
	for (int id = 0; id < vertices; id++)
	{
		vector<int>i_label_equal;

		if (CheckDiffNeibor(id,pos,difflabel))
		{
			vector<double>fitness;			//record best density of the neighbors
			int unique_num = difflabel.size();
			vector<vector<int> > i_neighbor_label_equal(unique_num);
			for (j = 0; j < vertices; j++)
				if (j != id && pos[j] == pos[id])
					i_label_equal.push_back(j);

			for (k = 0; k < unique_num; k++)
				for (j = 0; j < vertices; j++)
					if (pos[j] == difflabel[k])
						i_neighbor_label_equal[k].push_back(j);
			
			for (i = 0; i < unique_num; i++)
			{
				double tempfit = deltaQ_function(i_label_equal,i_neighbor_label_equal[i],id);
				fitness.push_back(tempfit);
			}
			
			BestFit = *max_element(fitness.begin(),fitness.end());
			
			//find the biggest D amongst the neighbor_RandGene
			if (BestFit > 0)
			{
				for (j = 0;j < unique_num;j++)
				{
					if(fitness[j] == BestFit)
					{
						pos[id] = difflabel[j];
						currentfit += BestFit;
					}
					break;
				}
			}
			else
			{	/*
				int possibility = rnd_uni(&rnd_uni_init);
				if (possibility < 0.5)
					pos[id] = vertices * rnd_uni(&rnd_uni_init);//*/
			}
		}
	}//*/

	/*
	while (!CheckDiffNeibor(RandGene,pos,difflabel))
	{
		RandGene = vertices * rnd_uni(&rnd_uni_init);
	}

	for(k = 0; k < vertices; k++)
		copylabel[k] = pos[k];

	for (i = 0; i < difflabel.size(); i++)
	{
		copylabel[RandGene] = difflabel[i];
		double tempfit = modularity(copylabel);
		fitness.push_back(tempfit);
	}

	BestFit = *max_element(fitness.begin(),fitness.end());
				
	//find the biggest D amongst the neighbor_RandGene
	if (BestFit > currentfit)
	{
		for (j = 0;j < difflabel.size();j++)
		{
			if(fitness[j] == BestFit)
			{
				pos[RandGene] = difflabel[j];
				currentfit = BestFit;
			}
			break;
		}
	}//*/

	sorting(pos);
}
//*/


/*
 * neighbor based greedy local search on one particle
 * implement the LS step on one vertex
 */
void LS_One_Node(int* pos,double currentfit)
{
	int i,j,k;
	int RandGene = vertices * rnd_uni(&rnd_uni_init);
	vector<int>difflabel;
	int* copylabel = new int[vertices];     //copy randchrom's gene
	vector<double>fitness;			 //record best density of the neighbors
	double BestFit = 0;			 //best chrom's density
	vector<int>i_label_equal;
	
	//*
	while (!CheckDiffNeibor(RandGene,pos,difflabel))
	{
		RandGene = vertices * rnd_uni(&rnd_uni_init);
	}

	int unique_num = difflabel.size();
	vector<vector<int> > i_neighbor_label_equal(unique_num);

	for (j = 0; j < vertices; j++)
	{
		if (j != RandGene && pos[j] == pos[RandGene])
		{
			i_label_equal.push_back(j);
		}
	}

	for (k = 0; k < unique_num; k++)
	{
		for (j = 0; j < vertices; j++)
		{
			if (pos[j] == difflabel[k])
			{
				i_neighbor_label_equal[k].push_back(j);
			}
		}
	}

	for (i = 0; i < unique_num; i++)
	{
		double tempfit = deltaQ_function(i_label_equal,i_neighbor_label_equal[i],RandGene);
		fitness.push_back(tempfit);
	}

	BestFit = *max_element(fitness.begin(),fitness.end());
				
	//find the biggest D amongst the neighbor_RandGene
	if (BestFit > 0)
	{
		for (j = 0;j < unique_num;j++)
		{
			if(fitness[j] == BestFit)
			{
				pos[RandGene] = difflabel[j];
				currentfit += BestFit;
			}
			break;
		}
	}//*/

	sorting(pos);
}
//*/


/*
 * BGLL local search
 * 
 */
void LS_One_Node1(int* pos,double currentfit)
{
	vector<vector<int> >community;

	int i,j,k;
	int RandGene = vertices * rnd_uni(&rnd_uni_init);
	vector<int>difflabel;
	int* copylabel = new int[vertices];     //copy randchrom's gene
	vector<double>fitness;			 //record best density of the neighbors
	double BestFit = 0;			 //best chrom's density
	vector<int>i_label_equal;
	
	//*
	while (!CheckDiffNeibor(RandGene,pos,difflabel))
	{
		RandGene = vertices * rnd_uni(&rnd_uni_init);
	}

	int unique_num = difflabel.size();
	vector<vector<int> > i_neighbor_label_equal(unique_num);

	for (j = 0; j < vertices; j++)
	{
		if (j != RandGene && pos[j] == pos[RandGene])
		{
			i_label_equal.push_back(j);
		}
	}

	for (k = 0; k < unique_num; k++)
	{
		for (j = 0; j < vertices; j++)
		{
			if (pos[j] == difflabel[k])
			{
				i_neighbor_label_equal[k].push_back(j);
			}
		}
	}

	for (i = 0; i < unique_num; i++)
	{
		double tempfit = deltaQ_function(i_label_equal,i_neighbor_label_equal[i],RandGene);
		fitness.push_back(tempfit);
	}

	BestFit = *max_element(fitness.begin(),fitness.end());
				
	//find the biggest D amongst the neighbor_RandGene
	if (BestFit > 0)
	{
		for (j = 0;j < unique_num;j++)
		{
			if(fitness[j] == BestFit)
			{
				pos[RandGene] = difflabel[j];
				currentfit += BestFit;
			}
			break;
		}
	}//*/

	sorting(pos);
}
//*/






#endif
