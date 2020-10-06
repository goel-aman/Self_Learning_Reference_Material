class TrieNode{
	public:
		char data;
		TrieNode ** children;
		bool isTerminal;
		
	public:
		TrieNode(char data){
		this->data = data;
		isTerminal = false;
		children = new TrieNode*[26];
		
		for(int i=0;i<26;i++){
			children[i] = NULL;
		}
		}
		
};

class Trie{
	private:
	TrieNode * root;  
	
	public:
	void insertWord(string word){
			insertWord(root,word);
		}
		
	private:
		void insertWord(TrieNode * root,string word){
			//base Case
			if(word.size() == 0){
				root->isTerminal = true;
				return;
			}
			
			//small Calculation
			TrieNode *child;
			index = word[0] - 'a';
			if(root->children[index] != NULL){
				child = root->children[index];
			}
			else{
				child = new TrieNode(word[0]);
				root->children[index] = child;
			}
			
			// Recusion 
			insertWord(child,word.substr(1));
		}
};
