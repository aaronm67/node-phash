# node-phash

  [pHash](http://www.phash.org/) bindings for node.js.

  Phash is a library that will create a "perceptual hash" of media files, so similar files will return similar hashes. Typically to compare, 
  a simple [Hamming distance](http://en.wikipedia.org/wiki/Hamming_distance) between the two hashes will be a good indicator of how similar two
  images are.

  Current version supports only image hashing. (no video & audio hashing)

## Installation

node-phash depends on  [CImg](http://cimg.sourceforge.net/), [pHash](http://www.phash.org/), [ImageMagicK](http://www.imagemagick.org/).

On Ubuntu:

    sudo apt-get install cimg-dev libphash0-dev

On OSX:

    brew install phash imagemagick

Then, install using npm:

    $ npm install phash

## Usage

```js
var pHash = require("phash");

pHash.imageHash("file.jpg", function(err, hash) {
    if (err) {
        throw err;
    }

    // hash is the pHash of file.jpg
});

var hashA = pHash.imageHashSync("a.jpg");
var hashB = pHash.imageHashSync("b.png");
var hammingAB = pHash.hammingDistance(hashA,hashB);
console.log("Hamming Distance A -> B: " + hammingAB);
```
