#include <cstring>
#include <utility>
#include <tuple>

namespace App {
    struct Account{

        int id;
        std::string nome_;
        int banco_;
        int agencia_;
        int conta_;
        float saldo_;

        Account(){/*empty*/}

        Account( int id_, std::string nome, int banco, int agencia, int conta, float saldo){
            id = id_;
            nome_ = nome;
            banco_ = banco;
            agencia_ = agencia;
            conta_ = conta;
            saldo_ = saldo;
        }

        int get_key(){
            return id;
        }

        void operator=( Account & ac ){
            this->id = ac.id;
            this->nome_ = ac.nome_;
            this->banco_ = ac.banco_;
            this->agencia_ = ac.agencia_;
            this->conta_ = ac.conta_;
            this->saldo_ = ac.saldo_;
        }
    };
    std::ostream& operator<<(std::ostream & os, const Account& rhs){
        os << " - CONTA - | ID = " << rhs.id ;
        os << " | NOME = " << rhs.nome_ << " | BANCO = " << rhs.banco_ << " | AGÊNCIA = " << rhs.agencia_ <<
              " | CONTA = " << rhs.conta_ << " | SALDO = " << rhs.saldo_ << " | ";
        return os;
    }

    template <class AcctKey>
    struct KeyHash;

    template <class AcctKey>
    struct KeyEqual;

    template <>
    struct KeyHash<int>
    {
        using AcctKey = int;
        size_t operator()(const AcctKey& k_)
        {
            return std::hash<int>()( k_ ) ;

            return 0;
        }
    };

    template <>
    struct KeyHash< std::pair<std::string, int> >
    {
        using AcctKey = std::pair<std::string, int>;
        size_t operator()(const AcctKey& k_)
        {
            return std::hash<std::string>()(k_.first) xor
                   std::hash<int>()(k_.second);

            return 0;
        }
    };

    template <>
    struct KeyHash< std::tuple<std::string, int, int, int> >
    {
        using AcctKey = std::tuple<std::string, int, int, int>;
        size_t operator()(const AcctKey& k_)
        {
            return  std::hash<std::string>()(std::get<0>(k_)) xor
                    std::hash<int>()(std::get<1>(k_)) xor
                    std::hash<int>()(std::get<2>(k_)) xor
                    std::hash<int>()(std::get<3>(k_));
        }

    };

    template <>
    struct KeyEqual<int>
    {
        using AcctKey = int;
        bool operator()(const AcctKey& lhs_, const AcctKey& rhs_)
        {
            return lhs_ == rhs_ ;
        }
    };

    template <>
    struct KeyEqual<std::pair<std::string, int>>
    {
        using AcctKey = std::pair<std::string, int>;
        bool operator()(const AcctKey& lhs_, const AcctKey& rhs_)
        {
            return lhs_ == rhs_ ;
        }
    };

    template <>
    struct KeyEqual<std::tuple<std::string, int, int, int>>
    {
        using AcctKey = std::tuple<std::string, int, int, int>;
        bool operator()(const AcctKey& lhs_, const AcctKey& rhs_)
        {
            return lhs_ == rhs_ ;
        }
    };

}



