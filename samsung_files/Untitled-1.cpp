#include<iostream>
#include<fstream>
using namespace std;
class shopping
{
	private:
		int pcode;
		float price, dis;
		string pname;
	public:
	  void menu();
	  void administrator();
	  void buyer();
	  void add();
	  void edit();
	  void rem();
	  void list();
	  void receipt();
};
void shopping::menu() {
    int choice;
    string email, password;
    while (true) {
        cout << "\t\t\t\t________________________________\n";
        cout << "\t\t\t\t                                \n";
        cout << "\t\t\t\t     Supermarket Main Menu      \n";
        cout << "\t\t\t\t                                \n";
        cout << "\t\t\t\t________________________________\n";
        cout << "\t\t\t\t                                \n";     
        cout << "\t\t\t\t|  1) Administrator    |\n";     
        cout << "\t\t\t\t|                      |\n";     
        cout << "\t\t\t\t|  2) Buyer            |\n";     
        cout << "\t\t\t\t|                      |\n";     
        cout << "\t\t\t\t|  3) Exit             |\n";     
        cout << "\t\t\t\t|                      |\n";     
        cout << "\n\t\t\t Please Select : ";     
        cin >> choice;     
        
        switch(choice) {     
            case 1:     
                cout << "\t\t\t Please log in  \n";     
                cout << "\t\t\t Enter Email :  ";     
                cin >> email;     
                cout << "\t\t\t Enter Password :  ";     
                cin >> password;     
                if(email == "areeb@gmail.com" && password == "areeb") {     
                    administrator();  // Go to admin menu
                } else {     
                    cout << "Invalid email/password";     
                }     
                break;     
    
            case 2:     
                buyer();  // Go to buyer menu
                break;
    
            case 3:     
                exit(0);  // Exit program
                break;
    
            default:     
                cout << "Please select from the given option";     
        }    
    }
}
void shopping::administrator() {
    int choice;
    while (true) {
        cout << "\n\n\n\t\t\t Administrator menu\n";
        cout << "\t\t\t|____1) Add the product_______|\n";
        cout << "\t\t\t|                             |\n";
        cout << "\t\t\t|____2) Modify the product____|\n";
        cout << "\t\t\t|                             |\n";
        cout << "\t\t\t|____3) Delete the product____|\n";
        cout << "\t\t\t|                             |\n";
        cout << "\t\t\t|____4) Back to the main menu |\n";
        cout << "\t\t\t|                             |\n";
        cout << "\n\n\t Please enter your choice : ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                add();  // Add product
                break;
            case 2:
                edit();  // Modify product
                break;
            case 3:
                rem();  // Delete product
                break;
            case 4:
                return;  // Go back to the main menu
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    }
}

