{
  'target_defaults': {
    'conditions': [
      ['OS=="linux"',
        {
          'cflags_cc!': [ '-fno-exceptions' ],
        }
      ],
      ['OS=="mac"',
        {
          'xcode_settings': {
            'GCC_ENABLE_CPP_EXCEPTIONS': 'YES',
          }
        }
      ],
      ['OS=="win"',
        {
          'configurations': {
            'Debug': {
              'msvs_settings': {
                'VCCLCompilerTool': {
                  'ExceptionHandling': '1',
                },
              },
            },
            'Release': {
              'msvs_settings': {
                'VCCLCompilerTool': {
                  'ExceptionHandling': '1',
                },
              },
            },
          },
        }
      ]
    ]
  }
}
