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
