template<class U, class V>
class DynamicMemo
{
    private:
        int limit_wgt;
        int limit_range;
        std::size_t limit;
        std::set<std::pair<int, U>> keys;
        std::map<U, V> table;
        std::map<U, int> counter;

        void cleanup()
        {
            while(table.size() >= limit)
            {
                auto smallest = keys.begin();
                table.erase(smallest->second);
                counter.erase(smallest->second);
                keys.erase(smallest);
            }
            if(range() > limit_range)
            {
                reset_counts();
            }
        }

        void increment(U key)
        {
            auto temp = counter.find(key);
            if(temp->second < limit_wgt)
            {
                keys.erase({temp->second, key});
                keys.insert({++temp->second, key});
            }
        }

        int range()
        {
            return (keys.rend() -> first) - (keys.begin() -> first);
        }

    public:
        DynamicMemo(int max_weight, int max_range, std::size_t max_size)
            : limit_wgt(max_weight), limit_range(max_range), limit(max_size)
        {}

        bool exists(U key)
        {
            return counter.find(key) != counter.end();
        }

        void insert(U key, V val)
        {
            if(exists(key))
            {
                increment(key);
            }
            else
            {
                counter[key] = 1;
                table[key] = val;
                keys.insert({1, key});
                cleanup();
            }
        }

        V get_value(U key)
        {
            increment(key);
            return table[key];
        }

        void reset_counts()
        {
            keys.clear();
            for(auto& i : table)
            {
                counter[i.first] = 0;
                keys.insert({0, i.first});
            }
        }
};
