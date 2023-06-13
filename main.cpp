#include<conio.h>
#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
void view_recently_played();
vector<int>recently_played;
vector<int>fav_playlist;
void view_fav_playlist();
class songs_data
{
           public:
                        int id;
                        string s_name,s_artist;
};
class songs
{
           public:
                        songs_data obj;
                        songs* next;
};
class alphabets
{
           public:
                        int cnt;
                        char ch;
                        songs* headIn;
                        alphabets()
                        {
                                   headIn=NULL;
                                   cnt=0;
                        }
};
class Register
{
    char f_name[10],l_name[10],password[20],u_name[20];
    public :
        bool tag;
        void signup();
        void Login();
};

songs* insert_node(songs* head,songs* newnode)
{
           if(head==NULL)
                      return newnode;
           else
           {
                      songs* ptr=head;
                      while(ptr->next!=NULL)
                                 ptr=ptr->next;
                      ptr->next=newnode;
                      return head;
           }
}
void print(songs* head)
{
           songs *temp;
           temp=head;
           while(temp!=NULL)
           {
                      cout<<temp->obj.id<<"\t\t"<<temp->obj.s_name<<"\t\t"<<temp->obj.s_artist<<"\n";
                      temp=temp->next;
           }
}
void feedback()
{
           int n;
           string text;;
           cout<<"\n\t\t*-*-*-*-*-*-*-*-FEEDBACK-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n";
           cout<<"\n\t\tWould you like to rate us(No. of stars)\n\t\t";
           cout<<"\n\t\t*     --> Very Bad :(";
           cout<<"\n\t\t**    --> Okay but needs improvement :(";
           cout<<"\n\t\t***   --> Good ";
           cout<<"\n\t\t****  --> Very Good :)";
           cout<<"\n\t\t***** --> AWESOME...Loved it ;)";
           STARS:cout<<"\n\t\tEnter the no. of stars you would like to give us:";
           cin>>n;
           cout<<"\t\t";
           for(int i=0;i<n;i++)
           {
                      if(n>5)
                      {
                                 cout<<"\n\t\tPlease rate us on the basis of five star rating system:)\n";
                                 goto STARS;
                      }
                      cout<<"*";
           }
           cout<<"\n\t\tWe would greatly appreciate it if you kindly give us some feedback\n\t\t";
           getline(cin,text);
           getline(cin,text);
}
void Register::signup()
{
    system("clear");
    cout<<"\tSIGN-UP";
    cout<<"\n\t--------";
    int p=0,q=0,r=0;
    a1:
    cout<<"\nEnter your First_name : ";
    cin>>f_name;
    for(int i=0;f_name[i]!='\0';i++)
    {
    if(!(f_name[i]>='a'&&f_name[i]<='z'||f_name[i]>='A'&&f_name[i]<='Z'))
    {
        p=1;
        break;
    }
    }
    if(p==1)
    {
        cout<<"\nInvalid First Name!!Enter only alphabets...";
        p=0;
        goto a1;
    }
    a2:
    cout<<"\nEnter your Last_name : ";
    cin>>l_name;
    for(int i=0;l_name[i]!='\0';i++)
    {
    if(!(l_name[i]>='a'&&l_name[i]<='z'||l_name[i]>='A'&&l_name[i]<='Z'))
    {
        q=1;
        break;
    }
    }
    if(q==1)
    {
        cout<<"\nInvalid Last Name!!Enter only alphabets...";
        q=0;
        goto a2;
    }
    a3:
    cout<<"\nEnter a valid username (only characters allowed) : ";
    cin>>u_name;
    for(int i=0;u_name[i]!='\0';i++)
    {
    if(!(u_name[i]>='a'&&u_name[i]<='z'||u_name[i]>='A'&&u_name[i]<='Z'))
    {
        cout<<"\nInvalid Username!!Enter only characters...";
        goto a3;
    }
    }
    cout<<"\nSet your Password : ";
    cin>>password;
    std::ofstream myfile;
    myfile.open("Quaver.txt",ios::app);
            if (myfile.is_open()) 
            {
                myfile<<"\nNAME : "<<f_name<<" "<<l_name<<"\tUsername : "<<u_name<<"\tPASSWORD : "<<password<<"\n\n";
                myfile.close(); 
                cout<<"\nSIGN-UP SUCCESSFULL...";
                cout<<"\nEnter any key to go back to the main page...";
                cin.get();
                cin.get();
                
            }
            else 
            cout<<"Could not write to file..."; 
    
}

