#ifndef _PSO_H_H_
#define _PSO_H_H_



#include "global.h"
#include "individual.h"
#include "NMI.h"
#include "mutation.h"
#include "LS.h"

/*
 * 粒子群类                                                     
 */
class ParticleSwarm
{
public:

	ParticleSwarm();
	~ParticleSwarm();

	vector<Particle>PSO_pop;

	void getGBest();  //获取全局极值
	void search();  
	void execute(int trial);	

};

ParticleSwarm::ParticleSwarm()
{
	gbest = -1e10;
	//初始化种群,包括位置，速度，fitness和pbest
	
	for(int i=0;i<PSO_popsize;i++)
	{  
		Particle pso;
		pso.initial();
		pso.obj_eval();
		PSO_pop.push_back(pso);
	}		  

	getGBest();	
}

ParticleSwarm::~ParticleSwarm()
{

}


void ParticleSwarm::getGBest()
{
	vector<double> fit;
	double maxfit;
	int index;

	for(int i=0;i<PSO_popsize;i++)
		fit.push_back(PSO_pop[i].fitness);

	maxfit = *max_element(fit.begin(),fit.end());

	if (maxfit > gbest)
	{
		for(int j=0;j<PSO_popsize;j++)
		{
			if (PSO_pop[j].fitness == maxfit)
			{
				index = j;
				break;
			}
		}
		gbest = maxfit;
		for(int k=0;k<vertices;k++)
			gbest_pos[k] = PSO_pop[index].pos[k];		  
	}
}

//迭代
void ParticleSwarm::search()
{  
	for(int k = 0; k < PSO_popsize; k++)
	{
		PSO_pop[k].updateVelocity();
		PSO_pop[k].updatePosition();

		if (k < PSO_popsize*pm)  realmutation(PSO_pop[k].pos);

	//	NborBasedMutate(PSO_pop[k].pos);
			 
		PSO_pop[k].obj_eval();

	//	LS_One_Node(PSO_pop[k].pos,PSO_pop[k].fitness);
	//	LS_All_Node(PSO_pop[k].pos,PSO_pop[k].fitness);

		PSO_pop[k].updatePBest();
	}
}

void ParticleSwarm::execute(int trial)
{			

	_LARGE_INTEGER time_start;    //*开始时间
	_LARGE_INTEGER time_over;     //*结束时间
	_LARGE_INTEGER time_step;     //*每代时间
	double dqFreq;                //*计时器频率
	LARGE_INTEGER f;              //*计时器频率
	QueryPerformanceFrequency(&f);
	dqFreq=(double)f.QuadPart;
	QueryPerformanceCounter(&time_start);

	vector<double>Qvalue;		//用于记录每代的Q值                                                                                                                                                                                                                                                                                                                            e>costtime;		//用于记录每代的时间
	vector<double>costtime;

	for(int gen = 0; gen < PSO_maxgen; gen++) 
	{
		search();

		QueryPerformanceCounter(&time_step);
		costtime.push_back((time_step.QuadPart - time_start.QuadPart)/dqFreq);
		
        getGBest();		
	
	//	LS_One_Node(gbest_pos,gbest);
	//	LS_All_Node(gbest_pos,gbest);
	
		Qvalue.push_back(gbest);
	}

	int timeindex;

	for (int tempindex = 0; tempindex < PSO_maxgen; tempindex++)
	{
		if (gbest == Qvalue[tempindex])
		{
			timeindex = tempindex;
			break;
		}
	}
	mintime = costtime[timeindex];
	
	QueryPerformanceCounter(&time_over);
	cout<<"一次总运行时间:"<<(time_over.QuadPart - time_start.QuadPart)/dqFreq<<"秒！"<<endl;	
			
	if (checkLabelFile(DataLabelFile))
		calc_NMI(gbest_pos,DataLabelFile);								

	PrintConvergence(trial,Qvalue);
	
/****************************************************************************************

	ofstream output("LPA.txt",ios::out);
	
	for (int i = 0;i < PSO_maxgen;i++ )
	{
		
		output << modularity[i]<<" ";
	}
//***************************************************************************************/


//****************************************************************************************

}

#endif







