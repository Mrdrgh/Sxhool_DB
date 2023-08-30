# The School Data Base
a small implementation of a school database containing teachers, students and the principal
that is based on singly linked lists, file_io, variadic functions and many other basic concepts, 
you can feed the database of the program by doing : ``` echo $file_name | ./program_name```
the file name is the teachers dat file that contains the principal.
By default, the principal login (cni) is FC65138 and password is "password", you can change them
by changing the source code , in the file : struct_functions.c > init_struct_teachers.

## functionnalities
- this is a sub_gui interface to allow the user to easly interact with the program, it consists of
  a list of choices enumerated from 1, the user enters the number of the desired functionnality and presses enter
- the principal can add teachers and students and has multiple messaging previliges such as the 'Scream_to_school' functionnality
  that allows him to send a message to the whole school (teachers and students) inbox, as well as other functionnalities to discover
- the teacher can also add and delete a student, but he is limited in regards of managing the teachers database, he cannot add teachers
  nor access thier database, he can send messages to students and can send messages to the principal's inbox
- the teachers and the pricipal can create books, and publish them into the book database, which the students can read, they can also delete
  them
- inboxes in this program were by default a string of strings representing the sender and the message, but i changed them to files at the
  end due to the undefined behaviour this functionnality triggered
- students are the bottom of the pyramid, they can only output thier informations or read the database books