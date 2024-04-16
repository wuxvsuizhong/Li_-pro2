#include <iostream>

#if 0
class myclass
{
private:
	class in//嵌套类私有,其所有的实例化的对象只能在myclass的类内部访问
	{
		private:
			int inx;//in的私有成员只能在in的内部访问
		public:
			int iny;
			in(int x,int y):inx(x),iny(y)
			{}
			void show()
			{
				std::cout<<"class in--> inx="<<inx<<"\tiny="<<iny<<std::endl;
			}
	}pin1;//同时实例化一个私有类成员
	int myx;//类私有成员
public:
	class pu//嵌套类公有
	{
		private:
			int pux;
		public:
			int puy;
			pu(int x,int y):pux(x),puy(y)
			{}
	}pu1;//同时实例化一个私有类成员

//	pu pu2(21,22);//实例化另一个公有类成员,这样实例化会报错，是否只能按照紧跟类声明之后才可以语法通过？
	int myy;//类公有成员
	myclass(int ix,int iy,int px,int py,int mx,int my)
		:pin1(ix,iy),pu1(px,py),myx(mx),myy(my)
	{}
	void showin()
	{	
	//	std::cout<<(this->pin1.inx)<<std::endl;//即使在类的内部，也不能访问嵌套类的私有成员，嵌套类私有成员只有嵌套类内部才可以访问
		this->pin1.show();
		std::cout<<this->pin1.iny<<std::endl;//可以访问私有嵌套类的公有成员
	}		
	void showpu()
	{
//		std::cout<<(this->pu1.pux)<<std::endl;//不能访问公有嵌套类的似有成员
		std::cout<<this->pu1.puy<<std::endl;
	}
};

int main()
{
	myclass m1(100,101,110,111,120,121);
	m1.showin();
//	std::cout<<m1.pin1.iny;//不能在实例化的类中访问私有嵌套类的任何成员
	return 0;
}
#endif

/************************普通类的嵌套****************************************/

template <class T> class myclass {
private:
  template <
      class
      V> // 此处用不同的泛型名称，如果类模版声明没有带有第二个类型名称，那么在该类中该泛型名称的作用范围仅限于有它存在的类范围
  class in {
  private:
    V v;

  public:
    in(V val) : v(val * 2) {}
    V &getv() { return this->v; }
    friend std::ostream &operator<<(std::ostream &os, const in<V> &I) {
      os << I.v;
      return os;
    }
  };
  T t1;
  in<T> v1;
  in<int> v2;
  in<T> v3; // 不能用V来出初始化in如（in<V>是错误的，因为myclass的初始化只有T）
public:
  myclass(T t, int i) : t1(t), v1(t), v2(i), v3(t) {}
  myclass(T t, T val, int i) : t1(t), v1(t), v2(i), v3(val) {}
  myclass(T t, T val, T val2, int i) : t1(t), v1(val), v2(i), v3(val2) {}

  void show() {
    std::cout << "t1=" << t1 << "\tv1=" << v1 << "\tv2=" << v2 << "\tv3=" << v3
              << std::endl;
  }
};

int main() {
  myclass<double> m1(11.1, 12);
  myclass<double> m2(22.2, 22.22, 22);
  myclass<double> m3(33.3, 33.33, 33.333, 33);
  m1.show();
  m2.show();
  m3.show();
  return 0;
}
