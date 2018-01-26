#include "plane.h"
#include "ray.h"
#include <iostream>
#include <cfloat>


// Intersect with the half space defined by the plane.  The plane's normal
// points outside.  If the ray starts on the "inside" side of the plane, be sure
// to record a hit with t=0 as the first entry in hits.
bool Plane::
Intersection(const Ray& ray, std::vector<Hit>& hits) const
{
    vec3 u = ray.direction;
    vec3 e = ray.endpoint;
    vec3 q = x1;
    vec3 n = normal;

    // TODO
    //vec3 p = (ray.endpoint - center );
    Hit h;
    h.object = this;
    double l = dot(u, n);
    double p = dot(n, (e-q));

    if(l == 0)
      return false;
      /*
        //std::cout<<"reached\n"<<std::endl;
        if(p == 0){
            h.t = 0;
            h.ray_exiting = l > 0;
            hits.push_back(h);
            return true;
        }else{

        }
    }*/
    double t = -p/l;

    h.t = t;
    h.ray_exiting = l > 0;

    hits.push_back(h);

    return true;
}

vec3 Plane::
Normal(const vec3& point) const
{
    return normal;
}
