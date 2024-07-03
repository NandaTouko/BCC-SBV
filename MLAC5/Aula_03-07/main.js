function fahrenheitToCelsius(fahrenheit) {
	var celsius = (5/9) * (fahrenheit-32);
	window.alert(fahrenheit + "°F = " + celsius + "°C");
}

function raizesEqSegGrau(a, b, delta) {
	var r1 = (-b + Math.sqrt(delta))/2*a;
	var r2 = (-b - Math.sqrt(delta))/2*a;
	document.write("Raíz 1 = " + r1.toFixed(2) + "<br/> Raíz 2 = " + r2.toFixed(2) + "<br/>");
}

function delta(a, b, c) {
	var delta = b*b - 4*a*c;
	document.write("Delta = " + delta + "<br/>");
	raizesEqSegGrau(a, b, delta);
}

function PA(p1, razao, qtdElementos) {
	var p2 = p1 + (qtdElementos-1) * razao;
	document.write("Último elemento da PA = " + p2 + "<br/>");
}

function PG(p1, razao, qtdElementos) {
	var p2 = p1 * Math.pow(razao, (qtdElementos-1));
	document.write("Último elemento da PG = " + p2 + "<br/>");
}