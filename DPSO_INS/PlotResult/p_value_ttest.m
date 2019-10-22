%%%%%%%%%用welch's t-test计算p-value

%%%%%%%%% for testing %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% A1=[31 34 29 26 32 35 38 34 30 29 32 31];
% A2=[26 24 28 29 30 29 32 26 31 29 32 28];
% [H,P,ci,stats]=ttest2(A1,A2)
% 

%%%%%%%%%现计算我的算法与其他算法在无符号网络上的真实数据集上的p-value
clc;
clear all;
%%%%%% on karate network
GDPSO=[0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979];
LPA=[0.374425 0.358235 0.359961 0.415105 0.39908 0.402038 0.371466 0.359961 0.402038 1.42336e-017 0.132807 0.39908 0.371795 0.24548 1.42336e-017 0.375164 0.371466 0.39908 0.369083 0.354947 0.374425 0.371795 0.387492 0.359961 0.371795 1.42336e-017 0.374425 0.374425 0.402038 0.314842];
CNM=[0.38 0.38 0.38 0.38 0.38 0.38 0.38 0.38 0.38 0.38 0.38 0.38 0.38 0.38 0.38 0.38 0.38 0.38 0.38 0.38 0.38 0.38 0.38 0.38 0.38 0.38 0.38 0.38 0.38 0.38];
Informap=[0.402 0.402 0.402 0.402 0.402 0.402 0.402 0.402 0.402 0.402 0.402 0.402 0.402 0.402 0.402 0.402 0.402 0.402 0.402 0.402 0.402 0.402 0.402 0.402 0.402 0.402 0.402 0.402 0.402 0.402];
MOGA_net = [0.4161 0.417406312	0.415598291	0.419789612	0.419789612	0.419789612	0.419789612	0.418803419	0.415105194	0.415598291	0.415598291	0.415598291	0.402284681	0.419789612	0.406558185	0.417406312	0.419789612	0.419789612	0.415598291	0.411160421	0.419789612	0.415598291	0.415598291	0.415598291	0.419789612	0.419789612	0.415598291	0.419789612	0.405900723	0.411160421];

GA_karate_Q=[0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979];
GA_karate_NMI=[0.68726 0.68726 0.68726 0.68726 0.68726 0.68726 0.68726 0.68726 0.68726 0.68726 0.68726 0.68726 0.68726 0.68726 0.68726 0.68726 0.68726 0.68726 0.68726 0.68726 0.68726 0.68726 0.68726 0.68726 0.68726 0.68726 0.68726 0.68726 0.68726 0.68726];
GA_karate_t=0.198679;
GA_kqmax=max(GA_karate_Q);GA_kqavg=mean(GA_karate_Q);GA_knmimax=max(GA_karate_NMI);GA_knmiavg=mean(GA_karate_NMI);

kmean_karate_Q=[-0.1080704	0.09335963	0.09335963	0.002876397	0.1185897	-0.07108810	-0.1080704	0.09335963	0.1429158	0.09335963	-0.07108810	0.09335963	0.09335963	0.06697896	0.002876397	-0.05119987	0.1429158	0.1429158	-0.07108810	0.1429158	-0.07108810	0.09335963	0.1054405	-0.07108810	-0.07108810	0.09919461	-0.1080704	0.1429158	0.1429158	-0.05119987];
kmean_karate_NMI=[0.5609977	0.6573776	0.6573776	0.7003140	0.6890200	0.4321534	0.5609977	0.6573776	0.7366424	0.6573776	0.4321534	0.6573776	0.6573776	0.6890200	0.7003140	0.4312298	0.7366424	0.7366424	0.4321534	0.7366424	0.4321534	0.6573776	0.6509480	0.4321534	0.4321534	0.5865424	0.5609977	0.7366424	0.7366424	0.4312298];
kmean_karate_t=0.026148;%%%%% k=4
kmean_kQmax=max(kmean_karate_Q);kmean_kQavg=mean(kmean_karate_Q);kmean_knmimax=max(kmean_karate_NMI);kmean_knmiavg=mean(kmean_karate_NMI);

Ncut_karate_Q=[0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979];
Ncut_karate_NMI=[0.6872629	0.6872629	0.6872629	0.6872629	0.6872629	0.6872629	0.6872629	0.6872629	0.6872629	0.6872629	0.6872629	0.6872629	0.6872629	0.6872629	0.6872629	0.6872629	0.6872629	0.6872629	0.6872629	0.6872629	0.6872629	0.6872629	0.6872629	0.6872629	0.6872629	0.6872629	0.6872629	0.6872629	0.6872629	0.6872629];
Ncut_karate_t=0.004209; %%%%% k=4
Ncut_kQmax=max(Ncut_karate_Q);Ncut_kQavg=mean(Ncut_karate_Q);Ncut_knmimax=max(Ncut_karate_NMI);Ncut_knmiavg=mean(Ncut_karate_NMI);

% [H0,P0,ci,stats] = ttest2(GDPSO,LPA,0.05,'right');
% [H1,P1,ci,stats] = ttest2(GDPSO,CNM,0.05,'right');
% [H2,P2,ci,stats] = ttest2(GDPSO,Informap,0.05,'right');
% [H3,P3,ci,stats] = ttest2(GDPSO,MOGA_net,0.05,'right');
% P=[P0 P1 P2 P3];

[P1,H1] = ttest2(GDPSO,GA_karate_Q,0.05,'right');   
[P2,H2] = ttest2(GDPSO,MOGA_net,0.05,'right');
[P3,H3] = ttest2(GDPSO,LPA,0.05,'right');           
[P4,H4] = ttest2(GDPSO,CNM,0.05,'right');
[P5,H5] = ttest2(GDPSO,Informap,0.05,'right');      
[P6,H6] = ttest2(GDPSO,kmean_karate_Q,0.05,'right');
[P7,H7] = ttest2(GDPSO,Ncut_karate_Q,0.05,'right');
P=[P1 P2 P3 P4 P5 P6 P7];
H=[H1 H2 H3 H4 H5 H6 H7];


