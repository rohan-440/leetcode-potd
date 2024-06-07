class Node
{
public:
    Node *links[26];
    bool flag = false;

    bool isContains(char ch)
    {
        return links[ch - 'a'] != NULL;
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node();
    }

    void insert(string s)
    {
        Node *temp = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (!temp->isContains(s[i]))
            {
                temp->put(s[i], new Node());
            }
            temp = temp->get(s[i]);
        }
        temp->setEnd();
    }

    string startsWith(string prefix)
    {
        Node *temp = root;
        string s = "";
        for (int i = 0; i < prefix.size(); i++)
        {
            if (temp->isContains(prefix[i]))
            {
                s.push_back(prefix[i]);
                temp = temp->get(prefix[i]);
                if (temp->isEnd())
                {
                    return s;
                }
            }
            else
            {
                break;
            }
        }
        return "";
    }
};

class Solution
{
public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        Trie *t = new Trie();
        for (int i = 0; i < dictionary.size(); i++)
        {
            t->insert(dictionary[i]);
        }
        stringstream ss(sentence);

        string word;
        string result = "";
        while (ss >> word)
        {
            string replacement = t->startsWith(word);
            if (replacement != "")
            {
                result += replacement;
            }
            else
            {
                result += word;
            }
            result += " ";
        }
        return result.substr(0, result.size() - 1);
    }
};