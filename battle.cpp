#include <iostream> 

using namespace std;

int main()

{

    string tpl;

    int youAtack, youDef, youServer1 = 100, youServer2 = 100, youServer3 = 100, oponentAtack, oponentDef, oponentServer1 = 100, oponentServer2 = 100, oponentServer3 = 100;

    cout << "Welcome! To start the game, write 'start', write 'help' to output the help" << endl;

    cin >> tpl;

    if (tpl == "help")

        cout << "Enter 2 digits: which server are you attacking and which one are you defending, separated by a space (example 1 3)" << endl;

    while (youServer1 > 0 && youServer2 > 0 && youServer3 > 0 && oponentServer1 > 0 && oponentServer2 > 0 && oponentServer3 > 0) {

        cout << "The power of the oponent's servers> " << oponentServer1 + oponentServer2 + oponentServer3 << endl;

        cout << oponentServer1 << " " << oponentServer2 << " " << oponentServer3 << endl;

        cout << endl;

        cout << "The power of your servers> " << youServer1 + youServer2 + youServer3 << endl;

        cout << youServer1 << " " << youServer2 << " " << youServer3 << endl;

        cout << endl; cout << endl;



        cin >> youAtack >> youDef;

        while (youAtack < 1 || youAtack > 3 || youDef < 1 || youDef > 3)

        {

            cout << "Incorrect data, repeat the input" << endl;

            cin >> youAtack >> youDef;

        }

        oponentDef = rand() % 3 + 1;

        oponentAtack = rand() % 3 + 1;





        if (youAtack != oponentDef) {

            switch (youAtack)

            {

            case 1:

                oponentServer1 -= 20;

                break;



            case 2:

                oponentServer2 -= 20;

                break;



            case 3:

                oponentServer3 -= 20;

                break;

            }

        }

        if (youDef != oponentAtack) {

            switch (oponentAtack)

            {

            case 1:

                youServer1 -= 20;

                break;



            case 2:

                youServer2 -= 20;

                break;



            case 3:

                youServer3 -= 20;

                break;

            }

        }

    }

    if (oponentServer1 + oponentServer2 + oponentServer3 < youServer1 + youServer2 + youServer3)

    {

        cout << "The power of the oponent's servers> " << oponentServer1 + oponentServer2 + oponentServer3 << endl;

        cout << oponentServer1 << " " << oponentServer2 << " " << oponentServer3 << endl;

        cout << endl;

        cout << "The power of your servers> " << youServer1 + youServer2 + youServer3 << endl;

        cout << youServer1 << " " << youServer2 << " " << youServer3 << endl;

        cout << endl; cout << endl;



        cout << "You win!" << endl;

    }
    else  if (oponentServer1 + oponentServer2 + oponentServer3 > youServer1 + youServer2 + youServer3) {

        cout << "The power of the oponent's servers> " << oponentServer1 + oponentServer2 + oponentServer3 << endl;

        cout << oponentServer1 << " " << oponentServer2 << " " << oponentServer3 << endl;

        cout << endl;

        cout << "The power of your servers> " << youServer1 + youServer2 + youServer3 << endl;

        cout << youServer1 << " " << youServer2 << " " << youServer3 << endl;

        cout << endl; cout << endl;



        cout << "You lose!" << endl;

    }
    else {



        if ((oponentServer1 == 0 || oponentServer2 == 0 || oponentServer3 == 0) && (youServer1 == 0 || youServer2 == 0 || youServer3 == 0))

        {

            cout << "The power of the oponent's servers:" << endl;

            cout << oponentServer1 << " " << oponentServer2 << " " << oponentServer3 << endl;

            cout << endl;

            cout << "The power of your servers:" << endl;

            cout << youServer1 << " " << youServer2 << " " << youServer3 << endl;

            cout << endl; cout << endl;



            cout << "Draw!" << endl;

        }

        else if (oponentServer1 == 0 || oponentServer2 == 0 || oponentServer3 == 0) {

            cout << "The power of the oponent's servers:" << endl;

            cout << oponentServer1 << " " << oponentServer2 << " " << oponentServer3 << endl;

            cout << endl;

            cout << "The power of your servers:" << endl;

            cout << youServer1 << " " << youServer2 << " " << youServer3 << endl;

            cout << endl; cout << endl;



            cout << "You win!" << endl;

        }

        else if (youServer1 == 0 || youServer2 == 0 || youServer3 == 0) {

            cout << "The power of the oponent's servers:" << endl;

            cout << oponentServer1 << " " << oponentServer2 << " " << oponentServer3 << endl;

            cout << endl;

            cout << "The power of your servers:" << endl;

            cout << youServer1 << " " << youServer2 << " " << youServer3 << endl;

            cout << endl; cout << endl;



            cout << "You lose!" << endl;

        }

    }

    cout << "Shall we play again? (Y/N)" << endl;

    cin >> tpl;

    if (tpl == "Y")

        main();

    return 0;

}
