/**
* \file C_Point_Tests.cpp
* \brief Contains all tests for C_Point
* \author PB
* \date 2014/09/26
*/

#include "gtest/gtest.h"
#include "Geom/GTEST_ADDONS.h"

int main(int argc, char* argv[])
{
	int ret = 0;
	::testing::InitGoogleTest(&argc, argv);
	ret = RUN_ALL_TESTS();
	return ret;
}