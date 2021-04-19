# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    prettier.py                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: charles <charles.cabergs@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/25 13:40:44 by charles           #+#    #+#              #
#    Updated: 2020/04/26 15:04:11 by charles          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

import sys
import re
import math

def green(s):
    return "\033[32m{}\033[0m".format(s)

def red(s):
    return "\033[31m{}\033[0m".format(s)

class Logs:
    def __init__(self):
        self.logs = []
        self.line_pattern = re.compile(
            r"^\[(?P<prefix>(FAIL SEGV)|(FAIL ASSERT)|(PASS)) *\] "
            r"\{(?P<testcontainer>.*)\} "
            r"\{(?P<testname>.*)\} "
            r"(?P<filename>[a-z_/]+\.cpp):"
            r"(?P<line>\d+) "
            r"\((?P<code>.*)\)$"
        )
        self.log_file_name = "result.log"
        self.current_testname = ""
        self.current_testcontainer = ""
        self.max_output_log = 10
        self.verbose = True

    def add_line(self, line):
        match = self.line_pattern.match(line)
        if match is None:
            print("\nERROR PARSING:", line)
        else:
            self.logs.append(match.groupdict())
            if self.verbose:
                if self.logs[-1]["testcontainer"] != self.current_testcontainer:
                    self.current_testcontainer = self.logs[-1]["testcontainer"]
                    if len(self.logs) != 1:
                        print("\n")
                    print("==={}===".format(self.current_testcontainer), end="")
                if self.logs[-1]["testname"] != self.current_testname:
                    self.current_testname = self.logs[-1]["testname"]
                    print("\n{}: ".format(self.current_testname), end="")
                self._put_indicator(self.logs[-1]["prefix"])
            else:
                print("\033[Am{}\r".format(len(self.logs)))

    def run(self):
        for line in sys.stdin:
            self.add_line(line)
        failed = [x for x in self.logs if x["prefix"] == "FAIL SEGV" or x["prefix"] == "FAIL ASSERT"]
        self.put_summary(failed)
        self.write_log_file(failed)

    def put_summary(self, failed):
        pass_num = len([x for x in self.logs if x["prefix"] == "PASS"])
        total = pass_num + len(failed)
        if total == 0:
            total = 1
        pass_str = green("[PASS] {} {:.2f}%".format(pass_num, 100.0 * float(pass_num) / total))
        fail_str = red("[FAIL] {} {:.2f}%".format(len(failed), 100.0 * float(len(failed)) / total))
        print("\nTotal {}    {}    {}".format(pass_num + len(failed), pass_str, fail_str))
        if len(failed) != 0:
            print()
        for f in failed[:self.max_output_log]:
            print(self.fail_formated(f, color=True))
        if len(failed) > self.max_output_log:
            print("\nSee {} for more information".format(self.log_file_name))

    def write_log_file(self, failed):
        try:
            with open(self.log_file_name, 'w') as file:
                failed_log_str = "\n\n".join([self.fail_formated(f, color=False) for f in failed])
                file.write(failed_log_str)
        except IOError as e:
            print("Error when writing to {}: {}".format(self.log_file_name, e.strerror))

    def fail_formated(self, fail, color=False):
        prefix = "[" + fail["prefix"] + "]"
        if color:
            prefix = red(prefix)
        return "{} {}:{}\n    {}".format(prefix, fail["filename"], fail["line"], fail["code"])

    def _put_indicator(self, prefix):
        if prefix == "PASS":
            sys.stdout.write(green('.'))
        else:
            sys.stdout.write(red('!'))
        sys.stdout.flush()


def main():
    logs = Logs()
    logs.run()


if __name__ == "__main__":
    main()
