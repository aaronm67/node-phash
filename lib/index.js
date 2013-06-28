var pHash = require('../build/Release/pHash');

exports.imageHashSync = function(file) {
    return pHash.imageHashSync(file);
};

exports.imageHash = function(file, cb) {
    return pHash.imageHash(file, cb);
};

exports.hammingDistance = function(hasha,hashb) {
  return pHash.hammingDistance(hasha,hashb);
};

/*
    Deprecated, use "imageHashSync"
*/
exports.getImageHash = exports.imageHashSync;

exports.getOldHash = function(filePath) {
    return pHash.oldHash(filePath);
};



