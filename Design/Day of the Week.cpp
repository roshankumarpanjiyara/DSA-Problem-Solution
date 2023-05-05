class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        string dayOfWeek[7] = {"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
        int dayOfMonthMod7[12] = {0,3,2,5,0,3,5,1,4,6,2,4};
        if(month < 3){
            year--;
        } 
        return dayOfWeek[(year + (year/4-year/100+year/400) + dayOfMonthMod7[month-1] + day)%7];
    }
};
