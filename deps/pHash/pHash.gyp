{
  'includes': [ '../common.gyp' ],
  'targets': [
    {
      'target_name': 'phash',
      'type': 'static_library',
      'defines': [
        'HAVE_IMAGE_HASH',
        'cimg_use_png',
        'cimg_verbosity=0',
      ],
      'include_dirs': [
        '.',
        '../libpng',
      ],
      'sources': [
        './ph_fft.c',
        './pHash.cpp',
        './phcomplex.c',
      ],
      'conditions': [
        ['OS=="win"',
          {
            'include_dirs': [
              './win32/',
            ],
            'sources': [
             './win32/dirent.c',
            ],
          },
        ],
      ],
    },
  ],
}
