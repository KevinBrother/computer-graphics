#version 330 core
out vec4 FragColor; // 指定一个片段着色器的输出变量名

struct Material {
    sampler2D diffuse;
    sampler2D specular;
    sampler2D emission;
    float shininess;
};

struct EmissionMatrix {
    float matrixlight;
    float matrixmove;
};

struct Light {
    vec3 position;
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
};

uniform Material material;
uniform Light light;
uniform EmissionMatrix emissionMatrix;

in vec3 Normal;
in vec3 FragPos;
in vec2 TexCoords;

//uniform vec3 objectColor;
uniform vec3 lightColor;
uniform vec3 lightPos; // 光源位置
uniform vec3 viewPos; // 观察者位置，其实就是摄像机位置

void main()
{
    // 光照计算 =====

    // 环境光 ambient light
    // 材质的环境光颜色几乎在所有的情况下都等于漫反射颜色，所以不需要分开存储
    vec3 ambient = light.ambient * vec3(texture(material.diffuse, TexCoords).rgb);

    // 漫反射 diffuse light
    vec3 norm = normalize(Normal);
    vec3 lightDir = normalize(lightPos - FragPos);
    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = light.diffuse * diff * vec3(texture(material.diffuse, TexCoords).rgb);

    // 镜面反射 specular light
    vec3 viewDir = normalize(viewPos - FragPos);
    vec3 reflectDir = reflect(-lightDir, norm);
    float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
    vec3 specular = light.specular * spec * vec3(texture(material.specular, TexCoords).rgb);

    // 放射光 emission light
//    vec3 emission = texture(material.emission, TexCoords).rgb;
//    vec3 emission = emissionMatrix.matrixlight *  texture(material.emission, vec2(TexCoords.x, TexCoords.y + emissionMatrix.matrixmove)).rgb;
    vec3 emission;
    float x = TexCoords.x;
    float y = TexCoords.y;
    float offset = emissionMatrix.matrixmove;

    if (x < 0.2 || x > 0.8 || y < 0.2 || y > 0.8) {
        emission = texture(material.emission, TexCoords + vec2(0.0, offset)).rgb;
    } else {
        emission = vec3(0.0);
    }

    vec3 result = ambient + diffuse + specular + emission;
    FragColor = vec4(result, 1.0);
}