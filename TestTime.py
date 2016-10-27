import time
import datetime
done = False
while(done == False):
	Now = datetime.datetime.now().time()
	Minutes =  Now.minute
	Hour = Now.hour
	print Hour
	print Minutes
	if Hour == 12 and Minutes == 28:
		print "The time is now; the day is here"	
		done = True