void Register::Login()
{
    system("clear");
    char user_name[20],pass[20];
    cout<<"\tLOGIN";
    cout<<"\n\t-----";
    cout<<"\nEnter your Username : ";
    cin>>user_name;
    cout<<"\nEnter your Password : ";
    cin>>pass;
    cin.get();
    ifstream fin;
    int a=0;
    fin.open("Quaver.txt",ios::in);
    if (fin.is_open()) 
        {
            string line,word;
            while (getline(fin,line)) 
            {
                while(fin>>word)
                {
                    if(user_name==word)
                    {
                        a=1;
                        break;
                    }
                }
                if (a==1)
                {
                   while(fin>>word && word!="\n")
                {
                    if(pass==word)
                    {
                        a=2;
                        break;
                    }
                }
                
                }
                if(a==2)
                {
                    break;
                }
            }
            fin.close();
            if(a==2)
            {
                cout<<"\nLOGIN SUCCESSFULL...";
                tag=1;
                
            }
            else 
            cout<<"\nINVALID USER!! TRY AGAIN...YOU NEED TO SIGN-UP FIRSTLY";
            cin.get();
        }
        else
        {
            cout<<"No records found...";
            cout <<"\nUnable to open file";
            cout<<"\nTry to Sign-up firstly...";
        }
}
void exit_program()
{
           cout<<"\n========================================>";
           cout<<"\nTHANK YOU :))";
           cout<<"\nDeveloped by:----->Devika Gupta";
           cout<<"\n========================================>";
           exit(0);
}
int search_by_id(songs* head,int num)
{
           int k=0;
           char s,x;
           songs *temp;
           temp=head;
           while(temp!=NULL)
           {
                      if(temp->obj.id==num)
                      {
                                 k=1;
                                 break;
                      }
                      temp=temp->next;
           }
           if(k==1)
           {          cout<<"\nSong Detected!!";
                      cout<<"\n Do you want to add this song to your favourite playlist??";
                      cin>>x;
                      if(x=='Y' || x=='y')
                                 fav_playlist.push_back(head->obj.id);
                      else
                                 cout<<"No problem :))";
                      cout<<"\nDo you want to play this song(y/n):";
                      cin>>s;
                      if(s=='Y' || s=='y')
                                 {cout<<"Played :))";
                                 recently_played.push_back(head->obj.id);
                                 }
                      else
                                 cout<<"No problem :))";
           }
           else
           cout<<"\nSearching alphabetically...";
           return k;
}

int search_by_sname(songs* head,string str)
{
           int k=0;
           char s,x;
           songs *temp;
           temp=head;
           while(temp!=NULL)
           {
                      if(temp->obj.s_name==str)
                      {
                                 k=1;
                                 break;
                      }
                      temp=temp->next;
           }
           if(k==1)
           {
                      cout<<"\nSong Detected!!";
                      if(x=='Y' || x=='y')
                                 fav_playlist.push_back(head->obj.id);
                      else
                                 cout<<"No problem :))";
                      cout<<"\nDo you want to play this song(y/n):";
                      cin>>s;
                      if(s=='Y' || s=='y')
                                {cout<<"Played :))";
                                recently_played.push_back(head->obj.id);
                                }
                      else
                                 cout<<"No problem :))";
           }
           else 
           cout<<"\nSearching alphabetically...";
           return k;
}


void view_recently_played()
{
            char ch;
            vector<int>::iterator it=recently_played.begin();
            if(recently_played.empty())
                cout<<"\nNo songs played till now!!!\n Please play songs first!!!";
            else
            {
                for(;it!=recently_played.end();it++)
                {
                    cout<<"\nSong with ID : "<<*it<<" is in your recently played list...";
                }
            }
            cout<<"\nDo you want to play the recently played songs(Y-Yes/N-No)?:";
            cin>>ch;
            while(ch=='y'||ch=='Y')
            {
                for(it=recently_played.begin();it!=recently_played.end();it++)
                {
                    cout<<"\nSong with ID : "<<*it<<" is getting played!!\n";
                }
                cout<<"\nDo you want to play the recently played songs again(Y-Yes/N-No)?:";
                cin>>ch;
            }
}


