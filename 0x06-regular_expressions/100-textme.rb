#!/usr/bin/env ruby
format = ARGV[0].scan(/from:(.\w+)|to:(.\w+)|flags:([0-9:-]+)/)
list = format.compact
puts list.join(',')
