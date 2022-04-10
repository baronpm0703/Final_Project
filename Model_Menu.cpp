#include "lib.h"

//Noted task havent finished: Adjust SvList, ADjust/Delete Semsetr
//Noted: Try to make orderd linked list

//Check is there enough 3 term of Semester
int Check_Num_Semester(School_Year::Semester* Semester_Head)
{
    int count = 0;

    while (Semester_Head != nullptr)
    {
        count ++;
        Semester_Head = Semester_Head -> Next;
        
    }
    
    return count;
}

//Check Sv_List empty - ┌( ಠ_ಠ)┘
bool Check_Sv_List(School_Year::Year_Class::SV_List* Sv_Head)
{
    if (Sv_Head == nullptr) return false;
    return true;
}

//Check classes empty - ┌( ಠ_ಠ)┘
bool Check_Classes(School_Year::Year_Class* Classes_Head)
{
    if (Classes_Head == nullptr) return false;
    return true;
}

//Checkb year empty - ༼ つ ◕_◕ ༽つ
bool Check_School_Year(School_Year* sYear_Head)
{
    if (sYear_Head == nullptr) return false;
    return true;
}

//Check Year Dup - (❁´◡`❁)
bool Check_Year_Duplicated(School_Year* sYear_Cur, string x)
{
    while (sYear_Cur != nullptr)
    {
        if (sYear_Cur -> year == x) return false;
        
        sYear_Cur = sYear_Cur -> Next;
    }
    return true;
}

//Check Classes Dup - ヽ(✿ﾟ▽ﾟ)ノ
bool Check_Classes_Duplicated(School_Year::Year_Class* Classes_Cur, string x)
{
    while (Classes_Cur != nullptr)
    {
        if (Classes_Cur -> nameClass == x) return false;
        
        Classes_Cur = Classes_Cur -> Next;
    }
    return true;
}

//Check Sv Dup in Input scene
bool Check_Sv_Duplicated_Input(School_Year::Year_Class::SV_List* Sv_Cur,School_Year::Year_Class::SV_List* Temp_Sv)
{
    while (Sv_Cur -> Next != nullptr)
    {
        if (Sv_Cur -> no == Temp_Sv -> no) return false; //Check no

        if (Sv_Cur -> idStudent == Temp_Sv -> idStudent) return false; //Check Id_SV

        if (Sv_Cur -> socialID == Temp_Sv ->socialID) return false; //Check Social ID

        //Only need to check 3 of this because every data remain is allowed to be duplicated

        Sv_Cur = Sv_Cur -> Next;
    }
    return true;
}

//Check Sv Dup in Input scene
bool Check_Sv_Duplicated(School_Year::Year_Class::SV_List* Sv_Cur,School_Year::Year_Class::SV_List* Temp_Sv)
{
    while (Sv_Cur != nullptr)
    {
        if (Sv_Cur -> no == Temp_Sv -> no) return false; //Check no

        if (Sv_Cur -> idStudent == Temp_Sv -> idStudent) return false; //Check Id_SV

        if (Sv_Cur -> socialID == Temp_Sv ->socialID) return false; //Check Social ID

        //Only need to check 3 of this because every data remain is allowed to be duplicated

        Sv_Cur = Sv_Cur -> Next;
    }
    return true;
}

//Check Semester
bool Check_Semester_Duplicated(School_Year::Semester* Semester_Cur, int temp)
{
    while (Semester_Cur != nullptr)
    {
        if (Semester_Cur -> Term == temp) return false;

        Semester_Cur = Semester_Cur -> Next;
    }
    return true;
}

//Check Subject Input
bool Check_Subject_Duplicated_Input(School_Year::Semester::Subject* Subject_Head,School_Year::Semester::Subject* Subject_Cur)
{
    while (Subject_Head -> Next != nullptr)
    {
        if (Subject_Head -> id_Subject == Subject_Cur -> id_Subject) return false;

        if (Subject_Head -> name_Subject == Subject_Cur -> name_Subject) return false;

        if (Subject_Head -> day_Of_Session_1  == Subject_Cur -> day_Of_Session_1 ) 
            {
                if (Subject_Head -> at_Time_1  == Subject_Cur -> at_Time_1 )  return false;
            }

        if (Subject_Head -> day_Of_Session_2  == Subject_Cur -> day_Of_Session_2 ) 
            {
                if (Subject_Head -> at_Time_2  == Subject_Cur -> at_Time_2 )  return false;
            }
        Subject_Head = Subject_Head -> Next;
    }
    return true;
}

//Check Subject Duplicated
bool Check_Subject_Duplicated(School_Year::Semester::Subject* Subject_Head,School_Year::Semester::Subject* Subject_Cur)
{
    while (Subject_Head != nullptr)
    {
        if (Subject_Cur == Subject_Head ) goto Next;

        if (Subject_Head -> id_Subject == Subject_Cur -> id_Subject) return false;

        if (Subject_Head -> name_Subject == Subject_Cur -> name_Subject) return false;

        if (Subject_Head -> day_Of_Session_1  == Subject_Cur -> day_Of_Session_1 ) 
            {
                if (Subject_Head -> at_Time_1  == Subject_Cur -> at_Time_1 )  return false;
            }

        if (Subject_Head -> day_Of_Session_2  == Subject_Cur -> day_Of_Session_2 ) 
            {
                if (Subject_Head -> at_Time_2  == Subject_Cur -> at_Time_2 )  return false;
            }

        Next:
        Subject_Head = Subject_Head -> Next;
    }
    return true;
}

//Find the year with the same naem of user choosed - ヾ(⌐■_■)ノ♪
School_Year* find_School_Year(School_Year* sYear_Cur,string user_choosed_Year)
{
    while (sYear_Cur != nullptr)
    {
        if (sYear_Cur -> year == user_choosed_Year) return sYear_Cur;
        
        sYear_Cur = sYear_Cur -> Next;
    }
}

//Find the classes with the same name of user choosed - ヾ(⌐■_■)ノ♪
School_Year::Year_Class* find_Classes(School_Year::Year_Class* Classes_Cur,string user_choosed_Class)
{
    while (Classes_Cur!= nullptr)
    {
        if (Classes_Cur -> nameClass == user_choosed_Class) return Classes_Cur;
        
        Classes_Cur= Classes_Cur-> Next;
    }
}

//Find Sv due to No, Id, Social ID
School_Year::Year_Class::SV_List* find_Student(School_Year::Year_Class::SV_List* Sv_Cur,School_Year::Year_Class::SV_List* Temp_Sv)
{
    while (Sv_Cur != nullptr)
    {
        if (Sv_Cur -> no == Temp_Sv -> no) return Sv_Cur; //Check no

        if (Sv_Cur -> idStudent == Temp_Sv -> idStudent) return Sv_Cur; //Check Id_SV

        if (Sv_Cur -> socialID == Temp_Sv ->socialID) return Sv_Cur; //Check Social ID

        //Only need to check 3 of this because every data remain is allowed to be duplicated

        Sv_Cur = Sv_Cur -> Next;
    }
}

//Find Semester
School_Year::Semester* find_Semester(School_Year::Semester* Semester_Cur, int temp)
{
    while (Semester_Cur != nullptr)
    {
        if (Semester_Cur -> Term == temp) return Semester_Cur;

        Semester_Cur = Semester_Cur -> Next;
    }
}

//Find Subject
School_Year::Semester::Subject* find_Subject(School_Year::Semester::Subject* Subject_Head,School_Year::Semester::Subject* Subject_Cur)
{
    while (Subject_Head != nullptr)
    {
        if (Subject_Head -> id_Subject == Subject_Cur -> id_Subject) return Subject_Head;

        if (Subject_Head -> name_Subject == Subject_Cur -> name_Subject) return Subject_Head;

        if (Subject_Head -> day_Of_Session_1  == Subject_Cur -> day_Of_Session_1 ) 
            {
                if (Subject_Head -> at_Time_1  == Subject_Cur -> at_Time_1 )  return Subject_Head;
            }

        if (Subject_Head -> day_Of_Session_2  == Subject_Cur -> day_Of_Session_2 ) 
            {
                if (Subject_Head -> at_Time_2  == Subject_Cur -> at_Time_2 )  return Subject_Head;
            }
    }
}

//Show School-Year table - <( ‵□′)───C＜─___-)||
void Show_Year_Table(School_Year* sYear_Head)
{
    //Show the table full of School_Year - 👌
    system("CLS");
    cout<<"School_Year: |    ";
    
    School_Year* sYear_Cur = sYear_Head;

        while (sYear_Cur != nullptr)
        {
            cout<< atoi((sYear_Cur -> year).c_str()) << " - " << atoi((sYear_Cur -> year).c_str()) + 1  << "    |    ";

            sYear_Cur = sYear_Cur -> Next;
        } 

    cout<<endl<<endl;
}

//Show Classes table - （︶^︶）
void Show_Classes_Table(string user_School_Year,School_Year::Year_Class* Classes_Head)
{
     //Show the Classes from chosen school year - 👌
        system("CLS");
        cout<<"School_Year:    |    "<<atoi(user_School_Year.c_str())<<"-"<<atoi(user_School_Year.c_str()) + 1<<"   |"<<endl;
        cout<<"Classes:        |   ";
        
        School_Year::Year_Class* Classes_Cur = Classes_Head;

        while (Classes_Cur != nullptr)
        {
            cout<<Classes_Cur -> nameClass<<"   |    ";
            Classes_Cur = Classes_Cur -> Next;
        }

        cout<<endl<<endl;
}

//Show SV_list table - 
void Show_Sv_Table(string user_Class,School_Year::Year_Class::SV_List* Sv_Head)
{
     //Show the Classes from chosen school year - 👌
        system("CLS");
        cout<<"| Classes\t|"<<user_Class<<"\t\t|"<<endl<<endl;
        cout<<"    \t| No\t| Student ID\t\t| First Name\t| Last Name\t\t| Gender\t| DateOfBirth\t\t| Social ID\t\t|"<<endl;
        cout<<"    \t";
        
        School_Year::Year_Class::SV_List* Sv_Cur = Sv_Head;

        while (Sv_Cur != nullptr) 
        {
            cout<<"| "<<Sv_Cur -> no<<"\t| "<<Sv_Cur ->idStudent<<"\t\t| "<<Sv_Cur ->firstName<<"\t\t| "<<Sv_Cur ->lastName<<"\t\t| "<<Sv_Cur ->gender<<"\t\t| "<<Sv_Cur ->dateOfBirth<<"\t\t| "<<Sv_Cur ->socialID<<"\t\t| "<<endl;
            
            cout<<"    \t";
            Sv_Cur = Sv_Cur -> Next;
        }

        cout<<endl<<endl;
}

//Show Semester
void Show_Semester_Table(string user_School_Year,School_Year::Semester* Semester_Head)
{
     //Show the table full of School_Year - 👌
        system("CLS");
        cout<<"| School_Year:    | "<<atoi(user_School_Year.c_str())<<"-"<<atoi(user_School_Year.c_str()) + 1<<"\t|"<<endl;
        cout<<"   | Semester   | Start Date\t| End Date\t|"<<endl;
        cout<<"   | ";
        School_Year::Semester* Semester_Cur = Semester_Head;

            while (Semester_Cur != nullptr)
            {
                switch (Semester_Cur -> Term)
                {
               
                case 1:
                {
                    cout<<Semester_Cur -> Term<<" (Fall)\t| "<<Semester_Cur -> start_Date<<"\t\t| "<<Semester_Cur -> end_Date<<"\t\t|";
                    break;
                }

                case 2:
                {
                    cout<<Semester_Cur -> Term<<" (Summer)\t| "<<Semester_Cur -> start_Date<<"\t\t| "<<Semester_Cur -> end_Date<<"\t\t|";
                    break;
                }
                
                default:
                    cout<<Semester_Cur -> Term<<" (Autumn)\t| "<<Semester_Cur -> start_Date<<"\t\t| "<<Semester_Cur -> end_Date<<"\t\t|";
                    break;
                }
                
                if (Semester_Cur -> Next != nullptr)
                {
                    cout<<endl;
                    cout<<"   | ";
                }

                Semester_Cur = Semester_Cur -> Next;
            } 

        cout<<endl<<endl;
}

