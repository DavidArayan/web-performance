#!/usr/bin/env ruby

require 'fileutils'

FileUtils.rm_rf('./src_asm/src')
FileUtils.rm_rf('./src_c/src')
FileUtils.rm_rf('./src_wasm/src')