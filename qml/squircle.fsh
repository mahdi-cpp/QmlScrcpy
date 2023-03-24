varying vec2 textureOut;        // Texture coordinates passed by the vertex shader
uniform sampler2D textureY;     // uniform Texture unit, using texture unit can use multiple textures
uniform sampler2D textureU;     // sampler2D is a 2D sampler
uniform sampler2D textureV;     // Declare yuv three texture units
void main(void)
{
    vec3 yuv;
    vec3 rgb;

    // SDL2 BT709_SHADER_CONSTANTS
    // https://github.com/spurious/SDL-mirror/blob/4ddd4c445aa059bb127e101b74a8c5b59257fbe2/src/render/opengl/SDL_shaders_gl.c#L102
    const vec3 Rcoeff = vec3(1.1644,  0.000,  1.7927);
    const vec3 Gcoeff = vec3(1.1644, -0.2132, -0.5329);
    const vec3 Bcoeff = vec3(1.1644,  2.1124,  0.000);

    // Sampling according to the specified texture textureY and coordinate textureOut
    yuv.x = texture2D(textureY, textureOut).r;
    yuv.y = texture2D(textureU, textureOut).r - 0.5;
    yuv.z = texture2D(textureV, textureOut).r - 0.5;

    // Convert to rgb after sampling
    // reduce some brightness
    yuv.x = yuv.x - 0.0625;
    rgb.r = dot(yuv, Rcoeff);
    rgb.g = dot(yuv, Gcoeff);
    rgb.b = dot(yuv, Bcoeff);
    // output color value
    gl_FragColor = vec4(rgb, 1.0);
}