attribute vec3 vertexIn;    // xyz vertex coordinates
attribute vec2 textureIn;   // xy texture coordinates
varying vec2 textureOut;    // Texture coordinates passed to the fragment shader

void main(void)
{
    gl_Position = vec4(vertexIn, 1.0);  // 1.0 means vertexIn is a vertex position
    textureOut = textureIn;             // Texture coordinates are passed directly to the fragment shader
}
