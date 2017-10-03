% main program for approximating the cooling 
% of a well-stirred cup of coffee using 
% Improve Euler Methods. 
% Example: Illustration of the Improved and Backward Euler
% methods with the time step size dt = 60, 30, 15, 1. 
% Here, we choose the rest parameters as 
% t_final = 60, h=10, 
% u_sur = 25, u0=100, u_obser = 80. 

% setting up the parameters 
dt = 5; 			% time step size
t_final = 60; 		% final time
t = [0:dt:t_final];	% array of discretized time points
u0 = 100; 			% temperature of the coffee at t = 0
u_sur = 25; 		% surrounding (or room) temperature
h = 10;             % observation time for measuring 
					% insulation of the cup c
u_obser = 80;		% observed temperature after h minutes

[u, c] = TempOfCoffee(t, dt, u0, u_sur, u_obser, h);
[u_im, c] = TempOfCoffee_ImpEuler(t, dt, u0, u_sur, u_obser, h);
[u_bk, c] = TempOfCoffee_BkEuler(t, dt, u0, u_sur, u_obser, h);

% Compute the exaxt solution 
% compute the insulation of the cup
time = [0:0.5:t_final]; 
c = (u_obser - u0)/(h*(u_sur - u0));
u_exact = u_sur + (u0 - u_sur) * exp(-c*time);

% displaying the result
disp('The time stepsize dt:'),
disp(dt) 

% finding the approximation error
u_exact60 = u_exact(length(time)); 
u_60 = u_im(length(t));
u_bk60 = u_bk(length(t)); 
Error_fd = abs(u_60-u_exact60);
Error_bk = abs(u_bk60-u_exact60);
err = [u_exact60, u_60, u_bk60, Error_fd, Error_bk]

% compare the exact solution and Euler approximation
figure(1); 
plot(time, u_exact, 'r', 'Linewidth',2);
hold on;
plot(t, u, 'g-.', t, u_im, 'k:', t, u_bk, 'b--','Linewidth', 2); 

%axis([0, t_final, -20, 100]);
xlabel('Time (minutes)', 'Fontsize', 12); 
ylabel('Temperature (C)','Fontsize', 12); 
title('Euler Approxmiations of Coffee Temperature','Fontsize', 12); 
legend('Exact Solution','Forward Euler','Improved Euler', 'Backward Euler');

hold off; 