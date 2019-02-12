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
puts " -----------------"
puts " --- ALL DONE! ---"
puts " -----------------"