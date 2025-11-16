#include <iostream>
#include <vector>
using namespace std;

template <typename I, typename F>
void my_for_each(I b, I e, F f) {
    for (; b != e; ++b) f(*b);
}

template <typename I1, typename I2, typename F>
I2 my_transform(I1 b, I1 e, I2 d, F f) {
    for (; b != e; ++b, ++d) *d = f(*b);
    return d;
}

template <typename I1, typename I2, typename P>
I2 my_copy_if(I1 b, I1 e, I2 d, P p) {
    for (; b != e; ++b) if (p(*b)) *d++ = *b;
    return d;
}

template <typename I, typename P>
I my_find_if(I b, I e, P p) {
    for (; b != e; ++b) if (p(*b)) return b;
    return e;
}

template <typename I, typename T, typename O>
T my_accumulate(I b, I e, T v, O op) {
    for (; b != e; ++b) v = op(v, *b);
    return v;
}

int main() {
    vector<int> v = {1,2,3,4,5};
    my_for_each(v.begin(), v.end(), [](int& x){x*=2;});
    for (int x:v) cout<<x<<" "; cout<<"\n";
    vector<int> o(v.size());
    my_transform(v.begin(), v.end(), o.begin(), [](int x){return x+1;});
    for (int x:o) cout<<x<<" "; cout<<"\n";
    vector<int> e(v.size());
    auto it = my_copy_if(v.begin(), v.end(), e.begin(), [](int x){return x%2==0;});
    e.resize(it-e.begin());
    for (int x:e) cout<<x<<" "; cout<<"\n";
    auto f = my_find_if(v.begin(), v.end(), [](int x){return x>6;});
    if (f!=v.end()) cout<<*f<<"\n"; else cout<<"none\n";
    cout<<my_accumulate(v.begin(), v.end(), 0, [](int a,int b){return a+b;})<<"\n";
}
