#!/usr/bin/env ruby
# If imported, can directly access the classes by just calling them

class Parent
    def initialize
        puts "I'm initializing the parent"
    end

    def speak
        puts "Don't touch that"
    end
end

class Child < Parent
    def initialize
        puts "Initialzing the child before calling super()"
        super()
        puts "Initialzing the child after calling super()"
    end

    def speak
        puts "But daaaaaad!!!!"
    end
end

class Dog
    attr_reader :name, :breed
    attr_writer :name  # You can't change the breed of a dog!
    def initialize(name, breed)
        @name = name
        @breed = breed
    end

    def speak
        puts "Woof woof!"  # Good pupper
    end
end

class Bird
    def fly
        puts "I'm flying, I'm flying!"
    end
end

class Penguin < Bird
    def fly
        puts "I can't fly T_T"
    end
end

d = Dog.new("Theodore", "Siberian Husky")
b = Bird.new
p = Penguin.new
parent = Parent.new
child = Child.new
