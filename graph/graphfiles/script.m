x = [25000,50000,75000,100000,125000,150000,175000,200000,225000,250000];
quicky=[0.014035,0.028864,0.044903,0.061915,0.079585,0.101621,0.117891,0.141579,0.158426,0.180286];
quickintroy=[0.009957,0.024318,0.035123,0.049459,0.064614,0.080855,0.104398,0.115522,0.129864,0.149968];
selectiony=[0.108327,0.447456,1.09285,2.03542,3.85115,5.2438,6.61026,9.13911,12.0144,15.1512];
plot(x,selectiony,'r');
hold on
plot(x,quicky,'b');
hold on
plot(x,quickintroy,'g');