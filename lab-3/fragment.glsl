
//HINTS:
//  use gl_FrontMaterial's properties such as ambient, diffuse, specular
//  and shininess for material properties. (use gl_LightSource for light
//  specular contribution)

varying vec3 lightDir,normal,pos;
void main()
{
    //use exaples above to set these vectors
    //Don't forget to normalize

    vec3 l,n,eye,r;
    l = normalize(lightDir);
    n = normalize(normal);
    r = normalize(-reflect(l,n));
    eye = normalize(-pos);

    // compute ambient component and add to color
    vec4 color_ambient = gl_LightSource[0].ambient* gl_FrontMaterial.ambient;

    // compute diffuse component and add to color
    vec4 color_diffuse = gl_LightSource[0].diffuse* gl_FrontMaterial.diffuse * max(0.0, dot(n,l));

    // compute specular component and add to color

    vec4 color_specular = gl_LightSource[0].specular* gl_FrontMaterial.specular * pow(max(0.0,dot(r,eye)),gl_FrontMaterial.shininess);

    vec4 color = color_ambient + color_diffuse + color_specular;
    gl_FragColor = color;
}
