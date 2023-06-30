//https://www.codingninjas.com/codestudio/problems/implement-trie_1387095?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos&leftPanelTab=0

struct Node{
	Node* alpha[26];
	int endWith=0,counterPrefix=0;
	
	bool isPresent(char ch){
		return alpha[ch-'a'] != NULL;
	}
	
	void addChar(char ch, Node* n1){
		alpha[ch-'a'] = n1;
	}
	Node* nextNode(char ch){
		return alpha[ch-'a'];
	}
	 
	void IncreaseEnd(){
		endWith++;
	}
	
	void IncreasePrefix(){
		counterPrefix++;
	}
	
	void deleteEnd(){
		endWith--;
	}
	
	void reducePrefix(){
		counterPrefix--;
	}
	
	int getEnd(){
		return endWith;
	}
		
	int getPrefix(){
		return counterPrefix;
	}
		
};

class Trie{
	private:
	Node* root;
    public:

    Trie(){
		root= new Node();
        // Write your code here.
    }


    void insert(string &word){
		Node* temp =root;
		for(int i=0;i<word.length();i++){
			if(!temp->isPresent(word[i])){
				temp->addChar(word[i], new Node() );
			}
			
			temp=temp->nextNode(word[i]);
			temp->IncreasePrefix();
		}
		temp->IncreaseEnd();
        // Write your code here.
    }


    int countWordsEqualTo(string &word){
		Node* temp =root;
		for(int i=0;i<word.length();i++){
			if(temp->isPresent(word[i])){
				temp=temp->nextNode(word[i]);
			}
			else
				return 0;
		}
		return temp->getEnd();
        // Write your code here.
    }



    int countWordsStartingWith(string &word){
		Node* temp =root;
        
		for(int i=0;i<word.length();i++){
			if(temp->isPresent(word[i])){
				temp=temp->nextNode(word[i]);
			}
			else
				return 0;
		}
		return temp->getPrefix();
        // Write your code here.
    }


    void erase(string &word){
		Node* temp =root;
		for(int i=0;i<word.length();i++){
				
				temp=temp->nextNode(word[i]);
				temp->reducePrefix();
		}
		temp->deleteEnd();
        // Write your code here.
    }
};
