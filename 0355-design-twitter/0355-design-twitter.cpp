#define pii pair<int, int>
class Twitter {
public:
    int timer = 0;
    map<int, set<int>> follows;
    map<int, set<int>> followers;
    map<int, vector<pii>> posts; 
    int tweetCount = 10;
    Twitter() {
       
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({timer, tweetId});
        timer++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pii> feed;
        set<int> peopleId = follows[userId];
        peopleId.insert(userId);
        for (auto followee: peopleId){
            vector<pii> p = posts[followee];
            if (p.empty()) continue;
            for (int i = p.size() - 1; i >= max(0, (int)p.size() - tweetCount); i--){
                feed.push(p[i]);
            }
        }
        vector<int> ans;
        while(!feed.empty() && ans.size() < tweetCount){
            ans.push_back(feed.top().second);
            feed.pop();
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */