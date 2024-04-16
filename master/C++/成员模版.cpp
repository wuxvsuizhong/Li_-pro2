#include <iostream>

template <class T> class beta {
private:
  template <class V> // beta私有部分申明的模版类hold。只能在beta类的内部访问hold
  class hold {
  private:
    V val;

  public:
    hold(V v = 0) : val(v) {}
    void show() const { std::cout << "hold --> val :" << val << std::endl; }
    V Value() const { return val; }
  };
  hold<T> q;
  hold<int> n;

public:
  beta(T t, int i) : q(t), n(i) {}
  template <class U> U blab(U u, T t) {
    return ((n.Value() + q.Value()) * u / t);
  }
  void show() const {
    q.show();
    n.show();
  }
};

int main() {
  beta<double> guy(3.5, 3);
  std::cout << "T was set to double" << std::endl;
  guy.show();
  std::cout << "V was set to T,which is double,then V was set to int\n";
  std::cout << guy.blab(10, 2.3) << std::endl;
  std::cout << "U was set to int" << std::endl;
  std::cout << guy.blab(10.0, 2.3) << std::endl;
  std::cout << "U was set to double" << std::endl;
  std::cout << "Donw" << std::endl;
  return 0;
}
