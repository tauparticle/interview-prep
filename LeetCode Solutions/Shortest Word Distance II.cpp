/*
 This is a follow up of Shortest Word Distance. The only difference is now you are given the list of words and your method will be called repeatedly many times with different parameters. How would you optimize it?
 
 Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list.
 
 For example,
 Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
 
 Given word1 = “coding”, word2 = “practice”, return 3.
 Given word1 = "makes", word2 = "coding", return 1.
 
 Note:
 You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
 
 Hide Company Tags LinkedIn
 Hide Tags Hash Table Design
 Hide Similar Problems (E) Merge Two Sorted Lists (E) Shortest Word Distance (M) Shortest Word Distance III
*/

class WordDistance {
public:
    WordDistance(vector<string>& words) {
        for (int i=0; i<words.size(); ++i)
        {
            auto& pos = m_positions[words[i]];
            pos.push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        auto& pos1 = m_positions[word1];
        auto& pos2 = m_positions[word2];
        
        int minDistance = INT_MAX;
        int i=0;
        int j=0;
        while (i < pos1.size() && j < pos2.size())
        {
            minDistance = min(minDistance, abs(pos1[i] - pos2[j]));
            if (pos1[i] > pos2[j])
            {
                j++;
            }
            else
            {
                i++;
            }
        }
        return minDistance;
    }
    
private:
    
    unordered_map<string, vector<int>> m_positions;
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");