%%%%%% on dolphin network
GDPSO=[0.5285195 0.5386	0.5285195	0.5285195	0.5277283	0.5285195	0.5277283	0.5285195	0.5277283	0.5276096	0.5285195	0.5277283	0.5285195	0.5285195	0.5277283	0.5285195	0.5267988	0.5277283	0.5277283	0.5285195	0.5277283	0.5277283	0.5285195	0.5285195	0.5285195	0.5277283	0.5277283	0.5277283	0.5277283	0.5277283];
LPA=[0.480598 0.50621 0.503382 0.373482 0.518472 0.494976 0.510838 0.511788 0.52045 0.49288 0.52579 0.52045 0.467545 0.504668 0.52045 0.520687 0.480598 0.509869 0.510047 0.50621 0.52045 0.52045 0.494976 0.492939 0.34257 0.48135 0.519619 0.519619 0.50182 0.519619];
CNM=[0.495 0.495 0.495 0.495 0.495 0.495 0.495 0.495 0.495 0.495];  
Informap=[0.5247 0.5247 0.5247 0.5247 0.5247 0.5247 0.5247 0.5247 0.5247 0.5247];
MOGA_net = [0.507258415	0.523733238	0.511095289	0.503599541	0.499545113	0.508781298	0.519065702	0.511787508	0.515584827	0.523713461	0.519698588	0.510640402	0.52260591	0.51048218	0.495431352	0.504548871	0.504568648	0.506902417	0.508781298	0.522546576	0.517523041	0.522190578	0.50799019	0.524287014	0.508306633	0.512736838	0.50850441	0.525790119	0.501325106	0.51718682];

GA_dol_Q=[0.5285195	0.5285195	0.5285195	0.5277283	0.5285195	0.5277283	0.5285195	0.5273724	0.5277283	0.5276096	0.5285195	0.5277283	0.5285195	0.5285195	0.5277283	0.5285195	0.5267988	0.5277283	0.5277283	0.5285195	0.5277283	0.5277283	0.5285195	0.5285195	0.5285195	0.5277283	0.5277283	0.5277283	0.5277283	0.5277283];
GA_dol_NMI=[0.5864663	0.5864663	0.5864663	0.5932109	0.5864663	0.5932109	0.5864663	0.5864663	0.5932109	0.5880272	0.5864663	0.5932109	0.5864663	0.5864663	0.5932109	0.5864663	0.5714557	0.5932109	0.5932109	0.5864663	0.5932109	0.5932109	0.5864663	0.5864663	0.5864663	0.5932109	0.5932109	0.5932109	0.5932109	0.5932109];
GA_dol_t= 2.386804 ;
GA_dqmax=max(GA_dol_Q);GA_dqavg=mean(GA_dol_Q);GA_dnmimax=max(GA_dol_NMI);GA_dnmiavg=mean(GA_dol_NMI);

kmean_dol_Q=[0.3800087	0.3850718	0.3850718	0.3946837	0.4589613	0.3850718	0.3850718	0.3850718	0.4610577	0.3850718	0.3850718	0.4589613	0.3850718	0.3850718	0.2231715	0.4796487	0.3850718	0.3800087	0.3850718	0.3850718	0.4796487	0.4589613	0.2030181	0.3850718	0.2476959	0.3850718	0.1833590	0.3800087	0.3850718	0.3946837];
kmean_dol_NMI=[0.3859883	0.4464259	0.4464259	0.4524837	0.4130488	0.4464259	0.4464259	0.4464259	0.4183651	0.4464259	0.4464259	0.4130488	0.4464259	0.4464259	0.3351940	0.4067008	0.4464259	0.3859883	0.4464259	0.4464259	0.4067008	0.4130488	0.3511038	0.4464259	0.4750854	0.4464259	0.4547614	0.3859883	0.4464259	0.4524837];
kmean_dol_t=0.045728;%%%%% k=5
kmean_dQmax=max(kmean_dol_Q);kmean_dQavg=mean(kmean_dol_Q);kmean_dnmimax=max(kmean_dol_NMI);kmean_dnmiavg=mean(kmean_dol_NMI);

Ncut_dol_Q=[0.5068431	0.5068431	0.4996836	0.5068431	0.5068431	0.5068431	0.4996836	0.4996836	0.5068431	0.5068431	0.4996836	0.5068431	0.4996836	0.4996836	0.5068431	0.5068431	0.5068431	0.5068431	0.5068431	0.4996836	0.5068431	0.5068431	0.5068431	0.5068431	0.5068431	0.4996836	0.5068431	0.5068431	0.4996836	0.5068431];
Ncut_dol_NMI=[0.5222673	0.5222673	0.4761365	0.5222673	0.5222673	0.5222673	0.4761365	0.4761365	0.5222673	0.5222673	0.4761365	0.5222673	0.4761365	0.4761365	0.5222673	0.5222673	0.5222673	0.5222673	0.5222673	0.4761365	0.5222673	0.5222673	0.5222673	0.5222673	0.5222673	0.4761365	0.5222673	0.5222673	0.4761365	0.5222673];
Ncut_dol_t=0.008199; %%%%% k=5;
Ncut_dQmax=max(Ncut_dol_Q);Ncut_dQavg=mean(Ncut_dol_Q);Ncut_dnmimax=max(Ncut_dol_NMI);Ncut_dnmiavg=mean(Ncut_dol_NMI);

% [H0,P0,ci,stats] = ttest2(GDPSO,LPA,0.05,'right');
% [H1,P1,ci,stats] = ttest2(GDPSO,CNM,0.05,'right');
% [H2,P2,ci,stats] = ttest2(GDPSO,Informap,0.05,'right');
% [H3,P3,ci,stats] = ttest2(GDPSO,MOGA_net,0.05,'right');
% P=[P0 P1 P2 P3];

[P1,H1] = ttest2(GDPSO,GA_dol_Q,0.05,'right');   
[P2,H2] = ttest2(GDPSO,MOGA_net,0.05,'right');
[P3,H3] = ttest2(GDPSO,LPA,0.05,'right');        
[P4,H4] = ttest2(GDPSO,CNM,0.05,'right');
[P5,H5] = ttest2(GDPSO,Informap,0.05,'right');   
[P6,H6] = ttest2(GDPSO,kmean_dol_Q,0.05,'right');
[P7,H7] = ttest2(GDPSO,Ncut_dol_Q,0.05,'right');
P=[P1 P2 P3 P4 P5 P6 P7];
H=[H1 H2 H3 H4 H5 H6 H7];



%%%%%% on football network
GDPSO=[0.60457 0.603375 0.603375 0.60457 0.60457 0.603324 0.603375 0.603204 0.603324 0.603375 0.60457 0.60457 0.603204 0.603375 0.603204 0.603375 0.60457 0.60457 0.60457 0.60457 0.60457 0.60457 0.603204 0.603204 0.603375 0.603204 0.60457 0.60457 0.60457 0.603204];
LPA=[0.583575 0.568473 0.589483 0.601009 0.567541 0.598632 0.580713 0.583892 0.58377 0.601009 0.600775 0.601009 0.578217 0.598632 0.581078 0.582443 0.572618 0.58099 0.566534 0.599795 0.578613 0.53529 0.601009 0.592913 0.569436 0.602872 0.592913 0.602981 0.590612 0.557149];
CNM=[0.577 0.577 0.577 0.577 0.577 0.577 0.577 0.577 0.577 0.577 0.577 0.577 0.577 0.577 0.577 0.577 0.577 0.577 0.577 0.577 0.577 0.577 0.577 0.577 0.577 0.577 0.577 0.577 0.577 0.577];  
Informap=[0.6005 0.6005 0.6005 0.6005 0.6005 0.6005 0.6005 0.6005 0.6005 0.6005 0.6005 0.6005 0.6005 0.6005 0.6005 0.6005 0.6005 0.6005 0.6005 0.6005 0.6005 0.6005 0.6005 0.6005 0.6005 0.6005 0.6005 0.6005 0.6005 0.6005];
MOGA_net = [0.503600616	0.464848085	0.496233058	0.49205629	0.468857197	0.504784855	0.487719849	0.52486501	0.488991907	0.51254228	0.521623657	0.504609215	0.530364399	0.508004918	0.495457316	0.497433264	0.492676352	0.512471758	0.480134072	0.50270645	0.522101344	0.475345225	0.494761409	0.479321072	0.517899295	0.500279427	0.499852303	0.511633477	0.526248839	0.518977084];

