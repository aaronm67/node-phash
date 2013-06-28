# node-phash

  [pHash](http://www.phash.org/) bindings for node.js.
  
  Current version supports only image hashing. (no video & audio hashing)

## Installation

node-phash depends on  [CImg](http://cimg.sourceforge.net/), [pHash](http://www.phash.org/), [ImageMagicK](http://www.imagemagick.org/).

To install these packages in Ubuntu:

    sudo apt-get install cimg-dev libphash0-dev

On OSX:

    brew install phash imagemagick

Then, install using npm:

    $ npm install phash

## Example
```js
var pHash = require("phash");

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
```
