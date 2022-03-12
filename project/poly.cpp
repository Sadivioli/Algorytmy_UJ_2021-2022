#include "poly.h"
using namespace std;

Polynomial::Polynomial(){
    //konstruktor domyślny
    //wielomian jest zerowy ~ pusty
}
Polynomial::Polynomial(const vector<int>& coeff, const vector<int>& degree){
    
    if (coeff.size() != degree.size()){
        cout << "Wystąpił błąd. Liczba współczynników musi być równa liczbie stopni" << endl;
        return;
    }else{
        for(int i = 0; i < coeff.size(); i++){
            Node term;
            term.coeff = coeff[i];
            term.degree = degree[i];
            poly.push_back(term);
        }
    }
}

Polynomial::~Polynomial(){
    poly.clear();
}

void Polynomial::printPoly(){
    for(list<Node>::iterator it = poly.begin(); it != poly.end(); it++){
        cout << it->coeff << "x^" << it->degree << " ";
    }
    cout << endl;
}

double Polynomial::hornerEval(int x){
    double result = 0;
    for(list<Node>::const_iterator it = poly.begin(); it != poly.end(); it++){
        result = result * x + it->coeff;
    }
    return result;
}

void Polynomial::polySiplify(){
    list<Node>::iterator it = poly.begin();
    while(it != poly.end()){
        list<Node>::iterator it2 = it;
        it2++;
        while(it2 != poly.end()){
            if(it->degree == it2->degree){
                it->coeff += it2->coeff;
                it2 = poly.erase(it2);
            }else{
                it2++;
            }
        }
        it++;
    }
}

Polynomial Polynomial::operator+(const Polynomial&toAdd) const {

    Polynomial result;

    //iterator po elementach pierwszego wielomianu
    list<Node>::const_iterator it1 = poly.begin();

    //iterator po elementach drugiego wielomianu
    list<Node>::const_iterator it2 = toAdd.poly.begin();

    //wykonujemy aż dotrzemy do końca wielomianu o wyższym stopniu
    while(it1 != poly.end() || it2 != toAdd.poly.end()){
        //dodawanie współczynników o takich samych potęgach
        if(it1->degree == it2->degree){
            Node term;
            term.coeff = it1->coeff + it2->coeff;
            term.degree = it1->degree;
            result.poly.push_back(term);
            it1++;
            it2++;
        }
        //Wielomian "z lewej" strony operatora ma wyższy stopień:
            //-przepisujemy współczynnik i przechodzimy do następnego term
            //-powtarzamy aż do momentu dodawania współczynników przy takich samych potęgach
        else if(it1->degree > it2->degree){
            Node term;
            term.coeff = it1->coeff;
            term.degree = it1->degree;
            result.poly.push_back(term);
            it1++;
        }
        else{
            Node term;
            term.coeff = it2->coeff;
            term.degree = it2->degree;
            result.poly.push_back(term);
            it2++;
        }
    }
    return result;
}

Polynomial Polynomial::operator-(const Polynomial &toSub) const {

    Polynomial result;

    list<Node>::const_iterator it1 = poly.begin();

    list<Node>::const_iterator it2 = toSub.poly.begin();

    while(it1 != poly.end() || it2 != toSub.poly.end()){
        if(it1->degree == it2->degree){
            Node term;
            term.coeff = it1->coeff - it2->coeff;
            term.degree = it1->degree;
            result.poly.push_back(term);
            it1++;
            it2++;
        }
        else if(it1->degree > it2->degree){
            Node term;
            term.coeff = it1->coeff;
            term.degree = it1->degree;
            result.poly.push_back(term);
            it1++;
        }
        else{
            Node term;
            term.coeff = -it2->coeff;
            term.degree = it2->degree;
            result.poly.push_back(term);
            it2++;
        }
    }
    return result;
}

Polynomial Polynomial::operator*(const Polynomial &toMul) const {
    Polynomial product;
    list<Node>::const_iterator it1 = poly.begin();
    list<Node>::const_iterator it2 = toMul.poly.begin();

    while(it1 != poly.end()){
        while(it2 != toMul.poly.end()){
            Node term;
            term.coeff = it1->coeff * it2->coeff;
            term.degree = it1->degree + it2->degree;
            product.poly.push_back(term);
            it2++;
        }
        it2 = toMul.poly.begin();
        it1++;
    }
    return product;
}