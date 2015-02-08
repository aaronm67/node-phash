{
  'targets': [
    {
      'target_name': 'phash',
      'type': 'static_library',
      'defines': [
        'HAVE_IMAGE_HASH',
        'cimg_use_png',
      ],
      'include_dirs': [
        '.',
        '../libpng',
      ],
      'sources': [
        './dirent.c',
        './ph_fft.c',
        './pHash.cpp',
        './phcomplex.c',
      ],
    },
  ]
}
