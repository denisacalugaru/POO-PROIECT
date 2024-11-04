#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>

class Ingredient {
private:
  std::string nume;
  std::string tip;

public:
  Ingredient(std::string  nume,  std::string  tip ): nume(std::move(nume)), tip(std::move(tip)){}

  [[nodiscard]]const std::string& getNume()const{return nume;}
  [[nodiscard]]const std::string& getTip()const{return tip;}


  friend std::ostream& operator<<(std::ostream& os, const Ingredient& ingr) {
    os << ingr.nume << " " << "(" <<ingr.tip << ")";
    return os;
  }
  ~Ingredient()= default;
};


class Preparat {
private:
  std::string nume;
  float pret;
  float gramaj;
  std::vector<Ingredient> ingrediente;

public:

  Preparat(std::string  nume, float pret, float gramaj, const std
    ::vector<Ingredient>& ingrediente)
  :nume(std::move(nume)), pret(pret),gramaj(gramaj), ingrediente(ingrediente){}

  Preparat(const Preparat& prep)
  : nume(prep.nume), pret(prep.pret),gramaj(prep.gramaj), ingrediente(prep.ingrediente) {}

  Preparat& operator=(const Preparat& prep) {
    if (this != &prep) {
      nume = prep.nume;
      pret = prep.pret;
      gramaj = prep.gramaj;
      ingrediente = prep.ingrediente;
    }
    return *this;
  }

  [[nodiscard]] bool esteVegetarian() const {
    for (const auto& ingr : ingrediente) {
      if (ingr.getTip() == "carne" || ingr.getTip() == "peste") {
        return false;
      }
    }
    return true;
  }

  [[nodiscard]] const std::string& getNume()const{return nume;}
  [[nodiscard]] float getPret()const{return pret;}

  friend std::ostream& operator<<(std::ostream& os, const Preparat& prep) {
    os<< "Preparat: " << prep.nume << " -Pret: " << prep.pret << "  RON\n";
    os<< "Ingrediente: \n";
    for (const auto& ingr:prep.ingrediente) {
      os << "  -" << ingr << "\n";
    }
    return os;
  }
  ~Preparat()= default;

};

  class Categorie {
  private:
    std::string nume;
    std::vector<Preparat> preparate;

  public:
    //constructor de initializare
    Categorie( const std::string& nume, const std::vector<Preparat>& preparate):nume(std::move(nume)),preparate(preparate){}

    // Funcție de ordonare alfabetic
    void ordoneazaPreparateAlfabetic() {
      std::ranges::sort(preparate, [](const Preparat& a, const Preparat& b) {
        return a.getNume() < b.getNume();
      });
    }
    [[nodiscard]] std::string getNume()const{return nume;}

    friend std::ostream& operator<<(std::ostream& os, const Categorie& cat) {
      os<<"Categorie: "<<cat.nume<< "\n";
      for(const auto& prep:cat.preparate) {
        os << prep << "\n";
      }
      return os;
    }
    ~Categorie()= default;
  };

    class Meniu {
      private:
      std::vector<Categorie> categorii;
      public:

      explicit Meniu(const std::vector<Categorie>& cat):categorii(cat){}

      void ordoneazaCategorii() {
        for (auto& categorie : categorii) {
          categorie.ordoneazaPreparateAlfabetic();
        }
      }

      static double calcularePretTotal(const std::vector<Preparat>& preparateComandate) {
        double total = 0.0;
        for (const auto& preparat : preparateComandate) {
          total += preparat.getPret();
        }
        return total;
      }

      friend std::ostream& operator<<(std::ostream& os, const Meniu& men) {
        os << "Meniu:\n";
        for(const auto& categorie : men.categorii) {
          os << categorie << "\n";
        }
        return os;
      }
      ~Meniu()= default;
    };
int main() {

  Ingredient ingr1("Rosii", "legumee");
  Ingredient ingr2("Mozzarella", "lactate");
  Ingredient ingr3("Busuioc", "condiment");
  Ingredient ingr4("Pui", "carne");
  Ingredient ingr5("Sos de rosii", "sos");
  Ingredient ingr6("Ciocolata", "dulciuri");
  Ingredient ingr7("Faina","cereale");
  Ingredient ingr8("Oua","aliment");
  Ingredient ingr9("Lapte", "lactate");
  Ingredient ingr10("Vita", "carne");
  Ingredient ingr11("Ulei", "cereale");
  Ingredient ingr12("Branza Cheddar", "lactate");
  Ingredient ingr13("Branza de vaci", "lactate");
  Ingredient ingr14("Dulceata de visine","dulciuri");
  Ingredient ingr15("Cafeina", "plante");
  Ingredient ingr16("Frunze tei", "plante");
  Ingredient ingr17("Apa", "lichide");


  //lista preparate
  Preparat prep1("Salata", 15.5, 250, {ingr1, ingr2, ingr3, ingr11});
  Preparat prep2("Pizza cu pui", 25.0,350, {ingr1, ingr2, ingr4, ingr5, ingr7, ingr11});
  Preparat prep3("Pizza Margherita", 20, 250,{ingr1, ingr2, ingr3, ingr7, ingr11});
  Preparat prep4("Clatite cu ciocolata", 18, 300, {ingr6, ingr7, ingr8, ingr9,ingr11});
  Preparat prep5("Burger vita", 22, 400, {ingr7, ingr1, ingr2, ingr3, ingr11, ingr12});
  Preparat prep6("Bruschete",12, 200, {ingr1, ingr2, ingr3,ingr11});
  Preparat prep7("Papanasi", 20, 300, {ingr14, ingr13, ingr11, ingr9, ingr8, ingr7});
  Preparat prep8("Cafea", 10, 100,{ingr15});
  Preparat prep9("Ceai", 8, 100, {ingr16, ingr17});

  //lisra categorii de preparate
  Categorie aperitive("Aperitive", {prep1, prep6});
  Categorie feluriPrincipale("Feluri Principale", {prep2, prep3,prep5});
  Categorie desert("Desert", {prep4, prep7});
  Categorie bautura("Bautura", {prep8, prep9});

  Meniu meniu({aperitive, feluriPrincipale, desert, bautura});

  meniu.ordoneazaCategorii();

  std::cout << meniu;

  std::cout << "\nVerificare preparate vegetariene:\n";
  std::cout << prep1.getNume() << " este vegetarian: " << (prep1.esteVegetarian() ? "Da" : "Nu") << "\n";
  std::cout << prep2.getNume() << " este vegetarian: " << (prep2.esteVegetarian() ? "Da" : "Nu") << "\n\n";

  std::vector<Preparat> preparateComandate = {prep2, prep3};
  double total = Meniu::calcularePretTotal(preparateComandate);
  std::cout << "Pretul total al preparatelor comandate: " << total << " RON\n";

  return 0;
}






