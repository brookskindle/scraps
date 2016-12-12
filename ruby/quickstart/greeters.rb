#!/usr/bin/env ruby

# Created with ruby 2.3.1

# A greeter that greets everybody by name. Can handle multiple names.
class DoorGreeter
    attr_accessor :names

    # create the object
    def initialize(names = "World")
        @names = names
    end

    def say_hi
        if @names.nil?
            puts "I guess nobody's here..."
        elsif @names.respond_to?("each")
            # More than one person, let's greet all of them!
            @names.each do |name|
                puts "Hello, #{name.capitalize}!"
            end
        else
            puts "You're the only one here, hello #{@names.capitalize}!"
        end
    end

    def say_bye
        if @names.nil?
            puts "I guess nobody's leaving..."
        elsif @names.respond_to?("join")
            # More than one person, let's greet all of them!
            puts "Goodbye to everyone! #{@names.join(",")}!"
        else
            puts "You're the only one leaving, good bye #{@names.capitalize}!"
        end
    end
end


if __FILE__ == $0
    # Initialize door greeter by default
    g = DoorGreeter.new
    g.say_hi
    g.say_bye
    puts

    # Change the door greeter names
    g.names = "tommy"
    g.say_hi
    g.say_bye
    puts

    # Have it greet multiple people
    g.names = ["joe", "hank", "fluffy"]
    g.say_hi
    g.say_bye
    puts

    # Have it greet nothing
    g.names = nil
    g.say_hi
    g.say_bye
end
