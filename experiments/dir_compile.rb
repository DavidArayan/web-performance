#!/usr/bin/env ruby

require 'fileutils'

cdir = ARGV[0]

puts " ----------------------------"
puts " --- Running ASM Makefile ---"
puts " ----------------------------"

system("cd " + cdir + "/src_asm && make")

puts "\n"
puts " --------------------------"
puts " --- Running C Makefile ---"
puts " --------------------------"

system("cd " + cdir + "/src_c && make")

puts "\n"
puts " -----------------------------"
puts " --- Running WASM Makefile ---"
puts " -----------------------------"

system("cd " + cdir + "/src_wasm && make")

puts "\n"
puts " ----------------------------"
puts " --- COPY ASM FINAL FILES ---"
puts " ----------------------------"

FileUtils.mkdir_p "./" + cdir + "/asm"

Dir.glob("./" + cdir + "/src_asm/*.mem") {|file|
	puts "Moving .mem File #{file}"
	FileUtils.mv(file, "./" + cdir + "/asm")
}

Dir.glob("./" + cdir + "/src_asm/*.js") {|file|
	puts "Moving .js File #{file}"
	FileUtils.mv(file, "./" + cdir + "/asm")
}

Dir.glob("./" + cdir + "/src_asm/*.html") {|file|
	puts "Moving .html File #{file}"
	FileUtils.mv(file, "./" + cdir + "/asm")
}

puts "\n"
puts " --------------------------"
puts " --- COPY C FINAL FILES ---"
puts " --------------------------"
puts "Copying of C Binaries will be skipped"

puts "\n"
puts " ---------------------------"
puts " --- COPY JS FINAL FILES ---"
puts " ---------------------------"

FileUtils.mkdir_p "./" + cdir + "/js"

Dir.glob("./" + cdir + "/src_js/*.js") {|file|
	puts "Moving .js File #{file}"
	FileUtils.mv(file, "./" + cdir + "/js")
}

Dir.glob("./" + cdir + "/src_js/*.html") {|file|
	puts "Moving .html File #{file}"
	FileUtils.mv(file, "./" + cdir + "/js")
}

puts "\n"
puts " -----------------------------"
puts " --- COPY WASM FINAL FILES ---"
puts " -----------------------------"

FileUtils.mkdir_p "./" + cdir + "/wasm"

Dir.glob("./" + cdir + "/src_wasm/*.wasm") {|file|
	puts "Moving .wasm File #{file}"
	FileUtils.mv(file, "./" + cdir + "/wasm")
}

Dir.glob("./" + cdir + "/src_wasm/*.js") {|file|
	puts "Moving .js File #{file}"
	FileUtils.mv(file, "./" + cdir + "/wasm")
}

Dir.glob("./" + cdir + "/src_wasm/*.html") {|file|
	puts "Moving .html File #{file}"
	FileUtils.mv(file, "./" + cdir + "/wasm")
}

puts "\n"
puts " -----------------"
puts " --- ALL DONE! ---"
puts " -----------------"