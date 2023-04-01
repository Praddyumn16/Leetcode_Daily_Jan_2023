class Solution {
public:
    bool detectCapitalUse(string word) {
        
        string temp = word;
        transform(temp.begin() , temp.end() , temp.begin() , ::toupper);

        if(word == temp)
            return true;
        
        transform(temp.begin() , temp.end() , temp.begin() , ::tolower);

        if(word == temp)
            return true;
        
        temp[0] = toupper(temp[0]);

        return word == temp;

    }
};