
set size square
set xlabel "x"
set ylabel "y"
#plot 'out5.res' w d tit 'polinomi' , 'exempl5.dat' notit, 'exempl5.spl' w d tit 'spline'
#plot 'out5.res' w p pt 7 ps 0.1 tit 'polinomi' , 'exempl5.dat' notit, 'exempl5.spl' w p pt 7 ps 0.1 tit 'spline'
plot 'prob20.pts' pt 6 tit "punts" , x*log(x) w l lt rgb "green" tit 'f(x)' , 'prob20.pol' w l lt rgb "red" tit 'prac 4'

set key center bot
set term jpeg size 800,800
set outp 'prob20.jpg'
replot