//Show Subject Table
void Show_Subject_Table(string user_Semester,School_Year::Semester::Subject* Subject_Head)
{
    system("CLS");
    cout<<"| Semester\t|"<<user_Semester<<"\t|"<<endl<<endl;
    cout<<"\t| Course ID\t| Course Name\t| Teacher Name\t\t| Start Date\t| End Date\t| Session 1\t| Time\t\t| Session 2\t| Time\t\t| Number of credits\t| Maximum Student|"<<endl;
    cout<<"\t";
    
    while (Subject_Head != nullptr)
    {
        cout<<"| "<<Subject_Head -> id_Subject<<"\t\t| "<<Subject_Head -> name_Subject<<"\t\t| ";

        //Teacher Name
        if ((Subject_Head -> teacher_Name).size() > 14) cout<<Subject_Head -> teacher_Name<<"\t| ";
        else cout<<Subject_Head -> teacher_Name<<"\t\t| ";
        
        //Start date, Endate
        cout<<Subject_Head -> startDate<<"\t| "<<Subject_Head -> endDate<<"\t| "<<Subject_Head -> day_Of_Session_1<<"\t\t| ";

        if (Subject_Head -> at_Time_1 == "S3" ) cout<<"13:30 - 15:29\t| ";
        if (Subject_Head -> at_Time_1 == "S4" ) cout<<"15:30 - 17:29\t| ";
        if (Subject_Head -> at_Time_1 == "S1" ) cout<<"7:30 - 9:29\t| ";
        if (Subject_Head -> at_Time_1 == "S2" ) cout<<"9:30 - 11:29\t| ";

        cout<<Subject_Head -> day_Of_Session_2<<"\t\t| ";

        if (Subject_Head -> at_Time_2 == "S3" ) cout<<"13:30 - 15:29\t| ";
        if (Subject_Head -> at_Time_2 == "S4" ) cout<<"15:30 - 17:29\t| ";
        if (Subject_Head -> at_Time_2 == "S1" ) cout<<"7:30 - 9:29\t| ";
        if (Subject_Head -> at_Time_2 == "S2" ) cout<<"9:30 - 11:29\t| ";

        cout<<Subject_Head -> number_Of_Credit<<"\t\t\t| "<<Subject_Head -> maximumRegrister<<" \t\t|"<<endl;
        cout<<"\t";

        Subject_Head = Subject_Head -> Next;
    }

    cout<<endl; 
}

//Show Specific Subject
void Show_Specific_Subject_Table(string user_Semester,School_Year::Semester::Subject* Subject_Head,School_Year::Semester::Subject* Subject_Cur)
{
    system("CLS");
    cout<<"You Are Choosing: "<<endl<<endl;
    cout<<"      \t| Course ID\t| Course Name\t| Teacher Name\t\t| Start Date\t| End Date\t| Session 1\t| Time\t\t| Session 2\t| Time\t\t| Number of credits\t| Maximum Student|"<<endl;
    cout<<"      \t";
    
    while (Subject_Head != nullptr)
    {
        if (Subject_Head != Subject_Cur) 
        {
            Subject_Head = Subject_Head -> Next;
            continue;
        }

        cout<<"| "<<Subject_Head -> id_Subject<<"\t\t| "<<Subject_Head -> name_Subject<<"\t\t| ";

        //Teacher Name
        if ((Subject_Head -> teacher_Name).size() > 14) cout<<Subject_Head -> teacher_Name<<"\t| ";
        else cout<<Subject_Head -> teacher_Name<<"\t\t| ";
        
        //Start date, Endate
        cout<<Subject_Head -> startDate<<"\t| "<<Subject_Head -> endDate<<"\t| "<<Subject_Head -> day_Of_Session_1<<"\t\t| ";

        if (Subject_Head -> at_Time_1 == "S3" ) cout<<"13:30 - 15:29\t| ";
        if (Subject_Head -> at_Time_1 == "S4" ) cout<<"15:30 - 17:29\t| ";
        if (Subject_Head -> at_Time_1 == "S1" ) cout<<"7:30 - 9:29\t| ";
        if (Subject_Head -> at_Time_1 == "S2" ) cout<<"9:30 - 11:29\t| ";

        cout<<Subject_Head -> day_Of_Session_2<<"\t\t| ";

        if (Subject_Head -> at_Time_2 == "S3" ) cout<<"13:30 - 15:29\t| ";
        if (Subject_Head -> at_Time_2 == "S4" ) cout<<"15:30 - 17:29\t| ";
        if (Subject_Head -> at_Time_2 == "S1" ) cout<<"7:30 - 9:29\t| ";
        if (Subject_Head -> at_Time_2 == "S2" ) cout<<"9:30 - 11:29\t| ";

        cout<<Subject_Head -> number_Of_Credit<<"\t\t\t| "<<Subject_Head -> maximumRegrister<<" \t\t|"<<endl;
        cout<<"\t";
        cout<<endl; 

        return;
    } 
}

//View Student List
void View_Sv_List(string user_Class, School_Year::Year_Class::SV_List* Sv_Head )
{
    //Show SV Table
    if (!Check_Sv_List(Sv_Head)) 
        {
            cout<<"Nothing being added"<<endl;
            system("Pause");
            return ;
        }
            else 
                {
                   Show_Sv_Table(user_Class,Sv_Head);
                }
    system("pause");
}

//Create Student List Manual
void Create_Sv_List_Manual(School_Year::Year_Class* &Class_Cur, School_Year::Year_Class::SV_List* &Sv_Head)
{
    //Declared
    string user_input = "";
    School_Year::Year_Class::SV_List* Sv_Cur = Sv_Head;

    //Check if Sv_Head empty for create new at first
    if (Sv_Head == nullptr) 
            {
                //Input
                cout<<"Your Class: "<<Class_Cur -> nameClass<<endl;
                
                //Declare for the element of SV list contain
                int no = 0 , idStudent , socialID;
                string lastName , firstName , gender , dateOfBirth;

                //Also create new node for the Sv_head
                Sv_Head = new School_Year::Year_Class::SV_List;

                Sv_Head -> no = no + 1 ; // Because this is the top of the list so it will be no = 1

                cout<<"ID Student: "; 
                    cin>>idStudent;
                cout<<"First Name: ";
                    cin.ignore(); // To get line
                    getline(cin,firstName);
                cout<<"Last Name: ";

                    getline(cin,lastName);
                cout<<"Gender (Male/Female/Other): ";
                    
                    getline(cin,gender);
                cout<<"Date of Birh: ";
                    
                    getline(cin,dateOfBirth);
                cout<<"Social ID: ";
                    cin>>socialID;

                //Assigned those value into the list
                Sv_Head -> idStudent = idStudent;
                Sv_Head -> firstName = firstName;
                Sv_Head -> lastName = lastName;
                Sv_Head -> gender = gender;
                Sv_Head -> dateOfBirth = dateOfBirth;
                Sv_Head -> socialID = socialID;

                //Dont forget to save the head of the Sv_list
                Class_Cur -> yearClassSV_ListHead = Sv_Head;

                return;
            }        
    
    //Check if Next SV_List is havent existed
            while (Sv_Cur -> Next != nullptr) Sv_Cur = Sv_Cur -> Next;

            //Create Next Classes and dont forget do store the Prev
            Sv_Cur -> Next = new School_Year::Year_Class::SV_List;
            Sv_Cur -> Next -> Prev = Sv_Cur;
            Sv_Cur = Sv_Cur -> Next;

    //Check if value is being duplicated or not?
    do
    {
        //Input
        cout<<"Your Class: "<<Class_Cur -> nameClass<<endl;
        
        //Declare for the element of SV list contain
        int no = 0 , idStudent , socialID;
        string lastName , firstName , gender , dateOfBirth;

        no = Sv_Cur -> Prev -> no + 1; // The No will be automatically count by the Node you add 

         cout<<"ID Student: "; 
            cin>>idStudent;
        cout<<"First Name: ";
            cin.ignore(); // To get line
            getline(cin,firstName);
        cout<<"Last Name: ";
            getline(cin,lastName);
        cout<<"Gender (Male/Female/Other): ";
            
            getline(cin,gender);
        cout<<"Date of Birh: ";
            
            getline(cin,dateOfBirth);
        cout<<"Social ID: ";
            cin>>socialID;

        //Assigned those value into the list
        Sv_Cur -> no = no;
        Sv_Cur -> idStudent = idStudent;
        Sv_Cur -> firstName = firstName;
        Sv_Cur -> lastName = lastName;
        Sv_Cur -> gender = gender;
        Sv_Cur -> dateOfBirth = dateOfBirth;
        Sv_Cur -> socialID = socialID;

        //Print out remind user to enter value again
        if (!Check_Sv_Duplicated_Input(Sv_Head,Sv_Cur)) cout<<"Your data has been duplicated. Pls retry."<<endl<<endl;
   
    } while ( !Check_Sv_Duplicated_Input(Sv_Head,Sv_Cur) );
    

    return ;
}

//Create_Sv_List Import
void Create_Sv_List_Import(School_Year::Year_Class* &Class_Cur, School_Year::Year_Class::SV_List* &Sv_Head)
{
    //Declared
    School_Year::Year_Class::SV_List* Sv_Cur = Sv_Head;

    int no = 0 , idStudent , socialID;
    string lastName , firstName , gender , dateOfBirth;

    fstream  finp;

    finp.open("Student_Info.csv", ios::in);

    if (!finp.is_open())
        {
            cout<<"The file is empty, Please import the data"<<endl;
            return;
        }
    //Check if Sv_Head empty for create new at first
    
    while ( !finp.eof() )
    {
        if (Sv_Head == nullptr)
        {
            Sv_Head = new School_Year::Year_Class::SV_List;

            string line_input = "";
            getline(finp, line_input);

            //Convert str -> char*;
            char* input = new char [ line_input.size() ];
            strcpy(input,line_input.c_str());

            //Set denim
            const char* denim = ",";

            no = atoi( strtok(input,denim) );
            idStudent = atoi( strtok(NULL,denim) );
            firstName = strtok(NULL,denim);
            lastName = strtok(NULL,denim);
            gender = strtok(NULL,denim);
            dateOfBirth = strtok(NULL,denim);
            socialID = atoi( strtok(NULL,denim) );

            Sv_Head -> no = no;
            Sv_Head -> idStudent = idStudent;
            Sv_Head -> firstName = firstName;
            Sv_Head -> lastName = lastName;
            Sv_Head -> gender = gender;
            Sv_Head -> dateOfBirth = dateOfBirth;
            Sv_Head -> socialID = socialID;

            Class_Cur -> yearClassSV_ListHead = Sv_Head;

            //Set up for the next income
            Sv_Cur = Sv_Head;
            
            continue;
        }

        //Get Data
        string line_input = "";
        getline(finp, line_input);

        //Convert str -> char*;
        char* input = new char [ line_input.size() ];
        strcpy(input,line_input.c_str());

        //Set denim
        const char* denim = ",";

        //Create new node
        while (Sv_Cur -> Next != nullptr) Sv_Cur = Sv_Cur -> Next;
        Sv_Cur -> Next = new School_Year::Year_Class::SV_List;
        Sv_Cur -> Next -> Prev = Sv_Cur;
        Sv_Cur = Sv_Cur -> Next;

        no = atoi( strtok(input,denim) );
        idStudent = atoi( strtok(NULL,denim) );
        firstName = strtok(NULL,denim);
        lastName = strtok(NULL,denim);
        gender = strtok(NULL,denim);
        dateOfBirth = strtok(NULL,denim);
        socialID = atoi( strtok(NULL,denim) );

        Sv_Cur -> no = no;
        Sv_Cur -> idStudent = idStudent;
        Sv_Cur -> firstName = firstName;
        Sv_Cur -> lastName = lastName;
        Sv_Cur -> gender = gender;
        Sv_Cur -> dateOfBirth = dateOfBirth;
        Sv_Cur -> socialID = socialID;
    }
    
    finp.close();

    return ;
}

