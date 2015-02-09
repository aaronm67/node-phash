# pHash [![NPM version](https://badge.fury.io/js/phash.png)](http://badge.fury.io/js/phash) [![Build Status](https://travis-ci.org/aaronm67/node-phash.png?branch=master)](https://travis-ci.org/aaronm67/node-phash)

[pHash](http://www.phash.org/) bindings for [Node.js](http://nodejs.org/).

A pHash is a "perceptual hash" of a multimedia file derived from various features from its content. This can be useful to compare similar files, create database indices and so on.

Note: Currently supports only images - no video or audio.

## Installation

    $ npm install phash

## Usage

```javascript
var pHash = require("phash");

pHash.imageHash("file.jpg", function(err, hash) {
    if (err) {
        console.error(err);
    }
    console.log("pHash: " + hash);
});

var hashA = pHash.imageHashSync("a.jpg");
var hashB = pHash.imageHashSync("b.png");
var hammingAB = pHash.hammingDistance(hashA, hashB);
console.log("Hamming Distance A -> B: " + hammingAB);
```

## API

### pHash#imageHash

Computes a pHash asynchronously.

```javascript
imageHash(filename, function(err, hash));
```

### pHash#imageHashSync

Computes a pHash.

```javascript
var hash = imageHashSync(filename);
```

### pHash#hammingDistance

Computes the [Hamming distance](http://en.wikipedia.org/wiki/Hamming_distance) between the two pHashes.

```
hammingDistance(hashA, hashB);
```

## License

Licensed under the incredibly [permissive](http://en.wikipedia.org/wiki/Permissive_free_software_licence) [MIT License](http://creativecommons.org/licenses/MIT/). Copyright &copy; 2013 Aaron Marasco. <br>
Dependencies may be licensed diffrently.

NOTE: The Node bindings for pHash provided are are MIT licensed and may be used and modified freely. You must also comply with the terms of whichever [pHash License](http://www.phash.org/licensing/) you are using.