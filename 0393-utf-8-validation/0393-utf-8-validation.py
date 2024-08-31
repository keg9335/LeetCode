class Solution:
    def validUtf8(self, data: List[int]) -> bool:
        mask_msb = [0x80, 0xE0, 0xF0, 0xF8]
        masked_msb_val = [0, 0xC0, 0xE0, 0xF0]
        mask = 0xC0
        masked_val = 0x80
        idx = 0
        while idx < len(data):
            for k in range(4):
                if (data[idx] & mask_msb[k]) == masked_msb_val[k]:
                    for check_idx in range(1, k+1):
                        if idx + check_idx >= len(data): return False
                        elif data[idx + check_idx] & mask != masked_val:
                            return False
                    idx += k+1
                    break
            else:
                return False
        
        return True