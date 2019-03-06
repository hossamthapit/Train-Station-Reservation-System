#include <bits/stdc++.h>
/*_*/
typedef long long ll;
typedef unsigned long long ull;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define szz(x) ll(x.size())
const int MAX = 1000000;
using namespace std;

/** train station project beta version **/

struct carriages
{
    int carriage;
    int classs;
    double seat_price;
};

carriages info[MAX];
int cars_num, dif_classes = 0, class_available[MAX] ;
bool booked_seats[MAX][31], class_vis[MAX] ;

void book_ticket()
{
    int classs, a = 0, seat, cariage;
    bool yes = 0 ;

    printf("\nThe available classes in the train is : ");

    for(int i = 0 ; i < dif_classes ; i++)
        if(i==0)
            printf("%d",class_available[i]);
        else
            printf(",%d",class_available[i]);

    printf("\nEnter the class you choose: ");
    //avoid error
    string s ;cin >> s ;
    stringstream e(s);e>>classs;
    if(s>="a"||classs<1||szz(s)>8||szz(s)!=(int)log10(classs)+1){printf("INVALID INPUT\n");return ;}
    //
    if(!class_vis[classs])
    {
        printf("\nClass %d wasn't in the choices ! \n", classs);
        return ;
    }

    for (int i = 1; i <= cars_num; i++)
        if (classs == info[i].classs)
            if (!a)
            {
                printf("\nThe available carriages for this class is : %d", i);
                a = 1;
            }
            else
                printf(",%d ", i);

    printf("\nEnter the number of the carriage you choose: ");
    //avoid error
    cin >> s ;
    stringstream ee(s); ee>>cariage;
    if(s>="a"||cariage<1||szz(s)>8||szz(s)!=(int)log10(cariage)+1){printf("INVALID INPUT\n");return ;}
    //

    if (info[cariage].classs != classs)
    {
        printf("\ncarriage %d wasn't in the choices ! \n", cariage);
        return ;
    }

    for(int i = 1 ; i < 31 ; i++)
        if(!booked_seats[cariage][i]&&!yes)
        {
            printf("\nThe available seats in carriage %d is: \n%d",cariage,i);
            yes = 1 ;
        }
        else if(!booked_seats[cariage][i])
            printf(",%d",i);

    if(!yes)
    {
        printf("sorry there is no available seats in this carriage \n");
        return;
    }
    printf("\n\nEnter the seat number you choose: ");
    //avoid error
    cin >> s ;
    stringstream eee(s);eee>>seat;
    if(s>="a"||szz(s)>8||szz(s)!=(int)log10(seat)+1){printf("INVALID INPUT\n");return ;}
    //
    if (seat < 1 || seat > 30 || booked_seats[cariage][seat])
        printf("\nseat number %d wasn't in the choices.\n",seat);
    else
    {
        printf("\nseat reserved successfully :) \n");
        printf("\n\n*************** TICKET INFORMATION *****************\n*\n");
        printf("*  THE CLASS OF THE TICKET IS: %d\n*\n",classs);
        printf("*  THE CARRIAGE NUMBER IS: %d\n*\n",cariage);
        printf("*  THE SEAT NUMBER IS: %d",seat);
        cout << "     TICKET PRICE: "<< info[cariage].seat_price<< " EGP\n" ;

        printf("*\n****************************************************\n\n");
        booked_seats[cariage][seat] = 1;
    }
}

void cancel_ticket()
{
    int cariage, seat ;
    printf("\nEnter the carriage number & the seat of the ticket you want to cancel\n\n");
    printf("Carriage number: ");
    //avoid error
    string s ;cin >> s ;
    stringstream e(s);e>>cariage;
    if(s>="a"||cariage<1||szz(s)>8||szz(s)!=(int)log10(cariage)+1){printf("INVALID INPUT\n");return ;}
    //

    printf("Seat number: ");
    //avoid error
    cin >> s ;
    stringstream ee(s);ee>>seat;
    if(s>="a"||seat<1||szz(s)>8||szz(s)!=(int)log10(seat)+1){printf("INVALID INPUT\n");return ;}
    //
    printf("\n");

    if (booked_seats[cariage][seat])
    {
        printf("ticket canceled successfully.\n");
        booked_seats[cariage][seat] = 0;
    }
    else
        printf("There is no booked_seats ticket with this information !!\n");
}

