{
  'includes': [ 'deps/common.gyp' ],
  'targets': [
    {
      'target_name': 'pHashBinding',
      'defines': [
        'HAVE_IMAGE_HASH',
        'cimg_use_png',
        'cimg_verbosity=0',
      ],
      'include_dirs': [
        'deps/pHash',
        'deps/libpng',
       ],
      'sources': [ 'src/phash.cpp' ],
      'dependencies': [
        'deps/zlib/zlib.gyp:zlib',
        'deps/libpng/libpng.gyp:libpng',
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
      ],
    }
  ]
}

