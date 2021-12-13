#include <iostream>

class Segment {
    double A,B;
public:
    Segment(double A, double B) : A(A), B(B) { }

    double GetA() const{return A;}
    double GetB() const{return B;}

    bool operator()(const double d)
    {
        return d >= GetA() && d <= GetB();
    }

    Segment operator*(double d) const{
        return Segment(GetA()*d, GetB()*d);
    };

    Segment operator/(double d) const{
        return Segment(GetA()/d, GetB()/d);
    };

    Segment operator+(double d) const{
        return Segment(GetA()+d, GetB()+d);
    };

    Segment operator-(double d) const{
        return Segment(GetA()-d, GetB()-d);
    };

    friend Segment operator*(double, const Segment&);
    friend Segment operator+(double, Segment&);
    friend Segment operator+(const Segment&, const Segment&);
    friend std::ostream& operator<<(std::ostream&, const Segment&);
};

Segment operator*(double d, const Segment& seg){
    return seg*d;
}

Segment operator+(double d, const Segment& seg){
    return seg+d;
}

Segment operator+(const Segment& seg, const Segment& seg2){
    return Segment(seg.GetA() > seg2.GetA() ? seg2.GetA() : seg.GetA(), seg.GetB() > seg2.GetB() ? seg.GetB() : seg2.GetB());
}

std::ostream& operator<<(std::ostream& stream, const Segment& seg){
    return stream << "[" << seg.GetA() << "," << seg.GetB() << "]";
}

int main() {
    using std::cout; using std::endl;
    Segment seg{2,3}, s = 1 + 2*((seg-2)/2+seg)/3;
    cout << s << endl << std::boolalpha;
    for (double x = 0.5; x < 4; x += 1)
        cout << "x=" << x << ": " << s(x) << endl;

    return 0;
}
