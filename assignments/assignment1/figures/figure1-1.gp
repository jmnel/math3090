#!/usr/bin/env gnuplot

set terminal epslatex color
set output '/home/jacques/repos/math3090/assignments/assignment1/figures/figure1-1.tex'

set auto
set xrange [0:60*6]
set yrange [20:105]
set xlabel "Time $t$ (minutes)"
set ylabel "Temperature (Degrees C)"


plot '../data/table1-1.txt' index 0 with lines title "Room temp. $u_{sur}(t)$", \
'' index 1 with lines title "Coffee temp. $u(t)$" 

set output
