#include "reflective_shader.h"
#include "ray.h"
#include "render_world.h"
#include "light.h"

vec3 Reflective_Shader::
Shade_Surface(const Ray& ray,const vec3& intersection_point,
    const vec3& same_side_normal,int recursion_depth,bool is_exiting) const
{
    vec3 color;
    vec3 shader_color, reflected_color;
    Ray rayr;
    vec3 D = ray.direction.normalized();

    vec3 I = intersection_point;
    vec3 N = same_side_normal;
    shader_color = shader->Shade_Surface(ray,intersection_point,N,recursion_depth,is_exiting);

    vec3 R = ( D - 2.0* dot(D,N)* N  );
    rayr.endpoint = I;
    rayr.direction = R;
    recursion_depth++;
    reflected_color = world.Cast_Ray( rayr, recursion_depth);


    color = reflectivity * reflected_color + (1 - reflectivity) * shader_color;
    return color;
}
