varying vec3 lightDir,normal,pos;
void main()
{
    //use example 3 to compute pos
    pos= (gl_ModelViewMatrix * gl_Vertex).xyz;

    //use example 5 to compute surface normal
    normal = normalize(gl_NormalMatrix * gl_Normal);

    //use example 6 to compute light_direction
    lightDir=normalize(gl_LightSource[0].position.xyz-pos);

    //use example 1 to set gl_Position
    gl_Position = gl_ProjectionMatrix * gl_ModelViewMatrix * gl_Vertex;
}
  
