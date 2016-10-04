{
  'includes': [ 'deps/common.gyp' ],
  'targets': [
    {
      'target_name': 'pHashBinding',
      'defines': [
        'HAVE_IMAGE_HASH',
        'cimg_verbosity=0',
        'cimg_use_png',
        'cimg_use_jpeg',
      ],
      'include_dirs': [
        "<!(node -e \"require('nan')\")",
        'deps/pHash',
        'deps/libpng',
        'deps/libjpeg',
       ],
      'sources': [ 'src/phash.cpp' ],
      'dependencies': [
        'deps/zlib/zlib.gyp:zlib',
        'deps/libpng/libpng.gyp:libpng',
        'deps/libjpeg/libjpeg.gyp:libjpeg',
        'deps/pHash/pHash.gyp:phash',
      ],
      'conditions': [
        ['OS=="win"',
          {
            'include_dirs': [
              'deps/pHash/win32/',
            ],
          },
        ],
	['OS == "mac"', 
	  {
	    'ccflags': [
      	      '-mmacosx-version-min=10.7',
      	      '-std=c++11',
      	      '-stdlib=libc++'
	    ]
	  }
	]
      ],
    }
  ]
}

