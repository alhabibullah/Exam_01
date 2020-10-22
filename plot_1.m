clc;clear all;
explicit_eular=importdata('explicit_eular.dat');
plot(explicit_eular(:,1),explicit_eular(:,2),'--c+','Linewidth',1.5);
hold on
implicit_eular=importdata('implicit_eular.dat');
plot(implicit_eular(:,1),implicit_eular(:,2),'-rs','Linewidth',1.5);
hold on
RK_2_method=importdata('RK_2_method.dat');
plot(RK_2_method(:,1),RK_2_method(:,2),'-bo','Linewidth',1.5);
hold on
RK_4_method=importdata('RK_4_method.dat');
plot(RK_4_method(:,1),RK_4_method(:,2),'-g','Linewidth',1.5)
legend('Explicit Eular','Implicit Eular','RK 2 method','RK 4 method')




