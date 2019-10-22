#ifndef _GLOBAL_H_H_H
#define _GLOBAL_H_H_H


#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <memory.h>
#include <vector>
#include <algorithm>	
#include <limits>		
#include <windows.h>


using namespace std;



#define RUNTIMES 1    
#define CONSTANTNUM 1000

#define PSO_popsize 100     //��Χ��20-60��̫��̫С������       
                 
#define PSO_maxgen 250	    //50-300

#define rnd(low,uper) ((rand()/(double)RAND_MAX)*((uper)-(low))+(low))

int		vertices;
int		edges;

char    DataFile[256];
char    DataLabelFile[256];
char    SaveFile[256];


double  NMI;
double  mintime;
int     seed = 237;
long    rnd_uni_init;	       // parameters for random number generation

/* һ��ȡw=0.729��c1=c2=1.494�����Ա�֤�㷨���� */
double paramater_w =0.7298;	   //��ʷϵ���� �ɳ���������� ,[0-1]
double paramater_c1=1.4961;    //��֪ϵ�����ȽϹ��ϵ�ֵ 
double paramater_c2=1.4961;    //���ϵ��, �ȽϹ��ϵ�ֵ 
double pm = 0.1;

vector<double> Thirty_Run_time;
vector<double> Thirty_Run_NMI;
vector<double> Thirty_Run_modularity;
vector<double> Conv_Traj;
vector<int> clusters;

double timeavg;
double NMIavg;
double NMImax;
double Qmax;
double Qavg;


struct network 
{
	vector<int> neighbours;
	int degree;	
};

int** AdjMatrix;
double** pairs;       
network* node;
int* gbest_pos;       //ȫ�ּ�ֵ������,ע����ParticleSwarm::getGBest()����
double gbest = -1e10; //ȫ�ּ�ֵ����Ӧֵ



#endif

