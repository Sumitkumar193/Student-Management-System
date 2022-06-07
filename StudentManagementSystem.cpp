#include<iostream>

#include<fstream>

#include<vector>

using namespace std;

class Student {
  private:
    char Name[20], Surname[20], Roll_No[10], Grade {};
  int Quiz1_Marks {}, Assignment1_Marks {}, Exam_Marks {};
  public:
    Student() { //Constructor
      cout << "Constructor called!" << endl;
    };
  void setName() {
    cout << "Enter Name: ";
    cin >> Name;
  };
  void setSurname() {
    cout << "Enter Surname: ";
    cin >> Surname;
  };
  void setRollNumber() {
    cout << "Enter Roll Number: ";
    cin >> Roll_No;
  };
  void setQuiz1Marks() {
    cout << "Enter Quiz1 Marks: ";
    cin >> Quiz1_Marks;
  };
  void setAssignment1Marks() {
    cout << "Enter Assignment1 Marks: ";
    cin >> Assignment1_Marks;
  };
  void setExamMarks() {
    cout << "Enter Exam Marks: ";
    cin >> Exam_Marks;
  };
  void setGrade() {
    int total {};
    total = Assignment1_Marks + Quiz1_Marks + Exam_Marks;
    if (total <= 39) {
      Grade = 'F';
    } else if (total > 39 && total <= 44) {
      Grade = 'D';
    } else if (total > 44 && total <= 54) {
      Grade = 'C';
    } else if (total > 54 && total <= 69) {
      Grade = 'B';
    } else if (total > 69) {
      Grade = 'A';
    }
  };
  void showAll() {
    cout << Name << "\t" << Surname << "\t" << Roll_No << "\t" << Exam_Marks << "\t" << Assignment1_Marks << "\t" << Quiz1_Marks << "\t" << Grade << endl;
  };
  void getName() {
    cout << "Name: " << Name << endl;
  };
  void getSurname() {
    cout << "Surname: " << Surname << endl;
  };
  void getRollNumber() {
    cout << "Roll Number: " << Roll_No << endl;
  };
  void getQuiz1Marks() {
    cout << "Quiz1 Marks: " << Quiz1_Marks << endl;
  };
  void getAssignment1Marks() {
    cout << "Assignment1 Marks: " << Assignment1_Marks << endl;
  };
  void getExamMarks() {
    cout << "Exam Marks: " << Exam_Marks << endl;
  };
  void getGrade() {
    cout << "Grade : " << Grade << endl;
  };
  bool pass() {
    int total {};
    total = Assignment1_Marks + Quiz1_Marks + Exam_Marks;
    if (total <= 39)
      return false;
    else
      return true;
  };

  string saveName() {
    return Name;
  };
  string saveSurname() {
    return Surname;
  };
  string saveRollNumber() {
    return Roll_No;
  };
  int saveQuiz1Marks() {
    return Quiz1_Marks;
  };
  int saveAssignment1Marks() {
    return Assignment1_Marks;
  };
  int saveExamMarks() {
    return Exam_Marks;
  };
  int saveGrade() {
    return Grade;
  };

  ~Student() { //Destructor
    cout << "Destructor Called!" << endl;
  };
};

int main() {
  int number_Student {};
  cout << "Enter Number of students: ";
  cin >> number_Student;
  Student s[number_Student]; //Initialize Array of Object with number_Student
  cout << "Table  (Array of Objects) for " << number_Student << " is created!" << endl;
  for (int i {}; i < number_Student; i++) {
    cout << "Enter Details for student# " << i << " : " << endl;
    s[i].setName();
    s[i].setSurname();
    s[i].setRollNumber();
    s[i].setQuiz1Marks();
    s[i].setAssignment1Marks();
    s[i].setExamMarks();
    s[i].setGrade();
  }
  //Show all saved Data
  for (int i {}; i < number_Student; i++) {
    //s[i].showAll();   //use this Output all the data!
  }

  for (int i {}; i < number_Student; i++) {
    cout << "Showing Details for Student ID# " << i << " : " << endl;
    s[i].getName();
    s[i].getSurname();
    s[i].getRollNumber();
    s[i].getQuiz1Marks();
    s[i].getAssignment1Marks();
    s[i].getExamMarks();
    s[i].getGrade();
    cout << "isPass?: " << boolalpha << s[i].pass() << endl;
  }

  ofstream myfile;
  myfile.open("data.csv");
  myfile << "Student No,Name,Surname,Roll Number,Quiz1 Marks,Assignment1 Marks,Exams Marks,Grade,isPass?,\n";
  for (int i {}; i < number_Student; i++) {
    myfile << i + 1 << "," << s[i].saveName() << "," << s[i].saveSurname() << "," << s[i].saveRollNumber() << "," << s[i].saveQuiz1Marks() << "," << s[i].saveAssignment1Marks() << "," << s[i].saveExamMarks() << "," << s[i].saveGrade() << "," << boolalpha << s[i].pass() << "\n";
  }
  myfile.close();

  return 0;
}
