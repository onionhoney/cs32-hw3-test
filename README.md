# CS32 Homework 2 Test
A test for homework 2 for CS 32 in UCLA.



### Quick Start for Mac

1. Click [here](https://github.com/onionhoney/cs32-hw2-test/archive/master.zip) to download the zip file, and unzip it.
2. Copy the unzipped folder (not the files) to the directory where all your source
files are located.
3. Open the folder and right click on **LaunchTest.app**, select "Open" and confirm.
4. Now your tests are ready to be served! A Terminal window will be opened that shows your test result.

See 'Running the test' section for an alternative way to start, if you're using
Linux or if something goes wrong with LaunchTest.app.

---

### DISCLAIMER

This test implements most of the requirements as specified in
the project specification, along with additional components
to test your project more thoroughly.
However, passing this test does not guarantee that your code
is entirely correct or will pass Smallberg's tests. It
serves merely as a reassurance that your code is correct.
It might also produce output helpful for debugging your code.

The code itself is written by mortals, and therefore it might
contain bugs. If you are pretty sure your code is correct,
but does not pass the test, please create an issue, or send
an email to the author with a simple explanation as to why
the test is not working.

Because the test might automatically clean up itself after
finishing the test, it might accidentally clean up things that
it shouldn't, if you have not followed the requirements in
the project specification or the instructions for running this
test. Therefore, it is **STRONGLY ADVISED** to make a backup
of your code before running the test.

Run the test at your own discretion. The author does not
take any responsibility in case of any accident.

---

### Running the test 

All code are expected to run in command line under
a \*nix system.

First, navigate to the directory where all your source files
are located

`cd path/to/source/`

Second, clone this repository

`git clone https://github.com/onionhoney/cs32-hw2-test.git`

Or if you want to try out the development branch:

`git clone https://github.com/colinxy/cs32-hw2-test.git`

Then, cd into this directory

`cd cs32-hw2-test`

and to execute it, first make it executable

`chmod +x run_test.sh`

and run it with

`./run_test.sh`

If the test output ends with the following line,

```
****** ALL TESTS PASSED ******
```

your code passes the test. Be sure to read
the error message carefully as it contains
useful information for debugging your code.
