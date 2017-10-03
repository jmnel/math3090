#!/usr/bin/env gnuplot

set terminal epslatex color
set output '/home/jacques/repos/math3090/assignments/assignment1/figures/figure2-2.tex'

set xlabel "Time $t$ (minutes)"
set ylabel "Temperature $U(t)$"

plot '../data/table2-2.txt' index 0 with lines title "$t^* = 0$ mins", \
'' index 1 with lines title "$t^* = 10$ mins", \
'' index 2 with lines title "$t^* = 30$ mins", \
'' index 4 with lines title "$t^* = 40$ mins", \
'' index 5 with lines title "$t^* = 50$ mins", \
50 with lines title "$u_d = 50°C$" 


set output
