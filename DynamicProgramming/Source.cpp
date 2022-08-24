//#include <iostream>
//#include <vector>
//#include <list>
//using namespace std;
//int LIS_BottomUp(vector<int>& v, vector<pair<int, int>>& sequenceL, int n) {
//    int maxIndex = 0;
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < i; j++) {
//            if (v[j]<v[i] && sequenceL[j].first + 1>sequenceL[i].first) {
//                sequenceL[i].first = sequenceL[j].first + 1;
//                sequenceL[i].second = j;
//            }
//        }
//        if (sequenceL[i].first > sequenceL[maxIndex].first)
//            maxIndex = i;
//    }
//    return maxIndex;
//}
//list<int> getSequence(vector<pair<int, int>>& seq, vector<int>& v, int indexMax) {
//    list<int>result;
//
//    while (indexMax != -1) {
//        result.emplace_front(v[indexMax]);
//        indexMax = seq[indexMax].second;
//    }
//    return result;
//}
//
////int main() {
////    int n;
////    cin >> n;
////    vector<int>v(n);
////    vector<pair<int, int>>sequenceL(n, make_pair(1, -1));
////    for (int& x : v)cin >> x;
////
////    int maxIndex = LIS_BottomUp(v, sequenceL, n);
////
////    cout << "LIS : " << sequenceL[maxIndex].first << endl;
////    list<int> l = getSequence(sequenceL, v, maxIndex);
////    for (auto x : l)
////        cout << x << " ";
////    return 0;
////}