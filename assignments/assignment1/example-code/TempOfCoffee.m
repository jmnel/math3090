function [u, c] = TempOfCoffee(t, dt, u0, u_sur, u_obser, h)
%  This code models the cooling of a well-stirred cup 
%  of coffee, based on Newton's law of cooling. 
%  It solves the first order difference algorithm. 
%  
%  Inputs
%   t  - a vector of time points. 
%        Here, t(1) gives the initial time
%   dt - duration of one time step
%   u0 - initial observed temperature of the coffee
%   dt - during of small changes of time
%   u_sur - the fixed surrounding temperature
%   u_obser  - observed temperature after h
%   h  - observation time for estimating c
%   c  - insulation of the cup
%  
%  Outputs: 
%   u  - the temperature of the coffee at each time point;
%        the same length as that of time t.
%   c  - insulation of the cup
% 
%  Reference: White, R.E. "Computational Mathematics
%             Models, Methods, and Analysis", CRC 2004
%             Chapter 1, page 5.
%  
%  Revised by Hongmei Zhu, September 2, 2005

% initialize parameters
N = length(t); 
u = zeros(size(t)); 
u(1) = u0;

% compute the insulation of the cup
c = (u_obser - u(1))/(h*(u_sur - u(1))); 

% compute the parameter in the model
a = 1 - c * dt;
disp('The parameter a:')
disp(a);
b = c*dt*u_sur; 

% compute the temperature at time t = k*dt 
for k = 2:N
    u(k) = a * u(k-1) + b; 
end
