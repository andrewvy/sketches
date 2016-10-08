from sys import argv

script, user_name = argv
prompt = '> '

print "Hi %s, I am the %s script!" % (user_name, script)
print "Some questions!"

print "What's your nickname?"
nickname = raw_input(prompt)

print "What do you like?"
likes = raw_input(prompt)

print "So, you are %s, and you like %s!" % (nickname, likes)