GA_fot_NMI=[0.8265625	0.8201082	0.7908852	0.8072324	0.8443190	0.8346740	0.8022228	0.7991419	0.8396753	0.8141003	0.7808641	0.8383472	0.7995828	0.8102015	0.8221129	0.7966501	0.8603196	0.8069251	0.8407035	0.8655469	0.8316247	0.8480967	0.7720272	0.8491203	0.8444545	0.8204285	0.8061693	0.8041428	0.8417763	0.8644305];
GA_fot_Q=[0.5831562	0.5927724	0.5890494	0.5841581	0.5825880	0.5836378	0.5836232	0.5832999	0.5854434	0.5662255	0.5925782	0.5816858	0.5876935	0.5822154	0.5856298	0.5688308	0.5829965	0.5847316	0.5757740	0.5928536	0.5850416	0.5924903	0.5744806	0.5821356	0.5730848	0.5785669	0.5852479	0.5840650	0.5723037	0.5913726];
GA_fot_t= 4.927628 ;
GA_fqmax=max(GA_fot_Q);GA_fqavg=mean(GA_fot_Q);GA_fnmimax=max(GA_fot_NMI);GA_fnmiavg=mean(GA_fot_NMI);

kmean_fot_Q=[0.4563468	0.5475785	0.5320050	0.5053118	0.5043790	0.5242423	0.5301688	0.4486946	0.5129853	0.5039572	0.4670702	0.5783088	0.5783088	0.5084187	0.5399128	0.4208383	0.5239376	0.5030537	0.5723024	0.5186790	0.5475785	0.5174562	0.4343905	0.5109948	0.4487438	0.5245057	0.5783088	0.5729318	0.5165594	0.4623984];
kmean_fot_NMI=[0.8232716	0.8886625	0.8568297	0.8541871	0.8439134	0.8851190	0.8604020	0.7881382	0.8408677	0.8441863	0.8174787	0.8940526	0.8940526	0.8450519	0.8700912	0.7454765	0.8807040	0.8415553	0.8930359	0.8538000	0.8886625	0.8521199	0.7759283	0.8613431	0.8091488	0.8524664	0.8940526	0.8923476	0.8664188	0.8220717];
kmean_fot_t=0.054806;%%%%% k=12
kmean_fQmax=max(kmean_fot_Q);kmean_fQavg=mean(kmean_fot_Q);kmean_fnmimax=max(kmean_fot_NMI);kmean_fnmiavg=mean(kmean_fot_NMI);

Ncut_fot_Q=[0.6005166	0.6005166	0.6005166	0.6005166	0.6005166	0.6005166	0.6005166	0.6005166	0.6005166	0.6030633	0.6005166	0.6005166	0.6005166	0.6005166	0.6005166	0.6005166	0.6005166	0.6005166	0.6005166	0.6030633	0.6005166	0.6005166	0.6005166	0.6005166	0.6005166	0.6005166	0.6005166	0.6005166	0.6005166	0.6005166];
Ncut_fot_NMI=[0.9241952	0.9241952	0.9241952	0.9241952	0.9241952	0.9241952	0.9241952	0.9241952	0.9241952	0.9113703	0.9241952	0.9241952	0.9241952	0.9241952	0.9241952	0.9241952	0.9241952	0.9241952	0.9241952	0.9113703	0.9241952	0.9241952	0.9241952	0.9241952	0.9241952	0.9241952	0.9241952	0.9241952	0.9241952	0.9241952];
Ncut_fot_t=0.008831; %%%%% k=12
Ncut_fQmax=max(Ncut_fot_Q);Ncut_fQavg=mean(Ncut_fot_Q);Ncut_fnmimax=max(Ncut_fot_NMI);Ncut_fnmiavg=mean(Ncut_fot_NMI);

% [H0,P0,ci,stats] = ttest2(GDPSO,LPA,0.05,'right');
% [H1,P1,ci,stats] = ttest2(GDPSO,CNM,0.05,'right');
% [H2,P2,ci,stats] = ttest2(GDPSO,Informap,0.05,'right');
% [H3,P3,ci,stats] = ttest2(GDPSO,MOGA_net,0.05,'right');
% P=[P0 P1 P2 P3];

[P1,H1] = ttest2(GDPSO,GA_fot_Q,0.05,'right');   
[P2,H2] = ttest2(GDPSO,MOGA_net,0.05,'right');
[P3,H3] = ttest2(GDPSO,LPA,0.05,'right');        
[P4,H4] = ttest2(GDPSO,CNM,0.05,'right');
[P5,H5] = ttest2(GDPSO,Informap,0.05,'right');   
[P6,H6] = ttest2(GDPSO,kmean_fot_Q,0.05,'right');
[P7,H7] = ttest2(GDPSO,Ncut_fot_Q,0.05,'right');
P=[P1 P2 P3 P4 P5 P6 P7];
H=[H1 H2 H3 H4 H5 H6 H7];



