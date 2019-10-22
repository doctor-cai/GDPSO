#ifndef _IGLP_H_
#define _IGLP_H_


//#include "global.h"
#include "common.h"
#include "random.h"


/*
 *	如果邻居有大多数（最少两个）个体有相同标号i，则
 *  将该节点的类标换成i，如果没有这样的标号则看有没有
 *  邻居节点标号和该节点标号相同，有就选择它，否则就
 *  随机选取一个邻居的编号
 */

void IGLP(int *gene,network* node,int nodes)

{   //*
	int n,i,j,k,l;
	int *a = new int[nodes];
	for (int a_row = 0; a_row < nodes; a_row++)
		a[a_row] = a_row+1;
	
	perturbation(a,nodes);

	for ( n = 0;n < 5;n++ )
	{
		for ( i = 0;i < nodes;i++ )
		{	
			int randnode = a[i];
			int	sum = 0;
			int maxr = -1;//record index of i's neighbour which ...	
			int label = -1;
			int	temp = 1;
			
			if(node[randnode].neighbours.size() > 1)
			{
				for ( j = 0;j < node[randnode].neighbours.size() - 1;j++ )
				{
					int counter = 1;//record no. of nodes that has same label with j
					
					for ( k = j + 1;k < node[randnode].neighbours.size();k++ )
					{
						int p = gene[node[randnode].neighbours[j]];
 						int q = gene[node[randnode].neighbours[k]];
						if( p == q )  counter++;
					}//end k
					
					if ( temp < counter )
					{
						maxr = j;
						temp = counter;
					}
				}//end j
				
				for ( l = 0;l < node[randnode].neighbours.size();l++ )
				{
					int u = gene[node[randnode].neighbours[l]];
					int v = gene[randnode];
					if ( u == v )
					{
						label = u;
					}
				}//end l
				if (label != -1 && maxr == -1)
				{
					gene[randnode] = label;
				}
				else 
				{
					if (maxr != -1)
					{
						gene[randnode] = gene[node[randnode].neighbours[maxr]];
					} 
					else
					{
						int randneighbor = rnd_uni(&rnd_uni_init)*node[randnode].neighbours.size();
						gene[randnode] = gene[node[randnode].neighbours[randneighbor]];
					}
				}				
			}//end if
			else 
			{ 
				if (node[randnode].neighbours.size() == 1)
				{
					gene[randnode] = gene[node[randnode].neighbours[0]];
 				}
				else
				{
				//	cout<<"第"<<i+1<<"个节点无连接"<<endl;
				}
				
			}
		}//end i
	}//end n
	delete [] a;
	//*/
}

void IGLP1(int *gene,network* node,int nodes)

{   //*
	int n,i,j,k,l;
	
	for ( n = 0;n < 5;n++ )
	{		
		for ( i = 0;i < nodes;i++ )
		{	
			int	sum = 0;
			int maxr = -1;//record index of i's neighbour which ...	
			int label = -1;
			int	temp = 1;
			int NeighborSize = node[i].neighbours.size();
			if(NeighborSize > 1)
			{
				vector<int>NodeIdCounter; //record no. of nodes that have same id with each node
				for ( j = 0;j < NeighborSize;j++ )
				{
					int counter = 1;//record no. of nodes that has same label with j
					int p = gene[node[i].neighbours[j]];

					for ( k = j + 1;k < NeighborSize;k++ )
					{						
						int q = gene[node[i].neighbours[k]];
						if( p == q )  counter++;
					}//end k

					NodeIdCounter.push_back(counter);
				}//end j
				
				int DominatedID = *max_element(NodeIdCounter.begin(),NodeIdCounter.end());
				vector<int>HowMuch;
				for ( l = 0;l < NeighborSize;l++ )
				{
					if ( DominatedID == NodeIdCounter[l] )
					{
						HowMuch.push_back(l);
					}
				}//end l

				if (HowMuch.size() == 1)
				{
					gene[i] = gene[node[i].neighbours[HowMuch[0]]];
				}
				else 
				{
					int randneighbor = rnd_uni(&rnd_uni_init)*HowMuch.size();
					gene[i] = gene[node[i].neighbours[HowMuch[randneighbor]]];
				}				
			}//end if
			else 
			{
				if (NeighborSize == 1)
				{
					gene[i] = gene[node[i].neighbours[0]];
				} 
				else
				{
				//	cout<<"第"<<i+1<<"个节点无连接"<<endl;
				}
				
			}
		}//end i
	}//end n
	//*/

	/*
	int n,i,j,k,l;
	
	for ( i = 0;i < nodes;i++ )
	{	
		int	sum = 0;
		int maxr = -1;//record index of i's neighbour which ...	
		int label = -1;
		int	temp = 1;
		int NeighborSize = node[i].neighbours.size();
		if(NeighborSize > 1)
		{
			vector<int>NodeIdCounter; //record no. of nodes that have same id with each node
			for ( j = 0;j < NeighborSize;j++ )
			{
				int counter = 1;//record no. of nodes that has same label with j
				int p = gene[node[i].neighbours[j]];
					
				for ( k = j + 1;k < NeighborSize;k++ )
				{						
					int q = gene[node[i].neighbours[k]];
					if( p == q )  counter++;
				}//end k
					
				NodeIdCounter.push_back(counter);
			}//end j
				
			int DominatedID = *max_element(NodeIdCounter.begin(),NodeIdCounter.end());
			vector<int>HowMuch;
			for ( l = 0;l < NeighborSize;l++ )
			{
				if ( DominatedID == NodeIdCounter[l] )
				{
					HowMuch.push_back(l);
				}
			}//end l
				
			if (HowMuch.size() == 1)
			{
				gene[i] = gene[node[i].neighbours[HowMuch[0]]];
			}
			else 
			{
				int randneighbor = rnd_uni(&rnd_uni_init)*HowMuch.size();
				gene[i] = gene[node[i].neighbours[HowMuch[randneighbor]]];
			}				
		}//end if
		else 
		{
			if (NeighborSize == 1)
			{
				gene[i] = gene[node[i].neighbours[0]];
			} 
			else
			{
				//	cout<<"第"<<i+1<<"个节点无连接"<<endl;
			}
				
		}
	}//end i
	//*/
}


void heuristic_initial(int* gene)

{	/*
	int thita = 0.2 * edges;
	for ( int m = 0;m < thita;m++ )
	{
		int position  = int(vertices * rnd_uni(&rnd_uni_init));
		
		if (node[position].neighbours.size() != 0)
		{
			for ( int k = 0;k < node[position].neighbours.size();k++ )
			{			
				gene[node[position].neighbours[k]] = gene[position];
			}
		} 
	}//*/

	//*
	for ( int m = 0;m < vertices;m++ )
	{
		int nborsize  = node[m].neighbours.size();
		
		if (nborsize == 1)
		{
			 gene[m] = gene[node[m].neighbours[0]];
		} 
		else
		{
			if (nborsize > 1)
			{
// 				for ( int k = 0;k < nborsize;k++ )				
// 					gene[node[m].neighbours[k]] = gene[m];

				int rndnbor = nborsize * rnd_uni(&rnd_uni_init);
				gene[m] = gene[node[m].neighbours[rndnbor]];
				
			}
		}
 
	}//*/
}

void rand_initial(int* gene)

{
	for ( int m = 0;m < vertices;m++ )
	{
		gene[m]  = int(vertices * rnd_uni(&rnd_uni_init)); 
	}
}



#endif