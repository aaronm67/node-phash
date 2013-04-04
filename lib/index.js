var pHash = require('../build/Release/pHash');

exports.getImageHash = function(filePath) {
  return pHash.imagehash(filePath);
};
