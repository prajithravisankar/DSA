import math


class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        # idea: brute force
        # try the speed from 1 until h
        # track the total hours to complete all the piles
        # if we can complete it then we return that speed, as it will be the
        # minimum k as we are calculating from speed = 1
        current_speed = (
            1  # speed of bananas per hour so currently set at 1 banana per hour
        )
        while True:
            total_hours_spent_eating = 0
            for bananas in piles:
                total_hours_spent_eating += math.ceil(bananas / current_speed)
                # bananas / current_speed = number of bananas per (number of bananas per hour) =
                # number of hours, which we add it to tal hours spent eating
                # we use ceil because if a pile has 17 bananas, and our current speed is 5
                # 17 / 5 would be three point something, so we ceil it to 4. so 4 hours spent
                # eating 17 bananas.
            if total_hours_spent_eating <= h:
                return current_speed

            current_speed += 1

        return current_speed
        # time: O(m * n), where m = max(piles), and n = length of piles.
        # space: O(1)


# giving TIME LIMIT EXCEEDED.
