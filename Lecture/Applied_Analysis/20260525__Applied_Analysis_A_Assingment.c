/*20260525_Applied_Analysis_Assignment.c/
/*Euler法で解く*/

#include <stdio.h>
#include<math.h>

#define N 10
int main(void)
{
    double u, uu, v, t, dt;
    int n;
    FILE *fp;
    
    dt = 0.1;

    fp= fopen("20260525_Applied_Analysis_Assignment_bvp.csv", "w");
    fprintf(fp, "%f, %f, %f\n", t, u, v);

    /*initial condition*/
    n = 0;
    t = n * dt;
    u = 1/2; /*u^0*/
    v= (t*exp(t)+ t+ 1)/(exp(t)+ 1); /*Exact sol*/
    fprintf(fp, "%f, %f, %f\n", t, u, v);

    for (n= 1; n<= N; n++){
        t = n * dt;
        uu = u;
        u = ((t*t+ t+ 1)- (2*t+ 1)* u+ u*u)*dt+ uu; /*u^n-> uu, u^{n+1}-> u*/
        v = (t*exp(t)+ t+ 1)/(exp(t)+ 1); 
    fprintf(fp, "%f, %f, %f\n", t, u, v);
    }

    fclose(fp);
    return 0;
}
/*Riccatiの方程式の計算せよ：
\begin{cases}
    du/dt= (t^2+ t+ 1)- (2t+ 1)u+ u^2 (0< t\le 1) <done>
    u(0)= 1/2 <done>
\end{cases}
Exact sol. (tu^t+ t+ 1)/(e^t+ 1)
dt= 0.1　<done>
N= 10 <done>
*/