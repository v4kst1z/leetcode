//
// Created by v4kst1z on 2021/3/24.
//

class Twitter {
private:
    int tw_id;
    struct User {
        int user_id;
        vector<int> follow;
        vector<pair<int, int>> twitter_id;
    };
    vector<struct User *> users;
public:
    /** Initialize your data structure here. */
    Twitter() : tw_id(0), users(10000, nullptr) {

    }

    ~Twitter() {
        for(int id = 0; id < 10000; id++)
            if(users[id])
                delete users[id];
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if(!users[userId]) {
            struct User * user = new User();
            user->user_id = userId;
            user->twitter_id.push_back(pair<int, int>(tw_id++, tweetId));
            users[userId] = user;
        } else {
            users[userId]->twitter_id.push_back(pair<int, int>(tw_id++, tweetId));
        }
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        if(!users[userId])
            return {};

        vector<pair<int, int>> all;
        all.insert(all.begin(), users[userId]->twitter_id.begin(), users[userId]->twitter_id.end());
        for(auto id: users[userId]->follow) {
            for(auto &elem: users[id]->twitter_id) {
                all.push_back(elem);
            }
        }
        sort(all.begin(), all.end(), [](pair<int, int> &a, pair<int, int> &b) {
            return a.first > b.first;
        });
        vector<int> result;
        if(all.size() >= 10)
            for(int id = 0; id < 10; id++)
                result.push_back(all[id].second);
        else
            for(auto &elem: all)
                result.push_back(elem.second);
        return result;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followeeId == followerId) return;
        if(!users[followerId]) {
            struct User * user = new User();
            users[followerId] = user;
        }
        if(!users[followeeId]) {
            struct User * user = new User();
            user->user_id = followeeId;
            users[followeeId] = user;
        }
        vector<int>::iterator it = find(users[followerId]->follow.begin(), users[followerId]->follow.end(), followeeId);
        if(it == users[followerId]->follow.end())
            users[followerId]->follow.push_back(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(!users[followerId])
            return;

        vector<int>::iterator it = find(users[followerId]->follow.begin(), users[followerId]->follow.end(), followeeId);
        if(it != users[followerId]->follow.end())
            users[followerId]->follow.erase(it);
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