#!/usr/bin/env ruby

require 'fileutils'

cdir = ARGV[0]

puts "-------------------------------------------"
puts " compiling - " + cdir + " - asm.js, wasm, c"
puts "-------------------------------------------"

puts "\n"
puts "compiling ASM files"
system("cd " + cdir + "/src_asm && make")

puts "\n"
puts "compiling C files"
system("cd " + cdir + "/src_c && make")

puts "\n"
puts "compiling WASM files"
system("cd " + cdir + "/src_wasm && make")

puts "\n"
puts "copying compiled ASM files"
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

# Copy the files in /src folders aswell if available
Dir.glob("./" + cdir + "/src_asm/src/*.mem") {|file|
	puts "Moving .mem File #{file}"
	FileUtils.mv(file, "./" + cdir + "/asm")
}

Dir.glob("./" + cdir + "/src_asm/src/*.js") {|file|
	puts "Moving .js File #{file}"
	FileUtils.mv(file, "./" + cdir + "/asm")
}

Dir.glob("./" + cdir + "/src_asm/src/*.html") {|file|
	puts "Moving .html File #{file}"
	FileUtils.mv(file, "./" + cdir + "/asm")
}

puts "\n"
puts "copying compiled ASM files"
puts "Copying of C Binaries will be skipped"

puts "\n"
puts "copying compiled JS files"

FileUtils.mkdir_p "./" + cdir + "/js"

Dir.glob("./" + cdir + "/src_js/*.js") {|file|
	puts "Moving .js File #{file}"
	FileUtils.mv(file, "./" + cdir + "/js")
}

Dir.glob("./" + cdir + "/src_js/*.html") {|file|
	puts "Moving .html File #{file}"
	FileUtils.mv(file, "./" + cdir + "/js")
}

Dir.glob("./" + cdir + "/src_js/src/*.js") {|file|
	puts "Moving .js File #{file}"
	FileUtils.mv(file, "./" + cdir + "/js")
}

Dir.glob("./" + cdir + "/src_js/src/*.html") {|file|
	puts "Moving .html File #{file}"
	FileUtils.mv(file, "./" + cdir + "/js")
}

puts "\n"
puts "copying compiled WASM files"

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

Dir.glob("./" + cdir + "/src_wasm/src/*.wasm") {|file|
	puts "Moving .wasm File #{file}"
	FileUtils.mv(file, "./" + cdir + "/wasm")
}

Dir.glob("./" + cdir + "/src_wasm/src/*.js") {|file|
	puts "Moving .js File #{file}"
	FileUtils.mv(file, "./" + cdir + "/wasm")
}

Dir.glob("./" + cdir + "/src_wasm/src/*.html") {|file|
	puts "Moving .html File #{file}"
	FileUtils.mv(file, "./" + cdir + "/wasm")
}

puts "\n"