//Adjust Sv List
void Adjust_Sv_List(School_Year::Year_Class* Class_Cur, School_Year::Year_Class::SV_List* &Sv_Head)
{
    if (Sv_Head == nullptr)
    {
        cout<<"There are nothing to be adjusted. Please Create One.";
        system("pause");
        return;
    }

    Show_Sv_Table(Class_Cur -> nameClass, Sv_Head);

    int user_Choose_Student ;
    string temp = "Y";
    cin.ignore();
    School_Year::Year_Class::SV_List* Temp_Sv = nullptr;
    do
    {
        delete Temp_Sv;
        Temp_Sv = new School_Year::Year_Class::SV_List;
        
        cout<<"You want to adjust your student due to: "<<endl;
        cout<<"     1: No"<<endl;
        cout<<"     2: ID Student"<<endl;
        cout<<"     3: Social ID"<<endl;
        cout<<"     4: Back"<<endl;
        cout<<"     Your Choice: ";
        
        cin>>user_Choose_Student;

        switch (user_Choose_Student)
        {
        
        case 1:
        {
            cout<<"\n Enter No: ";
            cin>>Temp_Sv -> no;

            break;
        }
        
        case 2:
        {
            cout<<"\n Enter Student ID: ";
            cin>>Temp_Sv -> idStudent;
            
            break;
        }

        case 3:
        {
            cout<<"\n Enter Social ID: ";
            cin>>Temp_Sv -> socialID;
        }
        default:
            return;
            break;
        }

        if (Check_Sv_Duplicated(Sv_Head,Temp_Sv)) 
        {
            cout<<"There arent any student match with your info. Please try again."<<endl;
            
            //Enter any key to continue and go back to  "Showing_School_Year"
            system("pause");
        }
    } while (Check_Sv_Duplicated(Sv_Head,Temp_Sv));

    School_Year::Year_Class::SV_List* Sv_Cur = find_Student(Sv_Head,Temp_Sv);

    cout<<endl;
    cin.ignore();
    do
    {
        Show_Sv_Table(Class_Cur -> nameClass, Sv_Head);

        int user_Choice; 
        cout<<"What do you want to change?"<<endl;
        cout<<"     1: Student ID."<<endl;
        cout<<"     2: Social ID."<<endl;
        cout<<"     3: First Name."<<endl;
        cout<<"     4: Last Name."<<endl;
        cout<<"     5: Gender."<<endl;
        cout<<"     6: Date of Birth."<<endl;
        cout<<"     7: Back."<<endl;
        cout<<"     Your answer: ";
        cin>>user_Choice;


        cin.ignore();
            Temp_Sv = new School_Year::Year_Class::SV_List;
        switch (user_Choice)
        {
            case 1:
            {
                cout<<"What do you want to change Student ID, from "<<Sv_Cur -> idStudent<<" to?"<<endl;
                cout<<"Enter Student ID: ";
                cin>>Temp_Sv -> idStudent;
                cin.ignore();

                if (!Check_Sv_Duplicated (Sv_Head,Temp_Sv))
                    {
                        cout<<"Your input is Incorrect. Please try again."<<endl;
                        
                        //Enter any key to continue and go back to  "Showing_School_Year"
                        system("pause");
                        cout<<"\n";

                        break;
                    }

                Sv_Cur -> idStudent = Temp_Sv -> idStudent;

                break;
            }
            
            case 3:
            {
                cout<<"What do you want to change First Name, from "<<Sv_Cur -> firstName<<" to?"<<endl;
                cout<<"Enter First Name: ";
                getline(cin,Temp_Sv -> firstName);

                if (!Check_Sv_Duplicated (Sv_Head,Temp_Sv))
                    {
                        cout<<"Your input is Incorrect. Please try again."<<endl;
                        
                        //Enter any key to continue and go back to  "Showing_School_Year"
                        system("pause");
                        cout<<"\n";

                        break;
                    }

                Sv_Cur -> firstName = Temp_Sv -> firstName ;

                break;
            }

            case 4:
            {
                cout<<"What do you want to change Last Name, from "<<Sv_Cur -> lastName<<" to?"<<endl;
                cout<<"Enter Last Name: ";
                getline(cin,Temp_Sv -> lastName);

                if (!Check_Sv_Duplicated (Sv_Head,Temp_Sv))
                    {
                        cout<<"Your input is Incorrect. Please try again."<<endl;
                        
                        //Enter any key to continue and go back to  "Showing_School_Year"
                        system("pause");
                        cout<<"\n";

                        break;
                    }

                Sv_Cur -> lastName = Temp_Sv -> lastName ;

                break;
            }

            case 5:
            {
                cout<<"What do you want to change Gender, from "<<Sv_Cur -> gender<<" to?"<<endl;
                cout<<"Enter Gender: ";
                getline(cin,Temp_Sv -> gender);

                if (!Check_Sv_Duplicated (Sv_Head,Temp_Sv))
                    {
                        cout<<"Your input is Incorrect. Please try again."<<endl;
                        
                        //Enter any key to continue and go back to  "Showing_School_Year"
                        system("pause");
                        cout<<"\n";

                        break;
                    }

                Sv_Cur-> gender = Temp_Sv -> gender ;

                break;
            }

            case 6:
            {
                cout<<"What do you want to change Date Of Birth, from "<<Sv_Cur -> dateOfBirth<<" to?"<<endl;
                cout<<"Enter Date Of Birth: ";
                getline(cin,Temp_Sv -> dateOfBirth);

                if (!Check_Sv_Duplicated (Sv_Head,Temp_Sv))
                    {
                        cout<<"Your input is Incorrect. Please try again."<<endl;
                        
                        //Enter any key to continue and go back to  "Showing_School_Year"
                        system("pause");
                        cout<<"\n";

                        break;
                    }

                Sv_Cur -> dateOfBirth = Temp_Sv -> dateOfBirth ;

                break;
            }

            case 2:
            {
                cout<<"What do you want to change Social ID, from "<<Sv_Cur -> socialID<<" to?"<<endl;
                cout<<"Enter Day of Session 1 in week: ";
                cin>>Temp_Sv -> socialID;
                cin.ignore();

                if (!Check_Sv_Duplicated (Sv_Head,Temp_Sv))
                    {
                        cout<<"Your input is Incorrect. Please try again."<<endl;
                        
                        //Enter any key to continue and go back to  "Showing_School_Year"
                        system("pause");
                        cout<<"\n";

                        break;
                    }

                Sv_Cur -> socialID = Temp_Sv -> socialID ;

                break;
            }

            default:
                {
                    system("pause");
                    return;
                    break;
                }
        }

        
        if (Check_Sv_Duplicated (Sv_Head,Temp_Sv))
        {
            cout<<endl;
            cout<<"Continue To Change Info Of This Course?"<<endl;
            cout<<"Enter (Y/N): "; 
            getline(cin,temp);
        }

    } while (!Check_Sv_Duplicated (Sv_Head, Temp_Sv) && temp == "Y");
    
    cout<<"\n";
    cout<<"Change Success"<<endl;

    system("pause");
    return;

}

//Delete SV_list
void Delete_Sv_List(School_Year::Year_Class* &Class_Cur, School_Year::Year_Class::SV_List* &Sv_Head)
{
    if (Sv_Head == nullptr)
    {
        cout<<"There are nothing to be deleted. Please Create One.";
        system("pause");
        return;
    }

    Show_Sv_Table(Class_Cur -> nameClass, Sv_Head);

    int user_Choose_Student ;
    cin.ignore();
    School_Year::Year_Class::SV_List* Temp_Sv = nullptr;
    do
    {
        delete Temp_Sv;
        Temp_Sv = new School_Year::Year_Class::SV_List;
        
        cout<<"You want to delete your student due to: "<<endl;
        cout<<"     1: No"<<endl;
        cout<<"     2: ID Student"<<endl;
        cout<<"     3: Social ID"<<endl;
        cout<<"     4: Back"<<endl;
        cout<<"     Your Choice: ";
        
        cin>>user_Choose_Student;

        switch (user_Choose_Student)
        {
        
        case 1:
        {
            cout<<"\n Enter No: ";
            cin>>Temp_Sv -> no;

            break;
        }
        
        case 2:
        {
            cout<<"\n Enter Student ID: ";
            cin>>Temp_Sv -> idStudent;
            
            break;
        }

        case 3:
        {
            cout<<"\n Enter Social ID: ";
            cin>>Temp_Sv -> socialID;
        }
        default:
            return;
            break;
        }

        if (Check_Sv_Duplicated(Sv_Head,Temp_Sv)) 
        {
            cout<<"There arent any student match with your info. Please try again."<<endl;
            
            //Enter any key to continue and go back to  "Showing_School_Year"
            system("pause");
        }
    } while (Check_Sv_Duplicated(Sv_Head,Temp_Sv));
    
    School_Year::Year_Class::SV_List* Sv_Cur = find_Student(Sv_Head,Temp_Sv);

    if (Sv_Cur == Sv_Head)
    {
        if (Sv_Head -> Next == nullptr)
        {
            Sv_Head = nullptr;
            Class_Cur -> yearClassSV_ListHead = Sv_Head;
            
            system("pause");
            return;
        }

        Sv_Head = Sv_Head -> Next;
        Sv_Head -> Prev = nullptr;  
        Class_Cur -> yearClassSV_ListHead = Sv_Head;

            system("pause");
            return;
    }

    Temp_Sv = Sv_Cur;

    Sv_Cur -> Prev -> Next = Temp_Sv -> Next;

    delete Temp_Sv;

    system("pause");
    return;
}

//View Classes - ᕦ(ò_óˇ)ᕤ
void View_Classes(string user_School_Year,School_Year::Year_Class* &Classes_Head)
{
    //Use a checking var to ignore line
    bool Check_Ignore = false;

    //Show Classes Table
    Showing_Classes:
    if (!Check_Classes(Classes_Head)) 
        {
            cout<<"Nothing being added"<<endl;
            system("Pause");
            return ;
        }
            else 
                {
                    Show_Classes_Table(user_School_Year,Classes_Head);
                }
    //Next step
        string user_Choosed_Class = "";
        
        if (!Check_Ignore) cin.ignore();
    do
    {
        //Menu of User choice about School-Year they want to view
            cout<<"Which Class you want to view info. Ex: 21clc01"<<endl;
            cout<<"Note: If you dont want to choose any class pls Enter 'N' "<<endl;
            cout<<"Enter answer: ";

            getline(cin,user_Choosed_Class);

        if (user_Choosed_Class == "N") return;

        //Check if the user choosed Year is existed - True is it not Duplicated which mean the Data is Incorrect
        if (Check_Classes_Duplicated(Classes_Head,user_Choosed_Class)) 
        {
            cout<<"Your input Classes: "<<user_Choosed_Class<<" is Incorrect. Please try again."<<endl;
            
            //Enter any key to continue and go back to  "Showing_School_Year"
            system("pause");
            Check_Ignore = true;
            goto Showing_Classes;
        }

    } while (Check_Classes_Duplicated(Classes_Head,user_Choosed_Class));
    
    //Menu for student list in specific classes - 📲
    int user_Choose = 0;
    School_Year::Year_Class* Classes_Cur = find_Classes(Classes_Head,user_Choosed_Class); // To locate the classes user is choosing
    School_Year::Year_Class::SV_List* Sv_Head = Classes_Cur -> yearClassSV_ListHead; //To view or create. 

    while (user_Choose != 5)
    {
        cout<<endl<<endl;

        //Classes Table
        Show_Classes_Table(user_School_Year,Classes_Head);

        //Sv_List
        if (Sv_Head != nullptr)
        {
            Show_Sv_Table(user_Choosed_Class, Sv_Head);
        }

        cout<<"         Wellcome to course registration (Beta Ver)"<<endl;
        cout<<"             1: View Info Student In Class: "<<user_Choosed_Class<<endl;
        cout<<"             2: Create Student List For: "<<user_Choosed_Class<<endl;
        cout<<"             3: Adjust Student List In: "<<user_Choosed_Class<<endl;
        cout<<"             4: Delete Student In: "<<user_Choosed_Class<<endl;
        cout<<"             5: Back"<<endl;
        cout<<"             Your choice: "; 

        cin>>user_Choose;

        cout<<endl;

        //Switch user_Choose
            switch (user_Choose)
            {
            
            //View Sv_List 
                case 1:
                {
                    //Declare
                    School_Year::Year_Class* Classes_Cur = find_Classes(Classes_Head,user_Choosed_Class);

                    //Functions View_SV_List
                    View_Sv_List(user_Choosed_Class, Classes_Cur -> yearClassSV_ListHead);

                    continue;

                    break;
                }

                //Create Classes
                case 2:
                {
                    //Ask user whether he want to import a csv or manual
                    int user_Prefer = 0;
                    cout<<"\t Which one do you prefer: Manual (1) or Quick Import a CSV File (2)"<<endl;
                    cout<<"Your answer: ";
                    cin>>user_Prefer;

                    switch (user_Prefer)
                        {
                        case 1:
                        {
                            //Declare
                            School_Year::Year_Class* Classes_Cur = find_Classes(Classes_Head,user_Choosed_Class);

                            //Functions Create_SV_List
                            Create_Sv_List_Manual (Classes_Cur,Sv_Head);

                            break;
                        }
                        
                        case 2:
                        {
                            //Notice and rule
                            cout<<"To import a CSV there is a rule: No , ID_Student , First Name , Last Name , Gender , Date of Birth , Social ID"<<endl;
                            sleep_until( system_clock::now() + seconds(1) );
                            cout<<"Notice: If u havent Import in Student_Info.csv, now it's your time! then continue"<<endl;

                            system("pause");
                            //Declare
                            School_Year::Year_Class* Classes_Cur = find_Classes(Classes_Head,user_Choosed_Class);

                            //Functions Create_SV_List
                            Create_Sv_List_Import (Classes_Cur,Sv_Head);

                            break;
                        }
                        
                        default:
                            break;
                        }
                    
                    continue;

                    break;
                }
            
            case 3:
                {
                    //Declare
                    School_Year::Year_Class* Classes_Cur = find_Classes(Classes_Head,user_Choosed_Class);

                    //Functions Adjust_SV_List
                    Adjust_Sv_List (Classes_Cur,Sv_Head);

                    continue;
                    
                    break;
                }

             case 4:
                {
                    //Declare
                    School_Year::Year_Class* Classes_Cur = find_Classes(Classes_Head,user_Choosed_Class);

                    //Functions Delete_SV_List
                    Delete_Sv_List (Classes_Cur,Sv_Head);

                    continue;
                    
                    break;
                }

            default:

                break;
            }
    }
    cout<<"Ending Menu Student List..."<<endl;
    system("pause");
    
    //End of this funcs
    return;
}

