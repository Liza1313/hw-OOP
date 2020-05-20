#pragma once

#include "define.h"


namespace OOP
{
    class JSON_adapter
    {
        protected:
            pt::ptree       _root;
            pt::ptree       _children;


        public:



        public:
            void
            operator=(const std::string file_name) noexcept
            {
                this->json_read(file_name);
            }


            void
            json_read(const std::string file_name) noexcept
            {
                pt::read_json(file_name+".json" , this->_root);
            }

            void
            json_write(const std::string file_name) noexcept
            {
                pt::write_json(file_name+".json" , this->_root);
            }

            pt::ptree static
            get_root(const std::string file_name)
            {
                pt::ptree root;
                pt::read_json(file_name+".json" , root);

                return root;
            }
    };


}
