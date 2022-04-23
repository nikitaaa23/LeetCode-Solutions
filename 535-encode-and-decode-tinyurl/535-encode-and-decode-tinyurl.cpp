class Solution {
public:
    int id;
    unordered_map<string, string>mp;
    // Encodes a URL to a shortened URL.
    Solution(){
        id =1;
    }
    string encode(string longUrl) {
         string tinyUrl = "http://tinyurl.com/" + to_string(id);
        mp[tinyUrl] =  longUrl;
        id++;
        return tinyUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));