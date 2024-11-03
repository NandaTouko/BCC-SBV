/*
    Criar uma cena com dois objetos 3D, um cubo e uma esfera, e uma fonte de luz.
    Utilize diferentes fontes de luz e avalie o efeito de cada uma sobre os objetos.
    - Luz ambiente;
    - Luz direcional;
    - Luz pontual;
    - Luz spot;
    - Utilizar câmera perspectiva e orbit control
*/

import * as THREE from 'three';
import { OrbitControls } from 'three/examples/jsm/controls/OrbitControls';
import { GUI } from 'dat.gui';

class ColorGUIHelper {
    constructor(object, prop) {
        this.object = object;
        this.prop = prop;
    }
    get value() {
        return `#${this.object[this.prop].getHexString()}`;
    }
    set value(hexString) {
        this.object[this.prop].set(hexString);
    }
}

// cria o renderizador
const renderizador = new THREE.WebGLRenderer();
renderizador.setSize(window.innerWidth, window.innerHeight);
document.body.appendChild(renderizador.domElement);

// cria a camera
const camera = new THREE.PerspectiveCamera(45, 2, 0.1, 100);
camera.position.set(0, 10, 20);

// cria um controle de órbita
const orbita = new OrbitControls(camera, renderizador.domElement);
orbita.target.set(0, 5, 0);
orbita.update();

// cria a cena
const cena = new THREE.Scene();
cena.background = new THREE.Color('black');





// iluminação
const light = new THREE.AmbientLight(0xFFFFFF, 1);
cena.add(light);



// popular a cena
const cubo = new THREE.Mesh(
    new THREE.BoxGeometry(),
    new THREE.MeshBasicMaterial({
        color: 0xc8a2c8,
        wireframe: true
    })
);
cena.add(cubo);
cubo.position.set(-2, 0, 0);

const esfera = new THREE.Mesh(
    new THREE.SphereGeometry(),
    new THREE.MeshBasicMaterial({
        color: 0x00ffff,
        wireframe: true
    })
);
cena.add(esfera);
esfera.position.set(2, 0, 0);

// cria menu de interação
const gui = new GUI();
gui.addColor(new ColorGUIHelper(light, 'color'), 'value').name('color');
gui.add(light, 'intensity', 0, 2, 0.01);

function animacao() {
    requestAnimationFrame(animacao);
    orbita.update();
    // renderiza a cena
    renderizador.render(cena, camera);
}

animacao();