from random import shuffle
import os
import subprocess
import sys
import itertools

n = 0
t = 0
c = 0
m = -10000
mi = 10000000
# while c < 100:
z = range(6)
a = itertools.permutations(z)
for l in a:
	c += 1
	s = " ".join([str(x) for x in l])
	# print s
	output = subprocess.check_output("./push_swap " + s, shell=True)
	lines = len(output.split("\n"))
	t += lines
	if lines > m:
		m = lines
	if lines < mi:
		mi = lines
	output = subprocess.check_output("echo \"%s\"" % (output) + " | ./checker " + s, shell=True)
	if output != "OK\n":
		print '\nit failed for %s\n' % s
	if lines > 100:
		print "\n%s\n" % s
	# if lines == 14:
	# 	print '\ntoo long for %s\n' % s
	# print str(n) +": avg: " + str(t / c) + " prev: " + str(lines) + " max: " + str(m) + " min: " + str(mi)
	n += 1
	sys.stdout.write("\ravg: " + str(t / c) + " prev: " + str(lines) + " max: " + str(m) + " min: " + str(mi))


# l = range(100)
# shuffle(l)
# print " ".join([str(x) for x in l])
# output = subprocess.check_output("./push_swap " + " ".join([str(x) for x in l]), shell=True)
# print output
# prev = ""
# pbc = 0
# for line in output.split("\n"):
# 	if line == 'pb':
# 		pbc += 1
# 	elif not line == 'pa':
# 		pbc = 0
# 	if line == 'pa' and pbc:
# 		print "bad"
# 		pbc -= 1
# 	prev = line
	# print line
