ll max_till_here=0;
ll max_so_far=*max_element(&v[0],&v[n]);
for(auto &x:v){
max_till_here+=x;
if(max_till_here>max_so_far)max_so_far=max_till_here;
if(max_till_here<0)max_till_here=0;
}	   