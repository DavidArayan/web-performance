#!/usr/bin/env ruby

require 'fileutils'

# remove our previous compiled targets
FileUtils.rm_rf('./compiled')

# grab all our directories - we need to compile all of them
directories = Dir.entries(".").select {|f| File.directory? f}

for i in 2..directories.length-1 do
	cdir = directories[i]

	puts "compiling code in " + cdir

	FileUtils.mkdir_p "./compiled/" + cdir

	system("ruby dir_clean.rb " + cdir)
	system("ruby dir_copy.rb " + cdir)
	system("ruby dir_compile.rb " + cdir)

	# copy all our compiled targets into a single folder
	FileUtils.copy_entry ("./" + cdir + "/asm"), ("./compiled/" + cdir + "/asm")
	FileUtils.copy_entry ("./" + cdir + "/wasm"), ("./compiled/" + cdir + "/wasm")
	FileUtils.copy_entry ("./" + cdir + "/js"), ("./compiled/" + cdir + "/js")

	# perform final cleanup
	system("ruby dir_clean.rb " + cdir)
end