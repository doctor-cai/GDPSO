/************************************************************/
/*          Copyright (c) 2013--2014                        */
/*==========================================================*/
/*	  西安电子科技大学智能感知与图像理解教育部重点实验室    */
/*==========================================================*/
/*    All rights reserved.    版权所有					    */
/*==========================================================*/
/*	  文件名称：Fast GDPSO.cpp							    */
/*==========================================================*/
/*    当前版本：1.0							   			    */
/*==========================================================*/
/* 作    者：蔡 清											*/
/*==========================================================*/
/* 起 始 日 期：2013年10月10日								*/
/* 完 成 日 期：2013年10月10日								*/
/*==========================================================*/
/* any questions, contact 2008_jammy@163.com  				*/
/************************************************************/


//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////



////////////////////////////
#include "PSO.h"
#include "global.h"
////////////////////////////

void main()
{

	cout<<"程序正在运行......."<<endl;

							
	char *LFRData[] = {"0.0.txt",    "0.05.txt",	"0.1.txt",\
					   "0.15.txt",	 "0.2.txt",\
					   "0.25.txt",	 "0.3.txt",\
					   "0.35.txt",	 "0.4.txt",\
					   "0.45.txt",   "0.5.txt" };
	
	char *LFRDataLabel[] ={"real0.0.txt",     "real0.05.txt",  "real0.1.txt",\
						   "real0.15.txt",	  "real0.2.txt",\
				     	   "real0.25.txt",	  "real0.3.txt",\
						   "real0.35.txt",	  "real0.4.txt",\
						   "real0.45.txt",    "real0.5.txt" };

	//*
	char *RealData[] = {"karate.txt",	"dolphin.txt",\
						"football.txt",	"SFI.txt",\
						"email.txt",    "netscience_remove.txt",\
						"power.txt",    "PGP_adj.txt"};//*/

	/*
	char *RealData[] = {"karate.pairs",	    "dolphin.pairs",\
						"football.pairs",	"SFI.pairs",\
						"email.pairs",      "netscience_remove.pairs",\
						"power.pairs",      "PGP_adj.pairs"};//*/
					
	int  nvars[] =  {34,  62, 115, 118, 1133, 1461, 4941, 10680, 141};

	int  nedges[] = {78, 159, 613, 200, 5451, 2742, 6594, 24340, 480};
	
	char *RealDataLabel[] ={"real_label_karate.txt",    "real_label_dolphin.txt",\
							"real_label_football.txt",	"does not exist",\
							"does not exist",		    "does not exist",\
							"does not exist", 			"does not exist",    "does not exist"};

	char *ObtainCLU[] ={"GDPSO_karate.CLU",      "GDPSO_dolphin.CLU", 
						"GDPSO_football.CLU",    "GDPSO_SFI.CLU", 	    
						"GDPSO_email.CLU",       "GDPSO_netsci_remove.CLU", 
						"GDPSO_power.CLU",       "GDPSO_pgp.CLU",            "GDPSO_war.CLU"};

	int n = 8;
//	for(int n=9; n<10; n++)
//	for(n = 4; n < 8; n++)
	{
		//* test for real social network
		char    FilePath[256];
		char    LabelPath[256];		
		strcpy(FilePath,"E:\\我搞定的程序\\SI\\DPSOCD\\");
		strcat(FilePath,RealData[n]);
		strcpy(DataFile,FilePath);

		strcpy(LabelPath,"E:\\我搞定的程序\\SI\\DPSOCD\\");
		strcat(LabelPath,RealDataLabel[n]);	
		strcpy(DataLabelFile,LabelPath);
		strcpy(SaveFile,ObtainCLU[n]);

		vertices  = nvars[n];
		edges = nedges[n];//*/

		/*
		char    FilePath[256];
		char    LabelPath[256];		
		strcpy(FilePath,"E:\\我搞定的程序\\SI\\DPSOCD\\");
		strcat(FilePath,LFRData[n]);
		strcpy(DataFile,FilePath);
		
		strcpy(LabelPath,"E:\\我搞定的程序\\SI\\DPSOCD\\");
		strcat(LabelPath,LFRDataLabel[n]);	
		strcpy(DataLabelFile,LabelPath);
		strcpy(SaveFile,ObtainCLU[n]);

		vertices  = 128;
		edges = 1024;//*/

		AllocateMemory();
		
		ReadFile(DataFile,AdjMatrix,vertices,vertices);

		/*
		ReadFile(DataFile,pairs,edges,2);
		CreateMatrix();//*/
		
		NodeInformation(node,AdjMatrix,vertices);
		
		seed = (seed + 111)%1235;	
		rnd_uni_init = -(long)seed;	
   //*
		for (int i = 1; i <= RUNTIMES; i++)
		{
			cout<<"第"<<i<<"次运行.......";

			ParticleSwarm PSO;
			PSO.execute(i);	

			if (checkLabelFile(DataLabelFile))
			{		
	 			cout<<"NMI value is: "<<NMI<<endl;
				Thirty_Run_NMI.push_back(NMI);
			}

			cout<<"Q value is: "<<gbest<<endl;
			Thirty_Run_modularity.push_back(gbest);		
			
			cout<<"time for first reaching max Q is: "<<mintime<<endl<<endl;
			Thirty_Run_time.push_back(mintime);	

		//	PrintPartition(i,gbest_pos,SaveFile,vertices);
		}		

		if (checkLabelFile(DataLabelFile))
		{
			for (int j = 0; j < RUNTIMES; j++)
				NMIavg += Thirty_Run_NMI[j];

			NMImax = *max_element(Thirty_Run_NMI.begin(),Thirty_Run_NMI.end());
			NMIavg = NMIavg/RUNTIMES;
			cout<<endl<<endl<<"max NMI = "<<NMImax<<"   "<<"avg NMI = "<<NMIavg<<endl;
		}
	
		Qmax = *max_element(Thirty_Run_modularity.begin(),Thirty_Run_modularity.end());
		for (int k = 0; k < RUNTIMES; k++)	
			Qavg += Thirty_Run_modularity[k];

		Qavg = Qavg/RUNTIMES;
		cout<<"max Q = "<<Qmax<<"    "<<"avg Q = "<<Qavg<<endl;

		for (int m = 0; m < RUNTIMES; m++)	
			timeavg += Thirty_Run_time[m];
		
		timeavg /= RUNTIMES;
		cout<<"averaged time = "<<timeavg<<"秒"<<endl<<endl;

	//	PrintResult();

	//	PrintPartition(gbest_pos,SaveFile,vertices);//*/
	
	}

	cout<<"程序运行完毕"<<endl;
//	system("pause");

}//end main