%%%%%% on SFI network
GDPSO=[0.74245 0.74105 0.746675 0.745988 0.750588 0.744875 0.743875 0.750588 0.744875 0.74405 0.744388 0.740875 0.747725 0.741988 0.74405 0.745988 0.741988 0.740738 0.744738 0.748388 0.744875 0.747725 0.74245 0.744738 0.74405 0.744738 0.747725 0.746675 0.743725 0.745588];
LPA=[0.695488 0.70625 0.705825 0.720838 0.672963 0.693988 0.710575 0.721888 0.683888 0.727313 0.704963 0.723388 0.678225 0.721413 0.713075 0.729425 0.725713 0.734138 0.725775 0.705038 0.720788 0.710438 0.730338 0.68895 0.720713 0.728688 0.697675 0.717788 0.6577 0.713138];
CNM=[0.7335 0.7335 0.7335 0.7335 0.7335 0.7335 0.7335 0.7335 0.7335 0.7335 0.7335 0.7335 0.7335 0.7335 0.7335 0.7335 0.7335 0.7335 0.7335 0.7335 0.7335 0.7335 0.7335 0.7335 0.7335 0.7335 0.7335 0.7335 0.7335 0.7335];  
Informap=[0.7334 0.7334 0.7334 0.7334 0.7334 0.7334 0.7334 0.7334 0.7334 0.7334 0.7334 0.7334 0.7334 0.7334 0.7334 0.7334 0.7334 0.7334 0.7334 0.7334 0.7334 0.7334 0.7334 0.7334 0.7334 0.7334 0.7334 0.7334 0.7334 0.7334];
MOGA_net = [0.728 0.7212 0.7316	0.7322	0.7291	0.7299	0.743	0.7363	0.7354	0.7359 0.728	0.7212	0.7316	0.7322	0.7291	0.7299	0.743	0.7363	0.7354	0.7359 0.728 0.7212	0.7316	0.7322	0.7291	0.7299	0.743	0.7363	0.7354	0.7359];

GA_SFI_Q=[0.7505875	0.7505875	0.7505875	0.7505875	0.7505875	0.7505875	0.7505875	0.7505875	0.7505875	0.7505875	0.7505875	0.7505875	0.7505875	0.7505875	0.7505875	0.7505875	0.7505875	0.7505875	0.7505875	0.7486500	0.7505875	0.7505875	0.7505875	0.7505875	0.7505875	0.7505875	0.7505875	0.7505875	0.7505875	0.7493375];
GA_SFI_t=6.853579;
GA_sqmax=max(GA_SFI_Q);GA_sqavg=mean(GA_SFI_Q);

kmean_SFI_Q=[0.2405625	0.2524000	0.2840000	0.3674875	0.2876000	0.2047500	0.1744625	0.2625000	0.2502125	0.1895000	0.3771625	0.2870125	0.3049375	0.2778125	0.2482125	0.3139875	0.2836625	0.4376250	0.2590000	0.2825625	0.2700125	0.2598000	0.2502125	0.3035125	0.2998375	0.2294625	0.2759375	0.2998375	0.2601625	0.3056625];
kmean_SFI_t=0.034491;%%%%% k=7
kmean_SFIQmax=max(kmean_SFI_Q);kmean_SFIQavg=mean(kmean_SFI_Q);

Ncut_SFI_Q=[0.7477875	0.7399875	0.7477875	0.7477875	0.7399875	0.7477875	0.7477875	0.7477875	0.7477875	0.7477875	0.7477875	0.7477875	0.7477875	0.7477875	0.7399875	0.7477875	0.7477875	0.7477875	0.7477875	0.7477875	0.7477875	0.7477875	0.7477875	0.7477875	0.7477875	0.7477875	0.7477875	0.7477875	0.7477875	0.7477875];
Ncut_SFI_t=0.009460;%%%%% k=7
Ncut_SFIQmax=max(Ncut_SFI_Q);Ncut_SFIQavg=mean(Ncut_SFI_Q);

% [H0,P0,ci,stats] = ttest2(GDPSO,LPA,0.05,'right');
% [H1,P1,ci,stats] = ttest2(GDPSO,CNM,0.05,'right');
% [H2,P2,ci,stats] = ttest2(GDPSO,Informap,0.05,'right');
% [H3,P3,ci,stats] = ttest2(GDPSO,MOGA_net,0.05,'right');
% P=[P0 P1 P2 P3];

[P1,H1] = ttest2(GDPSO,GA_SFI_Q,0.05,'right');   
[P2,H2] = ttest2(GDPSO,MOGA_net,0.05,'right');
[P3,H3] = ttest2(GDPSO,LPA,0.05,'right');        
[P4,H4] = ttest2(GDPSO,CNM,0.05,'right');
[P5,H5] = ttest2(GDPSO,Informap,0.05,'right');   
[P6,H6] = ttest2(GDPSO,kmean_SFI_Q,0.05,'right');
[P7,H7] = ttest2(GDPSO,Ncut_SFI_Q,0.05,'right');
P=[P1 P2 P3 P4 P5 P6 P7];
H=[H1 H2 H3 H4 H5 H6 H7];



%%%%%% on email network
%GDPSO=[0.472488 0.458015 0.462528 0.500588 0.524416 0.505058 0.4748 0.462804 0.44882 0.453588 0.456042 0.465092 0.45249 0.492127 0.503315 0.455831 0.504107 0.450856 0.462468 0.49695 0.470948 0.490278 0.446344 0.427182 0.456521 0.472452 0.454986 0.534438 0.51188 0.447295];
GDPSO=[0.458799 0.468744 0.509663 0.469012 0.437326 0.492504 0.485734 0.494817 0.494945 0.448752 0.485532 0.465293 0.522373 0.439808 0.47229 0.498625 0.468613 0.500266 0.470657 0.486186 0.437425 0.487419 0.488787 0.482948 0.478258 0.450632 0.463059 0.457135 0.485094 0.548742];
LPA=[0.00109875 0.000732447 7.55335e-017 7.55335e-017 7.55335e-017 7.55335e-017 7.55335e-017 7.55335e-017 0.000733205 0.205465 7.55335e-017 7.55335e-017 7.55335e-017 7.55335e-017 7.55335e-017 7.55335e-017 7.55335e-017 7.55335e-017 0.000366754 7.55335e-017 7.55335e-017 7.55335e-017 7.55335e-017 7.55335e-017 7.55335e-017 0.00146432 7.55335e-017 7.55335e-017 7.55335e-017 7.55335e-017];
CNM=[0.4985 0.4985 0.4985 0.4985 0.4985 0.4985 0.4985 0.4985 0.4985 0.4985 0.4985 0.4985 0.4985 0.4985 0.4985 0.4985 0.4985 0.4985 0.4985 0.4985 0.4985 0.4985 0.4985 0.4985 0.4985 0.4985 0.4985 0.4985 0.4985 0.4985];  
Informap=[0.5355 0.5355 0.5355 0.5355 0.5355 0.5355 0.5355 0.5355 0.5355 0.5355 0.5355 0.5355 0.5355 0.5355 0.5355 0.5355 0.5355 0.5355 0.5355 0.5355 0.5355 0.5355 0.5355 0.5355 0.5355 0.5355 0.5355 0.5355 0.5355 0.5355];
MOGA_net=[0.32828 0.3022 0.30886 0.310157 0.308045 0.3103 0.3133 0.2979 0.2969 0.2993 0.2967 0.3068 0.2945 0.3095 0.32676 0.32828 0.3022 0.30886 0.310157 0.308045 0.3103 0.3133 0.2979 0.2969 0.2993 0.2967 0.3068 0.2945 0.3095 0.32676]';

