#!/usr/bin/env ruby

require 'fileutils'

cdir = ARGV[0]

# Cleanup our previously copied objects
FileUtils.rm_rf("./" + cdir + "/src_asm/src")
FileUtils.rm_rf("./" + cdir + "/src_c/src")
FileUtils.rm_rf("./" + cdir + "/src_c/progc")
FileUtils.rm_rf("./" + cdir + "/src_wasm/src")
FileUtils.rm_rf("./" + cdir + "/src_js/src")

# Cleanup our previously compiled objects
FileUtils.rm_rf("./" + cdir + "/asm")
FileUtils.rm_rf("./" + cdir + "/c")
FileUtils.rm_rf("./" + cdir + "/wasm")
FileUtils.rm_rf("./" + cdir + "/js")