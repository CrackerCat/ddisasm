//===- X86Decoder.h ---------------------------------------------*- C++ -*-===//
//
//  Copyright (C) 2020 GrammaTech, Inc.
//
//  This code is licensed under the GNU Affero General Public License
//  as published by the Free Software Foundation, either version 3 of
//  the License, or (at your option) any later version. See the
//  LICENSE.txt file in the project root for license terms or visit
//  https://www.gnu.org/licenses/agpl.txt.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//  GNU Affero General Public License for more details.
//
//  This project is sponsored by the Office of Naval Research, One Liberty
//  Center, 875 N. Randolph Street, Arlington, VA 22203 under contract #
//  N68335-17-C-0700.  The content of the information does not necessarily
//  reflect the position or policy of the Government and no official
//  endorsement should be inferred.
//
//===----------------------------------------------------------------------===//

#ifndef SRC_X86_DECODER_H_
#define SRC_X86_DECODER_H_

#include <souffle/SouffleInterface.h>
#include <gtirb/gtirb.hpp>

#include "DatalogUtils.h"
#include "DlDecoder.h"
#include "DlOperandTable.h"

class X86Decoder : public DlDecoder
{
public:
    X86Decoder() : DlDecoder(gtirb::ISA::X64){};
    souffle::SouffleProgram* decode(const gtirb::Module& module,
                                    const std::vector<std::string>& DisasmOptions) override;
    void decodeSection(const gtirb::ByteInterval& byteInterval) override;
};

#endif /* SRC_X86_DECODER_H_ */