//Create Classes - (ﾉ*ФωФ)ﾉ
void Create_Classes(School_Year* &Year_Cur, School_Year::Year_Class* &Classes_Head)
{
    //Declareed
    string user_input = "";
    School_Year::Year_Class* Classes_Cur = Classes_Head;

    //Check if Classes_Head empty for create new at first
            if (Classes_Head == nullptr) 
            {
                //Input
                cout<<"Noted: Valided classes name (21clc01,..) if the school year was: 2021 - 2022 "<<endl;
                cout<<"Your school year chosen: "<<Year_Cur -> year<<" . Enter Classes Name: ";
                cin.ignore();
                getline(cin,user_input);
                
                //Convert string -> char*
                char* input = new char [user_input.size()];
                strcpy( input,user_input.c_str() );

                //Check if the data is corrected
                if (user_input.substr(0,2) != Year_Cur -> year . substr(2,2)) return ;

                //Declare
                Classes_Head = new School_Year::Year_Class;

                //Strtok
                const char* denim = "-";
                Classes_Head -> nameClass = strtok(input,denim);

                //Dont forget to save the head of the class list
                Year_Cur -> yearCLassHead = Classes_Head;
                return;
            }        

            //Check if value is being duplicated or not?
            char* contain = "";
            cin.ignore();
            do
            {
                //Input
                cout<<"Noted: Valided classes name (21clc01,..) if the school year was: 2021 - 2022 "<<endl;
                cout<<"Your school year chosen: "<<Year_Cur -> year<<" . Enter Classes Name: ";
                getline(cin,user_input);
                
                //Check if the data is corrected - If not the funcs will automatically delete the data
                if (user_input.substr(0,2) != Year_Cur -> year . substr(2,2)) return ;

                //Convert string -> char*
                char* input = new char [user_input.size()];
                strcpy( input,user_input.c_str() );

                //Strtok
                const char* denim = "-";
                contain = strtok(input,denim);

                //Print out remind user to enter value again
                if (!Check_Classes_Duplicated(Classes_Head,contain)) cout<<"Your data has been duplicated. Pls retry."<<endl<<endl;

            } while ( !Check_Classes_Duplicated(Classes_Head,contain) );

            //Check if Next Classes is havent existed
            while (Classes_Cur -> Next != nullptr) Classes_Cur = Classes_Cur -> Next;

            //Create Next Classes and dont forget do store the Prev
            Classes_Cur -> Next = new School_Year::Year_Class;
            Classes_Cur -> Next -> Prev = Classes_Cur;
            Classes_Cur = Classes_Cur -> Next;
            
            Classes_Cur -> nameClass = contain;

            return;
}

//Delete Classes
void Delete_Classes(School_Year* &sYear_Cur,School_Year::Year_Class* &Classes_Head)
{
    if (Classes_Head == nullptr)
    {
        cout<<"There are nothing to be deleted. Please Create One.";
        system("pause");
        return;
    }

    bool Check_Ignore = false;
    string user_Choose_Class = "";
        
        if (!Check_Ignore) cin.ignore();
    do
    {
        //Menu of User choice about School-Year they want to view
            cout<<"Which Class you want to Delete. Ex: 21clc09"<<endl;
            cout<<"Note: If you dont want to choose any class pls Enter 'N' "<<endl;
            cout<<"Enter answer: ";

            getline(cin,user_Choose_Class);

        if (user_Choose_Class == "N") return;

        //Check if the user choosed Year is existed - True is it not Duplicated which mean the Data is Incorrect
        if (Check_Classes_Duplicated(Classes_Head,user_Choose_Class)) 
        {
            cout<<"Your input Class: "<<user_Choose_Class<<" is Incorrect. Please try again."<<endl;
            
            //Enter any key to continue and go back to  "Showing_School_Year"
            system("pause");
            Check_Ignore = true;
        }

    } while (Check_Classes_Duplicated(Classes_Head,user_Choose_Class));

    School_Year::Year_Class* Class_Cur = find_Classes(Classes_Head,user_Choose_Class);

    //Delete all element
    Delete_Element_Of_YearClass(Class_Cur,2);

    if (Class_Cur == Classes_Head)
    {
        if (Class_Cur -> Next == nullptr)
            {
                Classes_Head = nullptr;
                sYear_Cur -> yearCLassHead = Classes_Head;
                system("pause");
                return;
            }

        Classes_Head = Classes_Head -> Next;
        sYear_Cur -> yearCLassHead = Classes_Head;
        system("pause");
        return;
    }

    School_Year::Year_Class* Temp_Class = Class_Cur;

    Class_Cur ->  Prev -> Next = Temp_Class -> Next;

    delete Temp_Class;

    system("pause");
    return;
}

//Adjust Classes
void Adjust_Classes(School_Year* &sYear_Cur,School_Year::Year_Class* &Classes_Head)     
{
    if (Classes_Head == nullptr)
    {
        cout<<"There are nothing to be adjusted. Please Create One.";
        system("pause");
        return;
    }

    bool Check_Ignore = false;
    string user_Choose_Class = "";
        
        if (!Check_Ignore) cin.ignore();
    do
    {
        //Menu of User choice about School-Year they want to view
            cout<<"Which Class you want to Adjust. Ex: 21clc09 "<<endl;
            cout<<"Note: If you dont want to choose any class pls Enter 'N' "<<endl;
            cout<<"Enter answer: ";

            getline(cin,user_Choose_Class);

        if (user_Choose_Class == "N") return;

        //Check if the user choosed Year is existed - True is it not Duplicated which mean the Data is Incorrect
        if (Check_Classes_Duplicated(Classes_Head,user_Choose_Class)) 
        {
            cout<<"Your input class: "<<user_Choose_Class<<" is Incorrect. Please try again."<<endl;
            
            //Enter any key to continue and go back to  "Showing_School_Year"
            system("pause");
            cout<<"\n";
            Check_Ignore = true;
        }
    } while (Check_Classes_Duplicated(Classes_Head,user_Choose_Class));

    cout<<"/n";
    School_Year::Year_Class* Class_Cur = find_Classes(Classes_Head,user_Choose_Class);

    do
    {
        //Menu of User choice about School-Year they want to view
            cout<<"What do you want to change from "<<user_Choose_Class<<" to ?. Ex: 21clc09 -> 21clc10";
            cout<<"Note: If you dont want to change pls Enter 'N' "<<endl;
            cout<<"Enter answer: ";

            getline(cin,user_Choose_Class);

        if (user_Choose_Class == "N") return;

        //Check if the data is corrected
        if (user_Choose_Class.substr(0,2) != sYear_Cur -> year . substr(2,2)) return ;


        //Check if the user choosed Year is existed - True is it not Duplicated which mean the Data is Incorrect
        if (!Check_Classes_Duplicated(Classes_Head,user_Choose_Class)) 
        {
            cout<<"Your input Class: "<<user_Choose_Class<<" is Incorrect. Please try again."<<endl;
            
            //Enter any key to continue and go back to  "Showing_School_Year"
            system("pause");
            cout<<"\n";
            Check_Ignore = true;
        }
    } while (!Check_Classes_Duplicated(Classes_Head,user_Choose_Class));

    Class_Cur -> nameClass = user_Choose_Class;

    cout<<"\n";
    cout<<"Change Success";

    system("pause");
    return;
}

//View Course
void View_Course(string user_Semester, School_Year::Semester::Subject* Subject_Head)
{
    //Show SV Table
    if (Subject_Head == nullptr) 
        {
            cout<<"Nothing being added"<<endl;
            system("Pause");
            return ;
        }
            else 
                {
                   Show_Subject_Table(user_Semester,Subject_Head);
                }
    system("pause");
}

