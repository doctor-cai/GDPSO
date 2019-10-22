#ifndef _PSO_H_H_
#define _PSO_H_H_



#include "global.h"
#include "individual.h"
#include "NMI.h"
#include "mutation.h"
#include "LS.h"

/*
 * ����Ⱥ��                                                     
 */
class ParticleSwarm
{
public:

	ParticleSwarm();
	~ParticleSwarm();

	vector<Particle>PSO_pop;

	void getGBest();  //��ȡȫ�ּ�ֵ
	void search();  
	void execute(int trial);	

};

ParticleSwarm::ParticleSwarm()
{
	gbest = -1e10;
	//��ʼ����Ⱥ,����λ�ã��ٶȣ�fitness��pbest
	
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

//����
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

	_LARGE_INTEGER time_start;    //*��ʼʱ��
	_LARGE_INTEGER time_over;     //*����ʱ��
	_LARGE_INTEGER time_step;     //*ÿ��ʱ��
	double dqFreq;                //*��ʱ��Ƶ��
	LARGE_INTEGER f;              //*��ʱ��Ƶ��
	QueryPerformanceFrequency(&f);
	dqFreq=(double)f.QuadPart;
	QueryPerformanceCounter(&time_start);

	vector<double>Qvalue;		//���ڼ�¼ÿ����Qֵ                                                                                                                                                                                                                                                                                                                            e>costtime;		//���ڼ�¼ÿ����ʱ��
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
	cout<<"һ��������ʱ��:"<<(time_over.QuadPart - time_start.QuadPart)/dqFreq<<"�룡"<<endl;	
			
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







