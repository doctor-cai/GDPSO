%不同算法在GN Extended benchmark数据上的NMI
figure(1)
x=0:0.05:0.5;

GDPSO   = [1	1	1	1	1	1	1	1	1	0.5791	0.1421];
y1=plot(x',GDPSO,'-r*');

hold on;
nmi_GA_Q=[1 1 1 1 0.9581 0.8822 0.6912 0.5665 0.4765 0.32135 0.168058];
y2=plot(x',nmi_GA_Q,'-kv');

nmi_MOGA   = [1	1 0.9975 0.8946	0.7503	0.6194	0.4526	0.3438	0.2311	0.1455	0.1067];
y3=plot(x',nmi_MOGA,'-cd');

nmi_LPA=[1 1 1 1 0.9669 0.9511 0.8149 0.6004 0.1503 0 0];
y4=plot(x',nmi_LPA,'-kv');

nmi_CNM   = [1	1	1	1 1 0.9325 1 0.9245 0.7797 0.3535 0.0257];
y5=plot(x',nmi_CNM,'-bs');

nmi_Informap   = [1	1	1	1	1	1	1	1	0 0 0];
y6=plot(x',nmi_Informap,'-mp');

nmi_kmeans   = [0.9353 0.94095 0.9601 0.9778 0.9539 0.96732 0.96057 0.95383 0.977919 0.87054 0.2285];
y7=plot(x',nmi_kmeans,'-mp');

nmi_Ncut   = [1 1 1 1 1 1 1 1 1 0.9748 0.3073];
y8=plot(x',nmi_Ncut,'-mp');



xlabel('The Mixing Parameter \gamma in Benchmark ');
ylabel('NMI');
legend('GDPSO','GA','MOGA','LPA','CNM','Informap','k-means','Ncut');
set(gca,'linewidth',2.0);
set(y1,'linewidth',2.0);
set(y2,'linewidth',2.0);
set(y3,'linewidth',2.0);
set(y4,'linewidth',2.0);
set(y5,'linewidth',2.0);
set(y6,'linewidth',2.0);
set(y7,'linewidth',2.0);
set(y8,'linewidth',2.0);
hh=findobj('tag','legend') ;
set(hh,'fontsize',12) ;
set(gca,'fontsize',12);
set(get(gca,'xlabel'),'fontsize',12);
set(get(gca,'ylabel'),'fontsize',12);



