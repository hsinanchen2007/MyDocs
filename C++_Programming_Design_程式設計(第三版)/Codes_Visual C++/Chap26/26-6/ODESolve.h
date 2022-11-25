// 郎ODESolve.cpp
// ㄧ计RK5Step() ﹚竡(き顶 Runge-Kutta 计縩だ)
// --------------------------------------
// Copyright (c) Yau-Zen Chang (2002.01-) 
// All Rights Reserved.
// セ祘Α舦妮 眎模く
// ㄏノゲ惠羘.
// --------------------------------------

inline void RK5Step (Vector& Xk, Vector& Xkp1,
         double& e,  Vector (*F)(Vector&))
{
   Vector Xtemp(SysOrder), E(SysOrder);
   Vector Q1(SysOrder), Q2(SysOrder),Q3(SysOrder),
          Q4(SysOrder), Q5(SysOrder),Q6(SysOrder);
   Q1=F(Xk);
   Xtemp = Xk + h*Q1/4.;
   Q2=F(Xtemp);
   Xtemp = Xk + h*(3.0*Q1 + 9.0*Q2)/32.0;
   Q3=F(Xtemp);
   Xtemp = Xk + h*(1932.*Q1 - 7200.*Q2 + 7296.*Q3)/2197.;
   Q4=F(Xtemp);
   Xtemp = Xk + h*(439.*Q1/216. - 8.*Q2 + 3680.*Q3/513.
          - 845.*Q4/4104.);
   Q5=F(Xtemp);
   Xtemp = Xk + h*(-8.*Q1/27. + 2.*Q2 - 3544.*Q3/2565.
             + 1859.*Q4/4104. - 11.*Q5/40.);
   Q6=F(Xtemp);
   Xkp1= Xk + h*(16.*Q1/135. + 6656.*Q3/12825.
              + 28561.*Q4/56430. - 9.*Q5/50. + 2.*Q6/55.);
   E = h*(Q1/360. - 128.*Q3/4275.
             - 2197.*Q4/75240. + Q5/50. + 2.*Q6/55.);
   e = InfNorm(E);   // e = Max(E);
   return;
}

// ㄧ计 RungeKutta5() ﹚竡
Matrix RungeKutta5(Vector& X0, double& Error,
                   Vector (*Fnc)(Vector&))
{
   Matrix Ans(SysOrder,NoPoint);
   Vector X(SysOrder), XNext(SysOrder);
   double e;
   int k;
   X = X0;
   Error = 0.0;
   Ans.SetCol(1, X);
   for (k = 2; k <= NoPoint; k++)
     {
       RK5Step (X, XNext, e, Fnc);
       Ans.SetCol(k, XNext);
       X = XNext;
       Error = MAX (e,Error);
       if (Error > ErrorBound)
        {
          cout  << "Diverging! Error = "
                << Error;
          exit(1);
        }
     }
   return Ans;
}
