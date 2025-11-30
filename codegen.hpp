#ifndef _CODEGEN_HPP_
#define _CODEGEN_HPP_

#include <vector>
#include "node.hpp"

// ノードのリストを受け取り、アセンブリコード全体を生成して出力する関数
void codegen(std::vector<Node*> &nodes);

#endif
