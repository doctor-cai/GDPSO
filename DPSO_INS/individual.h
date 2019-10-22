#ifndef _INDIVIDUAL_H_
#define _INDIVIDUAL_H_


#include "objective.h"
#include "IGLP.h"
#include "selection.h"


/*
 * ����������                                                           
*/
class Particle 
{
public:
	int* pos; 		    //����λ��
	int* v; 			//�����ٶ�
	double pbestfit;    //��������ֵ
	int* pbest_pos;     //�������Ž������
	double fitness;     //��ǰ�����һ����Ӧֵ

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
	pos = new int[vertices]; 		 //����λ��
	v = new int[vertices]; 			 //�����ٶ�
	pbestfit = -1e10;		         //��������ֵ
	pbest_pos = new int[vertices];   //�������Ž������
	fitness = -1e10;                 //��ǰ�����һ����Ӧֵ
}

Particle::~Particle()
{
}

void Particle::initial()
{	//��ʼ����and����ǰfitness����pbest

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
        //�����ٶȣ��������ӵ�pbest_pos����ȫ�ֵ�  gbest_pos_global[]
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
	//����λ��pos[i] += v[i];
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

	//*ʵ�鷢������Ч����Щ��ʱ��Ҳ��Щ
	sorting(pos);
	//*/
}

//���¸��弫ֵ	
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
