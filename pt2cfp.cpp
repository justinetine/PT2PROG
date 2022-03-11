#include <iostream>

using namespace std;


struct group_facet: public numpunct<char> {
    protected:
        string do_grouping() const { return "\003"; }
};


    void promptAndWait();

void dollarsToPesos(float conversionRate, unsigned usd = 0);
void PesosToDollars(float conversionRate, unsigned php = 0);
int ans = 1;
int main() 

{
    
    float conversionRate = 50.73; // $1 = 50.73 Pesos
    unsigned dollarsIn, pesosIn;
    int ch;

    do
    {
        system("cls");
        cout << endl;
        cout << "Dollar to Peso Conversion App" << endl;
        cout << "[1] Dollar to Peso" << endl;
        cout << "[2] Peso to Dollar" << endl;
        cout << "[3] Exit the Coversion App" << endl;
        cout << "Select Conversion : ";
        cin >> ch;

        switch(ch)
        {
            case 1:
            {
                system("cls");
                cout << "\n<< Convert Dollar to Peso >>" << endl;
                cout << "Enter a US Dollar Amount (without the dollar sign, commas or a decimal) : [####] ";
                cin >> dollarsIn;
                dollarsToPesos(conversionRate,dollarsIn);
        
                promptAndWait(); 
                break;
            }

            case 2:
            {
                system("cls");
                cout << "\n<< Convert Peso to Dollar >>" << endl;
                cout << "\nEnter a PHP peso amount (without the peso sign, commas or a decimal) : [####] "; 
                cin >> pesosIn;
                PesosToDollars(conversionRate, pesosIn);
                promptAndWait();
                break;
            }
            case 3:
            {
                cout << "Conversion App Terminated \nThank you for using the app!";
                return 0;
            }
            default:
            {
                cout << "Invalid Input!";
                break;
            }
        }
    }while(ans == 1);
return 0;
}       

void promptAndWait()
{
    cout << "Do you want to continue? " << endl;
    cout << "[1] Yes" << endl;
    cout << "[2] No" << endl;
    cin >> ans;
}

void dollarsToPesos (float conversionRate, unsigned usd) 
{
    
    cout.setf(ios::fixed);
    cout.precision(2);

    cout.imbue(locale(cout.getloc(), new group_facet));
    cout << "\n$" << usd << " US = " << "P" << (conversionRate * usd) << " Pesos. \n";
}
   
void PesosToDollars (float conversionRate, unsigned php) 
{
    
    cout.setf(ios::fixed);
    cout.precision(2);

  
    cout.imbue(locale(cout.getloc(), new group_facet));
    cout << "\nP" << php << " Pesos = " << "$" << (php / conversionRate) << " USD. \n";
}