var pHash = require('../index');

var hashA = pHash.getImageHash("a.jpg");
console.log("HashA: " + hashA);

var hashB = pHash.getImageHash("b.png");
console.log("HashB: " + hashB);

var hashC = pHash.getImageHash("c.png");
console.log("HashC: " + hashC);

var hashD = pHash.getImageHash("d.jpg");
console.log("HashD: " + hashD);


//not really an image attempting to create an exception
var hashF = pHash.getImageHash("f.png");
console.log("not an image: " + hashF);

var hashG = pHash.getImageHash("g.jpg");
console.log("nonRBG image: " + hashG);

var hashH = pHash.getImageHash("h.jpg");
console.log("empty image: " + hashH);


var hammingAB = pHash.hammingDistance(hashA,hashB);
var hammingAC = pHash.hammingDistance(hashA,hashC);
var hammingBC = pHash.hammingDistance(hashB,hashC);
var hammingAD = pHash.hammingDistance(hashA,hashD);


console.log("Hamming Distance A -> B: " + hammingAB);
console.log("Hamming Distance A -> C: " + hammingAC);
console.log("Hamming Distance B -> C: " + hammingBC);
console.log("Hamming Distance A -> D: " + hammingAD);
