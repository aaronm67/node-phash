# node-phash

  [pHash](http://www.phash.org/) bindings for node.js.
  
  Current version supports only image hashing. (no video & audio hashing)

## Installation

Install [CImg](http://cimg.sourceforge.net/), [pHash](http://www.phash.org/), [ImageMagicK](http://www.imagemagick.org/) packages first.

    $ npm install phash

## Example
```js
var pHash = require("phash");

console.log(pHash.getImageHash("a.jpg"));
console.log(pHash.getImageHash("b.png"));
```
