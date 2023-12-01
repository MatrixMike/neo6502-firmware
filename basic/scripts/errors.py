# *******************************************************************************************
# *******************************************************************************************
#
#		Name : 		errors.py
#		Purpose :	Error messages/macros generator
#		Date :		29th November 2023
#		Author : 	Paul Robson (paul@robsons.org.uk)
#
# *******************************************************************************************
# *******************************************************************************************

import sys

errors = """
	syntax : 	syntax error
	type : 		type mismatch error
	divzero : 	division by zero error
	range : 	out of range error
"""

err = []
id = 1
for e in [x.strip() for x in errors.replace("\t"," ").split("\n") if x.strip() != ""]:
	e = e.split(":")
	err.append([id,e[0].strip().lower(),e[1].strip()])
	id += 1

h = open("sources/generated/errors.inc","w")
h.write(";\n;\tThis file is automatically generated.\n;\n")
for e in err:
	h.write("error_{0} .macro\n".format(e[1]))
	h.write("\tlda\t#{0}\n".format(e[0]))
	h.write("\tjmp\tErrorHandler\n")
	h.write("\t.endm\n\n")
h.close()

h = open("sources/generated/errors.asm","w")
h.write("\t.section code\n")
h.write(";\n;\tThis file is automatically generated.\n;\n")
h.write("ErrorMessageText:\n")
for e in err:
	h.write("\t.text\t\"{0}\",0\n".format(e[2]))
h.write("\t.send code\n")
h.close()
