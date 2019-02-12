#!/usr/bin/env ruby

require 'fileutils'

puts " ----------------------------"
puts " --- Running ASM Makefile ---"
puts " ----------------------------"

system("cd src_asm && make")

puts "\n"
puts " --------------------------"
puts " --- Running C Makefile ---"
puts " --------------------------"

system("cd src_c && make")

puts "\n"
puts " -----------------------------"
puts " --- Running WASM Makefile ---"
puts " -----------------------------"

system("cd src_wasm && make")

puts "\n"
puts " ----------------------------"
puts " --- COPY ASM FINAL FILES ---"
puts " ----------------------------"

FileUtils.mkdir_p "./asm"

Dir.glob("./src_asm/*.mem") {|file|
	puts "Moving .mem File #{file}"
	FileUtils.mv(file, "./asm")
}

Dir.glob("./src_asm/*.js") {|file|
	puts "Moving .js File #{file}"
	FileUtils.mv(file, "./asm")
}

Dir.glob("./src_asm/*.html") {|file|
	puts "Moving .html File #{file}"
	FileUtils.mv(file, "./asm")
}

puts "\n"
puts " --------------------------"
puts " --- COPY C FINAL FILES ---"
puts " --------------------------"
puts "Copying of C Binaries will be skipped"


puts "\n"
puts " -----------------------------"
puts " --- COPY WASM FINAL FILES ---"
puts " -----------------------------"

FileUtils.mkdir_p "./wasm"

Dir.glob("./src_wasm/*.wasm") {|file|
	puts "Moving .wasm File #{file}"
	FileUtils.mv(file, "./wasm")
}

Dir.glob("./src_wasm/*.js") {|file|
	puts "Moving .js File #{file}"
	FileUtils.mv(file, "./wasm")
}

Dir.glob("./src_wasm/*.html") {|file|
	puts "Moving .html File #{file}"
	FileUtils.mv(file, "./wasm")
}

puts "\n"
puts " -----------------"
puts " --- ALL DONE! ---"
puts " -----------------"