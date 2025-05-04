#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>

using namespace std;

struct course{
    string name;
    int credits;
    string grade;
    float gradepoint;
};

float cgpoint(const string& grade)
{
    if(grade=="A+") return 10.0;
    if(grade=="A") return 9.0;
    if(grade=="B+") return 8.0;
    if(grade=="B") return 7.0;
    if(grade=="C+") return 6.0; 
    if(grade=="C") return 5.0;
    if(grade=="D+") return 4.0;
    if(grade=="D") return 3.0;
    if(grade=="E") return 2.0;
    if(grade=="F") return 0.0;
    return -1.0; // Invalid grade 
}

int main()
{
    int n;
    cout<<"Enter the no. of courses: ";
    cin>>n;

    vector<course>courses(n);

    float totalgpoints=0.0;
    int totalcredits=0;

    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter details for course "<<i+1<<":\n";
        cout<<"Course name: ";
        cin>>ws;
        getline(cin,courses[i].name);

        cout<<"Credits: ";
        cin>>courses[i].credits;

        cout<<"Grade: (A+, A, B+, B, C+, C, D , E , F) : ";
        cin>>courses[i].grade;

        courses[i].gradepoint=cgpoint(courses[i].grade);

        if(courses[i].gradepoint<0)
        {
            cout<<"Invalid grade entered. Exiting....\n";
           return 1;
        }

        totalgpoints+=courses[i].gradepoint*courses[i].credits;
        totalcredits+=courses[i].credits;
    }

    float cgpa=totalgpoints/totalcredits;

    cout << "\n--- Grade Summary ---\n";
    cout << left << setw(20) << "Course" 
         << setw(10) << "Credits" 
         << setw(10) << "Grade" 
         << setw(15) << "Grade Points" << endl;

    for (const auto& c : courses) {
        cout << left << setw(20) << c.name 
             << setw(10) << c.credits 
             << setw(10) << c.grade 
             << setw(15) << fixed << setprecision(2) << c.gradepoint << endl;
    }
    cout<<"\nTotal Credits: "<<totalcredits<<"\n";
    cout<<"\nCGPA: "<<fixed<<setprecision(2)<<cgpa<<"\n";
    return 0;

}