//Create Course Manual
void Create_Course_Manual(School_Year::Semester* &ySemester_Cur, School_Year::Semester::Subject* &Subject_Head)
{
    //Declare
    School_Year::Semester::Subject* Subject_Cur = Subject_Head;

    if (Subject_Head == nullptr)
        {
            cout<<"Your Semster: "<<ySemester_Cur -> Term<<endl;

            //Declare
            string name_Subject, id_Subject;
            string startDate, endDate;
            string teacher_Name;
            string day_Of_Session_1, day_Of_Session_2; // Mon/Tue/Wed
            string at_Time_1, at_Time_2; //S1(7:30) S2(9:30) S3(13:30) S4(15:30)
    
            int maximumRegrister, number_Of_Credit;

            //Enter Data
            cout<<"Course ID: ";
                cin.ignore();
            getline(cin,id_Subject);

            cout<<"Course Name: ";
            getline(cin,name_Subject);

            cout<<"Teacher Name: ";
            getline(cin,teacher_Name);

            cout<<"Start Date: ";
            getline(cin,startDate);

            cout<<"End Date: ";
            getline(cin,endDate);

            Input_SessionHead:
            cout<<"Day of Session 1 (Mon/Tue/Wed/..): ";
            getline(cin,day_Of_Session_1);

            cout<<"At what time of Session 1 { S1(7:30) S2(9:30) S3(13:30) S4(15:30) }"<<endl;
            cout<<"Enter: ";
            getline(cin,at_Time_1);

            cout<<"Day of Session 2 (Mon/Tue/Wed/..): ";
            getline(cin,day_Of_Session_2);

            cout<<"At what time of Session 2 { S1(7:30) S2(9:30) S3(13:30) S4(15:30) }"<<endl;
            cout<<"Enter: ";
            getline(cin,at_Time_2);

            //Check if duplicated time
            if (day_Of_Session_1 == day_Of_Session_2 && at_Time_1 == at_Time_2)
                {
                    cout<<"Your input time is Incorrect. Please Try Again."<<endl;
                    system("pause");
                    cout<<endl;
                    goto Input_SessionHead;
                }
            
            cout<<"Maximum number of student in this course: ";
            cin>>maximumRegrister;

            cout<<"Number of credits: ";
            cin>>number_Of_Credit;

            Subject_Head = new School_Year::Semester::Subject;

            //Assign data
            Subject_Head -> id_Subject = id_Subject;
            Subject_Head -> name_Subject = name_Subject;
            Subject_Head -> teacher_Name = teacher_Name;
            Subject_Head -> startDate = startDate;
            Subject_Head -> endDate = endDate;
            Subject_Head -> day_Of_Session_1 = day_Of_Session_1;
            Subject_Head -> at_Time_1 = at_Time_1;
            Subject_Head -> day_Of_Session_2 = day_Of_Session_2;
            Subject_Head -> at_Time_2 = at_Time_2;
            Subject_Head -> maximumRegrister = maximumRegrister;
            Subject_Head -> number_Of_Credit = number_Of_Credit;

            ySemester_Cur -> yearSemesterSubjectHead = Subject_Head;

            return;
        }

     //Check if Next SV_List is havent existed
            while (Subject_Cur -> Next != nullptr) Subject_Cur = Subject_Cur -> Next;

            //Create Next Classes and dont forget do store the Prev
            Subject_Cur -> Next = new School_Year::Semester::Subject;
            Subject_Cur -> Next -> Prev = Subject_Cur;
            Subject_Cur = Subject_Cur -> Next;

    //Check if value is being duplicated or not?
    do
    {
        cout<<"Your Semster: "<<ySemester_Cur -> Term<<endl;

            //Declare
            string name_Subject, id_Subject;
            string startDate, endDate;
            string teacher_Name;
            string day_Of_Session_1, day_Of_Session_2; // Mon/Tue/Wed
            string at_Time_1, at_Time_2; //S1(7:30) S2(9:30) S3(13:30) S4(15:30)
    
            int maximumRegrister, number_Of_Credit;


            //Enter Data
            cout<<"Course ID: ";
                cin.ignore();
            getline(cin,id_Subject);

            cout<<"Course Name: ";
            getline(cin,name_Subject);

            cout<<"Teacher Name: ";
            getline(cin,teacher_Name);

            cout<<"Start Date: ";
            getline(cin,startDate);

            cout<<"End Date: ";
            getline(cin,endDate);

            Input_SessionCur:

            cout<<"Day of Session 1 (Mon/Tue/Wed/..): ";
            getline(cin,day_Of_Session_1);

            cout<<"At what time of Session 1 { S1(7:30) S2(9:30) S3(13:30) S4(15:30) }"<<endl;
            cout<<"Enter: ";
            getline(cin,at_Time_1);

            cout<<"Day of Session 2 (Mon/Tue/Wed/..): ";
            getline(cin,day_Of_Session_2);

            cout<<"At what time of Session 2 { S1(7:30) S2(9:30) S3(13:30) S4(15:30) }"<<endl;
            cout<<"Enter: ";
            getline(cin,at_Time_2);

            //Check if duplicated time
            if (day_Of_Session_1 == day_Of_Session_2 && at_Time_1 == at_Time_2)
                {
                    cout<<"Your input time is Incorrect. Please Try Again."<<endl;
                    system("pause");
                    cout<<endl;
                    goto Input_SessionCur;
                }
            
            cout<<"Maximum number of student in this course: ";
            cin>>maximumRegrister;

            cout<<"Number of credits: ";
            cin>>number_Of_Credit;

            //Assign data
            Subject_Cur -> id_Subject = id_Subject;
            Subject_Cur -> name_Subject = name_Subject;
            Subject_Cur -> teacher_Name = teacher_Name;
            Subject_Head -> startDate = startDate;
            Subject_Head -> endDate = endDate;
            Subject_Cur -> day_Of_Session_1 = day_Of_Session_1;
            Subject_Cur -> at_Time_1 = at_Time_1;
            Subject_Cur -> day_Of_Session_2 = day_Of_Session_2;
            Subject_Cur -> at_Time_2 = at_Time_2;
            Subject_Cur -> maximumRegrister = maximumRegrister;
            Subject_Cur -> number_Of_Credit = number_Of_Credit;


        //Print out remind user to enter value again
        if (!Check_Subject_Duplicated_Input(Subject_Head,Subject_Cur)) cout<<"Your data has been duplicated. Pls retry."<<endl<<endl;
   
    } while ( !Check_Subject_Duplicated_Input(Subject_Head,Subject_Cur) );

    return;

}

//Create Course Import
void Create_Course_Import(School_Year::Semester* &ySemester_Cur, School_Year::Semester::Subject* &Subject_Head)
{
    //Declare
    string name_Subject, id_Subject;
    string startDate, endDate;
    string teacher_Name;
    string day_Of_Session_1, day_Of_Session_2; // Mon/Tue/Wed
    string at_Time_1, at_Time_2; //S1(7:30) S2(9:30) S3(13:30) S4(15:30)

    int maximumRegrister = 50, number_Of_Credit;

    fstream  finp;

    finp.open("Course_Info.csv", ios::in);

    if (!finp.is_open())
        {
            cout<<"The file is empty, Please import the data"<<endl;
            return;
        }
    while (!finp.eof())
    {
         //Declared
        School_Year::Semester::Subject* Subject_Cur = Subject_Head;

        if (Subject_Head == nullptr)
        {
            Subject_Head = new School_Year::Semester::Subject;

            string line_input = "";
            getline(finp, line_input);

            //Convert str -> char*;
            char* input = new char [ line_input.size() ];
            strcpy(input,line_input.c_str());

            //Set denim
            const char* denim = ",";

            //Get Data
            id_Subject = strtok(input,denim);
            name_Subject = strtok(NULL,denim);
            teacher_Name = strtok(NULL,denim);
            startDate = strtok(NULL,denim);
            endDate = strtok(NULL,denim);
            day_Of_Session_1 = strtok(NULL,denim);
            at_Time_1 = strtok(NULL,denim);
            day_Of_Session_2 = strtok(NULL,denim);
            at_Time_2 = strtok(NULL,denim);
            maximumRegrister = atoi( strtok(NULL,denim) );
            number_Of_Credit = atoi( strtok(NULL,denim) );

            //Assign
            Subject_Head -> id_Subject =  id_Subject;
            Subject_Head -> name_Subject = name_Subject;
            Subject_Head -> teacher_Name = teacher_Name;
            Subject_Head -> startDate = startDate;
            Subject_Head -> endDate = endDate;
            Subject_Head -> day_Of_Session_1 = day_Of_Session_1;
            Subject_Head -> at_Time_1 = at_Time_1;
            Subject_Head -> day_Of_Session_2 = day_Of_Session_2;
            Subject_Head -> at_Time_2 = at_Time_2;
            Subject_Head -> maximumRegrister = maximumRegrister;
            Subject_Head ->  number_Of_Credit = number_Of_Credit;

            //Head
            ySemester_Cur -> yearSemesterSubjectHead = Subject_Head;

            continue; 
        }

        //Get Data
        string line_input = "";
        getline(finp, line_input);

        //Convert str -> char*;
        char* input = new char [ line_input.size() ];
        strcpy(input,line_input.c_str());

        //Set denim
        const char* denim = ",";

        //Create new node
        while (Subject_Cur -> Next != nullptr) Subject_Cur = Subject_Cur -> Next;
        Subject_Cur -> Next = new School_Year::Semester::Subject;
        Subject_Cur -> Next -> Prev = Subject_Cur;
        Subject_Cur = Subject_Cur -> Next;

        //Get Data
        id_Subject = strtok(input,denim);
        name_Subject = strtok(NULL,denim);
        teacher_Name = strtok(NULL,denim);
        startDate = strtok(NULL,denim);
        endDate = strtok(NULL,denim);
        day_Of_Session_1 = strtok(NULL,denim);
        at_Time_1 = strtok(NULL,denim);
        day_Of_Session_2 = strtok(NULL,denim);
        at_Time_2 = strtok(NULL,denim);
        maximumRegrister = atoi( strtok(NULL,denim) );
        number_Of_Credit = atoi( strtok(NULL,denim) );

        //Assign
        Subject_Cur -> id_Subject =  id_Subject;
        Subject_Cur -> name_Subject = name_Subject;
        Subject_Cur -> teacher_Name = teacher_Name;
        Subject_Cur -> startDate = startDate;
        Subject_Cur -> endDate = endDate;
        Subject_Cur -> day_Of_Session_1 = day_Of_Session_1;
        Subject_Cur -> at_Time_1 = at_Time_1;
        Subject_Cur -> day_Of_Session_2 = day_Of_Session_2;
        Subject_Cur -> at_Time_2 = at_Time_2;
        Subject_Cur -> maximumRegrister = maximumRegrister;
        Subject_Cur ->  number_Of_Credit = number_Of_Credit;
    }

    finp.close();

    return;
}

