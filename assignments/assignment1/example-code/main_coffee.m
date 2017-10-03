% main program for simulating the cooling 
% of a well-stirred cup of coffee
% Example 1: u_obser = 95, dt = 10; 
% Example 2: u_obser = 60, dt = 10; 
% Example 3: u_obser = -15, dt = 10;
% Example 4: u_obser = -73, dt = 10;
% Example 5: u_obser = 25, dt = 20; (dt = 100; u_obser = 80)

% setting up the parameters 
dt = 20; 			% time step size
t_final = 300; 		% final time
t = [0:dt:t_final];	% array of discretized time points
u0 = 100; 			% temperature of the coffee at t = 0
u_sur = 25; 		% surrounding (or room) temperature
h = 10;             % observation time for measuring 
					% insulation of the cup c
u_obser = 25;		% observed temperature after h minutes

[u, c] = TempOfCoffee(t, dt, u0, u_sur, u_obser, h);
% visualizing the result
disp('Estimate of the insulation of the cup:'),
disp(c) 

figure(1); 
plot(t, u, 'r', t, u_sur * ones(size(u)), 'b'); 
xlabel('Time (minutes)'); 
ylabel('Temperature (C)'); 
title('Approximating the temperature of coffee'); 
legend('Coffee','Room');

% Xs = [t', t']; Ys = [u', u_sur * ones(size(u'))]; 
% createfigure(Xs, Ys)
