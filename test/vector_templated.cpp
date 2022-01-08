#include <gtest/gtest.h>

#include "vector.hpp"
#include <memory>

#include <complex>

template<typename T>
struct is_complex_type{static const bool value=false;};

template<typename T>
struct is_complex_type<std::complex<T>>{static const bool value=true;};

template<typename T>
constexpr bool is_complex(){return is_complex_type<T>::value;}


/* example of testing different instantiations of a templated class
 */
template<typename T>
class TVectorTest: public testing::Test
{
  void SetUp()
  {
    len=5;
    v1=std::unique_ptr<Vector<T>>{new Vector<T>({1.1,2.2,3.3,4.4,5.5})};
    v2=std::unique_ptr<Vector<T>>{new Vector<T>({5.5,4.4,3.3,2.2,1.1})};
    v3=std::unique_ptr<Vector<T>>{new Vector<T>(len)};
    sum=T(6.6);
    // for complex data make it a bit more interesting:
    if constexpr (is_complex<T>()){
      for (int i=0; i<len; i++) (*v1)[i] += T({0,1});
      sum+=T({0,1});
    }
  }

  void TearDown()
  {
  }

public:

  int len;
  T sum; // result of d_v1+d_v2
  std::unique_ptr<Vector<T>> v1, v2, v3;

};

// instantiate the tests for these types:
using scalar_types=::testing::Types<float,double,std::complex<float>,std::complex<double>>;

TYPED_TEST_CASE(TVectorTest, scalar_types);

TYPED_TEST(TVectorTest, add)
{
  using TF=TestFixture;
  *(TF::v3) = *(TF::v1) + *(TF::v2);
  EXPECT_FLOAT_EQ(std::real((*TF::v3)[0]),std::real(TF::sum));
  EXPECT_FLOAT_EQ(std::imag((*TF::v3)[0]),std::imag(TF::sum));
}
