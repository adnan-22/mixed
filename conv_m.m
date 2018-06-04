function [ y,n ] = conv_m( x,nx,h,nh )
n=min(nx)+min(nh):max(nx)+max(nh);
y=conv(x,h);
end

