#include <stdio.h>
#include<math.h>
#include<mpi.h>
#include<stdint.h>
#include<stdlib.h>


#define der(x,h) (sin(x+h)-sin(x-h))/(x*h)

int main(int argc, char** argv){
  float range,pi, tag, dest, F[25],h,my_results[25],results[100];
  float send_variable;
  double x;
  int i,j,k,N,world_rank,world_size,n;
  pi=3.1416;
  N=100;
  MPI_Init(&argc,&argv);
  MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
  MPI_Comm_size(MPI_COMM_WORLD, &world_size);
  x=world_rank*pi/4;
  h=pi/(N-1);
  n=N/world_size;
  for (j=0;j<25;j++){
      F[j]=sin(world_rank*pi/4+j*pi/99);
    }
  if (world_rank==0){
    my_results[0]=(F[1]-F[0])/h;
  }
  else if(world_rank!=0){
    F[0]=send_variable;
  }

  for (j=1;j<25;j++){
    my_results[j]=(F[j+1]-F[j-1])/(2*h);
  }
  if (world_rank>0){
    send_variable=(world_rank-1)*pi/4;
  }
if(0<world_rank<3){
  MPI_Send(&send_variable,1,MPI_FLOAT,world_rank-1,0,MPI_COMM_WORLD); 
}
 MPI_Gather(my_results,25,MPI_FLOAT,results,25,MPI_FLOAT,0,MPI_COMM_WORLD);
   MPI_Finalize();
 for (i=0;i<25;i++){
   printf("%f \n",my_results[i]);
}
}
