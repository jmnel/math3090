#!/usr/bin/env gnuplot

set terminal epslatex color
set output '/home/jacques/repos/math3090/assignments/assignment1/figures/figure2-3.tex'

set xlabel "Time $t$ (minutes)"
set ylabel "Temperature $U(t)$"

plot '../data/table2-3.txt' index 0 with lines title "Anal. model", \
'' index 1 with lines title "Disc. h=40.0", \
'' index 2 with lines title "Disc. h=20.0", \
'' index 3 with lines title "Disc. h=10.0", \
'' index 4 with lines title "Disc. h=5.0", \
50 with lines title "$u_d = 50°C$" 

set output
