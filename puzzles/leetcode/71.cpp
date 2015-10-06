/****************************
Simplify Path: https://leetcode.com/problems/simplify-path/

Given an absolute path for a file (Unix-style), simplify it.
For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
**/

//@time complexity: O(n)
//@space complexity: O(n)
string simplifyPath(string path) {
    int firstPos = 0;
    int secondPos;
    stack<string> sStr;
    while (firstPos != -1) {
        firstPos = path.find('/', firstPos);
        if (firstPos == -1) {
            break;
        }
        secondPos = path.find('/', firstPos + 1);
        string content;
        if (secondPos != -1) {
            content = path.substr(firstPos + 1, secondPos - firstPos - 1);
        } else {
            content = path.substr(firstPos + 1);
        }
            
        if (content == "..") {
            if (!sStr.empty()) {
                sStr.pop();
            }
        } else if (content != "." && content != ""){
            sStr.push(content);
        }
        firstPos = secondPos;
    }
        
    string ret;
    while(!sStr.empty()) {
        ret = "/" + sStr.top() + ret;
        sStr.pop();
    }
        
    if (ret == "") {
        ret = "/";
    }
        
    return ret;
}
