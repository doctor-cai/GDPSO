#ifndef _NEIGHBORSELECTION_H
#define _NEIGHBORSELECTION_H


/*****************************************************/
/*******从邻居随机选择点进行更新**********************
/*****************************************************/
void SelectRandNeibor(int id, int* pos)
{
	//实验结果发现随机选，Q值会得到更大的，shit
	int temp = node[id].neighbours.size();
	
	if (temp == 0) cout<<"node "<<id<<" is empty!"<<endl;
	
	if (temp == 1) pos[node[id].neighbours[0]] = pos[id];

	if (temp > 1)
	{
		temp = rnd_uni(&rnd_uni_init) * temp;			

		pos[id] = pos[node[id].neighbours[temp]];
	}
}


/**********************************************************************************/
//**********************从邻居选择大多数占优的点进行更新****************************
/**********************************************************************************/
void SelectDorminate(int i, int* pos)
{
	int	sum = 0;
	int maxr = -1;//record index of i's neighbour which ...	
	int label = -1;
	int	temp = 1;
						
	if(node[i].neighbours.size() > 1)
	{
		for ( int j = 0;j < node[i].neighbours.size();j++ )
		{
			int counter = 1;//record no. of nodes that has same label with j
								
			for ( int k = j + 1;k < node[i].neighbours.size();k++ )
			{
				int p = pos[node[i].neighbours[j]];
				int q = pos[node[i].neighbours[k]];
				if( p == q )  counter++;
			}//end k
								
			if ( temp < counter )
			{
				maxr = j;
				temp = counter;
			}
		}//end j
							
		for ( int l = 0;l < node[i].neighbours.size();l++ )
		{
			int u = pos[node[i].neighbours[l]];
			int v = pos[i];
			if ( u == v )
				label = u;
		}//end l

		if (maxr != -1)
		{
			pos[i] = pos[node[i].neighbours[maxr]];
		} 
		else
		{					
			int randneighbor = rnd_uni(&rnd_uni_init)*node[i].neighbours.size();
			 pos[i] = pos[node[i].neighbours[randneighbor]];				
		}
	}//end if
	else 
	{
		if (node[i].neighbours.size() == 1)
		{
		//	pos[node[i].neighbours[0]] =  pos[i]; //实验发现这个效果不好，为什么呢，亲！
			pos[i] =  pos[node[i].neighbours[0]];
		} 
		else
		{
			//	cout<<"第"<<i+1<<"个节点无连接"<<endl;
		}
							
	}
}//end 	 
		

/****************************************************************************/
//**********************从delataQ增加的角度去考虑****************************
/****************************************************************************/
void SelectDeltaQ(int i, int* pos, int &velocity)
{
	int neighborsize = node[i].neighbours.size();
	
	if(neighborsize > 1)
	{
		vector<int> neighbor_label;		//存储i节点邻居的类标
		vector<int>::iterator iter1;
		for (int nei = 0; nei < neighborsize; nei++)
		{
			neighbor_label.push_back(pos[node[i].neighbours[nei]]);
		}
		//删除neighbor_label中相同的元素，即计算邻居类标有几种
		sort(neighbor_label.begin(),neighbor_label.end());
		iter1 = unique(neighbor_label.begin(),neighbor_label.end());
		neighbor_label.erase(iter1,neighbor_label.end());

		for(vector<int>::iterator iter=neighbor_label.begin(); iter!=neighbor_label.end(); )
		{
			if(*iter == pos[i])
			{
				iter = neighbor_label.erase(iter);
				break;
			}
			else iter++;                                                                                                                                                                                                                                                                                                                                   
		}

		int unique_num = neighbor_label.size();
		if (unique_num != 0)
		{	//存储和node i 是一个社区的节点				
			vector<int> i_label_equal;  
			//存储i节点邻居有几个社区，每个社区的节点
			vector<vector<int> > i_neighbor_label_equal(unique_num);
			
			for (int j = 0; j < vertices; j++)
			{
				if (j != i && pos[j] == pos[i])
				{
					i_label_equal.push_back(j);
				}
			}

			for (int k = 0; k < unique_num; k++)
			{
				for (int id = 0; id < vertices; id++)
				{
					if (pos[id] == neighbor_label[k])
						i_neighbor_label_equal[k].push_back(id);
				}
			}

			//计算deltaQ的方法是：deltaQ = q2 -q1;
			// q1 = A_{i,j_in{gi}}-k_{i}*k_{j_in{gi}}/2m
			// q2 = A_{i,j_in{gineighbor}}-k_{i}*k_{j_in{gineighbor}}/2m
			// gi 是和i属于同一个社区的节点
			// gineighbor是和i的某个邻居属于同一个社区的节点
			vector<double> deltaQ;
			for ( int fuck = 0; fuck < unique_num; fuck++)
			{
				double temp = deltaQ_function(i_label_equal,i_neighbor_label_equal[fuck],i);
				deltaQ.push_back(temp);
			}
			double max_deltaQ = -100000, min_deltaQ = 100000;
			int label_index = 0, label_index1;
			for (int shit = 0; shit < deltaQ.size(); shit++)
			{
				if (max_deltaQ < deltaQ[shit])
				{
					max_deltaQ = deltaQ[shit];
					label_index = shit;
				}
				if (min_deltaQ > deltaQ[shit])
				{
					min_deltaQ = deltaQ[shit];
					label_index1 = shit;
				}
			}
			if (max_deltaQ > 0)
			{
				pos[i] = pos[i_neighbor_label_equal[label_index][0]];
			} 
			else
			{
			//	velocity = 0;
// 				if (rnd_uni(&rnd_uni_init) < pm)
// 				{
// 				//	pos[i] = pos[i_neighbor_label_equal[label_index][0]];
// 					pos[i] = pos[i_neighbor_label_equal[label_index1][0]];
// 				}
			}
		}
		
	}//end if neighbor.size > 1
	else 
	{
		if (neighborsize == 1)
		{
		//	pos[node[i].neighbours[0]] = pos[i];
			pos[i] = pos[node[i].neighbours[0]];
		} 
		else
		{
			//	cout<<"第"<<i+1<<"个节点无连接"<<endl;
			//	pos[i] = 0;
		}				
	}
}//end 



/****************************************************************************/
//******************choose the node with biggest degree**********************
/****************************************************************************/
void SelectMaxDegree(int i, int* pos)
{
	int neighborsize = node[i].neighbours.size();
			
	if(neighborsize > 1)
	{
		vector<int> neighbor_degree;		//存储i节点邻居
		for (int nei = 0; nei < neighborsize; nei++)
		{
			int neighbornode = node[i].neighbours[nei];
			neighbor_degree.push_back(node[neighbornode].degree);
		}
		//	int max_degree = *max_element(neighbor_degree,neighbor_degree + neighborsize);
		int max_degree = *max_element(neighbor_degree.begin(),neighbor_degree.end());
		int nodeindex;
				
		for (int tempindex = 0; tempindex < neighborsize; tempindex++)
		{
			if (max_degree == neighbor_degree[tempindex])
			{
				nodeindex = tempindex;
				break;
			}
		}

		pos[i] = pos[node[i].neighbours[nodeindex]];
		
	}//end if neighbor.size > 1
	else 
	{
		if (neighborsize == 1)
		{
			pos[i] = pos[node[i].neighbours[0]];
		} 
		else
		{
			//	cout<<"第"<<i+1<<"个节点无连接"<<endl;
			//	pos[i] = 0;
		}
				
	}
}


#endif
