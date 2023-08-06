class Solution {
public:
    int MOD = 1e9+7;
    int t[101][101];
    long solve(int song,int unique, int n, int goal, int k){
        if(song == goal){
            if(unique == n){
                return 1;
            }
            return 0;
        }
        if(t[song][unique] != -1){
            return t[song][unique];
        }
        long result = 0;
        if(unique < n){
            result += (n - unique) * solve(song + 1, unique + 1, n, goal, k); // play unique songs
        }
        if(unique > k){
            result += (unique - k) * solve(song + 1, unique, n, goal, k); // replay a song
        }

        return t[song][unique] = result % MOD;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        memset(t, -1, sizeof(t));
        return solve(0, 0, n, goal, k);
    }
};
