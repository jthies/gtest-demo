#include <gtest/gtest.h>

#include "vector.hpp"
#include <memory>

class VectorTest: public testing::Test
{
  void SetUp()
  {
    len=5;
    d_v1=std::unique_ptr<Vector<double>>{new Vector<double>({1.1,2.2,3.3,4.4,5.5})};
    d_v2=std::unique_ptr<Vector<double>>{new Vector<double>({5.5,4.4,3.3,2.2,1.1})};
    d_v3=std::unique_ptr<Vector<double>>{new Vector<double>(len)};
    d_sum=6.6;
    i_sum=6;

    i_v1=std::unique_ptr<Vector<int>>{new Vector<int>({1,2,3,4,5})};
    i_v2=std::unique_ptr<Vector<int>>{new Vector<int>({5,4,3,2,1})};
    i_v3=std::unique_ptr<Vector<int>>{new Vector<int>(len)};
  }

  void TearDown()
  {
  }

public:

  int len;
  double d_sum; // result of d_v1+d_v2
  int i_sum; // result of i_v1+i_v2
  std::unique_ptr<Vector<double>> d_v1, d_v2, d_v3;
  std::unique_ptr<Vector<int>> i_v1, i_v2, i_v3;

};

//note: TEST_F will run tests in a 'test fixture' (class) context,
//      i.e. call SetUp before the test and TearDown afterwards.
TEST_F(VectorTest,add_d_d)
{
  EXPECT_NO_THROW(*d_v3=*d_v1 + *d_v2);
  // check if one element has the expected value
  ASSERT_FLOAT_EQ((*d_v3)[0],d_sum);
  // if we want to check all elements, we have to do it in a loop or using some proxy like the norm
  for (int i=0; i<len; i++)
    EXPECT_FLOAT_EQ((*d_v3)[i],d_sum);
}

TEST_F(VectorTest,add_d_d_buggy_test)
{
  EXPECT_NO_THROW(*d_v3=*d_v1 + *d_v2);
  // never try to exactly compare floating point numbers...
  for (int i=0; i<len; i++)
  {
    EXPECT_EQ((*d_v3)[i],d_sum);
  }
}

TEST_F(VectorTest,add_i_i)
{
  EXPECT_NO_THROW(*i_v3=*i_v1 + *i_v2);
  // check if one element has the expected value
  ASSERT_EQ((*i_v3)[0],i_sum);
}

TEST_F(VectorTest,add_throws_on_length_mismatch)
{
  Vector<double> v7(7);
  EXPECT_THROW(*d_v3=*d_v1+v7,std::exception);
}

TEST_F(VectorTest,subtract_throws_on_length_mismatch)
{
  Vector<double> v7(7);
  EXPECT_THROW(*d_v3=*d_v1-v7,std::exception);
}

TEST_F(VectorTest,add_mixed_d_i)
{
  auto result = *d_v1 + *i_v1;
  EXPECT_FLOAT_EQ(result[0],2.1);
}

TEST_F(VectorTest,add_mixed_i_d)
{
  auto result = *i_v1 + *d_v1;
  EXPECT_FLOAT_EQ(result[0],2.1);
}
