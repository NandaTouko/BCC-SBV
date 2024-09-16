// Obter o elemento canvas
const canvas = document.getElementById('glcanvas');

// Obter o contexto WebGL
const gl = canvas.getContext('webgl');

// Verificar se o WebGL está disponível
if(!gl) {
    throw new Error('WebGL não disponível');
}

// Programa Vertex Shader
const vsSource = `
    atribute vec4 aVertexPosition;
    void main(void){
        gl_Position = aVertexPosition;
        gl_PointSize = 10.0;
    }`;

// Programa Fragment Shader
const fsSource = `
    void main(void){
        gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0); // Vermelho
    }`;