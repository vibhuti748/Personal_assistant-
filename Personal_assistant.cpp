#include <iostream>
#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <ctime>
#include <time.h>
#include <fstream>
#include <cstdio>

using namespace std;


class assistant
{
public :
    void typing(string t);
    void speak(string s);
};

assistant a;


//---------------typing function--------------
void assistant::typing(string t)
{
     speak(t);//----------for speaking the text

     cout<<"\n\n";
  for (int i = 0; t[i] != '\0'; i++)
  {

    cout << t[i];
    Sleep(65);
  }

}

void assistant :: speak(string s)
{
  ofstream file;
  file.open("speak.vbs", ios::out);
  file << "dim s";
  file << "\nset s = createObject(\"sapi.spvoice\")";
  file << "\ns.speak \"" << s << "\"";
  file.close();
  system("start speak.vbs");
  Sleep(300);
}

void wishme()
{
      time_t now = time(0);
    tm *time = localtime(&now);

    if (time-> tm_hour < 12)
        {
        a.typing("Good Morning Vibhuti ! How can I help you ?");

    }

    else if (time-> tm_hour >= 12 && time->tm_hour <= 16)
        {
        a.typing("Good Afternoon Vibhuti ! How can I help you ?");



    }

    else if (time-> tm_hour > 16 && time->tm_hour < 24)
        {
        a.typing("Good Evening Vibhuti ! How can I help you ?");



    }
}


int main()
{

    char ch[100];

      wishme();






              cout<<"\n\n******************************** Your Assistant *************************************** \n\n";
             
              time_t now = time(0);
                        char *dt = ctime(&now);
                        cout<<"\n\nThe date and time is "<< dt <<endl;
              cout<<"********************************************************************************************\n\n==>  ";


     while(1)
     {

            gets(ch);


            STARTUPINFO startInfo = {};
            PROCESS_INFORMATION processInfo = {};



            if(strcmp(ch, "open google")==0)
          {
            string s="https://www.google.co.in/";


            a.typing( "opening google in chrome browser");
            cout<<"\n\n";


            ShellExecute(NULL,"open",s.c_str(),NULL,NULL,SW_SHOWNORMAL);
          }



          else if(strcmp(ch, "search google")==0)
          {
             char text[100];
             string res;
             string g="https://www.google.com/search?q=";




             a.typing( "Enter what do you want to search : ");
             gets(text);

             res=g+text;


             a.typing( "searching in google");
             cout<<"\n\n";



              ShellExecute(NULL,"open",res.c_str(),NULL,NULL,SW_SHOWNORMAL);

          }



          else if(strcmp(ch, "open youtube")==0)

          {
               string n = "https://www.youtube.com/";


             a.typing( "Opening youtube in chrome browser");
             cout<<"\n\n";


            ShellExecute(NULL,"open",n.c_str(),NULL,NULL,SW_SHOWNORMAL);

          }



           else if(strcmp(ch, "search youtube")==0)
          {
             char text1[100];




             a.typing( "Enter what you want to search : ");
             gets(text1);

             string s;
             string res1="https://www.youtube.com/results?search_query=";

             s=res1+text1;



             a.typing( "Searching on Youtube .....");
             cout<<"\n\n";

              ShellExecute(NULL,"open",s.c_str(),NULL,NULL,SW_SHOWNORMAL);


        }
         else if(strcmp(ch, "open notepad")==0)
        {


             a.typing( "Opening Notepad .....");
             cout<<"\n\n";

            CreateProcess(TEXT("C:\\Windows\\notepad.exe"),NULL, NULL,NULL,FALSE,NULL,NULL, NULL, &startInfo, &processInfo);
        }
         else if(strcmp(ch, "play rimjhim")==0)
        {


             a.typing( "Playing \"Rimjhim\" .....");
             cout<<"\n\n";

            ShellExecute(NULL,"open","D:\Rimjhim Gire Sawan (Male) - Manzil (1977) 128 Kbps.mp3",NULL,NULL,SW_SHOWNORMAL);
        }

         else if(strcmp(ch, "play maahi ve")==0)
        {


             a.typing( "Playing \"Maahi ve\" .....");
             cout<<"\n\n";

            ShellExecute(NULL,"open","D:\Maahi Ve Highway 128 Kbps.mp3",NULL,NULL,SW_SHOWNORMAL);

        }
         else if(strcmp(ch, "search song")==0)
        {
             char text[100];
             string res1;
             string e="https://open.spotify.com/search/";

             a.typing( "Enter song name : ");
             gets(text);

             res1=e+text;

             system("cls");
             a.typing( "Searching on browser for song .....");
             cout<<"\n\n";



              ShellExecute(NULL,"open",res1.c_str(),NULL,NULL,SW_SHOWNORMAL);

        }
         else if(strcmp(ch, "bye") == 0 || strcmp(ch, "stop") == 0 || strcmp(ch, "exit") == 0 )
        {
             system("cls");
             a.typing("Have a nice day Vibhuti, thank you !!");
             exit(0);

        }

         else if(strcmp(ch, "hi") == 0 || strcmp(ch, "hello") == 0 || strcmp(ch, "how are you") == 0 )
        {

             a.typing( "Hello Vibhuti, glad to see you ! I am your personal assistant, made to help you in simple ways ! Tell me what can I do for you ?");
             cout<<"\n\n";


        }
         else if(strcmp(ch, "time") == 0 || strcmp(ch, "date") == 0)
        {
             a.typing( "the time and date is on top of the application");
             cout<<"\n\n";

        }
         else
        {

             a.typing( "Pardon Vibhuti, Invalid command !!");
             cout<<"\n\n";
        }



     }



    return 0;
}