#ifndef _EXECUTE_HPP_
#define _EXECUTE_HPP_

#include "ast.hpp"
#include "object.hpp"
#include "operator.hpp"
#include "state.hpp"

// 執行
Object* execute(State& scope);

#endif