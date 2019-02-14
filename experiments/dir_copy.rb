#!/usr/bin/env ruby

require 'fileutils'

cdir = ARGV[0]

FileUtils.copy_entry ("./" + cdir + "/src"), ("./" + cdir + "/src_asm/src")
FileUtils.copy_entry ("./" + cdir + "/src"), ("./" + cdir + "/src_c/src")
FileUtils.copy_entry ("./" + cdir + "/src"), ("./" + cdir + "/src_wasm/src")