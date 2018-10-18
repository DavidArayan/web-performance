
#!/usr/bin/env ruby

# Face contains a vertex position, a normal (facing direction) and the index
# required for forming triangles
class Face
	def initialize(posX, posY, posZ, norX, norY, norZ, ind)
		@posX_ = posX
		@posY_ = posY
		@posZ_ = posZ
		@norX_ = norX
		@norY_ = norY
		@norZ_ = norZ
		@index_ = ind
	end

	def position_x()
		return @posX_
	end

	def position_y()
		return @posY_
	end

	def position_z()
		return @posZ_
	end

	def normal_x()
		return @norX_
	end

	def normal_y()
		return @norY_
	end

	def normal_z()
		return @norZ_
	end

	def position_index()
		return @index_
	end
end

class Front
	V1 = Face.new(0.0, 1.0, 0.0, 0.0, 0.0, -1.0, 0)
	V2 = Face.new(1.0, 1.0, 0.0, 0.0, 0.0, -1.0, 1)
	V3 = Face.new(1.0, 0.0, 0.0, 0.0, 0.0, -1.0, 2)
	V4 = Face.new(0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 3)
end

class Back
	V1 = Face.new(0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 4)
	V2 = Face.new(1.0, 0.0, 1.0, 0.0, 0.0, 1.0, 5)
	V3 = Face.new(1.0, 1.0, 1.0, 0.0, 0.0, 1.0, 6)
	V4 = Face.new(0.0, 1.0, 1.0, 0.0, 0.0, 1.0, 7)
end

class Left
	V1 = Face.new(0.0, 1.0, 1.0, -1.0, 0.0, 0.0, 8)
	V2 = Face.new(0.0, 1.0, 0.0, -1.0, 0.0, 0.0, 9)
	V3 = Face.new(0.0, 0.0, 0.0, -1.0, 0.0, 0.0, 10) 
	V4 = Face.new(0.0, 0.0, 1.0, -1.0, 0.0, 0.0, 11) 
end

class Right
	V1 = Face.new(1.0, 1.0, 0.0, 1.0, 0.0, 0.0, 12)
	V2 = Face.new(1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 13)
	V3 = Face.new(1.0, 0.0, 1.0, 1.0, 0.0, 0.0, 14)
	V4 = Face.new(1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 15)
end

class Up
	V1 = Face.new(0.0, 1.0, 1.0, 0.0, 1.0, 0.0, 16)
	V2 = Face.new(1.0, 1.0, 1.0, 0.0, 1.0, 0.0, 17)
	V3 = Face.new(1.0, 1.0, 0.0, 0.0, 1.0, 0.0, 18)
	V4 = Face.new(0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 19)
end

class Down
	V1 = Face.new(0.0, 0.0, 0.0, 0.0, -1.0, 0.0, 20)
	V2 = Face.new(1.0, 0.0, 0.0, 0.0, -1.0, 0.0, 21)
	V3 = Face.new(1.0, 0.0, 1.0, 0.0, -1.0, 0.0, 22)
	V4 = Face.new(0.0, 0.0, 1.0, 0.0, -1.0, 0.0, 23)
end

class LUTGenerator

	def initialize
		File.open('lut_table.h', 'w') { |file|
			# reset to start of file
			file.truncate(0)
			#ifndef UTILS_H_
			#define UTILS_H_

			# generate our comments/header data
			file.write("/**********************************************\n")
			file.write(" * AUTO-GENERATED HEADER FILE - DO NOT MODIFY *\n")
			file.write(" * Refer to lut_generator.rb                  *\n")
			file.write(" **********************************************/\n")
			file.write("#ifndef __LUT_TABLE_GENERATOR_\n")
			file.write("#define __LUT_TABLE_GENERATOR_\n")
			file.write("\n")
			file.write("#include <stdlib.h>\n")
			file.write("\n")
			file.write("#ifdef __EMSCRIPTEN__\n")
			file.write("    #include <emscripten.h>\n")
			file.write("#endif /* __EMSCRIPTEN__ */\n")
			file.write("\n")
			file.write("#ifdef __cplusplus\n")
			file.write("    extern \"C\" {\n")
			file.write("#endif /* __cplusplus */\n")
			file.write("\n")

			# start generating our code
			generate_code(file)

			file.write("\n")
			file.write("#ifdef __cplusplus\n")
			file.write("    }\n")
			file.write("#endif /* __cplusplus */\n")
			file.write("#endif /* __LUT_TABLE_GENERATOR_ */\n")
		}
	end

	def generate_code(file)
		data = Array.new(0)
		total_count = 1

		for i in 0..64 do
			triangles = generate_triangles_for_index(i)
			data << triangles
		end

		data_len = data.count - 1

		# perform our counting
		for i in 0..data_len do
			write_triangles = data[i]

			if write_triangles != nil
				total_count ++
				total_count += write_triangles.count - 1
			end
		end

		file.write("/* LUT-CODE BEGINS HERE */\n")
		file.write("\n")

		file.write("const int triangle_lut[")
		file.write(total_count)
		file.write("] = {\n")

		lut_oflut = Array.new(0)

		lut_pointer = 0

		# write our triangles LUT table
		for i in 0..data_len do
			write_triangles = data[i]

			if write_triangles != nil
				file.write("    /* LUT Index=")
				file.write(i)
				file.write(" */ ")

				file.write("/* Count=")
				file.write(write_triangles.count)
				file.write(" */ \n")
				file.write("    ")
				file.write(write_triangles.count)
				file.write(",")

				lut_oflut << lut_pointer

				j_len = write_triangles.count - 1

				lut_pointer += j_len + 1

				for j in 0..j_len do
					file.write(write_triangles[j])
					file.write(",")
				end

				file.write("\n")
			end
		end

		file.write("    /* ARRAY TERMINATOR */ \n")
		file.write("    ")
		file.write(0)
		file.write("\n")
		file.write("}\n")
		file.write("\n")

		# write our LUT for our LUT
		file.write("const int triangle_lut_indices[65] = {\n")

		lut_oflutcount = lut_oflut.count - 1

		file.write("    ")

		for i in 0..lut_oflutcount do
			file.write(lut_oflut[i])
			file.write(",")
		end

		file.write(0)
		file.write("\n")

		file.write("}\n")

		file.write("\n")
		file.write("/* LUT-CODE ENDS HERE */\n")
	end

	def generate_triangles_for_index(ind)
		_indexLUT = [
			(ind & (1 << 0)),
			(ind & (1 << 1)),
			(ind & (1 << 2)),
			(ind & (1 << 3)),
			(ind & (1 << 4)),
			(ind & (1 << 5))
		]

		_clazzLUT = [
			Right,
			Left,
			Up,
			Down,
			Back,
			Front
		]

		count = _indexLUT.length

		_triangles = Array.new(0)

		for i in 0..count do
			if _indexLUT[i] == 0
				clazz = _clazzLUT[i]

				_triangles << clazz::V1.position_index()
				_triangles << clazz::V2.position_index()
				_triangles << clazz::V3.position_index()

				_triangles << clazz::V1.position_index()
				_triangles << clazz::V3.position_index()
				_triangles << clazz::V4.position_index()
			end
		end

		return _triangles
	end
end

# initialize the object
LUTGenerator.new