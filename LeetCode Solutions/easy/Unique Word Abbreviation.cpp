/*
 288. Unique Word Abbreviation   QuestionEditorial Solution  My Submissions
 Total Accepted: 17486
 Total Submissions: 113403
 Difficulty: Easy
 Contributors: Admin
 An abbreviation of a word follows the form <first letter><number><last letter>. Below are some examples of word abbreviations:
 
 a) it                      --> it    (no abbreviation)
 
 1
 b) d|o|g                   --> d1g
 
 1    1  1
 1---5----0----5--8
 c) i|nternationalizatio|n  --> i18n
 
 1
 1---5----0
 d) l|ocalizatio|n          --> l10n
 Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary. A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.
 
 Example:
 Given dictionary = [ "deer", "door", "cake", "card" ]
 
 isUnique("dear") -> false
 isUnique("cart") -> true
 isUnique("cane") -> false
 isUnique("make") -> true
 Hide Company Tags Google
 Hide Tags Hash Table Design
 Hide Similar Problems (E) Two Sum III - Data structure design (M) Generalized Abbreviation

 */

class ValidWordAbbr {
public:
    
    /* This is hard as fuck to understand.
     The description (A word's abbreviation is unique if no other word from the dictionary has the same abbreviation) is clear however a bit twisting. It took me a few "Wrong Answer"s to finally understand what it's asking for.
     We are trying to search for a word in a dictionary. If this word (also this word’s abbreviation) is not in the dictionary OR this word and only it’s abbreviation in the dictionary. We call a word’s abbreviation unique.
     */
    ValidWordAbbr(vector<string> &dictionary) {
        
        for (auto& word : dictionary)
        {
            string abr = getAbbr(word);
            unordered_set<string>& list = m_abbrs[abr];
            list.insert(word);
        }
        
    }
    
    bool isUnique(string word) {
        string abr = getAbbr(word);
        if (m_abbrs.find(abr) != m_abbrs.end())
        {
            auto& list = m_abbrs[abr];
            if (list.size() == 1 && list.find(word) != list.end())
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    
private:
    
    string getAbbr(const string& str)
    {
        int len = str.length()-2;
        if (len <= 0) return str;
        return str[0] + to_string(len) + str[str.length()-1];
    }
    
    unordered_map<string, unordered_set<string>> m_abbrs;
};


// Your ValidWordAbbr object will be instantiated and called as such:
// ValidWordAbbr vwa(dictionary);
// vwa.isUnique("hello");
// vwa.isUnique("anotherWord");