void shopping::buyer() {
    int choice;
    while (true) {
        cout << "\t\t\t    Buyer             \n";
        cout << "\t\t\t_______________         \n";
        cout << "\t\t\t 1) Buy product       \n";
        cout << "\t\t\t 2) Go back           \n";
        cout << "\t\t\t Enter your choice : ";
        cin >> choice;

        switch (choice) {
            case 1:
                receipt();
                break;
            case 2:
                return;  // Return to the main menu
            default:
                cout << "Invalid choice\n";
                break;
        }
    }
}
void shopping::add() {
    fstream data;
    int c;
    int token = 0;
    float p, d;
    string n;
    
    cout << "\n\n\t\t\t Add new product ";
    cout << "\n\n\t Product code of the product :";
    cin >> pcode;
    cout << "\n\n\t Name of the product :";
    cin >> pname;
    cout << "\n\n\t Price of the product :";
    cin >> price;
    cout << "\n\n\t Discount on product :";
    cin >> dis;

    // Open the database to check if the product already exists
    data.open("database.txt", ios::in);
    if (!data) {
        // If the file doesn't exist, create it and add the first product
        data.open("database.txt", ios::app | ios::out);
        data << "  " << pname << "  " << price << "  " << dis << "\n";
        data.close();
    } else {
        // If the file exists, check if the product already exists by product code
        data >> c >> n >> p >> d;
        while (!data.eof()) {
            if (c == pcode) {
                token++;
            }
            data >> c >> n >> p >> d;
        }
        data.close();
    }

    if (token == 1) {
        // If the product code already exists
        cout << "\n\n\t Product code already exists!\n";
    } else {
        // If the product doesn't exist, add it to the database
        data.open("database.txt", ios::app | ios::out);
        data << "  " << pname << "  " << price << "  " << dis << "\n";
        data.close();
        cout << "\n\n\t\t Record inserted !";
    }
}
void shopping::edit()
{
	fstream data,data1;
	int pkey;
	int token=0;
	int c;
	float p,d;
	string n;
	cout<<"\n\t\t\t Modify the record";
	cout<<"\n\t\t\t Product code :";
	cin>>pkey;
	data.open("database.txt",ios::in);
	if(!data)
	{
		cout<<"\n\nFile doesn't exit !";
	}
	else{
		data1.open("database1.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>dis;
		while(!data.eof())
		{
			if(pkey==pcode)
			{
				cout<<"\n\t\t Product new code :";
				cin>>c;
				cout<<"\n\t\t Name of the product :";
				cin>>n;
				cout<<"\n\t\t Price :";
				cin>>p;
				cout<<"\n\t\t Discount :";
				cin>>d;
				data1<<" "<<c<<" "<<n<<" "<<p<<" "<<" "<<d<<"\n";
				cout<<"\n\n\t\t Record edited ";
				token++;
			}
			else
			{
			data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";	
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt","database.txt");
		if(token==0)
		{
			cout<<"\n\n Record not found sorry !";
		}
	}
}
void shopping::rem()
{
	fstream data,data1;
	int pkey;
	int token=0;
	cout<<"\n\n\t Delete product";
	cout<<"\n\n\t Product code :";
	cin>>pkey;("database.txt",ios::in);
	if(!data)
	{
		cout<<"File does't exist";	
	}
	else{
		data1.open("database1.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>dis;
		while(!data.eof())
		{
			if(pcode==pkey)
			{
				cout<<"\n\n\t Product deleted successfully";
				token++;
			}
			else{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
				
			}
		data>>pcode>>pname>>price>>dis;	
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt","database.txt");
		if(token==0)
		{
			cout<<"\n\n Record not found sorry !";
		}
	}	
}
void shopping::list()
{
	fstream data;
	data.open("database.txt",ios::in);
	cout<<"\n\n|_______________________________\n";
	cout<<"ProNo\t\tName\t\tPrice\n";
	cout<<"\n\n|_______________________________\n";
	data>>pcode>>pname>>price>>dis;
	while(!data.eof())
	{
		cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
		data>>pcode>>pname>>price>>dis;	
	}
	data.close();
}
void shopping::receipt() {
	m:
    fstream data;
    int arrc[100];
    int arrq[100];
    int c = 0;
    char choice;
    float amount = 0;
    float dis = 0;
    float total = 0;
    cout << "\n\n\t\t\t\t RECEIPT \n";
    data.open("database.txt", ios::in);
    
    if (!data) {
        cout << "\n\n Empty database\n";
    } else {
        data.close();
        list();
        cout << "\n ________________________________\n";
        cout << "\n|                                |\n";
        cout << "|      Please place the order    |\n";
        cout << "|                                |\n";
        cout << "|________________________________|\n";
        
        do {
            cout << "\n\nEnter Product code: ";
            cin >> arrc[c];
            cout << "\n\nEnter Product Quantity: ";
            cin >> arrq[c];
            
            for (int i = 0; i < c; i++) {
                if (arrc[c] == arrc[i]) {
                    cout << "\n\n Duplicate product code. Please try again! ";
                    goto m;
                }
            }
            
            c++;
            cout << "\n\n Do you want to buy another product? (y/n): ";
            cin >> choice;
        } while (choice == 'y');
        
        cout << "\n\n\t\t\t_______________Receipt_____________\n";
        cout << "\nProduct No\t Product Quantity\t Price\tAmount with discount\n";
        
        for (int i = 0; i < c; i++) {
            data.open("database.txt", ios::in);
            data >> pcode >> pname >> price >> dis;
            
            while (!data.eof()) {
                if (pcode == arrc[i]) {
                    amount = price * arrq[i];
                    dis = amount - (amount * dis / 100);
                    total += dis;
                    cout << "\n" << pcode << "\t\t" << pname << "\t\t" << arrq[i] << "\t\t" << price << "\t\t" << amount << "\t\t" << dis;
                }
                data >> pcode >> pname >> price >> dis;
            }
            data.close();
        }
        
        cout << "\n\n_________________________________";
        cout << "\n Total Amount: " << total << "\n";
    }
}
int main()
{
	shopping s;
	s.menu();
}
