#include<iostream>
using namespace std;

struct Song{
	string title;
	string artist;
	Song* next;
};
class Playlist{
	public:
		Song* head;
		
		Playlist(){
			head=NULL;
		}
		
		void insert_at_front(string newtitle , string newartist) {
        	Song* newSong = new Song();
        	newSong->title= newtitle;
        	newSong->artist= newartist;
        	newSong->next = head;

        	head = newSong;
    }


    void delete_at_front() {
        if (head == NULL) {
            cout << "Error: List is empty. Cannot delete from the front." << endl;
            return;
        }

        Song* temp = head;
        head = head->next;
        delete temp;
        
    }
    
    void display(){
    	Song* temp = head;
    	int i=1;
    	while(temp != NULL){
    		cout<<"Song "<<i<<": "<<endl;
    		cout<<"->Title: "<<temp->title<<endl;
    		cout<<"->Artist: "<<temp->artist<<endl;;
    		i++;
    		temp=temp->next;
		}
		cout<<endl;
	}
};

int main(){
	Playlist Mus;
	
	Mus.insert_at_front("Off The Grid" , "Kanye West");
	Mus.insert_at_front("Stop Breathing" , "Carti");
	Mus.insert_at_front("XO Tour Llif3" , "Lil Uzi Vert");
	Mus.insert_at_front("High On Chai" , "Lil Mussi");
	
	Mus.display();
	
	cout<<"After Deletion:"<<endl;
	Mus.delete_at_front();
	Mus.display();
	return 0;
}
