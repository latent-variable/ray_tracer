#include "sphere.h"
#include "ray.h"


// Determine if the ray intersects with the sphere
bool Sphere::Intersection(const Ray& ray, std::vector<Hit>& hits) const
{
   vec3 p = (ray.endpoint - center );
   
   double x = dot(ray.direction, p);
   double z = dot(p,p);
   
   double delta = pow(2,(2 *x )) - 4*( z - pow(2,radius));
   
    if (delta <= 0 ) return false; 
  
    double t1 = (-2*dot(ray.direction, p ) - sqrt(delta))/2;
    double t2 = (-2*dot(ray.direction, p ) + sqrt(delta))/2;
    if(t1 > 0 ){
        Hit h1;
        h1.object = this; 
        h1.t = t1; 
        h1.ray_exiting = false;
        hits.push_back(h1);
        
    }
    Hit h2;
    h2.object = this; 
    h2.t = t2; 
    h2.ray_exiting = true;
    hits.push_back(h2);
        
    return true;
    
}

vec3 Sphere::Normal(const vec3& point) const
{
    vec3 normal;
    // TODO: set the normal
    return normal;
}
