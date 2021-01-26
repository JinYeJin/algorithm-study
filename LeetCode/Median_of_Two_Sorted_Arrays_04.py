class Solution:
    def merge(left, right):
        v=list()
        i=0
        j=0
        while(i<len(left) and j<len(right)):
            if left[i] <= right[j]:
                v.append(left[i])
                i+=1
            else:
                v.append(right[j])
                j+=1
        if i==len(left): 
            v = v + right[j:len(right)]
        if i==len(right): 
            v = v + left[i:len(left)]
        return v
    
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        merge_list = list(merge(nums1,nums2))
        mid = len(merge_list)//2
        if len(merge_list)%2 == 0:
            return (merge_list[mid-1] + merge_list[mid])/2
        else:
            return merge_list[mid]