#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "Vector3f.hpp"

// Test that default constructor sets everything to 0.0
TEST_CASE("Default constructor test", "[Vector3f]") {

	// Default constructor
	Vector3f vector3F = Vector3f();

	REQUIRE(vector3F.x == Approx(0.0));
	REQUIRE(vector3F.y == Approx(0.0));
	REQUIRE(vector3F.z == Approx(0.0));
}

// Test that default constructor sets everything to 0.0
TEST_CASE("User constructor test", "[Vector3f]") {

	// User constructor
	Vector3f vector3F = Vector3f(1.1, 2.2, 3.4);

	REQUIRE(vector3F.x == Approx(1.1));
	REQUIRE(vector3F.y == Approx(2.2));
	REQUIRE(vector3F.z == Approx(3.4));
}

// Test that default constructor sets everything to 0.0
TEST_CASE("Copy constructor test", "[Vector3f]") {

	// User constructor
	Vector3f vector3F = Vector3f(1.1, 2.2, 3.4);

	// Copy constructor
	Vector3f copyVector = Vector3f(vector3F);

	// Test the original.
	REQUIRE(vector3F.x == Approx(1.1));
	REQUIRE(vector3F.y == Approx(2.2));
	REQUIRE(vector3F.z == Approx(3.4));

	// Test the copy.
	REQUIRE(copyVector.x == Approx(1.1));
	REQUIRE(copyVector.y == Approx(2.2));
	REQUIRE(copyVector.z == Approx(3.4));
}

TEST_CASE("(In)Equalities test", "[Vector3f]") {

	// Setup test vectors
	Vector3f vec1  = Vector3f(1, 2,3 );
	Vector3f vec2  = Vector3f(1, 2,3 );
	Vector3f vec3  = Vector3f(4, 3.4,324 );

	REQUIRE(operator==(vec1, vec2));
	REQUIRE_FALSE(operator==(vec1, vec3));
	REQUIRE_FALSE(operator==(vec2, vec3));

	REQUIRE_FALSE(operator!=(vec1, vec2));
	REQUIRE(operator!=(vec1, vec3));
	REQUIRE(operator!=(vec2, vec3));

}