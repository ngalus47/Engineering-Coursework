from sys import argv

scipt, filename = argv

print '''
We're going to erase %r.
If you don't want that, hit CTRL-C (^c).
If you do want that, hit RETURN.
''' % filename

raw_input("?")

print "Opening file..."
target = open(filename, 'w')

print "Trincating the file.  Goodbye!"
target.truncate()

print "Now I'm going to ask you for three lines."

line1 = raw_input("line 1: ")
line2 = raw_input("line 2: ")
line3 = raw_input("line 3: ")

print "I'm going to write these to the file."

target.write('{}\n{}\n{}\n'.format(line1, line2, line3))

print "And finally, we close it."
target.close()