GA_email_Q=[0.3539236	0.3421137	0.3622301	0.3533390	0.3476196	0.3399994	0.3556799	0.3501199	0.3547666	0.3378924	0.3403362	0.3365565	0.3440247	0.3575718	0.3526204	0.3612039	0.3537671	0.3544755	0.3588063	0.3455996	0.3500938	0.3646509	0.3432809	0.3424579	0.3498256	0.3456312	0.3501711	0.3481307	0.3435897	0.3591408];
GA_email_t=310.147804;
GA_eqmax=max(GA_email_Q);GA_eqavg=mean(GA_email_Q);

kmean_email_Q=[0.3681403	0.3681403	0.3568452	0.3681403	0.3583436	0.3622331	0.3681403	0.3583436	0.3681403	0.3681403	0.3292343	0.3670883	0.3670883	0.3622331	0.3583436	0.3292343	0.3292343	0.3622331	0.3622331	0.3670883	0.3670883	0.3681403	0.3681403	0.3292343	0.3583436	0.3583436	0.3681403	0.3681403	0.3681403	0.3681403];
kmean_email_t=5.25796;%%%%% k=4
kmean_emaiQmax=max(kmean_email_Q);kmean_emailQavg=mean(kmean_email_Q);

Ncut_email_Q=[0.4695904	0.4695904	0.4695904	0.4695904	0.4841237	0.4695904	0.4695904	0.4841237	0.4695904	0.4841237	0.4841237	0.4697479	0.4695904	0.4695904	0.4841237	0.4695904	0.4695904	0.4841237	0.4695904	0.4841237	0.4841237	0.4695904	0.4695904	0.4695904	0.4841237	0.4841237	0.4695904	0.4841237	0.4695904	0.4695904];
Ncut_email_t=0.047031;%%%%% k=4
Ncut_eQmax=max(Ncut_email_Q);Ncut_eQavg=mean(Ncut_email_Q);

% [H0,P0,ci,stats] = ttest2(GDPSO,LPA,0.05,'right');
% [H1,P1,ci,stats] = ttest2(GDPSO,CNM,0.05,'right');
% [H2,P2,ci,stats] = ttest2(GDPSO,Informap,0.05,'right');
% [H3,P3,ci,stats] = ttest2(GDPSO,MOGA_net,0.05,'right');
% P=[P0 P1 P2 P3];

[P1,H1] = ttest2(GDPSO,GA_email_Q,0.05,'right');   
[P2,H2] = ttest2(GDPSO,MOGA_net,0.05,'right');
[P3,H3] = ttest2(GDPSO,LPA,0.05,'right');        
[P4,H4] = ttest2(GDPSO,CNM,0.05,'right');
[P5,H5] = ttest2(GDPSO,Informap,0.05,'right');   
[P6,H6] = ttest2(GDPSO,kmean_email_Q,0.05,'right');
[P7,H7] = ttest2(GDPSO,Ncut_email_Q,0.05,'right');
P=[P1 P2 P3 P4 P5 P6 P7];
H=[H1 H2 H3 H4 H5 H6 H7];



%%%%%% on netscience network
GDPSO=[0.950999 0.951655 0.950361 0.951662 0.951646 0.952444 0.952477 0.952105 0.950376 0.951643 0.952496 0.950914 0.950269 0.951638 0.950207 0.952395 0.950459 0.952446 0.949976 0.948334 0.950389 0.950552 0.949577 0.951894 0.948879 0.951594 0.950714 0.94943 0.953994 0.95069];
LPA=[0.920481 0.918339 0.920564 0.923287 0.925774 0.924092 0.915625 0.922599 0.920135 0.923365 0.918452 0.92397 0.915841 0.918806 0.919969 0.91953 0.920762 0.918248 0.913962 0.920068 0.926556 0.919021 0.920264 0.921516 0.923954 0.913173 0.917884 0.917595 0.923164 0.917503];
CNM=[0.9555 0.9555 0.9555 0.9555 0.9555 0.9555 0.9555 0.9555 0.9555 0.9555 0.9555 0.9555 0.9555 0.9555 0.9555 0.9555 0.9555 0.9555 0.9555 0.9555 0.9555 0.9555 0.9555 0.9555 0.9555 0.9555 0.9555 0.9555 0.9555 0.9555];  
Informap=[0.9252 0.9252 0.9252 0.9252 0.9252 0.9252 0.9252 0.9252 0.9252 0.9252 0.9252 0.9252 0.9252 0.9252 0.9252 0.9252 0.9252 0.9252 0.9252 0.9252 0.9252 0.9252 0.9252 0.9252 0.9252 0.9252 0.9252 0.9252 0.9252 0.9252];
MOGA_net=[0.8788	0.8767	0.8846	0.8807	0.8786	0.8826	0.873	0.8804	0.8916	0.883 0.8788	0.8767	0.8846	0.8807	0.8786	0.8826	0.873	0.8804	0.8916	0.883 0.8788	0.8767	0.8846	0.8807	0.8786	0.8826	0.873	0.8804	0.8916	0.883];

GA_netsci_Q=[0.8961251	0.9014729	0.8971119	0.8999057	0.9008420	0.9009182	0.8984595	0.9020458	0.9040232	0.9036432	0.9032806	0.9002627	0.8955424	0.9041826	0.9060400	0.8929831	0.9023420	0.8971817	0.9085613	0.8934367	0.9043706	0.9012137	0.9058787	0.9014293	0.9002755	0.9024999	0.8958861	0.8976907	0.8970896	0.8955478];
GA_netsci_t=199.660992;
GA_nqmax=max(GA_netsci_Q);GA_nqavg=mean(GA_netsci_Q);

kmean_netsci_Q=[0.6509538	0.6367840	0.6349971	0.6261688	0.6347938	0.6494727	0.6288394	0.6381552	0.6387641	0.6357827	0.6404442	0.6382889	0.6327974	0.6274534	0.6342361	0.6265373	0.6278557	0.6379970	0.6326226	0.6370615	0.6274816	0.6313087	0.6332593	0.6336069	0.6342081	0.6436050	0.6364102	0.6429301	0.6486033	0.6345473];
kmean_netsci_t=56.1879;%%%%% k=315
kmean_netsciQmax=max(kmean_netsci_Q);kmean_netsciQavg=mean(kmean_netsci_Q);

Ncut_netsci_Q=[0.9135253	0.9151952	0.9135253	0.9135253	0.9135253	0.9116945	0.9165393	0.9165393	0.9141653	0.9135253	0.9165393	0.9165393	0.9141653	0.9151952	0.9165393	0.9116945	0.9165539	0.9135253	0.9165539	0.9135253	0.9151952	0.9116945	0.9116945	0.9151952	0.9135253	0.9165393	0.9135253	0.9135253	0.9151952	0.9116945];
Ncut_netsci_t=0.593026;%%%%% k=100
Ncut_nQmax=max(Ncut_netsci_Q);Ncut_nQavg=mean(Ncut_netsci_Q);

