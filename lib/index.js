var pHash = require('../build/Release/pHash');

exports.getImageHash = function(filePath) {
  return pHash.imagehash(filePath);
};

exports.hammingDistance = function(hasha,hashb) {
  return pHash.hammingDistance(hasha,hashb);
};