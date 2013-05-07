{
  'targets': [
    {
      'target_name': 'pHash',
      'sources': [ 'phash.cpp' ],
      'cflags_cc': ['-fexceptions'],
      'link_settings': {
        'libraries': ['-lpHash']
      }
    }
  ]
}

