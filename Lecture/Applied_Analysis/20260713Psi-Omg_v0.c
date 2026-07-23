#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define I 100
#define J 100
#define N 10000
#define STEP 100
#define sub(i,j) ((i)+(I+1)*(j))

void Euler(void);
void Poisson(void);
void init(void);
void bound(void);
void output(int);

double *omg,*pmg,*psi;
double dx, dy, dt, Re;

int main(void)
{
    int n;

    Re = 500 ;
    dx = 1.0/I;
    dy = 1.0/J;
    dt = 0.1*dx;

    omg = (double *)malloc(sizeof(double)*(I+1)*(J+1));
    pmg = (double *)malloc(sizeof(double)*(I+1)*(J+1));
    psi = (double *)malloc(sizeof(double)*(I+1)*(J+1));

    init();
    bound();

    n = 0;
    output(n);

    for (n = 1; n <= N; n++) {

      bound();
      Euler();
      Poisson();

      if (n % STEP == 0) {
        output(n);
        printf("n = %d\n", n);
      }

    }

    free(omg);
    free(pmg);
    free(psi);

    return 0;
}

void init(void)
{
    int i,j;

    for (j = 0; j <= J; j++)
      for (i = 0; i <= I; i++) {
        omg[sub(i,j)] = 0.0;
        psi[sub(i,j)] = 0.0;
      }
}

void bound(void)
{
    int i,j;

    for (j = 0; j <= J; j++) {
      omg[sub(0,j)] = -2.0*psi[sub(1,j)]/(dx*dx) ;
      omg[sub(I,j)] = -2.0*psi[sub(i- 1,j)]/(dx*dx) ;
      psi[sub(0,j)] = 0.0;
      psi[sub(I,j)] = 0.0;
    }
    
    for (i = 0; i <= I; i++) {
      omg[sub(i,0)] = -2.0*psi[(i,1)]/(dy*dy) ;
      omg[sub(i,J)] = 2.0*psi[(1,J-1)]/(dy*dy) ;
      psi[sub(i,0)] = 0.0;
      psi[sub(i,J)] = 0.0;
    }
}

void Euler(void)
{
    int i,j;
    double u,v,upwindx,upwindy,lap;

    for (j = 0; j <= J; j++)
      for (i = 0; i <= I; i++)
        pmg[sub(i,j)] = omg[sub(i,j)];

    for (j = 1; j < J; j++)
      for (i = 1; i < I; i++) {

        u = (psi[sub(i,j+1)]-psi[sub(i,j-1)])/(2.0*dy);
        v =-(psi[sub(i+1,j)]-psi[sub(i-1,j)])/(2.0*dx);

        upwindx = u*(pmg[sub(i+1, j)]- pmg[sub(i-1,j)])/(2.0*dx)- fabs(u)*(pmg[sub(i+1, j)]- 2.0*pmg[sub(i,j)]+pmg[sub(i-1,j)])/(2.0*dx);
        

        upwindy = v*(pmg[sub(i+1, j)]- pmg[sub(i-1,j)])/(2.0*dx)- fabs(u)*(pmg[sub(i+1, j)]- 2.0*pmg[sub(i,j)]+pmg[sub(i-1,j)])/(2.0*dx);

        lap = (pmg[sub(i+1,j)]- 2.0*pmg[sub(i,j)]+pmg[sub(i-1,j)])/(dx*dy)
          +(pmg[sub(i,j+1)]- 2.0*pmg[sub(i,j)]+pmg[sub(i,j-1)])/(dx*dy);
            
        omg[sub(i,j)] = pmg[sub(i,j)]+dt*( -upwindx-upwindy+lap/Re );

      }
}

void Poisson(void)
{
    int i,j,l,L=100;

    for (l = 1; l <= L; l++) {

    for (j = 1; j < J; j++)
      for (i = 1; i < I; i++) {

      psi[sub(i,j)] = (-omg[sub(i, j)]
      -(psi[sub(i+1,j)]+psi[sub(i-1,j)])/(dx*dx)
      -(psi[sub(i,j+1)]+psi[sub(i,j-1)])/(dy*dy))
      /(-2.0/(dx*dx)-2.0/(dy*dy)) ;
                         
      }

    }
}

void output(int n)
{
    int i,j;
    char fname[50];
    FILE *fp;

    sprintf(fname, "data0713_%03d.csv",n/STEP);
    fp=fopen(fname,"w");
    fprintf(fp, "x,y,z,psi,omg\n");
    for (j = 0; j <= J; j++)
      for (i = 0; i <= I; i++)
        fprintf(fp, "%f,%f,%f,%f,%f\n",i*dx, j*dy, 0.0, psi[sub(i,j)], omg[sub(i,j)]);
    fclose(fp);
}