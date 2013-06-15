var should = require('should');

var pHash = require('../index');


describe('pHash', function() {
  var oldHashA = pHash.getOldHash('./examples/a.jpg');
  
  var hashA = pHash.getImageHash("./examples/a.jpg");
  var hashB = pHash.getImageHash("./examples/b.png");
  var hashC = pHash.getImageHash("./examples/c.png");
  var hashD = pHash.getImageHash("./examples/d.jpg");

  //not really an image attempting to create an exception
  var hashF = pHash.getImageHash("./examples/f.png");

  // nonRBG image
  var hashG = pHash.getImageHash("./examples/g.jpg");

  // empty image
  var hashH = pHash.getImageHash("./examples/h.jpg");

  describe('getImageHash()', function() {
    it('should be done', function() {
      oldHashA.should.equal(2816561582497830000);
      
      hashA.should.equal('2816561582497829945');
      hashB.should.equal('2816561582497829945');
      hashC.should.equal('15433968795834791622');
      hashD.should.equal('12040987020241900649');

      hashF.should.equal('0');
      hashG.should.equal('18182116099082822440');
      hashF.should.equal('0');
    });
  });

  describe('hammingDistance()', function() {
    it('should be done', function() {
      var hammingAB = pHash.hammingDistance(hashA,hashB);
      var hammingAC = pHash.hammingDistance(hashA,hashC);
      var hammingBC = pHash.hammingDistance(hashB,hashC);
      var hammingAD = pHash.hammingDistance(hashA,hashD);

      hammingAB.should.equal(0);
      hammingAC.should.equal(38);
      hammingBC.should.equal(38);
      hammingAD.should.equal(12);
    });
  });

});
