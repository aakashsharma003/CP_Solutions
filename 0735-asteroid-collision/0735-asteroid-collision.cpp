class Solution {
public:
       vector<int> asteroidCollision(vector<int> &asteroids)
    {
        int n = asteroids.size();
        stack<int> mys;
        vector<int> res;
        mys.push(asteroids[0]);
        for (int i = 1; i < asteroids.size(); i++)
        {
            if (!mys.empty()&&mys.top() * asteroids[i] < 0)
            {   
            //   if(mys.top() > 0 && abs(mys.top()) == abs(asteroids[i])) mys.pop();
               
                if(mys.empty() == false&&mys.top()>0){
                while ( (!mys.empty()) && mys.top()>0 && (mys.top() * asteroids[i]) < 0 && (abs(mys.top()) < abs(asteroids[i])))
                    {mys.pop();}
                    if( mys.empty() == true || (mys.top() * asteroids[i] >0))mys.push(asteroids[i]);
                    else if((abs(mys.top()) == abs(asteroids[i])) && (mys.top()*asteroids[i]<0) ) mys.pop();}
                    else mys.push(asteroids[i]);
            }
            else mys.push(asteroids[i]);

            
        }
        while(!mys.empty()){
            res.push_back(mys.top());
            mys.pop();
        }
        reverse(res.begin() , res.end());
        return res;
    }
};