//Adjust Course 
void Adjust_Course(School_Year::Semester* ySemester_Cur, School_Year::Semester::Subject* &Subject_Head)
{
    if (ySemester_Cur == nullptr)
    {
        cout<<"There are nothing to be adjusted. Please Create One";
        system("pause");
        return;
    }

    Show_Subject_Table(to_string(ySemester_Cur -> Term), Subject_Head);
    bool Check_Ignore = false;
    string user_Choose_Course = "";
    School_Year::Semester::Subject* Subject_Temp = new School_Year::Semester::Subject;
        
        cin.ignore();
    do
    {
        //Menu of User choice about School-Year they want to view
            cout<<"Which Course you want to Adjust. Ex: PHY0001 "<<endl;
            cout<<"Note: If you dont want to choose any Course pls Enter 'N' "<<endl;
            cout<<"Enter Course ID: ";

            getline(cin,user_Choose_Course);


        if (user_Choose_Course == "N") return;

        Subject_Temp -> id_Subject = user_Choose_Course;

        //Check if the user choosed Year is existed - True is it not Duplicated which mean the Data is Incorrect
        if (Check_Subject_Duplicated(Subject_Head,Subject_Temp)) 
        {
            cout<<"Your input Course: "<<Subject_Temp -> id_Subject<<" is Incorrect. Please try again."<<endl;
            
            //Enter any key to continue and go back to  "Showing_School_Year"
            system("pause");
            cout<<"\n";
        }
    } while (Check_Subject_Duplicated(Subject_Head,Subject_Temp));


    cout<<"\n";
    School_Year::Semester::Subject* Subject_ToFind = new School_Year::Semester::Subject;
    Subject_ToFind -> id_Subject = user_Choose_Course;

    School_Year::Semester::Subject* Subject_Cur = find_Subject(Subject_Head,Subject_ToFind);

    //Delete 
    delete Subject_ToFind;

    //Declare
    string temp = "Y";

    do
    {
        //Show table
        Show_Specific_Subject_Table(to_string(ySemester_Cur -> Term),Subject_Head,Subject_Cur);

        int user_Choice; 
        cout<<"What do you want to change?"<<endl;
        cout<<"     1: Course ID."<<endl;
        cout<<"     2: Course Name."<<endl;
        cout<<"     3: Teacher Name."<<endl;
        cout<<"     4: Start Date."<<endl;
        cout<<"     5: End Date."<<endl;
        cout<<"     6: Day Of Session 1."<<endl;
        cout<<"     7: Time of Day's Session 1."<<endl;
        cout<<"     8: Day Of Session 2."<<endl;
        cout<<"     9: Time of Day's Session 2."<<endl;
        cout<<"     10: Number of Credits."<<endl;
        cout<<"     11: Maximum Student Number."<<endl;
        cout<<"     12: Back."<<endl;
        cout<<"     Your answer: ";
        cin>>user_Choice;
        
        cout<<"\n";

            cin.ignore();
            Subject_ToFind = new School_Year::Semester::Subject;

        switch (user_Choice)
        {
            case 1:
            {
                cout<<"What do you want to change Course ID, from "<<Subject_Cur -> id_Subject<<" to?"<<endl;
                cout<<"Enter Course ID: ";
                getline(cin,Subject_ToFind -> id_Subject);

                if (!Check_Subject_Duplicated(Subject_Head,Subject_ToFind))
                    {
                        cout<<"Your input is Incorrect. Please try again."<<endl;
                        
                        //Enter any key to continue and go back to  "Showing_School_Year"
                        system("pause");
                        cout<<"\n";

                        break;
                    }

                Subject_Cur -> id_Subject = Subject_ToFind -> id_Subject;

                break;
            }
            
            case 2:
            {
                cout<<"What do you want to change Course Name, from "<<Subject_Cur -> name_Subject<<" to?"<<endl;
                cout<<"Enter Course Name: ";
                getline(cin,Subject_ToFind -> name_Subject);

                if (!Check_Subject_Duplicated(Subject_Head,Subject_ToFind))
                    {
                        cout<<"Your input is Incorrect. Please try again."<<endl;
                        
                        //Enter any key to continue and go back to  "Showing_School_Year"
                        system("pause");
                        cout<<"\n";

                        break;
                    }

                Subject_Cur -> name_Subject = Subject_ToFind -> name_Subject ;

                break;
            }

            case 3:
            {
                cout<<"What do you want to change Teacher Name, from "<<Subject_Cur -> teacher_Name<<" to?"<<endl;
                cout<<"Enter Teacher Name: ";
                getline(cin,Subject_ToFind -> teacher_Name);

                if (!Check_Subject_Duplicated(Subject_Head,Subject_ToFind))
                    {
                        cout<<"Your input is Incorrect. Please try again."<<endl;
                        
                        //Enter any key to continue and go back to  "Showing_School_Year"
                        system("pause");
                        cout<<"\n";

                        break;
                    }

                Subject_Cur -> teacher_Name = Subject_ToFind -> teacher_Name ;

                break;
            }

            case 4:
            {
                cout<<"What do you want to change Start Date Of Course, from "<<Subject_Cur -> startDate<<" to?"<<endl;
                cout<<"Enter Start Date Of Course: ";
                getline(cin,Subject_ToFind -> startDate);


                if (!Check_Subject_Duplicated(Subject_Head,Subject_ToFind))
                    {
                        cout<<"Your input is Incorrect. Please try again."<<endl;
                        
                        //Enter any key to continue and go back to  "Showing_School_Year"
                        system("pause");
                        cout<<"\n";

                        break;
                    }

                Subject_Cur -> startDate = Subject_ToFind -> startDate ;

                break;
            }

            case 5:
            {
                cout<<"What do you want to change End Date Of Course, from "<<Subject_Cur -> endDate<<" to?"<<endl;
                cout<<"Enter End Date Of Course: ";
                getline(cin,Subject_ToFind -> endDate);

                if (!Check_Subject_Duplicated(Subject_Head,Subject_ToFind))
                    {
                        cout<<"Your input is Incorrect. Please try again."<<endl;
                        
                        //Enter any key to continue and go back to  "Showing_School_Year"
                        system("pause");
                        cout<<"\n";

                        break;
                    }

                Subject_Cur -> endDate = Subject_ToFind -> endDate ;

                break;
            }

            case 6:
            {
                cout<<"What do you want to change Day of Session 1 in week, from "<<Subject_Cur -> day_Of_Session_1<<" to?"<<endl;
                cout<<"Enter Day of Session 1 in week: ";
                getline(cin,Subject_ToFind -> day_Of_Session_1);

                if (!Check_Subject_Duplicated(Subject_Head,Subject_ToFind))
                    {
                        cout<<"Your input is Incorrect. Please try again."<<endl;
                        
                        //Enter any key to continue and go back to  "Showing_School_Year"
                        system("pause");
                        cout<<"\n";

                        break;
                    }

                Subject_Cur -> day_Of_Session_1 = Subject_ToFind -> day_Of_Session_1 ;

                break;
            }

            case 7:
            {
                cout<<"What do you want to change Time of Session 1, from "<<Subject_Cur -> at_Time_1<<" to?"<<endl;
                cout<<"Enter Time of Session 1: ";
                getline(cin,Subject_ToFind -> at_Time_1);

                if (!Check_Subject_Duplicated(Subject_Head,Subject_ToFind))
                    {
                        cout<<"Your input is Incorrect. Please try again."<<endl;
                        
                        //Enter any key to continue and go back to  "Showing_School_Year"
                        system("pause");
                        cout<<"\n";

                        break;
                    }

                Subject_Cur -> at_Time_1 = Subject_ToFind -> at_Time_1 ;

                break;
            }

            case 8:
            {
                cout<<"What do you want to change Day of Session 2 in week, from "<<Subject_Cur -> day_Of_Session_2<<" to?"<<endl;
                cout<<"Enter Day of Session 2 in week: ";
                getline(cin,Subject_ToFind -> day_Of_Session_2);

                if (!Check_Subject_Duplicated(Subject_Head,Subject_ToFind))
                    {
                        cout<<"Your input is Incorrect. Please try again."<<endl;
                        
                        //Enter any key to continue and go back to  "Showing_School_Year"
                        system("pause");
                        cout<<"\n";

                        break;
                    }

                Subject_Cur -> day_Of_Session_2 = Subject_ToFind -> day_Of_Session_2 ;

                break;
            }

            case 9:
            {
                cout<<"What do you want to change Time of Session 2, from "<<Subject_Cur -> at_Time_2<<" to?"<<endl;
                cout<<"Enter Time of Session 2: ";
                getline(cin,Subject_ToFind -> at_Time_2);

                if (!Check_Subject_Duplicated(Subject_Head,Subject_ToFind))
                    {
                        cout<<"Your input is Incorrect. Please try again."<<endl;
                        
                        //Enter any key to continue and go back to  "Showing_School_Year"
                        system("pause");
                        cout<<"\n";

                        break;
                    }

                Subject_Cur -> at_Time_2 = Subject_ToFind -> at_Time_2 ;

                break;
            }

            case 10:
            {
                cout<<"What do you want to change Number Of Credit, from "<<Subject_Cur -> number_Of_Credit<<" to?"<<endl;
                cout<<"Enter Number Of Credit: ";
                cin>>Subject_ToFind -> number_Of_Credit;
                cin.ignore();

                if (!Check_Subject_Duplicated(Subject_Head,Subject_ToFind))
                    {
                        cout<<"Your input is Incorrect. Please try again."<<endl;
                        
                        //Enter any key to continue and go back to  "Showing_School_Year"
                        system("pause");
                        cout<<"\n";

                        break;
                    }


                Subject_Cur -> number_Of_Credit = Subject_ToFind -> number_Of_Credit ;

                break;
            }

            case 11:
            {
                cout<<"What do you want to change Maximum Student Registration, from "<<Subject_Cur -> maximumRegrister<<" to?"<<endl;
                cout<<"Enter Maximum Student Registration: ";
                cin>>Subject_ToFind -> maximumRegrister;
                cin.ignore();

                if (!Check_Subject_Duplicated(Subject_Head,Subject_ToFind))
                    {
                        cout<<"Your input is Incorrect. Please try again."<<endl;
                        
                        //Enter any key to continue and go back to  "Showing_School_Year"
                        system("pause");
                        cout<<"\n";

                        break;
                    }

                Subject_Cur -> maximumRegrister = Subject_ToFind -> maximumRegrister ;

                break;
            }

            default:
                {
                    system("pause");
                    return;
                    break;
                }
        }

        
        if (Check_Subject_Duplicated(Subject_Head,Subject_ToFind))
        {
            cout<<endl;
            cout<<"Continue To Change Info Of This Course?"<<endl;
            cout<<"Enter (Y/N): "; 
            getline(cin,temp);
        }

    } while (!Check_Subject_Duplicated(Subject_Head, Subject_ToFind) && temp == "Y");
    

    cout<<"\n";
    cout<<"Change Success"<<endl;

    system("pause");
    return;
}

//Delete Course
void Delete_Course(School_Year::Semester* &ySemester_Cur, School_Year::Semester::Subject* &Subject_Head)
{
    if (Subject_Head == nullptr)
    {
        cout<<"There are nothing to be deleted. Please Create One.";
        system("pause");
        return;
    }

    Show_Subject_Table(to_string(ySemester_Cur -> Term), Subject_Head);
    string user_Choose_Course = "";
    School_Year::Semester::Subject* Subject_Temp = new School_Year::Semester::Subject;
        
    cin.ignore();
    do
    {
        //Menu of User choice about School-Year they want to view
            cout<<"Which Course you want to Delete, Enter Course ID. Ex: PHY0001 "<<endl;
            cout<<"Note: If you dont want to choose any Course pls Enter 'N' "<<endl;
            cout<<"Enter Course ID: ";

            getline(cin,user_Choose_Course);


        if (user_Choose_Course == "N") return;

        Subject_Temp -> id_Subject = user_Choose_Course;

        //Check if the user choosed Year is existed - True is it not Duplicated which mean the Data is Incorrect
        if (Check_Subject_Duplicated(Subject_Head,Subject_Temp)) 
        {
            cout<<"Your input Course: "<<Subject_Temp -> id_Subject<<" is Incorrect. Please try again."<<endl;
            
            //Enter any key to continue and go back to  "Showing_School_Year"
            system("pause");
            cout<<"\n";
        }
    } while (Check_Subject_Duplicated(Subject_Head,Subject_Temp));

    School_Year::Semester::Subject* Subject_Cur = find_Subject(Subject_Head,Subject_Temp);

    //Delete all element
    Delete_Element_Of_Subject(Subject_Cur,2);

    if (Subject_Cur == Subject_Head)
    {
        if (Subject_Cur -> Next == nullptr)
            {
                Subject_Head = nullptr;
                ySemester_Cur -> yearSemesterSubjectHead = Subject_Head;

                system("pause");
                return;
            }

        Subject_Head = Subject_Head -> Next;
        ySemester_Cur -> yearSemesterSubjectHead = Subject_Head;

        system("pause");
        return;
    }

    School_Year::Semester::Subject* Temp_Sub = Subject_Cur;

    Subject_Cur ->  Prev -> Next = Temp_Sub -> Next;

    delete Temp_Sub;

    system("pause");
    return;

}

//View_Semester
void View_Semester(string user_School_Year,School_Year::Semester* &Semester_Head)
{
    //Use a checking var to ignore line
    bool Check_Ignore = false;

    //Show Semster Table
    Showing_Semester:
    if (Semester_Head == nullptr) 
        {
            cout<<"Nothing being added"<<endl;
            system("Pause");
            return ;
        }
            else 
                {
                    Show_Semester_Table(user_School_Year,Semester_Head);
                }
        
        string user_Choose_Temp ="";
        int user_Choose_Semester;
        if (!Check_Ignore) cin.ignore();
    do
    {
            cout<<"Which Semester you want to view info. Ex: 1/2/3"<<endl;
            cout<<"Note: If you dont want to choose any class pls Enter 'N' "<<endl;
            cout<<"Enter answer: ";

            getline(cin,user_Choose_Temp);

        if (user_Choose_Temp == "N") return;

        user_Choose_Semester = atoi ( user_Choose_Temp .c_str());

        //Check if the user choosed Year is existed - True is it not Duplicated which mean the Data is Incorrect
        if (Check_Semester_Duplicated(Semester_Head,user_Choose_Semester)) 
        {
            cout<<"Your input Semester: "<<user_Choose_Semester<<" is Incorrect. Please try again."<<endl;
            
            //Enter any key to continue and go back to  "Showing_School_Year"
            system("pause");
            Check_Ignore = true;
            goto Showing_Semester;
        }
    } while (Check_Semester_Duplicated(Semester_Head,user_Choose_Semester));
    
    //Menu Course
    int user_Choose =  0;
    School_Year::Semester* Semester_Cur = find_Semester(Semester_Head,user_Choose_Semester);
    School_Year::Semester::Subject* Course_Head = Semester_Cur -> yearSemesterSubjectHead;

    while (user_Choose != 5)
    {
        cout<<endl<<endl;

        //Semester Table
        Show_Semester_Table(user_School_Year,Semester_Head);

        if (Course_Head != nullptr)
        {
            Show_Subject_Table(to_string(user_Choose_Semester),Course_Head);
        }

        cout<<"         Wellcome to course registration (Beta Ver)"<<endl;
        cout<<"             1: View Info Course In Semester: "<<user_Choose_Semester<<endl;
        cout<<"             2: Create Course List For Semester: "<<user_Choose_Semester<<endl;
        cout<<"             3: Adjust Course List In Semester: "<<user_Choose_Semester<<endl;
        cout<<"             4: Delete Course In Semester: "<<user_Choose_Semester<<endl;
        cout<<"             5: Back"<<endl;
        cout<<"             Your choice: "; 

        cin>>user_Choose;

        cout<<endl;

        //Switch user choose
        switch (user_Choose)
        {
        //View Course
            case 1:
            {
                //Declare
                    School_Year::Semester* Semester_Cur = find_Semester(Semester_Head,user_Choose_Semester);

                    //Functions View_SV_List
                    View_Course(to_string(user_Choose_Semester), Semester_Cur -> yearSemesterSubjectHead);


                continue;

                break;
            }

        //Create Course
            case 2:
            {
                //Ask user whether he want to import a csv or manual
                    int user_Prefer = 0;
                    cout<<"\t Which one do you prefer: Manual (1) or Quick Import a CSV File (2)"<<endl;
                    cout<<"Your answer: ";
                    cin>>user_Prefer;

                    switch (user_Prefer)
                        {
                        case 1:
                        {
                            //Declare
                            School_Year::Semester* Semester_Cur = find_Semester(Semester_Head,user_Choose_Semester);

                            //Functions Create_SV_List
                            Create_Course_Manual (Semester_Cur,Course_Head);

                            break;
                        }
                        
                        case 2:
                        {
                            //Notice and rule
                            cout<<"To import a CSV there is a rule: Course Id, Course Name, Teacher Name, Number of credits, Maximum student, Day of week (Mon/Tue/..), At time (S1/S2/S3...)"<<endl;
                            sleep_until( system_clock::now() + seconds(1) );
                            cout<<"Notice: If u havent Import in Course_Info.csv, now it's your time! then continue"<<endl;

                            system("pause");

                            //Declare
                            School_Year::Semester* Semester_Cur = find_Semester(Semester_Head,user_Choose_Semester);

                            //Functions Create_SV_List
                            Create_Course_Import (Semester_Cur,Course_Head);

                            break;
                        }
                        
                        default:
                            break;
                        }
                    
                    continue;

                    break;

            }
        
        case 3:
        {

            //Declare
            School_Year::Semester* Semester_Cur = find_Semester(Semester_Head,user_Choose_Semester);

            //Functions Adjust Course
            Adjust_Course(Semester_Cur,Course_Head);

            continue;

            break;
        }

        case 4:
        {

            //Declare
            School_Year::Semester* Semester_Cur = find_Semester(Semester_Head,user_Choose_Semester);

            //Functions Delete Course
            Delete_Course(Semester_Cur,Course_Head);

            continue;

            break;
        }

        default:
            break;
        }
    }
    cout<<"Ending Menu Semester"<<endl;
    system("pause");

}

