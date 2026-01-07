class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        # idea: a speed to complete a pile of bananas are anywhere between 1 and max(piles)
        # find the current speed using binary search eliminating about half each time
        # compare the speed that we found using binary search works by checking if it completes all the bananas
        # by calculating total hours. if the total hours less than h, then keep that as our current result
        # and move right pointer to the left of our current speed by 1 to find even more minimal value
        # and if total hours greater than h, the our current speed we found is not high enough to finish within
        # h hours, so we move left pointer to the next speed of our current speed
        left, right = 1, max(piles)
        potential_speed = right  # pontential speed to complete all the bananas we need to find min of this

        while left <= right:
            current_speed_bananas_per_hour = (
                left + (right - left) // 2
            )  # returns an integer
            total_hours = 0
            for bananas in piles:
                # total_hours += math.ceil(float(bananas) / current_speed_bananas_per_hour)
                # if we want to not use math.ceil or flot
                total_hours += (
                    bananas + current_speed_bananas_per_hour - 1
                ) // current_speed_bananas_per_hour

            if total_hours <= h:
                potential_speed = current_speed_bananas_per_hour
                right = (
                    current_speed_bananas_per_hour - 1
                )  # we could try finding even lower

            else:
                # our current_speed_bananas_per_hour is not enough to complete all the bananas, so we increase the speed
                left = current_speed_bananas_per_hour + 1

        return potential_speed
        # time: O(nlogm), n = length of the piles (inner loop), and m = max(piles), and if we are doing binary search between 1 and m, it runs logm times
