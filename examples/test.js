var pHash = require('../index');

var hashA = pHash.getImageHash("a.jpg");
var hashB = pHash.getImageHash("b.png");
var hashC = pHash.getImageHash("c.png");
var hashD = pHash.getImageHash("d.jpg");

var hammingAB = pHash.hammingDistance(hashA,hashB);
var hammingAC = pHash.hammingDistance(hashA,hashC);
var hammingBC = pHash.hammingDistance(hashB,hashC);
var hammingAD = pHash.hammingDistance(hashA,hashD);

console.log("HashA: " + hashA);
console.log("HashB: " + hashB);
console.log("HashC: " + hashC);
console.log("HashD: " + hashD);

console.log("Hamming Distance A -> B: " + hammingAB);
console.log("Hamming Distance A -> C: " + hammingAC);
console.log("Hamming Distance B -> C: " + hammingBC);
console.log("Hamming Distance A -> D: " + hammingAD);
