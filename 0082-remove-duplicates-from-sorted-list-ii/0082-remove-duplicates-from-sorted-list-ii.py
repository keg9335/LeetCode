# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def deleteDuplicates(self, head: Optional[ListNode]) -> Optional[ListNode]:
        head_deduplicated = head
        prev, curr = None, head

        while curr:
            if curr.next and curr.next.val == curr.val:
                while curr.next and curr.next.val == curr.val:
                    curr = curr.next
                if prev:
                    prev.next = curr.next
                else:
                    head_deduplicated = curr.next
                curr = curr.next                    # type: ignore
            else:
                prev, curr = curr, curr.next            # type: ignore

        return head_deduplicated
        