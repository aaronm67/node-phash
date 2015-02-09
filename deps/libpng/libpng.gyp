{
  'includes': [ '../common.gyp' ],
  'targets': [
    {
      'target_name': 'libpng',
      'type': 'static_library',
      'include_dirs': [
        '.',
        '../zlib'
      ],
      'sources': [
        'png.c',
        'pngerror.c',
        'pngget.c',
        'pngmem.c',
        'pngpread.c',
        'pngread.c',
        'pngrio.c',
        'pngrtran.c',
        'pngrutil.c',
        'pngset.c',
        'pngtest.c',
        'pngtrans.c',
        'pngwio.c',
        'pngwrite.c',
        'pngwtran.c',
        'pngwutil.c',
      ],
    },
  ]
}
