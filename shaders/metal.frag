
varying vec3 vertex;		// The position of the vertex, in eye space
varying vec3 light;		// The normalized vector from the vertex to the light
varying vec3 eye;		// The normalized vector from the vertex to the eye
varying vec3 normal;		// The normal vector of the vertex, in eye space

uniform samplerCube envMap;	// The cube map containing the environment to reflect
uniform vec4 ambient;		// The ambient channel of the color to reflect
uniform vec4 diffuse;		// The diffuse channel of the color to reflect
uniform vec4 specular;		// The specular channel of the color to reflect
    
uniform float r0;		// The Fresnel reflectivity when the incident angle is 0
uniform float m;		// The roughness of the material

void main()
{
    vec3 e = normalize(eye);
    vec3 n = normalize(normal);
    vec3 i = normalize(vertex - eye);
    vec3 l = normalize(light);
    vec3 h = normalize(l - i);
    
    // TODO
    float intensity = dot(n, l);
    vec3 r = reflect(-1, n);
    intensity = intensity + pow(dot(e, r), specular);
    
    //calculate sampler cube vector
    vec3 env_vector = reflect(e, n);
    env_vector.y = -1.0 * env_vector.y;
    
    gl_FragColor = textureCube(envMap, env_vector) * intensity;
}
