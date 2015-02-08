# node-phash

  node-pash is [pHash](http://www.phash.org/) bindings for node.js.

  Phash is a library that will create a "perceptual hash" of media files, so similar files will return similar hashes. Typically to compare hashes, 
  a simple [Hamming distance](http://en.wikipedia.org/wiki/Hamming_distance) between the two hashes is a good indicator of how similar two
  media files are.

  Current version supports only image hashing. (no video & audio hashing)
  
  [![Build Status](https://travis-ci.org/aaronm67/node-phash.png?branch=master)](https://travis-ci.org/aaronm67/node-phash)

## Installation

Install using npm:

    $ npm install phash

## Functions

```js

// asynchronous hash
imageHash(filename, function(err, hash));

// synchronous hash
var hash = imageHashSync(filename);

hammingDistance(hash1, hash2);
```

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
