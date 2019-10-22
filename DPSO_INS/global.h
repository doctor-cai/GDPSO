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

#define PSO_popsize 100     //范围是20-60，太大太小都不好       
                 
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

/* 一般取w=0.729，c1=c2=1.494，可以保证算法收敛 */
double paramater_w =0.7298;	   //历史系数， 由程序随机生成 ,[0-1]
double paramater_c1=1.4961;    //认知系数，比较公认的值 
double paramater_c2=1.4961;    //社会系数, 比较公认的值 
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
int* gbest_pos;       //全局极值的坐标,注意由ParticleSwarm::getGBest()更新
double gbest = -1e10; //全局极值的适应值



#endif

