#include "light.h"
#include "point_light.h"
#include "phong_shader.h"
#include "ray.h"
#include "render_world.h"
#include "object.h"
#include <iostream>

using namespace std;

vec3 Phong_Shader::
Shade_Surface(const Ray& ray,const vec3& intersection_point,
    const vec3& same_side_normal,int recursion_depth,bool is_exiting) const
{
    vec3 color;
    vec3 I = intersection_point;
    vec3 N = same_side_normal;

    vec3 Ambient;
    vec3 Diffuse;
    vec3 Specular;


     // TODO: determine the color
     // world.lights[i]->
     //Ambient Ia = Ra*La
     Ambient = world.ambient_color * world.ambient_intensity * color_ambient;
     color = Ambient;

     for(unsigned i = 0; i < world.lights.size(); i++){

        vec3 L = world.lights[i]->position - I ; // Light vector to intersect
        float d = dot((L),(L)); // Magnitude of Light Square

        if (world.enable_shadows){

           Hit hit;
           Ray ray2(I,L.normalized());
           Object *obj = world.Closest_Intersection(ray2,hit );

           if(!obj){
                goto COLOR;
            }else{
                if(hit.t < sqrt(d) )
                    continue;
                else goto COLOR;

            }
        }else{

           COLOR:

           //Light color square distance between the intersection point and the light source
           vec3 light_color = ((world.lights[i]->Emitted_Light(ray))/ d);

           //Diffuse Id = Rd*Ld*max(0,light*normal)
           float cs = max( dot((L).normalized(),N), 0.0);
           //square distance between the intersection point and the light source
           Diffuse = color_diffuse  * cs * light_color;

           //Specular
           vec3 L_norm = L.normalized();
           vec3 R = ( 2.0* dot(L_norm,N)* N - L_norm);
           R = R.normalized();
           float cs2 = max(dot( R , (-ray.direction).normalized() ),0.0);
           double Specular_intensity = pow(cs2,specular_power);
           Specular = (light_color*color_specular)*Specular_intensity;

           color = color + Diffuse + Specular;
       }


     }
    return color;
}
