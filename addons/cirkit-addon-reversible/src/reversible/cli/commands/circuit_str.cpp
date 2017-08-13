/* CirKit: A circuit toolkit
 * Copyright (C) 2009-2015  University of Bremen
 * Copyright (C) 2015-2017  EPFL
 *
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

#include "circuit_str.hpp"

#include <alice/rules.hpp>

#include <reversible/cli/stores.hpp>
#include <reversible/functions/circuit_from_string.hpp>

namespace cirkit
{

circuit_str_command::circuit_str_command( const environment::ptr& env )
  : cirkit_command( env, "Show circuit as string" )
{
}

command::rules_t circuit_str_command::validity_rules() const
{
  return {has_store_element<circuit>( env )};
}

bool circuit_str_command::execute()
{
  const auto& circuits = env->store<circuit>();
  circuit_str = circuit_to_string( circuits.current() );

  std::cout << circuit_str << std::endl;

  return true;
}

command::log_opt_t circuit_str_command::log() const
{
  return log_opt_t({
      {"string", circuit_str}
    });
}


}

// Local Variables:
// c-basic-offset: 2
// eval: (c-set-offset 'substatement-open 0)
// eval: (c-set-offset 'innamespace 0)
// End: