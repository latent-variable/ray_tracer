#include "light.h"
#include "phong_shader.h"
#include "ray.h"
#include "render_world.h"
#include "object.h"

vec3 Phong_Shader::
Shade_Surface(const Ray& ray,const vec3& intersection_point,
    const vec3& same_side_normal,int recursion_depth,bool is_exiting) const 
{
    vec3 color;
    vec3 L = normalize(ray.direction);
    vec3 E = normalize(ray.endpoint);
    vec3 R; // add 

    //Ambient 
    vec3 Ambient = world.ambient_color + world.ambient_instensity + color_ambient;

     // TODO: determine the color
    color = Ambient;

    return color;
}
