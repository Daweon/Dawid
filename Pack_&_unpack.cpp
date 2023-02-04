#include <iostream>
#include <ctype.h>
#include <string>
#include <math.h>

using namespace std;

class Pack_or_unpack {
public:

string UnpackString(string s){
    string output;
    string phrase, phrase2;                                                         // phrase is single section inside brackets
    int numb_before_bracket, open, close, digit, cut, highest=0, inner=0, iter=0;
    while(s.find(']') != string::npos && s.find('[')!= string::npos ){              // checking whether there are brackets to unpack in string
        for (int i=0; i<s.length();i++){                                            // finding the innermost brackets
            if (s[i]=='[') {inner++;}
            if (s[i]==']') {inner--;}
            if (inner>highest) {highest=inner; iter=i;}                             // iter is a number of a string element which is '[' of first innermost brackets
            }
        numb_before_bracket = 0;
        close = s.find(']',iter-1);                                                 // finding end of brackets to unpack
        open = s.find_last_of('[',s.find(']',iter-1));                              // finding beginning of brackets to unpack
        digit = open-1;
        cut=0;
        while (isdigit(s[digit])){                                                  // finding a number before brackets
            numb_before_bracket=numb_before_bracket+((int)s[digit]-48)*pow(10,cut);
            digit--;
            cut++;
            }
        phrase=s.substr(open+1,close-open-1);                                       // phrase is a group of elements inside brackets to be copied
        phrase2=phrase;
        for(int i=1; i<numb_before_bracket; i++){                                   // multiplying phrases
            phrase.append(phrase2);
            }
        s = s.replace(open-cut,close-open+cut+1,phrase);                            // replacing brackets with multiplied phrases
        }


return(s);
}

string PackString(string s){
    int samelength=0, n=0, m=0, largestlength=0, bestn=0;
    string phrase, same, paste, bestsame, output;
    bool nodigit, write;
    output=s;
    for (int j=0; j<output.length(); j++){                                       // j: number of element from which same phrase will be searched
        for (int i=output.length()-j; i>0; i--){                                 // i-j: size of phrase, that is section which is repeated and which will be packed
            nodigit = true;
            m=0;
            while (m != output.substr(j,i).length()+1){                          // finding digit inside phrase, if there is at least one, phrase will be not packed
                if (isdigit(output.substr(j,i)[m])) {nodigit == false;}
                m++;
                }
            if (output.substr(j,i) == output.substr(j+i,i)      &&               // finding brackets phrase, if there is at least one, phrase will be not packed
                (output.substr(j,i).find(']') == string::npos ) &&
                (output.substr(j,i).find('[') == string::npos ) && (nodigit)){
                same.clear();
                n=0;
                same=output.substr(j,i);                                         // same is phrase to be packed
                samelength=same.length();
                while (same==output.substr(j+samelength*n,samelength)){          // finding number of repetitions
                    n++;
                    write=true;
                }
            if (samelength*n>=largestlength) {                              // finding method to pack largest section from given j
                largestlength = samelength*n;
                bestsame = same;
                bestn = n;
                }
            }
            }
            paste = to_string(bestn) + "[" + bestsame + "]";
            if (largestlength<paste.length()){write=false;}                 // ensuring bracket is no longer than section to be replaced
            if (write){
                paste = to_string(bestn) + "[" + bestsame + "]";            // paste is number, brackets and phrase inside them to be replaced
                output=output.replace(j,largestlength,paste);                         // replacing repeated phrases with bracket
                write=false;                                                // preventing from replacing the same phrase again
                largestlength = 0;
                }
            if (j==output.length()){
                    if (output.length()>s.length()) {return(s);}return(output);}
        }
if (output.length()>s.length()) {return(s);}
return(output);
}
};

int main()
{
    Pack_or_unpack first, second;

    string input_to_pack;
    cout << "Type string to pack: ";
    cin >> input_to_pack;
    cout << endl << first.PackString(input_to_pack)<<endl;

    string input_to_unpack;
    cout << "Type string to unpack: ";
    cin >> input_to_unpack;
    cout << endl << first.UnpackString(input_to_unpack)<<endl;

    return 0;
}
