require 'fileutils'

FileUtils.copy_entry "./src", "./src_asm/src"
FileUtils.copy_entry "./src", "./src_c/src"
FileUtils.copy_entry "./src", "./src_wasm/src"