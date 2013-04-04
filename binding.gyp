{
  'targets': [
    {
      'target_name': 'phash',
      'sources': [ 'phash.cpp' ],
      'cflags_cc': ['-fexceptions'],
      'link_settings': {
        'libraries': ['-lpHash']
      }
    }
  ]
}

