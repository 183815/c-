#ifndef CONFIG_H
#define CONFIG_H

#include "head.h"
#define conf_file "conf.ini"
#define file_path "book.data"

class config
{
public:
    config();
    ~config();
    void save_config_file();
    void read_config_file();
protected:
private:
};

#endif // CONFIG_H
