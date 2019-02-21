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
	puts directories[i]
end

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
	FileUtils.copy_entry ("./" + cdir + "/js"), ("./compiled/" + cdir + "/js")

	# copy our templates into their respective folders
	FileUtils.cp("./_templates/index_asm.html", "./compiled/" + cdir + "/asm/index.html");
	FileUtils.cp("./_templates/index_wasm.html", "./compiled/" + cdir + "/wasm/index.html");
	FileUtils.cp("./_templates/index_js.html", "./compiled/" + cdir + "/js/index.html");

	# perform final cleanup
	system("ruby dir_clean.rb " + cdir)
end