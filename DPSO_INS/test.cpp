


//////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////



////////////////////////////
#include "PSO.h"
#include "global.h"
////////////////////////////

void main()
{

	cout<<"程序正在运行......."<<endl;

	char *RealData[] = {"karate.txt",	"dolphin.txt",\
						"football.txt",	"SFI.txt",\
						"email.txt",    "netscience_remove.txt",\
						"power.txt",    "PGP_adj.txt"};
					
	int  nvars[] =  {34,  62, 115, 118, 1133, 1461, 4941, 10680};

	int  nedges[] = {78, 159, 613, 200, 5451, 2742, 6594, 24340};
	
	char *ObtainCLU[] ={"infomap_karate.CLU",      "infomap_dolphin.CLU", 
						"infomap_football.CLU",    "infomap_SFI.CLU", 	    
						"infomap_email.CLU",       "infomap_netscience.CLU", 
						"infomap_power.CLU",       "infomap_pgp.CLU"};

	int n = 1;

	//* test for real social network
	char   FilePath[256];	
	strcpy(FilePath,"E:\\我搞定的程序\\SI\\DPSOCD\\");
	strcat(FilePath,RealData[n]);
	strcpy(DataFile,FilePath);

	
	strcpy(SaveFile,ObtainCLU[n]);

	vertices  = nvars[n];
	edges = nedges[n];//*/

	int * pos = new int [vertices];

	AllocateMemory();
		
	ReadFile(DataFile,AdjMatrix,vertices,vertices);
		
	NodeInformation(node,AdjMatrix,vertices);

	ifstream input(SaveFile,ios::in);
	
	if(input.fail())
	{
		cout<<"Oops!Couldn't open file\n";
		exit(1);
	}
	
	for (int i = 0;i < vertices;i++ )
		input >> pos[i];

	input.close();
	
	gbest = modularity(pos);

	cout<<"Q value is: "<<gbest<<endl;

	cout<<"程序运行完毕"<<endl;

}//end main




