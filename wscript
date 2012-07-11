import Options
from os import unlink, symlink, popen
from os.path import exists

srcdir = "."
blddir = "build"
VERSION = "0.0.1"

def set_options(opt):
  opt.tool_options("compiler_cxx")

def configure(conf):
  conf.check_tool("compiler_cxx")
  conf.check_tool("node_addon")
  conf.env.append_value("LINKFLAGS", "-lpHash");

def build(bld):
  obj = bld.new_task_gen("cxx", "shlib", "node_addon")
  obj.target = "phash"
  obj.source = "phash.cpp"

def shutdown():
  if Options.commands['clean']:
    if exists('phash.node'): unlink('phash.node')
  else:
    if exists('build/Release/phash.node') and not exists('phash.node'):
      symlink('build/Release/phash.node', 'phash.node')

