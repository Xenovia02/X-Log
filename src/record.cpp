#include "record.hpp"

namespace xlog
{
    Record::Record(Record&& old)
    {
        args = std::move(old.args);
        msg = std::move(old.msg);
        lgr = std::move(old.lgr);
        lvl = old.lvl;
        file = std::move(old.file);
        line = old.line;
    }

    void Record::init_rest(const std::string& message, const std::string& lname, const uchar& level)
        : msg(message), lgr(lname), lvl(level) { }

    str_umap Recod::get_dict() const
    {
        str_umap dict
        {
            { "msg" , msg  }
            { "lgr" , lgr  }
            { "lvl" , lvl  }
            { "file", file }
            { "line", line }
        };
        dict.merge(args);
        return dict;
    }
}