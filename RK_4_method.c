#include <stdio.h>

#define dy(t,theta) -g/l*theta_0
#define dtheta(t,theta) y_0

int main()
{
  float theta_0,theta_n,y_0,y_n, t,g,l,h;
  float dy_dt_1,dy_dt_2,dy_dt_3,dy_dt_4;
  float dtheta_dt_1,dtheta_dt_2,dtheta_dt_3,dtheta_dt_4;
  float k11,k12,k21,k22,k31,k32,k41,k42;
  int i,n;
  h=0.01;
  t=0;
  n=6/h;
  theta_0=0.175;
  y_0=0;
  g=9.81;
  l=0.6;

  for (i=0;i<n+1;i=i+1)
    {
      dy_dt_1=dy(t,theta_0);
      k11=dy_dt_1*h;

      dy_dt_2=dy(t+h/2,theta+k11*h/2);
      k21=dy_dt_2;

      dy_dt_3=dy(t+h/2,theta+k21*h/2);
      k31=dy_dt_3;

      dy_dt_4=dy(t+h,theta+k31*h);
      k41=dy_dt_4;

      y_n=y_0+h*(k11+2*k21+2*k31+k41)/6;
      k12=y_n*h;
      k22=y_n*h;
      k32=y_n*h;
      k42=y_n*h;
      theta_n=theta_0+h*(k12+2*k22+2*k32+k42)/6;
      printf("%f, %f \n", t, theta_n);
      y_0=y_n;
      theta_0=theta_n;
      t=t+h;
    }
  return 0; 
}
