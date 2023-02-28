#include "config.h"

config::config()
{
    read_config_file();
}

config::~config()
{
    save_config_file();
}

void config::save_config_file()
{
    fstream fout(conf_file,ios::out|ios::trunc);
    fout<<conf_file<<' '<<file_path;
    fout.close();
}

void config::read_config_file()
{
    char choice;
    cout<<"是否使用默认配置(1.是     2.否):";
    cin>>choice;
    if(choice=='1'){
        fstream fin(conf_file,ios::in);
        if(fin){
            fin>>conf_file>>file_path;
            fin.close();
        }
        else {
            save_config_file();
        }
    }
    else if(choice=='2'){
        cout<<"请输入保存文件位置(例如:C:\\\\book.data):"<<endl;
        cin>>file_path;
    }
}
