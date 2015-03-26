class Solution {
public:
    string simplifyPath(string path) {
        deque< string> qu;	
		size_t pos=0,posn;

		while(pos != path.size())
		{
			posn = path.find('/',pos+1);
			if(posn==string::npos) posn=path.size();

			string tmp(path,pos,posn-pos);

			if(tmp=="/") {
			}
			else if(tmp=="/..") {
				if(qu.size()) qu.pop_back();
			}
			else if(tmp=="/.") {
			}
			else {
				qu.push_back(tmp);
			}

			pos=posn;
		}

		string str = qu.size() ? "" : "/";

		while(qu.size())
		{
			str.append(qu.front());
			qu.pop_front();
		}
        
		return str;
    }
};
