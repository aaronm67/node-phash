{
  'includes': [ '../common.gyp' ],
  'targets': [
    {
      'target_name': 'phash',
      'type': 'static_library',
      'defines': [
        'HAVE_IMAGE_HASH',
        'cimg_verbosity=0',
        'cimg_use_png',
        'cimg_use_jpeg',
      ],
      'include_dirs': [
        '.',
        '../libpng',
        '../libjpeg',
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