% [H0,P0,ci,stats] = ttest2(GDPSO,LPA,0.05,'right');
% [H1,P1,ci,stats] = ttest2(GDPSO,CNM,0.05,'right');
% [H2,P2,ci,stats] = ttest2(GDPSO,Informap,0.05,'right');
% [H3,P3,ci,stats] = ttest2(GDPSO,MOGA_net,0.05,'right');
% P=[P0 P1 P2 P3];

[P1,H1] = ttest2(GDPSO,GA_netsci_Q,0.05,'right');   
[P2,H2] = ttest2(GDPSO,MOGA_net,0.05,'right');
[P3,H3] = ttest2(GDPSO,LPA,0.05,'right');           
[P4,H4] = ttest2(GDPSO,CNM,0.05,'right');
[P5,H5] = ttest2(GDPSO,Informap,0.05,'right');      
[P6,H6] = ttest2(GDPSO,kmean_netsci_Q,0.05,'right');
[P7,H7] = ttest2(GDPSO,Ncut_netsci_Q,0.05,'right');
P=[P1 P2 P3 P4 P5 P6 P7];
H=[H1 H2 H3 H4 H5 H6 H7];


%%%%%% on powergrid network
GDPSO=[0.836168 0.837544 0.836178 0.837965 0.835706 0.836703 0.837007 0.836773 0.837184 0.836273 0.835871 0.837948 0.835947 0.836802 0.836469 0.837173 0.836486 0.835976 0.837261 0.835813 0.83565 0.836804 0.83744 0.838234 0.836272 0.836386 0.837872 0.836926 0.837078 0.837069];
LPA=[0.757791 0.747751 0.750614 0.745667 0.74253 0.748305 0.747092 0.744999 0.751394 0.748711 0.748682 0.7405 0.743006 0.754253 0.74234 0.752524 0.743643 0.748083 0.746711 0.747133 0.743958 0.744155 0.747544 0.750789 0.744047 0.76016 0.748822 0.745304 0.744544 0.746573];
CNM=[0.9229 0.9229 0.9229 0.9229 0.9229 0.9229 0.9229 0.9229 0.9229 0.9229 0.9229 0.9229 0.9229 0.9229 0.9229 0.9229 0.9229 0.9229 0.9229 0.9229 0.9229 0.9229 0.9229 0.9229 0.9229 0.9229 0.9229 0.9229 0.9229 0.9229];  
Informap=[0.814 0.814 0.814 0.814 0.814 0.814 0.814 0.814 0.814 0.814 0.814 0.814 0.814 0.814 0.814 0.814 0.814 0.814 0.814 0.814 0.814 0.814 0.814 0.814 0.814 0.814 0.814 0.814 0.814 0.814];
MOGA_net=[0.7035 0.6972	0.6939 0.695 0.6919	0.6935 0.6954 0.6905 0.6956	0.6924 0.7035	0.6972	0.6939	0.695	0.6919	0.6935	0.6954	0.6905	0.6956	0.6924 0.7035	0.6972	0.6939	0.695	0.6919	0.6935	0.6954	0.6905	0.6956	0.6924];

GA_power_Q=[0.7160580	0.7112109	0.7121375	0.7144167	0.7093931	0.7130511	0.7093301	0.7116113	0.7128913	0.7147435	0.7106594	0.7112324	0.7129649	0.7160435	0.7143316	0.7130317	0.7103056	0.7108359 0.7160580	0.7112109	0.7121375	0.7144167	0.7093931	0.7130511	0.7093301	0.7116113	0.7128913	0.7147435	0.7106594	0.711232];
GA_power_t=3448.528276;
GA_pqmax=max(GA_power_Q);GA_pqavg=mean(GA_power_Q);
kmean=[0 0];

Ncut_power_Q=[0.840876612077665	0.842794151106835	0.841054805620544	0.841636512838636	0.843396781439868	0.839356860136562	0.841871030216994	0.843458013778615	0.842177960413764	0.842340833476746	0.844051198961420	0.842352683297767	0.842735521762246	0.842436053482060	0.841329359528081	0.842749503559433	0.841004679390201	0.842927449198107	0.841020049450939	0.840598141283681	0.842649052775384	0.841800377518440	0.842737430624628	0.841605177747068	0.842972542973078	0.840818602493589	0.841500760495731	0.840976938909611	0.841254715571820	0.841763291049305];
Ncut_power_t=111.686105;%%%%% k=200
Ncut_pQmax=max(Ncut_power_Q);Ncut_pQavg=mean(Ncut_power_Q);

% [H0,P0,ci,stats] = ttest2(GDPSO,LPA,0.05,'right');
% [H1,P1,ci,stats] = ttest2(GDPSO,CNM,0.05,'right');
% [H2,P2,ci,stats] = ttest2(GDPSO,Informap,0.05,'right');
% [H3,P3,ci,stats] = ttest2(GDPSO,MOGA_net,0.05,'right');
% P=[P0 P1 P2 P3];

[P1,H1] = ttest2(GDPSO,GA_power_Q,0.05,'right');   
[P2,H2] = ttest2(GDPSO,MOGA_net,0.05,'right');
[P3,H3] = ttest2(GDPSO,LPA,0.05,'right');           
[P4,H4] = ttest2(GDPSO,CNM,0.05,'right');
[P5,H5] = ttest2(GDPSO,Informap,0.05,'right');      
[P6,H6] = ttest2(GDPSO,kmean,0.05,'right');
[P7,H7] = ttest2(GDPSO,Ncut_power_Q,0.05,'right');
P=[P1 P2 P3 P4 P5 P6 P7];
H=[H1 H2 H3 H4 H5 H6 H7];