//Create Semester
void Create_Semester(School_Year* &Year_Cur, School_Year::Semester* &Semester_Head)
{
    //Declare
    int user_input = 0;
    School_Year::Semester* Semester_Cur = Semester_Head;

    //Case head == null
    if (Semester_Head == nullptr)
    {
        //Input
        do
        {
            cout<<"Remember, there are only 3 semster per School Year. If you want to back, Enter 0"<<endl;
            cout<<"Enter term (1/2/3): ";
            cin>>user_input;

            cout<<endl;

            if (user_input == 0) 
            {
                system("pause");
                return;
            }

            if (!Check_Semester_Duplicated(Semester_Head,user_input)) 
            cout<<"Your data has been duplicated. Pls retry."<<endl<<endl;

        } while (!Check_Semester_Duplicated(Semester_Head,user_input));

        Semester_Head = new School_Year::Semester;
        Semester_Head -> Term = user_input;

        cin.ignore();
        cout<<"Enter Start Date For This Semester: "; 
        getline(cin,Semester_Head -> start_Date);
        cout<<"Enter End Date For This Semester: "; 
        getline(cin,Semester_Head -> end_Date);

        Year_Cur -> yearSemesterHead = Semester_Head;

        return;
    }


    while (Semester_Cur -> Next != nullptr) Semester_Cur = Semester_Cur -> Next;

    //Input
        do
        {
            cout<<"Remember, there are only 3 semster per School Year."<<endl;
            cout<<"Enter term (1/2/3): ";
            cin>>user_input;

            cout<<endl;
            if (!Check_Semester_Duplicated(Semester_Head,user_input)) 
            cout<<"Your data has been duplicated. Pls retry."<<endl<<endl;

        } while (!Check_Semester_Duplicated(Semester_Head,user_input));

    //One school year only contain 3 semester
     if (Check_Num_Semester(Semester_Head) == 3) 
        {
            cout<<"There enough 3 semester in this school year. Thanks";
            system("pause");
            return;
        }

    Semester_Cur -> Next = new School_Year::Semester;
    Semester_Cur -> Next -> Prev = Semester_Cur;
    Semester_Cur = Semester_Cur -> Next;
    Semester_Cur -> Term = user_input;

    //Adding Start date, End Date
    cin.ignore();
    cout<<"Enter Start Date For This Semester: "; 
    getline(cin,Semester_Cur -> start_Date);
    cout<<"Enter End Date For This Semester: "; 
    getline(cin,Semester_Cur -> end_Date);

    return;
}

//Adjust Semster
void Adjust_Semester(School_Year* Year_Cur, School_Year::Semester* &Semester_Head)
{
    if (Semester_Head == nullptr)
    {
        cout<<"There are nothing to be adjusted. Please Create One.";
        system("pause");
        return;
    }

    Show_Semester_Table(Year_Cur -> year, Semester_Head);

    string user_Choose_Semester = "";
    cin.ignore();
    do
    {
        cout<<"Which Semester you want to Adjust. Ex: 1/2/3 "<<endl;
        cout<<"Note: If you dont want to choose any Term pls Enter 'N' "<<endl;
        cout<<"Enter answer: "; 
        getline(cin,user_Choose_Semester);

        if (user_Choose_Semester == "N") return;

        if (Check_Semester_Duplicated( Semester_Head,stoi(user_Choose_Semester) )) 
        {
            cout<<"Your input Semester: "<<user_Choose_Semester<<" is Incorrect. Please try again."<<endl;
            
            //Enter any key to continue and go back to  "Showing_School_Year"
            system("pause");
            cout<<"\n";
        }

    } while (Check_Semester_Duplicated( Semester_Head,stoi(user_Choose_Semester) ));

    cout<<endl;
    School_Year::Semester* Semester_Cur = find_Semester(Semester_Head,stoi(user_Choose_Semester));

    do
    {
        Changes_Term:
        Show_Semester_Table(Year_Cur -> year, Semester_Head);
        
        cout<<"What do you want to change from "<<user_Choose_Semester<<" to ?. Ex: Semester 1 -> Semester 2"<<endl;
        cout<<"Note: There are only 3 semester from 1 -> 3. If you dont want to change pls Enter 'N' "<<endl;
        cout<<"Enter answer: ";

        getline(cin,user_Choose_Semester);

        if (user_Choose_Semester == "N") return;

        if (stoi(user_Choose_Semester) < 1 || stoi(user_Choose_Semester) > 3 ) 
        {
            cout<<"Your input Semester: "<<user_Choose_Semester<<" is Incorrect. Please try again."<<endl;
            
            //Enter any key to continue and go back to  "Showing_School_Year"
            system("pause");
            cout<<"\n";
            goto Changes_Term;
        }

        if (!Check_Semester_Duplicated(Semester_Head,stoi(user_Choose_Semester) )) 
        {
            cout<<"Your input Semester: "<<user_Choose_Semester<<" is Incorrect. Please try again."<<endl;
            
            //Enter any key to continue and go back to  "Showing_School_Year"
            system("pause");
            cout<<"\n";
        }
    } while (!Check_Semester_Duplicated(Semester_Head,stoi(user_Choose_Semester)));
    
    Semester_Cur -> Term = stoi(user_Choose_Semester);

    string user_Answer;
    cout<<"Wanna change Start Date, End Date of new Term? Enter (Y/N): ";
    getline(cin,user_Answer);
    
    if (user_Answer == "N") 
    {
        cout<<"\n";
        cout<<"Change Success"<<endl;

        system("pause");
        return;
    }

    cout<<"\nEnter Start Date: ";
    getline(cin,Semester_Cur -> start_Date);
    cout<<"\nEnter End Date: ";
    getline(cin,Semester_Cur -> end_Date);

    cout<<"\n";
    cout<<"Change Success"<<endl;

    system("pause");
    return;
}

//Delete Semster
void Delete_Semester(School_Year* &sYear_Cur, School_Year::Semester* &Semester_Head)
{
    if (Semester_Head == nullptr)
    {
        cout<<"There are nothing to be deleted. Please Create One.";
        system("pause");
        return;
    }

    Show_Semester_Table(sYear_Cur -> year, Semester_Head);
    
    string user_Choose_Semester = "";
        
        cin.ignore();
    do
    {
        //Menu of User choice about School-Year they want to view
            cout<<"Which Semester you want to Delete. Ex: 1/2/3"<<endl;
            cout<<"Note: If you dont want to choose any Semester pls Enter 'N' "<<endl;
            cout<<"Enter answer: ";

            getline(cin,user_Choose_Semester);

        if (user_Choose_Semester == "N") return;

        //Check if the user choosed Year is existed - True is it not Duplicated which mean the Data is Incorrect
        if (Check_Semester_Duplicated(Semester_Head,stoi(user_Choose_Semester))) 
        {
            cout<<"Your input Semester: "<<user_Choose_Semester<<" is Incorrect. Please try again."<<endl;
            
            //Enter any key to continue and go back to  "Showing_School_Year"
            system("pause");
            cout<<endl;
        }

    } while (Check_Semester_Duplicated(Semester_Head,stoi(user_Choose_Semester)));

    School_Year::Semester* Semester_Cur = find_Semester(Semester_Head,stoi(user_Choose_Semester));

    //Delete all element
    Delete_Element_Of_Semester(Semester_Cur,2);

    if (Semester_Cur == Semester_Head)
    {
        if (Semester_Cur -> Next == nullptr)
            {
                Semester_Head = nullptr;
                sYear_Cur -> yearSemesterHead = Semester_Head;
                system("pause");
                return;
            }

        Semester_Head = Semester_Head -> Next;
        sYear_Cur -> yearSemesterHead = Semester_Head;
        system("pause");
        return;
    }

    School_Year::Semester* Temp_Semester = Semester_Cur;

    Semester_Cur ->  Prev -> Next = Temp_Semester -> Next;

    delete Temp_Semester;

    system("pause");

    return;
}

