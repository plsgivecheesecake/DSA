class Solution:
    def __init__(self):
        self.min_distance = float('inf')
    
    def look_left(self, words: List[str], target: str, startIndex: int) -> None:
        i = 1
        n = len(words)
        while (startIndex - i + n) % n != startIndex:
            if words[(startIndex - i + n) % n] == target:
                self.min_distance = min(self.min_distance, i)
                break
            i += 1

    def look_right(self, words: List[str], target: str, startIndex: int) -> None:
        i = 1
        n = len(words)
        while (startIndex + i) % n != startIndex:
            if words[(startIndex + i) % n] == target:
                self.min_distance = min(self.min_distance, i)
                break
            i += 1

    def closestTarget(self, words: List[str], target: str, startIndex: int) -> int:
        if words[startIndex] == target:
            return 0
        
        self.look_left(words, target, startIndex)
        self.look_right(words, target, startIndex)

        return -1 if self.min_distance == float('inf') else self.min_distance