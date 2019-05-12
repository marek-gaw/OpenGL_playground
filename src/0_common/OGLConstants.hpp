/************************************************************
 *
 * file: OGLConstants.hpp
 * brief: Common constants
 *
 ************************************************************/

#ifndef SRC_0_COMMON_OGLCONSTANTS_HPP
#define SRC_0_COMMON_OGLCONSTANTS_HPP

#include <string>

namespace OGL {
namespace Constants {
    namespace Window {
        constexpr int Width  = 800;
        constexpr int Height = 600;
    }

namespace Glut {
    namespace Version {
        const int Major = 3;
        constexpr int Minor = 0;
    }
    namespace Shaders {
        const std::string vertPath = "../src/2_triangle/shaders/shader.vert";
        const std::string fragPath = "../src/2_triangle/shaders/shader.frag";
    }
}

}
}

#endif // SRC_0_COMMON_OGLCONSTANTS_HPP