%%%%%% on pgp network
GDPSO=[0.800518 0.799807 0.801043 0.800543 0.802186 0.799364 0.801765 0.803225 0.805031 0.801555 0.802093 0.796575 0.800674 0.800574 0.805031 0.800518 0.799807 0.801043 0.800543 0.802186 0.799364 0.801765 0.803225 0.805031 0.801555 0.802093 0.796575 0.800674 0.800574 0.805031];
LPA=[0.784842 0.783214 0.786389 0.793266 0.782448 0.777693 0.784089 0.783537 0.787511 0.784703 0.790013 0.784059 0.773432 0.784485 0.775348 0.779076 0.78092 0.785216 0.785623 0.780286 0.783531 0.794921 0.78819 0.789274 0.791073 0.775781 0.78397 0.787816 0.785917 0.788652];
CNM=[0.8481 0.8481 0.8481 0.8481 0.8481 0.8481 0.8481 0.8481 0.8481 0.8481 0.8481 0.8481 0.8481 0.8481 0.8481 0.8481 0.8481 0.8481 0.8481 0.8481 0.8481 0.8481 0.8481 0.8481 0.8481 0.8481 0.8481 0.8481 0.8481 0.8481];
Informap=[0.7777 0.7777 0.7777 0.7777 0.7777 0.7777 0.7777 0.7777 0.7777 0.7777 0.7777 0.7777 0.7777 0.7777 0.7777 0.7777 0.7777 0.7777 0.7777 0.7777 0.7777 0.7777 0.7777 0.7777 0.7777 0.7777 0.7777 0.7777 0.7777 0.7777];
MOGA_net = [0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0];
GA_pgp_Q=[0.657566 0.657123 0.6653 0.643216 0.633731 0.642425 0.656566 0.657566 0.656766 0.657566 0.657566 0.641518 0.644749 0.632313 0.640401 0.657566 0.657123 0.630728 0.643216 0.633731 0.642425 0.656566 0.657566 0.656766 0.657566 0.657566 0.641518 0.644749 0.632313 0.640401];
GA_pgp_t=37797.9229;GA_pgpqmax=max(GA_pgp_Q);GA_pgpqavg=mean(GA_pgp_Q);
kmean=[0 0];
Ncut_pgp_Q=[0 0];%%%%% k=1000  %%%%% out of memory


% [H0,P0,ci,stats] = ttest2(GDPSO,LPA,0.05,'right');
% [H1,P1,ci,stats] = ttest2(GDPSO,CNM,0.05,'right');
% [H2,P2,ci,stats] = ttest2(GDPSO,Informap,0.05,'right');
% [H3,P3,ci,stats] = ttest2(GDPSO,MOGA_net,0.05,'right');
% P=[P0 P1 P2 P3];

[P1,H1] = ttest2(GDPSO,GA_pgp_Q,0.05,'right');  
[P2,H2] = ttest2(GDPSO,LPA,0.05,'right');           
[P3,H3] = ttest2(GDPSO,Informap,0.05,'right');  
[P4,H4] = ttest2(GDPSO,kmean,0.05,'right');

P=[P1 P2 P3 P4];
H=[H1 H2 H3 H4];


delta_GDPSO_ka=[0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979];
delta_GDPSO_dol=[0.5285195 0.5386	0.5285195	0.5285195	0.5277283	0.5285195	0.5277283	0.5285195	0.5277283	0.5276096	0.5285195	0.5277283	0.5285195	0.5285195	0.5277283	0.5285195	0.5267988	0.5277283	0.5277283	0.5285195	0.5277283	0.5277283	0.5285195	0.5285195	0.5285195	0.5277283	0.5277283	0.5277283	0.5277283	0.5277283];
delta_GDPSO_fot=[0.60457 0.603375 0.603375 0.60457 0.60457 0.603324 0.603375 0.603204 0.603324 0.603375 0.60457 0.60457 0.603204 0.603375 0.603204 0.603375 0.60457 0.60457 0.60457 0.60457 0.60457 0.60457 0.603204 0.603204 0.603375 0.603204 0.60457 0.60457 0.60457 0.603204];
delta_GDPSO_SFI=[0.74245 0.74105 0.746675 0.745988 0.750588 0.744875 0.743875 0.750588 0.744875 0.74405 0.744388 0.740875 0.747725 0.741988 0.74405 0.745988 0.741988 0.740738 0.744738 0.748388 0.744875 0.747725 0.74245 0.744738 0.74405 0.744738 0.747725 0.746675 0.743725 0.745588];
delta_GDPSO_email=[0.458799 0.468744 0.509663 0.469012 0.437326 0.492504 0.485734 0.494817 0.494945 0.448752 0.485532 0.465293 0.522373 0.439808 0.47229 0.498625 0.468613 0.500266 0.470657 0.486186 0.437425 0.487419 0.488787 0.482948 0.478258 0.450632 0.463059 0.457135 0.485094 0.548742];
delta_GDPSO_netsci=[0.950999 0.951655 0.950361 0.951662 0.951646 0.952444 0.952477 0.952105 0.950376 0.951643 0.952496 0.950914 0.950269 0.951638 0.950207 0.952395 0.950459 0.952446 0.949976 0.948334 0.950389 0.950552 0.949577 0.951894 0.948879 0.951594 0.950714 0.94943 0.953994 0.95069];
delta_GDPSO_power=[0.836168 0.837544 0.836178 0.837965 0.835706 0.836703 0.837007 0.836773 0.837184 0.836273 0.835871 0.837948 0.835947 0.836802 0.836469 0.837173 0.836486 0.835976 0.837261 0.835813 0.83565 0.836804 0.83744 0.838234 0.836272 0.836386 0.837872 0.836926 0.837078 0.837069];
delta_GDPSO_pgp=[0.800518 0.799807 0.801043 0.800543 0.802186 0.799364 0.801765 0.803225 0.805031 0.801555 0.802093 0.796575 0.800674 0.800574 0.805031 0.800518 0.799807 0.801043 0.800543 0.802186 0.799364 0.801765 0.803225 0.805031 0.801555 0.802093 0.796575 0.800674 0.800574 0.805031];

maxD_GDPSO_ka=[0.415105 0.415598 0.402038 0.402038 0.402038 0.415598 0.415105 0.402038 0.402038 0.402038 0.415598 0.402038 0.402038 0.403271 0.402038 0.402038 0.415598 0.415105 0.415598 0.402038 0.403271 0.415598 0.415105 0.403271 0.415105 0.415598 0.402038 0.402038 0.415598 0.403271]; 
maxD_GDPSO_dol=[0.526463 0.526463 0.526463 0.526463 0.526463 0.526463 0.526463 0.526799 0.526463 0.526463 0.526463 0.526463 0.526463 0.526799 0.526463 0.526463 0.526463 0.526463 0.526463 0.526463 0.526463 0.526463 0.526463 0.526463 0.526799 0.526463 0.526463 0.526463 0.526463 0.526463];
maxD_GDPSO_fot=[0.604346 0.603204 0.603204 0.604346 0.60457 0.603324 0.603375 0.603204 0.603324 0.603204 0.60457 0.60457 0.603204 0.603204 0.603204 0.603375 0.60457 0.604346 0.604346 0.60457 0.60457 0.604429 0.603204 0.602981 0.603375 0.603204 0.60457 0.60457 0.60457 0.602981];
maxD_GDPSO_SFI=[0.73465 0.744075 0.74295 0.74645 0.747138 0.7432 0.738075 0.748388 0.747138 0.738663 0.739575 0.743488 0.743638 0.74405 0.7452 0.7452 0.744875 0.745575 0.740763 0.743738 0.7428 0.74135 0.74645 0.74615 0.739575 0.745988 0.740825 0.74645 0.741138 0.740838];
maxD_GDPSO_email=[0.366369 0.330501 0.329108 0.470625 0.404805 0.3789 0.41546 0.271609 0.268319 0.290021 0.34191 0.234757 0.345769 0.44761 0.151584 0.152822 0.301409 0.111628 0.410869 0.264848 0.274366 0.46046 0.368342 0.258803 0.288386 0.332253 0.113143 0.494084 0.285019 0.16077];
maxD_GDPSO_netsci=[0.945388 0.948516 0.945655 0.946636 0.947609 0.945533 0.946205 0.951215 0.950208 0.949783 0.946015 0.95047 0.947648 0.949334 0.947609 0.947609 0.945445 0.945533 0.952187 0.947609 0.95118 0.948816 0.94701 0.945396 0.948121 0.948411 0.947609 0.946323 0.945533 0.949437];
maxD_GDPSO_power=[0.836168 0.837544 0.836178 0.837965 0.835706 0.836703 0.837007 0.836773 0.837184 0.836273 0.835871 0.837948 0.835947 0.836802 0.836469 0.837173 0.836486 0.835976 0.837261 0.835813 0.83565 0.836804 0.83744 0.838234 0.836272 0.836386 0.837872 0.836926 0.837078 0.837069];
maxD_GDPSO_pgp=[0.796487 0.7958 0.796945 0.796155 0.798045 0.796646 0.799032 0.798057 0.798499 0.797488 0.796864 0.794503 0.796023 0.796996 0.798938 0.796785 0.798143 0.796467 0.796402 0.802086 0.798628 0.797787 0.795429 0.800476 0.796103 0.800803 0.797706 0.798279 0.799964 0.80064];

