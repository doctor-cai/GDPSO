%%%%%%%%% ������� gmax �Ͳ��� popsize ���㷨ʵ�����ܵ�Ӱ��

 

%%%%%%%%%�ּ����ҵ��㷨�������㷨���޷��������ϵ���ʵ���ݼ��ϵ�p-value
clc;
clear all;
%%%%%% gmax=100ʱ
pop20=[];
pop60=[];
pop100=[0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979 0.41979];
pop140=[];
pop180=[];
avg20=mean(pop20); std20=std(pop20);
avg60=mean(pop60); std60=std(pop60);
avg100=mean(pop100); std100=std(pop100);
avg140=mean(pop140); std140=std(pop140);
avg180=mean(pop180); std180=std(pop180);

%%%%%% pop=100ʱ
gmax50=[];
gmax100=[];
gmax150=[];
gmax200=[];
gmax250=[];
avggmax50=mean(gmax50); stdgmax50=std(gmax50);
avggmax100=mean(gmax100); stdgmax100=std(gmax100);
avggmax150=mean(gmax150); stdgmax150=std(gmax150);
avggmax200=mean(gmax200); stdgmax200=std(gmax200);
avggmax250=mean(gmax250); stdgmax250=std(gmax250);

a=[0.800621 0.804202 0.797719 0.800497 0.800540 0.801104 0.804684 0.802899 0.79778 0.800615 0.798211 0.802769 0.800999 0.799121 0.7987 0.799179 0.798554 0.799121 0.801995 0.799579 0.801354 0.799908 0.798447 0.798763 0.801995 0.799579 0.801354 0.799908 0.798447 0.798763];
b=[0.800466 0.802405 0.804689 0.799854 0.799598 0.800745 0.800711 0.799297 0.804542 0.800123 0.802204 0.800624 0.800524 0.799393 0.801131 0.801724 ];