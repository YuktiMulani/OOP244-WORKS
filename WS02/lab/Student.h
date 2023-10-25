
#ifndef SDDS_STUDENT_H_
#define SDDS_STUDENT_H_

#define DATAFILE "simpsons.csv"


namespace sdds {
    struct Student {
        char* m_name;
        int m_studentNumber;
        char m_grade;
    };
    void sort();
    bool load(Student& stu);
    bool load(const char* stufile);
    void display(const Student& student);
    void display();
    void deallocateMemory();
}
#endif // SDDS_STUDENT_H_