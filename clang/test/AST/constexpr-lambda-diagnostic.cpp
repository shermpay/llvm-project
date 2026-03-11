// RUN: %clang_cc1 -triple x86_64-linux-gnu -fsyntax-only -std=c++17 -verify=expected %s 
constexpr void undefined();  // expected-note {{declared here}}
static constexpr int r = [] { // expected-error {{constexpr variable 'r' must be initialized by a constant expression}} \
                                 expected-note {{in call to '[] {}.operator()()'}}}
  undefined();  // expected-note {{undefined function 'undefined' cannot be used in a constant expression}}
  return 0;
 }();