//View Year - ╰(*°▽°*)╯ 
//This contain Menu Classes of SChool-Year
void View_Year(School_Year* &sYear_Head)
{
    //Use a checking var to ignore line
    bool Check_Ignore = false;

    Showing_School_Year:
    //At first check if empty or not - ✔
    if (!Check_School_Year(sYear_Head)) 
        {
            cout<<"Nothing being added"<<endl;
            system("pause");
            return ;
        }
            else 
                {
                    Show_Year_Table(sYear_Head);
                }

    //Next step
        string user_choosed_Year = "";
        
        if (!Check_Ignore) cin.ignore();
    do
    {
        //Menu of User choice about School-Year they want to view
            cout<<"Which School-Year you want to view info. Ex: 2021-2022"<<endl;
            cout<<"Note: If you dont want to choose any year pls Enter 'N' "<<endl;
            cout<<"Enter answer: ";

            getline(cin,user_choosed_Year);

        if (user_choosed_Year == "N") return;

        //Declare
        const char* denim = "-"; //Use strtok - 👍
        char* temp = new char [user_choosed_Year.size()];

        // But it neeeded to convert string -> char* - 🔑
        strcpy(temp,user_choosed_Year.c_str());
        user_choosed_Year = strtok(temp, denim);

        //Check if the user choosed Year is existed - True is it not Duplicated which mean the Data is Incorrect
        if (Check_Year_Duplicated(sYear_Head,user_choosed_Year)) 
        {
            cout<<"Your input school-year: "<<user_choosed_Year<<" is Incorrect. Please try again."<<endl;
            
            //Enter any key to continue and go back to  "Showing_School_Year"
            system("pause");
            Check_Ignore = true;
            goto Showing_School_Year;
        }

    } while (Check_Year_Duplicated(sYear_Head,user_choosed_Year));
    


    //Menu for classes in specific school-year - 📲
    int user_Choose = 0;
    School_Year* sYear_Cur = find_School_Year(sYear_Head,user_choosed_Year); // To locate the school year user is choosing
    School_Year::Year_Class* Classes_Head = sYear_Cur -> yearCLassHead; // To view or create. First is Declare
    School_Year::Semester* Semester_Head = sYear_Cur -> yearSemesterHead; //To view or create. First is Declare

    while (user_Choose != 9)
    {
        cout<<endl<<endl;

        //School year table
        Show_Year_Table(sYear_Head);

        //Classes table
        if (Classes_Head != nullptr && (user_Choose == 1 || user_Choose == 2 || user_Choose == 3 || user_Choose == 4) )
        {
            Show_Classes_Table(user_choosed_Year,Classes_Head);
        }
        
        //Semester table
        if (Semester_Head != nullptr && (user_Choose == 5 || user_Choose == 6 || user_Choose == 7 || user_Choose == 8) )
        {
            Show_Semester_Table(user_choosed_Year,Semester_Head);
        }

        cout<<"         Wellcome to course registration (Beta Ver)"<<endl;
        cout<<"             1: View Info Classes in School-Year: "<<atoi(user_choosed_Year.c_str())<<"-"<<atoi(user_choosed_Year.c_str()) + 1<<endl;
        cout<<"             2: Create 1st Year Classes For: "<<atoi(user_choosed_Year.c_str())<<"-"<<atoi(user_choosed_Year.c_str()) + 1<<endl;
        cout<<"             3: Adjust A Class In School - Year: "<<atoi(user_choosed_Year.c_str())<<"-"<<atoi(user_choosed_Year.c_str()) + 1<<endl;
        cout<<"             4: Delete A Class In School - Year: "<<atoi(user_choosed_Year.c_str())<<"-"<<atoi(user_choosed_Year.c_str()) + 1<<endl;
        cout<<"             5: View Info Specific Semesters in School-Year: "<<atoi(user_choosed_Year.c_str())<<"-"<<atoi(user_choosed_Year.c_str()) + 1<<endl;
        cout<<"             6: Create Semesters For: "<<atoi(user_choosed_Year.c_str())<<"-"<<atoi(user_choosed_Year.c_str()) + 1<<endl;
        cout<<"             7: Adjust Semester For: "<<atoi(user_choosed_Year.c_str())<<"-"<<atoi(user_choosed_Year.c_str()) + 1<<endl;
        cout<<"             8: Delete Semester For: "<<atoi(user_choosed_Year.c_str())<<"-"<<atoi(user_choosed_Year.c_str()) + 1<<endl;
        cout<<"             9: Back"<<endl;
        cout<<"             Your choice: "; 

        cin>>user_Choose;

        cout<<endl;

        //Switch user_Choose
            switch (user_Choose)
            {
                //View Classes 
                case 1:
                {
                    //Declare
                    School_Year* sYear_Cur = find_School_Year(sYear_Head,user_choosed_Year);

                    //Functions View_Classes
                    View_Classes(user_choosed_Year,sYear_Cur -> yearCLassHead);

                    continue;

                    break;
                }

                //Create Classes
                case 2:
                {
                    //Declare
                    School_Year* sYear_Cur = find_School_Year(sYear_Head,user_choosed_Year);

                    //Functions Create_Classes
                    Create_Classes(sYear_Cur,Classes_Head);
                    
                    continue;

                    break;
                }
                
                //Adjust
                case 3:
                {
                    //Declare
                    School_Year* sYear_Cur = find_School_Year(sYear_Head,user_choosed_Year);

                    //Functions Adjust_Classes
                    Adjust_Classes(sYear_Cur,Classes_Head);

                    continue;

                    break;
                }

                //Delete
                case 4:
                {
                    //Declare
                    School_Year* sYear_Cur = find_School_Year(sYear_Head,user_choosed_Year);

                    //Functions Delete_Classes
                    Delete_Classes(sYear_Cur,Classes_Head);

                    continue;

                    break;
                }

                //View Semester
                case 5:
                {
                    //Declare
                    School_Year* sYear_Cur = find_School_Year(sYear_Head,user_choosed_Year);

                    //Functions View_Semester
                    View_Semester(user_choosed_Year,Semester_Head);

                    continue;

                    break;
                }

                //Create Semester
                case 6:
                {
                    //Declare
                    School_Year* sYear_Cur = find_School_Year(sYear_Head,user_choosed_Year);

                    //Functions Create Semester
                    Create_Semester(sYear_Cur,Semester_Head);
                    
                    continue;

                    break;
                }
                
                //Adjust Semester
                case 7:
                {
                    //Declare
                    School_Year* sYear_Cur = find_School_Year(sYear_Head,user_choosed_Year);

                    //Functions Adjust Semester
                    Adjust_Semester(sYear_Cur,Semester_Head);
                    
                    continue;

                    break;
                }

                //Delete Semester
                case 8:
                {
                    //Declare
                    School_Year* sYear_Cur = find_School_Year(sYear_Head,user_choosed_Year);

                    //Functions Adjust Semester
                    Delete_Semester(sYear_Cur,Semester_Head);
                    
                    continue;

                    break;
                }

                default:

                    break;
            }

    }

    cout<<"Ending Menu Classes..."<<endl;
    system("pause");
    
    //End of this funcs
    return;
}

//Create Year - ヾ(≧▽≦*)o
void Create_Year(School_Year* &sYear_Head)
{
    //Declareed
    string user_input = "";
    School_Year* sYear_Cur = sYear_Head;

    //Check if sYear_Head empty for create new at first
            if (sYear_Head == nullptr) 
            {
                sYear_Head = new School_Year;
                
                //Input
                cout<<"Enter School-Year (Ex: 2020-2021 or just 2021) : ";
                cin.ignore();
                getline(cin,user_input);
                
                //Convert string -> char*
                char* input = new char [user_input.size()];
                strcpy( input,user_input.c_str() );

                //Strtok
                const char* denim = "-";
                sYear_Head -> year = strtok(input,denim);

                return;
            }

        //Check if value is being duplicated or not?
        char* contain = "";
        cin.ignore();
        do
        {
            //Input
            cout<<"Enter School-Year (Ex: 2020-2021) : ";
            // cin.ignore();
            getline(cin,user_input);
            
            //Convert string -> char*
            char* input = new char [user_input.size()];
            strcpy( input,user_input.c_str() );

            //Strtok
            const char* denim = "-";
            contain = strtok(input,denim);

            //Print out remind user to enter value again
            if (!Check_Year_Duplicated(sYear_Head,contain)) cout<<"Your data has been duplicated. Pls retry"<<endl<<endl;

        } while ( !Check_Year_Duplicated(sYear_Head,contain) );

        //Check if Next year is havent existed
            while (sYear_Cur -> Next != nullptr) sYear_Cur = sYear_Cur -> Next;
            
            //Create Next Year and dont forget save the Prev
            sYear_Cur -> Next = new School_Year;
            sYear_Cur -> Next -> Prev = sYear_Cur;
            sYear_Cur = sYear_Cur -> Next;
        
        sYear_Cur -> year = contain;

        return;
}

//Adjust Year
void Adjust_Year(School_Year* &sYear_Head)
{
    if (sYear_Head == nullptr)
    {   
        cout<<"There are nothing to be adjusted. Please Create One.";
        system("pause");
        return;
    }

    bool Check_Ignore = false;
    string user_choosed_Year = "";
        
        if (!Check_Ignore) cin.ignore();
    do
    {
        //Menu of User choice about School-Year they want to view
            cout<<"Which School-Year you want to Adjust. Ex: 2021-2022 or 2021"<<endl;
            cout<<"Note: If you dont want to choose any year pls Enter 'N' "<<endl;
            cout<<"Enter answer: ";

            getline(cin,user_choosed_Year);

        if (user_choosed_Year == "N") return;

        //Declare
        const char* denim = "-"; //Use strtok - 👍
        char* temp = new char [user_choosed_Year.size()];

        // But it neeeded to convert string -> char* - 🔑
        strcpy(temp,user_choosed_Year.c_str());
        user_choosed_Year = strtok(temp, denim);

        //Check if the user choosed Year is existed - True is it not Duplicated which mean the Data is Incorrect
        if (Check_Year_Duplicated(sYear_Head,user_choosed_Year)) 
        {
            cout<<"Your input school-year: "<<user_choosed_Year<<" is Incorrect. Please try again."<<endl;
            
            //Enter any key to continue and go back to  "Showing_School_Year"
            system("pause");
            cout<<"\n";
            Check_Ignore = true;
        }
    } while (Check_Year_Duplicated(sYear_Head,user_choosed_Year));

    cout<<"\n";
    School_Year* Year_Cur = find_School_Year(sYear_Head,user_choosed_Year);

    do
    {
        //Menu of User choice about School-Year they want to view
            cout<<"What do you want to change from "<<atoi((Year_Cur -> year).c_str()) << " - " << atoi((Year_Cur -> year).c_str()) + 1  <<" to ?. Ex: 2021-2022 -> 2022-2023"<<endl;
            cout<<"Note: If you dont want to change pls Enter 'N' "<<endl;
            cout<<"Enter answer: ";

            getline(cin,user_choosed_Year);

        if (user_choosed_Year == "N") return;

        //Declare
        const char* denim = "-"; //Use strtok - 👍
        char* temp = new char [user_choosed_Year.size()];

        // But it neeeded to convert string -> char* - 🔑
        strcpy(temp,user_choosed_Year.c_str());
        user_choosed_Year = strtok(temp, denim);

        //Check if the user choosed Year is existed - True is it not Duplicated which mean the Data is Incorrect
        if (!Check_Year_Duplicated(sYear_Head,user_choosed_Year)) 
        {
            cout<<"Your input school-year: "<<user_choosed_Year<<" is Incorrect. Please try again."<<endl;
            
            //Enter any key to continue and go back to  "Showing_School_Year"
            system("pause");
            cout<<"\n";
            Check_Ignore = true;
        }
    } while (!Check_Year_Duplicated(sYear_Head,user_choosed_Year));

    //Assigned
    Year_Cur -> year = user_choosed_Year;

    cout<<"\n";
    cout<<"Change Success";

    system("pause");
    return;
}

//Delete a Year
void Delete_Year(School_Year* &sYear_Head)
{
    if (sYear_Head == nullptr)
    {   
        cout<<"There are nothing to be deleted. Please Create One.";
        system("pause");
        return;
    }

    bool Check_Ignore = false;
    string user_choosed_Year = "";
        
        if (!Check_Ignore) cin.ignore();
    do
    {
        //Menu of User choice about School-Year they want to view
            cout<<"Which School-Year you want to Delete. Ex: 2021-2022 or 2021"<<endl;
            cout<<"Note: If you dont want to choose any year pls Enter 'N' "<<endl;
            cout<<"Enter answer: ";

            getline(cin,user_choosed_Year);

        if (user_choosed_Year == "N") return;

        //Declare
        const char* denim = "-"; //Use strtok - 👍
        char* temp = new char [user_choosed_Year.size()];

        // But it neeeded to convert string -> char* - 🔑
        strcpy(temp,user_choosed_Year.c_str());
        user_choosed_Year = strtok(temp, denim);

        //Check if the user choosed Year is existed - True is it not Duplicated which mean the Data is Incorrect
        if (Check_Year_Duplicated(sYear_Head,user_choosed_Year)) 
        {
            cout<<"Your input school-year: "<<user_choosed_Year<<" is Incorrect. Please try again."<<endl;
            
            //Enter any key to continue and go back to  "Showing_School_Year"
            system("pause");
            Check_Ignore = true;
        }

    } while (Check_Year_Duplicated(sYear_Head,user_choosed_Year));


    School_Year* Year_Cur = find_School_Year(sYear_Head,user_choosed_Year);

    //Save for tommorrow
    Delete_Element_Of_Year(Year_Cur);

    if (Year_Cur == sYear_Head && Year_Cur -> Next == nullptr)
    {
        sYear_Head = nullptr;
        system("pause");
        return;
    }
    else if (Year_Cur == sYear_Head && Year_Cur -> Next != nullptr) 
        {
            sYear_Head = sYear_Head -> Next;
            sYear_Head -> Prev = nullptr;
            system("pause");
            return;
        }

    School_Year* Temp_Year = Year_Cur;

    Year_Cur -> Prev -> Next = Temp_Year -> Next;

    delete Temp_Year;

    system("pause");
    return;
}

//Menu School Year - ✍(◔◡◔)
void Menu_School_Year(School_Year* &sYear_Head)
{
    //First we need to clear screen and ask user which one they want to choose
    int user_Choose = 0;
    while (user_Choose != 5)
    {
        system("CLS");
        if (sYear_Head != nullptr)
        {
            Show_Year_Table(sYear_Head);
        }
        cout<<"         Wellcome to course registration (Beta Ver)"<<endl;
        cout<<"             1: View info of a School - Year"<<endl;
        cout<<"             2: Create New School - Year"<<endl;
        cout<<"             3: Adjust A School - Year"<<endl;
        cout<<"             4: Delete A School - Year"<<endl;
        cout<<"             5: Back"<<endl;
        cout<<"             Your choice: "; 
        cin>>user_Choose;
        cout<<endl;

        //Better use switch
        switch (user_Choose)
        {
        
            case 1:
            {
                //In view Year there is a menu of classes
                View_Year(sYear_Head);

                continue;

                break;
            }

            case 2:
            {
                Create_Year(sYear_Head);

                continue;

                break;
            }
            
            case 3:
            {
                Adjust_Year(sYear_Head);

                continue;

                break;
            }

            case 4:
            {
                Delete_Year(sYear_Head);

                continue;

                break;
            }
            default:
                system("pause");
                break;
        }

    }

    cout<<"Ending Menu School-Year"<<endl;

    return ;
}