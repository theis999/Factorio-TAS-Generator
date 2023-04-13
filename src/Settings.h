#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>

#ifndef TAS_SETTINGS_DEFINED
#define TAS_SETTINGS_DEFINED
#include "nlohmann/json.hpp"

/// <summary>
/// Settings contains methods for reading generator-settings.json file
/// Reads/writes to the json file
/// Converts the json file -> json data -> settings::cpp_json::setting which is the interface storage class for settings
/// Converts settings::cpp_json::setting.last_tas to UTF-8 and back again
/// </summary>
namespace settings
{
    using json = nlohmann::json;

    using std::string;
    using std::vector;
    using std::map;
    using std::fstream;

    namespace file
    {
#pragma region filepath

        //entry string for json last tas
        const string last = "last_tas";

        //entry string for json : shortcuts map
        const string shortcuts = "shortcuts";

        //filename for settings json
        const string filename = "generator-settings.json";

        /// <summary>
        /// Gets the fully qualified named of settings json file
        /// </summary>
        /// <returns>The file name as a std::string</returns>
        static inline const string GetFilePath()
        {
            return (std::filesystem::current_path() / filename).string();
        }
#pragma endregion filepath

#pragma region UTF8
        constexpr int MASKBITS = 0x3F;
        constexpr int MASKBYTE = 0x80;
        constexpr int MASK2BYTES = 0xC0;
        constexpr int MASK3BYTES = 0xE0;
        constexpr int MASK4BYTES = 0xF0;
        constexpr int MASK5BYTES = 0xF8;
        constexpr int MASK6BYTES = 0xFC;

        typedef unsigned short   Unicode2Bytes;
        typedef unsigned int     Unicode4Bytes;

        static void UTF8Encode2BytesUnicode(std::vector< Unicode2Bytes > input, std::vector< byte >& output)
        {
            for (int i = 0; i < input.size(); i++)
            {
                // 0xxxxxxx
                if (input[i] < 0x80)
                {
                    output.push_back((byte)input[i]);
                }
                // 110xxxxx 10xxxxxx
                else if (input[i] < 0x800)
                {
                    output.push_back((byte)(MASK2BYTES | input[i] >> 6));
                    output.push_back((byte)(MASKBYTE | input[i] & MASKBITS));
                }
                // 1110xxxx 10xxxxxx 10xxxxxx
                else if (input[i] < 0x10000)
                {
                    output.push_back((byte)(MASK3BYTES | input[i] >> 12));
                    output.push_back((byte)(MASKBYTE | input[i] >> 6 & MASKBITS));
                    output.push_back((byte)(MASKBYTE | input[i] & MASKBITS));
                }
            }
        }

        static void UTF8Decode2BytesUnicode(std::vector< byte > input, std::vector< Unicode2Bytes >& output)
        {
            for (int i = 0; i < input.size();)
            {
                Unicode2Bytes ch;
                // 1110xxxx 10xxxxxx 10xxxxxx
                if ((input[i] & MASK3BYTES) == MASK3BYTES)
                {
                    ch = ((input[i] & 0x0F) << 12)
                        | ((input[i + 1] & MASKBITS) << 6)
                        | (input[i + 2] & MASKBITS);
                    i += 3;
                }
                // 110xxxxx 10xxxxxx
                else if ((input[i] & MASK2BYTES) == MASK2BYTES)
                {
                    ch = ((input[i] & 0x1F) << 6) | (input[i + 1] & MASKBITS);
                    i += 2;
                }

                // 0xxxxxxx
                else if (input[i] < MASKBYTE)
                {
                    ch = input[i];
                    i += 1;
                }
                output.push_back(ch);
            }
        }

        static void UTF8Encode4BytesUnicode(std::vector< Unicode4Bytes > input, std::vector< byte >& output)
        {
            for (int i = 0; i < input.size(); i++)
            {
                // 0xxxxxxx
                if (input[i] < 0x80)
                {
                    output.push_back((byte)input[i]);
                }

                // 110xxxxx 10xxxxxx
                else if (input[i] < 0x800)
                {
                    output.push_back((byte)(MASK2BYTES | input[i] >> 6));
                    output.push_back((byte)(MASKBYTE | input[i] & MASKBITS));
                }

                // 1110xxxx 10xxxxxx 10xxxxxx
                else if (input[i] < 0x10000)
                {
                    output.push_back((byte)(MASK3BYTES | input[i] >> 12));
                    output.push_back((byte)(MASKBYTE | input[i] >> 6 & MASKBITS));
                    output.push_back((byte)(MASKBYTE | input[i] & MASKBITS));
                }

                // 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
                else if (input[i] < 0x200000)
                {
                    output.push_back((byte)(MASK4BYTES | input[i] >> 18));
                    output.push_back((byte)(MASKBYTE | input[i] >> 12 & MASKBITS));
                    output.push_back((byte)(MASKBYTE | input[i] >> 6 & MASKBITS));
                    output.push_back((byte)(MASKBYTE | input[i] & MASKBITS));
                }

                // 111110xx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
                else if (input[i] < 0x4000000)
                {
                    output.push_back((byte)(MASK5BYTES | input[i] >> 24));
                    output.push_back((byte)(MASKBYTE | input[i] >> 18 & MASKBITS));
                    output.push_back((byte)(MASKBYTE | input[i] >> 12 & MASKBITS));
                    output.push_back((byte)(MASKBYTE | input[i] >> 6 & MASKBITS));
                    output.push_back((byte)(MASKBYTE | input[i] & MASKBITS));
                }

                // 1111110x 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
                else if (input[i] < 0x8000000)
                {
                    output.push_back((byte)(MASK6BYTES | input[i] >> 30));
                    output.push_back((byte)(MASKBYTE | input[i] >> 18 & MASKBITS));
                    output.push_back((byte)(MASKBYTE | input[i] >> 12 & MASKBITS));
                    output.push_back((byte)(MASKBYTE | input[i] >> 6 & MASKBITS));
                    output.push_back((byte)(MASKBYTE | input[i] & MASKBITS));
                }
            }
        }

