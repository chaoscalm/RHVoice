/* Copyright (C) 2019  Olga Yakovleva <yakovleva.o.v@gmail.com> */

/* This program is free software: you can redistribute it and/or modify */
/* it under the terms of the GNU Lesser General Public License as published by */
/* the Free Software Foundation, either version 2.1 of the License, or */
/* (at your option) any later version. */

/* This program is distributed in the hope that it will be useful, */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the */
/* GNU Lesser General Public License for more details. */

/* You should have received a copy of the GNU Lesser General Public License */
/* along with this program.  If not, see <http://www.gnu.org/licenses/>. */

#ifndef RHVOICE_BRAZILIAN_PORTUGUESE_HPP
#define RHVOICE_BRAZILIAN_PORTUGUESE_HPP

#include "str.hpp"
#include "fst.hpp"
#include "language.hpp"

namespace RHVoice
{
  class brazilian_portuguese_info: public language_info
  {
  public:
    brazilian_portuguese_info(const std::string& data_path,const std::string& userdict_path);

    #ifdef WIN32
    unsigned short get_id() const
    {
      return 1046;
    }
    #endif

  private:
    smart_ptr<language> create_instance() const;
  };

  class brazilian_portuguese: public language
  {
  public:
    explicit brazilian_portuguese(const brazilian_portuguese_info& info_);

    const brazilian_portuguese_info& get_info() const
    {
      return info;
    }

    std::vector<std::string> get_word_transcription(const item& word) const;

  private:

    void before_g2p(item& w) const;

    const brazilian_portuguese_info& info;
    const fst g2p_fst;
    const fst lseq_fst;
  };
}
#endif