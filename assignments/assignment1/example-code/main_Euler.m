% main program for approximating the cooling 
% of a well-stirred cup of coffee using 
% Euler Methods. 
% Example 1: Illustration of the Forward Euler
% method with the time step size dt = 60, 30, 15, 1. 
% Here, we choose the rest parameters as 
% t_final = 60, h=10, 
% u_sur = 25, u0=100, u_obser = 60. 

% setting up the parameters 
dt = 30; 			% time step size
t_final = 60; 		% final time
t = [0:dt:t_final];	% array of discretized time points
u0 = 100; 			% temperature of the coffee at t = 0
u_sur = 25; 		% surrounding (or room) temperature
h = 10;             % observation time for measuring 
					% insulation of the cup c
u_obser = 80;		% observed temperature after h minutes

[u, c] = TempOfCoffee(t, dt, u0, u_sur, u_obser, h);

% Compute the exaxt solution 
% compute the insulation of the cup
time = [0:0.5:t_final]; 
c = (u_obser - u0)/(h*(u_sur - u0));
u_exact = u_sur + (u0 - u_sur) * exp(-c*time);

% displaying the result
disp('The time stepsize dt:'),
disp(dt) 

% finding the approximation error
u_exact_60 = u_exact(length(time)); 
u_60 = u(length(t));
relativeError = abs(u_60-u_exact_60);
[u_exact_60, u_60, relativeError]

% compare the exact solution and Euler approximation
figure(1); 
plot(time, u_exact, 'r', time, u_sur * ones(size(time)), 'b--', 'Linewidth',2);
hold on;
plot(t, u, 'k:', 'Linewidth', 2); 

axis([0, t_final, -20, 100]);
xlabel('Time (minutes)', 'Fontsize', 12); 
ylabel('Temperature (C)','Fontsize', 12); 
title('Forward Euler Approxmiation of Coffee Temperature','Fontsize', 12); 
legend('Coffee','Room', 'Euler', 'Fontsize', 12);

hold off; 