class Solution
{
public:
    string minWindow(string s, string t)
    {
        // Utilisation d'un map desordonnee pour garder toutes les sous chaines
        unordered_map<string, int> map_substr;
        if (s.size() < t.size())
            return "";
        if (s == t)
            return s;
        string copy, copy1 = s, sub_veri;
        reverse(copy1.begin(), copy1.end());
        int pos_strt, nb = 0, pos_cont;
        bool see_first = false;
        for (auto car : copy1)
        {
            if (t.find(car) != string::npos)
            {
                pos_strt = s.size() - copy1.find(car) - 1;
                see_first = true;
            }
            if (see_first)
            {
                copy = t;
                sub_veri = s.substr(pos_strt);
                nb = 0;
                for (auto car : sub_veri)
                {
                    if ((pos_cont = copy.find(car)) != string::npos)
                    {
                        copy.erase(pos_cont, 1);
                    }
                    nb++;
                    if (copy.empty())
                        map_substr[s.substr(pos_strt, nb)] = s.substr(pos_strt, nb).size();
                }
            }
            see_first = false;
        }
        string result;
        int min = 0;
        for (auto mp : map_substr)
        {
            if (mp.second < min)
            {
                min = mp.second;
                result = mp.first;
            }
        }
        if (min)
            return result;
        return "";
    }
    // Demmain je terminerai avec ca, trop fatigue hhh
};