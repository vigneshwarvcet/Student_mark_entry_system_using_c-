#include <iostream>
#include <vector>
#include <string>
using namespace std;

class User {
    string name, password;
    string registrationNo;

public:
    User(string name, string password, string registrationNo) {
        this->name = name;
        this->password = password;
        this->registrationNo = registrationNo;
    }
    string getName() {
        return name;
    }
    string getId() {
        return registrationNo;
    }
    string getPassword() {
        return password;
    }
};

class Admin {
    string name, password;
    int id;

public:
    Admin(string name, string password, int id) {
        this->name = name;
        this->password = password;
        this->id = id;
    }

    string getAdminName() {
        return name;
    }

    string getAdminPassword() {
        return password;
    }

    int getAdminId() {
        return id;
    }
};

class Marks {
    string registrationNo;
    vector<int> marks;

public:
    Marks(string registrationNo, vector<int> marks) {
        this->registrationNo = registrationNo;
        this->marks = marks;
    }

    string getRegNo() {
        return registrationNo;
    }

    vector<int> getMarks() {
        return marks;
    }
};

class Student {
    string username, password;
    vector<User> users;
    vector<Admin> admins;
    vector<Marks> marksList;

public:
    void getdata();
    void Studentlogin();
    void newstudent();
    void oldstudent();
    void adminLogin();
    void newadmin();
    void oldadmin();
    int validateuser(string registrationNo, string password);
    int validateadmin(int registrationNo, string password);
    void viewmarks(string stregistrationNo);
    void addmarks();
};

void Student::getdata() {
    int choices;

    cout << "\t\t_____________Welcome to VCET LOGIN______________________" << endl;
    cout << "\t\t_____________Enter Your Choices_________________________" << endl;
    cout << "\t\t________________________________________________________" << endl;
    cout << "\t\t______________1. Student________________________________" << endl;
    cout << "\t\t______________2. Admin__________________________________" << endl;
    cin >> choices;

    switch (choices) {
    case 1:
        Studentlogin();
        break;
    case 2:
        adminLogin();
        break;
    default:
        cout << "___________________OOPS you entered an invalid input---retry---------________________" << endl;
        getdata();
    }
}

void Student::Studentlogin() {
    while (true) {
        // system("cls"); // Commenting out for portability
        int choice;

        cout << "\t\t__________________Welcome to VCET LOGIN_______________________" << endl;
        cout << "\t\t__________________Enter Your Choices__________________________" << endl;
        cout << "\t\t_" << endl;
        cout << "\t\t_1. New student" << endl;
        cout << "\t\t_2. Registered student_" << endl;
        cout << "\t\t_3. Exit_" << endl;

        cin >> choice;

        switch (choice) {
        case 1:
            newstudent();
            break;
        case 2:
            oldstudent();
            break;
        case 3:
             getdata();
             return;
        default:
            cout << "_____________________OOPS you entered an invalid input---retry---------______________________" << endl;
            Studentlogin();
        }
    }
}

void Student::newstudent() {
    string registrationNo;
    string password, name;
    cout << "\t\t__________________Enter Your Data________________" << endl;
    cout << "\t\t_________________________________________________" << endl;
    cout << "Enter Your name: ";
    cin >> name;
    cout << "Enter your Registration number: ";
    cin >> registrationNo;
    cout << "Enter your password (!!!---password should not contain spaces----!!!): ";
    cin >> password;
    cout << "Successfully created !!!" << endl;

    User newUser(name, password, registrationNo);
    users.push_back(newUser);
}

void Student::oldstudent() {
    string registrationNo;
    string password;
    cout << "\t\t____________Enter Your Data_______________" << endl;
    cout << "\t\t__________________________________________" << endl;
    cout << "Enter your Registration number: ";
    cin >> registrationNo;
    cout << "Enter your password: ";
    cin >> password;
    int x = validateuser(registrationNo, password);
    if (x >= 0) {
        cout << "Successfully logged in !!!" << endl;
        viewmarks(registrationNo);
    } else {
        cout << "Invalid login credentials!" << endl;
    }
}

int Student::validateuser(string registrationNo, string password) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getId() == registrationNo) {
            if (users[i].getPassword() == password) {
                return i;
            }
        }
    }
    return -1;
}

void Student::adminLogin() {
    while (true) {
        // system("cls"); // Commenting out for portability
        int choice;

        cout << "\t\t____________Welcome to VCET LOGIN____________" << endl;
        cout << "\t\t____________Enter Your Choices_______________" << endl;
        cout << "\t\t_" << endl;
        cout << "\t\t_1. New Admin" << endl;
        cout << "\t\t_2. Registered Admin_" << endl;
        cout << "\t\t_3. Exit_" << endl;

        cin >> choice;

        switch (choice) {
        case 1:
            newadmin();
            break;
        case 2:
            oldadmin();
            break;
        case 3:
            getdata();
            return;
        default:
            cout << "________OOPS you entered an invalid input---retry---------___________" << endl;
            adminLogin();
        }
    }
}

void Student::newadmin() {
    int registrationNo;
    string password, name;
    cout << "\t\t_Enter Your Data_" << endl;
    cout << "\t\t_" << endl;
    cout << "Enter Your name: ";
    cin >> name;
    cout << "Enter your Registration number: ";
    cin >> registrationNo;
    cout << "Enter your password (!!!---password should not contain spaces----!!!): ";
    cin >> password;
    cout << "Successfully created !!!" << endl;

    Admin newAdmin(name, password, registrationNo);
    admins.push_back(newAdmin);
}

void Student::oldadmin() {
    int registrationNo;
    string password;
    cout << "\t\t_Enter Your Data_" << endl;
    cout << "\t\t_" << endl;
    cout << "Enter your Registration number: ";
    cin >> registrationNo;
    cout << "Enter your password: ";
    cin >> password;
    int x = validateadmin(registrationNo, password);
    if (x >= 0) {
        cout << "Successfully logged in !!!" << endl;
        addmarks();
    } else {
        cout << "Invalid login credentials!" << endl;
    }
}

int Student::validateadmin(int registrationNo, string password) {
    for (int i = 0; i < admins.size(); i++) {
        if (admins[i].getAdminId() == registrationNo) {
            if (admins[i].getAdminPassword() == password) {
                return i;
            }
        }
    }
    return -1;
}

void Student::addmarks() {
    // system("cls"); // Commenting out for portability
    vector<int> m;
    string registrationNo;
    cout << "Enter the student's registration number: ";
    cin >> registrationNo;
    for (int i = 0; i < 5; i++) {
        int mark;
        cout << "Enter subject " << i + 1 << " marks here: ";
        cin >> mark;
        m.push_back(mark);
    }
    Marks newMarks(registrationNo, m);
    marksList.push_back(newMarks);
    cout << "Marks added successfully!" << endl;
}

void Student::viewmarks(string regno) {
    // system("cls"); // Commenting out for portability
    for (int i = 0; i < marksList.size(); i++) {
        if (marksList[i].getRegNo() == regno) {
            vector<int> m = marksList[i].getMarks();
            cout << "Marks for registration number " << regno << ":\n";
            for (int j = 0; j < m.size(); j++) {
                cout << "Subject " << j + 1 << ": " << m[j] << endl;
            }
            return;
        }
        else{
            cout<<"_____---D-A-T-A-N-O-T-F-O-U-N-D---___________";
        }
    }
    cout << "No marks found for the given registration number." << endl;
}

int main() {
    Student obj;
    obj.getdata();
    return 0;
}