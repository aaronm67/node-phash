var pHash = require('../index');

console.log('oldHashA: \t' + pHash.getOldImageHash('a.jpg'));

var hashA = pHash.getImageHash("a.jpg");
console.log("HashA: \t\t" + hashA);

var hashB = pHash.getImageHash("b.png");
console.log("HashB: \t\t" + hashB);

var hashC = pHash.getImageHash("c.png");
console.log("HashC: \t\t" + hashC);

var hashD = pHash.getImageHash("d.jpg");
console.log("HashD: \t\t" + hashD);


//not really an image attempting to create an exception
var hashF = pHash.getImageHash("f.png");
console.log("HashF (not an image): \t" + hashF);

var hashG = pHash.getImageHash("g.jpg");
console.log("HashG (nonRBG image): \t" + hashG);

var hashH = pHash.getImageHash("h.jpg");
console.log("HashH (empty image): \t" + hashH);


var hammingAB = pHash.hammingDistance(hashA,hashB);
var hammingAC = pHash.hammingDistance(hashA,hashC);
var hammingBC = pHash.hammingDistance(hashB,hashC);
var hammingAD = pHash.hammingDistance(hashA,hashD);


console.log("Hamming Distance A -> B: " + hammingAB);
console.log("Hamming Distance A -> C: " + hammingAC);
console.log("Hamming Distance B -> C: " + hammingBC);
console.log("Hamming Distance A -> D: " + hammingAD);
