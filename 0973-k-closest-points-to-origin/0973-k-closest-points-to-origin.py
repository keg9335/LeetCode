class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        heap = []
        for point in points:
            distance = math.sqrt(point[0]**2 + point[1]**2)
            heappush(heap, [distance, point])
            
        result = []
        for _ in range(k):
            result.append(heappop(heap)[1])

        return result
        
        