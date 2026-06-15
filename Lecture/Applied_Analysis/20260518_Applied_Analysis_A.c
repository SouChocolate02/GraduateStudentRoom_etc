/*20260518_Applied_Analysis.c*/
#include <stdio.h>
#include <math.h>
#define J 20

int main(void)
{
    double a[J], b[J], c[J], d[J], g[J], s[J];
    double u[J+1], v[J+1], h;
    int j;
    FILE *fp;
    
    h= 1.0/J;
    u[0]= 0.0; u[J]= 0.0; /* Boundary condition*/

    for (j= 1; j< J; j++){
        a[j]= c[j]= 1.0;
        b[j]= h*h- 2.0;
        d[j]= -j* h*h*h;
    }

    c[0]= 0.0; c[J- 1]= 0.0;
    g[0]= 1.0; s[0]= 0.0;
    
    for (j= 1; j< J; j++){
        g[j]= b[j]- (a[j]*c[j- 1])/g[j-1];
        s[j]= d[j]- (a[j]*s[j- 1])/g[j-1];
    }

    for (j= J-1; j> 0; j--)
        u[j]= (s[j]- c[j]*u[j+1])/g[j];

    for (j= 0; j<= J; j++)
    v[j]= sin(j*h)/sin(1.0)- j*h;

    fp= fopen("20260518_Applied_Analysis_bvp.csv", "w");
    fprintf(fp, "x, u, v\n");
    for (j= 0; j<= J; j++)
        fprintf(fp, "%f, %f, %f\n", j*h, u[j], v[j]);
    fclose(fp);

    return 0;
}