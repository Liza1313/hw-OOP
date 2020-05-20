#pragma once

#include "jsonadapter.h"


namespace OOP
{
    class InfoManager : public JSON_adapter
    {

        public:
            InfoManager() = default;
            ~InfoManager() = default;

            void
            data_write(const std::string *name , const std::string *file_path , const std::map<std::string , std::string> *data)
            {
                _root.empty() ? this->json_read(*file_path) : void();

                for(auto&& [first, second] : *data)
                {
                    this->_children.put(first , second.data());
                }

                this->_root.add_child(*name , this->_children);

                this->json_write(*file_path);
            }

            std::map<std::string , std::string>
            data_get(const std::string *name , const std::string *file_path)
            {
                _root.empty() ? this->json_read(*file_path) : void();

                /** get entity by input @param name */
                auto iterator = _root.find(*name);

                /**method for convertaion data from boost_json_array */
                //std::map<std::string , std::string>   data = ArrayHelper<std::string>::map_convert(iterator->second);
                std::map<std::string , std::string>   data;


                return data;
            }

    };


}
