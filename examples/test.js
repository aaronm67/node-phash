var pHash = require('../index');

var hashA = pHash.getImageHash("a.jpg");
var hashB = pHash.getImageHash("b.png");
var hashC = pHash.getImageHash("c.png");
var hashD = pHash.getImageHash("d.jpg");

//not really an image attempting to create an exception
var hashF = pHash.getImageHash("f.png");
var hashG = pHash.getImageHash("g.jpg");
var hashH = pHash.getImageHash("h.jpg");


var hammingAB = pHash.hammingDistance(hashA,hashB);
var hammingAC = pHash.hammingDistance(hashA,hashC);
var hammingBC = pHash.hammingDistance(hashB,hashC);
var hammingAD = pHash.hammingDistance(hashA,hashD);

console.log("HashA: " + hashA);
console.log("HashB: " + hashB);
console.log("HashC: " + hashC);
console.log("HashD: " + hashD);
console.log("not an image: " + hashF);
console.log("nonRBG image: " + hashG);
console.log("empty image: " + hashH);

console.log("Hamming Distance A -> B: " + hammingAB);
console.log("Hamming Distance A -> C: " + hammingAC);
console.log("Hamming Distance B -> C: " + hammingBC);
console.log("Hamming Distance A -> D: " + hammingAD);
