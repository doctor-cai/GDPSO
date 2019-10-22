#ifndef _INDIVIDUAL_H_
#define _INDIVIDUAL_H_


#include "objective.h"
#include "IGLP.h"
#include "selection.h"


/*
 * 单个粒子类                                                           
*/
class Particle 
{
public:
	int* pos; 		    //粒子位置
	int* v; 			//粒子速度
	double pbestfit;    //个体最优值
	int* pbest_pos;     //个体最优解的坐标
	double fitness;     //当前算出的一个适应值

public:
	Particle();
	virtual ~Particle();

	void initial();
	void obj_eval();
	void updatePosition(); 
	void updateVelocity(); 
	void updatePBest();	 
};

Particle::Particle()
{
	pos = new int[vertices]; 		 //粒子位置
	v = new int[vertices]; 			 //粒子速度
	pbestfit = -1e10;		         //个体最优值
	pbest_pos = new int[vertices];   //个体最优解的坐标
	fitness = -1e10;                 //当前算出的一个适应值
}

Particle::~Particle()
{
}

void Particle::initial()
{	//初始化，and将当前fitness赋给pbest

//	IGLP(pos,node,vertices);

	//*
	for (int row = 0; row < vertices; row++)
		pos[row] = row+1;	
	perturbation(pos,vertices);

	IGLP1(pos,node,vertices);//*/

//	heuristic_initial(pos);

//	rand_initial(pos);

//	sorting(pos);
	
	for (int i = 0; i < vertices; i++)
	{
		v[i] = 0;	
		pbest_pos[i] = pos[i];
	}
	
//	fitness = modularity(pos);
//	pbestfit = fitness ;
}


void Particle::obj_eval()
{
	fitness = modularity(pos);	
}


void Particle::updateVelocity()
{
	double v1, v2;
	for(int i=0;i<vertices;i++)
    {			
        //更新速度，利用粒子的pbest_pos，和全局的  gbest_pos_global[]
		if (pbest_pos[i] != pos[i])
			v1 = 1;
		else v1 = 0;
		
		if (gbest_pos[i] != pos[i])
			v2 = 1;
		else v2 = 0;

		/*
		double velocity = v[i]*paramater_w + paramater_c1*rnd(0,1)*v1 + paramater_c2*rnd(0,1)*v2;		
 		if (velocity > 1) v[i] = 1;
 		else v[i] = 0;//*/

		/*
		double velocity = v[i]*paramater_w + paramater_c2*rnd(0,1)*v2;		
 		if (velocity > 1) v[i] = 1;
 		else v[i] = 0;//*/

		/*
		double velocity = v1 + v2;		
 		if (velocity == 2) v[i] = 1;
 		else v[i] = 0;//*/
	
		/*
		double velocity = v[i] + v1 + v2;
 		if (velocity == 3) v[i] = 1;
 		else v[i] = 0;//*/

		/*
		double velocity = v[i] + v2;
 		if (velocity == 2) v[i] = 1;
 		else v[i] = 0;//*/

		/*
		double velocity = v2;
 		if (velocity == 1) v[i] = 1;
 		else v[i] = 0;//*/

		//* it seems to be the best
		double velocity = v[i]*paramater_w + paramater_c1*rnd(0,1)*v1 + paramater_c2*rnd(0,1)*v2;		
		double sigmoid = 1.0/(1.0+exp(-velocity));
		if (rnd_uni(&rnd_uni_init) < sigmoid)
			v[i] = 1;
 		else v[i] = 0;//*/
	}
}

void Particle::updatePosition()
{
	//更新位移pos[i] += v[i];
	for (int i=0;i<vertices;i++)
	{
		if (v[i] == 1)
		{
		//	SelectDorminate(i,pos);
		//	SelectMaxDegree(i,pos);
			SelectDeltaQ(i,pos,v[i]);
		//	SelectRandNeibor(i,pos);
		}
						
	}//end for	

	//*实验发现排序效果好些，时间也短些
	sorting(pos);
	//*/
}

//更新个体极值	
void Particle::updatePBest()
{	
	if(this->fitness > pbestfit)
	{
		pbestfit = this->fitness;
		for(int i=0;i<vertices;i++)
		{
			pbest_pos[i]=pos[i];	
		}
	}
}

#endif
