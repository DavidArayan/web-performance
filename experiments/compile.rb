#!/usr/bin/env ruby

require 'fileutils'

# remove our previous compiled targets
FileUtils.rm_rf('./compiled')

# grab all our directories - we need to compile all of them
directories = Dir.entries(".").select {|f| File.directory? f}

directories.delete(".")
directories.delete("..")

# print all our directories for the user
puts "the following directories will be compiled"
for i in 0..directories.length-1 do
	cdir = directories[i]

	if cdir.start_with?('_') == true
		next
	end

	puts cdir
end

puts "compiling target directories"
for i in 0..directories.length-1 do
	cdir = directories[i]

	# Skip directories with an underscore
	if cdir.start_with?('_') == true
		puts "skipping the directory " + cdir
		next
	end

	puts "compiling code in " + cdir

	FileUtils.mkdir_p "./compiled/" + cdir

	system("ruby dir_clean.rb " + cdir)
	system("ruby dir_copy.rb " + cdir)
	system("ruby dir_compile.rb " + cdir)

	# copy all our compiled targets into a single folder
	FileUtils.copy_entry ("./" + cdir + "/asm"), ("./compiled/" + cdir + "/asm")
	FileUtils.copy_entry ("./" + cdir + "/wasm"), ("./compiled/" + cdir + "/wasm")
	FileUtils.copy_entry ("./" + cdir + "/c"), ("./compiled/" + cdir + "/c")
	FileUtils.copy_entry ("./" + cdir + "/js"), ("./compiled/" + cdir + "/js")

	puts "copying template files in " + cdir

	# copy our templates into their respective folders
	if File.file?("./compiled/" + cdir + "/asm/index.html") == false
		FileUtils.cp("./_templates/index_asm.html", "./compiled/" + cdir + "/asm/index.html");
	end

	if File.file?("./compiled/" + cdir + "/wasm/index.html") == false
		FileUtils.cp("./_templates/index_wasm.html", "./compiled/" + cdir + "/wasm/index.html");
	end

	if File.file?("./compiled/" + cdir + "/js/index.html") == false
		FileUtils.cp("./_templates/index_js.html", "./compiled/" + cdir + "/js/index.html");
	end

	# perform final cleanup
	system("ruby dir_clean.rb " + cdir)
end

puts "\n"
puts "all finished! compiled files can now be copied out and service closed"