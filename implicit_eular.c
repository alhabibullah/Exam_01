#include<stdio.h>


#define dy(t,theta) -g/l*theata_0*h
#define dtheta(t,theta) h*y0

int main()
{
  float t_n, theta_0,h,y_n,theta_n,dy_dt,dtheta_dt,t,g,l,y_0;
  int i,n;
  h=0.15;
  t=0;
  t_n=6;
  n=t_n/h;
  theta_0=0.175;
  y_0=0;
  g=9.81;
  l=0.6;
  for (i=0;i<n+1;i=i+1)
    {
      printf("%f, %f \n",t,theta_0);
      y_n=(y_0-h*(g/l)*theta_0)/(1+h*h*(g/l));
      theta_n=theta_0+h*y_n;
      y_0=y_n;
      theta_0=theta_n;
      t=t+h;
    }
  return 0;
}
