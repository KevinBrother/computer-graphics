#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(int argc, char **argv){
  string vertexPath = "./shader.vs.glsl";
  ifstream vShaderFile;
  std::stringstream vShaderStream;
  std::string vertexCode;

  try {
    vShaderFile.open(vertexPath);
    vShaderStream << vShaderFile.rdbuf();
    vertexCode = vShaderStream.str();
  }
  catch (std::ifstream::failure& e)
  {
    std::cout << "ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ: " << e.what() << std::endl;
  }

  std::cout << vertexCode << std::endl; // 输出每行内容

}

/*
int main(int argc, char **argv){
  ifstream ifs("shader.fs.glsl");
  if (!ifs.bad())
  {
    // Dump the contents of the file to cout.
//    cout << ifs.rdbuf();

    std::string line;
    while (std::getline(ifs, line)) { // 逐行读取文件内容
      std::cout << line << std::endl; // 输出每行内容
    }

    ifs.close();
  }else {
    cout << "Error: Could not open file: a.txt." << endl;
  }
}
*/
