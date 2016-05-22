var assert = require("assert");
var pHash = require('../lib/phash');
require("should");

var examples = [
    { path: __dirname + "/data/a.jpg", hash: "2816561582497829945" },
    { path: __dirname + "/data/a.jpg", hash: "2816561582497829945" },
    { path: __dirname + "/data/c.png", hash: "15433968795834791622" },
    { path: __dirname + "/data/d.jpg", hash: "12040987020241900649" }
];

describe("pHash", function() {
    describe("sync test", function() {
        examples.forEach(function(i) {
            it(i.path, function() {
                var hash = pHash.imageHashSync(i.path);
                assert.equal(i.hash, hash);
            });
        });

        it("should fail", function() {
            var hashF = pHash.imageHashSync(__dirname + "/data/f.png");
            hashF.should.equal('0');
        });
    });

    // https://github.com/aaronm67/node-phash/issues/8
    describe("invalid file test", function() {
        it("should fail", function() {
            var hash = pHash.imageHashSync("fake/path/here");
            hash.should.equal("0");
        });

        it("should fail", function(done) {
            pHash.imageHash("fake/path/here", function(err, hash) {
                assert.equal(err.message, "Error getting image hash");
                assert(err);
                done();
            });
        });

    })

    describe("async test", function() {
        var test = examples[0];
        examples.forEach(function(i) {
            it(i.path, function(done) {
                pHash.imageHash(i.path, function(err, hash) { 
                    if (err) { 
                        done(err); 
                    }

                    assert.equal(i.hash, hash);
                    done();
                });
            });
        });

        it("should fail", function(done) { 
            pHash.imageHash(__dirname + "/data/f.png", function(err, hash) {
                assert.equal(err.message, "Error getting image hash");
                assert(err);
                done();
            });
        });

        it("should throw", function() {
            assert.throws(function() {
                pHash.imageHash("not enough arguments");
            });
        });

        it("should throw", function() {
            assert.throws(function() {
                pHash.imageHash("not enough arguments", 123);
            });
        });
    });

    describe("legacy test", function() {
        it("should match", function() {
            examples.forEach(function(i) {
                var hash = pHash.getImageHash(i.path);
                assert.equal(i.hash, hash);
            });
        });

        it("should fail", function() {
            var hashF = pHash.getImageHash(__dirname + "/data/f.png");
            hashF.should.equal('0');
        });
    });

    describe('hammingDistance()', function() {
        it('should be done', function() {
            var hammingAB = pHash.hammingDistance(examples[0].hash,examples[1].hash);
            var hammingAC = pHash.hammingDistance(examples[0].hash,examples[2].hash);
            var hammingBC = pHash.hammingDistance(examples[1].hash,examples[2].hash);
            var hammingAD = pHash.hammingDistance(examples[0].hash,examples[3].hash);
            hammingAB.should.equal(0);
            hammingAC.should.equal(38);
            hammingBC.should.equal(38);
            hammingAD.should.equal(12);
        }); 
    });
});
