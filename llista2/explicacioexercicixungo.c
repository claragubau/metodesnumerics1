/*BORRAR FILE QUAN ACABI LA PRACTICA*/
la funcio que volem integrar es f(x)=k(x,t)*y(t) i es la que posem a la formula dels trapezis per tant acaba quedant
g(x) = y(x)-landa(k(xi, t0)*y(t0)/2+........+)

IDEA FELIZ: tj = xj, per tant els valors de y(xi) = y(t0)

si fossin tres punts, hauriem de fer
1. g(x) = y(x) - landa(k(x,t0)*y(t0)/2 + k(x,t1)*y(t1)+k(x,t2)*y(t2)/2)
2. idem pro amb x = x0, x = x1 i x = x2
3. x € [0,1], t€[0,1], xi = i*h, tj = j*h per tant acaba siguent lo mateix

acabem tenint tres equacions on les incognites son y(t0), y(t1), y(t2) i si fem l'equacio per x0, sabem y(t0) = y(x0), llavors per x1, tenim y(t1) = y(x1)...
