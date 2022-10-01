#T his program converts string to lowercase or uppercase acc. to user's choice
# Input the string
puts "Enter the string:"
str = gets.chomp


# Ask for the option 
puts "\nChoose the option: \nA) Lowercase \nB) Uppercase"
choice = gets.chomp

def colorize(str)
	"\e[34m#{str}\e[0m"
end

# condition to execute code based on the user's choice
if choice.downcase == "a"
	puts "\nThe lowercase is: #{colorize(str.downcase)}"
elsif choice.downcase == "b"
	puts "\nThe uppercase is: #{colorize(str.upcase)}"
else
	puts "\nInvalid option"
end