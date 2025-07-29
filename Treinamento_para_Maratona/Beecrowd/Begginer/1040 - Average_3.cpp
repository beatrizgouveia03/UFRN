#include <bits/stdc++.h>

using namespace std;

#define ff float
#define dd double
#define ll unsigned long long int
#define str string
#define ct cout << 
#define end << endl
#define precise fixed << setprecision(1)

int main() {
    dd a, b, c, d, md;

    cin >> a >> b >> c >> d;

    md = (2*a+3*b+4*c+d)/10;

    ct precise << "Media: " << md end;

    if(md >= 7.0) ct "Aluno aprovado." end;
    else if(md < 5.0) ct "Aluno reprovado." end;
    else {
        dd aux;

        ct "Aluno em exame." end;

        cin >> aux;

        ct "Nota do exame: " << aux end;
        md = (md+aux)/2;
        (md >= 5.0) ? ct "Aluno aprovado." end :
         ct "Aluno reprovado." end;
        
        ct "Media final: " << md end; 
        
    }
    
   

    return 0;
} 