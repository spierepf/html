#include <string>
#include <map>

using namespace std;

void myReplace(string& str, const string& oldStr, const string& newStr)
{
    string::size_type pos = 0u;
    while((pos = str.find(oldStr, pos)) != std::string::npos) {
        str.replace(pos, oldStr.length(), newStr);
        pos += newStr.length();
    }
}

class HTMLNode
{
private:
    const string name;
    string content;
    map<string, string> attributes;

    string formatContent() {
        if(content.find("\n") == string::npos) return content;

        string retval = "\n" + content;
        myReplace(retval, "\n", "\n  ");

        return retval + "\n";
    }

    string formatAttributes() {
        string retval;

        for(map<string, string>::iterator it = attributes.begin(); it != attributes.end(); ++it) {
            retval += " " + it->first + "=\"" + it->second + "\"";
        }

        return retval;
    }

public:
    HTMLNode(const string& name = "") : name(name), content("") {}

    operator string() {
        if(name != "") {
            string retval = "";
            retval += "<" + name + formatAttributes();
            retval += (content == "") ? "/" : ">" + formatContent() + "</" + name;
            retval += ">";
            return retval;
        }
        return content;
    }

    HTMLNode& addContent(string text) {
        content += (content == "" ? "" : "\n") + text;

        return *this;
    }

    HTMLNode& addAttribute(string name, string value) {
        attributes.insert(std::map<string, string>::value_type(name, value));

        return *this;
    }
};
