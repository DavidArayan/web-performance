#!/usr/bin/env ruby

require 'fileutils'

FileUtils.mkdir_p "./compiled"

# Compile, Copy, Cleanup of default folder
system("cd default && ruby clean.rb")
system("cd default && ruby copy.rb")
system("cd default && ruby compile.rb")

FileUtils.mkdir_p "./compiled/default"

FileUtils.copy_entry "./default/asm", "./compiled/default/asm"
FileUtils.copy_entry "./default/wasm", "./compiled/default/wasm"