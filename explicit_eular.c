#include<stdio.h>

#define dy(t,theta) -g/l*theta_0
#define dtheta(t,theta) y_0

int main()
{
  float y_0,theta_0,h,y_n,theta_n,dy_dt,dtheta_dt,t,g,l;
  int i, n;
  h=0.15;
  t=0;
  n=40;
  theta_0=0.174;
  y_0=0;
  l=0.6;
  g=9.81;
  for (i=0;i<n+1;i=i+1)
    {
      dy_dt=dy(t,theata);
      dtheta_dt=dtheta(t,y_n);
      y_n=y_0+h*dy_dt;
      theta_n=theta_0+h*y_n;
      printf("%f,  %f \n", t, theta_0);
	y_0=y_n;
      theta_0=theta_n;
      t=t+h;
    }
  return 0;
}
