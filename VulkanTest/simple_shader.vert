#version 450

vec2 positions[3] = vec2[] {
    vec2(0.0, -0.5),
    vec2(0.5, 0.5),
    vec2(-0.5, 0.5)
};

void main() {
    // 3rd data is z index
    // 4th data is normalization data which is divide other three by its value
    gl_Position = vec4(positions[gl_VertexIndex], 0.0, 1.0);
}