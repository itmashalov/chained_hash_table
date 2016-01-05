#include <iostream>
#include <string>
#include <vector>
using namespace std;


class  Hash_table
{
 
 string word;
 int word_asc;
 int word_asc_rest;
 int  size_of_arr;
 int num_of_elements;
 string word_to_find;
 string word_to_delete;
 int word_to_delete_asc;
 int word_to_find_asc;
 int find_index;
 int find_index2;





 vector<string> hashVect[100];
    public:
	/*	
	this function intialize the hash table and it has one parameter: in size

	*/
	void Initalisation(int size)
	{
		size=size_of_arr;

		vector<string> hashVect[100]; 
	}

	

	/*	
	this function converts a word into ascii code and sets the value in variable

	*/

	void set_convertToASCII(string word) 
	{

		word_asc=0;
 	
	 for (int i = 0; i < word.length(); i++) 
         { 
		char x = word.at(i);
		word_asc=word_asc+int(x);


	 }
	
	}
	/*	
	this function the value of the variable which contains the ascii code of the word

	*/
	int get_convertToASCII() {return word_asc;}

	/*	
	this function add a word into the hash table, firtst it converts the wort into ascii code to see where to add the word and after that it adds the word as a string

	*/
	void add(){
	 cout << "Please enter the word which you want to add: " << endl;
         getline(std::cin, word);
     	 set_convertToASCII(word);
	 int word_asc2=get_convertToASCII();
	
         word_asc_rest=word_asc2%100;
	 hashVect[word_asc_rest].push_back(word);

	}
	/*	
	this function prints the elements in the hash table

	*/
        void print(){
		 int j,i;
		 for (j=0; j<100; j++){
  			 for (i=0; i<hashVect[j].size(); i++) cout << " " << hashVect[j].at(i) << " " <<"\n";
		 
		 }
		}
	
	/*	
	this function return the size of the hash table

	*/
	void return_size(){
	  int k;
	num_of_elements=0;
	 for (k=0; k<100; k++){
  		
		num_of_elements=num_of_elements+hashVect[k].size();
 		
	 }
 	 cout << num_of_elements <<endl;
	}
	/*	
	this function says if an element is in the table or not and if it is also prints the exact possition

	*/
	void find_element() 
	{
		cout << "Please enter the word for which you are looking for " << endl;
		getline(std::cin, word_to_find);
		set_convertToASCII(word_to_find);
	    	word_to_find_asc=get_convertToASCII();
		find_index =word_to_find_asc%100;
		bool flag=0;
		 for (int p=0; p<hashVect[find_index].size(); p++){
			 if(hashVect[find_index].at(p) == word_to_find){
				 cout << "the word "<<word_to_find<<" is in the table. array index : " << find_index<<" vector index: " <<  p << endl;
			  flag=1;
			  break;
			 }
		 }
		 if(flag==0){
			 cout << "the word "<<word_to_find<<" is not in the table"<<endl;
		 }

	}
	/*	
	this function deletes an element form the table

	*/
	void delete_element() 
	{
		cout << "Please enter the word which you want to delete " << endl;
		getline(std::cin, word_to_delete);
		set_convertToASCII(word_to_delete);
	   	word_to_delete_asc=get_convertToASCII();
		find_index2 =word_to_delete_asc%100;
		bool flag=0;
		int q;
		 for (q=0; q<hashVect[find_index2].size(); q++){
			 if(hashVect[find_index2].at(q) == word_to_delete){
				 cout << "the word "<<word_to_delete<<" is in the table. array index : " << find_index2<<" vector index: " <<  q << endl;
			 hashVect[find_index2].at(q)=hashVect[find_index2].back();
			 hashVect[find_index2].pop_back();
			 cout << "the word has been deleted" << endl;	 
			 flag=1;
			 break;
			 }
		 }

		 if(flag==0){
			 cout << "the word "<<word_to_delete<<" is not in the table"<<endl;
		 }

	}



};

int main() 
{ 

//********* menu starts here *************
string choice;

		
		cout << "Press \"i\" to insert an element " << endl;
		cout << "Press \"d\" to Delete an element " << endl;
		cout << "Press \"l\" to Look up an element " << endl;
		cout << "Press \"s\" to see the number of elements stored in the hash table" << endl;
		cout << "Press \"p\" to prints out the current state of the hash table" << endl;
		cout << "Press \"exit\" to exit the program" << endl;
getline(std::cin, choice);
Hash_table hash1;
while(choice !="exit"){

	
	if(choice=="i"){
		hash1.add();
		
		
		cout << "Press \"i\" to insert an element " << endl;
		cout << "Press \"d\" to Delete an element " << endl;
		cout << "Press \"l\" to Look up an element " << endl;
		cout << "Press \"s\" to see the number of elements stored in the hash table" << endl;
		cout << "Press \"p\" to prints out the current state of the hash table" << endl;
		cout << "Press \"exit\" to exit the program" << endl;
		getline(std::cin, choice);
	}
	if(choice=="d"){
		hash1.delete_element();
		
		
		cout << "Press \"i\" to insert an element " << endl;
		cout << "Press \"d\" to Delete an element " << endl;
		cout << "Press \"l\" to Look up an element " << endl;
		cout << "Press \"s\" to see the number of elements stored in the hash table" << endl;
		cout << "Press \"p\" to prints out the current state of the hash table" << endl;
		cout << "Press \"exit\" to exit the program" << endl;
	
		getline(std::cin, choice);
	}
	if(choice=="l"){
		hash1.find_element();
		
		
		cout << "Press \"i\" to insert an element " << endl;
		cout << "Press \"d\" to Delete an element " << endl;
		cout << "Press \"l\" to Look up an element " << endl;
		cout << "Press \"s\" to see the number of elements stored in the hash table" << endl;
		cout << "Press \"p\" to prints out the current state of the hash table" << endl;
		cout << "Press \"exit\" to exit the program" << endl;
	
		getline(std::cin, choice);
	}
	if(choice=="s"){
		hash1.return_size();
		
		
		cout << "Press \"i\" to insert an element " << endl;
		cout << "Press \"d\" to Delete an element " << endl;
		cout << "Press \"l\" to Look up an element " << endl;
		cout << "Press \"s\" to see the number of elements stored in the hash table" << endl;
		cout << "Press \"p\" to prints out the current state of the hash table" << endl;
		cout << "Press \"exit\" to exit the program" << endl;
	
		getline(std::cin, choice);
	}
	if(choice=="p"){
		hash1.print();
		
		
		cout << "Press \"i\" to insert an element " << endl;
		cout << "Press \"d\" to Delete an element " << endl;
		cout << "Press \"l\" to Look up an element " << endl;
		cout << "Press \"s\" to see the number of elements stored in the hash table" << endl;
		cout << "Press \"p\" to prints out the current state of the hash table" << endl;
		cout << "Press \"exit\" to exit the program" << endl;
	
		getline(std::cin, choice);
	}
	
	if(choice=="exit"){
		break;
	}
}
	
	 //********* menu ends here *************
	
   



return 0;
}
