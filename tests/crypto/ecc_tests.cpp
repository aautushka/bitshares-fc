
#include <boost/test/unit_test.hpp>

#include <fc/crypto/elliptic.hpp>

using namespace fc;

BOOST_AUTO_TEST_SUITE(ecc_tests)

BOOST_AUTO_TEST_CASE(encrypts_message)
{
    auto privkey = fc::ecc::private_key::generate();
    auto pubkey = privkey.get_public_key();

    auto message = std::vector<char>{1, 2, 3, 4};
    auto cipher = pubkey.encrypt(message);

    BOOST_CHECK(message == privkey.decrypt(cipher));
}

BOOST_AUTO_TEST_SUITE_END()
