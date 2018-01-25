
//HINTS: 
//  use gl_FrontMaterial's properties such as ambient, diffuse, specular
//  and shininess for material properties. (use gl_LightSource for light 
//  specular contribution)

varying vec3 lightDir,normal,pos;
void main()
{
    //use exaples above to set these vectors
    //Don't forget to normalize
    
    vec3 l,n,eye;
    l = lightDir;
    n = normal;
    eye = pos;
    
    vec4 color = vec4(0.0,0.0,0.0,0.0);
    // compute ambient component and add to color
    color = color + cross(gl_LightSource[1].ambient, gl_FrontMaterial.ambient);

    // compute diffuse component and add to color
    color = color+ cross(gl_LightSource[1].diffuse, gl_FrontMaterial.diffuse) * max(0.0, dot(l,n));

    // compute specular component and add to color
    color = color + cross(gl_LightSource[1].specular, gl_FrontMaterial.specular) *max(0.0,dot(eye,l));
    
    gl_FragColor = color;    
}
 
