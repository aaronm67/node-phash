{
  'targets': [
    {
      'target_name': 'pHash',
      'sources': [ 'pHash.cpp' ],
      'cflags_cc': ['-fexceptions'],
      'link_settings': {
        'libraries': ['-lpHash']
      }
    }
  ]
}

