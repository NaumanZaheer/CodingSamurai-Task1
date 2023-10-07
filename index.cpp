#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;

class Database{


    string name;
    int rollno;
    double percentage;
    string grade;
    ifstream fin;
    int count;


    public:
    Database(): count(1)
    {
        ifstream inputFile("student_grades.txt");
        if (inputFile.is_open()) {
            
            while(!inputFile.eof())
            {
                getline(inputFile , name);
                inputFile >> rollno;
                inputFile >> percentage;
                inputFile >> grade;

                if(name != "")
                {
                    cout << "Student # "<<count <<endl;
                    cout << "Name: " << name << endl;
                    cout << "Roll Number: " << rollno << endl;
                    cout << "Percentage: " << percentage << "%" << endl;
                    cout << "Grade: " << grade << endl;
                    cout <<endl;
                }
                
            }
            
            inputFile.close();
        } else {
            cout << "No student data exists!" << endl;
        }
    }


};
class Grading{

    double max_total;
    double obt_total;
    float percentage;
    string grade;

    public:

    Grading()
    {
        obt_total = 0 , max_total = 0 , percentage = 0.0f;
        grade ="";
    }

    float Quiz_grading(double & max , double *obt , int &number_of_quizes)
    {
        
        max_total = max * number_of_quizes;
        for(int i = 0 ; i < number_of_quizes ; i++)
        {
            obt_total += obt[i];
        }
        obt_total*=1.0;
        max_total*=1.0;

        this->percentage = obt_total/max_total;
        this->percentage *= 10.0;
        return percentage;
    }

    float Assign_grading(double & max , double *obt , int &number_of_assign)
    {
    
        percentage = 0.0f;
        obt_total = 0 , max_total = 0;

        max_total = max * number_of_assign;
        for(int i = 0 ; i < number_of_assign ; i++)
        {
            obt_total += obt[i];
        }
        obt_total*=1.0;
        max_total*=1.0;

        this->percentage = obt_total/max_total;
        this->percentage *= 15.0;
        return percentage;
    }

    float mid_grading(double & max , double & obt)
    {
        return (obt/max)*35.0;
    }
    float finals_grading(double & max , double & obt)
    {
        return (obt/max)*40.0;
    }
    string retGrade(double & perc)
    {
        if(perc >= 95.0 && perc <=100.0)
        grade = "A";
        else if(perc>=92.5 && perc <= 94.99)
        grade = "A+";
        else if(perc >= 90.0 && perc <= 92.49)
        grade = "A-";
        else if(perc>=85.0 && perc <= 89.99)
        grade = "B";
        else if(perc >= 82.5 && perc <= 84.99)
        grade = "B+";
        else if(perc>=80.0 && perc <= 82.49)
        grade = "B-";
        else if(perc >= 75.0 && perc <= 79.99)
        grade = "C";
        else if(perc>=70.0 && perc <= 74.99)
        grade = "C+";
        else if(perc >= 65.0 && perc <= 69.99)
        grade = "C-";
        else if(perc>=50.0 && perc <= 64.99)
        grade = "D";
        else if(perc < 50.0)
        grade = "F";

        return grade;
    }



};
class Marking{

    int num_of_quizes; //10% 
    double quiz_max;
    double * quiz_obtained;

    int num_of_assigns; //15%
    double assign_max;
    double * assign_obtained;

    double mid_obtained; //35%
    double mid_max;

    double finals_obtained; //40%
    double finals_max;

    double percentage;
    string grade;

    string name;
    int id;


    public:

    Marking(){}
    Marking(string name , int id): grade("")
    {
        this->name = name , this->id = id;
        percentage = finals_max = finals_obtained = mid_max = mid_obtained = num_of_assigns = assign_max = num_of_quizes = quiz_max = 0;
        Quiz_marking();
        Assign_marking();
        Mid_Marking();
        Final_marking();
        Percentage_calc();
    }
    