        static void UTF8Decode4BytesUnicode(std::vector< byte > input, std::vector< Unicode4Bytes >& output)
        {
            for (int i = 0; i < input.size();)
            {
                Unicode4Bytes ch;
                // 1111110x 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
                if ((input[i] & MASK6BYTES) == MASK6BYTES)
                {
                    ch = ((input[i] & 0x01) << 30)
                        | ((input[i + 1] & MASKBITS) << 24)
                        | ((input[i + 2] & MASKBITS) << 18)
                        | ((input[i + 3] & MASKBITS) << 12)
                        | ((input[i + 4] & MASKBITS) << 6)
                        | (input[i + 5] & MASKBITS);
                    i += 6;
                }
                // 111110xx 10xxxxxx 10xxxxxx 10xxxxxx 10xxxxxx
                else if ((input[i] & MASK5BYTES) == MASK5BYTES)
                {
                    ch = ((input[i] & 0x03) << 24)
                        | ((input[i + 1] & MASKBITS) << 18)
                        | ((input[i + 2] & MASKBITS) << 12)
                        | ((input[i + 3] & MASKBITS) << 6)
                        | (input[i + 4] & MASKBITS);
                    i += 5;
                }
                // 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
                else if ((input[i] & MASK4BYTES) == MASK4BYTES)
                {
                    ch = ((input[i] & 0x07) << 18)
                        | ((input[i + 1] & MASKBITS) << 12)
                        | ((input[i + 2] & MASKBITS) << 6)
                        | (input[i + 3] & MASKBITS);
                    i += 4;
                }
                // 1110xxxx 10xxxxxx 10xxxxxx
                else if ((input[i] & MASK3BYTES) == MASK3BYTES)
                {
                    ch = ((input[i] & 0x0F) << 12)
                        | ((input[i + 1] & MASKBITS) << 6)
                        | (input[i + 2] & MASKBITS);
                    i += 3;
                }
                // 110xxxxx 10xxxxxx
                else if ((input[i] & MASK2BYTES) == MASK2BYTES)
                {
                    ch = ((input[i] & 0x1F) << 6)
                        | (input[i + 1] & MASKBITS);
                    i += 2;
                }
                // 0xxxxxxx
                else if (input[i] < MASKBYTE)
                {
                    ch = input[i];
                    i += 1;
                }
                output.push_back(ch);
            }
        }
#pragma endregion UTF8
    }

    namespace cpp_json
    {
        struct setting
        {
            string last_tas;
            map<string, map<string, string>> shortcuts;
        };

        static void to_json(json& j, const setting& s)
        {
            j = json{
                {"last_tas", s.last_tas},
                {"shortcuts", s.shortcuts}
            };
        }

        static void from_json(const json& j, setting& s)
        {
            if (j.contains(file::last))
                s.last_tas = j[file::last];
            else
                s.last_tas = "";

            if (j.contains(file::shortcuts))
                for (auto& [key, value] : j.at(file::shortcuts).items())
                {
                    s.shortcuts.insert({key, value});
                }
            else
                s.shortcuts = {};
        }
    }

    using namespace file;
    using namespace cpp_json;

    static setting ReadSettingFile()
    {
        string setting_path = GetFilePath();
        json data;
        try // try to open last file
        {
            fstream file(setting_path, fstream::in | fstream::binary | fstream::ate);

            fstream::pos_type pos = file.tellg();
            file.seekg(0, std::ios_base::beg);
            std::vector<char>  result(pos); result.reserve(512);
            file.read(&result[0], pos);


            data = json::parse(result);
            file.close();

            vector<byte> utf; utf.reserve(512);
            vector<Unicode2Bytes> uni; uni.reserve(512);
            for (auto c : data[last].get<string>()) utf.push_back(c);
            UTF8Decode2BytesUnicode(utf, uni);
            string l = "";
            for (auto s : uni) l += (char)s;
            data[last] = l;

            return data.get<setting>();
        }
        catch (json::parse_error err)
        {
            // parser error
        } 
        catch (...)
        {
            // ignore all errors
        } 
        
        return setting();
    }

    static void SaveSettingFile(setting* s)
    {
        try // try to save new file
        {
            if (!(s->last_tas.empty()))
            {
                vector<byte> utf;
                vector<Unicode2Bytes> uni;
                for (auto c : s->last_tas) uni.push_back(c);
                UTF8Encode2BytesUnicode(uni, utf);
                s->last_tas = "";
                for (auto c : utf) s->last_tas.push_back((char)c);
            }
            json j = *s;
            string setting_path = GetFilePath();
            std::ofstream o;
            o.open(setting_path);
            auto dump = j.dump(4);
            o << dump << std::endl;
            o.close();
        }
        catch (json::type_error err)
        {
        } // type error
        catch (...)
        {
        } // ignore all errors
    }

    /// <summary>
    /// Saves the last tas file location in the settings file
    /// </summary>
    /// <param name="path">to the last tas location</param>
    static inline void SaveLastTas(string path)
    {
        try
        {
            auto a = ReadSettingFile();
            a.last_tas = path;
            SaveSettingFile(&a);
        }
        catch (json::type_error err)
        {
        } // type error
        catch (...)
        {
        } // ignore all errors
    }
}
#endif // !TAS_SETTINGS_DEFINED
