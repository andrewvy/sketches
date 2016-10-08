# file.close()
# file.read()
# file.readline()
# file.truncate()

from sys import argv

script, filename = argv

print "We are going to erase %r." % filename
print "Is that okay? Hit CTRL-C to cancel. Enter to continue."
raw_input("?")

print "Opening file..."
target = open(filename, 'w') # By default, open() is read-only.

print "Truncating the file. Goodbye!"
target.truncate()

print "Now, asking you for three lines."
line1 = raw_input("line 1: ")
line2 = raw_input("line 2: ")
line3 = raw_input("line 3: ")

target.write(line1)
target.write("\n")
target.write(line2)
target.write("\n")
target.write(line3)
target.write("\n")

print "And now we close the file."
target.close()