void available_seats()
{
    int classs ;
    bool yes = 0 ;
    printf("\nThe available classes in the train is : ");

    for(int i = 0 ; i < dif_classes ; i++)
        if(!yes)
        {
            printf("%d",class_available[i]);
            yes=1;
        }
        else
            printf(",%d",class_available[i]);

    printf("\nEnter the class you want to show the available seat in it: ");
    //avoid error
    string s ;cin >> s ;
    stringstream e(s);e>>classs;
    if(s>="a"||classs<1||szz(s)>8||szz(s)!=(int)log10(classs)+1){printf("INVALID INPUT\n");return ;}
    //

    if(!class_vis[classs])
    {
        printf("\nClass %d wasn't in the choices ! \n", classs);
        return ;
    }

    printf("\n");
    bool a = 1;
    for (int i = 1; i <= cars_num; i++)
    {
        if (classs != info[i].classs)
            continue;
        for (int k = 1; k <= 30; k++)
        {
            if (a && !booked_seats[i][k])
            {
                printf("The available seat for class %d in carriage %d# is :\n%d", classs, i, k);
                a = 0;
            }
            else if (!booked_seats[i][k] && !a)
            {
                printf(",%d", k);
            }
        }
        if (a)
            printf("There is no available seats in carriage %d# for class %d", i, classs);
        printf("\n\n");
        a = 1;
    }

}

void profits()
{
    printf("\n");
    int  seat_num = 0, seat_sum = 0;
    double train_profit=0 , sum=0 ;
    for (int i = 1; i <= cars_num; i++)
    {
        for (int k = 1; k <= 30; k++)
        {
            if (booked_seats[i][k])
            {
                sum += (info[i].seat_price);
                seat_num++;
            }
        }
        cout << "The profit for carriage " <<  i << " is " << sum << " EGP " << seat_num << endl;
        train_profit += sum;
        seat_sum += seat_num;
        sum = seat_num = 0;
    }
    cout << "\nThe total profit for the train is "<< train_profit << " EGP for " <<  seat_sum <<endl;
}

void close()
{
    printf("GAME OVER\n");
    exit(0);
}

void options()
{
    printf("____________________________________________________\n");
    printf("____________________________________________________\n\nOPTIONS:-\n");
    printf("Enter 1 to book a ticket.\nEnter 2 to cancel a ticket. \nEnter 3 to show available seats.\n");
    printf("Enter 4 to show profits in details.\nEnter 0 to exit.\n\nEnter your choice: ");
}

int main()
{
    map < int , int > mp ;
    int  carriage_class;
    double carriage_price;
    printf("WELCOME :) \n\n");
    printf("Please set the train info before any use.\n\n");
    printf("Enter the number of the carriage in the train: ");
    //avoid error
    string s ;cin >> s ;
    stringstream e(s); e >> cars_num;
    if(s>="a"||cars_num<1||szz(s)>6||(int)log10(cars_num)+1!=szz(s)){printf("INVALID INPUT\n");return 0;}
    //

    printf("\n");

    for (int t = 1; t <= cars_num; t++)
    {

        printf("Carriage %d#\nEnter the class: ", t);
        //avoid error
        int ew ;
        cin >> s ;
        stringstream e(s); e>>carriage_class;
        ew = carriage_class ;
        if(s>="a"||carriage_class<1||szz(s)>8||(int)log10(carriage_class)+1!=szz(s)){printf("INVALID INPUT\n");return 0;}
        //

        if(!class_vis[carriage_class])
        {
            class_vis[carriage_class]=1;
            class_available[dif_classes]=carriage_class;
            dif_classes++;
        }
        printf("Enter the price: ");
        //avoid error
        cin >> s ;
        stringstream ee(s); ee >> carriage_price;
        if(s>="a"||carriage_price<1||szz(s)>8){printf("INVALID INPUT\n");return 0;}
        //

        if(mp[ew]!=0&&mp[ew]!=carriage_price){
            printf("INVALID PRICE\n");
            return 0;
        }
        mp[carriage_class]=carriage_price;

        printf("\n");
        info[t].carriage = t;
        info[t].classs = carriage_class;
        info[t].seat_price = carriage_price;
    }
    printf("Train info set successfully...\n");
    sort(class_available,class_available+dif_classes);

    while(true)
    {
        string choice;
        options();
        cin >> choice;

        if (choice == "1")
            book_ticket();

        else if (choice == "2")
            cancel_ticket();

        else if (choice == "3")
            available_seats();

        else  if (choice == "4")
            profits();

        else if (choice=="0")
            close();
        else
            printf("\nThis choice wasn't in the options !!\n");
    }
}