dominate_GDPSO_ka=[0.415105 0.415598 0.415598 0.415598 0.402038 0.415598 0.403271 0.402038 0.415598 0.415598 0.415598 0.402038 0.402038 0.415598 0.402038 0.402038 0.415598 0.415105 0.415598 0.402038 0.402038 0.415598 0.402038 0.402038 0.415105 0.403271 0.403271 0.402038 0.402038 0.415598];
dominate_GDPSO_dol=[0.526463 0.526463 0.526463 0.526463 0.526463 0.526463 0.526463 0.526463 0.526463 0.526463 0.526463 0.526463 0.526463 0.526463 0.526799 0.526463 0.526463 0.526463 0.526463 0.526463 0.526463 0.526463 0.526463 0.526799 0.526463 0.526799 0.526463 0.526463 0.526463 0.526799];
dominate_GDPSO_fot=[0.60457 0.603375 0.603375 0.60457 0.60457 0.603324 0.603375 0.603204 0.603324 0.603375 0.60457 0.60457 0.603204 0.603375 0.603204 0.603375 0.60457 0.60457 0.60457 0.60457 0.60457 0.60457 0.603204 0.603204 0.603375 0.603204 0.60457 0.60457 0.60457 0.603204];
dominate_GDPSO_SFI=[0.73925 0.74365 0.74645 0.748388 0.744738 0.7474 0.748388 0.74405 0.746675 0.74645 0.745988 0.747725 0.748388 0.748388 0.74645 0.74645 0.748388 0.74405 0.738425 0.74405 0.744875 0.744875 0.749663 0.74245 0.748388 0.745988 0.74365 0.744388 0.744875 0.749663];
dominate_GDPSO_email=[0.366952 0.330501 0.296315 0.346502 0.311796 0.266562 0.300818 0.339973 0.319648 0.0167883 0.275947 0.349951 0.294531 0.26354 0.258847 0.110611 0.31024 0.00359452 0.109637 0.352673 0.281086 0.243009 0.319851 0.147747 0.280841 0.00465697 0.292519 0.0145039 0.255528 0.294896];
dominate_GDPSO_netsci=[0.927287 0.928948 0.929769 0.928581 0.927399 0.931386 0.928562 0.929556 0.92888 0.9293 0.9306 0.930098 0.933418 0.929633 0.931475 0.929821 0.927897 0.93108 0.929086 0.92946 0.929472 0.930445 0.930245 0.93092 0.929367 0.929404 0.927996 0.929207 0.928969 0.928761];
dominate_GDPSO_power=[0.809953 0.812104 0.811089 0.811513 0.810223 0.811379 0.809914 0.810783 0.812559 0.811604 0.812369 0.811672 0.811619 0.809922 0.813398 0.810756 0.8142 0.814474 0.811349 0.812442 0.810851 0.811192 0.810623 0.810235 0.811763 0.81354 0.813138 0.812056 0.81095 0.809757];
dominate_GDPSO_pgp=[0.808182 0.809864 0.814521 0.807659 0.807416 0.808092 0.807072 0.810285 0.812439 0.810432 0.811641 0.80819 0.810865 0.811022 0.807231 0.808894 0.806914 0.809462 0.81012 0.807809 0.813832 0.810781 0.806458 0.810267 0.809908 0.80731 0.807344 0.810126 0.807418 0.807373];

[P1,H1] = ttest2(delta_GDPSO_ka,maxD_GDPSO_ka,0.05,'right');  
[P2,H2] = ttest2(delta_GDPSO_dol,maxD_GDPSO_dol,0.05,'right');  
[P3,H3] = ttest2(delta_GDPSO_fot,maxD_GDPSO_fot,0.05,'right');  
[P4,H4] = ttest2(delta_GDPSO_SFI,maxD_GDPSO_SFI,0.05,'right');  
[P5,H5] = ttest2(delta_GDPSO_email,maxD_GDPSO_email,0.05,'right');  
[P6,H6] = ttest2(delta_GDPSO_netsci,maxD_GDPSO_netsci,0.05,'right');  
[P7,H7] = ttest2(delta_GDPSO_power,maxD_GDPSO_power,0.05,'right');  
[P8,H8] = ttest2(delta_GDPSO_pgp,maxD_GDPSO_pgp,0.05,'right');  


[PP1,HH1] = ttest2(delta_GDPSO_ka,dominate_GDPSO_ka,0.05,'right');  
[PP2,HH2] = ttest2(delta_GDPSO_dol,dominate_GDPSO_dol,0.05,'right');  
[PP3,HH3] = ttest2(delta_GDPSO_fot,dominate_GDPSO_fot,0.05,'right');  
[PP4,HH4] = ttest2(delta_GDPSO_SFI,dominate_GDPSO_SFI,0.05,'right');  
[PP5,HH5] = ttest2(delta_GDPSO_email,dominate_GDPSO_email,0.05,'right');  
[PP6,HH6] = ttest2(delta_GDPSO_netsci,dominate_GDPSO_netsci,0.05,'right');  
[PP7,HH7] = ttest2(delta_GDPSO_power,dominate_GDPSO_power,0.05,'right');  
[PP8,HH8] = ttest2(delta_GDPSO_pgp,dominate_GDPSO_pgp,0.05,'right');  


