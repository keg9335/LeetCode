class Twitter:

    def __init__(self):
        self.posts = []
        self.follows = {}
        

    def postTweet(self, userId: int, tweetId: int) -> None:
        self.posts.append((userId, tweetId))
        

    def getNewsFeed(self, userId: int) -> List[int]:
        feeds = []
        for user, tweet in self.posts[::-1]:
            if user == userId or (userId in self.follows and user in self.follows[userId]):
                feeds.append(tweet)
                if len(feeds) == 10:
                    break
        return feeds
        

    def follow(self, followerId: int, followeeId: int) -> None:
        if followerId not in self.follows:
            self.follows[followerId] = set()
        self.follows[followerId].add(followeeId)
        

    def unfollow(self, followerId: int, followeeId: int) -> None:
        if followerId in self.follows:
            self.follows[followerId].remove(followeeId)

            



# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)