import urllib2

data = urllib2.urlopen("https://preview.c9users.io/glort/mediapp/FileReadTest.txt").read(20000) # read only 20 000 chars
data = data.split("\n") # then split it into lines

for line in data:
    print line

disk = int(data[0])

hour = int(data[1])

min = int(data[2])

print "disk: " , disk
print "hour: " , hour
print "min: " , min