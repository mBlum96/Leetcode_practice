import collections
import heapq
import functools

#solution using magic functions (appears to me at least)
#this is not a very good solution since we use max (O(n)) k times
#bringing our solution's time complexity to O(kn)
class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        words.sort()#first sort the words lexicographically
        #So when we later sort by frequency we don't get in
        #the return list a word with the same frequency
        #as the one expected but that should be after it
        #in lexicographical order
        count = collections.Counter(words)
        ret = []
        for i in range(k):
            MFStr = max(count,key=count.get)
            count.pop(MFStr)
            ret.append(MFStr)
        return ret

@functools.total_ordering
class Element:
    def __init__(self,count,word):
        self.count = count
        self.word = word
    def __lt__(self,other):
        if(self.count == other.count):
            return self.word>other.word
        else:
            return self.count<other.count
    def __eq__(self,other):
        return self.count==other.count and self.word==other.word
    

class Solution(object):
    def topKFrequent(self, words, k):
        counts = collections.Counter(words)   
        freqs = []
        heapq.heapify(freqs)
        for word, count in counts.items():
            heapq.heappush(freqs, (Element(count,word),word))
            if(len(freqs)>k):
                heapq.heappop(freqs)
        
        res = []
        for _ in range(k):
            res.append(heapq.heappop(freqs)[1])
        return res[::-1]
    