#include <iostream>
#include <string.h>

int main() {
    using std::cout;
    using std::string;
    using std::getline;
    // string s = "abc   def s  sdfe   rtmju.";
    // const char *d = " ";
    // char *p = strtok(const_cast<char *>(s.c_str()), d);
    // std::cout<<"s:"<<s<<"\n";
    // std::cout<<p<<" ";
    // while (p)
    // {

    // }
    string s;
    char seq[2];
    getline(std::cin,s);
    std::cin.get(seq,sizeof(seq));

    cout<<"s:|"<<s<<'|'<<"\n"<<"seq:|"<<seq<<"|"<<"\n";

    // size_t firstnpos = s.find_first_not_of(seq);
    // size_t nextpos = s.find_first_of(seq, firstnpos + 1);
    // cout << s.substr(firstnpos, nextpos-firstnpos) << "\n";
    size_t firstnpos=0,nextpos=0;

    do
    {
      firstnpos = s.find_first_not_of(seq,nextpos);
      if(firstnpos == string::npos)
        firstnpos = s.size();
      nextpos = s.find_first_of(seq, firstnpos + 1);
      if(nextpos == string::npos )
        nextpos = s.size();

      if(firstnpos != nextpos){
        cout <<'|'<< s.substr(firstnpos, nextpos-firstnpos) <<'|'<< "\n";
      }
    } while (nextpos < s.size() && firstnpos < s.size());
    

    return 0;
}