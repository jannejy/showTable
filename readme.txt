The program shows in table view data read from a file.
It contains:
- 'main.qml' (interface of the application)
- class PersonData in c++ (the structure describing a person data)
- class PersonDataModel (contains list of PersonData, it is in charge of displaying data in interface)

Interface contains:
- table view with headings
- button to open a file dialog
- file dialog to choose a file

You can not edit the table.

The program can read a file in a following format:
user_id_1; user_name_1; phone_number_1;
user_id_2; user_name_2; phone_number_2;
...
user_id_n; user_name_n; phone_number_n;