void view_fav_playlist()
{
            char a;
            vector<int>::iterator xyz=fav_playlist.begin();
            if(fav_playlist.empty())
                cout<<"\nNo songs added to favourite playlist till now!!!\n Please add some songs first!!!";
            else
            {
                for(;xyz!=fav_playlist.end();xyz++)
                {
                    cout<<"\nSong with ID: "<<*xyz<<" is in your favourite playlist...";
                }
            }
            cout<<"\nDo you want to play the favorite song's playlist??(Y-Yes/N-No)?:";
            cin>>a;
            while(a=='y'||a=='Y')
            {
                for(xyz=fav_playlist.begin();xyz!=fav_playlist.end();xyz++)
                {
                    cout<<"\n"<<*xyz<<" song is getting played !!";
                }
                cout<<"\nDo you want to play the favourite songs again??(Y-Yes/N-No)?:";
                cin>>a;
            }
}




int flag=0;
int main()
{
           int num=0,x;
           int alpha;
           char ch2;
           string sname,sartist;
           alphabets head[26];
           Register r;
           char ch1='A';
           for(int i=1;i<=26;i++)
           {
                      head[i].ch=ch1;
                      ch1++;
           }
           while(1)
           {
                      start:
                      system("clear");
                      cout<<"|======================================================================================================================|";
                      cout<<"\n|----------------------------------||*||*||*||*|| MUSIC LIBRARY SYSTEM ||*||*||*||*||----------------------------------|";
                      cout<<"\n|======================================================================================================================|";
                      cout<<"\n\nUSE:\n1.Sign-Up\n2.Insert Songs into Directory\n3.Login\n4.Exit";
                      cout<<"\nEnter your choice:";
                      cin>>alpha;
                      switch(alpha)
                      {
                                 case 2:{     system("clear");
                                              cout<<"\nSONGS INSERTION";
                                              cout<<"\n----------------\n";
                                              int j=1,p;
                                              flag=1;
                                              for(int i=1;i<=3;i++)
                                              {
                                                         x:
                                                         cout<<"\n\nEnter the name of the song:";
                                                         cin.get();
                                                         getline(cin,sname);
                                                        
                                                         cout<<"Enter the name of the artist:";
                                                         getline(cin,sartist, '\n');
                                            
                                                         ch2=sname[0];
                                                
                                                         num=0;
                                                         for(j=1;j<=26;j++)
                                                         {
                                                                    if(head[j].ch==ch2)
                                                                    {
                                                                               num=1;
                                                                               p=j;
                                                                               break;
                                                                    }
                                                         }
                                                         if(num==1)
                                                         {
                                                                  songs* node=new songs;
                                                                  node->obj.id=i;
                                                                  cout<<node->obj.id<<" ";
                                                                  node->obj.s_name=sname;
                                                                  node->obj.s_artist=sartist;
                                                                  head[p].headIn=insert_node(head[p].headIn,node);
                                                                  cout<<"Song Inserted successfully";
                                                         }
                                                         else
                                                                  {cout<<"\nSorry!! But this song cannot be inserted";
                                                                  cout<<"\nPlease insert again";
                                                                  goto x;}
                                              }
                                          
                                              cout<<"\nSongs Insertion Successfully Completed!!))";
                                              cout<<"\nPress any key to go back to main window : ";
                                                                  cin.get();
                                                                  goto start;
                                 }
                                 break;
                                 case 1:
                                        {  r.signup();
                                          cout<<"Press any key to go back to main window...";
                                                       cin.get();
                                                       goto start;
                                        }
                                        break;
                                 case 3:{if(flag==0)
                                              {
                                                       cout<<"Please execute the first function first !!";
                                                       cout<<"Press any key to go back to main window : ";
                                                       cin.get();
                                                       goto start;
                                              }
                                          else
                                          {
                                              r.Login();
                                              if(r.tag==1)
                                              {
                                              while(1)
                                              {
                                                       system("clear");
                                                       A:
                                                       cout<<"\t\t\t\t\t   Welcome to Quaver";
                                                       cout<<"\n\t\t\t\t\t<======================>";
                                                       cout<<"\n\t\t\t\t\tThe Ultimate Song Directory";
                                                       cout<<"\n\nUSE:\n1.View all songs in the Directory";
                                                       cout<<"\n2.Search paticular song\n3.View recently played songs\n4.My favourite playlist";
                                                       cout<<"\n5.Give feedback and rate us\n6.Sign out";
                                                       cout<<"\nEnter your choice:";
                                                       cin>>x;
                                                       switch(x)
                                                       {
                                                                  case 1:{     system("clear");
                                                                               
                                                                               cout<<"\nID"<<"\t\t  "<<"Name"<<"\t\t"<<"Artist";
                                                                               cout<<"\n---"<<"\t\t  "<<"-----"<<"\t\t"<<"-------\n";
                                                                               for(int i=1;i<=26;i++)
                                                                                {print(head[i].headIn);
                                                                                 }
                                                                                 cout<<"\nPress any key to continue...";
                                                                                 cin.get();
                                                                                 goto A;
                                                                                 break;
                                                                  }
                                                                  case 2:{char c;
                                                                               int y,k;
                                                                               char z;
                                                                               cout<<"\nID"<<"         "<<"Name"<<"         "<<"Artist";
                                                                               cout<<"\n---"<<"         "<<"---------"<<"         "<<"-------\n";
                                                                               for(int i=1;i<26;i++)
                                                                                       {
                                                                                           print(head[i].headIn);
                                                                                
                                                                                       }
                                                                               cout<<"\n\n---------->Search Bar";
                                                                               cout<<"\nUSE:\n1.Search by the ID no\n2.Search by name of the song";
                                                                               CHOICE:cout<<"\nEnter your choice:";
                                                                               cin>>y;
                                                                               if(y==1)
                                                                               {
                                                                                          int num;
                                                                                          SEARCH:cout<<"\nEnter the id to be searched:";
                                                                                          cin>>num;
                                                                                          for(int i=1;i<=26;i++)
                                                                                          {
                                                                                                    
                                                                                                     k=search_by_id(head[i].headIn,num);
                                                                                                     if(k==1)
                                                                                                     {
                                                                                                              break;
                                                                                                     }
                                                                                          }
                                                                                          
                                                                                          if(k==0)
                                                                                          {
                                                                                                     cout<<"\nDo you want to search the song again by id(y/n)?";
                                                                                                     cin>>c;
                                                                                                     if(c=='y'||c=='Y')
                                                                                                              goto SEARCH;
                                                                                                     else
                                                                                                     {
                                                                                                                cout<<"Please rate us :))";
                                                                                                                feedback();
                                                                                                     }
                                                                                          }
                                                                               }
                                                                               else if(y==2)
                                                                               {
                                                                                          string str;
                                                                                          YES:cout<<"\nEnter the name of the song to be searched:";
                                                                                          getline(cin,str);
                                                                                          getline(cin,str);
                                                                                          for(int i=1;i<=26;i++)
                                                                                          {
                                                                                                     k=search_by_sname(head[i].headIn,str);
                                                                                                     if(k==1)
                                                                                                              break;
                                                                                          }
                                                                                          if(k==0)
                                                                                          {
                                                                                                     cout<<"\nDo you want to search the song again by name(y/n)?";
                                                                                                     cin>>c;
                                                                                                     if(c=='y'||c=='Y')
                                                                                                              goto YES;
                                                                                                     else
                                                                                                     {
                                                                                                                cout<<"Please rate us :))";
                                                                                                                feedback();
                                                                                                     }
                                                                                          }
                                                                               }
                                                                               else
                                                                               {
                                                                                          cout<<"Incorrect Number entered!!";
                                                                                          cout<<"Do you want to re-enter the choice(y/n):";
                                                                                          cin>>z;
                                                                                          if(z=='Y'|| z=='y')
                                                                                                   goto CHOICE;
                                                                                          else
                                                                                          {
                                                                                                    cout<<"Please rate us :))";
                                                                                                    feedback();
                                                                                          }
                                                                               }
                                                    
                                                                               break;
                                                                  case 3:view_recently_played();break;
                                                                  case 4:view_fav_playlist();break;
                                                                  case 5:{feedback();}
                                                                               break;
                                                                  case 6:{exit_program();}
                                                                               break;
                                                                  default:{cout<<"Wrong input!! Please try again";}
                                                       }
                                        
                                                       getch();
                                              }
                                              }
                                              }
                                              else 
                                              cout<<"Please Login to continue...";
                                              cout<<"Press any key to go back to main window : ";
                                                       cin.get();
                                                       goto start;
                                              
                                              }
                                              break;
                                 case 4:{exit_program();
                                              break;
                                 }
                                 default:cout<<"Wrong choice entered!!";
                                 }
                      getch();
           }
           return 0;
           }
}