    void Quiz_marking()
    {

        while(true)
        {
            cout << "Number of quizes : ";
            cin >> num_of_quizes;
            if(num_of_quizes>0)
            {
                quiz_obtained = new double[num_of_quizes];
                break;
            }
            else
            cout << "Enter valid number of quizes ! "<<endl;
        }

        while(true)
        {
            cout << "Max marks  of quiz : ";
            cin >> quiz_max;
            if(quiz_max > 0)
            break;
            else
            cout << "Enter valid max marks for quizes ! "<<endl;
        }

        int obt;
        for(int i = 0 ; i < num_of_quizes ; i ++)
        {
            while(true)
            {
                cout << "Enter obtained marks for Quiz " << i+1 << " : ";
                cin >> obt;
                if(obt >= 0 && obt <= quiz_max)
                {
                    quiz_obtained[i] = obt;
                    break;
                }
                else
                cout << "Enter valid obtained quiz marks ! "<<endl;
            }

        }
    }
    void Assign_marking()
    {

        while(true)
        {
            cout << "Number of assignments : ";
            cin >> num_of_assigns;
            if(num_of_assigns>0)
            {
                assign_obtained = new double[num_of_assigns];
                break;
            }
            else
            cout << "Enter valid number of assignments ! "<<endl;
        }

        while(true)
        {
            cout << "Max marks  of assignments : ";
            cin >> assign_max;
            if(assign_max > 0)
            break;
            else
            cout << "Enter valid max marks for assignments ! "<<endl;
        }

        int obt;
        for(int i = 0 ; i < num_of_assigns ; i ++)
        {
            while(true)
            {
                cout << "Enter obtained marks for Assignment " << i+1 << " : ";
                cin >> obt;
                if(obt >= 0 && obt <= assign_max)
                {
                    assign_obtained[i] = obt;
                    break;
                }
                else
                cout << "Enter valid obtained quiz Assignment ! "<<endl;
            }

        }

    }
    void Mid_Marking()
    {
        while(true)
        {
            cout << "Max marks  of midExam : ";
            cin >> mid_max;
            if(mid_max > 0)
            break;
            else
            cout << "Enter valid max marks for midExam ! "<<endl;
        }

        while(true)
        {
            cout << "Enter obtained marks in midExam : ";
            cin >> mid_obtained;
            if(mid_obtained>=0 && mid_obtained <= mid_max)
            break;
            else
            cout << "Enter valid obtained marks for midExam ! "<<endl;
        }
        
    }
    void Final_marking()
    {

        while(true)
        {
            cout << "Max marks  of FinalExam : ";
            cin >> finals_max;
            if(finals_max > 0)
            break;
            else
            cout << "Enter valid max marks for FinalExam ! "<<endl;
        }

        while(true)
        {
            cout << "Enter obtained marks in FinalExam : ";
            cin >> finals_obtained;
            if(finals_obtained>=0 && finals_obtained <= finals_max)
            break;
            else
            cout << "Enter valid obtained marks for FinalExam ! "<<endl;
        }

    }
    void Percentage_calc()
    {
        Grading * grd = new Grading();

        percentage = (grd->Quiz_grading(quiz_max , quiz_obtained , num_of_quizes)+ grd->Assign_grading(assign_max , assign_obtained , num_of_assigns) + grd->mid_grading(mid_max , mid_obtained) + grd->finals_grading(finals_max , finals_obtained));

        cout << "\n----------------------------------------------\n";
        cout << "\nPercentage of this subject : "<< percentage <<" %"<<endl;
        cout << "----------------------------------------------\n";

        Grade_Calc(grd);
        
    }
    void Grade_Calc(Grading * grd)
    {
        grade = grd->retGrade(percentage);
        cout << "\n----------------------------------------------\n";
        cout << "\nStudent grade for this subject : "<< grade <<endl;
        cout << "----------------------------------------------\n";
        
    }
    ~Marking()
    {
        ofstream outputFile("student_grades.txt", ios::app); 
        if (outputFile.is_open()) {

            

            outputFile << name << endl;
            outputFile << id << endl;
            outputFile << percentage <<endl;
            outputFile << grade <<endl;

            outputFile.close();
            cout << "Student details written to student_grades.txt." << endl;
        } 
        else {
            cout << "Error: Unable to write to file." << endl;
        }
    }
};
class Student{

    string name;
    int id;
    static int serial;

    public:

    Student()
    {
        name = "";
        id = 0;
    }

    void Intro()
    {
        cout << "Enter name : ";
        cin.ignore();
        getline(cin , name);
        cout << "Enter roll number : ";
        cin >> this->id;
    }
    void marks_allot()
    {
        Marking * marksheet = new Marking(name , id);
        delete marksheet;
    }

};
int Student :: serial = 0;
int main()
{
    int x = 0;
    while(x != 3)
    {
        cout << "1- Enter student details"<<endl;
        cout << "2- Display student grades"<<endl;
        cout << "3- Exit"<<endl<<endl;
        cout << "Enter choice : ";

        
        cin >> x;
        if(x == 1)
        {
            Student * stud = new Student();
            stud->Intro();
            stud->marks_allot();

        }
        else if(x==2)
        {
            Database * db = new Database();
            delete db;
        }
        else if(x!= 1 && x!=2 && x!=3)
        {
            cout << "Enter valid option : "<<endl;
        }
    }
}