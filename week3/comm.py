#!/usr/bin/python
import random, sys
from optparse import OptionParser
class comm:
    def __init__(self, filename1, filename2, parser, options):
        self.flag1 = bool (options.flag1)
        self.flag2 = bool(options.flag2)
        self.flag3 = bool(options.flag3)
        self.unSort = bool(options.unSort)
        self.parser = parser
        self.a = []
        if filename1 == "-":
            self.lines1 = sys.stdin.readlines()
        else:
            f = open(filename1, 'r')
            self.lines1 = f.readlines()
            f.close()

        if filename2 == "-":
            self.lines2 = sys.stdin.readlines()
        else:
            f = open(filename2, 'r')
            self.lines2 = f.readlines()
            f.close()

    def u_comm(self):
        # this is for unsorted0

        try:
            for i in self.lines1:

                for j in self.lines2:
                    if i == j:  # if both of the lines are the same
                        self.a.append([i,2])
                        self.lines2.remove(i)
                        same = True
                        break
                    else:
                        same= False
                if same==False:
                    self.a.append([i,0])
            for i in self.lines2:
                self.a.append([i,1])
        except:
            self.parser.error("cannot comm two unsorted")

    def s_comm (self):
        try:
            i = 0
            j = 0
            while i < len(self.lines1) and j < len(self.lines2):
                if self.lines1[i] < self.lines2[j]:
                    self.a.append([self.lines1[i],0])
                    i = i + 1
                elif self.lines1[i] > self.lines2[j]:
                    self.a.append([self.lines2[j], 1])
                    j = j + 1
                else:
                    self.a.append([self.lines1[i],2])
                    i = i + 1
                    j = j + 1
            while i < len(self.lines1):
                self.a.append([self.lines1[i],0]) # append to first column
                i = i + 1
            while j < len(self.lines2):
                self.a.append([self.lines2[j],1])
                j = j + 1

        except:
            self.parser.error("cannot comm two sorted")

    def printFile(self):
        a="\t"
        b="\t"

        flagArray=[self.flag1,self.flag2,self.flag3]
        if flagArray[0] == True: # column 1 is supressed
            a=""
        if flagArray[1] == True: # column 2 is supressed
            b=""
        t2 = a
        t3 = a+b
        for comp in self.a:
            if(flagArray[comp[1]] ==False):
                if(comp[1] == 0):
                    sys.stdout.write(comp[0])
                if (comp[1] == 1):
                    sys.stdout.write(t2+comp[0])
                if(comp[1]==2):
                    sys.stdout.write(t3+comp[0])


def check_number_of_argument(args,parser):
        if len(args)==0:
            parser.error("there is no operand")
        if len(args) == 1:
            parser.error("missing one operand")
        if len(args) >2:
            parser.error("Too many operands")

def main():
        version_msg = "%prog 2.0"
        usage_msg = """"%prog [OPTION]...FILE1 FILE2
        Output was a comparsion between FILE1 and FILE2."""
        parser = OptionParser()
        parser.add_option("-1",action="store_true",dest="flag1",default=0
                          ,help="suppress first column")
        parser.add_option("-2", action="store_true", dest="flag2", default=0
                          , help="suppress second column")
        parser.add_option("-3", action="store_true", dest="flag3", default=0
                          , help="suppress third column")
        parser.add_option("-u", action="store_true", dest="unSort", default=0
                         , help="input files are not sorted")
        options, args = parser.parse_args()
        check_number_of_argument(args,parser)
        comp= comm(args[0],args[1], parser, options)

        unSort = bool (options.unSort)
        if (unSort == True):
            comp.u_comm()
        elif (unSort== False):
            comp.s_comm()
        comp.printFile()
if __name__ == "__main__":
    main()
