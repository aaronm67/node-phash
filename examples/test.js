var pHash = require('../index');

var hashA = pHash.getImageHash("a.jpg");
var hashB = pHash.getImageHash("b.png");
var hashC = pHash.getImageHash("c.png");

var hammingAB = pHash.hammingDistance(hashA,hashB);
var hammingAC = pHash.hammingDistance(hashA,hashC);

console.log("HashA: " + hashA);
console.log("HashB: " + hashB);
console.log("HashC: " + hashC);

console.log("Hamming Distance A -> B: " + hammingAB);
console.log("Hamming Distance A -> C: " + hammingAC);
