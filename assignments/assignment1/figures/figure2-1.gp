#!/usr/bin/env gnuplot

set terminal epslatex color
set output '/home/jacques/repos/math3090/assignments/assignment1/figures/figure2-1.tex'

set auto
set yrange [40:110]
set xlabel "Time $t$ (minutes)"
set ylabel "Temperature $U(t)$"


plot '../data/table2-1.txt' index 0 with lines title "$U(t)$", \
50 with lines title "$u_d = 50°C$" 


set output
