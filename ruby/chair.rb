#!/usr/bin/env ruby

class Chair
    attr_reader :color, :price
    attr_writer :price
    def initialize(color, price)
        @color = color
        @price = price
    end
end

puts 'hello there!'


class Student
    @@id = 0

    attr_reader :id

    def inititialize
        @@id += 1
    end
end
