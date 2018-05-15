/* 271. Encode and Decode Strings   QuestionEditorial Solution  My Submissions
 Total Accepted: 13164
 Total Submissions: 49920
 Difficulty: Medium
 Contributors: Admin
 Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.
 
 Machine 1 (sender) has the function:
 
 string encode(vector<string> strs) {
 // ... your code
 return encoded_string;
 }
 Machine 2 (receiver) has the function:
 vector<string> decode(string s) {
 //... your code
 return strs;
 }
 So Machine 1 does:
 
 string encoded_string = encode(strs);
 and Machine 2 does:
 
 vector<string> strs2 = decode(encoded_string);
 strs2 in Machine 2 should be the same as strs in Machine 1.
 
 Implement the encode and decode methods.
 
 Note:
 The string may contain any possible characters out of 256 valid ascii characters. Your algorithm should be generalized enough to work on any possible characters.
 Do not use class member/global/static variables to store states. Your encode and decode algorithms should be stateless.
 Do not rely on any library method such as eval or serialize methods. You should implement your own encode/decode algorithm.
 Hide Company Tags Google
 Hide Tags String
 Hide Similar Problems (E) Count and Say (H) Serialize and Deserialize Binary Tree

 */
class Codec {
public:
    
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        ostringstream oss;
        
        // record size
        oss << strs.size() << " ";
        
        // record lengths
        for (auto s : strs)
        {
            oss << s.length() << " ";
        }
        
        // record strings
        for (auto s : strs)
        {
            oss << s << " ";
        }
        return oss.str();
    }
    
    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> strs;
        vector<int> lens;
        
        // decode size
        int i = 0;
        int size = s.length();
        
        while (i < size && isdigit(s[i])) i++;
        
        int nums = stoi(s.substr(0, i)); i++;
        cout << "decode: s=" << s << ", nums=" << nums << endl;
        
        // for each num, decode "nums" lengths and store them in lens
        for (int j=0; j<nums; ++j)
        {
            int b = i;
            while (i < size && isdigit(s[i])) i++;
            int len = stoi(s.substr(b, i-b)); i++;
            lens.push_back(len);
        }
        
        for (int j=0; j<lens.size(); ++j)
        {
            int len = lens[j];
            string txt = s.substr(i, len); i++;
            strs.push_back(txt);
            i += len;
        }
        
        return strs;
        
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));
