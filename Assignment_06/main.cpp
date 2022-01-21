#include <iostream>

template <typename F, typename S>
class Pair {
    F fst;
    S scn;
public:
    explicit Pair(F first, S second) : fst(first), scn(second){};

    template<typename A, typename B>
    explicit Pair(const A& first, const B& second) : fst(static_cast<F>(first)), scn(static_cast<S>(second)){};

    template<typename A,typename B>
    explicit Pair(const Pair<A,B>& pair){
        fst = pair.first();
        scn = pair.second();
    }

    F first() const{
        return fst;
    }

    S second() const{
        return scn;
    }

    template<typename A,typename B>
    Pair& operator=(const Pair<A, B>& other){
        fst = static_cast<Pair<F, S>>(other).first();
        scn = static_cast<Pair<F, S>>(other).second();

        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Pair<F,S>& pair){
        return std::cout<<"["<<pair.first()<<","<<pair.second()<<"]";
    }


    template<typename F, typename S>
    friend bool operator<(const Pair<F,S>&, const Pair<F,S>& second);

    template<typename F, typename S>
    friend bool operator<=(const Pair<F,S>&, const Pair<F,S>& second);

    template<typename F, typename S>
    friend bool operator>(const Pair<F,S>&, const Pair<F,S>& second);

    template<typename F, typename S>
    friend bool operator>=(const Pair<F,S>&, const Pair<F,S>& second);

    template<typename F, typename S>
    friend bool operator==(const Pair<F,S>&, const Pair<F,S>& second);

    template<typename F, typename S>
    friend bool operator!=(const Pair<F,S>&, const Pair<F,S>& second);
};

template <typename F, typename S>
bool operator<(const Pair<F,S>& first, const Pair<F,S>& second){
    if(first.first() == second.first()){
        if(first.second() < second.second())
            return true;
    }
    else {
        if (first.first() < second.first())
            return true;
    }

    return false;
}

template <typename F, typename S>
bool operator<=(const Pair<F,S>& first, const Pair<F,S>& second){
    return (first < second) | (!(first < second) && first.second() == second.second());
}

template <typename F, typename S>
bool operator>(const Pair<F,S>& first, const Pair<F,S>& second){
    return !(first < second) && (first.second() != second.second());
}

template <typename F, typename S>
bool operator>=(const Pair<F,S>& first, const Pair<F,S>& second){
    return !(first < second) || (first < second && first.second() == second.second());
}

template <typename F, typename S>
bool operator==(const Pair<F,S>& first, const Pair<F,S>& second){
    return first.first() == second.first() && first.second() == second.second();
}

template <typename F, typename S>
bool operator!=(const Pair<F,S>& first, const Pair<F,S>& second){
    return first.first() != second.first() || first.second() != second.second();
}

template <typename PAIR>
void check(const PAIR& lhs, const PAIR& rhs) {
    using std::cout; using std::endl;
    auto flags = cout.flags();
    cout << std::boolalpha;
    cout << "\nLHS=" << lhs << " RHS=" << rhs << endl;

    cout << "lhs < rhs: " << (lhs < rhs) << endl;
    cout << "lhs <= rhs: " << (lhs <= rhs) << endl;
    cout << "lhs > rhs: " << (lhs > rhs) << endl;
    cout << "lhs >= rhs: " << (lhs >= rhs) << endl;
    cout << "lhs == rhs: " << (lhs == rhs) << endl;
    cout << "lhs != rhs: " << (lhs != rhs) << endl;
    cout.flags(flags);
}

int main () {
    check(Pair<int,int>(3,3), Pair<int,int>(4,2));
    check(Pair<int,int>(3,3), Pair<int,int>(3,2));
    check(Pair<int,int>(4,3), Pair<int,int>(4,3));
    Pair<int,int> pia{3,4};
    Pair<int,int> pib{4,5};
    Pair<double,double> pd(pia);
    std::cout << pia << std::endl;
    std::cout << pd << std::endl;
    pd = pib;
    std::cout << pd << std::endl;
}
